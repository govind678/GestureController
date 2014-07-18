//==============================================================================
//
//  AudioEngine.h
//  BeMotion
//
//  Created by Govinda Ram Pingali on 3/8/14.
//  Copyright (c) 2014 BeMotionLLC. All rights reserved.
//
//==============================================================================



#ifndef __BeMotion__AudioEngine__
#define __BeMotion__AudioEngine__

#include "BeMotionHeader.h"
#include "Macros.h"
#include "LiveAudioStream.h"
#include "AudioFileRecord.h"
#include "AudioMixerPlayer.h"
#include "LoadPreset.h"
#include "Metronome2.h"
//#include "TrimAudio.h"

class AudioEngine
{
public:
    
    AudioEngine();
    ~AudioEngine();
    
    
    void startLiveAudioStreaming();
    void stopLiveAudioStreaming();
    bool isLiveAudioRunning();
    
    int loadAudioFile(int sampleID, String filePath);
    void startPlayback(int sampleID);
    void stopPlayback(int sampleID);
    
    void setEffectParameter(int sampleID, int effectPosition, int parameterID, float value);
    float getEffectParameter(int sampleID, int effectPosition, int parameterID);
    int getEffectType(int sampleID, int effectPosition);
    
    void setSampleParameter(int sampleID, int parameterID, float value);
    float getSampleParameter(int sampleID, int parameterID);

    void setCurrentPresetBank(String presetBank);
    String  getCurrentPresetBank();
    
    void addAudioEffect(int sampleID, int effectPosition, int effectID);
    void removeAudioEffect(int sampleID, int effectPosition);
    
    void startRecordingAudioSample(int sampleID);
    void stopRecordingAudioSample(int sampleID);
    
    void startRecordingMaster(int sampleID);
    void stopRecordingMaster(int sampleID);
    
    void toggleRecordingPlaybackSample(int sampleID, bool toggle);
    
    void setSampleGestureControlToggle(int sampleID, int parameterID, bool toggle);
    void setEffectGestureControlToggle(int sampleID, int effectPosition, int parameterID, bool toggle);
    
    bool getSampleGestureControlToggle(int sampleID, int parameterID);
    bool getEffectGestureControlToggle(int sampleID, int effectPosition, int parameterID);
    
    float getSampleCurrentPlaybackTime(int sampleID);
    bool  getSamplePlaybackStatus(int sampleID);
    
    void beat(int beatNo);
    void setTempo(float newTempo);
    int getTempo();
    void startMetronome();
    void stopMetronome();
    bool getMetronomeStatus();
    
    void motionUpdate(float* motion);
    
    int loadFXPreset(String filepath);
    String getCurrentFXPack();
    
    float* getSamplesToDrawWaveform(int sampleID);
    
    
private:

    
//    ScopedPointer<LiveAudioStream>  liveAudioStream;
    
    ScopedPointer<AudioFileRecord>      audioFileRecorder;
    ScopedPointer<AudioMixerPlayer>     audioMixer;
    
    ScopedPointer<LoadPreset>           presetLoader;
//    ScopedPointer<TrimAudio>            audioTrimmer;
    
    ScopedPointer<Metronome2>           metronome;
    
    StringArray         recordingFilePathArray1;
    StringArray         recordingFilePathArray2;
    StringArray         playbackFilePathArray;
    
    
    String              currentRecordingPath1;
    String              currentRecordingPath2;
    String              currentPlaybackPath;
    
    Array<bool>         m_pbRecordingToggle;
    
    
    AudioDeviceManager                      sharedAudioDeviceManager;
    AudioDeviceManager::AudioDeviceSetup    deviceSetup;
    
    bool m_bLiveAudioThreadRunning;
    
    String              currentPresetBank;
    String              currentFXPack;
    
    int                 m_iCurrentPresetBankLoaded;
    int                 m_iCurrentFXPackLoaded;
    
};

#endif /* defined(__BeMotion__AudioEngine__) */
