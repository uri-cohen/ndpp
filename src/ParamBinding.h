
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

// ParamBinding - hierarchical param binding
//
// A string (key, value) mapping with a recursive fall back to parent binding

///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <string>
#include <map>

using namespace std;

///////////////////////////////////////////////////////////////////////////////

class ParamBinding
{
public:
	ParamBinding(ParamBinding* parent = nullptr)
		: _parent(parent) {}
	virtual ~ParamBinding(void) {}

	// add a (key, value) pair to current mapping
	void add(
			const string& key,
			const string& value) {
		_map[key] = value;
	}

	// check exists
	bool exists(const string& key) const {
		for(const ParamBinding* pb = this; pb != nullptr; pb = pb->_parent) {
			map<string, string>::const_iterator it = pb->_map.find(key);
			if (it != pb->_map.end()) {
				return true;
			}
		}
		return false;
	}

	// get value (recursively if needed).  If no value then use default value def
	string get(
			const string& key,
			const string def = "") const {
		for(const ParamBinding* pb = this; pb != nullptr; pb = pb->_parent) {
			map<string, string>::const_iterator it = pb->_map.find(key);
			if (it != pb->_map.end()) {
				return it->second;
			}
		}
		return def;
	}

	// check if key is registered locally
	bool isLocal(const string& key) const {
		return _map.find(key) != _map.end();
	}

private:
	ParamBinding*			_parent;
	map<string, string>		_map;
};
