---
layout: default
title: module audio
permalink: audio
---

# **Function reference module: audio**

## Audio device management functions

#### InitAudioDevice()

```c

void InitAudioDevice( void );

```

Initialize audio device and context

---

#### CloseAudioDevice()

```c

void CloseAudioDevice( void );

```

Close the audio device and context

---

#### IsAudioDeviceReady()

```c

bool IsAudioDeviceReady( void );

```

Check if audio device has been initialized successfully

---

#### SetMasterVolume()

```c

void SetMasterVolume( float volume );

```

Set master volume ( listener )

---

## Wave/Sound loading/unloading functions

#### LoadWave()

```c

Wave LoadWave( const char *fileName );

```

Load wave data from file

---

#### LoadWaveFromMemory()

```c

Wave LoadWaveFromMemory( const char *fileType, const unsigned char *fileData, int dataSize );

```

Load wave from memory buffer

---

#### LoadSound()

```c

Sound LoadSound( const char *fileName );

```

Load sound from file

---

#### LoadSoundFromWave()

```c

Sound LoadSoundFromWave( Wave wave );

```

Load sound from wave data

---

#### UpdateSound()

```c

void UpdateSound( Sound sound, const void *data, int samplesCount );

```

Update sound buffer with new data

---

#### UnloadWave()

```c

void UnloadWave( Wave wave );

```

Unload wave data

---

#### UnloadSound()

```c

void UnloadSound( Sound sound );

```

Unload sound

---

#### ExportWave()

```c

bool ExportWave( Wave wave, const char *fileName );

```

Export wave data to file, returns true on success

---

#### ExportWaveAsCode()

```c

bool ExportWaveAsCode( Wave wave, const char *fileName );

```

Export wave sample data to code ( .h ), returns true on success

---

## Wave/Sound management functions

#### PlaySound()

```c

void PlaySound( Sound sound );

```

Play a sound

---

#### StopSound()

```c

void StopSound( Sound sound );

```

Stop playing a sound

---

#### PauseSound()

```c

void PauseSound( Sound sound );

```

Pause a sound

---

#### ResumeSound()

```c

void ResumeSound( Sound sound );

```

Resume a paused sound

---

#### PlaySoundMulti()

```c

void PlaySoundMulti( Sound sound );

```

Play a sound ( using multichannel buffer pool )

---

#### StopSoundMulti()

```c

void StopSoundMulti( void );

```

Stop any sound playing ( using multichannel buffer pool )

---

#### GetSoundsPlaying()

```c

int GetSoundsPlaying( void );

```

Get number of sounds playing in the multichannel

---

#### IsSoundPlaying()

```c

bool IsSoundPlaying( Sound sound );

```

Check if a sound is currently playing

---

#### SetSoundVolume()

```c

void SetSoundVolume( Sound sound, float volume );

```

Set volume for a sound ( 1.0 is max level )

---

#### SetSoundPitch()

```c

void SetSoundPitch( Sound sound, float pitch );

```

Set pitch for a sound ( 1.0 is base level )

---

#### WaveFormat()

```c

void WaveFormat( Wave *wave, int sampleRate, int sampleSize, int channels );

```

Convert wave data to desired format

---

#### WaveCopy()

```c

Wave WaveCopy( Wave wave );

```

Copy a wave to a new wave

---

#### WaveCrop()

```c

void WaveCrop( Wave *wave, int initSample, int finalSample );

```

Crop a wave to defined samples range

---

#### LoadWaveSamples()

```c

float *LoadWaveSamples( Wave wave );

```

Load samples data from wave as a floats array

---

#### UnloadWaveSamples()

```c

void UnloadWaveSamples( float *samples );

```

Unload samples data loaded with LoadWaveSamples(  )

---

## Music management functions

#### LoadMusicStream()

```c

Music LoadMusicStream( const char *fileName );

```

Load music stream from file

---

#### UnloadMusicStream()

```c

void UnloadMusicStream( Music music );

```

Unload music stream

---

#### PlayMusicStream()

```c

void PlayMusicStream( Music music );

```

Start music playing

---

#### UpdateMusicStream()

```c

void UpdateMusicStream( Music music );

```

Updates buffers for music streaming

---

#### StopMusicStream()

```c

void StopMusicStream( Music music );

```

Stop music playing

---

#### PauseMusicStream()

```c

void PauseMusicStream( Music music );

```

Pause music playing

---

#### ResumeMusicStream()

```c

void ResumeMusicStream( Music music );

```

Resume playing paused music

---

#### IsMusicPlaying()

```c

bool IsMusicPlaying( Music music );

```

Check if music is playing

---

#### SetMusicVolume()

```c

void SetMusicVolume( Music music, float volume );

```

Set volume for music ( 1.0 is max level )

---

#### SetMusicPitch()

```c

void SetMusicPitch( Music music, float pitch );

```

Set pitch for a music ( 1.0 is base level )

---

#### GetMusicTimeLength()

```c

float GetMusicTimeLength( Music music );

```

Get music time length ( in seconds )

---

#### GetMusicTimePlayed()

```c

float GetMusicTimePlayed( Music music );

```

Get current music time played ( in seconds )

---

## AudioStream management functions

#### InitAudioStream()

```c

AudioStream InitAudioStream( unsigned int sampleRate, unsigned int sampleSize, unsigned int channels );

```

Init audio stream ( to stream raw audio pcm data )

---

#### UpdateAudioStream()

```c

void UpdateAudioStream( AudioStream stream, const void *data, int samplesCount );

```

Update audio stream buffers with data

---

#### CloseAudioStream()

```c

void CloseAudioStream( AudioStream stream );

```

Close audio stream and free memory

---

#### IsAudioStreamProcessed()

```c

bool IsAudioStreamProcessed( AudioStream stream );

```

Check if any audio stream buffers requires refill

---

#### PlayAudioStream()

```c

void PlayAudioStream( AudioStream stream );

```

Play audio stream

---

#### PauseAudioStream()

```c

void PauseAudioStream( AudioStream stream );

```

Pause audio stream

---

#### ResumeAudioStream()

```c

void ResumeAudioStream( AudioStream stream );

```

Resume audio stream

---

#### IsAudioStreamPlaying()

```c

bool IsAudioStreamPlaying( AudioStream stream );

```

Check if audio stream is playing

---

#### StopAudioStream()

```c

void StopAudioStream( AudioStream stream );

```

Stop audio stream

---

#### SetAudioStreamVolume()

```c

void SetAudioStreamVolume( AudioStream stream, float volume );

```

Set volume for audio stream ( 1.0 is max level )

---

#### SetAudioStreamPitch()

```c

void SetAudioStreamPitch( AudioStream stream, float pitch );

```

Set pitch for audio stream ( 1.0 is base level )

---

#### SetAudioStreamBufferSizeDefault()

```c

void SetAudioStreamBufferSizeDefault( int size );

```

Default size for new audio streams

---