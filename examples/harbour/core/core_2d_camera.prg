#include "hbraylib.ch"

#define MAX_BUILDINGS   100

#define RECTANGLE_X        1
#define RECTANGLE_Y        2
#define RECTANGLE_WIDTH    3
#define RECTANGLE_HEIGHT   4

#define CAMERA2D_TARGET     1
#define CAMERA2D_OFFSET     2
#define CAMERA2D_ROTATION   3
#define CAMERA2D_ZOOM       4

#define VECTOR2_X   1
#define VECTOR2_Y   2

PROCEDURE Main()

   LOCAL nScreenWidth := 800
   LOCAL nScreenHeight := 450
   LOCAL aPlayer := { 400, 280, 40, 40 }
   LOCAL aBuildings[ MAX_BUILDINGS ][ 4 ]
   LOCAL aBuildColors[ MAX_BUILDINGS ][ 4 ]
   LOCAL nSpacing := 0
   LOCAL aCamera[ 4 ]
   LOCAL i

   InitWindow( nScreenWidth, nScreenHeight, "Harbour raylib [core] example - 2d aCamera" )

   FOR i := 1 TO MAX_BUILDINGS

      aBuildings[ i ][ RECTANGLE_WIDTH  ] := GetRandomValue( 50, 200 )
      aBuildings[ i ][ RECTANGLE_HEIGHT ] := GetRandomValue( 100, 800 )
      aBuildings[ i ][ RECTANGLE_Y      ] := nScreenHeight - 130.0 - aBuildings[ i ][ RECTANGLE_HEIGHT ]
      aBuildings[ i ][ RECTANGLE_X      ] := -6000.0 + nSpacing

      nSpacing += Int( aBuildings[ i ][ RECTANGLE_WIDTH  ] )

      aBuildColors[ i ] := { GetRandomValue( 200, 240 ), GetRandomValue( 200, 240 ), GetRandomValue( 200, 250 ), 255 }

   NEXT

   aCamera[ CAMERA2D_TARGET   ] := { aPlayer[ RECTANGLE_X ] + 20.0, aPlayer[ RECTANGLE_Y ] + 20.0 }
   aCamera[ CAMERA2D_OFFSET   ] := { nScreenWidth / 2.0, nScreenHeight / 2.0 }
   aCamera[ CAMERA2D_ROTATION ] := 0.0
   aCamera[ CAMERA2D_ZOOM     ] := 1.0

   SetTargetFPS( 60 )

   DO WHILE ! WindowShouldClose()

      IF IsKeyDown( KEY_RIGHT )
         aPlayer[ RECTANGLE_X ] += 2
      ELSEIF IsKeyDown( KEY_LEFT )
         aPlayer[ RECTANGLE_X ] -= 2
      ENDIF

      aCamera[ CAMERA2D_TARGET ] := { aPlayer[ RECTANGLE_X ] + 20, aPlayer[ RECTANGLE_Y ] + 20 }

      IF IsKeyDown( KEY_A )
         aCamera[ CAMERA2D_ROTATION ]--
      ELSEIF IsKeyDown( KEY_S )
         aCamera[ CAMERA2D_ROTATION ]++
      ENDIF

      IF aCamera[ CAMERA2D_ROTATION ] > 40
         aCamera[ CAMERA2D_ROTATION ] := 40
      ELSEIF aCamera[ CAMERA2D_ROTATION ] < -40
         aCamera[ CAMERA2D_ROTATION ] := -40
      ENDIF

      aCamera[ CAMERA2D_ZOOM ] += IntToF( GetMouseWheelMove() ) * 0.05

      IF aCamera[ CAMERA2D_ZOOM ] > 3.0
         aCamera[ CAMERA2D_ZOOM ] := 3.0
      ELSEIF aCamera[ CAMERA2D_ZOOM ] < 0.1
         aCamera[ CAMERA2D_ZOOM ] := 0.1
      ENDIF

      IF IsKeyPressed( KEY_R )
         aCamera[ CAMERA2D_ZOOM ] := 1.0
         aCamera[ CAMERA2D_ROTATION ] := 0.0
      ENDIF

      BeginDrawing()

      ClearBackground( RAYWHITE )

      BeginMode2D( aCamera )

      DrawRectangle( - 6000, 320, 13000, 8000, DARKGRAY )

      FOR i := 1 TO MAX_BUILDINGS
         DrawRectangleRec( aBuildings[ i ], aBuildColors[ i ] )
      NEXT

      DrawRectangleRec( aPlayer, RED )

      DrawLine( Int( aCamera[ CAMERA2D_TARGET ][ VECTOR2_X ] ), - nScreenHeight * 10, Int( aCamera[ CAMERA2D_TARGET ][ VECTOR2_X ] ), nScreenHeight * 10, GREEN )
      DrawLine( - nScreenWidth * 10, Int( aCamera[ CAMERA2D_TARGET ][ VECTOR2_Y ] ), nScreenWidth * 10, Int( aCamera[ CAMERA2D_TARGET ][ VECTOR2_Y ] ), GREEN )

      EndMode2D()

      DrawText( "SCREEN AREA", 640, 10, 20, RED )

      DrawRectangle( 0, 0, nScreenWidth, 5, RED )
      DrawRectangle( 0, 5, 5, nScreenHeight - 10, RED )
      DrawRectangle( nScreenWidth - 5, 5, 5, nScreenHeight - 10, RED )
      DrawRectangle( 0, nScreenHeight - 5, nScreenWidth, 5, RED )

      DrawRectangle( 10, 10, 250, 113, Fade( SKYBLUE, 0.5 ) )
      DrawRectangleLines( 10, 10, 250, 113, BLUE )

      DrawText( "Free 2d aCamera controls:", 20, 20, 10, BLACK )
      DrawText( "- Right/Left to move Offset", 40, 40, 10, DARKGRAY )
      DrawText( "- Mouse Wheel to Zoom in-out", 40, 60, 10, DARKGRAY )
      DrawText( "- A / S to Rotate", 40, 80, 10, DARKGRAY )
      DrawText( "- R to reset Zoom and Rotation", 40, 100, 10, DARKGRAY )

      EndDrawing()

   ENDDO

   CloseWindow()

   RETURN
