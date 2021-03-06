/*
    CHIRPINO version 1.0
    This software is provided by ASIO Ltd trading as Chirp

        http://chirp.io

    and is distributed freely and without warranty under the Creative Commons licence CC BY-NC 3.0
  
        https://creativecommons.org/licenses/by-nc/3.0/
  
    Have fun
*/


#ifndef BEAK_H
#define BEAK_H


#include "application.h"
#include "Synth.h"


class Beak {
protected:
    static const byte CHIRP_STRING_LENGTH = 18;

    //0.0872 * 72000000 / 256; // 87.2ms in number of pulses at 72MHz/256 per pulse
    static const uint16_t BLOCK_TIME = 24525;

    static const byte DEFAULT_MAX_VOLUME = 255;

    static const int MINIMUM_FREE_RAM = 256;

    static const uint32_t phaseSteps[];

    byte maxVolume;

    uint32_t phaseStepForCharCode(const char charCode);

    virtual int16_t numberOfFrames();

    virtual void head(uint32_t phaseStep);
    virtual void append(uint32_t phaseStep);
    virtual void tail(uint32_t phaseStep);

public:
    static const byte BAD_CHIRP_CODE_WARNING = 1;
    static const byte CHIRP_STRING_LENGTH_WARNING = 2;
    static const byte TOO_LITTLE_RAM_WARNING = 4;

    Beak(byte volume = DEFAULT_MAX_VOLUME);
    void setVolume(byte volume = DEFAULT_MAX_VOLUME);

	byte chirp(const char *chirpStr);
	byte chirp(const char *chirpStr, char *enoughSpaceForFrames);
	byte chirp(const char *chirpStr, int16_t nFrames, SynthFrame *frames);
};


#endif
