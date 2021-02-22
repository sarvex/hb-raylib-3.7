
#include "hbraylib.ch"

#define X 1
#define Y 2


PROCEDURE Main()

   LOCAL screenWidth  := 800
   LOCAL screenHeight := 450
   LOCAL lContinue    := .T.

   LOCAL ballPosition :=  {}
   LOCAL ballSpeed := { 5.0, 4.0 }
   LOCAL ballRadius := 20

   LOCAL pause := .F.
   LOCAL framesCounter := 0

   InitWindow( screenWidth, screenHeight, "Harbour raylib [shapes] example - bouncing ball" )

   ballPosition :=  { GetScreenWidth() / 2, GetScreenHeight() / 2 }

   SetTargetFPS( 60 )

   DO WHILE lContinue

      IF IsKeyPressed( KEY_SPACE )
         iif( pause = .T., pause := .F., pause := .T. )
      ENDIF

      IF !pause
         ballPosition[ X ] += ballSpeed[ X ]
         ballPosition[ Y ] += ballSpeed[ Y ]

         IF ballPosition[ X ] >= GetScreenWidth() - ballRadius .OR. ballPosition[ X ] <= ballRadius
            ballSpeed[ X ] *= -1.0
         ENDIF

         IF ballPosition[ Y ] >= GetScreenHeight() - ballRadius .OR. ballPosition[ Y ] <= ballRadius
            ballSpeed[ Y ] *= -1.0
         ENDIF
      ELSE
         framesCounter++
      ENDIF

      BeginDrawing()
      ClearBackground( RAYWHITE )

      DrawCircleV( ballPosition, ballRadius, MAROON )
      DrawText( "PRESS SPACE to PAUSE BALL MOVEMENT", 10, GetScreenHeight() - 25, 20, LIGHTGRAY )

      IF pause .AND. framesCounter / 30  % 2 == 0
         DrawText( "PAUSED", 350, 200, 30, GRAY )
      ENDIF

      DrawFPS( 10, 10 )
      EndDrawing()

      IF WindowShouldClose()
         lContinue := .F.
      ENDIF
   ENDDO

   CloseWindow()

   RETURN
