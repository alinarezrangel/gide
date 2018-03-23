/*****************************************************************************
*    Exceptions.hpp: Exception classes.
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

#ifndef __GIDE_EXCEPTIONS_HPP__
#define __GIDE_EXCEPTIONS_HPP__ 1

#include <gtkmm.h>
#include <glibmm/i18n.h>

#include <exception>
#include <stdexcept>
#include <string>

#include "Macros.hpp"

namespace GIDE
{
	/*
	* Exception classes in this file should use the standard library
	* snake_lower_case naming convention instead of the GIDE CamelCase naming
	* convention.
	*/

	class invalid_state_error : public std::logic_error
	{
		public:
			explicit invalid_state_error(const std::string& what_arg);
			explicit invalid_state_error(const char* what_arg);
	};
}

#endif /* ~__GIDE_EXCEPTIONS_HPP__ */
