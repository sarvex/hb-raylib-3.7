
#include "hbraylib.ch"

#define x 1
#define y 2

PROCEDURE Main()

   LOCAL nScreenWidth := 800
   LOCAL nScreenHeight := 450
   LOCAL aBallPosition

   InitWindow( nScreenWidth, nScreenHeight, "Harbour and raylib [ core ] example - keyboard input" )

   aBallPosition := { Int( nScreenWidth / 2 ), Int( nScreenHeight / 2 ) }

   SetTargetFPS( 60 )

   DO WHILE ! WindowShouldClose()

      IF IsKeyDown( KEY_RIGHT )
         aBallPosition[ x ] += 2
      ENDIF
      IF IsKeyDown( KEY_LEFT )
         aBallPosition[ x ] -= 2
      ENDIF
      IF IsKeyDown( KEY_UP )
         aBallPosition[ y ] -= 2
      ENDIF
      IF IsKeyDown( KEY_DOWN )
         aBallPosition[ y ] += 2
      ENDIF

      BeginDrawing()

      ClearBackground( RAYWHITE )

      DrawText( "move the ball with arrow keys", 10, 10, 20, DARKGRAY )

      DrawCircleV( aBallPosition, 50, MAROON )

      EndDrawing()

   ENDDO

   CloseWindow()

   RETURN
