
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

#pragma once

#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

#include "ParamBinding.h"

class Macro;
class Guard;

///////////////////////////////////////////////////////////////////////////////


class MacroRecipe
{
public:
	enum class Role { STR, PARAM };

private:
	struct Data
	{
		Data(void) : role(Role::STR), data("") {}
		Data(Role r, const string& d) : role(r), data(d) {}
		Data(const Data& o) : role(o.role), data(o.data) {}

		Role			role;
		string			data;
	};

public:
	MacroRecipe(Macro* macro): _macro(macro) {}

	virtual ~MacroRecipe(void);

	// addGuard takes an ownership of guard
	void addGuard(Guard* guard) {
		_guards.push_back(guard);
	};

	void addData(Role r, const string& d) {
		_data.push_back(Data(r, d));
	};

	// check guard
	bool isValid(const ParamBinding& context) const;

	// expand without checking guard
	string expand(const ParamBinding& context);

private:
	Macro*				_macro;
	vector<Guard*>		_guards;
	vector<Data>		_data;
};

///////////////////////////////////////////////////////////////////////////////
