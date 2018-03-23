/*****************************************************************************
*    NewProjectAssistant.cpp: A assistant window for creating a new project.
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

#include "NewProjectAssistant.hpp"

namespace GIDE
{
	NewProjectAssistant::NewProjectAssistant(
		BaseObjectType* c_object,
		const Glib::RefPtr<Gtk::Builder>& ref_builder
	)
		: Gtk::Assistant(c_object),
			path(""),
			metadata(),
			templt(nullptr),
			first_page(nullptr),
			second_page(nullptr),
			third_page(nullptr),
			fourth_page(nullptr),
			fiveth_page(nullptr)
	{
		ref_builder->get_widget("project_template", this->project_template_combo);
		ref_builder->get_widget("project_language", this->project_language_combo);
		ref_builder->get_widget("project_name", this->project_name_entry);
		ref_builder->get_widget("project_author", this->project_author_entry);
		ref_builder->get_widget("project_build_system", this->project_build_system_combo);
		ref_builder->get_widget("project_select_folder", this->project_select_folder);

		ref_builder->get_widget("welcome_screen", this->first_page);
		ref_builder->get_widget("project_template_screen", this->second_page);
		ref_builder->get_widget("project_metatada_screen", this->third_page);
		ref_builder->get_widget("project_buildsys_screen", this->fourth_page);
		ref_builder->get_widget("project_select_folder_screen", this->fiveth_page);

		this->ThrowIfNull(this->project_template_combo, "project_template", "ComboBox");
		this->ThrowIfNull(this->project_language_combo, "project_language", "ComboBox");
		this->ThrowIfNull(this->project_build_system_combo, "project_build_system", "ComboBox");
		this->ThrowIfNull(this->project_name_entry, "project_name", "Entry");
		this->ThrowIfNull(this->project_author_entry, "project_author", "Entry");
		this->ThrowIfNull(this->project_select_folder, "project_select_folder", "FileChooserWidget");

		this->project_template_combo->set_model(this->template_model);
		this->project_language_combo->set_model(this->language_model);
		this->project_build_system_combo->set_model(this->build_system_model);

		// Configure the FileChooser (it will select only folders)
		this->project_select_folder->set_action(Gtk::FILE_CHOOSER_ACTION_SELECT_FOLDER);
		this->project_select_folder->set_select_multiple(false);
		this->project_select_folder->set_do_overwrite_confirmation(true);
		this->project_select_folder->set_create_folders(true);
	}

	NewProjectAssistant::~NewProjectAssistant(void) {}

	ProjectMetadata NewProjectAssistant::get_project_metadata(void)
	{
		auto name_buffer = this->project_name_entry->get_buffer();
		auto author_buffer = this->project_author_entry->get_buffer();
		auto active_language = this->project_language_combo->get_active();

		if(!name_buffer)
			throw invalid_state_error("buffer for the name field is undefined");

		if(!author_buffer)
			throw invalid_state_error("buffer for the author field is undefined");

		if(!active_language)
			throw invalid_state_error("there is no active language");

		return ProjectMetadata(
			name_buffer->get_text(),
			author_buffer->get_text(),
			active_language->get_value(
				this->programming_language_column.language
			),
			GIDE_VERSION,
			this->project_build_system_combo->get_active()->get_value(
				this->build_system_column.system
			)
		);
	}

	Glib::ustring NewProjectAssistant::get_project_path(void)
	{
		return this->project_select_folder->get_uri();
	}

	std::shared_ptr<ProjectTemplate> NewProjectAssistant::get_project_template(void)
	{
		return this->project_template_combo->get_active()->get_value(
			this->project_template_column.templt
		);
	}

	NewProjectAssistant* NewProjectAssistant::create(void)
	{
		auto ref_builder = Gtk::Builder::create_from_file(
			GIDE_GLADEUIDIR "/project_new_assistant_dialog.glade"
		);

		NewProjectAssistant* window = nullptr;
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
