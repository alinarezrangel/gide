/*****************************************************************************
*    GIDEApplicationWindow.hpp: The basic window of the application.
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

#ifndef __GIDE_APPLICATION_WINDOW_HPP__
#define __GIDE_APPLICATION_WINDOW_HPP__ 1

#include <gtkmm.h>
#include <glibmm/i18n.h>
#include <gtksourceviewmm.h>

#include <exception>
#include <stdexcept>

#include <clocale>

#include "GIDEMacros.hpp"
#include "GIDEFileSystemTreeModel.hpp"

namespace GIDE
{
	class ApplicationWindow : public Gtk::ApplicationWindow
	{
		public:
			explicit ApplicationWindow(
				BaseObjectType* c_object,
				const Glib::RefPtr<Gtk::Builder>& ref_builder
			);
			virtual ~ApplicationWindow(void);

			static ApplicationWindow* create(void);

		protected:
			void add_column_to_project_view(const TreeFileSystem::TreeEntry& entry);

		private:
			Glib::RefPtr<Gtk::Builder> ref_builder;
			Glib::RefPtr<Gsv::Buffer> source_buffer;
			Gsv::View source_view;
			Glib::RefPtr<Gtk::TreeStore> project_fs_model;
			TreeFileSystem::ModelColumn project_fs_model_columns;
	};
}

#endif /* ~__GIDE_APPLICATION_WINDOW_HPP__ */
