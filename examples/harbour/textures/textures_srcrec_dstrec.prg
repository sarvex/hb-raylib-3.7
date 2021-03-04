#include "hbraylib.ch"

#define TEXTURE2D_WIDTH  2
#define TEXTURE2D_HEIGHT 3

#define VECTOR2_X 1
#define VECTOR2_Y 2

PROCEDURE Main()

   LOCAL ScreenWidth := 800
   LOCAL ScreenHeight := 450

   LOCAL scarfy

   LOCAL frameWidth
   LOCAL frameHeight

   LOCAL origin
   LOCAL sourceRec
   LOCAL destRec
   LOCAL rotation := 0

   InitWindow( screenWidth, screenHeight, "Harbour raylib [textures] examples - texture source and destination rectangles" )

   scarfy := LoadTexture( "resources/scarfy.png" )

   frameWidth  := scarfy[ TEXTURE2D_WIDTH ] / 6
   frameHeight := scarfy[ TEXTURE2D_HEIGHT ]

   sourceRec := { 0.0, 0.0, frameWidth, frameHeight }
   destRec := { screenWidth / 2, screenHeight / 2, frameWidth * 2, frameHeight * 2 }
   origin := { frameWidth, frameHeight }

   SetTargetFPS( 60 )

   DO WHILE ! WindowShouldClose()

      BeginDrawing()

      ClearBackground( RAYWHITE )

      rotation++

      DrawTexturePro( scarfy, sourceRec, destRec, origin, rotation, WHITE )

      DrawLine( Int( destRec[ VECTOR2_X ] ), 0, Int( destRec[ VECTOR2_X ] ), screenHeight, GRAY )
      DrawLine( 0, Int( destRec[ VECTOR2_Y ] ), screenWidth, Int( destRec[ VECTOR2_Y ] ), GRAY )

      DrawText( "(c) Scarfy sprite by Eiden Marsal", screenWidth - 200, screenHeight - 20, 10, GRAY )

      EndDrawing()

   ENDDO

   UnloadTexture( scarfy )

   CloseWindow()

   RETURN
