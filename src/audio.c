/*
 * RayLib library: audio.c
 *
 * Copyright 2020 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbraylib.h"

/* --- Audio device management functions --- */
// void InitAudioDevice( void );
// void CloseAudioDevice( void );
// bool IsAudioDeviceReady( void );
// void SetMasterVolume( float volume );

/* --- Wave/Sound loading/unloading functions --- */
// Wave LoadWave( const char *fileName );
// Sound LoadSound( const char *fileName );
// Sound LoadSoundFromWave( Wave wave );
// void UpdateSound( Sound sound, const void *data, int samplesCount );
// void UnloadWave( Wave wave );
// void UnloadSound( Sound sound );
// void ExportWave( Wave wave, const char *fileName );
// void ExportWaveAsCode( Wave wave, const char *fileName );

/* --- Wave/Sound management functions --- */
// void PlaySound( Sound sound );
// void StopSound( Sound sound );
// void PauseSound( Sound sound );
// void ResumeSound( Sound sound );
// void PlaySoundMulti( Sound sound );
// void StopSoundMulti( void );
// int GetSoundsPlaying( void );
// bool IsSoundPlaying( Sound sound );
// void SetSoundVolume( Sound sound, float volume );
// void SetSoundPitch( Sound sound, float pitch );
// void WaveFormat( Wave *wave, int sampleRate, int sampleSize, int channels );
// Wave WaveCopy( Wave wave );
// void WaveCrop( Wave *wave, int initSample, int finalSample );
// float *GetWaveData( Wave wave );

/* --- Music management functions --- */
// Music LoadMusicStream( const char *fileName );
// void UnloadMusicStream( Music music );
// void PlayMusicStream( Music music );
// void UpdateMusicStream( Music music );
// void StopMusicStream( Music music );
// void PauseMusicStream( Music music );
// void ResumeMusicStream( Music music );
// bool IsMusicPlaying( Music music );
// void SetMusicVolume( Music music, float volume );
// void SetMusicPitch( Music music, float pitch );
// void SetMusicLoopCount( Music music, int count );
// float GetMusicTimeLength( Music music );
// float GetMusicTimePlayed( Music music );

/* --- AudioStream management functions --- */
// AudioStream InitAudioStream( unsigned int sampleRate, unsigned int sampleSize, unsigned int channels );
// void UpdateAudioStream( AudioStream stream, const void *data, int samplesCount );
// void CloseAudioStream( AudioStream stream );
// bool IsAudioStreamProcessed( AudioStream stream );
// void PlayAudioStream( AudioStream stream );
// void PauseAudioStream( AudioStream stream );
// void ResumeAudioStream( AudioStream stream );
// bool IsAudioStreamPlaying( AudioStream stream );
// void StopAudioStream( AudioStream stream );
// void SetAudioStreamVolume( AudioStream stream, float volume );
// void SetAudioStreamPitch( AudioStream stream, float pitch );
// void SetAudioStreamBufferSizeDefault( int size );
