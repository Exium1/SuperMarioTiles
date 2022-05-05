#include "Images.h"

Image* currentBackground;

int16_t backgroundPixel(int x, int y) {

	return currentBackground->src[(160 * 128) - (128 * y) - (x + 1)];

}
