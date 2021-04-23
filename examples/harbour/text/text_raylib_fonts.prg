#include "hbraylib.ch"

#define MAX_FONTS   8

#define VECTOR2_X   1
#define VECTOR2_Y   2

#define FONT_BASESIZE   1

PROCEDURE Main()

   LOCAL nScreenWidth := 800
   LOCAL nScreenHeight := 450
   LOCAL aFonts[ MAX_FONTS ]
   LOCAL aMessages
   LOCAL aSpacings
   LOCAL aPositions[ MAX_FONTS ][ 2 ]
   LOCAL i
   LOCAL aColors

   InitWindow( nScreenWidth, nScreenHeight, "Harbour raylib [text] example - raylib fonts" )

   aFonts[ 1 ] := LoadFont( "resources/fonts/alagard.png" )
   aFonts[ 2 ] := LoadFont( "resources/fonts/pixelplay.png" )
   aFonts[ 3 ] := LoadFont( "resources/fonts/mecha.png" )
   aFonts[ 4 ] := LoadFont( "resources/fonts/setback.png" )
   aFonts[ 5 ] := LoadFont( "resources/fonts/romulus.png" )
   aFonts[ 6 ] := LoadFont( "resources/fonts/pixantiqua.png" )
   aFonts[ 7 ] := LoadFont( "resources/fonts/alpha_beta.png" )
   aFonts[ 8 ] := LoadFont( "resources/fonts/jupiter_crash.png" )

   aMessages := { ;
      "ALAGARD FONT designed by Hewett Tsoi", ;
      "PIXELPLAY FONT designed by Aleksander Shevchuk", ;
      "MECHA FONT designed by Captain Falcon", ;
      "SETBACK FONT designed by Brian Kent (AEnigma)", ;
      "ROMULUS FONT designed by Hewett Tsoi", ;
      "PIXANTIQUA FONT designed by Gerhard Grossmann", ;
      "ALPHA_BETA FONT designed by Brian Kent (AEnigma)", ;
      "JUPITER_CRASH FONT designed by Brian Kent (AEnigma)" }

   aSpacings := { 2, 4, 8, 4, 3, 4, 4, 1 }

   FOR i := 1 TO MAX_FONTS
      aPositions[ i ][ VECTOR2_X ] := nScreenWidth / 2 - MeasureTextEx( aFonts[ i ], aMessages[ i ], aFonts[ i ][ FONT_BASESIZE ] * 2, aSpacings[ i ] )[ VECTOR2_X ] / 2
      aPositions[ i ][ VECTOR2_Y ] := 60 + aFonts[ i ][ FONT_BASESIZE ] + 45 * i
   NEXT

   aPositions[ 3 ][ VECTOR2_Y ] += 8
   aPositions[ 4 ][ VECTOR2_Y ] += 2
   aPositions[ 7 ][ VECTOR2_Y ] -= 8

   aColors := { MAROON, ORANGE, DARKGREEN, DARKBLUE, DARKPURPLE, LIME, GOLD, RED }

   SetTargetFPS( 60 )

   DO WHILE ! WindowShouldClose()

      BeginDrawing()

      ClearBackground( RAYWHITE )

      DrawText( "free fonts included with raylib", 250, 20, 20, DARKGRAY )
      DrawLine( 220, 50, 590, 50, DARKGRAY )

      FOR i := 1 TO MAX_FONTS
         DrawTextEx( aFonts[ i ], aMessages[ i ], aPositions[ i ], aFonts[ i ][ FONT_BASESIZE ] * 2, aSpacings[ i ], aColors[ i ] )
      NEXT

      EndDrawing()

   ENDDO

   FOR i := 1 TO MAX_FONTS
      UnloadFont( aFonts[ i ] )
   NEXT

   CloseWindow()

   RETURN
