/*****************************************************************************
*    Project.cpp: Manages a project.
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

#include "Project.hpp"

namespace GIDE
{
	Project::Project(void)
		: valid(false),
			project_directory(nullptr),
			metadata()
	{}

	Project::Project(const Glib::ustring& path_to_folder)
		: valid(true),
			project_directory(ProjectFolder::create_from_path(path_to_folder)),
			metadata()
	{}

	Project::Project(const Project& copy)
		: valid(copy.valid),
			project_directory(copy.project_directory),
			metadata(copy.metadata)
	{}

	Project::Project(Project&& move)
		: valid(move.valid),
			project_directory(move.project_directory),
			metadata(move.metadata)
	{}

	Project::~Project(void)
	{}

	bool Project::is_valid(void)
	{
		return this->valid;
	}

	bool Project::is_valid(void) const
	{
		return this->valid;
	}

	bool Project::create(
		const Glib::ustring& path_to_folder,
		std::shared_ptr<ProjectTemplate> tplt,
		const ProjectMetadata& meta
	)
	{
		this->metadata = meta;

		boost::filesystem::create_directory(
			boost::filesystem::path(path_to_folder)
		);

		this->project_directory = ProjectFolder::create_from_path(path_to_folder);

		tplt->create_template(this->project_directory, meta);

		Glib::KeyFile project_file;

		this->save_project_metadata(project_file);

		project_file.save_to_file(
			Glib::build_filename(path_to_folder, GIDE_PROJECT_FILENAME)
		);

		this->valid = true;

		return true;
	}

	bool Project::read_from(const Glib::ustring& path_to_folder)
	{
		this->project_directory = ProjectFolder::create_from_path(path_to_folder);

		this->valid = this->validate_project_file(
			Glib::build_filename(path_to_folder, GIDE_PROJECT_FILENAME)
		);

		Glib::KeyFile project_file;

		project_file.load_from_file(
			Glib::build_filename(path_to_folder, GIDE_PROJECT_FILENAME)
		);

		this->read_project_metadata(project_file);

		return this->valid;
	}

	bool Project::validate_project_file(const Glib::ustring& filename)
	{
		Glib::KeyFile project_file;

		project_file.load_from_file(filename);

		return
			project_file.has_group("GIDE") &&
			project_file.has_group("Project") &&
			project_file.has_group("Build") &&
			project_file.has_key("GIDE", "Version") &&
			project_file.has_key("Project", "Name") &&
			project_file.has_key("Project", "Author") &&
			project_file.has_key("Project", "Language") &&
			project_file.has_key("Build", "System");
	}

	bool Project::validate_project_file(const Glib::ustring& filename) const
	{
		Glib::KeyFile project_file;

		project_file.load_from_file(filename);

		return
			project_file.has_group("GIDE") &&
			project_file.has_group("Project") &&
			project_file.has_group("Build") &&
			project_file.has_key("GIDE", "Version") &&
			project_file.has_key("Project", "Name") &&
			project_file.has_key("Project", "Author") &&
			project_file.has_key("Project", "Language") &&
			project_file.has_key("Build", "System");
	}

	Glib::RefPtr<ProjectFolder> Project::get_main_folder(void)
	{
		return this->project_directory;
	}

	Glib::RefPtr<ProjectFolder> Project::get_source_folder(void)
	{
		return this->project_directory->get_subfolder(
			GIDE_FILENAME_SRC
		);
	}

	Glib::RefPtr<ProjectFolder> Project::get_include_folder(void)
	{
		return this->project_directory->get_subfolder(
			GIDE_FILENAME_INCLUDE
		);
	}

	Glib::RefPtr<ProjectFolder> Project::get_ui_folder(void)
	{
		return this->project_directory->get_subfolder(
			GIDE_FILENAME_UI
		);
	}

	Glib::RefPtr<ProjectFolder> Project::get_docs_folder(void)
	{
		return this->project_directory->get_subfolder(
			GIDE_FILENAME_DOCS
		);
	}

	void Project::read_project_metadata(Glib::KeyFile& file)
	{
		std::map<Glib::ustring, ProjectProgrammingLanguages> pl_map = {
			{"cpp", ProjectProgrammingLanguages::CPP},
			{"cpp1x", ProjectProgrammingLanguages::CPP1X},
			{"c", ProjectProgrammingLanguages::C},
			{"c1x", ProjectProgrammingLanguages::C1X}
		};

		std::map<Glib::ustring, ProjectBuildSystems> bs_map = {
			{"make", ProjectBuildSystems::MAKE},
			{"cmake", ProjectBuildSystems::CMAKE}
		};

		this->metadata.project_name = file.get_string("Project", "Name");
		this->metadata.project_author = file.get_string("Project", "Author");
		this->metadata.project_language =
			pl_map[file.get_string("Project", "Language")];

		this->metadata.gide_version = file.get_string("GIDE", "Version");

		this->metadata.build_system =
			bs_map[file.get_string("Build", "System")];
	}

	void Project::save_project_metadata(Glib::KeyFile& file)
	{
		std::map<ProjectProgrammingLanguages, Glib::ustring> pl_map = {
			{ProjectProgrammingLanguages::CPP, "cpp"},
			{ProjectProgrammingLanguages::CPP1X, "cpp1x"},
			{ProjectProgrammingLanguages::C, "c"},
			{ProjectProgrammingLanguages::C1X, "c1x"}
		};

		std::map<ProjectBuildSystems, Glib::ustring> bs_map = {
			{ProjectBuildSystems::MAKE, "make"},
			{ProjectBuildSystems::CMAKE, "cmake"}
		};

		file.set_string("Project", "Name", this->metadata.project_name);
		file.set_string("Project", "Author", this->metadata.project_author);
		file.set_string(
			"Project",
			"Language",
			pl_map[this->metadata.project_language]
		);

		file.set_string("GIDE", "Version", this->metadata.gide_version);

		file.set_string(
			"Build",
			"System",
			bs_map[this->metadata.build_system]
		);
	}
}
