
#include "hbraylib.ch"

PROCEDURE Main()

   LOCAL nScreenWidth := 0
   LOCAL nScreenHeight := 0

   SetConfigFlags( FLAG_WINDOW_RESIZABLE + FLAG_VSYNC_HINT )

   InitWindow( 800, 450, "Harbour and raylib [ tutorial_03 ] GetWindowPosition()" )

   SetTargetFPS( 60 )

   DO WHILE ! WindowShouldClose()

      IF nScreenHeight != GetScreenHeight() .AND. nScreenWidth != GetScreenWidth()

         nScreenWidth := GetScreenWidth()
         nScreenHeight := GetScreenHeight()

      ENDIF

      BeginDrawing()

      ClearBackground( { 32, 32, 32, 255 } )

      SetWindowTitle( "{ " + hb_ntos( GetWindowPosition()[ 1 ] ) + ", " + hb_ntos( GetWindowPosition()[ 2 ] ) + " } = GetWindowPosition()" )

      EndDrawing()

   ENDDO

   CloseWindow()

   RETURN
