#include "hbraylib.ch"

PROCEDURE Main()

   LOCAL nScreenWidth  := 800
   LOCAL nScreenHeight := 450
   LOCAL lContinue    := .T.

   InitWindow( nScreenWidth, nScreenHeight, "Harbour raylib [shapes] example - basic shapes drawing" )

   SetTargetFPS( 60 )

   DO WHILE lContinue

      BeginDrawing()

      ClearBackground( RAYWHITE )

      IF WindowShouldClose()
         lContinue := .F.
      ENDIF

      DrawText( "some basic shapes available on Harbour raylib", 20, 20, 20, DARKGRAY )

      DrawCircle( Int( nScreenHeight / 4 ), 120, 35, DARKBLUE )

      DrawRectangle( Int( nScreenWidth / 4 ) * 2 - 60, 100, 120, 60, RED )
      DrawRectangleLines( Int( nScreenWidth / 4 ) * 2 - 40, 320, 80, 60, ORANGE )
      DrawRectangleGradientH( Int( nScreenWidth / 4 ) * 2 - 90, 170, 180, 130, MAROON, GOLD )

      DrawTriangle( { nScreenWidth / 4 * 3, 80 }, ;
         { nScreenWidth / 4 * 3 - 60, 150 }, ;
         { nScreenWidth / 4 * 3 + 60, 150 }, VIOLET )

      DrawPoly( { nScreenWidth / 4 * 3, 320 }, 6, 80, 0, BROWN )

      DrawCircleGradient( Int( nScreenWidth / 4 ), 220, 60, GREEN, SKYBLUE )

      DrawLine( 18, 42, nScreenWidth - 18, 42, BLACK )
      DrawCircleLines( Int( nScreenWidth / 4 ), 340, 80, DARKBLUE )

      DrawTriangleLines( { nScreenWidth / 4 * 3, 160 }, ;
         { nScreenWidth / 4 * 3 - 20, 230 }, ;
         { nScreenWidth / 4 * 3 + 20, 230 }, DARKBLUE )

      EndDrawing()

   ENDDO

   CloseWindow()

   RETURN
