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
};

void floatAnimation() {

	static int floatOffset = 0;
	static int floatDirection = 1;
	
	if (floatOffset > 8) floatDirection = 0;
	else if (floatOffset < 0) floatDirection = 1;
	
	spriteToAnimate->draw();
	
	if (floatDirection == 0) {
		spriteToAnimate->y--;
		floatOffset--;
	} else { 
		floatOffset++;
		spriteToAnimate->y++;
	}
}

#endif
