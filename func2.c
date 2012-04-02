/*
* This file is part of Exceptions for C.
*
* Copyright (C) 2011 Henning Wende <wende@uni-tuebingen.de>
*
* Exceptions for C is free software: you can redistribute it
* and/or modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation,
* either version 2 of the License, or (at your option) any later version.
*
* Exceptions for C is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty
* of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
* See the GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with Exceptions for C. If not, see <www.gnu.org/licenses/>.
*/

#include "func1.h"

#include <stdio.h>

void func2()
{
	printf("----IN----\n");
	printf("entering func2\n");
	printf("func2: THROW(-2)\n");
	THROW(-2);
	printf("leaving func2\n");
	printf("----OUT---\n");
}
