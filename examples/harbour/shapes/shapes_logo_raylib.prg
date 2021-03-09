#include "hbraylib.ch"

PROCEDURE Main()

   LOCAL nScreenWidth := 800
   LOCAL nScreenHeight := 450

   InitWindow( nScreenWidth, nScreenHeight, "Harbour raylib [shapes] example - raylib logo using shapes" )

   SetTargetFPS( 60 )

   DO WHILE ( ! WindowShouldClose() )

      BeginDrawing()

      ClearBackground( RAYWHITE )

      DrawRectangle( Int( nScreenWidth / 2 ) - 128, Int( nScreenHeight / 2 ) - 128, 256, 256, BLACK )
      DrawRectangle( Int( nScreenWidth / 2 ) - 112, Int( nScreenHeight / 2 ) - 112, 224, 224, RAYWHITE )
      DrawText( "raylib", Int( nScreenWidth / 2 ) - 44, Int( nScreenHeight / 2 ) + 48, 50, BLACK )

      DrawText( "this is NOT a texture!", 350, 370, 10, GRAY )

      EndDrawing()

   ENDDO

   CloseWindow()

   RETURN
