#include "hbraylib.ch"

#define CAMERA3D_POSITION   1
#define CAMERA3D_TARGET     2
#define CAMERA3D_UP         3
#define CAMERA3D_FOVY       4
#define CAMERA3D_TYPE       5

PROCEDURE Main()

   LOCAL nScreenWidth := 800
   LOCAL nScreenHeight := 450
   LOCAL aCamera[ 5 ]
   LOCAL aCubePosition := { 0.0, 0.0, 0.0 }

   InitWindow( nScreenWidth, nScreenHeight, "Harbour raylib [core] example - 3d aCamera free" )

   aCamera[ CAMERA3D_POSITION ] := { 10.0, 10.0, 10.0 }
   aCamera[ CAMERA3D_TARGET   ] := { 0.0, 0.0, 0.0 }
   aCamera[ CAMERA3D_UP       ] := { 0.0, 1.0, 0.0 }
   aCamera[ CAMERA3D_FOVY     ] := 45.0
   aCamera[ CAMERA3D_TYPE     ] := CAMERA_PERSPECTIVE

   SetCameraMode( aCamera, CAMERA_FREE )

   SetTargetFPS( 60 )

   DO WHILE ! WindowShouldClose()

      UpdateCamera( aCamera )

      IF IsKeyDown( Asc( "Z" ) )
         aCamera[ CAMERA3D_TARGET ] := { 0.0, 0.0, 0.0 }
      ENDIF

      BeginDrawing()

      ClearBackground( RAYWHITE )

      BeginMode3D( aCamera )

      DrawCube( aCubePosition, 2.0, 2.0, 2.0, RED )
      DrawCubeWires( aCubePosition, 2.0, 2.0, 2.0, MAROON )

      DrawGrid( 10, 1.0 )

      EndMode3D()

      DrawRectangle( 10, 10, 320, 133, Fade( SKYBLUE, 0.5 ) )
      DrawRectangleLines( 10, 10, 320, 133, BLUE )

      DrawText( "Free aCamera default controls:", 20, 20, 10, BLACK )
      DrawText( "- Mouse Wheel to Zoom in-out", 40, 40, 10, DARKGRAY )
      DrawText( "- Mouse Wheel Pressed to Pan", 40, 60, 10, DARKGRAY )
      DrawText( "- Alt + Mouse Wheel Pressed to Rotate", 40, 80, 10, DARKGRAY )
      DrawText( "- Alt + Ctrl + Mouse Wheel Pressed for Smooth Zoom", 40, 100, 10, DARKGRAY )
      DrawText( "- Z to zoom to (0, 0, 0)", 40, 120, 10, DARKGRAY )

      EndDrawing()

   ENDDO

   CloseWindow()

   RETURN
