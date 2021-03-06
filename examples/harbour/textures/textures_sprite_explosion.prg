#include "hbraylib.ch"

#define NUM_FRAMES_PER_LINE   5
#define NUM_LINES             5

#define TEXTURE2D_WIDTH    2
#define TEXTURE2D_HEIGHT   3

#define VECTOR2_X   1
#define VECTOR2_Y   2

#define RECTANGLE_X   1
#define RECTANGLE_Y   2

PROCEDURE Main()

   LOCAL nScreenWidth := 800
   LOCAL nScreenHeight := 450
   LOCAL aFxBoom
   LOCAL aExplosion
   LOCAL nFrameWidth
   LOCAL nFrameHeight
   LOCAL nCurrentFrame := 0
   LOCAL nCurrentLine := 0
   LOCAL aFrameRec
   LOCAL aPosition := { 0.0, 0.0 }
   LOCAL lActive := .F.
   LOCAL nFramesCounter := 0

   InitWindow( nScreenWidth, nScreenHeight, "Harbour raylib [textures] example - sprite explosion" )

   InitAudioDevice()

   aFxBoom := LoadSound( "resources/boom.wav" )

   aExplosion := LoadTexture( "resources/explosion.png" )

   nFrameWidth := aExplosion[ TEXTURE2D_WIDTH ] / NUM_FRAMES_PER_LINE
   nFrameHeight := aExplosion[ TEXTURE2D_HEIGHT ] / NUM_LINES

   aFrameRec := { 0, 0, nFrameWidth, nFrameHeight }

   SetTargetFPS( 120 )

   DO WHILE ! WindowShouldClose()

      IF IsMouseButtonPressed( MOUSE_LEFT_BUTTON ) .AND. ! lActive

         aPosition := GetMousePosition()
         lActive := .T.

         aPosition[ VECTOR2_X ] -= nFrameWidth / 2
         aPosition[ VECTOR2_Y ] -= nFrameHeight / 2

         PlaySound( aFxBoom )
      ENDIF

      IF ( lActive )

         nFramesCounter++

         IF nFramesCounter > 2

            nCurrentFrame++

            IF nCurrentFrame >= NUM_FRAMES_PER_LINE

               nCurrentFrame = 0
               nCurrentLine++

               IF nCurrentLine >= NUM_LINES
                  nCurrentLine := 0
                  lActive := .F.
               ENDIF
            ENDIF

            nFramesCounter = 0
         ENDIF
      ENDIF

      aFrameRec[ RECTANGLE_X ] := nFrameWidth * nCurrentFrame
      aFrameRec[ RECTANGLE_Y ] := nFrameHeight * nCurrentLine

      BeginDrawing()

      ClearBackground( RAYWHITE )

      IF lActive
         DrawTextureRec( aExplosion, aFrameRec, aPosition, WHITE )
      ENDIF

      EndDrawing()

   ENDDO

   UnloadTexture( aExplosion )
   UnloadSound( aFxBoom )

   CloseAudioDevice()

   CloseWindow()

   RETURN
