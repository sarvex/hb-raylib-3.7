#include "hbraylib.ch"

#define TEXTURE2D_WIDTH  2
#define TEXTURE2D_HEIGHT 3

PROCEDURE Main()

   LOCAL nScreenWidth := 800
   LOCAL nScreenHeight := 450

   LOCAL aTexture

   InitWindow( nScreenWidth, nScreenHeight, "Harbour raylib [aTextures] example - Texture loading and drawing" )

   aTexture := LoadTexture( "resources/raylib_logo.png" )

   SetTargetFPS( 60 )

   DO WHILE ! WindowShouldClose()

      BeginDrawing()

      ClearBackground( RAYWHITE )

      DrawTexture( aTexture, Int( nScreenWidth / 2 - aTexture[ TEXTURE2D_WIDTH ] / 2 ), Int( nScreenHeight / 2 - aTexture[ TEXTURE2D_HEIGHT ] / 2 ), WHITE )

      DrawText( "this IS a aTexture!", 360, 370, 10, GRAY )

      EndDrawing()

   ENDDO

   UnloadTexture( aTexture )

   CloseWindow()

   RETURN
