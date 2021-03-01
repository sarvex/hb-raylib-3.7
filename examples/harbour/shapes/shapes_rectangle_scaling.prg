#include "hbraylib.ch"

#define MOUSE_SCALE_MARK_SIZE   12

#define RECTANGLE_X        1
#define RECTANGLE_Y        2
#define RECTANGLE_WIDTH    3
#define RECTANGLE_HEIGHT   4

#define VECTOR2_X   1
#define VECTOR2_Y   2

PROCEDURE Main()

   LOCAL screenWidth := 800
   LOCAL screenHeight := 450
   LOCAL rec := { 100, 100, 200, 80 }
   LOCAL mouseScaleReady
   LOCAL mouseScaleMode := .F.
   LOCAL mousePosition

   InitWindow( screenWidth, screenHeight, "Harbour raylib [shapes] example - rectangle scaling mouse" )

   SetTargetFPS( 60 )

   DO WHILE ! WindowShouldClose()

      mousePosition := GetMousePosition()

      IF CheckCollisionPointRec( mousePosition, rec ) .AND. ;
         CheckCollisionPointRec( mousePosition, { rec[ RECTANGLE_X ] + rec[ RECTANGLE_WIDTH ] - MOUSE_SCALE_MARK_SIZE, ;
                                                rec[ RECTANGLE_Y ] + rec[ RECTANGLE_HEIGHT ] - MOUSE_SCALE_MARK_SIZE, ;
                                                MOUSE_SCALE_MARK_SIZE, MOUSE_SCALE_MARK_SIZE } )
         mouseScaleReady := .T.

         IF IsMouseButtonPressed( MOUSE_LEFT_BUTTON )
            mouseScaleMode := .T.
         ENDIF

      ELSE
         mouseScaleReady := .F.
      ENDIF

      IF mouseScaleMode

         mouseScaleReady := .T.

         rec[ RECTANGLE_WIDTH ] := mousePosition[ VECTOR2_X ] - rec[ RECTANGLE_X ]
         rec[ RECTANGLE_HEIGHT ] := mousePosition[ VECTOR2_Y ] - rec[ RECTANGLE_Y ]

         IF rec[ RECTANGLE_WIDTH ] < MOUSE_SCALE_MARK_SIZE
            rec[ RECTANGLE_WIDTH ] := MOUSE_SCALE_MARK_SIZE
         ENDIF

         IF rec[ RECTANGLE_HEIGHT ] < MOUSE_SCALE_MARK_SIZE
            rec[ RECTANGLE_HEIGHT ] := MOUSE_SCALE_MARK_SIZE
         ENDIF

         if IsMouseButtonReleased( MOUSE_LEFT_BUTTON )
            mouseScaleMode := .F.
         ENDIF
      ENDIF

      BeginDrawing()

      ClearBackground( RAYWHITE )

      DrawText( "Scale rectangle dragging from bottom-right corner!", 10, 10, 20, GRAY )

      DrawRectangleRec( rec, Fade( GREEN, 0.5 ) )

      if mouseScaleReady

         DrawRectangleLinesEx( rec, 1, RED )

         DrawTriangle( { rec[ RECTANGLE_X ] + rec[ RECTANGLE_WIDTH ] - MOUSE_SCALE_MARK_SIZE, rec[ RECTANGLE_Y ] + rec[ RECTANGLE_HEIGHT ] },;
                       { rec[ RECTANGLE_X ] + rec[ RECTANGLE_WIDTH ], rec[ RECTANGLE_Y ] + rec[ RECTANGLE_HEIGHT ] },;
                       { rec[ RECTANGLE_X ] + rec[ RECTANGLE_WIDTH ], rec[ RECTANGLE_Y ] + rec[ RECTANGLE_HEIGHT ] - MOUSE_SCALE_MARK_SIZE }, RED )
      ENDIF

      EndDrawing()

   ENDDO

    CloseWindow()

   RETURN
