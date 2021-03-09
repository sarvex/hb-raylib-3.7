#include "hbraylib.ch"

PROCEDURE Main()

   LOCAL nScreenWidth := 800
   LOCAL nScreenHeight := 450
   LOCAL cMESSAGE := e"This sample illustrates a text writing\nanimation effect! Check it out! ;)"
   LOCAL nframesCounter := 0

   InitWindow( nScreenWidth, nScreenHeight, "Harbour raylib [text] example - text writing anim" )

   SetTargetFPS( 60 )

   DO WHILE ! WindowShouldClose()

      IF IsKeyDown( KEY_SPACE )
         nframesCounter += 8
      ELSE
         nframesCounter++
      ENDIF

      IF IsKeyPressed( KEY_ENTER )
         nframesCounter := 0
      ENDIF

      BeginDrawing()

      ClearBackground( RAYWHITE )

      DrawText( TextSubtext( cMESSAGE, 0, nframesCounter / 10 ), 210, 130, 20, MAROON )

      DrawText( "PRESS [ENTER] to RESTART!", 240, 260, 20, LIGHTGRAY )
      DrawText( "PRESS [SPACE] to SPEED UP!", 239, 300, 20, LIGHTGRAY )

      EndDrawing()

   ENDDO

   CloseWindow()

   RETURN
