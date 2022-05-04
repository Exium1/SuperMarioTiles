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
void Sound_Init();
void Output_Init();
void Sound_Play(int index);
void Timer1_Init(void(*task)(void), uint32_t period);
void Delay1ms(uint32_t);
void gameUpdate();

bool ongoingGame = false;

enum ScreenMode {
	MENU,
	LANG_SELECT,
	DIFF_SELECT,
	GAME,
	PAUSE
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

ScreenMode currentScreen = GAME;
Language language = ENGLISH;
Difficulty difficulty = EASY;

extern Image* currentBackground;
extern Sprite* spriteToAnimate;

int main(void){
  PLL_Init(Bus80MHz);       // Bus clock is 80 MHz 
  TExaS_Init();
  Random_Init(859378);
  Output_Init();
	Sound_Init();
	Input_Init();
  EnableInterrupts();
	
	Sound_Play(0);
	
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
		
		if (currentScreen == PAUSE) {
		
		
		
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
	
	buttonIndex = 0;

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

void menuScreen() {
	
	Image MainMenuBackground(128, 160, MainMenuBackgroundSrc);
	Image GoldCoinBig(22, 29, GoldCoinBigSrc);
	
	Sprite GoldCoinSprite(53, 100, &GoldCoinBig);
	
	currentBackground = &MainMenuBackground;
	
	MainMenuBackground.draw(0, 160);	
	GoldCoinSprite.animate(FLOATING);
	
	IO_Touch(4, true);
	
	Timer0_Stop();
	currentScreen = LANG_SELECT;
		
	transitionCollapse();
}

void languageSelectScreen() {

	Image MarioWorldBackground(128, 160, MarioWorldBackgroundSrc);
	Image LanguageEnglish(92, 44, LanguageEnglishSrc);
	Image LanguageItaliano(92, 44, LanguageItalianoSrc);
	Image ButtonHighlighted(98, 50, ButtonHighlightedSrc);
	
	MarioWorldBackground.draw(0, 160);
	LanguageEnglish.draw(18, 68);
	LanguageItaliano.draw(18, 136);
	
	currentBackground = &MarioWorldBackground;
	
	bool languageChosen = false;

	while (1) {
		if (my.PosSect(2) == 0){
			ButtonHighlighted.draw(15, 71);
			LanguageEnglish.draw(18, 68);
						
			while(my.PosSect(2) == 0) {
				if (IO_Touch(4, false)) {
					language = ENGLISH;
					languageChosen = true;
					break;
				}
			}
			
			if (languageChosen) break;
			
			ButtonHighlighted.erase(15, 71);
			LanguageEnglish.draw(18, 68);
			
		}
		
		if (my.PosSect(2) == 1){
			ButtonHighlighted.draw(15, 139);
			LanguageItaliano.draw(18, 136);
						
			while(my.PosSect(2) == 1) {
				if (IO_Touch(4, false)) {
					language = ITALIANO;
					languageChosen = true;
					break;
				} 
			}
			
			if(languageChosen) break;
		
			ButtonHighlighted.erase(15, 139);
			LanguageItaliano.draw(18, 136);
			
		}
	}
		
	currentScreen = DIFF_SELECT;
		
	transitionCollapse();

}

void difficultySelectScreen() {

	Image MarioWorldBackground(128, 160, MarioWorldBackgroundSrc);
	Image DifficultyEasy(92, 44, DifficultyEasySrc);
	Image DifficultyNormal(92, 44, DifficultyNormalSrc);
	Image DifficultyHard(92, 44, DifficultyHardSrc);
	Image ButtonHighlighted(98, 50, ButtonHighlightedSrc);
	
	currentBackground = &MarioWorldBackground;
	
	MarioWorldBackground.draw(0, 160);
	DifficultyEasy.draw(18, 51);
	DifficultyNormal.draw(18, 102);
	DifficultyHard.draw(18, 153);
	
	bool difficultyChosen = false;
	
	if (language == ENGLISH){
		while (1) {
			if (my.PosSect(3) == 0){
				ButtonHighlighted.draw(15, 54);
				DifficultyEasy.draw(18, 51);
				
				while (my.PosSect(3) == 0) {
					if (IO_Touch(4, false)) {
						difficulty = EASY;
						difficultyChosen = true;
						break;
					}
				}
				
				if (difficultyChosen) break;
				
				ButtonHighlighted.erase(15, 54);
				DifficultyEasy.draw(18, 51);

			}

			if (my.PosSect(3) == 1){
				ButtonHighlighted.draw(15, 105);
				DifficultyNormal.draw(18, 102);
				
				while(my.PosSect(3) == 1) {
					if (IO_Touch(4, false)) {
						difficulty = NORMAL;
						difficultyChosen = true;
						break;
					}
				}
				
				if (difficultyChosen) break;
				
				ButtonHighlighted.erase(15, 105);
				DifficultyNormal.draw(18, 102);
			}
			
			if (my.PosSect(3) == 2){
				ButtonHighlighted.draw(15, 156);
				DifficultyHard.draw(18, 153);
				
				while (my.PosSect(3) == 2) {
					if (IO_Touch(4, false)) {
						difficulty = HARD;
						difficultyChosen = true;
						break;
					}
				}
				
				if (difficultyChosen) break;

				ButtonHighlighted.erase(15, 156);
				DifficultyHard.draw(18, 153);
			}
		}
	}
	
	if (language == ITALIANO){}//todo 
		
	currentScreen = GAME;
		
	transitionCollapse();

}

Tile* tiles[10] = {};
int tilesLength = 0;
	
Image BrickBlockMedium(32, 32, BrickBlockMediumSrc);

void gameScreen() {
	
	Image EasyLevelBackground(128, 160, EasyLevelBackgroundSrc);
	
//	Sprite Block1(0, 160, &BrickBlockMedium);
//	Sprite Block2(32, 128, &BrickBlockMedium);
//	Sprite Block3(32, 96, &BrickBlockMedium);
//	Sprite Block4(64, 64, &BrickBlockMedium);
//	Sprite Block5(0, 32, &BrickBlockMedium);
	
//	Block1.draw();
//	Block2.draw();
//	Block3.draw();
//	Block4.draw();
//	Block5.draw();
	
	EasyLevelBackground.draw(0, 160);
	
	currentBackground = &EasyLevelBackground;

	ST7735_FillRect(0, 0, 128, 12, 0x0000);
	
	for (int row = 0; row < 5; row++) {

		int col = Random() % 4;
		
		Sprite* tempBlock = new Sprite(32 * col, 160 - (32 * row), &BrickBlockMedium);		
		tiles[tilesLength] = new Tile(tempBlock, false, 10, col);
		
		tiles[tilesLength]->draw();
		
		tilesLength++;

	}

	// Countdown
	ST7735_DrawChar(61, 2, '3', 0xFFFF, 0x0000, 1);
	Delay1ms(1000);
	ST7735_DrawChar(61, 2, '2', 0xFFFF, 0x0000, 1);
	Delay1ms(1000);
	ST7735_DrawChar(61, 2, '1', 0xFFFF, 0x0000, 1);
	Delay1ms(1000);
	char* goString = "Go!";
	ST7735_DrawString(61, 8, goString, 0xFFFF);
	
	for (int i = 0; i < tilesLength; i++) {
		tiles[i]->falling = true;
	}
	
	Timer0_Init(&gameUpdate, 960000);
	
	ongoingGame = true;
	while(ongoingGame) {};
	
}

void gameUpdate() {

	for (int i = 0; i < tilesLength; i++) {
			
		if (tiles[i]->falling) tiles[i]->fall();
		
	}
	
	ST7735_FillRect(0, 0, 128, 12, 0x0000);
}

