#include "hbraylib.ch"

PROCEDURE Main()

   LOCAL nScreenWidth := 800
   LOCAL nScreenHeight := 450
   LOCAL lContinue := .T.
   LOCAL x, y

   SetConfigFlags( FLAG_WINDOW_RESIZABLE + FLAG_VSYNC_HINT )

   InitWindow( nScreenWidth, nScreenHeight, "Harbour raylib [ tutorial_08 ] shapes" )

   SetTargetFPS( 60 )

   DO WHILE lContinue

      BeginDrawing()

      ClearBackground( { 32, 32, 32, 255 } )

      IF WindowShouldClose()
         lContinue := .F.
      ENDIF

      FOR x := 0 TO 800
         FOR y := 0 TO 450
            DrawPixel( x, y, { hb_RandomInt( 0, 255 ), hb_RandomInt( 0, 255 ), hb_RandomInt( 0, 255 ), 255 } )
         NEXT
      NEXT

      EndDrawing()

   ENDDO

   CloseWindow()

   RETURN
