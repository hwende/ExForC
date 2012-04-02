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
#include "func2.h"

#include <stdio.h>
#include <string.h>



void func1a()
{
	printf("----------\n");
	printf("entering func1a\n");
	printf("func1a: TRY\n");

	TRY {
		printf("func1a: this code is executed\n");
		THROW(-1);
		printf("func1a: this code is NOT executed\n");
	}
	CATCHALL {
		printf("func1a: catchall\n");
		printf("func1a: error code is %i\n", exception.errorCode);
		printf("func1a: exception status is %i\n", exception.status);
		exception.status = ES_HANDLED;
	}
	EOTRY;

	printf("func1a: END OF TRY\n");
	printf("func1a: exception status is %i\n", exception.status);
}



void func1b()
{
	printf("----IN----\n");
	printf("entering func1b\n");
	printf("func1b: TRY\n");

	TRY {
		printf("func1b: calling func2\n");
		func2();
		printf("func1b: after calling func2\n");
	}
	CATCHALL {
		printf("func1b: catchall\n");
		printf("func1b: error code is %i\n", exception.errorCode);
		printf("func1b: exception status is %i\n", exception.status);
		//PASS(exception.errorCode);
		HANDLE();
	}
	EOTRY;

	printf("func1b: END OF TRY\n");
	printf("func1b: exception status is %i\n", exception.status);
	printf("leaving func1b\n");
	printf("----OUT---\n");
}
