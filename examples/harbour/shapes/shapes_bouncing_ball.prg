#include "hbraylib.ch"

#define VECTOR2_X 1
#define VECTOR2_Y 2

PROCEDURE Main()

   LOCAL nScreenWidth  := 800
   LOCAL nScreenHeight := 450
   LOCAL lContinue    := .T.

   LOCAL aBallSpeed := { 5.0, 4.0 }
   LOCAL nBallRadius := 20

   LOCAL lPause := .F.
   LOCAL nFramesCounter := 0
   LOCAL aBallPosition

   InitWindow( nScreenWidth, nScreenHeight, "Harbour raylib [shapes] example - bouncing ball" )

   aBallPosition :=  { GetScreenWidth() / 2, GetScreenHeight() / 2 }

   SetTargetFPS( 60 )

   DO WHILE lContinue

      IF IsKeyPressed( KEY_SPACE )
         iif( lPause == .T., lPause := .F., lPause := .T. )
      ENDIF

      IF !lPause
         aBallPosition[ VECTOR2_X ] += aBallSpeed[ VECTOR2_X ]
         aBallPosition[ VECTOR2_Y ] += aBallSpeed[ VECTOR2_Y ]

         IF aBallPosition[ VECTOR2_X ] >= GetScreenWidth() - nBallRadius .OR. aBallPosition[ VECTOR2_X ] <= nBallRadius
            aBallSpeed[ VECTOR2_X ] *= -1.0
         ENDIF

         IF aBallPosition[ VECTOR2_Y ] >= GetScreenHeight() - nBallRadius .OR. aBallPosition[ VECTOR2_Y ] <= nBallRadius
            aBallSpeed[ VECTOR2_Y ] *= -1.0
         ENDIF
      ELSE
         nFramesCounter++
      ENDIF

      BeginDrawing()
      ClearBackground( RAYWHITE )

      DrawCircleV( aBallPosition, nBallRadius, MAROON )
      DrawText( "PRESS SPACE to PAUSE BALL MOVEMENT", 10, GetScreenHeight() - 25, 20, LIGHTGRAY )

      IF lPause .AND. nFramesCounter / 30 % 2 == 0
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
