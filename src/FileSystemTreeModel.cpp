/*****************************************************************************
*    GIDEFileSystemTreeModel.cpp: File System abstractiong for use in TreeViews.
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

#include "FileSystemTreeModel.hpp"

namespace GIDE
{
	namespace TreeFileSystem
	{
		Glib::ustring get_iconname_from_filetype(FileType tp)
		{
			if(tp == FileType::FOLDER)
				return GIDE_ICONSDIR "/" GIDE_FILEICONSDIR "/folder.png";

			return GIDE_ICONSDIR "/" GIDE_FILEICONSDIR "/text.png";
		}

		ModelColumn::ModelColumn(void)
		{
			this->add(this->icon);
			this->add(this->filetype);
			this->add(this->filename);
		}

		TreeEntry::TreeEntry(void)
			: filetype(FileType::FOLDER),
				filename("")
		{
			this->icon = Gdk::Pixbuf::create_from_file(get_iconname_from_filetype(this->filetype));
		}

		TreeEntry::TreeEntry(FileType ft)
			: filetype(ft),
				filename("")
		{
			this->icon = Gdk::Pixbuf::create_from_file(get_iconname_from_filetype(this->filetype));
		}

		TreeEntry::TreeEntry(const Glib::ustring& fn)
			: filetype(FileType::FOLDER),
				filename(fn)
		{
			this->icon = Gdk::Pixbuf::create_from_file(get_iconname_from_filetype(this->filetype));
		}

		TreeEntry::TreeEntry(FileType ft, const Glib::ustring& fn)
			: filetype(ft),
				filename(fn)
		{
			this->icon = Gdk::Pixbuf::create_from_file(get_iconname_from_filetype(this->filetype));
		}
	}
}
