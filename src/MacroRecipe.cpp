
// Copyright 2016 Uri Cohen (uri.l.cohen@gmail.com)
//
//  This file is part of NDPP.
//
//  NDPP is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  NDPP is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with NDPP.  If not, see <http://www.gnu.org/licenses/>.

///////////////////////////////////////////////////////////////////////////////

// MacroRecipe - The basic macro expansion recipe by guards

///////////////////////////////////////////////////////////////////////////////

#include "MacroRecipe.h"
#include "Guard.h"

MacroRecipe::~MacroRecipe(void)
{
	for(auto g : _guards) {
		delete g;
	}
}

bool
MacroRecipe::isValid(const ParamBinding& context) const
{
	for(auto g : _guards) {
		if (! g->test(context)) {
			return false;
		}
	}
	return true;
}

string
MacroRecipe::expand(const ParamBinding& context)
{
	string result("");
	for(auto& d : _data) {
		switch (d.role) {
		case Role::STR:
			result += d.data;
			break;
		case Role::PARAM:
			result += context.get(d.data);
			break;
		}
	}
	return result;
}
