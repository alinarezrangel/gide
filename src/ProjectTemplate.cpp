/*****************************************************************************
*    ProjectTemplate.cpp: A project template manager.
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

#include "ProjectTemplate.hpp"

namespace GIDE
{
	ProjectTemplate::ProjectTemplate(void)
		: template_name(""),
			template_description("")
	{}

	ProjectTemplate::ProjectTemplate(
		const Glib::ustring& name,
		const Glib::ustring& desc
	)
		: template_name(name),
			template_description(desc)
	{}

	ProjectTemplate::~ProjectTemplate(void)
	{}

	void ProjectTemplate::create_template(Glib::RefPtr<ProjectFolder> folder)
	{
		return;
	}

	Glib::ustring ProjectTemplate::get_name(void)
	{
		return this->template_name;
	}

	Glib::ustring ProjectTemplate::get_description(void)
	{
		return this->template_description;
	}

	void ProjectTemplate::fill_file(
		Glib::RefPtr<ProjectFolder> folder,
		const Glib::ustring& filename,
		const Glib::ustring& filecontents
	)
	{
		auto file = folder->get_file(filename);

		auto stream = file->create_file();

		stream->write(filecontents);
		stream->close();
	}

	namespace BuiltinProjectTemplates
	{
		BasicCPPTemplate::BasicCPPTemplate(void)
			: ProjectTemplate(
				_("Basic C++ template"),
				_("A basic C++ template that uses gtkmm 3")
			)
		{}

		BasicCPPTemplate::~BasicCPPTemplate(void)
		{}

		void BasicCPPTemplate::create_template(Glib::RefPtr<ProjectFolder> folder)
		{
			this->fill_file(folder, "hello.world.txt", "Hello World\n");
		}
	}
}
