#include "hbraylib.ch"

#define MAX_PARTICLES    200
#define POSITION         1
#define ACOLOR           2
#define ALPHA            3
#define SIZE             4
#define ROTATION         5
#define ACTIVE           6

#define TEXTURE2D_WIDTH  2
#define TEXTURE2D_HEIGHT 3

#define VECTOR2_X        1
#define VECTOR2_Y        2

#define RECTANGLE_X      1
#define RECTANGLE_Y      2

PROCEDURE Main()

   LOCAL nScreenWidth := 800
   LOCAL nScreenHeight := 450
   LOCAL aMouseTail[ 6, MAX_PARTICLES ]
   LOCAL aSmoke
   LOCAL nBlending := BLEND_ALPHA
   LOCAL nGravity := 3.0
   LOCAL aSourceRec := { 0.0, 0.0 }
   LOCAL i

   InitWindow( nScreenWidth, nScreenHeight, "Harbour raylib [textures] example - particles blending" )

   FOR i := 1 TO MAX_PARTICLES
      aMouseTail[ POSITION, i ] := { 3, 4 }
      aMouseTail[ ACOLOR, i ] := { GetRandomValue( 0, 255 ), GetRandomValue( 0, 255 ), GetRandomValue( 0, 255 ), 255 }
      aMouseTail[ ALPHA, i ] := 1
      aMouseTail[ SIZE, i ] := GetRandomValue( 1, 30 ) / 20.0
      aMouseTail[ ROTATION, i ] := GetRandomValue( 0, 360 )
      aMouseTail[ ACTIVE, i ] := .F.
   NEXT

   aSmoke = LoadTexture( "resources/spark_flame.png" )

   SetTargetFPS( 60 )

   DO WHILE ! WindowShouldClose()

      FOR i := 1 TO MAX_PARTICLES
         IF !aMouseTail[ ACTIVE, i ]
            aMouseTail[ ACTIVE, i ] := .T.
            aMouseTail[ ALPHA, i ] := 1
            aMouseTail[ POSITION, i ] := GetMousePOSITION()
            i := MAX_PARTICLES
         ENDIF
      NEXT

      FOR i := 1 TO MAX_PARTICLES
         IF aMouseTail[ ACTIVE, i ]
            aMouseTail[ POSITION, i, VECTOR2_Y ] += nGravity / 2
            aMouseTail[ ALPHA, i ] -= 0.005
         ENDIF

         IF aMouseTail[ ALPHA, i ] <= 0
            aMouseTail[ ACTIVE, i ] := .F.
         ENDIF
         aMouseTail[ ROTATION, i ] += 2.0
      NEXT

      IF IsKeyPressed( KEY_SPACE )
         IF nBlending == BLEND_ALPHA
            nBlending := BLEND_ADDITIVE
         ELSE
            nBlending := BLEND_ALPHA
         ENDIF
      ENDIF

      BeginDrawing()

      ClearBackground( DARKGRAY )

      BeginBlendMode( nBlending )

      FOR i := 1 TO MAX_PARTICLES
         IF aMouseTail[ ACTIVE, i ]
            DrawTexturePro( aSmoke, { aSourceRec[ RECTANGLE_X ], aSourceRec[ RECTANGLE_Y ], aSmoke[ TEXTURE2D_WIDTH ], aSmoke[ TEXTURE2D_HEIGHT ]  }, ;
               { aMouseTail[ POSITION, i, VECTOR2_X ], aMouseTail[ POSITION, i, VECTOR2_Y ], aSmoke[ TEXTURE2D_WIDTH ] * aMouseTail[ SIZE, i ], aSmoke[ TEXTURE2D_HEIGHT ] * aMouseTail[ SIZE, i ] }, ;
               { ( aSmoke[ TEXTURE2D_WIDTH ] * aMouseTail[ SIZE, i ] / 2.0 ), ( aSmoke[ TEXTURE2D_HEIGHT ] * aMouseTail[ SIZE, i ] / 2.0 ) }, ;
               aMouseTail[ ROTATION, i ], Fade( aMouseTail[ ACOLOR, i ], aMouseTail[ ALPHA, i ] ) )
         ENDIF
      NEXT

      EndBlendMode()

      DrawText( "PRESS SPACE to CHANGE BLENDING MODE", 180, 20, 20, BLACK )

      IF nBlending == BLEND_ALPHA
         DrawText( "ALPHA BLENDING", 290, nScreenHeight - 40, 20, BLACK )
      ELSE
         DrawText( "ADDITIVE BLENDING", 280, nScreenHeight - 40, 20, RAYWHITE )
      ENDIF

      EndDrawing()

   ENDDO

   UnloadTexture( aSmoke )

   CloseWindow()

   RETURN
