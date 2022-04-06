#pragma once
#include "SDL.h";
/**
* Enumeration containing all the keys we need
*/
enum KEYS_PRESSED_LIST
{
	KEY_ESCAPE,KEY_R,KEY_G,KEY_B,KEY_W,KEY_A,KEY_S,KEY_D,SIZE_OF_KEYS_PRESSED_ENUM
};

/**
* Class Handling all the keyboard inputs
*/
class Input
{
public:
	/**
* Check which keys are being pressed
*/
	void Update(void);
	/**
* Check if a key is being pressed
*/
	bool KeyIsPressed(KEYS_PRESSED_LIST key);
	/**
* Reference to the Array of pressed keys
*/
	const bool* GetKeyPressedList() {
		return m_keysPressed;
	}
	Input();
	~Input();

private:
	/**
* SDL event to check for the key presses
*/
	SDL_Event m_event;
	/**
* Array of pressed keys
*/
	bool m_keysPressed[SIZE_OF_KEYS_PRESSED_ENUM];
};