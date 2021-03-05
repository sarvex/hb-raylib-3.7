#include "hbraylib.ch"

#define MAX_FRAME_SPEED   15
#define MIN_FRAME_SPEED   1

#define TEXTURE2D_WIDTH   2
#define TEXTURE2D_HEIGHT  3

#define RECTANGLE_X        1
#define RECTANGLE_Y        2
#define RECTANGLE_WIDTH    3
#define RECTANGLE_HEIGHT   4

PROCEDURE Main()

   LOCAL nScreenWidth := 800
   LOCAL nScreenHeight := 450
   LOCAL aScarfy
   LOCAL aPosition
   LOCAL aFrameRec
   LOCAL nCurrentFrame := 0
   LOCAL nFramesCounter := 0
   LOCAL nFramesSpeed := 8
   LOCAL i

   InitWindow( nScreenWidth, nScreenHeight, "Harbour raylib [texture] example - texture rectangle" )

   aScarfy := LoadTexture( "resources/scarfy.png" )

   aPosition := { 350.0, 280.0 }
   aFrameRec := { 0.0, 0.0, aScarfy[ TEXTURE2D_WIDTH ] / 6, aScarfy[ TEXTURE2D_HEIGHT ] }

   SetTargetFPS( 60 )

   DO WHILE ! WindowShouldClose()

      nFramesCounter++

      IF nFramesCounter >= ( 60 / nFramesSpeed )

         nFramesCounter := 0
         nCurrentFrame++

         IF nCurrentFrame > 5
            nCurrentFrame := 0
         ENDIF

         aFrameRec[ RECTANGLE_X ] := nCurrentFrame * aScarfy[ TEXTURE2D_WIDTH ] / 6

      ENDIF

      IF IsKeyPressed( KEY_RIGHT )
         nFramesSpeed++
      ELSEIF IsKeyPressed( KEY_LEFT )
         nFramesSpeed--
      ENDIF

      IF nFramesSpeed > MAX_FRAME_SPEED
         nFramesSpeed := MAX_FRAME_SPEED
      ELSEIF nFramesSpeed < MIN_FRAME_SPEED
         nFramesSpeed := MIN_FRAME_SPEED
      ENDIF

      BeginDrawing()

      ClearBackground( RAYWHITE )

      DrawTexture( aScarfy, 15, 40, WHITE )
      DrawRectangleLines( 15, 40, aScarfy[ TEXTURE2D_WIDTH ], aScarfy[ TEXTURE2D_HEIGHT ], LIME )
      DrawRectangleLines( 15 + Int( aFrameRec[ RECTANGLE_X ] ), 40 + Int( aFrameRec[ RECTANGLE_Y ] ), Int( aFrameRec[ RECTANGLE_WIDTH ] ), Int( aFrameRec[ RECTANGLE_HEIGHT ] ), RED )

      DrawText( "FRAME SPEED: ", 165, 210, 10, DARKGRAY )
      DrawText( TextFormat( "  %02i FPS", nFramesSpeed ), 575, 210, 10, DARKGRAY )
      DrawText( "PRESS RIGHT/LEFT KEYS to CHANGE SPEED!", 290, 240, 10, DARKGRAY )

      FOR i := 0 TO MAX_FRAME_SPEED - 1

         IF i < nFramesSpeed
            DrawRectangle( 250 + 21 * i, 205, 20, 20, RED )
         ENDIF

         DrawRectangleLines( 250 + 21 * i, 205, 20, 20, MAROON )

      NEXT

      DrawTextureRec( aScarfy, aFrameRec, aPosition, WHITE )

      DrawText( "(c) Scarfy sprite by Eiden Marsal", nScreenWidth - 200, nScreenHeight - 20, 10, GRAY )

      EndDrawing()

   ENDDO

   UnloadTexture( aScarfy )

   CloseWindow()

   RETURN
