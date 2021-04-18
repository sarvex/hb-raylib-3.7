#include "hbraylib.ch"

#define FONT_BASESIZE   1
#define VECTOR2_X       1

PROCEDURE Main()

   LOCAL nScreenWidth := 800
   LOCAL nScreenHeight := 450
   LOCAL cMsg1 := "THIS IS A custom SPRITE FONT..."
   LOCAL cMsg2 := "...and this is ANOTHER CUSTOM font..."
   LOCAL cMsg3 := "...and a THIRD one! GREAT! :D"
   LOCAL aFont1, aFont2, aFont3
   LOCAL aFontPosition1, aFontPosition2, aFontPosition3

   InitWindow( nScreenWidth, nScreenHeight, "Harbour raylib [text] example - sprite font loading" )

   aFont1 := LoadFont( "resources/custom_mecha.png" )
   aFont2 := LoadFont( "resources/custom_alagard.png" )
   aFont3 := LoadFont( "resources/custom_jupiter_crash.png" )

   aFontPosition1 := { nScreenWidth / 2 - MeasureTextEx( aFont1, cMsg1, aFont1[ FONT_BASESIZE ]+0.0, -3.0 )[ VECTOR2_X ] / 2, nScreenHeight / 2 - aFont1[ FONT_BASESIZE ] / 2 - 80 }

   aFontPosition2 := { nScreenWidth / 2 - MeasureTextEx( aFont2, cMsg2, aFont2[ FONT_BASESIZE ], -2 )[ VECTOR2_X ] / 2, nScreenHeight / 2 - aFont2[ FONT_BASESIZE ] / 2 - 10 }

   aFontPosition3 := { nScreenWidth / 2 - MeasureTextEx( aFont3, cMsg3, aFont3[ FONT_BASESIZE ],  2 )[ VECTOR2_X ] / 2, nScreenHeight / 2 - aFont3[ FONT_BASESIZE ] / 2 + 50 }

   SetTargetFPS( 60 )

   DO WHILE ! WindowShouldClose()

      BeginDrawing()

      ClearBackground( RAYWHITE )

      DrawTextEx( aFont1, cMsg1, aFontPosition1, aFont1[ FONT_BASESIZE ], -3, WHITE )
      DrawTextEx( aFont2, cMsg2, aFontPosition2, aFont2[ FONT_BASESIZE ], -2, WHITE )
      DrawTextEx( aFont3, cMsg3, aFontPosition3, aFont3[ FONT_BASESIZE ],  2, WHITE )

      EndDrawing()

   ENDDO

   UnloadFont( aFont1 )
   UnloadFont( aFont2 )
   UnloadFont( aFont3 )

   CloseWindow()

   RETURN
