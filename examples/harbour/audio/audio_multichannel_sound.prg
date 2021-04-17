#include "hbraylib.ch"

PROCEDURE Main()

   LOCAL nScreenWidth := 800
   LOCAL nScreenHeight := 450
   LOCAL aFxWav
   LOCAL aFxOgg

   InitWindow( nScreenWidth, nScreenHeight, "Harbour raylib [audio] example - Multichannel sound playing" )

   InitAudioDevice()

   aFxWav := LoadSound( "resources/sound.wav" )
   aFxOgg := LoadSound( "resources/target.ogg" )

   SetTargetFPS( 60 )

   DO WHILE ! WindowShouldClose()

      IF IsKeyPressed( KEY_ENTER )
         PlaySound( aFxWav )
      ENDIF
      IF IsKeyPressed( KEY_SPACE )
         PlaySoundMulti( aFxOgg )
      ENDIF

      BeginDrawing()

      ClearBackground( RAYWHITE )

      DrawText( "MULTICHANNEL SOUND PLAYING", 20, 20, 20, GRAY )
      DrawText( "Press SPACE to play new ogg instance!", 200, 120, 20, LIGHTGRAY )
      DrawText( "Press ENTER to play new wav instance!", 200, 180, 20, LIGHTGRAY )

      DrawText( TextFormat( "CONCURRENT SOUNDS PLAYING: %02i", GetSoundsPlaying() ), 220, 280, 20, RED )

      EndDrawing()

   ENDDO

   StopSoundMulti()

   UnloadSound( aFxWav )
   UnloadSound( aFxOgg )

   CloseAudioDevice()

   CloseWindow()

   RETURN
