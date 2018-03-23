/*****************************************************************************
*    ProjectMetadata.hpp: Metadata of a project.
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

#ifndef __GIDE_PROJECT_METADATA_HPP__
#define __GIDE_PROJECT_METADATA_HPP__ 1

#include <glibmm.h>
#include <glibmm/i18n.h>

#include <utility>

#include <clocale>

#include "Macros.hpp"

namespace GIDE
{
	/**
	* @brief Contains all supported build systems.
	*/
	enum class ProjectBuildSystems
	{
		MAKE, // Only use make
		CMAKE // Use CMake and Make
	};

	/**
	* @brief Contains all supported programming languages for projects
	*/
	enum class ProjectProgrammingLanguages
	{
		CPP, // C++
		CPP1X, // C++11, C++14 or C++17
		C, // C
		C1X // C11, C14 or C17
	};

	/**
	* @brief Contains the metadata of any project.
	*/
	struct ProjectMetadata : public Glib::Object
	{
		Glib::ustring project_name;
		Glib::ustring project_author;
		ProjectProgrammingLanguages project_language;

		Glib::ustring gide_version;

		ProjectBuildSystems build_system;

		ProjectMetadata(void);
		ProjectMetadata(const ProjectMetadata& met);
		ProjectMetadata(ProjectMetadata&& met);
		ProjectMetadata(Glib::ustring name);
		ProjectMetadata(Glib::ustring name, Glib::ustring author);
		ProjectMetadata(
			Glib::ustring name,
			Glib::ustring author,
			ProjectProgrammingLanguages language
		);
		ProjectMetadata(
			Glib::ustring name,
			Glib::ustring author,
			ProjectProgrammingLanguages language,
			Glib::ustring gide_version
		);
		ProjectMetadata(
			Glib::ustring name,
			Glib::ustring author,
			ProjectProgrammingLanguages language,
			Glib::ustring gide_version,
			ProjectBuildSystems buildsys
		);

		ProjectMetadata& operator=(const ProjectMetadata& met);
		ProjectMetadata& operator=(ProjectMetadata&& met);
	};
}

#endif /* ~__GIDE_PROJECT_METADATA_HPP__ */
