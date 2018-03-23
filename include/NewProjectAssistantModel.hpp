/*****************************************************************************
*    NewProjectAssistantModel.hpp: Models for comboboxes and others for the
*                                  NewProjectAssistant.
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

#ifndef __GIDE_NEW_PROJECT_ASSISTANT_MODEL_HPP__
#define __GIDE_NEW_PROJECT_ASSISTANT_MODEL_HPP__ 1

#include <gtkmm.h>
#include <glibmm/i18n.h>

#include <clocale>

#include <memory>

#include "Macros.hpp"
#include "ProjectMetadata.hpp"
#include "ProjectTemplate.hpp"

namespace GIDE
{
	namespace NewProjectAssistantModels
	{
		namespace ProgrammingLanguage
		{
			struct ModelColumn : public Gtk::TreeModel::ColumnRecord
			{
				ModelColumn(void);

				Gtk::TreeModelColumn<ProjectProgrammingLanguages> language;
				Gtk::TreeModelColumn<Glib::ustring> name;
			};

			struct TreeEntry : public Glib::Object
			{
				TreeEntry(void);
				TreeEntry(
					ProjectProgrammingLanguages lang
				);
				TreeEntry(
					ProjectProgrammingLanguages lang,
					Glib::ustring name
				);

				Glib::ustring name;
				ProjectProgrammingLanguages language;
			};
		}

		namespace BuildSystem
		{
			struct ModelColumn : public Gtk::TreeModel::ColumnRecord
			{
				ModelColumn(void);

				Gtk::TreeModelColumn<ProjectBuildSystems> system;
				Gtk::TreeModelColumn<Glib::ustring> name;
			};

			struct TreeEntry : public Glib::Object
			{
				TreeEntry(void);
				TreeEntry(
					ProjectBuildSystems sys
				);
				TreeEntry(
					ProjectBuildSystems sys,
					Glib::ustring name
				);

				Glib::ustring name;
				ProjectBuildSystems system;
			};
		}

		namespace ProjectTemplateNS
		{
			struct ModelColumn : public Gtk::TreeModel::ColumnRecord
			{
				ModelColumn(void);

				Gtk::TreeModelColumn<std::shared_ptr<ProjectTemplate>> templt;
				Gtk::TreeModelColumn<Glib::ustring> name;
				Gtk::TreeModelColumn<Glib::ustring> description;
			};

			struct TreeEntry : public Glib::Object
			{
				TreeEntry(void);
				TreeEntry(
					std::shared_ptr<ProjectTemplate> tpl
				);
				TreeEntry(
					std::shared_ptr<ProjectTemplate> tpl,
					Glib::ustring name
				);
				TreeEntry(
					std::shared_ptr<ProjectTemplate> tpl,
					Glib::ustring name,
					Glib::ustring desc
				);

				Glib::ustring name;
				Glib::ustring description;
				std::shared_ptr<ProjectTemplate> templt;
			};
		}
	}
}

#endif /* ~__GIDE_NEW_PROJECT_ASSISTANT_MODEL_HPP__ */
