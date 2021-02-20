
#include "hbraylib.ch"



PROCEDURE Main()

   LOCAL screenWidth  := 800
   LOCAL screenHeight := 450
   LOCAL lContinue    := .T.

   LOCAL logoPositionX := screenWidth / 2 - 128
   LOCAL logoPositionY := screenHeight / 2 - 128

   LOCAL framesCounter := 0
   LOCAL lettersCount  := 0

   LOCAL topSideRecWidth   := 16
   LOCAL leftSideRecHeight := 16

   LOCAL bottomSideRecWidth := 16
   LOCAL rightSideRecHeight := 16

   LOCAL STATE := 0
   LOCAL alpha := 1.0

   InitWindow( screenWidth, screenHeight, "Harbour raylib [shapes] example - Harbour raylib logo animation" )

   SetTargetFPS( 60 )

   DO WHILE lContinue

      IF STATE == 0
         framesCounter++
         IF ( framesCounter == 120 )
            STATE         := 1
            framesCounter := 0
         ENDIF
      ELSE
         IF  STATE == 1
            topSideRecWidth   += 4
            leftSideRecHeight += 4
            IF ( topSideRecWidth == 256 )
               STATE := 2
            END IF
         ELSE
            IF ( STATE == 2 )
               bottomSideRecWidth += 4
               rightSideRecHeight += 4
               IF ( bottomSideRecWidth == 256 )
                  STATE := 3
               END IF
            ELSE
               IF  STATE == 3
                  framesCounter++
                  IF ( framesCounter = 12 )
                     lettersCount++
                     framesCounter := 0
                  END IF
                  IF ( lettersCount >= 10 )
                     alpha -= 0.02
                     IF ( alpha <= 0 )
                        alpha := 0
                        STATE := 4
                     END IF
                  END IF
               ELSE
                  IF  STATE == 4
                     IF IsKeyPressed( KEY_R )
                        framesCounter := 0
                        lettersCount  := 0

                        topSideRecWidth   := 16
                        leftSideRecHeight := 16

                        bottomSideRecWidth := 16
                        rightSideRecHeight := 16

                        alpha := 1.0
                        STATE := 0
                     END IF
                  ENDIF
               ENDIF
            ENDIF
         ENDIF
      ENDIF
      // ---------------------------------------------
      BeginDrawing()
      ClearBackground( RAYWHITE )

      IF  STATE == 0
         IF ( framesCounter / 15 ) % 2 == 0
            DrawRectangle( Int( logoPositionX ), Int( logoPositionY ), 16, 16, BLACK )
         ELSE
         END IF
      ELSE
         IF  STATE == 1
            DrawRectangle( Int( logoPositionX ), Int( logoPositionY ), topSideRecWidth, 16, BLACK )
            DrawRectangle( Int( logoPositionX ), Int( logoPositionY ), 16, leftSideRecHeight, BLACK )
         ELSE
            IF  STATE == 2

               DrawRectangle( Int( logoPositionX ), Int( logoPositionY ), topSideRecWidth, 16, BLACK )
               DrawRectangle( Int( logoPositionX ), Int( logoPositionY ), 16, leftSideRecHeight, BLACK )

               DrawRectangle( Int( logoPositionX ) + 240, Int( logoPositionY ), 16, rightSideRecHeight, BLACK )
               DrawRectangle( Int( logoPositionX ), Int( logoPositionY ) + 240, bottomSideRecWidth, 16, BLACK )
            ELSE
               IF  STATE == 3

                  DrawRectangle( Int( logoPositionX ), Int( logoPositionY ), topSideRecWidth, 16, Fade( BLACK, alpha ) )
                  DrawRectangle( Int( logoPositionX ), Int( logoPositionY ) + 16, 16, leftSideRecHeight - 32, Fade( BLACK, alpha ) )

                  DrawRectangle( Int( logoPositionX ) + 240, Int( logoPositionY ) + 16, 16, rightSideRecHeight - 32, Fade( BLACK, alpha ) )
                  DrawRectangle( Int( logoPositionX ), Int( logoPositionY ) + 240, bottomSideRecWidth, 16, Fade( BLACK, alpha ) )

                  DrawRectangle( Int( screenWidth / 2 - 112 ), Int( screenHeight / 2 - 112 ), 224, 224, Fade( RAYWHITE, alpha ) )

                  DrawText( TextSubtext( "Harbour", 0, lettersCount ), Int( screenWidth / 2 - 100 ), Int( screenHeight / 2  ), 50, Fade( BLACK, alpha ) )
                  DrawText( TextSubtext( " raylib", 0, lettersCount ), Int( screenWidth / 2 - 30 ), Int( screenHeight / 2 + 48 ), 40, Fade( BLACK, alpha ) )
               ELSE
                  IF  STATE == 4
                     DrawText( "[R] REPLAY", 340, 200, 20, GRAY )
                  ENDIF
               END IF
            END IF
         END IF
      ENDIF

      IF WindowShouldClose()
         lContinue := .F.
      ENDIF

      EndDrawing()

   ENDDO

   CloseWindow()

   RETURN
