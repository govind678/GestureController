//==============================================================================
//
//  AudioFileStream.h
//  GestureController
//
//  Created by Govinda Ram Pingali on 3/8/14.
//  Copyright (c) 2014 GTCMT. All rights reserved.
//
//==============================================================================

#ifndef __GestureController__AudioFileStream__
#define __GestureController__AudioFileStream__

#include "GestureControllerHeader.h"
#include "Macros.h"

#include "AudioEffectSource.h"
#include "Limiter.h"


class AudioFileStream        :   public AudioSource
{
    
public:
    
    AudioFileStream(int sampleID, AudioDeviceManager& deviceManager);
    ~AudioFileStream();
    
    
    void loadAudioFile(String audioFilePath);
    
    void prepareToPlay(int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const AudioSourceChannelInfo& audioSourceChannelInfo) override;
    void releaseResources() override;
    
    void processAudioBlock(float** audioBuffer, int numSamples);
    
    
    void startPlayback();
    void stopPlayback();
    
    bool isPlaying();
    
    void setMode(int mode);
    int getMode();
    
    void addAudioEffect(int effectPosition, int effectID);
    void removeAudioEffect(int effectPosition);
    void setAudioEffectBypassState(int effectPosition, bool bypassState);
    
    void setEffectParameter(int effectPosition, int parameterID, float value);
    void setSampleParameter(int parameterID, float value);
    
    float getEffectParameter(int effectPosition, int parameterID);
    float getSampleParameter(int parameterID);
    
    int  getEffectType(int effectPosition);

    void setSmoothing(int effecPosition, int parameterID, float value);

    void beat(int beatNum);
    
    
private:
    
    void setLooping(bool looping);
    
    
    AudioDeviceManager&     deviceManager;
    
    AudioFormatManager      formatManager;
    AudioTransportSource    transportSource;
    ScopedPointer<AudioFormatReaderSource> currentAudioFileSource;
    
    OwnedArray<AudioEffectSource>   audioEffectSource;
    Array<bool>                     m_pbBypassStateArray;
    Array<bool>                     audioEffectInitialized;

    ScopedPointer<CLimiter>         m_pcLimiter;
    
    TimeSliceThread thread;
    
    int                             m_iSampleID;
    String                          m_sCurrentFilePath;
    bool                            m_bAudioCurrentlyPlaying;
    int                             m_iQuantization;
    int                             m_iButtonMode;
    
    int                             m_iBeat;
    
};

#endif /* defined(__GestureController__AudioFileStream__) */
