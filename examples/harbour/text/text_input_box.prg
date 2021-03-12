#include "hbraylib.ch"

#define MAX_INPUT_CHARS 9

#define RECTANGLE_X        1
#define RECTANGLE_Y        2
#define RECTANGLE_WIDTH    3
#define RECTANGLE_HEIGHT   4

PROCEDURE Main()

   LOCAL nScreenWidth := 800
   LOCAL nScreenHeight := 450
   LOCAL cName := ""
   LOCAL nLetterCount := 0
   LOCAL aTextBox := { nScreenWidth / 2 - 100, 180, 225, 50 }
   LOCAL lMouseOnText
   LOCAL nFramesCounter := 0
   LOCAL nKey

   InitWindow( nScreenWidth, nScreenHeight, "Harbour raylib [text] example - input box" )

   SetTargetFPS( 10 )

   DO WHILE ! WindowShouldClose()

      IF CheckCollisionPointRec( GetMousePosition(), aTextBox )
         lMouseOnText := .T.
      ELSE
         lMouseOnText := .F.
      ENDIF

      IF lMouseOnText
         SetMouseCursor( MOUSE_CURSOR_IBEAM )
         nKey := GetCharPressed()
         WHILE nKey > 0
            IF nKey >= 32 .AND. nKey <= 125 .AND. nLetterCount < MAX_INPUT_CHARS
               cName += Chr( nKey )
               nLetterCount++
            ENDIF
            nKey := GetCharPressed()
         ENDDO
         IF IsKeyPressed( KEY_BACKSPACE )
            nLetterCount--
            cName := SubStr( cName, 1, nLetterCount )
            IF nLetterCount < 0
               nLetterCount := 0
            ENDIF
         ENDIF
      ELSE
         IF GetMouseCursor() != MOUSE_CURSOR_DEFAULT
            SetMouseCursor( MOUSE_CURSOR_DEFAULT )
         ENDIF
      ENDIF

      IF lMouseOnText
         nFramesCounter++
      ELSE
         nFramesCounter := 0
      ENDIF

      BeginDrawing()

      ClearBackground( RAYWHITE )

      DrawText( "PLACE MOUSE OVER INPUT BOX!", 240, 140, 20, GRAY )

      DrawRectangleRec( aTextBox, LIGHTGRAY )

      IF lMouseOnText
         DrawRectangleLines( Int( aTextBox[ RECTANGLE_X ] ), Int( aTextBox[ RECTANGLE_Y ] ), Int( aTextBox[ RECTANGLE_WIDTH ] ), Int( aTextBox[ RECTANGLE_HEIGHT ] ), RED )
      ELSE
         DrawRectangleLines( Int( aTextBox[ RECTANGLE_X ] ), Int( aTextBox[ RECTANGLE_Y ] ), Int( aTextBox[ RECTANGLE_WIDTH ] ), Int( aTextBox[ RECTANGLE_HEIGHT ] ), DARKGRAY )
      ENDIF

      DrawText( cName, Int( aTextBox[ RECTANGLE_X ] ) + 5, Int( aTextBox[ RECTANGLE_Y ] ) + 8, 40, MAROON )

      DrawText( TextFormat( "INPUT CHARS: %i/%i", nLetterCount, MAX_INPUT_CHARS ), 315, 250, 20, DARKGRAY )

      IF lMouseOnText
         IF nLetterCount < MAX_INPUT_CHARS
            IF ( nFramesCounter / 20 ) % 2 == 0
               DrawText( "_", Int( aTextBox[ RECTANGLE_X ] ) + 8 + MeasureText( cName, 40 ), Int( aTextBox[ RECTANGLE_Y ] ) + 12, 40, MAROON )
            ENDIF
         ELSE
            DrawText( "Press BACKSPACE to delete chars...", 230, 300, 20, GRAY )
         ENDIF
      ENDIF
      EndDrawing()
   ENDDO
   CloseWindow()

   RETURN
