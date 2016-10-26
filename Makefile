
# Copyright 2016 Uri Cohen (uri.l.cohen@gmail.com)
#
#  This file is part of NDPP.
#
#  NDPP is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
#
#  NDPP is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with NDPP.  If not, see <http:#www.gnu.org/licenses/>.

ARCH 		:= $(shell arch)
TARGET 		:= 

.PHONY: all clean test

all:
	$(MAKE) -C src all ARCH=$(ARCH) TARGET=$(TARGET)

clean:

test:

		