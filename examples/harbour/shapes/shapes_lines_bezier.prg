#include "hbraylib.ch"

PROCEDURE Main()

   LOCAL nScreenWidth := 800
   LOCAL nScreenHeight := 450
   LOCAL aStart := { 0, 0 }
   LOCAL aEnd := { nScreenWidth, nScreenHeight }

   SetConfigFlags( FLAG_MSAA_4X_HINT )
   InitWindow( nScreenWidth, nScreenHeight, "raylib [shapes] example - cubic-bezier lines" )

   SetTargetFPS( 60 )

   DO WHILE ! WindowShouldClose()

      IF IsMouseButtonDown( MOUSE_LEFT_BUTTON )
         aStart = GetMousePosition()
      ELSEIF IsMouseButtonDown( MOUSE_RIGHT_BUTTON )
         aEnd = GetMousePosition()
      ENDIF

      BeginDrawing()

      ClearBackground( RAYWHITE )

      DrawText( "USE MOUSE LEFT-RIGHT CLICK to DEFINE LINE START and END POINTS", 15, 20, 20, GRAY )

      DrawLineBezier( aStart, aEnd, 2.0, RED )

      EndDrawing()

   ENDDO

   CloseWindow()

   RETURN
