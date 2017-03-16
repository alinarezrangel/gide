/*****************************************************************************
*    NewProjectAssistant.hpp: A assistant window for creating a new project.
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

#ifndef __GIDE_NEW_PROJECT_ASSISTANT_HPP__
#define __GIDE_NEW_PROJECT_ASSISTANT_HPP__ 1

#include <gtkmm.h>
#include <glibmm/i18n.h>

#include <clocale>

#include "Macros.hpp"
#include "Project.hpp"

namespace GIDE
{
	class NewProjectAssistant : public Gtk::Assistant
	{
		public:
			NewProjectAssistant(void) = delete;
			NewProjectAssistant(
				BaseObjectType* c_object,
				const Glib::RefPtr<Gtk::Builder>& ref_builder
			);
			virtual ~NewProjectAssistant(void);

			//

			static NewProjectAssistant* create(void);
	};
}

#endif /* ~__GIDE_NEW_PROJECT_ASSISTANT_HPP__ */
