/*
Portable ZX-Spectrum emulator.
Copyright (C) 2001-2010 SMT, Dexus, Alone Coder, deathsoft, djdron, scor

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

#ifndef	__UI_MENU_H__
#define	__UI_MENU_H__

#include "../../ui/ui_dialog.h"

#pragma once

#ifdef USE_UI

namespace xOptions
{
class eOptionB;
}

namespace xUi
{

class eTree;

class eMenu : public eDialog
{
	typedef eDialog eInherited;
public:
	eMenu() : tree(NULL) {}
	virtual void Init();
protected:
	void CreateOption(int& i, xOptions::eOptionB* o);
	bool ChangeOption(bool next);
	void OnChangeOption();
	virtual bool OnKey(char key, dword flags);
protected:
	eTree* tree;
	enum { ITEMS_COUNT = 256 };
	xOptions::eOptionB* options[ITEMS_COUNT];
};

}
//namespace xUi

#endif//USE_UI

#endif//__UI_MENU_H__
