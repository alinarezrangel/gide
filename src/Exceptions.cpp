/*****************************************************************************
*    Exceptions.cpp: Exception classes.
*    Copyright (C) 2017  Alejandro Linarez Rangel
*
*    This program is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*****************************************************************************/

#include "Exceptions.hpp"

namespace GIDE
{
	/*
	* Exception classes in this file should use the standard library
	* snake_lower_case naming convention instead of the GIDE CamelCase naming
	* convention.
	*/

	invalid_state_error::invalid_state_error(const std::string& what_arg)
		: std::logic_error(what_arg)
	{}

	invalid_state_error::invalid_state_error(const char* what_arg)
		: std::logic_error(what_arg)
	{}
}
