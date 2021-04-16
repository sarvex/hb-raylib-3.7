/*
 * RayLib library: audio.c
 * version 3.5
 *
 * Copyright 2021 Leonardo Mendez ( mlmgerencir at gmail com )
 * Copyright 2021 Maurizio la Cecilia ( m.lacecilia at gmail com )
 * Copyright 2020 - 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbraylib.h"

//------------------------------------------------------------------------------------
// Audio Loading and Playing Functions (Module: audio)
//------------------------------------------------------------------------------------

// Audio device management functions
// void InitAudioDevice(void);                                     // Initialize audio device and context
HB_FUNC( INITAUDIODEVICE )
{
   InitAudioDevice();
}

// void CloseAudioDevice(void);                                    // Close the audio device and context
HB_FUNC( CLOSEAUDIODEVICE )
{
   CloseAudioDevice();
}

// bool IsAudioDeviceReady(void);                                  // Check if audio device has been initialized successfully
HB_FUNC( ISAUDIODEVICEREADY )
{
   hb_retl( IsAudioDeviceReady() );
}

// void SetMasterVolume(float volume);                             // Set master volume (listener)
HB_FUNC( SETMASTERVOLUME )
{
   if( hb_param( 1, HB_IT_NUMERIC ) != NULL )
   {
      SetMasterVolume( ( float ) hb_parnd( 1 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// Wave/Sound loading/unloading functions

// Wave LoadWave(const char *fileName);                            // Load wave data from file
HB_FUNC( LOADWAVE )
{
   if( hb_param( 1, HB_IT_STRING ) != NULL )
   {
      Wave wave = LoadWave( hb_parc( 1 ) );

      PHB_ITEM info = hb_itemArrayNew( 5 );

      hb_arraySetNI( info, 1, ( unsigned int ) wave.sampleCount );
      hb_arraySetNI( info, 2, ( unsigned int ) wave.sampleRate );
      hb_arraySetNI( info, 3, ( unsigned int ) wave.sampleSize );
      hb_arraySetNI( info, 4, ( unsigned int ) wave.channels );
      hb_arraySetPtr( info, 5, wave.data );

      hb_itemReturnRelease( info );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// Wave LoadWaveFromMemory(const char *fileType, const unsigned char *fileData, int dataSize); // Load wave from memory buffer, fileType refers to extension: i.e. "wav"
HB_FUNC( LOADWAVEFROMMEMORY )
{
   if( hb_param( 1, HB_IT_STRING ) != NULL &&
       hb_param( 2, HB_IT_STRING ) != NULL &&
       hb_param( 3, HB_IT_INTEGER ) != NULL )
   {
      const unsigned char fileData = hb_parni( 2 );
      Wave wave = LoadWaveFromMemory( hb_parc( 1 ), &fileData, hb_parni( 3 ) );
      hb_storni( fileData, 2 );

      PHB_ITEM info = hb_itemArrayNew( 5 );

      hb_arraySetNI( info, 1, ( unsigned int ) wave.sampleCount );
      hb_arraySetNI( info, 2, ( unsigned int ) wave.sampleRate );
      hb_arraySetNI( info, 3, ( unsigned int ) wave.sampleSize );
      hb_arraySetNI( info, 4, ( unsigned int ) wave.channels );
      hb_arraySetPtr( info, 5, wave.data );

      hb_itemReturnRelease( info );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// Sound LoadSound(const char *fileName);                          // Load sound from file
HB_FUNC( LOADSOUND )
{
   if( hb_param( 1, HB_IT_STRING ) != NULL )
   {
      Sound sound = LoadSound( hb_parc( 1 ) );

      PHB_ITEM pLoadSoundArray = hb_itemArrayNew( 2 );

      PHB_ITEM pSubarray = hb_arrayGetItemPtr( pLoadSoundArray, 1 );

      hb_arrayNew( pSubarray, 4 );
      hb_arraySetPtr( pSubarray, 1, sound.stream.buffer );
      hb_arraySetNI( pSubarray, 2, ( unsigned int ) sound.stream.sampleRate );
      hb_arraySetNI( pSubarray, 3, ( unsigned int ) sound.stream.sampleSize );
      hb_arraySetNI( pSubarray, 4, ( unsigned int ) sound.stream.channels );

      hb_arraySetNI( pLoadSoundArray, 2, ( unsigned int ) sound.sampleCount );

      hb_itemReturnRelease( pLoadSoundArray );
      hb_itemRelease( pSubarray );

   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// Sound LoadSoundFromWave(Wave wave);                             // Load sound from wave data
HB_FUNC( LOADSOUNDFROMWAVE )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 5 )
   {
      Wave wave;

      wave.sampleCount = ( unsigned int ) hb_arrayGetNI( pItem, 1 );
      wave.sampleRate  = ( unsigned int ) hb_arrayGetNI( pItem, 2 );
      wave.sampleSize  = ( unsigned int ) hb_arrayGetNI( pItem, 3 );
      wave.channels    = ( unsigned int ) hb_arrayGetNI( pItem, 4 );
      wave.data        = hb_arrayGetPtr( pItem, 5 );

      Sound sound = LoadSoundFromWave( wave );

      PHB_ITEM pLoadSoundArray = hb_itemArrayNew( 2 );

      PHB_ITEM pSubarray = hb_arrayGetItemPtr( pLoadSoundArray, 1 );

      hb_arrayNew( pSubarray, 4 );
      hb_arraySetPtr( pSubarray, 1, sound.stream.buffer );
      hb_arraySetNI( pSubarray, 2, ( unsigned int ) sound.stream.sampleRate );
      hb_arraySetNI( pSubarray, 3, ( unsigned int ) sound.stream.sampleSize );
      hb_arraySetNI( pSubarray, 4, ( unsigned int ) sound.stream.channels );

      hb_arraySetNI( pLoadSoundArray, 2, ( unsigned int ) sound.sampleCount );

      hb_itemReturnRelease( pLoadSoundArray );
      hb_itemRelease( pSubarray );

   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void UpdateSound(Sound sound, const void *data, int samplesCount);// Update sound buffer with new data
HB_FUNC( UPDATESOUND )
{
    PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 2 &&
                 hb_param( 2, HB_IT_POINTER ) != NULL &&
                 hb_param( 2, HB_IT_INTEGER ) != NULL )
   {
      Sound sound;

      PHB_ITEM pSubarray = hb_arrayGetItemPtr( pItem, 1 );

      sound.stream.buffer     = ( rAudioBuffer * ) hb_arrayGetPtr( pSubarray, 1 );
      sound.stream.sampleRate = ( unsigned int ) hb_arrayGetNI( pSubarray, 2 );
      sound.stream.sampleSize = ( unsigned int ) hb_arrayGetNI( pSubarray, 3 );
      sound.stream.channels   = ( unsigned int ) hb_arrayGetNI( pSubarray, 4 );

      sound.sampleCount = ( unsigned int ) hb_arrayGetNI( pItem, 2 );

      UpdateSound( sound, hb_parptr( 2 ), hb_parni( 3 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void UnloadWave(Wave wave);                                     // Unload wave data
HB_FUNC( UNLOADWAVE )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 5 )
   {
      Wave wave;

      wave.sampleCount = ( unsigned int ) hb_arrayGetNI( pItem, 1 );
      wave.sampleRate  = ( unsigned int ) hb_arrayGetNI( pItem, 2 );
      wave.sampleSize  = ( unsigned int ) hb_arrayGetNI( pItem, 3 );
      wave.channels    = ( unsigned int ) hb_arrayGetNI( pItem, 4 );
      wave.data        = hb_arrayGetPtr( pItem, 5 );

      UnloadWave( wave );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void UnloadSound(Sound sound);                                  // Unload sound
HB_FUNC( UNLOADSOUND )
{
    PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 2 )
   {
      Sound sound;

      PHB_ITEM pSubarray = hb_arrayGetItemPtr( pItem, 1 );

      sound.stream.buffer     = ( rAudioBuffer * ) hb_arrayGetPtr( pSubarray, 1 );
      sound.stream.sampleRate = ( unsigned int ) hb_arrayGetNI( pSubarray, 2 );
      sound.stream.sampleSize = ( unsigned int ) hb_arrayGetNI( pSubarray, 3 );
      sound.stream.channels   = ( unsigned int ) hb_arrayGetNI( pSubarray, 4 );

      sound.sampleCount = ( unsigned int ) hb_arrayGetNI( pItem, 2 );

      UnloadSound( sound );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// bool ExportWave(Wave wave, const char *fileName);               // Export wave data to file, returns true on success
HB_FUNC( EXPORTWAVE )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 5 &&
                 hb_param( 2, HB_IT_STRING )  != NULL )
   {
      Wave wave;

      wave.sampleCount = ( unsigned int ) hb_arrayGetNI( pItem, 1 );
      wave.sampleRate  = ( unsigned int ) hb_arrayGetNI( pItem, 2 );
      wave.sampleSize  = ( unsigned int ) hb_arrayGetNI( pItem, 3 );
      wave.channels    = ( unsigned int ) hb_arrayGetNI( pItem, 4 );
      wave.data        = hb_arrayGetPtr( pItem, 5 );

      hb_retl( ExportWave( wave, hb_parc( 2 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// bool ExportWaveAsCode(Wave wave, const char *fileName);         // Export wave sample data to code (.h), returns true on success
HB_FUNC( EXPORTWAVEASCODE )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 5 &&
                 hb_param( 2, HB_IT_STRING )  != NULL )
   {
      Wave wave;

      wave.sampleCount = ( unsigned int ) hb_arrayGetNI( pItem, 1 );
      wave.sampleRate  = ( unsigned int ) hb_arrayGetNI( pItem, 2 );
      wave.sampleSize  = ( unsigned int ) hb_arrayGetNI( pItem, 3 );
      wave.channels    = ( unsigned int ) hb_arrayGetNI( pItem, 4 );
      wave.data        = hb_arrayGetPtr( pItem, 5 );

      hb_retl( ExportWaveAsCode( wave, hb_parc( 2 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// Wave/Sound management functions

// void PlaySound(Sound sound);                                    // Play a sound
HB_FUNC( PLAYSOUND )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 2 )
   {
      Sound sound;

      PHB_ITEM pSubarray = hb_arrayGetItemPtr( pItem, 1 );

      sound.stream.buffer     = ( rAudioBuffer * ) hb_arrayGetPtr( pSubarray, 1 );
      sound.stream.sampleRate = ( unsigned int ) hb_arrayGetNI( pSubarray, 2 );
      sound.stream.sampleSize = ( unsigned int ) hb_arrayGetNI( pSubarray, 3 );
      sound.stream.channels   = ( unsigned int ) hb_arrayGetNI( pSubarray, 4 );

      sound.sampleCount = ( unsigned int ) hb_arrayGetNI( pItem, 2 );

      PlaySound( sound );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void StopSound(Sound sound);                                    // Stop playing a sound
HB_FUNC( STOPSOUND )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 2 )
   {
      Sound sound;

      PHB_ITEM pSubarray = hb_arrayGetItemPtr( pItem, 1 );

      sound.stream.buffer     = ( rAudioBuffer * ) hb_arrayGetPtr( pSubarray, 1 );
      sound.stream.sampleRate = ( unsigned int ) hb_arrayGetNI( pSubarray, 2 );
      sound.stream.sampleSize = ( unsigned int ) hb_arrayGetNI( pSubarray, 3 );
      sound.stream.channels   = ( unsigned int ) hb_arrayGetNI( pSubarray, 4 );

      sound.sampleCount = ( unsigned int ) hb_arrayGetNI( pItem, 2 );

      StopSound( sound );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void PauseSound(Sound sound);                                   // Pause a sound
HB_FUNC( PAUSESOUND )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 2 )
   {
      Sound sound;

      PHB_ITEM pSubarray = hb_arrayGetItemPtr( pItem, 1 );

      sound.stream.buffer     = ( rAudioBuffer * ) hb_arrayGetPtr( pSubarray, 1 );
      sound.stream.sampleRate = ( unsigned int ) hb_arrayGetNI( pSubarray, 2 );
      sound.stream.sampleSize = ( unsigned int ) hb_arrayGetNI( pSubarray, 3 );
      sound.stream.channels   = ( unsigned int ) hb_arrayGetNI( pSubarray, 4 );

      sound.sampleCount = ( unsigned int ) hb_arrayGetNI( pItem, 2 );

      PauseSound( sound );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void ResumeSound(Sound sound);                                  // Resume a paused sound
HB_FUNC( RESUMESOUND )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 2 )
   {
      Sound sound;

      PHB_ITEM pSubarray = hb_arrayGetItemPtr( pItem, 1 );

      sound.stream.buffer     = ( rAudioBuffer * ) hb_arrayGetPtr( pSubarray, 1 );
      sound.stream.sampleRate = ( unsigned int ) hb_arrayGetNI( pSubarray, 2 );
      sound.stream.sampleSize = ( unsigned int ) hb_arrayGetNI( pSubarray, 3 );
      sound.stream.channels   = ( unsigned int ) hb_arrayGetNI( pSubarray, 4 );

      sound.sampleCount = ( unsigned int ) hb_arrayGetNI( pItem, 2 );

      ResumeSound( sound );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void PlaySoundMulti(Sound sound);                               // Play a sound (using multichannel buffer pool)
HB_FUNC( PLAYSOUNDMULTI )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 2 )
   {
      Sound sound;

      PHB_ITEM pSubarray = hb_arrayGetItemPtr( pItem, 1 );

      sound.stream.buffer     = ( rAudioBuffer * ) hb_arrayGetPtr( pSubarray, 1 );
      sound.stream.sampleRate = ( unsigned int ) hb_arrayGetNI( pSubarray, 2 );
      sound.stream.sampleSize = ( unsigned int ) hb_arrayGetNI( pSubarray, 3 );
      sound.stream.channels   = ( unsigned int ) hb_arrayGetNI( pSubarray, 4 );

      sound.sampleCount = ( unsigned int ) hb_arrayGetNI( pItem, 2 );

      PlaySoundMulti( sound );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void StopSoundMulti(void);                                      // Stop any sound playing (using multichannel buffer pool)
HB_FUNC(STOPSOUNDMULTI)
{
   StopSoundMulti();
}

// int GetSoundsPlaying(void);                                     // Get number of sounds playing in the multichannel
HB_FUNC(GETSOUNDSPLAYING)
{
   hb_retni(GetSoundsPlaying());
}

// bool IsSoundPlaying(Sound sound);                               // Check if a sound is currently playing
HB_FUNC( ISSOUNDPLAYING )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 2 )
   {
      Sound sound;

      PHB_ITEM pSubarray = hb_arrayGetItemPtr( pItem, 1 );

      sound.stream.buffer     = ( rAudioBuffer * ) hb_arrayGetPtr( pSubarray, 1 );
      sound.stream.sampleRate = ( unsigned int ) hb_arrayGetNI( pSubarray, 2 );
      sound.stream.sampleSize = ( unsigned int ) hb_arrayGetNI( pSubarray, 3 );
      sound.stream.channels   = ( unsigned int ) hb_arrayGetNI( pSubarray, 4 );

      sound.sampleCount = ( unsigned int ) hb_arrayGetNI( pItem, 2 );

       hb_retl( IsSoundPlaying( sound ));
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void SetSoundVolume(Sound sound, float volume);                 // Set volume for a sound (1.0 is max level)
HB_FUNC( SETSOUNDVOLUME )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 2 && hb_param( 2, HB_IT_NUMERIC ) != NULL)
   {
      Sound sound;

      PHB_ITEM pSubarray = hb_arrayGetItemPtr( pItem, 1 );

      sound.stream.buffer     = ( rAudioBuffer * ) hb_arrayGetPtr( pSubarray, 1 );
      sound.stream.sampleRate = ( unsigned int ) hb_arrayGetNI( pSubarray, 2 );
      sound.stream.sampleSize = ( unsigned int ) hb_arrayGetNI( pSubarray, 3 );
      sound.stream.channels   = ( unsigned int ) hb_arrayGetNI( pSubarray, 4 );

      sound.sampleCount = ( unsigned int ) hb_arrayGetNI( pItem, 2 );

      SetSoundVolume( sound, ( float ) hb_parnd( 2 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void SetSoundPitch(Sound sound, float pitch);                   // Set pitch for a sound (1.0 is base level)
HB_FUNC( SETSOUNDPITCH )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 2 && hb_param( 2, HB_IT_NUMERIC ) != NULL)
   {
      Sound sound;

      PHB_ITEM pSubarray = hb_arrayGetItemPtr( pItem, 1 );

      sound.stream.buffer     = ( rAudioBuffer * ) hb_arrayGetPtr( pSubarray, 1 );
      sound.stream.sampleRate = ( unsigned int ) hb_arrayGetNI( pSubarray, 2 );
      sound.stream.sampleSize = ( unsigned int ) hb_arrayGetNI( pSubarray, 3 );
      sound.stream.channels   = ( unsigned int ) hb_arrayGetNI( pSubarray, 4 );

      sound.sampleCount = ( unsigned int ) hb_arrayGetNI( pItem, 2 );

      SetSoundPitch( sound, ( float ) hb_parnd( 2 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void WaveFormat(Wave *wave, int sampleRate, int sampleSize, int channels);  // Convert wave data to desired format
HB_FUNC( WAVEFORMAT )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 5 &&
                 hb_param( 2, HB_IT_INTEGER ) != NULL &&
                 hb_param( 3, HB_IT_INTEGER ) != NULL &&
                 hb_param( 4, HB_IT_INTEGER ) != NULL )
   {
      Wave wave;

      wave.sampleCount = ( unsigned int ) hb_arrayGetNI( pItem, 1 );
      wave.sampleRate  = ( unsigned int ) hb_arrayGetNI( pItem, 2 );
      wave.sampleSize  = ( unsigned int ) hb_arrayGetNI( pItem, 3 );
      wave.channels    = ( unsigned int ) hb_arrayGetNI( pItem, 4 );
      wave.data        = hb_arrayGetPtr( pItem, 5 );

      WaveFormat( &wave, hb_parni( 2 ), hb_parni( 3 ), hb_parni( 4 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// Wave WaveCopy(Wave wave);                                       // Copy a wave to a new wave
HB_FUNC( WAVECOPY )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 5 )
   {
      Wave wave;

      wave.sampleCount = ( unsigned int ) hb_arrayGetNI( pItem, 1 );
      wave.sampleRate  = ( unsigned int ) hb_arrayGetNI( pItem, 2 );
      wave.sampleSize  = ( unsigned int ) hb_arrayGetNI( pItem, 3 );
      wave.channels    = ( unsigned int ) hb_arrayGetNI( pItem, 4 );
      wave.data        = hb_arrayGetPtr( pItem, 5 );

      Wave waveret = WaveCopy( wave );

      PHB_ITEM info = hb_itemArrayNew( 5 );

      hb_arraySetNI( info, 1, ( unsigned int ) waveret.sampleCount );
      hb_arraySetNI( info, 2, ( unsigned int ) waveret.sampleRate );
      hb_arraySetNI( info, 3, ( unsigned int ) waveret.sampleSize );
      hb_arraySetNI( info, 4, ( unsigned int ) waveret.channels );
      hb_arraySetPtr( info, 5, waveret.data );

      hb_itemReturnRelease( info );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void WaveCrop(Wave *wave, int initSample, int finalSample);     // Crop a wave to defined samples range
HB_FUNC( WAVECROP )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 5 &&
                 hb_param( 2, HB_IT_INTEGER ) != NULL &&
                 hb_param( 3, HB_IT_INTEGER ) != NULL )
   {
      Wave wave;

      wave.sampleCount = ( unsigned int ) hb_arrayGetNI( pItem, 1 );
      wave.sampleRate  = ( unsigned int ) hb_arrayGetNI( pItem, 2 );
      wave.sampleSize  = ( unsigned int ) hb_arrayGetNI( pItem, 3 );
      wave.channels    = ( unsigned int ) hb_arrayGetNI( pItem, 4 );
      wave.data        = hb_arrayGetPtr( pItem, 5 );

      WaveCrop( &wave, hb_parni( 2 ), hb_parni( 3 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// float *LoadWaveSamples(Wave wave);                              // Load samples data from wave as a floats array
HB_FUNC( LOADWAVESAMPLES )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 5 )
   {
      Wave wave;

      wave.sampleCount = ( unsigned int ) hb_arrayGetNI( pItem, 1 );
      wave.sampleRate  = ( unsigned int ) hb_arrayGetNI( pItem, 2 );
      wave.sampleSize  = ( unsigned int ) hb_arrayGetNI( pItem, 3 );
      wave.channels    = ( unsigned int ) hb_arrayGetNI( pItem, 4 );
      wave.data        = hb_arrayGetPtr( pItem, 5 );

      hb_retptr( LoadWaveSamples( wave ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void UnloadWaveSamples(float *samples);                         // Unload samples data loaded with LoadWaveSamples()
HB_FUNC( UNLOADWAVESAMPLES )
{
   if( hb_param( 1, HB_IT_NUMERIC ) != NULL )
   {
      float samples;
      UnloadWaveSamples( &samples );
      hb_storni( ( float ) samples, 1 );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// Music management functions

// Music LoadMusicStream(const char *fileName);                    // Load music stream from file
HB_FUNC( LOADMUSICSTREAM )
{
   if( hb_param( 1, HB_IT_STRING ) != NULL )
   {
      Music music = LoadMusicStream( hb_parc( 1 ) );

      PHB_ITEM pLoadMusicStreamArray = hb_itemArrayNew( 5 );

         //AudioStream stream
         PHB_ITEM pSubarrayAudioStream = hb_arrayGetItemPtr( pLoadMusicStreamArray, 1 );

         hb_arrayNew( pSubarrayAudioStream, 4 );
         hb_arraySetPtr( pSubarrayAudioStream, 1, ( rAudioBuffer * ) music.stream.buffer );
         hb_arraySetNI( pSubarrayAudioStream, 2, ( unsigned int ) music.stream.sampleRate );
         hb_arraySetNI( pSubarrayAudioStream, 3, ( unsigned int ) music.stream.sampleSize );
         hb_arraySetNI( pSubarrayAudioStream, 4, ( unsigned int ) music.stream.channels );

      hb_arraySetNI(  pLoadMusicStreamArray, 2, ( unsigned int ) music.sampleCount );
      hb_arraySetL(   pLoadMusicStreamArray, 3, music.looping );
      hb_arraySetNI(  pLoadMusicStreamArray, 4, music.ctxType );
      hb_arraySetPtr( pLoadMusicStreamArray, 5, music.ctxData );

      hb_itemReturnRelease( pLoadMusicStreamArray );
      hb_itemRelease( pSubarrayAudioStream );

   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void UnloadMusicStream(Music music);                            // Unload music stream
HB_FUNC( UNLOADMUSICSTREAM )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 5 )
   {
      Music music;

         //AudioStream stream
         PHB_ITEM pSubarrayAudioStream = hb_arrayGetItemPtr( pItem, 1 );

         music.stream.buffer     = ( rAudioBuffer * ) hb_arrayGetPtr( pSubarrayAudioStream, 1 );
         music.stream.sampleRate = ( unsigned int ) hb_arrayGetNI( pSubarrayAudioStream, 2 );
         music.stream.sampleSize = ( unsigned int ) hb_arrayGetNI( pSubarrayAudioStream, 3 );
         music.stream.channels   = ( unsigned int ) hb_arrayGetNI( pSubarrayAudioStream, 4 );

      music.sampleCount = ( unsigned int ) hb_arrayGetNI( pItem, 2 );
      music.looping = hb_arrayGetL( pItem, 3 );
      music.ctxType = hb_arrayGetNI( pItem, 4 );
      music.ctxData = hb_arrayGetPtr( pItem, 5 );

      UnloadMusicStream( music );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void PlayMusicStream(Music music);                              // Start music playing
HB_FUNC( PLAYMUSICSTREAM )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 5 )
   {
      Music music;

         //AudioStream stream
         PHB_ITEM pSubarrayAudioStream = hb_arrayGetItemPtr( pItem, 1 );

         music.stream.buffer     = ( rAudioBuffer * ) hb_arrayGetPtr( pSubarrayAudioStream, 1 );
         music.stream.sampleRate = ( unsigned int ) hb_arrayGetNI( pSubarrayAudioStream, 2 );
         music.stream.sampleSize = ( unsigned int ) hb_arrayGetNI( pSubarrayAudioStream, 3 );
         music.stream.channels   = ( unsigned int ) hb_arrayGetNI( pSubarrayAudioStream, 4 );

      music.sampleCount = ( unsigned int ) hb_arrayGetNI( pItem, 2 );
      music.looping = hb_arrayGetL( pItem, 3 );
      music.ctxType = hb_arrayGetNI( pItem, 4 );
      music.ctxData = hb_arrayGetPtr( pItem, 5 );

      PlayMusicStream( music );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void UpdateMusicStream(Music music);                            // Updates buffers for music streaming
HB_FUNC( UPDATEMUSICSTREAM )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 5 )
   {
      Music music;

         //AudioStream stream
         PHB_ITEM pSubarrayAudioStream = hb_arrayGetItemPtr( pItem, 1 );

         music.stream.buffer     = ( rAudioBuffer * ) hb_arrayGetPtr( pSubarrayAudioStream, 1 );
         music.stream.sampleRate = ( unsigned int ) hb_arrayGetNI( pSubarrayAudioStream, 2 );
         music.stream.sampleSize = ( unsigned int ) hb_arrayGetNI( pSubarrayAudioStream, 3 );
         music.stream.channels   = ( unsigned int ) hb_arrayGetNI( pSubarrayAudioStream, 4 );

      music.sampleCount = ( unsigned int ) hb_arrayGetNI( pItem, 2 );
      music.looping = hb_arrayGetL( pItem, 3 );
      music.ctxType = hb_arrayGetNI( pItem, 4 );
      music.ctxData = hb_arrayGetPtr( pItem, 5 );

      UpdateMusicStream( music );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void StopMusicStream(Music music);                              // Stop music playing
HB_FUNC( STOPMUSICSTREAM )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 5 )
   {
      Music music;

         //AudioStream stream
         PHB_ITEM pSubarrayAudioStream = hb_arrayGetItemPtr( pItem, 1 );

         music.stream.buffer     = ( rAudioBuffer * ) hb_arrayGetPtr( pSubarrayAudioStream, 1 );
         music.stream.sampleRate = ( unsigned int ) hb_arrayGetNI( pSubarrayAudioStream, 2 );
         music.stream.sampleSize = ( unsigned int ) hb_arrayGetNI( pSubarrayAudioStream, 3 );
         music.stream.channels   = ( unsigned int ) hb_arrayGetNI( pSubarrayAudioStream, 4 );

      music.sampleCount = ( unsigned int ) hb_arrayGetNI( pItem, 2 );
      music.looping = hb_arrayGetL( pItem, 3 );
      music.ctxType = hb_arrayGetNI( pItem, 4 );
      music.ctxData = hb_arrayGetPtr( pItem, 5 );

      StopMusicStream( music );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void PauseMusicStream(Music music);                             // Pause music playing
HB_FUNC( PAUSEMUSICSTREAM )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 5 )
   {
      Music music;

         //AudioStream stream
         PHB_ITEM pSubarrayAudioStream = hb_arrayGetItemPtr( pItem, 1 );

         music.stream.buffer     = ( rAudioBuffer * ) hb_arrayGetPtr( pSubarrayAudioStream, 1 );
         music.stream.sampleRate = ( unsigned int ) hb_arrayGetNI( pSubarrayAudioStream, 2 );
         music.stream.sampleSize = ( unsigned int ) hb_arrayGetNI( pSubarrayAudioStream, 3 );
         music.stream.channels   = ( unsigned int ) hb_arrayGetNI( pSubarrayAudioStream, 4 );

      music.sampleCount = ( unsigned int ) hb_arrayGetNI( pItem, 2 );
      music.looping = hb_arrayGetL( pItem, 3 );
      music.ctxType = hb_arrayGetNI( pItem, 4 );
      music.ctxData = hb_arrayGetPtr( pItem, 5 );

      PauseMusicStream( music );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void ResumeMusicStream(Music music);                            // Resume playing paused music
HB_FUNC( RESUMEMUSICSTREAM )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 5 )
   {
      Music music;

         //AudioStream stream
         PHB_ITEM pSubarrayAudioStream = hb_arrayGetItemPtr( pItem, 1 );

         music.stream.buffer     = ( rAudioBuffer * ) hb_arrayGetPtr( pSubarrayAudioStream, 1 );
         music.stream.sampleRate = ( unsigned int ) hb_arrayGetNI( pSubarrayAudioStream, 2 );
         music.stream.sampleSize = ( unsigned int ) hb_arrayGetNI( pSubarrayAudioStream, 3 );
         music.stream.channels   = ( unsigned int ) hb_arrayGetNI( pSubarrayAudioStream, 4 );

      music.sampleCount = ( unsigned int ) hb_arrayGetNI( pItem, 2 );
      music.looping = hb_arrayGetL( pItem, 3 );
      music.ctxType = hb_arrayGetNI( pItem, 4 );
      music.ctxData = hb_arrayGetPtr( pItem, 5 );

      ResumeMusicStream( music );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// bool IsMusicPlaying(Music music);                               // Check if music is playing
HB_FUNC( ISMUSICPLAYING )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 5 )
   {
      Music music;

         //AudioStream stream
         PHB_ITEM pSubarrayAudioStream = hb_arrayGetItemPtr( pItem, 1 );

         music.stream.buffer     = ( rAudioBuffer * ) hb_arrayGetPtr( pSubarrayAudioStream, 1 );
         music.stream.sampleRate = ( unsigned int ) hb_arrayGetNI( pSubarrayAudioStream, 2 );
         music.stream.sampleSize = ( unsigned int ) hb_arrayGetNI( pSubarrayAudioStream, 3 );
         music.stream.channels   = ( unsigned int ) hb_arrayGetNI( pSubarrayAudioStream, 4 );

      music.sampleCount = ( unsigned int ) hb_arrayGetNI( pItem, 2 );
      music.looping = hb_arrayGetL( pItem, 3 );
      music.ctxType = hb_arrayGetNI( pItem, 4 );
      music.ctxData = hb_arrayGetPtr( pItem, 5 );

      hb_retl( IsMusicPlaying( music ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void SetMusicVolume(Music music, float volume);                 // Set volume for music (1.0 is max level)
HB_FUNC( SETMUSICVOLUME )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 5 &&
                 hb_param( 2, HB_IT_NUMERIC ) != NULL )
   {
      Music music;

         //AudioStream stream
         PHB_ITEM pSubarrayAudioStream = hb_arrayGetItemPtr( pItem, 1 );

         music.stream.buffer     = ( rAudioBuffer * ) hb_arrayGetPtr( pSubarrayAudioStream, 1 );
         music.stream.sampleRate = ( unsigned int ) hb_arrayGetNI( pSubarrayAudioStream, 2 );
         music.stream.sampleSize = ( unsigned int ) hb_arrayGetNI( pSubarrayAudioStream, 3 );
         music.stream.channels   = ( unsigned int ) hb_arrayGetNI( pSubarrayAudioStream, 4 );

      music.sampleCount = ( unsigned int ) hb_arrayGetNI( pItem, 2 );
      music.looping = hb_arrayGetL( pItem, 3 );
      music.ctxType = hb_arrayGetNI( pItem, 4 );
      music.ctxData = hb_arrayGetPtr( pItem, 5 );

      SetMusicVolume( music, ( float ) hb_parnd( 2 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void SetMusicPitch(Music music, float pitch);                   // Set pitch for a music (1.0 is base level)
HB_FUNC( SETMUSICPITCH )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 5 &&
                 hb_param( 2, HB_IT_NUMERIC ) != NULL )
   {
      Music music;

         //AudioStream stream
         PHB_ITEM pSubarrayAudioStream = hb_arrayGetItemPtr( pItem, 1 );

         music.stream.buffer     = ( rAudioBuffer * ) hb_arrayGetPtr( pSubarrayAudioStream, 1 );
         music.stream.sampleRate = ( unsigned int ) hb_arrayGetNI( pSubarrayAudioStream, 2 );
         music.stream.sampleSize = ( unsigned int ) hb_arrayGetNI( pSubarrayAudioStream, 3 );
         music.stream.channels   = ( unsigned int ) hb_arrayGetNI( pSubarrayAudioStream, 4 );

      music.sampleCount = ( unsigned int ) hb_arrayGetNI( pItem, 2 );
      music.looping = hb_arrayGetL( pItem, 3 );
      music.ctxType = hb_arrayGetNI( pItem, 4 );
      music.ctxData = hb_arrayGetPtr( pItem, 5 );

      SetMusicPitch( music, ( float ) hb_parnd( 2 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// float GetMusicTimeLength(Music music);                          // Get music time length (in seconds)
HB_FUNC( GETMUSICTIMELENGTH )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 5 )
   {
      Music music;

         //AudioStream stream
         PHB_ITEM pSubarrayAudioStream = hb_arrayGetItemPtr( pItem, 1 );

         music.stream.buffer     = ( rAudioBuffer * ) hb_arrayGetPtr( pSubarrayAudioStream, 1 );
         music.stream.sampleRate = ( unsigned int ) hb_arrayGetNI( pSubarrayAudioStream, 2 );
         music.stream.sampleSize = ( unsigned int ) hb_arrayGetNI( pSubarrayAudioStream, 3 );
         music.stream.channels   = ( unsigned int ) hb_arrayGetNI( pSubarrayAudioStream, 4 );

      music.sampleCount = ( unsigned int ) hb_arrayGetNI( pItem, 2 );
      music.looping = hb_arrayGetL( pItem, 3 );
      music.ctxType = hb_arrayGetNI( pItem, 4 );
      music.ctxData = hb_arrayGetPtr( pItem, 5 );

      hb_retnd( ( float ) GetMusicTimeLength( music ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// float GetMusicTimePlayed(Music music);                          // Get current music time played (in seconds)
HB_FUNC( GETMUSICTIMEPLAYED )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 5 )
   {
      Music music;

         //AudioStream stream
         PHB_ITEM pSubarrayAudioStream = hb_arrayGetItemPtr( pItem, 1 );

         music.stream.buffer     = ( rAudioBuffer * ) hb_arrayGetPtr( pSubarrayAudioStream, 1 );
         music.stream.sampleRate = ( unsigned int ) hb_arrayGetNI( pSubarrayAudioStream, 2 );
         music.stream.sampleSize = ( unsigned int ) hb_arrayGetNI( pSubarrayAudioStream, 3 );
         music.stream.channels   = ( unsigned int ) hb_arrayGetNI( pSubarrayAudioStream, 4 );

      music.sampleCount = ( unsigned int ) hb_arrayGetNI( pItem, 2 );
      music.looping = hb_arrayGetL( pItem, 3 );
      music.ctxType = hb_arrayGetNI( pItem, 4 );
      music.ctxData = hb_arrayGetPtr( pItem, 5 );

      hb_retnd( ( float ) GetMusicTimePlayed( music ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// AudioStream management functions

// AudioStream InitAudioStream(unsigned int sampleRate, unsigned int sampleSize, unsigned int channels); // Init audio stream (to stream raw audio pcm data)
HB_FUNC( INITAUDIOSTREAM )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL &&
       hb_param( 2, HB_IT_INTEGER ) != NULL &&
       hb_param( 3, HB_IT_INTEGER ) != NULL )
   {
      AudioStream audiostream = InitAudioStream( ( unsigned int ) hb_parni( 1 ), ( unsigned int ) hb_parni( 2 ), ( unsigned int ) hb_parni( 3 ) );

      PHB_ITEM pInitAudioStreamArray = hb_itemArrayNew( 4 );

      hb_arraySetPtr( pInitAudioStreamArray, 1, ( rAudioBuffer * ) audiostream.buffer );
      hb_arraySetNI( pInitAudioStreamArray, 2, ( unsigned int ) audiostream.sampleRate );
      hb_arraySetNI( pInitAudioStreamArray, 3, ( unsigned int ) audiostream.sampleSize );
      hb_arraySetNI( pInitAudioStreamArray, 4, ( unsigned int ) audiostream.channels );

      hb_itemReturnRelease( pInitAudioStreamArray );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void UpdateAudioStream(AudioStream stream, const void *data, int samplesCount); // Update audio stream buffers with data
HB_FUNC( UPDATEAUDIOSTREAM )
{
   PHB_ITEM pItem;

   if(  ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 4 &&
                  hb_param( 2, HB_IT_POINTER ) != NULL &&
                  hb_param( 3, HB_IT_INTEGER ) != NULL )
   {
      AudioStream stream;

      stream.buffer     = ( rAudioBuffer * ) hb_arrayGetPtr( pItem, 1 );
      stream.sampleRate = ( unsigned int ) hb_arrayGetNI( pItem, 2 );
      stream.sampleSize = ( unsigned int ) hb_arrayGetNI( pItem, 3 );
      stream.channels   = ( unsigned int ) hb_arrayGetNI( pItem, 4 );

      UpdateAudioStream( stream, hb_parptr( 2 ), hb_parni( 3 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void CloseAudioStream(AudioStream stream);                      // Close audio stream and free memory
HB_FUNC( CLOSEAUDIOSTREAM )
{
   PHB_ITEM pItem;

   if(  ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 4 )
   {
      AudioStream stream;

      stream.buffer     = ( rAudioBuffer * ) hb_arrayGetPtr( pItem, 1 );
      stream.sampleRate = ( unsigned int ) hb_arrayGetNI( pItem, 2 );
      stream.sampleSize = ( unsigned int ) hb_arrayGetNI( pItem, 3 );
      stream.channels   = ( unsigned int ) hb_arrayGetNI( pItem, 4 );

      CloseAudioStream( stream );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// bool IsAudioStreamProcessed(AudioStream stream);                // Check if any audio stream buffers requires refill
HB_FUNC( ISAUDIOSTREAMPROCESSED )
{
   PHB_ITEM pItem;

   if(  ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 4 )
   {
      AudioStream stream;

      stream.buffer     = ( rAudioBuffer * ) hb_arrayGetPtr( pItem, 1 );
      stream.sampleRate = ( unsigned int ) hb_arrayGetNI( pItem, 2 );
      stream.sampleSize = ( unsigned int ) hb_arrayGetNI( pItem, 3 );
      stream.channels   = ( unsigned int ) hb_arrayGetNI( pItem, 4 );

      hb_retl( IsAudioStreamProcessed( stream ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void PlayAudioStream(AudioStream stream);                       // Play audio stream
HB_FUNC( PLAYAUDIOSTREAM )
{
   PHB_ITEM pItem;

   if(  ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 4 )
   {
      AudioStream stream;

      stream.buffer     = ( rAudioBuffer * ) hb_arrayGetPtr( pItem, 1 );
      stream.sampleRate = ( unsigned int ) hb_arrayGetNI( pItem, 2 );
      stream.sampleSize = ( unsigned int ) hb_arrayGetNI( pItem, 3 );
      stream.channels   = ( unsigned int ) hb_arrayGetNI( pItem, 4 );

      PlayAudioStream( stream );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void PauseAudioStream(AudioStream stream);                      // Pause audio stream
HB_FUNC( PAUSEAUDIOSTREAM )
{
   PHB_ITEM pItem;

   if(  ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 4 )
   {
      AudioStream stream;

      stream.buffer     = ( rAudioBuffer * ) hb_arrayGetPtr( pItem, 1 );
      stream.sampleRate = ( unsigned int ) hb_arrayGetNI( pItem, 2 );
      stream.sampleSize = ( unsigned int ) hb_arrayGetNI( pItem, 3 );
      stream.channels   = ( unsigned int ) hb_arrayGetNI( pItem, 4 );

      PauseAudioStream( stream );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void ResumeAudioStream(AudioStream stream);                     // Resume audio stream
HB_FUNC( RESUMEAUDIOSTREAM )
{
   PHB_ITEM pItem;

   if(  ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 4 )
   {
      AudioStream stream;

      stream.buffer     = ( rAudioBuffer * ) hb_arrayGetPtr( pItem, 1 );
      stream.sampleRate = ( unsigned int ) hb_arrayGetNI( pItem, 2 );
      stream.sampleSize = ( unsigned int ) hb_arrayGetNI( pItem, 3 );
      stream.channels   = ( unsigned int ) hb_arrayGetNI( pItem, 4 );

      ResumeAudioStream( stream );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// bool IsAudioStreamPlaying(AudioStream stream);                  // Check if audio stream is playing
HB_FUNC( ISAUDIOSTREAMPLAYING )
{
   PHB_ITEM pItem;

   if(  ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 4 )
   {
      AudioStream stream;

      stream.buffer     = ( rAudioBuffer * ) hb_arrayGetPtr( pItem, 1 );
      stream.sampleRate = ( unsigned int ) hb_arrayGetNI( pItem, 2 );
      stream.sampleSize = ( unsigned int ) hb_arrayGetNI( pItem, 3 );
      stream.channels   = ( unsigned int ) hb_arrayGetNI( pItem, 4 );

      hb_retl( IsAudioStreamPlaying( stream ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void StopAudioStream(AudioStream stream);                       // Stop audio stream
HB_FUNC( STOPAUDIOSTREAM )
{
   PHB_ITEM pItem;

   if(  ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 4 )
   {
      AudioStream stream;

      stream.buffer     = ( rAudioBuffer * ) hb_arrayGetPtr( pItem, 1 );
      stream.sampleRate = ( unsigned int ) hb_arrayGetNI( pItem, 2 );
      stream.sampleSize = ( unsigned int ) hb_arrayGetNI( pItem, 3 );
      stream.channels   = ( unsigned int ) hb_arrayGetNI( pItem, 4 );

      StopAudioStream( stream );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void SetAudioStreamVolume(AudioStream stream, float volume);    // Set volume for audio stream (1.0 is max level)
HB_FUNC( SETAUDIOSTREAMVOLUME )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 4 &&
                 hb_param( 2, HB_IT_NUMERIC ) != NULL )
   {
      AudioStream stream;

      stream.buffer     = ( rAudioBuffer * ) hb_arrayGetPtr( pItem, 1 );
      stream.sampleRate = ( unsigned int ) hb_arrayGetNI( pItem, 2 );
      stream.sampleSize = ( unsigned int ) hb_arrayGetNI( pItem, 3 );
      stream.channels   = ( unsigned int ) hb_arrayGetNI( pItem, 4 );

      SetAudioStreamVolume( stream, ( float ) hb_parnd( 2 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void SetAudioStreamPitch(AudioStream stream, float pitch);      // Set pitch for audio stream (1.0 is base level)
HB_FUNC( SetAudioStreamPitch )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 4 &&
                 hb_param( 2, HB_IT_NUMERIC ) != NULL )
   {
      AudioStream stream;

      stream.buffer     = ( rAudioBuffer * ) hb_arrayGetPtr( pItem, 1 );
      stream.sampleRate = ( unsigned int ) hb_arrayGetNI( pItem, 2 );
      stream.sampleSize = ( unsigned int ) hb_arrayGetNI( pItem, 3 );
      stream.channels   = ( unsigned int ) hb_arrayGetNI( pItem, 4 );

      SetAudioStreamPitch( stream, ( float ) hb_parnd( 2 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void SetAudioStreamBufferSizeDefault(int size);                 // Default size for new audio streams
HB_FUNC( SETAUDIOSTREAMBUFFERSIZEDEFAULT )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL )
   {
      SetAudioStreamBufferSizeDefault( hb_parni( 1 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}
