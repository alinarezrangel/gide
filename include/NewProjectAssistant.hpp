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

#include <exception>
#include <stdexcept>

#include "Macros.hpp"
#include "Exceptions.hpp"
#include "Project.hpp"
#include "NewProjectAssistantModel.hpp"

namespace GIDE
{
	/**
	* @brief An assistant to help users when creating projects.
	*
	* This should be used to guide users step-by-step in the process of creating
	* projects.
	*/
	class NewProjectAssistant : public Gtk::Assistant
	{
		public:
			NewProjectAssistant(void) = delete;
			NewProjectAssistant(
				BaseObjectType* c_object,
				const Glib::RefPtr<Gtk::Builder>& ref_builder
			);
			virtual ~NewProjectAssistant(void);

			/**
			* @brief Gets the project metadata from the user.
			*/
			ProjectMetadata get_project_metadata(void);
			Glib::ustring get_project_path(void);
			std::shared_ptr<ProjectTemplate> get_project_template(void);

			static NewProjectAssistant* create(void);

		protected:
			template<class T_Widget>
			void ThrowIfNull(
				T_Widget* widget,
				const Glib::ustring& ui_name,
				const Glib::ustring& ui_widget
			)
			{
				if(!widget)
				{
					throw std::runtime_error(
						"(NewProjectAssistant) No " + ui_widget + " named " + ui_name +
						" in the UI file"
					);
				}
			}

		private:
			Glib::ustring path; //< Path to the project
			ProjectMetadata metadata; //< Project's metadata
			std::shared_ptr<ProjectTemplate> templt; //< Project's template to use

			Gtk::Entry* project_name_entry;
			Gtk::Entry* project_author_entry;
			Gtk::ComboBox* project_template_combo;
			Gtk::ComboBox* project_language_combo;
			Gtk::ComboBox* project_build_system_combo;
			Gtk::FileChooserWidget* project_select_folder;

			Gtk::Box* first_page;
			Gtk::Frame* second_page;
			Gtk::Frame* third_page;
			Gtk::Frame* fourth_page;
			Gtk::Frame* fiveth_page;

			// These are the models and columns used to fill the UI comboboxes.
			Glib::RefPtr<Gtk::ListStore> template_model;
			Glib::RefPtr<Gtk::ListStore> language_model;
			Glib::RefPtr<Gtk::ListStore> build_system_model;

			NewProjectAssistantModels::ProgrammingLanguage::ModelColumn
				programming_language_column;

			NewProjectAssistantModels::BuildSystem::ModelColumn
				build_system_column;

			NewProjectAssistantModels::ProjectTemplateNS::ModelColumn
				project_template_column;
	};
}

#endif /* ~__GIDE_NEW_PROJECT_ASSISTANT_HPP__ */
