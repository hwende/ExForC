#
# This file is part of Exceptions for C.
#
# Copyright (C) 2011 Henning Wende <wende@uni-tuebingen.de>
#
# Exceptions for C is free software: you can redistribute it
# and/or modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation,
# either version 2 of the License, or (at your option) any later version.
#
# Exceptions for C is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty
# of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with Exceptions for C. If not, see <www.gnu.org/licenses/>.
#

CC       = gcc
CFLAGS   = -Wall -O2
CPPFLAGS =
LDFLAGS  =
DFLAGS   = -MM

PROGRAM = a.exe



# this wildcard functions produce a list of all the *.h and *.c files
# and via pattern substitution a list of object files
#--------------------------------------------------------------------
HEADERS = $(wildcard *.h)
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)

DEPFILE = .depends



# what file is needed for rule 'all'? (look at it's dependencies)
# (this rule (the first) is carried out if 'make' is called)
#----------------------------------------------------------------
.PHONY: all
all: $(PROGRAM)



# if 'PROGRAM' is needed, what files does it depend on?
# how to make 'PROGRAM' if it does not exist or is older than the dependencies?
# ($^ is a list of the dependencies, ie 'OBJECTS' and $@ is the target, ie 'PROGRAM')
#------------------------------------------------------------------------------------
$(PROGRAM): $(OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@



# if one of the 'OBJECTS' is needed, what files does it depend on?
# (note: the 'DEPFILE' contains exactly the needed lines. look at it)
#--------------------------------------------------------------------
-include $(DEPFILE)

# when this 'DEPFILE' needs to be included, what files does it depend on?
# how to make the 'DEPFILE' if it does not exist or is older than the dependencies?
# (don't use $^ here since this would include the headers and you don't want that)
#----------------------------------------------------------------------------------
$(DEPFILE): $(HEADERS) $(SOURCES)
	$(CC) $(DFLAGS) $(SOURCES) > $@



# the target 'clean' cleans everything up nicely
# .PHONY since this should always be carried out
# (use linux commands inside a makefile)
#------------------------------------------------
.PHONY: clean
clean:
	del $(PROGRAM)
	del $(OBJECTS)
	del $(DEPFILE)
