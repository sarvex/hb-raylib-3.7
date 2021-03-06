#include "hbraylib.ch"

PROCEDURE Main()

   LOCAL nScreenWidth := 800
   LOCAL nScreenHeight := 450
   LOCAL nScore := 100020
   LOCAL nHiscore := 200450
   LOCAL nLives := 5

   InitWindow( nScreenWidth, nScreenHeight, "Harbour raylib [text] example - text formatting" )

   SetTargetFPS( 60 )

   DO WHILE ! WindowShouldClose()

      BeginDrawing()

      ClearBackground( RAYWHITE )

      DrawText( TextFormat( "Score: %08i", nScore ), 200, 80, 20, RED )

      DrawText( TextFormat( "HiScore: %08i", nHiscore ), 200, 120, 20, GREEN )

      DrawText( TextFormat( "Lives: %02i", nLives ), 200, 160, 40, BLUE )

      DrawText( TextFormat( "Elapsed Time: %02.02f ms", GetFrameTime() * 1000 ), 200, 220, 20, BLACK )

      EndDrawing()

   ENDDO

   CloseWindow()

   RETURN
