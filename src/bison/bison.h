/* bison.h: C interface to bison parser */
/*
    Copyright (C) 2007 Wolf Lammen.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License , or
    (at your option) any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; see the file COPYING.  If not, write to:

      The Free Software Foundation, Inc.
      59 Temple Place, Suite 330
      Boston, MA 02111-1307 USA.


    You may contact the author by:
       e-mail:  ookami1 <at> gmx <dot> de
       mail:  Wolf Lammen
              Oertzweg 45
              22307 Hamburg
              Germany

*************************************************************************/

#ifndef _BISON_H
#define _BISON_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct String
{
  char* s;
  int lg;
  struct String* prev;
} String;

typedef struct DigitSeq
{
  String* digits;
  char  base;
  char  complement;
  signed char sign;
} DigitSeq;

typedef struct NumLiteral
{
  DigitSeq intpart;
  String* fracpart;
  DigitSeq exp;
} NumLiteral;

typedef struct NumValue
{
  void* val;
  char* text;
} NumValue;

typedef void* Params;

typedef void* Postfix;
typedef void* Function;

typedef struct Var
{
  void* write;
  NumValue d;
} Var;

DigitSeq appendStr(DigitSeq tail, String* next);
DigitSeq initStr(String* head, char base);
NumValue convertStr(NumLiteral text);
Params addParam(Params list, NumValue val);
Postfix addPostfix(Postfix list, Postfix op);
NumValue callFunction(Function f, Params params);
NumValue callPostfix(Postfix list, NumValue val);
NumValue callBinOperator(Function op, NumValue p1, NumValue p2);

#ifdef __cplusplus
}
#endif 

#endif /* _BISON_H */
