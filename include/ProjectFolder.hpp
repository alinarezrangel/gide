/*****************************************************************************
*    ProjectFolder.hpp: Abstraction of a folder inside a project.
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

#ifndef __GIDE_PROJECT_FOLDER_HPP__
#define __GIDE_PROJECT_FOLDER_HPP__ 1

#include <glibmm.h>
#include <giomm.h>
#include <glibmm/i18n.h>

#include <clocale>

#include <memory>

#include <boost/filesystem.hpp>

#include "Macros.hpp"

namespace GIDE
{
	/**
	* @brief Represents and manages a folder that is inside a project.
	*/
	class ProjectFolder : public Glib::Object
	{
		public:
			typedef
				Glib::Dir::iterator
				iterator;
			typedef
				Glib::Dir::const_iterator
				const_iterator;

			ProjectFolder(void) = delete;

			/**
			* @brief Creates a folder in the specified path.
			*
			* @param folder_path The path to the folder.
			*/
			ProjectFolder(const Glib::ustring& folder_path);

			/**
			* @brief Copy constructor.
			*
			* @param folder Folder to copy (will be the same after this).
			*/
			ProjectFolder(const ProjectFolder& folder);

			/**
			* @brief Move constructor.
			*
			* @param move Folder to move.
			*/
			ProjectFolder(ProjectFolder&& move);

			/**
			* @brief Closes the folder.
			*/
			virtual ~ProjectFolder(void);

			/**
			* @brief Sets the folder to another.
			*
			* After this, there two folders will be the same.
			*
			* @param folder Folder to copy inside this.
			*/
			ProjectFolder& operator=(const ProjectFolder& folder);

			/**
			* @brief Gets an iterator.
			*
			* With this you can iterate on each file/folder of the folder.
			*
			* @return Iterator to the first item.
			*/
			iterator begin(void);

			/**
			* @brief Gets an iterator.
			*
			* With this you can iterate on each file/folder of the folder.
			*
			* @return Iterator past the last item.
			*/
			iterator end(void);

			/**
			* @brief Const version of begin.
			*
			* @return Iterator to the first item.
			*/
			const_iterator begin(void) const;

			/**
			* @brief Const version of end.
			*
			* @return Iterator past the last item.
			*/
			const_iterator end(void) const;

			/**
			* @brief Gets the path to the folder.
			*
			* Returns the same path passed on the construction.
			*
			* @return Path to this folder.
			*/
			Glib::ustring get_path(void);

			/**
			* @brief Creates a file.
			*
			* This method it's deprecated, use get_file and then create the file
			* using the returned Gio::File.
			*
			* @return Gio::File to the created file.
			*/
			Glib::RefPtr<Gio::File> create_file(const Glib::ustring& filename);

			/**
			* @brief Gets a file.
			*
			* The file not necessary exists, in that case you can create the file.
			*
			* @return Gio::File to the path.
			*/
			Glib::RefPtr<Gio::File> get_file(const Glib::ustring& filename);

			/**
			* @brief Const version of get_file.
			*
			* @return Gio::File to the path.
			*/
			Glib::RefPtr<Gio::File> get_file(const Glib::ustring& filename) const;

			/**
			* @brief Gets a subfolder from the folder.
			*
			* @param name Name of the subfolder
			*
			* @return The ProjectFolder that wraps the subfolder.
			*/
			Glib::RefPtr<ProjectFolder> get_subfolder(const Glib::ustring& name);

			/**
			* @brief Creates a subfolder and returns it.
			*
			* @param name Name of the subfolder.
			*
			* @return ProjectFolder to the created subfolder.
			*/
			Glib::RefPtr<ProjectFolder> create_subfolder(const Glib::ustring& name);

			/**
			* @brief Const version of get_subfolder.
			*
			* @param name Name of the subfolder
			*
			* @return The ProjectFolder that wraps the subfolder.
			*/
			Glib::RefPtr<ProjectFolder> get_subfolder(
				const Glib::ustring& name
			) const;

			/**
			* @brief Creates a ProjectFolder.
			*
			* @param folder_path Path to the folder.
			*
			* @return The ProjectFolder.
			*/
			static Glib::RefPtr<ProjectFolder> create_from_path(
				const Glib::ustring& folder_path
			);

		private:
			std::shared_ptr<Glib::Dir> directory;
			Glib::ustring path;
	};
}

#endif /* ~__GIDE_PROJECT_FOLDER_HPP__ */
