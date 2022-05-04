#include "Sprite.h"
#include "ST7735.h"
#include "Random.h"

class Tile;

extern Tile* targetTile;
extern int playerScore;
extern int playerLives;
extern Image BlockBrick;

class Tile {

	public:
		
		Sprite* sprite;
		bool clicked;
		bool onScreen;
		bool falling;
		bool target;
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
			
			int boxTop = this->sprite->y - this->sprite->image->height;
			
			if (boxTop < 0) {
				ST7735_FillRect(this->sprite->x, 0, this->sprite->image->width, boxTop - (this->fallSpeed), 0x07E0);
			} else ST7735_FillRect(this->sprite->x, this->sprite->y - this->sprite->image->height, this->sprite->image->width, this->fallSpeed, 0x07E0);
			
			if (this->sprite->y >= 128 && (this->sprite->y - this->sprite->image->height) <= 128 && !this->clicked) {
				targetTile = this;
				this->target = true;
			} else this->target = false;
			
			this->sprite->y += this->fallSpeed;
			this->sprite->draw();
		
		}
		
		void draw() {
		
			this->sprite->draw();
		
		}
		
		void reset() {
			
			int newCol = Random() % 4;
		
			this->sprite->y = 0; // Move back to top
			this->sprite->x = newCol * 32; // Move into random col
			this->col = newCol;
			this->clicked = false;
			this->sprite->image = &BlockBrick;
		
		}
		
		void hitBottom() {
			
			if(this->clicked == true) {
			
				playerScore++;
			
			} else {
			
				playerScore -= 10;
				playerLives -= 1;
			
			}
			
			this->reset();
			
		}
	
};
