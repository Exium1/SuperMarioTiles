#include "Sprite.h"

Sprite* spriteToAnimate;

void floatAnimation() {

	static int floatOffset = 0;
	static int floatDirection = 1;
	
	if (floatOffset > 8) floatDirection = 0;
	else if (floatOffset < 0) floatDirection = 1;
	
	if (floatDirection == 0) {
		ST7735_FillRect(spriteToAnimate->x, spriteToAnimate->y, spriteToAnimate->image->width, 1, 0x07E0);
		spriteToAnimate->y--;
		floatOffset--;
	} else { 
		ST7735_FillRect(spriteToAnimate->x, spriteToAnimate->y - spriteToAnimate->image->height + 1, spriteToAnimate->image->width, 1, 0x07E0);
		floatOffset++;
		spriteToAnimate->y++;
	}
	
	spriteToAnimate->draw();
}
