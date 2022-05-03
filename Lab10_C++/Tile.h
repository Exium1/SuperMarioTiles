#include "Sprite.h"

class Tile {

	public:
		
		Sprite* sprite;
		bool clicked;
		bool onScreen;
		bool falling;
		int scrollSpeed;
		int row;
	
		Tile(Sprite* sprite, bool falling, int scrollSpeed, int row) {
		
			this->sprite = sprite;
			this->clicked = false;
			this->onScreen = false;
			this->falling = falling;
			this->scrollSpeed = scrollSpeed;
			this->row = row;
		
		}
		
		void fall() {
		
			this->sprite->erase();
			this->sprite->y += this->scrollSpeed;
			this->sprite->draw();
		
		}
	
};
