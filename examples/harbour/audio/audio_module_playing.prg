#include "hbraylib.ch"

#define LOOPING      3

#define MAX_CIRCLES  64
#define ALPHA        1
#define RADIUS       2
#define POSITION     3
#define SPEED        4
#define ACOLOR       5

PROCEDURE Main()

   LOCAL nScreenWidth := 800
   LOCAL nScreenHeight := 450
   LOCAL aColors := { ORANGE, RED, GOLD, LIME, BLUE, VIOLET, BROWN, LIGHTGRAY, PINK, YELLOW, GREEN, SKYBLUE, PURPLE, BEIGE }
   LOCAL aMusic
   LOCAL aCircles[ MAX_CIRCLES, 5 ]
   LOCAL nTimePlayed
   LOCAL lPause := .F.
   LOCAL nPitch := 1.0
   LOCAL i

   InitWindow( nScreenWidth, nScreenHeight, "Harbour raylib [audio] example - module playing (streaming)" )

   InitAudioDevice()

   FOR i := MAX_CIRCLES TO 1 STEP -1
      aCircles[ i, ALPHA ] := 0
      aCircles[ i, RADIUS ] := GetRandomValue( 10, 40 )
      aCircles[ i, POSITION ] := { GetRandomValue( aCircles[ i, RADIUS ], nScreenWidth - aCircles[ i, RADIUS ] ), GetRandomValue( aCircles[ i, RADIUS ], nScreenHeight - aCircles[ i, RADIUS ] ) }
      aCircles[ i, SPEED ] := GetRandomValue( 1, 100 ) / 2000
      aCircles[ i, ACOLOR ] := aColors[ GetRandomValue( 1, 14 ) ]
   NEXT

   aMusic := LoadMusicStream( "resources/mini1111.xm" )
   aMusic[ LOOPING ] := .F.

   PlayMusicStream( aMusic )

   SetTargetFPS( 60 )

   DO WHILE ! WindowShouldClose()

      UpdateMusicStream( aMusic )

      IF IsKeyPressed( KEY_SPACE )
         StopMusicStream( aMusic )
         PlayMusicStream( aMusic )
      ENDIF

      IF IsKeyPressed( KEY_P )
         lPause := !lPause
         IF lPause
            PauseMusicStream( aMusic )
         ELSE
            ResumeMusicStream( aMusic )
         ENDIF
      ENDIF

      IF IsKeyDown( KEY_DOWN )
         nPitch -= 0.01
      ELSEIF IsKeyDown( KEY_UP )
         nPitch += 0.01
      ENDIF

      SetMusicPitch( aMusic, nPitch )

      nTimePlayed := GetMusicTimePlayed( aMusic ) / GetMusicTimeLength( aMusic ) * ( nScreenWidth - 40 )
      IF !lPause
         FOR i := MAX_CIRCLES TO 1 STEP -1
            aCircles[ i, ALPHA ] += aCircles[ i, SPEED ]
            aCircles[ i, RADIUS ] += aCircles[ i, SPEED ] * 10

            IF aCircles[ i, ALPHA ] > 1
               aCircles[ i, SPEED ] *= -1
            ENDIF

            IF aCircles[ i, ALPHA ] <= 0
               aCircles[ i, ALPHA ] := 0
               aCircles[ i, RADIUS ] := GetRandomValue( 10, 40 )
               aCircles[ i, POSITION ] := { GetRandomValue( aCircles[ i, RADIUS ], nScreenWidth - aCircles[ i, RADIUS ] ), GetRandomValue( aCircles[ i, RADIUS ], nScreenHeight - aCircles[ i, RADIUS ] ) }
               aCircles[ i, SPEED ] := GetRandomValue( 1, 100 ) / 2000
               aCircles[ i, ACOLOR ] := aColors[ GetRandomValue( 1, 14 ) ]
            ENDIF
         NEXT
      ENDIF

      BeginDrawing()

      ClearBackground( RAYWHITE )

      FOR i := MAX_CIRCLES TO 1 STEP -1
         DrawCircleV( aCircles[ i, POSITION ], aCircles[ i, RADIUS ], Fade( aCircles[ i, ACOLOR ], aCircles[ i, ALPHA ] ) )
      NEXT

      DrawRectangle( 20, nScreenHeight - 20 - 12, nScreenWidth - 40, 12, LIGHTGRAY )
      DrawRectangle( 20, nScreenHeight - 20 - 12, Int( nTimePlayed ), 12, MAROON )
      DrawRectangleLines( 20, nScreenHeight - 20 - 12, nScreenWidth - 40, 12, GRAY )

      EndDrawing()

   ENDDO

   UnloadMusicStream( aMusic )

   CloseAudioDevice()

   CloseWindow()

   RETURN
