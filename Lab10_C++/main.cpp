// main.cpp
// Runs on LM4F120/TM4C123
// Jonathan Valvano and Daniel Valvano
// This is a starter project for the EE319K Lab 10 in C++

// Last Modified: 1/17/2020 
// http://www.spaceinvaders.de/
// sounds at http://www.classicgaming.cc/classics/spaceinvaders/sounds.php
// http://www.classicgaming.cc/classics/spaceinvaders/playguide.php
/* This example accompanies the books
   "Embedded Systems: Real Time Interfacing to Arm Cortex M Microcontrollers",
   ISBN: 978-1463590154, Jonathan Valvano, copyright (c) 2017

   "Embedded Systems: Introduction to Arm Cortex M Microcontrollers",
   ISBN: 978-1469998749, Jonathan Valvano, copyright (c) 2017

 Copyright 2018 by Jonathan W. Valvano, valvano@mail.utexas.edu
    You may use, edit, run or distribute this file
    as long as the above copyright notice remains
 THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 VALVANO SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 For more information about my classes, my research, and my books, see
 http://users.ece.utexas.edu/~valvano/
 */
// ******* Possible Hardware I/O connections*******************
// Slide pot pin 1 connected to ground
// Slide pot pin 2 connected to PD2/AIN5
// Slide pot pin 3 connected to +3.3V 
// fire button connected to PE0
// special weapon fire button connected to PE1
// 8*R resistor DAC bit 0 on PB0 (least significant bit)
// 4*R resistor DAC bit 1 on PB1
// 2*R resistor DAC bit 2 on PB2
// 1*R resistor DAC bit 3 on PB3 (most significant bit)
// LED on PB4
// LED on PB5

// Backlight (pin 10) connected to +3.3 V
// MISO (pin 9) unconnected
// SCK (pin 8) connected to PA2 (SSI0Clk)
// MOSI (pin 7) connected to PA5 (SSI0Tx)
// TFT_CS (pin 6) connected to PA3 (SSI0Fss)
// CARD_CS (pin 5) unconnected
// Data/Command (pin 4) connected to PA6 (GPIO), high for data, low for command
// RESET (pin 3) connected to PA7 (GPIO)
// VCC (pin 2) connected to +3.3 V
// Gnd (pin 1) connected to ground

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <math.h>
#include "../inc/tm4c123gh6pm.h"
#include "PLL.h"
#include "ST7735.h"
#include "Random.h"
#include "SlidePot.h"
#include "Images.h"
#include "UART.h"
#include "Timer0.h"
#include "Sprite.h"
#include "TexaS.h"
#include "Tile.h"
#include "Timer2.h"

using namespace std;

SlidePot my(1500,0);

extern "C" void DisableInterrupts(void);
extern "C" void EnableInterrupts(void);
extern "C" void SysTick_Handler(void);

void Input_Init() {
	
	// Buttons
	SYSCTL_RCGCGPIO_R |= 0x10;
	while((SYSCTL_RCGCGPIO_R & 0x10) == 0) {};
		
	GPIO_PORTE_DEN_R |= 0x1F;
	GPIO_PORTE_DIR_R &= ~0x1F;
		
	// ADC
	ADC_Init();

}

class Image;
void menuScreen();
void languageSelectScreen();
void difficultySelectScreen();
void gameScreen();
void endScreen();
void Sound_Init();
void Sound_Stop(int index);
void Sound_Stop();
void Output_Init();
void Sound_Play(int index, bool loop);
void Timer1_Init(void(*task)(void), uint32_t period);
void Delay1ms(uint32_t);
void gameUpdate();

bool ongoingGame = false;
int playerScore = 0;
int playerLives = 3;
int fallTileCount = 0;

enum ScreenMode {
	MENU,
	LANG_SELECT,
	DIFF_SELECT,
	GAME,
	END
};

enum Language {
	ENGLISH,
	ITALIANO
};

enum Difficulty {
	EASY,
	NORMAL,
	HARD
};

ScreenMode currentScreen = MENU;
Language language = ENGLISH;
Difficulty difficulty = EASY;

extern Image* currentBackground;
extern Sprite* spriteToAnimate;

Tile* tiles[6] = {};
Tile* targetTile;
int tilesLength = 0;
	
Image BlockBrick(32, 32, BlockBrickSrc);
Image BlockBlank(32, 32, BlockBlankSrc);

int main(void){
  PLL_Init(Bus80MHz);       // Bus clock is 80 MHz 
  TExaS_Init();
  Random_Init(859378);
  Output_Init();
	Sound_Init();
	Input_Init();
  EnableInterrupts();
		
  while(1){	
		if (currentScreen == MENU) {
		
			menuScreen();
		}
		
		if (currentScreen == LANG_SELECT) {
		
			languageSelectScreen();
		
		}
		
		if (currentScreen == DIFF_SELECT) {
		
			difficultySelectScreen();
			
		}
		
		if (currentScreen == GAME) {
		
			gameScreen();
			
		}
		
		if (currentScreen == END) {
		
			endScreen();
		
		}
		
  }
}


void transitionCollapse() {
	
	for (int h = 0; h < 160; h++) {
	
		for (int w = 0; w < 128; w++) {
		
			if (w < 64) {
				ST7735_DrawPixel(w * 2, h, 0x0000);
			} else {
				ST7735_DrawPixel(127 - ((w - 64) * 2), h, 0x0000);
			}
		}
	}
	
	Delay1ms(300);
}

bool IO_Touch(int buttonIndex, bool wait) {
	
	// buttonIndex = 0;

	if (wait) {
		
		while ((GPIO_PORTE_DATA_R & (1 << buttonIndex)) == 0) {};
		while ((GPIO_PORTE_DATA_R & (1 << buttonIndex)) != 0) {};
		
		return true;
	
	} else {
		
		if (GPIO_PORTE_DATA_R & (1 << buttonIndex)) {
			
			while ((GPIO_PORTE_DATA_R & (1 << buttonIndex)) != 0) {};
			return true;
				
		} else return false;
	}
}

void printScore(int score) {

	for (int i = 2; i >= 0; i--) {
		int power = pow(10.0, i);
		
		int charValue = score / power;
		score = (score) % power;
		
		ST7735_OutChar(charValue + 0x30);
	}

}

void menuScreen() {
	
	Image MainMenuBackground(128, 160, MainMenuBackgroundSrc);
	Image GoldCoinBig(22, 29, GoldCoinBigSrc);
	Image SuperMarioTiles(120, 26, SuperMarioTilesSrc);
	
	currentBackground = &MainMenuBackground;
	
	Sprite GoldCoinSprite(53, 100, &GoldCoinBig);
		
	MainMenuBackground.draw(0, 160);	
	SuperMarioTiles.draw(4, 30);
	GoldCoinSprite.animate(FLOATING);
	
	Sound_Play(1, false);
		
	IO_Touch(4, true);
	
	Timer0_Stop();
	currentScreen = LANG_SELECT;
		
	transitionCollapse();
}

void languageSelectScreen() {
	
	Image MainMenuBackground(128, 160, MainMenuBackgroundSrc);
	Image LanguageEnglish(54, 7, LanguageEnglishSrc);
	Image LanguageItaliano(59, 7, LanguageItalianoSrc);
	Image RedButton(92, 44, RedButtonSrc);
	Image ButtonHighlighted(98, 50, ButtonHighlightedSrc);
	
	currentBackground = &MainMenuBackground;
	
	MainMenuBackground.draw(0, 160);
	
	RedButton.draw(18, 68);
	LanguageEnglish.draw(37, 50);
	
	RedButton.draw(18, 136);
	LanguageItaliano.draw(34, 118);
		
	bool languageChosen = false;

	while (1) {
		if (my.PosSect(2) == 0){
			ButtonHighlighted.draw(15, 71);
			LanguageEnglish.draw(37, 50);
						
			while(my.PosSect(2) == 0) {
				if (IO_Touch(4, false)) {
					language = ENGLISH;
					languageChosen = true;
					break;
				}
			}
			
			if (languageChosen) break;
			
			ButtonHighlighted.erase(15, 71);
			RedButton.draw(18, 68);
			LanguageEnglish.draw(37, 50);
			
		}
		
		if (my.PosSect(2) == 1){
			ButtonHighlighted.draw(15, 139);
			LanguageItaliano.draw(34, 118);
						
			while(my.PosSect(2) == 1) {
				if (IO_Touch(4, false)) {
					language = ITALIANO;
					languageChosen = true;
					break;
				} 
			}
			
			if(languageChosen) break;
		
			ButtonHighlighted.erase(15, 139);
			RedButton.draw(18, 136);
			LanguageItaliano.draw(34, 118);
			
		}
	}
		
	currentScreen = DIFF_SELECT;
		
	transitionCollapse();

}

void difficultySelectScreen() {

	Image MainMenuBackground(128, 160, MainMenuBackgroundSrc);
	Image ButtonHighlighted(98, 50, ButtonHighlightedSrc);
	Image RedButton(92, 44, RedButtonSrc);
	
	currentBackground = &MainMenuBackground;
	
	MainMenuBackground.draw(0, 160);
	
	bool difficultyChosen = false;
	
	if (language == ENGLISH) {
		
		Image DifficultyEasy = Image(43, 10, DifficultyEasy_ENSrc);
		Image DifficultyMedium = Image(63, 10, DifficultyMedium_ENSrc);
		Image DifficultyHard = Image(43, 10, DifficultyHard_ENSrc);
		
		RedButton.draw(18, 51);
		DifficultyEasy.draw(43, 34);
		
		RedButton.draw(18, 102);
		DifficultyMedium.draw(33, 85);

		RedButton.draw(18, 153);
		DifficultyHard.draw(43, 136);
		
		while (1) {
			if (my.PosSect(3) == 0){
				ButtonHighlighted.draw(15, 54);
				DifficultyEasy.draw(43, 34);
				
				while (my.PosSect(3) == 0) {
					if (IO_Touch(4, false)) {
						difficulty = EASY;
						difficultyChosen = true;
						break;
					}
				}
				
				if (difficultyChosen) break;
				
				ButtonHighlighted.erase(15, 54);
				RedButton.draw(18, 51);
				DifficultyEasy.draw(43, 34);

			}

			if (my.PosSect(3) == 1){
				ButtonHighlighted.draw(15, 105);
				DifficultyMedium.draw(33, 85);
				
				while(my.PosSect(3) == 1) {
					if (IO_Touch(4, false)) {
						difficulty = NORMAL;
						difficultyChosen = true;
						break;
					}
				}
				
				if (difficultyChosen) break;
				
				ButtonHighlighted.erase(15, 105);
				RedButton.draw(18, 102);
				DifficultyMedium.draw(33, 85);
			}
			
			if (my.PosSect(3) == 2){
				ButtonHighlighted.draw(15, 156);
				DifficultyHard.draw(43, 136);
				
				while (my.PosSect(3) == 2) {
					if (IO_Touch(4, false)) {
						difficulty = HARD;
						difficultyChosen = true;
						break;
					}
				}
				
				if (difficultyChosen) break;

				ButtonHighlighted.erase(15, 156);
				RedButton.draw(18, 153);
				DifficultyHard.draw(43, 136);
			}
		}
	
	} else if (language == ITALIANO) {
		
		Image DifficultyEasy = Image(57, 9, DifficultyEasy_ITSrc);
		Image DifficultyMedium = Image(53, 10, DifficultyMedium_ITSrc);
		Image DifficultyHard = Image(67, 7, DifficultyHard_ITSrc);
		
		RedButton.draw(18, 51);
		DifficultyEasy.draw(35, 33);
		
		RedButton.draw(18, 102);
		DifficultyMedium.draw(37, 85);

		RedButton.draw(18, 153);
		DifficultyHard.draw(30, 137);
	
		while (1) {
			if (my.PosSect(3) == 0){
				ButtonHighlighted.draw(15, 54);
				DifficultyEasy.draw(35, 33);
				
				while (my.PosSect(3) == 0) {
					if (IO_Touch(4, false)) {
						difficulty = EASY;
						difficultyChosen = true;
						break;
					}
				}
				
				if (difficultyChosen) break;
				
				ButtonHighlighted.erase(15, 54);
				RedButton.draw(18, 51);
				DifficultyEasy.draw(35, 33);

			}

			if (my.PosSect(3) == 1){
				ButtonHighlighted.draw(15, 105);
				DifficultyMedium.draw(37, 85);
				
				while(my.PosSect(3) == 1) {
					if (IO_Touch(4, false)) {
						difficulty = NORMAL;
						difficultyChosen = true;
						break;
					}
				}
				
				if (difficultyChosen) break;
				
				ButtonHighlighted.erase(15, 105);
				RedButton.draw(18, 102);
				DifficultyMedium.draw(37, 85);
			}
			
			if (my.PosSect(3) == 2){
				ButtonHighlighted.draw(15, 156);
				DifficultyHard.draw(30, 137);
				
				while (my.PosSect(3) == 2) {
					if (IO_Touch(4, false)) {
						difficulty = HARD;
						difficultyChosen = true;
						break;
					}
				}
				
				if (difficultyChosen) break;

				ButtonHighlighted.erase(15, 156);
				RedButton.draw(18, 153);
				DifficultyHard.draw(30, 137);
			}
		}
	
	}
	
	currentScreen = GAME;
		
	transitionCollapse();

}
void gameScreen() {
	
	Image MainMenuBackground(128, 160, MainMenuBackgroundSrc);
	MainMenuBackground.draw(0, 160);
	
	currentBackground = &MainMenuBackground;
	
	playerLives = 3;
	playerScore = 0;
	
	int fallSpeed;
	
	if (difficulty == EASY) fallSpeed = 1;
	else if (difficulty == NORMAL) fallSpeed = 2;
	else if (difficulty == HARD) fallSpeed = 4;
	
	for (int row = 0; row < 6; row++) {

		int col = Random() % 4;
		
		Sprite* tempBlock = new Sprite(32 * col, 160 - (32 * row), &BlockBrick);
		
		tiles[row] = new Tile(tempBlock, false, fallSpeed, col);
		if (row != 0) tiles[row]->draw();
		else tiles[row]->visible = false;
		
		tiles[row]->falling = true;
		
	}
	
	targetTile = tiles[1];
	
	ST7735_FillRect(0, 0, 128, 12, 0x0000); // Top bar
	ST7735_FillRect(0, 128, 128, 3, 0x35DD); // Hit bar
			
	Sound_Play(0, true);
	
	while ((GPIO_PORTE_DATA_R & 0xF) == 0) {}
		
	Timer0_Init((&gameUpdate), 960000);
	
	ongoingGame = true;
	while(ongoingGame) {};
		
	for (int i = 0; i < 6; i++) {
		delete tiles[i];
	}
		
	currentScreen = END;
		
	transitionCollapse();
			
}

void gameUpdate() {
		
	fallTileCount++;
	
	if ((GPIO_PORTE_DATA_R & 0xF) != 0) {
		
		int portEVal = GPIO_PORTE_DATA_R & 0xF;
		int index;
		
		if (portEVal == 1) index = 0;
		else if (portEVal == 2) index = 1;
		else if (portEVal == 4) index = 2;
		else if (portEVal == 8) index = 3;
		
		if (targetTile->col == index) {
			// right tile hit
			
			if (!targetTile->clicked) {
				
				targetTile->clicked = true;
				targetTile->sprite->image = &BlockBlank;
				
				playerScore += 1;
				
			}
			
		} else if (!targetTile->missed) {
						
			// wrong tile hit
			playerScore -= 1;
			playerLives -= 1;
			
			targetTile->missed = true;
			
		}
	}
	
	if (playerLives <= 0) {
	
		ongoingGame = false;
		Timer0_Stop();
		Sound_Stop(0);
		
		return;
	}

	for (int i = 0; i < 6; i++) {
		
		Tile* tile = tiles[i];
		
		if (tile->falling && ((fallTileCount % 2) == 0)) tile->fall();
		
		if (tile->sprite->y - tile->sprite->image->height > 160) {
			tile->offScreen();
		}
	}
	
	ST7735_FillRect(0, 0, 128, 12, 0x0000); // Top bar
	ST7735_FillRect(0, 128, 128, 3, 0x35DD); // Hit bar
		
	ST7735_SetTextColor(0xFFFF);
	ST7735_SetCursor(0, 0);
	
	int scoreTemp = playerScore;
	
	if (scoreTemp < 0) scoreTemp = 0;
	if (scoreTemp > 999) scoreTemp = 999;
	
	printScore(scoreTemp);
	
	ST7735_SetCursor(17, 0);
	ST7735_OutChar((playerLives >= 0 ? playerLives : 0) + 0x30);
	
}

void endScreen() {

	ST7735_FillScreen(0x0000);
	
	if (language == ENGLISH) {
	
		ST7735_DrawString(6, 2, "Game Over!", 0xFFFF);
		ST7735_DrawString(6, 6, "Score: ", 0xFFFF);
					
		ST7735_SetCursor(13, 6);
		printScore(playerScore);

		if (playerScore < 10) {
			
				ST7735_DrawString(5, 9, "Mama mia!", 0xFFFF);
				ST7735_DrawString(5, 10, "You suck!", 0xFFFF);			
			
		} else if (playerScore < 25) {
		
				ST7735_DrawString(4, 9, "You do better", 0xFFFF);		
				ST7735_DrawString(5, 10, "watching...", 0xFFFF);						
			
		} else if (playerScore < 50) {
		
				ST7735_DrawString(5, 9, "Not bad kid.", 0xFFFF);			
			
		} else if (playerScore < 100) {
		
				ST7735_DrawString(4, 9, "Almost there.", 0xFFFF);			
			
		} else {
			
				ST7735_DrawString(6, 9, "You saved", 0xFFFF);			
				ST7735_DrawString(3, 10, "Princess Melody!", 0xFFFF);			
			
		}
	} else if (language == ITALIANO) {
	
		ST7735_DrawString(3, 2, "Fine dei Giochi!", 0xFFFF);
		ST7735_DrawString(6, 6, "Punto: ", 0xFFFF);
					
		ST7735_SetCursor(13, 6);
		printScore(playerScore);

		if (playerScore < 10) {
			
				ST7735_DrawString(5, 9, "Mama mia!", 0xFFFF);
				ST7735_DrawString(5, 10, "Fai schifo!", 0xFFFF);			
			
		} else if (playerScore < 25) {
		
				ST7735_DrawString(4, 9, "Fai meglio a", 0xFFFF);		
				ST7735_DrawString(5, 10, "guardare...", 0xFFFF);						
			
		} else if (playerScore < 50) {
		
				ST7735_DrawString(5, 9, "Non cattivo", 0xFFFF);			
				ST7735_DrawString(6, 10, "ragazzo.", 0xFFFF);			
			
		} else if (playerScore < 100) {
		
				ST7735_DrawString(6, 9, "Quasi li.", 0xFFFF);			
			
		} else {
			
				ST7735_DrawString(4, 9, "Hai salvato la", 0xFFFF);			
				ST7735_DrawString(2, 10, "principessa Melody!", 0xFFFF);			
			
		}
	
	}
	
	while ((GPIO_PORTE_DATA_R & 0xF) == 0) {}
		
	currentScreen = MENU;
		
	transitionCollapse();
}

