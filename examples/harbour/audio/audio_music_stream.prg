#include "hbraylib.ch"

PROCEDURE Main()

   LOCAL nScreenWidth := 800
   LOCAL nScreenHeight := 450
   LOCAL aMusic
   LOCAL nTimePlayed
   LOCAL lPause := .F.

   InitWindow( nScreenWidth, nScreenHeight, "Harbour raylib [audio] example - music playing (streaming)" )

   InitAudioDevice()

   aMusic := LoadMusicStream( "resources/country.mp3" )

   PlayMusicStream( aMusic )

   SetTargetFPS( 60 )

   DO WHILE ! WindowShouldClose()

      UpdateMusicStream( aMusic )

      IF IsKeyPressed( KEY_SPACE )
         StopMusicStream( aMusic )
         PlayMusicStream( aMusic )
      ENDIF

      IF IsKeyPressed( KEY_P )

         lPause := ! lPause

         IF lPause
            PauseMusicStream( aMusic )
         ELSE
            ResumeMusicStream( aMusic )
         ENDIF
      ENDIF

      nTimePlayed := GetMusicTimePlayed( aMusic ) / GetMusicTimeLength( aMusic ) * 400

      IF nTimePlayed > 400
         StopMusicStream( aMusic )
      ENDIF

      BeginDrawing()

      ClearBackground( RAYWHITE )

      DrawText( "MUSIC SHOULD BE PLAYING!", 255, 150, 20, LIGHTGRAY )

      DrawRectangle( 200, 200, 400, 12, LIGHTGRAY )
      DrawRectangle( 200, 200, Int( nTimePlayed ), 12, MAROON )
      DrawRectangleLines( 200, 200, 400, 12, GRAY )

      DrawText( "PRESS SPACE TO RESTART MUSIC", 215, 250, 20, LIGHTGRAY )
      DrawText( "PRESS P TO PAUSE/RESUME MUSIC", 208, 280, 20, LIGHTGRAY )

      EndDrawing()

   ENDDO

   UnloadMusicStream( aMusic )

   CloseAudioDevice()

   CloseWindow()

   RETURN
