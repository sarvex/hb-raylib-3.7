
#include "hbraylib.ch"

PROCEDURE Main()

   LOCAL nScreenWidth := 800
   LOCAL nScreenHeight := 450
   LOCAL lContinue := .T.

   SetConfigFlags( FLAG_WINDOW_RESIZABLE + FLAG_VSYNC_HINT )

   InitWindow( nScreenWidth, nScreenHeight, "Harbour raylib [ tutorial_08 ] shapes" )

   SetTargetFPS( 60 )

   DO WHILE lContinue

      BeginDrawing()

      ClearBackground( { 32, 32, 32, 255 } )

      IF WindowShouldClose()
         lContinue := .F. // WindowShouldClose()
      ENDIF

      DrawText( hb_ntos( GetKeyPressed() ), 190, 200, 20, LIGHTGRAY )

// GetKeyPressed()

// SWITCH nKey

// CASE K_ESC
// lContinue := .F.
// EXIT

// OTHERWISE

// ENDSWITCH

      EndDrawing()

   ENDDO

   CloseWindow()

   RETURN
