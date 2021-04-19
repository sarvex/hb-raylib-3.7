#include "hbraylib.ch"

PROCEDURE Main()

   LOCAL nScreenWidth := 800
   LOCAL nScreenHeight := 450
   LOCAL nKeyPressed
   LOCAL nKey := 0

   SetConfigFlags( FLAG_WINDOW_RESIZABLE + FLAG_VSYNC_HINT )

   InitWindow( nScreenWidth, nScreenHeight, "Harbour raylib [ tutorial_08 ] keycode" )

   SetTargetFPS( 10 )

   DO WHILE ! WindowShouldClose()

      BeginDrawing()

      ClearBackground( { 32, 32, 32, 255 } )

      nKeyPressed := GetKeyPressed()

      IF nKeyPressed != 0
         nKey := nKeyPressed
      ENDIF

      DrawText( hb_ntos( nKey ), 310, 200, 20, LIGHTGRAY )
      DrawText( "Get key pressed keycode", 30, 200, 20, LIGHTGRAY )

      EndDrawing()

   ENDDO

   CloseWindow()

   RETURN
