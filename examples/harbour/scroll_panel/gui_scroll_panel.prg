#include "hbraylib.ch"
#include "hbraygui.ch"

#define RECTANGLE_X        1
#define RECTANGLE_Y        2
#define RECTANGLE_WIDTH    3
#define RECTANGLE_HEIGHT   4

#define VECTOR2_X   1
#define VECTOR2_Y   2

PROCEDURE Main()

   LOCAL nScreenWidth := 800
   LOCAL nScreenHeight := 450
   LOCAL aPanelRec := { 20, 40, 200, 150 }
   LOCAL aPanelContentRec := { 0, 0, 340, 340 }
   LOCAL aPanelScroll := { 99, - 20 }
   LOCAL lShowContentArea := .T.
   LOCAL aView

   InitWindow( nScreenWidth, nScreenHeight, "Harbour raygui - GuiScrollPanel()" )

   SetTargetFPS( 60 )

   DO WHILE ! WindowShouldClose()

      BeginDrawing()

      ClearBackground( RAYWHITE )

      DrawText( TextFormat( "[ %i, %i ]", aPanelScroll[ VECTOR2_X ], aPanelScroll[ VECTOR2_X ] ), 4, 4, 20, RED )

      aView := GuiScrollPanel( aPanelRec, aPanelContentRec, aPanelScroll )

      BeginScissorMode( Int( aView[ RECTANGLE_X ] ), Int( aView[ RECTANGLE_Y ] ), Int( aView[ RECTANGLE_WIDTH ] ), Int( aView[ RECTANGLE_HEIGHT ] ) )
      GuiGrid( { aPanelRec[ RECTANGLE_X ] + aPanelScroll[ VECTOR2_X ], aPanelRec[ RECTANGLE_Y ] + aPanelScroll[ VECTOR2_Y ], ;
         aPanelContentRec[ RECTANGLE_WIDTH ], aPanelContentRec[ RECTANGLE_HEIGHT ] }, 16, 3 )
      EndScissorMode()

      IF lShowContentArea

         DrawRectangle( Int( aPanelRec[ RECTANGLE_X ] + aPanelScroll[ VECTOR2_X ] ), Int( aPanelRec[ RECTANGLE_Y ] + aPanelScroll[ VECTOR2_Y ] ), ;
            Int( aPanelContentRec[ RECTANGLE_WIDTH ] ), Int( aPanelContentRec[ RECTANGLE_HEIGHT ] ), Fade( RED, 0.1 ) )
      ENDIF

      DrawStyleEditControls()

      lShowContentArea := GuiCheckBox( { 565, 80, 20, 20 }, "SHOW CONTENT AREA", lShowContentArea )

      aPanelContentRec[ RECTANGLE_WIDTH ] := GuiSliderBar( { 590, 385, 145, 15 }, "WIDTH", TextFormat( "%i", aPanelContentRec[ RECTANGLE_WIDTH ] ), aPanelContentRec[ RECTANGLE_WIDTH ], 1, 600 )
      aPanelContentRec[ RECTANGLE_HEIGHT ] := GuiSliderBar( { 590, 410, 145, 15 }, "HEIGHT", TextFormat( "%i", aPanelContentRec[ RECTANGLE_HEIGHT ] ), aPanelContentRec[ RECTANGLE_HEIGHT ], 1, 400 )

      EndDrawing()

   ENDDO

   CloseWindow()

   RETURN

STATIC PROCEDURE DrawStyleEditControls()

   LOCAL nStyle
   LOCAL lStyle
   LOCAL nText

   GuiGroupBox( { 550, 170, 220, 205 }, "SCROLLBAR STYLE" )

   nStyle := GuiGetStyle( SCROLLBAR, BORDER_WIDTH )
   GuiLabel( { 555, 195, 110, 10 }, "BORDER_WIDTH" )
   GuiSpinner( { 670, 190, 90, 20 }, "", nStyle, 0, 6, .F. )
   GuiSetStyle( SCROLLBAR, BORDER_WIDTH, nStyle )

   nStyle := GuiGetStyle( SCROLLBAR, ARROWS_SIZE )
   GuiLabel( { 555, 220, 110, 10 }, "ARROWS_SIZE" )
   GuiSpinner( { 670, 215, 90, 20 }, "", nStyle, 4, 14, .F. )
   GuiSetStyle( SCROLLBAR, ARROWS_SIZE, nStyle )

   nStyle := GuiGetStyle( SCROLLBAR, TEXT_INNER_PADDING )
   GuiLabel( { 555, 245, 110, 10 }, "TEXT_INNER_PADDING" )
   GuiSpinner( { 670, 240, 90, 20 }, "", nStyle, 0, 14, .F. )
   GuiSetStyle( SCROLLBAR, TEXT_INNER_PADDING, nStyle )

   lStyle := GuiCheckBox( { 565, 280, 20, 20 }, "ARROWS_VISIBLE", NToL( GuiGetStyle( SCROLLBAR, ARROWS_VISIBLE ) ) )
   GuiSetStyle( SCROLLBAR, ARROWS_VISIBLE, LToN( lStyle ) )

   nStyle := GuiGetStyle( SCROLLBAR, SLIDER_PADDING )
   GuiLabel( { 555, 325, 110, 10 }, "SLIDER_PADDING" )
   GuiSpinner( { 670, 320, 90, 20 }, "", nStyle, 0, 14, .F. )
   GuiSetStyle( SCROLLBAR, SLIDER_PADDING, nStyle )

   nStyle := GuiGetStyle( SCROLLBAR, SCROLL_SLIDER_SIZE )
   GuiLabel( { 555, 350, 110, 10 }, "SLIDER_SIZE" )
   GuiSpinner( { 670, 345, 90, 20 }, "", nStyle, 2, 100, .F. )
   GuiSetStyle( SCROLLBAR, SCROLL_SLIDER_SIZE, nStyle )

   nText := GuiGetStyle( LISTVIEW, SCROLLBAR_SIDE )
   nStyle := GuiToggle( { 560, 110, 200, 35 }, hb_ntos( nText ), NToL( GuiGetStyle( LISTVIEW, SCROLLBAR_SIDE ) ) )
   GuiSetStyle( LISTVIEW, SCROLLBAR_SIDE, LToN( nStyle ) )

   GuiGroupBox( { 550, 20, 220, 135 }, "SCROLLPANEL STYLE" )

   nStyle := GuiGetStyle( LISTVIEW, SCROLLBAR_WIDTH )
   GuiLabel( { 555, 35, 110, 10 }, "SCROLLBAR_WIDTH" )
   GuiSpinner( { 670, 30, 90, 20 }, "", nStyle, 6, 30, .F. )
   GuiSetStyle( LISTVIEW, SCROLLBAR_WIDTH, nStyle )

   nStyle := GuiGetStyle( DEFAULT, BORDER_WIDTH )
   GuiLabel( { 555, 60, 110, 10 }, "BORDER_WIDTH" )
   GuiSpinner( { 670, 55, 90, 20 }, "", nStyle, 0, 20, .F. )
   GuiSetStyle( DEFAULT, BORDER_WIDTH, nStyle )

   RETURN
