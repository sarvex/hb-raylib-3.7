#include "hbraylib.ch"

#define TEXTURE2D_WIDTH  2
#define TEXTURE2D_HEIGHT 3

#define VECTOR2_X 1
#define VECTOR2_Y 2

PROCEDURE Main()

   LOCAL nScreenWidth := 800
   LOCAL nScreenHeight := 450

   LOCAL aScarfy

   LOCAL aFrameWidth
   LOCAL aFrameHeight

   LOCAL aOrigin
   LOCAL aSourceRec
   LOCAL aDestRec
   LOCAL nRotation := 0

   InitWindow( nScreenWidth, nScreenHeight, "Harbour raylib [textures] examples - texture source and destination rectangles" )

   aScarfy := LoadTexture( "resources/Scarfy.png" )
   
   aFrameWidth  := aScarfy[ TEXTURE2D_WIDTH ] / 6
   aFrameHeight := aScarfy[ TEXTURE2D_HEIGHT ]

   aSourceRec := { 0.0, 0.0, aFrameWidth, aFrameHeight }
   aDestRec := { nScreenWidth / 2, nScreenHeight / 2, aFrameWidth * 2, aFrameHeight * 2 }
   aOrigin := { aFrameWidth, aFrameHeight }

   SetTargetFPS( 60 )

   DO WHILE ! WindowShouldClose()

      BeginDrawing()

      ClearBackground( RAYWHITE )

      nRotation++

      DrawTexturePro( aScarfy, aSourceRec, aDestRec, aOrigin, nRotation, WHITE )

      DrawLine( Int( aDestRec[ VECTOR2_X ] ), 0, Int( aDestRec[ VECTOR2_X ] ), nScreenHeight, GRAY )
      DrawLine( 0, Int( aDestRec[ VECTOR2_Y ] ), nScreenWidth, Int( aDestRec[ VECTOR2_Y ] ), GRAY )

      DrawText( "(c) Scarfy sprite by Eiden Marsal", nScreenWidth - 200, nScreenHeight - 20, 10, GRAY )

      EndDrawing()

   ENDDO

   UnloadTexture( aScarfy )

   CloseWindow()

   RETURN
