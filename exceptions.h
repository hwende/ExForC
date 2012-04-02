/*
* Exceptions for C
*
* Copyright (C) 2011 Henning Wende <wende@uni-tuebingen.de>
*
* This implementation is free software: you can redistribute it
* and/or modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation,
* either version 2 of the License, or (at your option) any later version.
*
* This implementation is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty
* of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
* See the GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this implementation. If not, see <www.gnu.org/licenses/>.
*/



#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <setjmp.h>
#include <string.h>



enum ExceptionStatus {
	ES_THROWN,
	ES_PASSED,
	ES_HANDLED
};



struct Exception {
	jmp_buf env;
	int errorCode;
	enum ExceptionStatus status;
};



struct Exception exception;



#define TRY		do {                                                           \
					jmp_buf envCopy;                                           \
					memcpy(envCopy, exception.env, sizeof(jmp_buf));           \
					switch (setjmp(exception.env)) {                           \
						case 0 : {

#define CATCH(e)		} break;                                               \
						case (e) : {                                           \
							memcpy(exception.env, envCopy, sizeof(jmp_buf));   \

#define CATCHALL		} break;                                               \
						default : {                                            \
							memcpy(exception.env, envCopy, sizeof(jmp_buf));   \

#define EOTRY			} break;                                               \
					} /* switch */                                             \
					memcpy(exception.env, envCopy, sizeof(jmp_buf));           \
				} while(0);

#define THROW(e) {                         \
			exception.errorCode = e;       \
			exception.status = ES_THROWN;  \
			longjmp(exception.env, e);     \
		}

#define PASS(e) {                          \
			exception.errorCode = e;       \
			exception.status = ES_PASSED;  \
			longjmp(exception.env, e);     \
		}

#define HANDLE() {                         \
			exception.status = ES_HANDLED; \
		}



#endif
