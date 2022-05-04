#include "Sprite.h"
#include "ST7735.h"

class Tile {

	public:
		
		Sprite* sprite;
		bool clicked;
		bool onScreen;
		bool falling;
		int fallSpeed;
		int col;
	
		Tile(Sprite* sprite, bool falling, int fallSpeed, int col) {
		
			this->sprite = sprite;
			this->clicked = false;
			this->onScreen = false;
			this->falling = falling;
			this->fallSpeed = fallSpeed;
			this->col = col;
		
		}
		
		void fall() {
		
			ST7735_FillRect(this->sprite->x, this->sprite->y - this->sprite->image->height, this->sprite->image->width, this->fallSpeed, 0x07E0);
			
			this->sprite->y += this->fallSpeed;
			this->sprite->draw();
		
		}
		
		void draw() {
		
			this->sprite->draw();
		
		}
	
};
