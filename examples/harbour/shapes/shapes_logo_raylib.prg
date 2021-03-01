#include "hbraylib.ch"

PROCEDURE Main()

   LOCAL screenWidth := 800
   LOCAL screenHeight := 450

   InitWindow( screenWidth, screenHeight, "Harbour raylib [shapes] example - raylib logo using shapes" )

   SetTargetFPS( 60 )

   DO WHILE ( ! WindowShouldClose() )

      BeginDrawing()

      ClearBackground( RAYWHITE )

      DrawRectangle( Int( screenWidth / 2 ) - 128, Int( screenHeight / 2 ) - 128, 256, 256, BLACK )
      DrawRectangle( Int( screenWidth / 2 ) - 112, Int( screenHeight / 2 ) - 112, 224, 224, RAYWHITE )
      DrawText( "raylib", Int( screenWidth / 2 ) - 44, Int( screenHeight / 2 ) + 48, 50, BLACK )

      DrawText( "this is NOT a texture!", 350, 370, 10, GRAY )

      EndDrawing()

   ENDDO

   CloseWindow()

   RETURN
