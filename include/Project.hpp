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
	/**
	* @brief Contains the metadata of any project.
	*/
	struct ProjectMetadata
	{
		Glib::ustring project_name;
		Glib::ustring project_author;
		Glib::ustring project_language;

		Glib::ustring gide_version;

		Glib::ustring build_system;
	};

	/**
	* @brief The project class manages a GIDE project.
	*/
	class Project : public Glib::Object
	{
		public:
			/**
			* @brief Creates a new invalid void project.
			*/
			Project(void);

			/**
			* @brief Creates a project that points to the specified path.
			*
			* @param path_to_folder Path to the folder that contains the project.
			*/
			Project(const Glib::ustring& path_to_folder);

			/**
			* @brief Creates a project as a copy of another.
			*/
			Project(const Project& copy);

			/**
			* @brief Creates a project and moves all data from another.
			*/
			Project(Project&& move);

			/**
			* @brief Destroyes and frees the project.
			*/
			virtual ~Project(void);

			/**
			* @brief Gets if the project is valid.
			*
			* @return true if the project is valid, false otherwise.
			*/
			bool is_valid(void);

			/**
			* @brief Const version of is_valid.
			*/
			bool is_valid(void) const;

			/**
			* @brief Creates the project.
			*
			* Calling this will close any opened project and if fails will leave
			* the project object in an undefined state in which any operation it's
			* undefined.
			*
			* @param path_to_folder Path to the folder.
			* @param tplt Template of the new project.
			* @param meta Project metadata.
			*
			* @return true if the project was created successfully, false otherwise.
			*/
			bool create(
				const Glib::ustring& path_to_folder,
				ProjectTemplate& tplt,
				const ProjectMetadata& meta
			);

			/**
			* @brief Loads a project.
			*
			* Loads the project from the specified folder, which should contain a
			* file named GIDE_PROJECT_FILENAME.
			*
			* @param path_to_folder Path to the existing project.
			*
			* @return true if the project was successfully readed, false otherwise.
			*/
			bool read_from(const Glib::ustring& path_to_folder);

			/**
			* @brief Validates a project file in the specified location.
			*
			* @param filename Path to the project file.
			*
			* @return true if the file is valid and false otherwise.
			*/
			bool validate_project_file(const Glib::ustring& filename);

			/**
			* @brief const version of validate_project_file
			*/
			bool validate_project_file(const Glib::ustring& filename) const;

			/**
			* @brief Gets the root folder of the project.
			*
			* @return RefPtr to the root folder.
			*/
			Glib::RefPtr<ProjectFolder> get_main_folder(void);

			/**
			* @brief Gets the GIDE_FILENAME_SRC folder.
			*
			* @return RefPtr to the source directory (if exists).
			*/
			Glib::RefPtr<ProjectFolder> get_source_folder(void);

			/**
			* @brief Gets the GIDE_FILENAME_INCLUDE folder.
			*
			* @return RefPtr to the include directory (if exists).
			*/
			Glib::RefPtr<ProjectFolder> get_include_folder(void);

			/**
			* @brief Gets the GIDE_FILENAME_UI folder.
			*
			* @return RefPtr to the UI Glade directory (if exists).
			*/
			Glib::RefPtr<ProjectFolder> get_ui_folder(void);

			/**
			* @brief Gets the GIDE_FILENAME_DOCS folder.
			*
			* @return RefPtr to the docs directory (if exists).
			*/
			Glib::RefPtr<ProjectFolder> get_docs_folder(void);

		protected:
			/**
			* @brief Reads the project metadata from a keyfile.
			*
			* @param file KeyFile to read.
			*/
			void read_project_metadata(Glib::KeyFile& file);

			/**
			* @brief Saves the project metadata to a keyfile.
			*
			* @param file KeyFile in which save the current metadata.
			*/
			void save_project_metadata(Glib::KeyFile& file);

		private:
			bool valid;

			Glib::RefPtr<ProjectFolder> project_directory;
			ProjectMetadata metadata;
	};
}

#endif /* ~__GIDE_PROJECT_HPP__ */
