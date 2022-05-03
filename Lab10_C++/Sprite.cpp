#include "Sprite.h"

Sprite* spriteToAnimate;

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
