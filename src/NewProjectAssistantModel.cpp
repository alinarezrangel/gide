/*****************************************************************************
*    NewProjectAssistantModel.cpp: Models for comboboxes and others for the
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

#include "NewProjectAssistantModel.hpp"

namespace GIDE
{
	namespace NewProjectAssistantModels
	{
		namespace ProgrammingLanguage
		{
			ModelColumn::ModelColumn(void)
			{
				this->add(this->language);
				this->add(this->name);
			}

			TreeEntry::TreeEntry(void)
				: name(""),
					language(ProjectProgrammingLanguages::CPP)
			{}

			TreeEntry::TreeEntry(
				ProjectProgrammingLanguages lang
			)
				: name(""),
					language(lang)
			{}

			TreeEntry::TreeEntry(
				ProjectProgrammingLanguages lang,
				Glib::ustring name
			)
				: name(name),
					language(lang)
			{}
		}

		namespace BuildSystem
		{
			ModelColumn::ModelColumn(void)
			{
				this->add(this->system);
				this->add(this->name);
			}

			TreeEntry::TreeEntry(void)
				: name(""),
					system(ProjectBuildSystems::MAKE)
			{}

			TreeEntry::TreeEntry(
				ProjectBuildSystems sys
			)
				: name(""),
					system(sys)
			{}

			TreeEntry::TreeEntry(
				ProjectBuildSystems sys,
				Glib::ustring name
			)
				: name(name),
					system(sys)
			{}
		}

		namespace ProjectTemplateNS
		{
			ModelColumn::ModelColumn(void)
			{
				this->add(this->templt);
				this->add(this->name);
				this->add(this->description);
			}

			TreeEntry::TreeEntry(void)
				: name(""),
					description(""),
					templt(std::shared_ptr<ProjectTemplate>(nullptr))
			{}

			TreeEntry::TreeEntry(
				std::shared_ptr<ProjectTemplate> tpl
			)
				: name(""),
					description(""),
					templt(tpl)
			{}

			TreeEntry::TreeEntry(
				std::shared_ptr<ProjectTemplate> tpl,
				Glib::ustring name
			)
				: name(name),
					description(""),
					templt(tpl)
			{}

			TreeEntry::TreeEntry(
				std::shared_ptr<ProjectTemplate> tpl,
				Glib::ustring name,
				Glib::ustring desc
			)
				: name(name),
					description(desc),
					templt(tpl)
			{}
		}
	}
}
