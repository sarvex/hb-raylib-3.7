
#include "hbraylib.ch"

PROCEDURE Main()

   LOCAL nScreenWidth := 0
   LOCAL nScreenHeight := 0

   SetConfigFlags( FLAG_WINDOW_RESIZABLE + FLAG_VSYNC_HINT )

   InitWindow( 800, 450, "Harbour and raylib [ tutorial_02 ] GetMousePosition()" )

   SetTargetFPS( 60 )

   DO WHILE ! WindowShouldClose()

      IF nScreenHeight != GetScreenHeight() .AND. nScreenWidth != GetScreenWidth()

         nScreenWidth := GetScreenWidth()
         nScreenHeight := GetScreenHeight()

      ENDIF

      BeginDrawing()

      ClearBackground( { 32, 32, 32, 255 } )

      SetWindowTitle( "{ " + hb_ntos( GetMousePosition()[ 1 ] ) + ", " + hb_ntos( GetMousePosition()[ 2 ] ) + " } = GetMousePosition()" )

      EndDrawing()

   ENDDO

   CloseWindow()

   RETURN
