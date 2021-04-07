#include "hbraylib.ch"

#define MAX_COLORS_COUNT   21

#define RECTANGLE_X        1
#define RECTANGLE_Y        2
#define RECTANGLE_WIDTH    3
#define RECTANGLE_HEIGHT   4

PROCEDURE Main()

   LOCAL screenWidth  := 800
   LOCAL screenHeight := 450
   LOCAL aColors      := { DARKGRAY, MAROON, ORANGE, DARKGREEN, DARKBLUE, DARKPURPLE, DARKBROWN, GRAY, RED, GOLD, LIME, BLUE, VIOLET, BROWN, ;
      LIGHTGRAY, PINK, YELLOW, GREEN, SKYBLUE, PURPLE, BEIGE }
   LOCAL aColorNames  := { "DARKGRAY", "MAROON", "ORANGE", "DARKGREEN", "DARKBLUE", "DARKPURPLE", "DARKBROWN", "GRAY", "RED", "GOLD", "LIME", ;
      "BLUE", "VIOLET", "BROWN", "LIGHTGRAY", "PINK", "YELLOW", "GREEN", "SKYBLUE", "PURPLE", "BEIGE" }
   LOCAL aColorsRecs[ MAX_COLORS_COUNT, 4 ]
   LOCAL aColorState[ MAX_COLORS_COUNT ]
   LOCAL aMousePoint
   LOCAL x := 0
   LOCAL i

   InitWindow( screenWidth, screenHeight, "Harbour raylib [shapes] example - colors palette" )

   FOR i := 1 TO MAX_COLORS_COUNT
      aColorsRecs[ i, RECTANGLE_X ] := 20 + 100 * ( x % 7 ) + 10 * ( x % 7 )
      aColorsRecs[ i, RECTANGLE_Y ] := 80 + 100 * Int( x / 7 ) + 10 * Int( x / 7 )
      aColorsRecs[ i, RECTANGLE_WIDTH ] := 100
      aColorsRecs[ i, RECTANGLE_HEIGHT ] := 100
      x++
   NEXT

   SetTargetFPS( 60 )

   DO WHILE ! WindowShouldClose()

      aMousePoint := GetMousePosition()

      FOR i := 1 TO MAX_COLORS_COUNT
         IF CheckCollisionPointRec( aMousePoint, aColorsRecs[ i ] )
            aColorState[ i ] := 1
         ELSE
            aColorState[ i ] := 0
         ENDIF
      NEXT

      BeginDrawing()

      ClearBackground( RAYWHITE )

      DrawText( "harbour raylib colors palette", 28, 42, 20, BLACK )
      DrawText( "press SPACE to see all colors", GetScreenWidth() - 180, GetScreenHeight() - 40, 10, GRAY )

      FOR i := 1 TO MAX_COLORS_COUNT

         DrawRectangleRec( aColorsRecs[ i ], Fade( aColors[ i ], iif( aColorState[ i ] == 1, 0.6, 1.0 ) ) )

         IF ( IsKeyDown( KEY_SPACE ) .OR. aColorState[ i ] == 1 )
            DrawRectangle( Int( aColorsRecs[ i, RECTANGLE_X ] ), Int( aColorsRecs[ i, RECTANGLE_Y ] + aColorsRecs[ i, RECTANGLE_HEIGHT ] - 26 ), ;
               Int( aColorsRecs[ i, RECTANGLE_WIDTH ] ), 20, BLACK )
            DrawRectangleLinesEx( aColorsRecs[ i ], 6, Fade( BLACK, 0.3 ) )
            DrawText( aColorNames[ i ], Int( aColorsRecs[ i, RECTANGLE_X ] + aColorsRecs[ i, RECTANGLE_WIDTH ] - MeasureText( aColorNames[ i ], 10 ) - 12 ), ;
               Int( aColorsRecs[ i, RECTANGLE_Y ] + aColorsRecs[ i, RECTANGLE_HEIGHT ] - 20 ), 10, aColors[ i ] )
         ENDIF

      NEXT

      EndDrawing()

   ENDDO

   CloseWindow()

   RETURN
