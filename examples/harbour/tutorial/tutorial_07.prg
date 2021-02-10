
#include "hbraylib.ch"

PROCEDURE Main()

   LOCAL nScreenWidth := 800
   LOCAL nScreenHeight := 450

   SetConfigFlags( FLAG_WINDOW_RESIZABLE + FLAG_VSYNC_HINT )

   InitWindow( nScreenWidth, nScreenHeight, "Harbour raylib [ tutorial_07 ] Fade()" )

   SetTargetFPS( 60 )

   DO WHILE ! WindowShouldClose()

      BeginDrawing()

      ClearBackground( Fade( GRAY, 0.5 ) )

      EndDrawing()

   ENDDO

   CloseWindow()

   RETURN
