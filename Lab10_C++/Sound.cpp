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
extern bool stopped;

void playSample();

class Sound {
	
	public:	
	
		const unsigned char* wave;
		uint32_t length;
		uint32_t index;
		bool loop;
		
		Sound(const unsigned char* wave, uint32_t length) {
		
			this->wave = wave;
			this->length = length;
			this->index = 0;
		}
		
		void play() {
			
			soundToPlay = this;

			Timer1_Init(&(playSample), BusClock/SampleFreq);
						
		}
		
		void play(int seek) {
					
			this->index = seek;
			soundToPlay = this;

			Timer1_Init(&(playSample), BusClock/SampleFreq);
			
		}
		
		void stop() {
			
			Timer1_Stop();
			
			this->index = 0;
			this->loop = false;
		
		}
	
};

void playSample() {

	DAC_Out(soundToPlay->wave[(soundToPlay->index)++]);
	
	if (soundToPlay->index > soundToPlay->length) {
	
		if (!soundToPlay->loop) soundToPlay->stop();
		
		soundToPlay->index = 0;
	
	}
}

Sound soundList[1] = {
	Sound(TitleTheme_Speed, TitleTheme_SpeedLength)
};
	
void Sound_Init(void){
// write this
	DAC_Init();
};

void Sound_Play(int index, bool loop){
// write this
	soundList[index].loop = loop;
	soundList[index].play(0);
	
};

void Sound_Stop(int index) {
	
	soundList[index].stop();

}

void Sound_Stop() {

	Timer1_Stop();

}
