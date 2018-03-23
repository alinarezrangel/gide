/*****************************************************************************
*    FileSystemTreeModel.hpp: File System abstractiong for use in TreeViews.
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

#ifndef __GIDE_FILE_SYSTEM_TREE_MODEL_HPP__
#define __GIDE_FILE_SYSTEM_TREE_MODEL_HPP__ 1

#include <gtkmm.h>
#include <glibmm/i18n.h>

#include <clocale>

#include "Macros.hpp"

namespace GIDE
{
	namespace TreeFileSystem
	{
		enum class FileType
		{
			FILE,
			FOLDER,
			SYMLINK,

			// Specific file types
			FILE_CPP_HEADER, // H, hh, hpp, h++
			FILE_CPP_SOURCE, // C, cc, cpp, c++
			FILE_C_HEADER, // h
			FILE_C_SOURCE, // c
			FILE_CSS, // css
			FILE_JAVASCRIPT, // js, jsx, jsdoc
			FILE_HTML, // htm, html, html5
			FILE_PROJECT, // pro
			FILE_GLADE, // glade, ui, xml
			FILE_GIT, // .gitignore, .gitkeep, etc
			FILE_MARKDOWN // md, mkd, markdown
		};

		Glib::ustring get_iconname_from_filetype(FileType tp);

		struct ModelColumn : public Gtk::TreeModel::ColumnRecord
		{
			ModelColumn(void);

			Gtk::TreeModelColumn<Glib::RefPtr<Gdk::Pixbuf>> icon;
			Gtk::TreeModelColumn<FileType> filetype;
			Gtk::TreeModelColumn<Glib::ustring> filename;
		};

		struct TreeEntry : public Glib::Object
		{
			TreeEntry(void);
			TreeEntry(FileType ft);
			TreeEntry(const Glib::ustring& fn);
			TreeEntry(FileType ft, const Glib::ustring& fn);

			Glib::RefPtr<Gdk::Pixbuf> icon;
			FileType filetype;
			Glib::ustring filename;
		};
	}
}

#endif /* ~__GIDE_FILE_SYSTEM_TREE_MODEL_HPP__ */
