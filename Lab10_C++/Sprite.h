#include <stdint.h>
#include "ST7735.h"
#include "Images.h"
#include "Timer0.h"

#ifndef __Sprite_h
#define __Sprite_h

enum SpriteAnimateTypes {

	STILL,
	FLOATING,
	FALLING,
	SLIDING
	
};

class Sprite;
extern Sprite* spriteToAnimate;
void floatAnimation();

class Sprite {

	public: 
		
		// Bottom left
		int x;
		int y;
		Image* image;
	
		Sprite(int x, int y, Image* image) {
		
			this->x = x;
			this->y = y;
			this->image = image;
		
		}
		
		void draw() {
		
			this->image->draw(this->x, this->y);
			
		}
		
		void animate(SpriteAnimateTypes animation) {
	
			spriteToAnimate = this;
			
			if (animation == FLOATING) {
			
				Timer0_Init(&floatAnimation, 1600000); // 50 Hz - CoinAnimation

			}
		}
		
		void erase() {
		
			this->image->erase(this->x, this->y);
		
		}
};

#endif
