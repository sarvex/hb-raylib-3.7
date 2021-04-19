#include "hbraylib.ch"

#define MAX_COLUMNS 20

#define CAMERA3D_POSITION   1
#define CAMERA3D_TARGET     2
#define CAMERA3D_UP         3
#define CAMERA3D_FOVY       4
#define CAMERA3D_TYPE       5


PROCEDURE Main()

   LOCAL nScreenWidth := 800
   LOCAL nScreenHeight := 450
   LOCAL aCamera[ 5 ]
   LOCAL aHeights[ MAX_COLUMNS ]
   LOCAL aPositions[ MAX_COLUMNS ]
   LOCAL aColors[ MAX_COLUMNS ]
   LOCAL i

   InitWindow( nScreenWidth, nScreenHeight, "Harbour raylib [core] example - 3d camera first person" )

   aCamera[ CAMERA3D_POSITION ] := { 4.0, 2.0, 4.0 }
   aCamera[ CAMERA3D_TARGET   ] := { 0.0, 1.8, 0.0 }
   aCamera[ CAMERA3D_UP       ] := { 0.0, 1.0, 0.0 }
   aCamera[ CAMERA3D_FOVY     ] := 60.0
   aCamera[ CAMERA3D_TYPE     ] := CAMERA_PERSPECTIVE

   FOR i := 1 TO MAX_COLUMNS
      aHeights[ i ]   := IntToF( GetRandomValue( 1, 12 ) )
      aPositions[ i ] := { IntToF( GetRandomValue( - 15, 15 ) ), aHeights[ i ] / 2.0, IntToF( GetRandomValue( - 15, 15 ) ) }
      aColors[ i ]    := { GetRandomValue( 20, 255 ), GetRandomValue( 10, 55 ), 30, 255 }
   NEXT

   SetCameraMode( aCamera, CAMERA_FIRST_PERSON )

   SetTargetFPS( 60 )

   DO WHILE ! WindowShouldClose()

      UpdateCamera( aCamera )

      BeginDrawing()

      ClearBackground( RAYWHITE )

      BeginMode3D( aCamera )

      DrawPlane( { 0.0, 0.0, 0.0 }, { 32.0, 32.0 }, LIGHTGRAY )
      DrawCube( { - 16.0, 2.5, 0.0 }, 1.0, 5.0, 32.0, BLUE )
      DrawCube( { 16.0, 2.5, 0.0 }, 1.0, 5.0, 32.0, LIME )
      DrawCube( { 0.0, 2.5, 16.0 }, 32.0, 5.0, 1.0, GOLD )


      FOR i := 1 TO MAX_COLUMNS
         DrawCube( aPositions[ i ], 2.0, aHeights[ i ], 2.0, aColors[ i ] )
         DrawCubeWires( aPositions[ i ], 2.0, aHeights[ i ], 2.0, MAROON )
      NEXT

      EndMode3D()

      DrawRectangle( 10, 10, 220, 70, Fade( SKYBLUE, 0.5 ) )
      DrawRectangleLines( 10, 10, 220, 70, BLUE )

      DrawText( "First person camera default controls:", 20, 20, 10, BLACK )
      DrawText( "- Move with keys: W, A, S, D", 40, 40, 10, DARKGRAY )
      DrawText( "- Mouse move to look around", 40, 60, 10, DARKGRAY )

      EndDrawing()

   ENDDO

   CloseWindow()

   RETURN
