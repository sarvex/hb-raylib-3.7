#include "hbraylib.ch"

PROCEDURE Main()

   LOCAL nScreenWidth  := 800
   LOCAL nScreenHeight := 450
   LOCAL lContinue    := .T.

   LOCAL nLogoPositionX := Int( nScreenWidth / 2 - 128 )
   LOCAL nLogoPositionY := Int( nScreenHeight / 2 - 128 )

   LOCAL nFramesCounter := 0
   LOCAL nLettersCount  := 0

   LOCAL nTopSideRecWidth   := 16
   LOCAL nLeftSideRecHeight := 16

   LOCAL nBottomSideRecWidth := 16
   LOCAL nRightSideRecHeight := 16
   
   LOCAL nState := 0
   LOCAL nAlpha := 1.0

   InitWindow( nScreenWidth, nScreenHeight, "Harbour raylib [shapes] example - Harbour raylib logo animation" )

   SetTargetFPS( 60 )

   DO WHILE lContinue

      IF nState == 0
         nFramesCounter++
         IF nFramesCounter == 120
            nState         := 1
            nFramesCounter := 0
         ENDIF
      ELSE
         IF nState == 1
            nTopSideRecWidth    += 4
            nLeftSideRecHeight  += 4
            IF nTopSideRecWidth == 256
               nState := 2
            ENDIF
         ELSE
            IF nState == 2
               nBottomSideRecWidth    += 4
               nRightSideRecHeight    += 4
               IF nBottomSideRecWidth == 256
                  nState := 3
               ENDIF
            ELSE
               IF nState == 3
                  nFramesCounter++
                  IF nFramesCounter = 12
                     nLettersCount++
                     nFramesCounter := 0
                  ENDIF
                  IF nLettersCount >= 18
                     nAlpha -= 0.02
                     IF nAlpha <= 0
                        nAlpha := 0
                        nState := 4
                     ENDIF
                  ENDIF
               ELSE
                  IF nState == 4
                     IF IsKeyPressed( KEY_R )
                        nFramesCounter := 0
                        nLettersCount  := 0

                        nTopSideRecWidth   := 16
                        nLeftSideRecHeight := 16

                        nBottomSideRecWidth := 16
                        nRightSideRecHeight := 16

                        nAlpha := 1.0
                        nState := 0
                     ENDIF
                  ENDIF
               ENDIF
            ENDIF
         ENDIF
      ENDIF

      BeginDrawing()
      ClearBackground( RAYWHITE )

      IF nState == 0
         IF ( nFramesCounter / 15 ) % 2 == 0
            DrawRectangle( nLogoPositionX,  nLogoPositionY, 16, 16, BLACK )
         ENDIF
      ELSE
         IF nState == 1
            DrawRectangle( nLogoPositionX,  nLogoPositionY, nTopSideRecWidth, 16, BLACK )
            DrawRectangle( nLogoPositionX,  nLogoPositionY, 16, nLeftSideRecHeight, BLACK )
         ELSE
            IF nState == 2
               DrawRectangle( nLogoPositionX,  nLogoPositionY, nTopSideRecWidth, 16, BLACK )
               DrawRectangle( nLogoPositionX,  nLogoPositionY, 16, nLeftSideRecHeight, BLACK )

               DrawRectangle( nLogoPositionX + 240,  nLogoPositionY, 16, nRightSideRecHeight, BLACK )
               DrawRectangle( nLogoPositionX,  nLogoPositionY + 240, nBottomSideRecWidth, 16, BLACK )
            ELSE
               IF nState == 3
                  DrawRectangle( nLogoPositionX,  nLogoPositionY, nTopSideRecWidth, 16, Fade( BLACK, nAlpha ) )
                  DrawRectangle( nLogoPositionX,  nLogoPositionY + 16, 16, nLeftSideRecHeight - 32, Fade( BLACK, nAlpha ) )

                  DrawRectangle( nLogoPositionX + 240,  nLogoPositionY + 16, 16, nRightSideRecHeight - 32, Fade( BLACK, nAlpha ) )
                  DrawRectangle( nLogoPositionX,  nLogoPositionY + 240, nBottomSideRecWidth, 16, Fade( BLACK, nAlpha ) )

                  DrawRectangle( Int( nScreenWidth / 2 - 112 ), Int( nScreenHeight / 2 - 112 ), 224, 224, Fade( RAYWHITE, nAlpha ) )

                  DrawText( TextSubtext( e"Harbour\n  raylib", 0, nLettersCount ), Int( nScreenWidth / 2 - 60 ), Int( nScreenHeight / 2  ), 40, Fade( BLACK, nAlpha ) )
               ELSE
                  IF nState == 4
                     DrawText( "[R] REPLAY", 340, 200, 20, GRAY )
                  ENDIF
               ENDIF
            ENDIF
         ENDIF
      ENDIF

      IF WindowShouldClose()
         lContinue := .F.
      ENDIF

      EndDrawing()

   ENDDO

   CloseWindow()

   RETURN
