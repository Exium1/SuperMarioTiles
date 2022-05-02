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

SlidePot my(1500,0);

extern "C" void DisableInterrupts(void);
extern "C" void EnableInterrupts(void);
extern "C" void SysTick_Handler(void);

void Buttons_Init() {
	
	SYSCTL_RCGCGPIO_R |= 0x10;
	while((SYSCTL_RCGCGPIO_R & 0x10) == 0) {};
		
	GPIO_PORTE_DEN_R |= 0xF;
	GPIO_PORTE_DIR_R &= ~0xF;

}

class Image;
void menuScreen();
void languageSelectScreen();
void difficultySelectScreen();
void Sound_Init();
void Sound_Play(int index);
void Timer1_Init(void(*task)(void), uint32_t period);
void Delay1ms(uint32_t);

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

ScreenMode currentScreen = MENU;
Language language = ENGLISH;
Sprite* spriteToAnimate;

int main(void){
  PLL_Init(Bus80MHz);       // Bus clock is 80 MHz 
  TExaS_Init();
  Random_Init(1);
  //Output_Init();
	Sound_Init();
	ST7735_InitR(INITR_REDTAB);
	ST7735_InvertDisplay(1);
	Buttons_Init();
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

void menuScreen() {
	
	Image MainMenuBackground(128, 160, MainMenuBackgroundSrc);
	Image GoldCoinBig(22, 29, GoldCoinBigSrc);
	
	Sprite GoldCoinSprite(53, 100, &GoldCoinBig);
	
	MainMenuBackground.draw(0, 160);	
	GoldCoinSprite.animate(FLOATING);
	
	// Continues only when any button is pressed, then released
	while (false && (GPIO_PORTE_DATA_R & 0xF) == 0) {};
	while ((GPIO_PORTE_DATA_R & 0xF) != 0) {};
		
	Delay1ms(3000);
		
	Timer0_Stop();
	currentScreen = LANG_SELECT;
		
	transitionCollapse();
}

void languageSelectScreen() {

	Image MarioWorldBackground(128, 160, MarioWorldBackgroundSrc);
	Image LanguageEnglish(92, 44, LanguageEnglishSrc);
	Image LanguageItaliano(92, 44, LanguageItalianoSrc);
	
	MarioWorldBackground.draw(0, 160);
	LanguageEnglish.draw(18, 68);
	LanguageItaliano.draw(18, 136);
	
	while (false && 1) {
	
		if ((GPIO_PORTE_DATA_R & 0x1) == 1) {
			language = ENGLISH;
			break;
		} else if ((GPIO_PORTE_DATA_R & 0x2) == 1) {
			language = ITALIANO;
			break;
		}
	}
		
	Delay1ms(3000);
	
	currentScreen = DIFF_SELECT;
		
	transitionCollapse();

}

void difficultySelectScreen() {

	Image MarioWorldBackground(128, 160, MarioWorldBackgroundSrc);
	Image DifficultyEasy(92, 44, DifficultyEasySrc);
	Image DifficultyNormal(92, 44, DifficultyNormalSrc);
	Image DifficultyHard(92, 44, DifficultyHardSrc);
	
	MarioWorldBackground.draw(0, 160);
	DifficultyEasy.draw(18, 51);
	DifficultyNormal.draw(18, 102);
	DifficultyHard.draw(18, 153);
	
	while (false && 1) {
	
		if ((GPIO_PORTE_DATA_R & 0x1) == 1) {
			break;
		} else if ((GPIO_PORTE_DATA_R & 0x2) == 1) {
			break;
		} else if ((GPIO_PORTE_DATA_R & 0x4) == 1) {
			break;
		}
	}
	
	Delay1ms(3000);
	
	currentScreen = GAME;
		
	transitionCollapse();

}

