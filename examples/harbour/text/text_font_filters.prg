#include "hbraylib.ch"

#define FONT_BASESIZE   1
#define FONT_TEXTURE    4

#define VECTOR2_X   1
#define VECTOR2_Y   2

PROCEDURE Main()

   LOCAL nScreenWidth := 800
   LOCAL nScreenHeight := 450
   LOCAL cMsg := "Loaded Font"
   LOCAL aFont
   LOCAL nFontSize
   LOCAL aFontPosition := { 40, nScreenHeight / 2 - 80 }
   LOCAL aTextSize
   LOCAL nCurrentFontFilter := 0
   LOCAL nCount
   LOCAL aDroppedFiles

   InitWindow( nScreenWidth, nScreenHeight, "Harbour raylib [text] example - Font filters" )

   aFont := LoadFontEx( "resources/KAISG.ttf", 96, 0, 0 )

   GenTextureMipmaps( aFont[ FONT_TEXTURE ] )

   nFontSize := aFont[ FONT_BASESIZE ]

   SetTextureFilter( aFont[ FONT_TEXTURE ], FILTER_POINT )

   SetTargetFPS( 60 )

   DO WHILE ! WindowShouldClose()

      nFontSize += GetMouseWheelMove() * 4.0

      IF IsKeyPressed( KEY_ONE )
         SetTextureFilter( aFont[ FONT_TEXTURE ], FILTER_POINT )
         nCurrentFontFilter := 0
      ELSEIF IsKeyPressed( KEY_TWO )
         SetTextureFilter( aFont[ FONT_TEXTURE ], FILTER_BILINEAR )
         nCurrentFontFilter := 1
      ELSEIF IsKeyPressed( KEY_THREE )
         SetTextureFilter( aFont[ FONT_TEXTURE ], FILTER_TRILINEAR )
         nCurrentFontFilter := 2
      ENDIF

      aTextSize := MeasureTextEx( aFont, cMsg, nFontSize, 0 )

      IF IsKeyDown( KEY_LEFT )
         aFontPosition[ VECTOR2_X ] -= 10
      ELSEIF IsKeyDown( KEY_RIGHT )
         aFontPosition[ VECTOR2_X ] += 10
      ENDIF

      IF IsFileDropped()

         nCount := 1
         aDroppedFiles := GetDroppedFiles( nCount )

         IF IsFileExtension( aDroppedFiles[ 1 ], ".ttf" )

            UnloadFont( aFont )
            aFont := LoadFontEx( aDroppedFiles[ 1 ], Int( nFontSize ), 0, 0 )
            ClearDroppedFiles()

         ENDIF
      ENDIF

      BeginDrawing()

      ClearBackground( RAYWHITE )

      DrawText( "Use mouse wheel to change Font size", 20, 20, 10, GRAY )
      DrawText( "Use KEY_RIGHT and KEY_LEFT to move text", 20, 40, 10, GRAY )
      DrawText( "Use 1, 2, 3 to change texture filter", 20, 60, 10, GRAY )
      DrawText( "Drop a new TTF Font for dynamic loading", 20, 80, 10, DARKGRAY )

      DrawTextEx( aFont, cMsg, aFontPosition, nFontSize, 0, BLACK )

      DrawRectangle( 0, nScreenHeight - 80, nScreenWidth, 80, LIGHTGRAY )
      DrawText( TextFormat( "Font size: %02.02f", nFontSize ), 20, nScreenHeight - 50, 10, DARKGRAY )
      DrawText( TextFormat( "Text size: [%02.02f, %02.02f]", aTextSize[ VECTOR2_X ], aTextSize[ VECTOR2_Y ] ), 20, nScreenHeight - 30, 10, DARKGRAY )
      DrawText( "CURRENT TEXTURE FILTER:", 250, 400, 20, GRAY )

      IF nCurrentFontFilter == 0
         DrawText( "POINT", 570, 400, 20, BLACK )
      ELSEIF nCurrentFontFilter == 1
         DrawText( "BILINEAR", 570, 400, 20, BLACK )
      ELSEIF nCurrentFontFilter == 2
         DrawText( "TRILINEAR", 570, 400, 20, BLACK )
      ENDIF

      EndDrawing()

   ENDDO

   ClearDroppedFiles()

   UnloadFont( aFont )

   CloseWindow()

   RETURN
