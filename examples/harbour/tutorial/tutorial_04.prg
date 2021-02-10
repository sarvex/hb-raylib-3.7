
#include "hbraylib.ch"

PROCEDURE Main()

   LOCAL nScreenWidth := 0
   LOCAL nScreenHeight := 0

   SetConfigFlags( FLAG_WINDOW_RESIZABLE + FLAG_VSYNC_HINT )

   InitWindow( 800, 450, "Harbour and raylib [ tutorial_04 ] GetMonitorName()" )

   SetTargetFPS( 60 )

   DO WHILE ! WindowShouldClose()

      IF nScreenHeight != GetScreenHeight() .AND. nScreenWidth != GetScreenWidth()

         nScreenWidth := GetScreenWidth()
         nScreenHeight := GetScreenHeight()

      ENDIF

      BeginDrawing()

      ClearBackground( { 32, 32, 32, 255 } )

      SetWindowTitle( '"' + GetMonitorName( 0 ) + '"' + " = GetMonitorName()" )

      EndDrawing()

   ENDDO

   CloseWindow()

   RETURN
