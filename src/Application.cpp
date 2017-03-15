/*****************************************************************************
*    GIDEApplication.cpp: Manages all GIDE application commands.
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

#include "Application.hpp"

namespace GIDE
{
	Application::Application(void)
		: Gtk::Application(
			"org.gide.application",
			Gio::APPLICATION_HANDLES_COMMAND_LINE
			)
	{
	}

	Application::~Application(void)
	{
	}

	int Application::on_command_line(
		const Glib::RefPtr<Gio::ApplicationCommandLine>& command_line
	)
	{
		Glib::OptionContext context;

		Glib::OptionGroup main_options(
			"options",
			_("Main options"),
			_("Show help of all general options")
		);

		Glib::OptionEntry version_option;
		bool version_option_flag = false;

		version_option.set_long_name(_("version"));
		version_option.set_description(_("Prints the G_IDE version and exists"));

		main_options.add_entry(version_option, version_option_flag);

		Glib::OptionGroup gtk_options(gtk_get_option_group(true));

		context.add_group(main_options);
		context.add_group(gtk_options);

		int argc = 0;
		char** argv = command_line->get_arguments(argc);
		context.parse(argc, argv);

		this->activate();

		if(version_option_flag)
		{
			g_print(Glib::ustring::compose(_("GIDE v%1\n"), GIDE_VERSION).c_str());
		}

		return 0;
	}
}
