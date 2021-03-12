#include "hbraylib.ch"

#define VECTOR2_X   1
#define VECTOR2_Y   2

PROCEDURE Main()

   LOCAL nScreenWidth := 800
   LOCAL nScreenHeight := 600
   LOCAL aMousePosition
   LOCAL aWindowPosition := { 500, 200 }
   LOCAL aPanOffset
   LOCAL lDragWindow := .F.
   LOCAL lExitWindow := .F.

   SetConfigFlags( FLAG_WINDOW_UNDECORATED )
   InitWindow( nScreenWidth, nScreenHeight, "Harbour raygui - portable window" )

   SetWindowPosition( aWindowPosition[ VECTOR2_X ], aWindowPosition[ VECTOR2_Y ] )

   SetTargetFPS( 60 )

   DO WHILE ! lExitWindow .AND. ! WindowShouldClose()

      aMousePosition := GetMousePosition()

      IF IsMouseButtonPressed( MOUSE_LEFT_BUTTON )

         IF CheckCollisionPointRec( aMousePosition, { 0.0, 0.0, nScreenWidth + 0.5, 20.0 } )
            lDragWindow := .T.
            aPanOffset := aMousePosition
         ENDIF
      ENDIF

      IF lDragWindow

         aWindowPosition[ VECTOR2_X ] += aMousePosition[ VECTOR2_X ] - aPanOffset[ VECTOR2_X ]
         aWindowPosition[ VECTOR2_Y ] += aMousePosition[ VECTOR2_Y ] - aPanOffset[ VECTOR2_Y ]

         IF IsMouseButtonReleased( MOUSE_LEFT_BUTTON )
            lDragWindow := .F.
         ENDIF

         SetWindowPosition( aWindowPosition[ VECTOR2_X ], aWindowPosition[ VECTOR2_Y ] )
      ENDIF

      BeginDrawing()

      ClearBackground( RAYWHITE )

      lExitWindow := GuiWindowBox( { 0.0, 0.0, nScreenWidth + 0.5, nScreenHeight + 0.5 }, "PORTABLE WINDOW" )

      DrawText( TextFormat( "Mouse Position: [ %i, %i ]",  aMousePosition[ VECTOR2_X ], aMousePosition[ VECTOR2_Y ] ), 10, 40, 10, DARKGRAY )

      EndDrawing()

   ENDDO

   CloseWindow()

   RETURN
