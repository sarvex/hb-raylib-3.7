#include "hbraylib.ch"

#define LOGO     0
#define TITLE    1
#define GAMEPLAY 2
#define ENDING   3

PROCEDURE Main()

   LOCAL nScreenWidth := 800
   LOCAL nScreenHeight := 450
   LOCAL nCurrentScreen := LOGO
   LOCAL nFramesCounter := 0

   InitWindow( nScreenWidth, nScreenHeight, "Harbour raylib [core] example - basic screen manager" )

   SetTargetFPS( 60 )

   DO WHILE ! WindowShouldClose()

      SWITCH nCurrentScreen

      CASE LOGO

         nFramesCounter++
         IF nFramesCounter > 120
            nCurrentScreen := TITLE
         ENDIF
         EXIT

      CASE TITLE

         IF IsKeyPressed( KEY_ENTER ) .OR. IsGestureDetected( GESTURE_TAP )
            nCurrentScreen := GAMEPLAY
         ENDIF

         EXIT

      CASE GAMEPLAY

         IF IsKeyPressed( KEY_ENTER ) .OR. IsGestureDetected( GESTURE_TAP )
            nCurrentScreen := ENDING
         ENDIF
         EXIT

      CASE ENDING

         IF IsKeyPressed( KEY_ENTER ) .OR. IsGestureDetected( GESTURE_TAP )
            nCurrentScreen := TITLE
         ENDIF
         EXIT

      ENDSWITCH

      BeginDrawing()

      ClearBackground( RAYWHITE )

      SWITCH nCurrentScreen

      CASE LOGO

         DrawText( "LOGO SCREEN", 20, 20, 40, LIGHTGRAY )
         DrawText( "WAIT for 2 SECONDS...", 290, 220, 20, GRAY )
         EXIT

      CASE TITLE

         DrawRectangle( 0, 0, nScreenWidth, nScreenHeight, GREEN )
         DrawText( "TITLE SCREEN", 20, 20, 40, DARKGREEN )
         DrawText( "PRESS ENTER or TAP to JUMP to GAMEPLAY SCREEN", 120, 220, 20, DARKGREEN )
         EXIT

      CASE GAMEPLAY

         DrawRectangle( 0, 0, nScreenWidth, nScreenHeight, PURPLE )
         DrawText( "GAMEPLAY SCREEN", 20, 20, 40, MAROON )
         DrawText( "PRESS ENTER or TAP to JUMP to ENDING SCREEN", 130, 220, 20, MAROON )
         EXIT

      CASE ENDING

         DrawRectangle( 0, 0, nScreenWidth, nScreenHeight, BLUE )
         DrawText( "ENDING SCREEN", 20, 20, 40, DARKBLUE )
         DrawText( "PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, 220, 20, DARKBLUE )
         EXIT

      ENDSWITCH

      EndDrawing()

   ENDDO

   CloseWindow()

   RETURN
