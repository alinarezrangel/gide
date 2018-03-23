/*****************************************************************************
*    ProjectMetadata.cpp: Metadata of a project.
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

#include "ProjectMetadata.hpp"

namespace GIDE
{
	ProjectMetadata::ProjectMetadata(void)
		: project_name(""),
			project_author(""),
			project_language(ProjectProgrammingLanguages::CPP),
			gide_version(GIDE_VERSION),
			build_system(ProjectBuildSystems::MAKE)
	{}

	ProjectMetadata::ProjectMetadata(const ProjectMetadata& met)
		: project_name(met.project_name),
			project_author(met.project_author),
			project_language(met.project_language),
			gide_version(met.gide_version),
			build_system(met.build_system)
	{}

	ProjectMetadata::ProjectMetadata(ProjectMetadata&& met)
		: project_name(std::move(met.project_name)),
			project_author(std::move(met.project_author)),
			project_language(std::move(met.project_language)),
			gide_version(std::move(met.gide_version)),
			build_system(std::move(met.build_system))
	{}

	ProjectMetadata::ProjectMetadata(Glib::ustring name)
		: project_name(name),
			project_author(""),
			project_language(ProjectProgrammingLanguages::CPP),
			gide_version(GIDE_VERSION),
			build_system(ProjectBuildSystems::MAKE)
	{}

	ProjectMetadata::ProjectMetadata(Glib::ustring name, Glib::ustring author)
		: project_name(name),
			project_author(author),
			project_language(ProjectProgrammingLanguages::CPP),
			gide_version(GIDE_VERSION),
			build_system(ProjectBuildSystems::MAKE)
	{}

	ProjectMetadata::ProjectMetadata(
		Glib::ustring name,
		Glib::ustring author,
		ProjectProgrammingLanguages language
	)
		: project_name(name),
			project_author(author),
			project_language(language),
			gide_version(GIDE_VERSION),
			build_system(ProjectBuildSystems::MAKE)
	{}

	ProjectMetadata::ProjectMetadata(
		Glib::ustring name,
		Glib::ustring author,
		ProjectProgrammingLanguages language,
		Glib::ustring gide_version
	)
		: project_name(name),
			project_author(author),
			project_language(language),
			gide_version(gide_version),
			build_system(ProjectBuildSystems::MAKE)
	{}

	ProjectMetadata::ProjectMetadata(
		Glib::ustring name,
		Glib::ustring author,
		ProjectProgrammingLanguages language,
		Glib::ustring gide_version,
		ProjectBuildSystems buildsys
	)
		: project_name(name),
			project_author(author),
			project_language(language),
			gide_version(gide_version),
			build_system(buildsys)
	{}

	ProjectMetadata& ProjectMetadata::operator=(const ProjectMetadata& met)
	{
		this->project_name = met.project_name;
		this->project_author = met.project_author;
		this->project_language = met.project_language;
		this->gide_version = met.gide_version;
		this->build_system = met.build_system;

		return *this;
	}

	ProjectMetadata& ProjectMetadata::operator=(ProjectMetadata&& met)
	{
		this->project_name = std::move(met.project_name);
		this->project_author = std::move(met.project_author);
		this->project_language = std::move(met.project_language);
		this->gide_version = std::move(met.gide_version);
		this->build_system = std::move(met.build_system);

		return *this;
	}
}
