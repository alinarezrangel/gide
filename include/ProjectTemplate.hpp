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

namespace GIDE
{
	class ProjectTemplate : public Glib::Object
	{
		public:
			ProjectTemplate(void);
			ProjectTemplate(const ProjectTemplate&) = delete;
			ProjectTemplate(ProjectTemplate&&) = delete;
			virtual ~ProjectTemplate(void);

			virtual void create_template(Glib::RefPtr<ProjectFolder> folder);

			Glib::ustring get_name(void);
			Glib::ustring get_description(void);

		protected:
			ProjectTemplate(const Glib::ustring& name, const Glib::ustring& desc);

			void fill_file(
				Glib::RefPtr<ProjectFolder> folder,
				const Glib::ustring& filename,
				const Glib::ustring& filecontents
			);

		private:
			Glib::ustring template_name;
			Glib::ustring template_description;
	};

	namespace BuiltinProjectTemplates
	{
		class BasicCPPTemplate : public ProjectTemplate
		{
			public:
				BasicCPPTemplate(void);
				virtual ~BasicCPPTemplate(void);

				virtual void create_template(Glib::RefPtr<ProjectFolder> folder);
		};
	}
}

#endif /* ~__GIDE_PROJECT_TEMPLATE_HPP__ */
