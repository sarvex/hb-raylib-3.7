#include "hbraylib.ch"

#define FONT_BASESIZE   1

PROCEDURE Main()

   LOCAL nScreenWidth := 800
   LOCAL nScreenHeight := 450
   LOCAL cMsg := e"!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_\n`abcdefghijklmnopqrstuvwxyz{|}~⌂ÇüéâäàąçêëèïîćÄĄĘęłôöĆûùŚÖÜ¢Ł¥śƒ\nŹŻóÓńŃźż¿⌐¬½¼¡«»░▒▓│┤╡╢╖╕╣║╗╝╜╛┐└┴┬├─┼╞╟╚╔╩╦╠═╬╧╨╤╥╙╘╒╓╫╪┘┌█▄▌▐▀\nαßΓπΣσµτΦΘΩδ∞φε∩≡±≥≤⌠⌡÷≈°∙·√ⁿ²■"
   LOCAL aFontBm
   LOCAL aFontTtf
   LOCAL lUseTtf

   InitWindow( nScreenWidth, nScreenHeight, "Harbour raylib [text] example - font loading" )

   aFontBm := LoadFont( "resources/pixantiqua.fnt" )

   aFontTtf := LoadFontEx( "resources/pixantiqua.ttf", 32, 0, 250 )

   SetTargetFPS( 60 )

   DO WHILE ! WindowShouldClose()

      IF IsKeyDown( KEY_SPACE )
         lUseTtf := .T.
      ELSE
         lUseTtf := .F.
      ENDIF

      BeginDrawing()

      ClearBackground( RAYWHITE )

      DrawText( "Hold SPACE to use TTF generated font", 20, 20, 20, LIGHTGRAY )

      IF ! lUseTtf
         DrawTextEx( aFontBm, cMsg, { 20.0, 100.0 }, aFontBm[ FONT_BASESIZE ], 2, MAROON )
         DrawText( "Using BMFont (Angelcode) imported", 20, GetScreenHeight() - 30, 20, GRAY )
      ELSE
         DrawTextEx( aFontTtf, cMsg, { 20.0, 100.0 }, aFontTtf[ FONT_BASESIZE ], 2, LIME )
         DrawText( "Using TTF font generated", 20, GetScreenHeight() - 30, 20, GRAY )
      ENDIF

      EndDrawing()

   ENDDO

   UnloadFont( aFontBm )
   UnloadFont( aFontTtf )

   CloseWindow()

   RETURN
