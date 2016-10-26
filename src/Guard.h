
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

// Guard - A MacroRecipe guard
// This class was considered to be a MacroRecipe private subclass.
// The reason this is not this way is to enable construction of (future) complex
// nested guards.

///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <string>
#include <vector>
#include <set>
using namespace std;

///////////////////////////////////////////////////////////////////////////////

class Guard
{
public:
	Guard(const string& param) : _param(param) {}
	virtual ~Guard(void) {}
	virtual bool test(const ParamBinding& context) const = 0;

protected:
	string			_param;
};

class EqGuard : public Guard
{
public:
	EqGuard(
			const string& param,
			const string& value)
: Guard(param), _value(value) {}
	virtual ~EqGuard(void) {}
	virtual bool test(const ParamBinding& context) const {
		return context.get(_param) == _value;
	}
private:
	string			_value;
};

class NeGuard : public Guard
{
	NeGuard(
			const string& param,
			const string& value)
	: Guard(param), _value(value) {}
	virtual ~NeGuard(void) {}
	virtual bool test(const ParamBinding& context) const {
		return context.get(_param) != _value;
	}
private:
	string 			_value;
};

class InGuard : public Guard
{
	InGuard(
			const string& param,
			const vector<string>& values)
	: Guard(param), _values(values.begin(), values.end()) {}
	virtual ~InGuard(void) {}
	virtual bool test(const ParamBinding& context) const {
		return _values.find(context.get(_param)) != _values.end();
	}
private:
	set<string>		_values;
};

class NotInGuard : public Guard
{
	NotInGuard(
			const string& param,
			const vector<string>& values)
	: Guard(param), _values(values.begin(), values.end()) {}
	virtual ~NotInGuard(void) {}
	virtual bool test(const ParamBinding& context) const {
		return _values.find(context.get(_param)) == _values.end();
	}
private:
	set<string>		_values;
};

