#include "hbraylib.ch"

PROCEDURE Main()

   LOCAL screenWidth  := 800
   LOCAL screenHeight := 450
   LOCAL lContinue    := .T.

   InitWindow( screenWidth, screenHeight, "Harbour raylib [shapes] example - basic shapes drawing" )

   SetTargetFPS( 60 )

   DO WHILE lContinue

      BeginDrawing()

      ClearBackground( RAYWHITE )

      IF WindowShouldClose()
         lContinue := .F.
      ENDIF

      DrawText( "some basic shapes available on Harbour raylib", 20, 20, 20, DARKGRAY )

      DrawCircle( Int( screenHeight / 4 ), 120, 35, DARKBLUE )

      DrawRectangle( Int( screenWidth / 4 ) * 2 - 60, 100, 120, 60, RED )
      DrawRectangleLines( Int( screenWidth / 4 ) * 2 - 40, 320, 80, 60, ORANGE )
      DrawRectangleGradientH( Int( screenWidth / 4 ) * 2 - 90, 170, 180, 130, MAROON, GOLD )

      DrawTriangle( { screenWidth / 4 * 3, 80 }, ;
         { screenWidth / 4 * 3 - 60, 150 }, ;
         { screenWidth / 4 * 3 + 60, 150 }, VIOLET )

      DrawPoly( { screenWidth / 4 * 3, 320 }, 6, 80, 0, BROWN )

      DrawCircleGradient( Int( screenWidth / 4 ), 220, 60, GREEN, SKYBLUE )

      DrawLine( 18, 42, screenWidth - 18, 42, BLACK )
      DrawCircleLines( int( screenWidth / 4 ), 340, 80, DARKBLUE )

      DrawTriangleLines( { screenWidth / 4 * 3, 160 }, ;
         { screenWidth / 4 * 3 - 20, 230 }, ;
         { screenWidth / 4 * 3 + 20, 230 }, DARKBLUE )

      EndDrawing()

   ENDDO

   CloseWindow()

   RETURN
