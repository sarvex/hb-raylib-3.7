#include "hbraylib.ch"

#define MAX_BUNNIES        50000
#define MAX_BATCH_ELEMENTS 8192

#define POSITION           1
#define SPEED              2
#define ACOLOR             3

#define VECTOR2_X          1
#define VECTOR2_Y          2

#define TEXTURE2D_WIDTH    2
#define TEXTURE2D_HEIGHT   3

PROCEDURE Main()

   LOCAL nScreenWidth := 800
   LOCAL nScreenHeight := 450

   LOCAL aTexBunny
   LOCAL nBunniesCount := 0
   LOCAL aBunnies[ 3, MAX_BUNNIES ]
   LOCAL i

   InitWindow( nScreenWidth, nScreenHeight, "Harbour raylib [textures] example - bunnymark" )

   aTexBunny := LoadTexture( "resources/wabbit_alpha.png" )

   SetTargetFPS( 60 )

   DO WHILE ! WindowShouldClose()

      IF IsMouseButtonDown( MOUSE_LEFT_BUTTON )
         FOR  i := 0 TO 100
            IF nBunniesCount < MAX_BUNNIES
               nBunniesCount++
               aBunnies[ POSITION, nBunniesCount ] := GetMousePosition()
               aBunnies[ SPEED, nBunniesCount ] := { GetRandomValue( - 250, 250 ) / 60.0, GetRandomValue( - 250, 250 ) / 60.0 }
               aBunnies[ ACOLOR, nBunniesCount ] := { GetRandomValue( 50, 240 ), GetRandomValue( 80, 240 ), GetRandomValue( 100, 240 ), 255 }
            ENDIF
         NEXT
      ENDIF

      FOR i := 1 TO nBunniesCount
         aBunnies[ POSITION, i, VECTOR2_X ] += aBunnies[ SPEED, i, VECTOR2_X ]
         aBunnies[ POSITION, i, VECTOR2_Y ] += aBunnies[ SPEED, i, VECTOR2_Y ]
         IF aBunnies[ POSITION, i, VECTOR2_X ] + aTexBunny[ TEXTURE2D_WIDTH ] / 2 > GetScreenWidth() .OR. ;
               aBunnies[ POSITION, i, VECTOR2_X ] + aTexBunny[ TEXTURE2D_WIDTH ] / 2 < 0
            aBunnies[ SPEED, i, VECTOR2_X ] *= -1
         ENDIF
         IF aBunnies[ POSITION, i, VECTOR2_Y ] + aTexBunny[ TEXTURE2D_HEIGHT ] / 2 > GetScreenHeight() .OR. ;
               aBunnies[ POSITION, i, VECTOR2_Y ] + aTexBunny[ TEXTURE2D_HEIGHT ] / 2 - 40 < 0
            aBunnies[ SPEED, i, VECTOR2_Y ] *= -1
         ENDIF
      NEXT

      BeginDrawing()

      ClearBackground( RAYWHITE )

      FOR i := 1 TO nBunniesCount
         DrawTexture( aTexBunny, Int( aBunnies[ POSITION, i, VECTOR2_X ] ), Int( aBunnies[ POSITION, i, VECTOR2_Y ] ), aBunnies[ ACOLOR, i ] )
      NEXT

      DrawRectangle( 0, 0, nScreenWidth, 40, BLACK )
      DrawText( TextFormat( "bunnies: %i", nBunniesCount ), 120, 10, 20, GREEN )
      DrawText( TextFormat( "batched draw calls: %i", 1 + nBunniesCount / MAX_BATCH_ELEMENTS ), 320, 10, 20, MAROON )

      DrawFPS( 10, 10 )

      EndDrawing()

   ENDDO

   UnloadTexture( aTexBunny )

   CloseWindow()

   RETURN
