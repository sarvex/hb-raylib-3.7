#include "hbraylib.ch"

#define TEXTURE2D_WIDTH  2
#define TEXTURE2D_HEIGHT 3

PROCEDURE Main()

   LOCAL ScreenWidth := 800
   LOCAL ScreenHeight := 450

   LOCAL image
   LOCAL texture

   InitWindow( ScreenWidth, ScreenHeight, "Harbour raylib [textures] example - image loading" )

   image := LoadImage( "resources/raylib_logo.png" )

   texture := LoadTextureFromImage( image )

   UnloadImage( image )

   SetTargetFPS( 60 )

   DO WHILE ! WindowShouldClose()

      BeginDrawing()

      ClearBackground( RAYWHITE )

      DrawTexture( texture, Int( screenWidth / 2 - texture[ TEXTURE2D_WIDTH ] / 2 ), Int( screenHeight / 2 - texture[ TEXTURE2D_HEIGHT ] / 2 ), WHITE )

      DrawText( "this IS a texture loaded from an image!", 300, 370, 10, GRAY )

      EndDrawing()

   ENDDO

   UnloadTexture( texture )

   CloseWindow()

   RETURN
