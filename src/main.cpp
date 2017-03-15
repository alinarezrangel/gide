/*****************************************************************************
*    main.cpp: Starts the GIDE.
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

#include <gtkmm.h>
#include <gtksourceviewmm.h>

#include <clocale>

#include "GIDEMacros.hpp"
#include "GIDEApplication.hpp"
#include "GIDEApplicationWindow.hpp"

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");
	/*
	bindtextdomain (GETTEXT_PACKAGE, GIDE_LOCALEDIR);
	bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
	textdomain (GETTEXT_PACKAGE);
	*/

	Gsv::init();

	GIDE::Application application;

	auto window = GIDE::ApplicationWindow::create();

	return application.run(*window, argc, argv);
}
