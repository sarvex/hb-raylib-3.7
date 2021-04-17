#include "hbraylib.ch"

PROCEDURE Main()

   LOCAL nScreenWidth := 800
   LOCAL nScreenHeight := 450
   LOCAL nCount := 0
   LOCAL aDroppedFiles
   LOCAL i

   InitWindow( nScreenWidth, nScreenHeight, "Harbour raylib [core] example - drop files" )

   SetTargetFPS( 60 )

   DO WHILE ! WindowShouldClose()

      IF IsFileDropped()
         aDroppedFiles := GetDroppedFiles( @nCount )
      ENDIF

      BeginDrawing()

      ClearBackground( RAYWHITE )

      IF nCount == 0
         DrawText( "Drop your files to this window!", 100, 40, 20, DARKGRAY )
      ELSE
         DrawText( "Dropped files:", 100, 40, 20, DARKGRAY )

         FOR i := 1 TO nCount
            IF i % 2 == 0
               DrawRectangle( 0, 85 + 40 * i, nScreenWidth, 40, Fade( LIGHTGRAY, 0.5 ) )
            ELSE
               DrawRectangle( 0, 85 + 40 * i, nScreenWidth, 40, Fade( LIGHTGRAY, 0.3 ) )
            ENDIF
            DrawText( aDroppedFiles[ i ], 120, 100 + 40 * i, 10, GRAY )
         NEXT

         DrawText( "Drop new files...", 100, 110 + 40 * nCount, 20, DARKGRAY )

      ENDIF

      EndDrawing()

   ENDDO

   ClearDroppedFiles()

   CloseWindow()

   RETURN
