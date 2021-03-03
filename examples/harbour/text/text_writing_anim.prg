#include "hbraylib.ch"

PROCEDURE Main()

   LOCAL nScreenWidth := 800
   LOCAL nScreenHeight := 450
   
   LOCAL MESSAGE := "This sample illustrates a text writing" + Chr( 10 ) + "animation effect! take a look and you" + Chr( 10 ) + "  will see that Harbor is great! ;)"
   LOCAL framesCounter := 0

   InitWindow( nScreenWidth, nScreenHeight, "Harbour raylib [text] example - text writing anim" )

   SetTargetFPS( 60 )

   DO WHILE ! WindowShouldClose()

      IF IsKeyDown( KEY_SPACE )
         framesCounter += 8
      ELSE
         framesCounter++
      ENDIF

      IF IsKeyPressed( KEY_ENTER )
         framesCounter := 0
      ENDIF

      BeginDrawing()

      ClearBackground( RAYWHITE )

      DrawText( TextSubtext( MESSAGE, 0, framesCounter / 10 ), 210, 130, 20, MAROON )

      DrawText( "PRESS [ENTER] to RESTART!", 240, 260, 20, LIGHTGRAY )
      DrawText( "PRESS [SPACE] to SPEED UP!", 239, 300, 20, LIGHTGRAY )

      EndDrawing()

   ENDDO

   CloseWindow()

   RETURN
