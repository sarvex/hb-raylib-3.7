#include "hbraylib.ch"

#define TEXTURE2D_WIDTH  2
#define TEXTURE2D_HEIGHT 3

PROCEDURE Main()

   LOCAL nScreenWidth  := 800
   LOCAL nScreenHeight := 450

   LOCAL aBgImage
   LOCAL aBgTexture

   LOCAL aFgImage
   LOCAL aFgTexture

   LOCAL nBlendCountMax := 4
   LOCAL nBlendMode := 0

   SetTargetFPS( 60 )

   InitWindow( nScreenWidth, nScreenHeight, "Harbour raylib [textures] example - blend modes" )

   aBgImage := LoadImage( "resources/cyberpunk_street_background.png" )
   aBgTexture := LoadTextureFromImage( aBgImage )

   aFgImage := LoadImage( "resources/cyberpunk_street_foreground.png" )
   aFgTexture := LoadTextureFromImage( aFgImage )

   UnloadImage( aBgImage )
   UnloadImage( aFgImage )

   DO WHILE ! WindowShouldClose()
      IF IsKeyPressed( KEY_SPACE )
         IF nBlendMode >= nBlendCountMax - 1
            nBlendMode := 0
         ELSE
            nBlendMode++
         ENDIF
      ENDIF

      BeginDrawing()

      ClearBackground( RAYWHITE )

      DrawTexture( aBgTexture, Int( nScreenWidth  / 2 - aBgTexture[ TEXTURE2D_WIDTH ] / 2 ), Int( nScreenHeight / 2 - aBgTexture[ TEXTURE2D_HEIGHT ] / 2 ), WHITE )

      BeginBlendMode( nBlendMode )
      DrawTexture( aFgTexture, Int( nScreenWidth  / 2 - afgTexture[ TEXTURE2D_WIDTH ] / 2 ), Int( nScreenHeight / 2 - afgTexture[ TEXTURE2D_HEIGHT ] / 2 ), WHITE )
      EndBlendMode()

      DrawText( "Press SPACE to change blend modes.", 310, 350, 10, GRAY )

      DO CASE
      CASE nBlendMode = BLEND_ALPHA
         DrawText( "Current: BLEND_ALPHA", Int( nScreenWidth / 2 - 60 ), 370, 10, GRAY )
      CASE nBlendMode = BLEND_ADDITIVE
         DrawText( "Current: BLEND_ADDITIVE", Int( nScreenWidth / 2 - 60 ), 370, 10, GRAY )
      CASE nBlendMode = BLEND_MULTIPLIED
         DrawText( "Current: BLEND_MULTIPLIED", Int( nScreenWidth / 2 - 60 ), 370, 10, GRAY )
      CASE nBlendMode = BLEND_ADD_COLORS
         DrawText( "Current: BLEND_ADD_COLORS", Int( nScreenWidth / 2 - 60 ), 370, 10, GRAY )
      ENDCASE

      DrawText( "(c) Cyberpunk Street Environment by Luis Zuno (@ansimuz)", Int( nScreenWidth - 330 ), Int( nScreenHeight - 20 ), 10, GRAY )

      EndDrawing()
 
   ENDDO

   UnloadTexture( aBgTexture )
   UnloadTexture( afgTexture )

   CloseWindow()

   RETURN
