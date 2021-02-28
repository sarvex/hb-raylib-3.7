
#include "hbraylib.ch"

PROCEDURE Main()

   LOCAL nScreenWidth := 800
   LOCAL nScreenHeight := 450

   SetConfigFlags( FLAG_WINDOW_RESIZABLE + FLAG_VSYNC_HINT )

   InitWindow( nScreenWidth, nScreenHeight, "Harbour raylib [ tutorial_01 ] SetConfigFlags()" )

   SetWindowIcon( LoadImage( "../../../docs/assets/img/LogoWindow16x16.png" ) )


   SetTargetFPS( 60 )

   DO WHILE ! WindowShouldClose()

      BeginDrawing()

      ClearBackground( { 32, 32, 32, 255 } )

      EndDrawing()

   ENDDO

   CloseWindow()

   RETURN
