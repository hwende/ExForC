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



#include "exceptions.h"
#include "func1.h"
#include "func2.h"

#include <stdio.h>



int main (void)
{
	/**-----------------------------------------------------------------------*/
/*
	printf("----------\n");
	printf("function: main - try\n");
	printf("----------\n");

	TRY {
		printf("should see me\n");
		THROW(-100);
		printf("should not see me\n");
	}
	CATCHALL {
		printf("catchall\n");
		printf("error code is %i\n", exception.errorCode);
		printf("exception status is %i\n", exception.status);
		exception.status = ES_HANDLED;
	}
	EOTRY;

	printf("----------\n");
	printf("after EOTRY\n");
	printf("error code is %i\n", exception.errorCode);
	printf("exception status is %i\n", exception.status);
*/
	/**-----------------------------------------------------------------------*/
/*
	printf("--------------------\n");
	printf("function main: calling func1a\n");
	printf("--------------------\n");

	func1a();
*/
	/**-----------------------------------------------------------------------*/
/*
	printf("----------\n");
	printf("function: main - try\n");
	printf("----------\n");

	TRY {
		printf("calling func2\n");
		func2();
		printf("main: after calling func2\n");
	}
	CATCHALL {
		printf("catchall\n");
		printf("error code is %i\n", exception.errorCode);
		printf("exception status is %i\n", exception.status);
		exception.status = ES_HANDLED;
	}
	EOTRY;

	printf("----------\n");
	printf("after EOTRY\n");
	printf("error code is %i\n", exception.errorCode);
	printf("exception status is %i\n", exception.status);
*/
	/**-----------------------------------------------------------------------*/

	printf("SIZE TEST\n");
	printf("sizeof jmp_buf   is %u\n", sizeof(jmp_buf));
	printf("sizeof Exception is %u\n", sizeof(struct Exception));

	printf("----IN----\n");
	printf("main: TRY\n");

	TRY {
		printf("main: calling func1b\n");
		func1b();
		printf("main: after calling func1b\n");
	}
	CATCHALL {
		printf("main: catchall\n");
		printf("main: error code is %i\n", exception.errorCode);
		printf("main: exception status is %i\n", exception.status);
		HANDLE();
	}
	EOTRY;

	printf("main: END OF TRY\n");
	printf("main: error code is %i\n", exception.errorCode);
	printf("main: exception status is %i\n", exception.status);

	/**-----------------------------------------------------------------------*/

	printf("----OUT---\n");

	return 0;
}
