#include "hbraylib.ch"

PROCEDURE Main()

   LOCAL nScreenWidth := 800
   LOCAL nScreenHeight := 450
   LOCAL aFxWav
   LOCAL aFxOgg

   InitWindow( nScreenWidth, nScreenHeight, "Harbour raylib [audio] example - sound loading and playing" )

   InitAudioDevice()

   aFxWav := LoadSound( "resources/sound.wav" )
   aFxOgg := LoadSound( "resources/target.ogg" )

   SetTargetFPS( 60 )

   DO WHILE ! WindowShouldClose()

      IF IsKeyPressed( KEY_SPACE )
         PlaySound( aFxWav )
      ENDIF
      IF IsKeyPressed( KEY_ENTER )
         PlaySound( aFxOgg )
      ENDIF

      BeginDrawing();

      ClearBackground( RAYWHITE )

      DrawText( "Press SPACE to PLAY the WAV sound!", 200, 180, 20, LIGHTGRAY )
      DrawText( "Press ENTER to PLAY the OGG sound!", 200, 220, 20, LIGHTGRAY )

      EndDrawing()

   ENDDO

   UnloadSound( aFxWav )
   UnloadSound( aFxOgg )

   CloseAudioDevice()

   CloseWindow()

   RETURN
