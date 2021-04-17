#include "hbraylib.ch"

PROCEDURE Main()

   LOCAL nScreenWidth := 800
   LOCAL nScreenHeight := 450
   LOCAL aCamera := { { 0.0, 10.0, 10.0 }, { 0.0, 0.0, 0.0 }, { 0.0, 1.0, 0.0 }, 45.0, CAMERA_PERSPECTIVE }
   LOCAL aCubePosition := { 0.0, 0.0, 0.0 }

   InitWindow( nScreenWidth, nScreenHeight, "Harbour raylib [core] example - 3d camera mode" )

   SetTargetFPS( 60 )

   DO WHILE ! WindowShouldClose()

      BeginDrawing()

      ClearBackground( RAYWHITE )

      BeginMode3D( aCamera )

      DrawCube( aCubePosition, 2.0, 2.0, 2.0, RED )
      DrawCubeWires( aCubePosition, 2.0, 2.0, 2.0, MAROON )

      DrawGrid( 10, 1.0 )

      EndMode3D()

      DrawText( "Welcome to the third dimension!", 10, 40, 20, DARKGRAY )

      DrawFPS( 10, 10 )

      EndDrawing()

   ENDDO

   CloseWindow()

   RETURN
