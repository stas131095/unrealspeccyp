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

#ifndef __PLATFORM_H__
#define __PLATFORM_H__

#include "../std.h"

#pragma once

#if defined(_WINDOWS) || defined(_LINUX) || defined(_MAC)

#define USE_OAL
#define USE_GL
//#define USE_GLUT
#define USE_WXWIDGETS

#endif//_WINDOWS || _LINUX || _MAC

namespace xPlatform
{

enum eKeyFlags
{
	KF_DOWN = 0x01,
	KF_SHIFT = 0x02,
	KF_CTRL = 0x04,
	KF_ALT = 0x08,

	KF_KEMPSTON = 0x10,
	KF_CURSOR = 0x20,
	KF_QAOP = 0x40,
	KF_SINCLAIR2 = 0x80,

	KF_UI_SENDER = 0x100
};
enum eMouseAction { MA_MOVE, MA_BUTTON, MA_WHEEL };
enum eAction
{
	A_RESET, A_QUIT, A_TAPE_TOGGLE, A_TAPE_FAST_TOGGLE, A_DRIVE_NEXT,
	A_JOYSTICK_NEXT, A_SOUND_NEXT, A_VOLUME_NEXT,
	A_TRUE_SPEED_TOGGLE, A_MODE_48K_TOGGLE
};
enum eActionResult
{
	AR_TAPE_STARTED, AR_TAPE_STOPPED, AR_TAPE_NOT_INSERTED,
	AR_TAPE_FAST_SET, AR_TAPE_FAST_RESET,
	AR_DRIVE_A, AR_DRIVE_B, AR_DRIVE_C, AR_DRIVE_D,
	AR_OK,
	AR_ERROR
};

enum eJoystick { J_FIRST, J_KEMPSTON = J_FIRST, J_CURSOR, J_QAOP, J_SINCLAIR2, J_LAST };
enum eSound { S_FIRST, S_BEEPER = S_FIRST, S_AY, S_TAPE, S_LAST };
enum eVolume { V_FIRST, V_MUTE = V_FIRST, V_10, V_20, V_30, V_40, V_50, V_60, V_70, V_80, V_90, V_100, V_LAST };

struct eHandler
{
	eHandler();
	~eHandler();
	virtual void OnInit() = 0;
	virtual void OnDone() = 0;
	virtual void OnLoop() = 0;
	virtual const char* WindowCaption() = 0;
	virtual void OnKey(char key, dword flags) = 0;
	virtual void OnMouse(eMouseAction action, byte a, byte b) = 0;

	virtual bool OnOpenFile(const char* name) = 0;
	virtual bool OnSaveFile(const char* name) = 0;
	virtual eActionResult OnAction(eAction action) = 0;

	// data to draw
	virtual void* VideoData() = 0;
	virtual void* VideoDataUI() = 0;
	// pause/resume function for sync video by audio
	virtual void VideoPaused(bool paused) = 0;
	// audio
	virtual int	AudioSources() = 0;
	virtual void* AudioData(int source) = 0;
	virtual dword AudioDataReady(int source) = 0;
	virtual void AudioDataUse(int source, dword size) = 0;

	virtual bool TapeInserted() const = 0;
	virtual bool TapeStarted() const = 0;
	virtual bool FullSpeed() const = 0;
	virtual bool TrueSpeed() const = 0;
	virtual bool Mode48k() const = 0;
	virtual bool Quit() const = 0;

	virtual eJoystick	Joystick() const = 0;
	virtual eSound		Sound() const = 0;
	virtual eVolume		Volume() const = 0;
};

eHandler* Handler();

}
//namespace xPlatform

#endif//__PLATFORM_H__
