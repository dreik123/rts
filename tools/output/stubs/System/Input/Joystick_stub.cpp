#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "InputHandler.h"
#include "Joystick.h"

#include <SDL.h>

#include "System/Config/ConfigHandler.h"
#include "System/Log/ILog.h"
#include "System/EventHandler.h"

CONFIG(bool, JoystickEnabled).defaultValue(true).headlessValue(false);
CONFIG(int, JoystickUse).defaultValue(0);

Joystick* stick = NULL;

void InitJoystick()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void FreeJoystick() {
	if (stick != NULL) {
		delete stick;
		stick = NULL;
	}
}

Joystick::Joystick()
	: myStick(nullptr)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

Joystick::~Joystick()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool Joystick::HandleEvent(const SDL_Event& event)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
