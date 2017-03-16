/*****************************************************************************
*    ProjectFolder.cpp: Abstraction of a folder inside a project.
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

#include "ProjectFolder.hpp"

namespace GIDE
{
	ProjectFolder::ProjectFolder(const Glib::ustring& folder_path)
		: directory(new Glib::Dir(folder_path)),
			path(folder_path)
	{
	}

	ProjectFolder::ProjectFolder(const ProjectFolder& folder)
		: directory(folder.directory),
			path(folder.path)
	{
	}

	ProjectFolder::ProjectFolder(ProjectFolder&& move)
		: directory(move.directory),
			path(move.path)
	{
	}

	ProjectFolder::~ProjectFolder(void)
	{
	}

	ProjectFolder& ProjectFolder::operator=(const ProjectFolder& folder)
	{
		if(this == &folder)
			return *this;

		this->directory = folder.directory;
		this->path = folder.path;

		return *this;
	}

	ProjectFolder::iterator ProjectFolder::begin(void)
	{
		return this->directory->begin();
	}

	ProjectFolder::iterator ProjectFolder::end(void)
	{
		return this->directory->end();
	}

	ProjectFolder::const_iterator ProjectFolder::begin(void) const
	{
		return this->directory->begin();
	}

	ProjectFolder::const_iterator ProjectFolder::end(void) const
	{
		return this->directory->end();
	}

	Glib::ustring ProjectFolder::get_path(void)
	{
		return this->path;
	}

	Glib::RefPtr<Gio::File> ProjectFolder::create_file(
		const Glib::ustring& filename
	)
	{
		Glib::RefPtr<Gio::File> file =
			Gio::File::create_for_path(Glib::build_filename(this->path, filename));

		file->create_file();

		return file;
	}

	Glib::RefPtr<Gio::File> ProjectFolder::get_file(
		const Glib::ustring& filename
	)
	{
		Glib::RefPtr<Gio::File> file =
			Gio::File::create_for_path(Glib::build_filename(this->path, filename));

		return file;
	}

	Glib::RefPtr<Gio::File> ProjectFolder::get_file(
		const Glib::ustring& filename
	) const
	{
		Glib::RefPtr<Gio::File> file =
			Gio::File::create_for_path(Glib::build_filename(this->path, filename));

		return file;
	}

	Glib::RefPtr<ProjectFolder> ProjectFolder::get_subfolder(
		const Glib::ustring& name
	)
	{
		return ProjectFolder::create_from_path(
			Glib::build_filename(this->path, name)
		);
	}

	Glib::RefPtr<ProjectFolder> ProjectFolder::create_subfolder(
		const Glib::ustring& name
	)
	{
		boost::filesystem::create_directory(
			boost::filesystem::path(
				Glib::build_filename(this->path, name.c_str())
			)
		);

		return this->get_subfolder(name);
	}

	Glib::RefPtr<ProjectFolder> ProjectFolder::get_subfolder(
		const Glib::ustring& name
	) const
	{
		return ProjectFolder::create_from_path(
			Glib::build_filename(this->path, name)
		);
	}

	Glib::RefPtr<ProjectFolder> ProjectFolder::create_from_path(
		const Glib::ustring& folder_path
	)
	{
		return Glib::RefPtr<ProjectFolder>(new ProjectFolder(folder_path));
	}
}
