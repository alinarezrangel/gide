/*****************************************************************************
*    Project.hpp: Manages a project.
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

#ifndef __GIDE_PROJECT_HPP__
#define __GIDE_PROJECT_HPP__ 1

#include <glibmm.h>
#include <giomm.h>
#include <glibmm/i18n.h>

#include <clocale>

#include <list>

#include <boost/filesystem.hpp>

#include "Macros.hpp"
#include "ProjectFolder.hpp"
#include "ProjectTemplate.hpp"

namespace GIDE
{
	struct ProjectMetadata
	{
		Glib::ustring project_name;
		Glib::ustring project_author;
		Glib::ustring project_language;

		Glib::ustring gide_version;

		Glib::ustring build_system;
	};

	class Project : public Glib::Object
	{
		public:
			Project(void);
			Project(const Glib::ustring& path_to_folder);
			Project(const Project& copy);
			Project(Project&& move);
			virtual ~Project(void);

			bool is_valid(void);
			bool is_valid(void) const;
			bool create(
				const Glib::ustring& path_to_folder,
				ProjectTemplate& tplt,
				const ProjectMetadata& meta
			);
			bool read_from(const Glib::ustring& path_to_folder);
			bool validate_project_file(const Glib::ustring& filename);
			bool validate_project_file(const Glib::ustring& filename) const;

			Glib::RefPtr<ProjectFolder> get_main_folder(void);
			Glib::RefPtr<ProjectFolder> get_source_folder(void);
			Glib::RefPtr<ProjectFolder> get_include_folder(void);
			Glib::RefPtr<ProjectFolder> get_ui_folder(void);
			Glib::RefPtr<ProjectFolder> get_docs_folder(void);

		protected:
			void read_project_metadata(Glib::KeyFile& file);
			void save_project_metadata(Glib::KeyFile& file);

		private:
			bool valid;

			Glib::RefPtr<ProjectFolder> project_directory;
			ProjectMetadata metadata;
	};
}

#endif /* ~__GIDE_PROJECT_HPP__ */
