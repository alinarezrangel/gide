/*****************************************************************************
*    GIDEApplicationWindow.cpp: The basic window of the application.
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

#include "GIDEApplicationWindow.hpp"

namespace GIDE
{
	ApplicationWindow::ApplicationWindow(
		BaseObjectType* c_object,
		const Glib::RefPtr<Gtk::Builder>& ref_builder
	)
		: Gtk::ApplicationWindow(c_object)
	{
		//
	}

	ApplicationWindow::~ApplicationWindow(void)
	{
	}

	ApplicationWindow* ApplicationWindow::create(void)
	{
		auto ref_builder = Gtk::Builder::create_from_file(
			GIDE_GLADEUIDIR "/main_window_nonended.glade"
		);

		ApplicationWindow* window = nullptr;
		ref_builder->get_widget_derived("main_window", window);

		if(!window)
		{
			throw std::runtime_error(
				"No window named \"main_window\" on the Glade file"
			);
		}

		return window;
	}
}
