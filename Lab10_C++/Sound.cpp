// Sound.cpp
// Runs on any computer
// Sound assets based off the original Space Invaders 
// Import these constants into your SpaceInvaders.c for sounds!
// Jonathan Valvano
// 1/17/2020
#include <stdint.h>
#include "Sound.h"
#include "Timer1.h"
#include "DAC.h"

#define BusClock 80000000
#define SampleFreq 11025

class Sound;
Sound* soundToPlay;

void playSample();

class Sound {
	
	public:	
	
		const unsigned char* wave;
		uint32_t length;
		uint32_t index;
		
		Sound(const unsigned char* wave, uint32_t length) {
		
			this->wave = wave;
			this->length = length;
			this->index = 0;
		}
		
		Sound(void) {}
		
		void play() {
			
			soundToPlay = this;

			Timer1_Init(&(playSample), BusClock/SampleFreq);
			
		}
		
		void play(int seek) {
					
			this->index = seek;
			soundToPlay = this;

			Timer1_Init(&(playSample), BusClock/SampleFreq);
			
		}
	
};

void playSample() {

	DAC_Out(soundToPlay->wave[(soundToPlay->index)++]);
	
	if (soundToPlay->index > soundToPlay->length) {
	
		Timer1A_Stop();
		soundToPlay->index = 0;
	
	}
}

Sound soundList[2] = {
	Sound(shoot, shootLength),
	Sound(invaderKilled, invaderKilledLength)
};
	
void Sound_Init(void){
// write this
	DAC_Init();
};

void Sound_Play(int index){
// write this
	soundList[index].play();
	
};
