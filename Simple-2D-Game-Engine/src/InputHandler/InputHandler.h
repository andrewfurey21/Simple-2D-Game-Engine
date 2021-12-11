#pragma once
#include "../Includes.h"

class InputHandler {

private:
	InputHandler();
	~InputHandler();

	static InputHandler* sInstance;
	const uint8_t* mKeyboardStates;


public:
	static InputHandler* Instance();
	static void Release();
	bool KeyDown(SDL_Scancode scanCode);
	void Update();

	int mouseX;
	int mouseY;
};

