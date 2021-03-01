#include "hbraylib.ch"

#define RECTANGLE_X        1
#define RECTANGLE_Y        2
#define RECTANGLE_WIDTH    3
#define RECTANGLE_HEIGHT   4

PROCEDURE Main()

   LOCAL screenWidth := 800
   LOCAL screenHeight := 450
   LOCAL boxA, boxB
   LOCAL boxASpeedX
   LOCAL boxCollision := { 0 }
   LOCAL screenUpperLimit := 40
   LOCAL pause := .F.
   LOCAL collision

   InitWindow( screenWidth, screenHeight, "Harbour raylib [shapes] example - collision area" )

   boxA := { 10, GetScreenHeight() / 2 - 50, 200, 100 }
   boxASpeedX := 4

   boxB := { GetScreenWidth() / 2 - 30, GetScreenHeight() / 2 - 30, 60, 60 }

   SetTargetFPS( 60 )

   DO WHILE ! WindowShouldClose()

      IF ! pause
         boxA[ RECTANGLE_X ] += boxASpeedX
      ENDIF

      IF ( ( boxA[ RECTANGLE_X ] + boxA[ RECTANGLE_WIDTH ] ) >= GetScreenWidth() ) .OR. ( boxA[ RECTANGLE_X ] <= 0 )
         boxASpeedX *= -1
      ENDIF

      boxB[ RECTANGLE_X ] := GetMouseX() - boxB[ RECTANGLE_WIDTH ] / 2
      boxB[ RECTANGLE_Y ] := GetMouseY() - boxB[ RECTANGLE_HEIGHT ] / 2

      IF ( boxB[ RECTANGLE_X ] + boxB[ RECTANGLE_WIDTH ] ) >= GetScreenWidth()
         boxB[ RECTANGLE_X ] = GetScreenWidth() - boxB[ RECTANGLE_WIDTH ]
      ELSEIF boxB[ RECTANGLE_X ] <= 0
         boxB[ RECTANGLE_X ] = 0
      ENDIF

      IF ( boxB[ RECTANGLE_Y ] + boxB[ RECTANGLE_HEIGHT ] ) >= GetScreenHeight()
         boxB[ RECTANGLE_Y ] = GetScreenHeight() - boxB[ RECTANGLE_HEIGHT ]
      ELSEIF boxB[ RECTANGLE_Y ] <= screenUpperLimit
         boxB[ RECTANGLE_Y ] = screenUpperLimit
      ENDIF

      collision := CheckCollisionRecs( boxA, boxB )

      IF collision
         boxCollision := GetCollisionRec( boxA, boxB )
      ENDIF

      IF IsKeyPressed( KEY_SPACE )
         pause = ! pause
      ENDIF

      BeginDrawing()

      ClearBackground( RAYWHITE )

      DrawRectangle( 0, 0, screenWidth, screenUpperLimit, iif( collision, RED, BLACK ) )

      DrawRectangleRec( boxA, GOLD )
      DrawRectangleRec( boxB, BLUE )

      IF collision

         DrawRectangleRec( boxCollision, LIME )

         DrawText( "COLLISION!", Int( GetScreenWidth() / 2 ) - Int( MeasureText( "COLLISION!", 20 ) / 2 ), Int( screenUpperLimit / 2 ) - 10, 20, BLACK )

         DrawText( TextFormat( "Collision Area: %i", Int( boxCollision[ RECTANGLE_WIDTH ] ) * Int( boxCollision[ RECTANGLE_HEIGHT ] ) ), Int( GetScreenWidth() / 2 ) - 100, screenUpperLimit + 10, 20, BLACK )

      ENDIF

      DrawFPS( 10, 10 )

       EndDrawing()

   ENDDO

   CloseWindow()

   RETURN
