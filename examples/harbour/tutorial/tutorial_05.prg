
#include "hbraylib.ch"

PROCEDURE Main()

   LOCAL nScreenWidth := 800
   LOCAL nScreenHeight := 450

   SetConfigFlags( FLAG_WINDOW_RESIZABLE + FLAG_VSYNC_HINT )

   InitWindow( nScreenWidth, nScreenHeight, "Harbour raylib [ tutorial_05 ] ColorFromHSV" )

   SetTargetFPS( 60 )

   DO WHILE ! WindowShouldClose()

      BeginDrawing()

      ClearBackground( ColorFromHSV( { 0.00, 0.00, 0.20 } ) )

      EndDrawing()

   ENDDO

   CloseWindow()

   RETURN
