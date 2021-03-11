#include "hbraylib.ch"

#define TEXTURE2D_WIDTH  2
#define TEXTURE2D_HEIGHT 3

PROCEDURE Main()

   LOCAL nScreenWidth := 800
   LOCAL nScreenHeight := 450

   LOCAL aBackground
   LOCAL aMidground
   LOCAL aForeground

   LOCAL nScrollingBack := 0.0
   LOCAL nScrollingMid := 0.0
   LOCAL nScrollingFore := 0.0

   InitWindow( nScreenWidth, nScreenHeight, "Harbour raylib [textures] example - background scrolling" )


   aBackground := LoadTexture( "resources/cyberpunk_street_background.png" )
   aMidground := LoadTexture( "resources/cyberpunk_street_midground.png" )
   aForeground := LoadTexture( "resources/cyberpunk_street_foreground.png" )

   SetTargetFPS( 60 )

   DO WHILE ! WindowShouldClose()

      nScrollingBack -= 0.1
      nScrollingMid -= 0.5
      nScrollingFore -= 1.0

      IF ( nScrollingBack <= -aBackground[ TEXTURE2D_WIDTH ] * 2 )
         nScrollingBack := 0
      ENDIF

      IF ( nScrollingMid <= -aMidground[ TEXTURE2D_WIDTH ] * 2 )
         nScrollingMid := 0
      ENDIF

      IF ( nScrollingFore <= -aForeground[ TEXTURE2D_WIDTH ] * 2 )
         nScrollingFore := 0
      ENDIF

      BeginDrawing()

      ClearBackground( GetColor( 0x052c46ff ) )

      DrawTextureEx( aBackground, { nScrollingBack, 20 }, 0.0, 2.0, WHITE )

      DrawTextureEx( aBackground, { aBackground[ TEXTURE2D_WIDTH ] * 2 + nScrollingBack, 20 }, 0.0, 2.0, WHITE )

      DrawTextureEx( aMidground, { nScrollingMid, 20 }, 0.0, 2.0, WHITE )

      DrawTextureEx( aMidground, { aMidground[ TEXTURE2D_WIDTH ] * 2 + nScrollingMid, 20 }, 0.0, 2.0, WHITE )

      DrawTextureEx( aForeground, { nScrollingFore, 70 }, 0.0, 2.0, WHITE )

      DrawTextureEx( aForeground, { aForeground[ TEXTURE2D_WIDTH ] * 2 + nScrollingFore, 70 }, 0.0, 2.0, WHITE )

      DrawText( "BACKGROUND SCROLLING & PARALLAX", 10, 10, 20, RED )
      DrawText( "(c) Cyberpunk Street Environment by Luis Zuno (@ansimuz)", nScreenWidth - 330, nScreenHeight - 20, 10, RAYWHITE )

      EndDrawing()

   ENDDO

   UnloadTexture( aBackground )
   UnloadTexture( aMidground )
   UnloadTexture( aForeground )

   CloseWindow()

   RETURN
