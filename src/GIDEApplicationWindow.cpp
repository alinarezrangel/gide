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
		: Gtk::ApplicationWindow(c_object),
			ref_builder(ref_builder),
			source_buffer(
				Gsv::Buffer::create(
					Gsv::LanguageManager::get_default()->get_language("cpp")
				)
			),
			source_view(),
			project_fs_model_columns()
	{
		this->project_fs_model = Gtk::TreeStore::create(project_fs_model_columns);

		this->resize(500, 300);

		this->source_view.set_source_buffer(this->source_buffer);
		this->source_view.set_show_line_numbers(true);
		this->source_view.set_tab_width(2);
		this->source_view.set_auto_indent(true);
		this->source_view.set_insert_spaces_instead_of_tabs(false);
		this->source_view.set_show_right_margin(true);
		this->source_view.set_highlight_current_line(true);
		this->source_view.set_indent_on_tab(true);
		this->source_view.set_monospace(true);
		this->source_view.set_right_margin_position(80);

		this->source_buffer->set_highlight_matching_brackets(true);
		this->source_buffer->set_highlight_syntax(true);

		Gtk::Viewport* viewport = nullptr;
		ref_builder->get_widget("viewport", viewport);

		if(!viewport)
		{
			throw std::runtime_error(
				"No viewport named \"viewport\" on the Glade file"
			);
		}

		Gtk::Paned* panels = nullptr;
		ref_builder->get_widget("panels", panels);

		if(!panels)
		{
			throw std::runtime_error(
				"No paned named \"panels\" on the Glade file"
			);
		}

		Gtk::TreeView* filesystem_view = nullptr;
		ref_builder->get_widget("project_filesystem_view", filesystem_view);

		if(!filesystem_view)
		{
			throw std::runtime_error(
				"No TreeView named \"project_filesystem_view\" on the Glade file"
			);
		}

		filesystem_view->set_model(this->project_fs_model);
		int numcols = filesystem_view->append_column(
			_("Icon"),
			this->project_fs_rendererpb
		);
		filesystem_view->append_column_numeric(
			_("Type"),
			this->project_fs_model_columns.filetype,
			"%d"
		);
		filesystem_view->append_column(
			_("Filename"),
			this->project_fs_model_columns.filename
		);

		filesystem_view->get_column(numcols - 1)->add_attribute(
			this->project_fs_rendererpb,
			"pixbuf",
			this->project_fs_model_columns.icon
		);

		this->add_column_to_project_view(
			TreeFileSystem::TreeEntry("project.pro")
		);

		viewport->add(this->source_view);
		panels->set_position(100);

		this->show_all();
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

	void ApplicationWindow::add_column_to_project_view(
		const TreeFileSystem::TreeEntry& entry
	)
	{
		Gtk::TreeModel::Row row = *this->project_fs_model->append();
		row[this->project_fs_model_columns.icon] = entry.icon;
		row[this->project_fs_model_columns.filetype] = entry.filetype;
		row[this->project_fs_model_columns.filename] = entry.filename;
	}
}
