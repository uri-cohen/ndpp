
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

// Macro - a recipe for (possibly non-deterministic) output generation
//
// A Macro is actually an ordered set of recipes (MacroRecipe) with guard
// expressions. All using same "interface" - that is same set of positional
// arguments. The first MacroRecipe whose guard is evaluated to True is
// selected and expanded.

///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <string>
#include <vector>
using namespace std;

#include "ParamDef.h"
#include "MacroRecipe.h"

///////////////////////////////////////////////////////////////////////////////

class Macro
{
public:
	Macro(const string& name) : _name(name) {}
	virtual ~Macro(void) {}

	void addRecipe(
			const MacroRecipe& recipe);

	// searches for context matching recipe and expands it
	// returns true iff found and expand one
	bool expand(
			string& out,
			const ParamBinding& context);

	// create a new context
	ParamBinding* newContext(
			const ParamBinding& context,
			const vector<string>& args) const;

private:
	string					_name;
	vector<MacroRecipe>		_recipes;
	ParamDef				_params;
};
