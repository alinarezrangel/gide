/*****************************************************************************
*    ApplicationWindow.hpp: The basic window of the application.
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

#include <clocale>

#include <exception>
#include <stdexcept>

#include "Macros.hpp"
#include "FileSystemTreeModel.hpp"
#include "NewProjectAssistant.hpp"
#include "Project.hpp"

namespace GIDE
{
	/**
	* @brief The main window of the application.
	*/
	class ApplicationWindow : public Gtk::ApplicationWindow
	{
		public:
			/**
			* @brief Contructs an Application Window.
			*
			* Is designed for internal use only by Gtk::Builder.
			*/
			explicit ApplicationWindow(
				BaseObjectType* c_object,
				const Glib::RefPtr<Gtk::Builder>& ref_builder
			);
			/**
			* @brief Destroyes an Application Window.
			*/
			virtual ~ApplicationWindow(void);

			/**
			* @brief Creates an Application Window.
			*
			* @return The new ApplicationWindow.
			*/
			static ApplicationWindow* create(void);

		protected:
			Gtk::TreeModel::Row add_column_to_project_view(
				const TreeFileSystem::TreeEntry& entry
			);

			Gtk::TreeModel::Row add_column_to_project_view(
				const TreeFileSystem::TreeEntry& entry,
				const Gtk::TreeModel::Row& rw
			);

			virtual void on_new_project_action(const Glib::VariantBase& param);
			virtual void on_new_project_assistant_done(void);
			virtual void on_new_project_assistant_cancel_close(void);

		private:
			Glib::RefPtr<Gtk::Builder> ref_builder;

			Glib::RefPtr<Gsv::Buffer> source_buffer;
			Gsv::View source_view;

			Glib::RefPtr<Gtk::TreeStore> project_fs_model;
			TreeFileSystem::ModelColumn project_fs_model_columns;
			Gtk::CellRendererPixbuf project_fs_rendererpb;

			Glib::RefPtr<Gio::SimpleAction> new_project_action;

			NewProjectAssistant* assistant;
	};
}

#endif /* ~__GIDE_APPLICATION_WINDOW_HPP__ */
