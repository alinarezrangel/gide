/*****************************************************************************
*    ProjectTemplate.hpp: A project template manager.
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

#ifndef __GIDE_PROJECT_TEMPLATE_HPP__
#define __GIDE_PROJECT_TEMPLATE_HPP__ 1

#include <glibmm.h>
#include <giomm.h>
#include <glibmm/i18n.h>

#include <clocale>

#include <list>

#include <boost/filesystem.hpp>

#include "Macros.hpp"
#include "ProjectFolder.hpp"
#include "ProjectMetadata.hpp"

namespace GIDE
{
	/**
	* @brief A project template contains all structure and files for a project.
	*
	* The project template class should create and fills the files for the
	* project, it's recommended to have a "template dir" from which the files
	* will be copied.
	*/
	class ProjectTemplate : public Glib::Object
	{
		public:
			/**
			* @brief Creates the project template.
			*/
			ProjectTemplate(void);

			ProjectTemplate(const ProjectTemplate&) = delete;
			ProjectTemplate(ProjectTemplate&&) = delete;

			/**
			* @brief Destroyes the project template.
			*/
			virtual ~ProjectTemplate(void);

			/**
			* @brief Creates the project.
			*
			* This method should create and fills the files in a template-specific
			* structure. It's recommended to the project to have the following
			* folders on the root folder: A GIDE_FILENAME_SRC and
			* GIDE_FILENAME_INCLUDE for headers and sources (on languages that
			* have that separation) a GIDE_FILENAME_UI folder with the Glade files
			* and a GIDE_FILENAME_DOCS folder that the user can fill with it's
			* own documentation.
			*
			* @param folder Root folder in which the project should be created.
			*/
			virtual void create_template(
				Glib::RefPtr<ProjectFolder> folder,
				const ProjectMetadata& metadata
			);

			/**
			* @brief Gets the name of the template.
			*
			* @return The name of the template
			*/
			Glib::ustring get_name(void);

			/**
			* @brief Gets the description of the template.
			*
			* @return The description of the template
			*/
			Glib::ustring get_description(void);

		protected:
			/**
			* @brief Creates the project template.
			*
			* This constructor is protected, but the ProjectTemplate subclasses
			* should use it.
			*
			* @param name Name of the template.
			* @param desc Description of the template.
			*/
			ProjectTemplate(const Glib::ustring& name, const Glib::ustring& desc);

			/**
			* @brief Creates and fills a file.
			*
			* Creates the specified file and fills it with the specified content.
			*
			* @param folder Folder in which the file will be created.
			* @param filename The name of the new file.
			* @param filecontents The contents of the file.
			*/
			void fill_file(
				Glib::RefPtr<ProjectFolder> folder,
				const Glib::ustring& filename,
				const Glib::ustring& filecontents
			);

		private:
			Glib::ustring template_name;
			Glib::ustring template_description;
	};

	/**
	* @brief This namespace contains basic preistalled templates.
	*/
	namespace BuiltinProjectTemplates
	{
		/**
		* @brief This template creates a basic C++ and GTKmm project.
		*
		* Uses the Makefile build system, but this can be changed.
		*/
		class BasicCPPTemplate : public ProjectTemplate
		{
			public:
				BasicCPPTemplate(void);
				virtual ~BasicCPPTemplate(void);

				virtual void create_template(
					Glib::RefPtr<ProjectFolder> folder,
					const ProjectMetadata& metadata
				);
		};
	}
}

#endif /* ~__GIDE_PROJECT_TEMPLATE_HPP__ */
