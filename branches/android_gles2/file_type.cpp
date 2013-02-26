/*
Portable ZX-Spectrum emulator.
Copyright (C) 2001-2012 SMT, Dexus, Alone Coder, deathsoft, djdron, scor

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "platform/platform.h"
#include "platform/io.h"
#include "file_type.h"

namespace xPlatform
{

eFileType* eFileType::FindByName(const char* name)
{
	int l = strlen(name);
	if(!l)
		return NULL;
	const char* ext = name + l;
	while(ext >= name && *ext != '.')
		--ext;
	++ext;
	char type[xIo::MAX_PATH_LEN];
	char* t = type;
	while(*ext)
	{
		char c = *ext++;
		if(c >= 'A' && c <= 'Z')
			c += 'a' - 'A';
		*t++ = c;
	}
	*t = '\0';
	return Find(type);
}

}
//namespace xPlatform
