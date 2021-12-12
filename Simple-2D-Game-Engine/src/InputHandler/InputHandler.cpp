#include "InputHandler.h"

InputHandler* InputHandler::sInstance = nullptr;

InputHandler* InputHandler::Instance() {
	if (sInstance == nullptr) {
		sInstance = new InputHandler();
	}
	return sInstance;
}

void InputHandler::Release() {
	delete sInstance;
	sInstance = nullptr;
}

bool InputHandler::KeyDown(SDL_Scancode scanCode) {
	return mKeyboardStates[scanCode];
}

void InputHandler::Update() {
	mKeyboardStates = SDL_GetKeyboardState(NULL);
}