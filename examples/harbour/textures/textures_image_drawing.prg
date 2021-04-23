#include "hbraylib.ch"

#define TEXTURE2D_WIDTH  2
#define TEXTURE2D_HEIGHT 3

#define VECTOR2_X        1
#define VECTOR2_Y        2

#define FONT_BASESIZE    1

PROCEDURE Main()

   LOCAL nScreenWidth := 800
   LOCAL nScreenHeight := 450
   LOCAL aCat
   LOCAL aParrots
   LOCAL aTexture
   LOCAL aFont

   InitWindow( nScreenWidth, nScreenHeight, "Harbour raylib [textures] example - image drawing" )

   aCat := LoadImage( "resources/cat.png" )
   // ImageCrop( aCat, { 100, 10, 280, 380 } )
   // ImageFlipHorizontal( aCat )
   // ImageResize( aCat, 150, 200 )
   aParrots := LoadImage( "resources/parrots.png" )

   ImageDraw( aParrots, aCat, { 0, 0, aCat[ TEXTURE2D_WIDTH ], aCat[ TEXTURE2D_HEIGHT ] }, { 30, 40, aCat[ TEXTURE2D_WIDTH ] * 1.5, aCat[ TEXTURE2D_HEIGHT ] * 1.5 }, WHITE )
   // ImageCrop( aParrots, { 0, 50, aParrots[ TEXTURE2D_WIDTH ], aParrots[ TEXTURE2D_HEIGHT ] - 100 } )
   ImageDrawPixel( aParrots, 10, 10, RAYWHITE )
   ImageDrawCircle( aParrots, 10, 10, 5, RAYWHITE )
   ImageDrawRectangle( aParrots, 5, 20, 10, 10, RAYWHITE )

   UnloadImage( aCat )

   aFont := LoadFont( "resources/custom_jupiter_crash.png" )

   ImageDrawTextEx( aParrots, aFont, "PARROTS & CAT", { 300, 230 }, aFont[ FONT_BASESIZE ], - 2, WHITE )

   UnloadFont( aFont )

   aTexture := LoadTextureFromImage( aParrots )
   UnloadImage( aParrots )

   SetTargetFPS( 60 )

   DO WHILE ! WindowShouldClose()

      BeginDrawing()

      ClearBackground( RAYWHITE )

      DrawTexture( aTexture, Int( nScreenWidth / 2 - aTexture[ TEXTURE2D_WIDTH ] / 2 ), Int( nScreenHeight / 2 - aTexture[ TEXTURE2D_HEIGHT ] / 2 - 40 ), WHITE )
      DrawRectangleLines( Int( nScreenWidth / 2 - aTexture[ TEXTURE2D_WIDTH ] / 2 ), Int( nScreenHeight / 2 - aTexture[ TEXTURE2D_HEIGHT ] / 2 - 40 ), ;
         Int( aTexture[ TEXTURE2D_WIDTH ] ), Int( aTexture[ TEXTURE2D_HEIGHT ] ), DARKGRAY )

      DrawText( "We are drawing only one texture from various images composed!", 240, 350, 10, DARKGRAY )
      DrawText( "Source images have been cropped, scaled, flipped and copied one over the other.", 190, 370, 10, DARKGRAY )

      EndDrawing()

   ENDDO

   UnloadTexture( aTexture )

   CloseWindow()

   RETURN
