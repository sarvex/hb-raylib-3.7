/*
 * RayLib library: text.c
 * version 3.5
 *
 * Copyright 2020 - 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbraylib.h"

//------------------------------------------------------------------------------------
// Font Loading and Text Drawing Functions (Module: text)
//------------------------------------------------------------------------------------

// Font loading/unloading functions
// Font GetFontDefault(void);                                                            // Get the default Font
// Font LoadFont(const char *fileName);                                                  // Load font from file into GPU memory (VRAM)
// Font LoadFontEx(const char *fileName, int fontSize, int *fontChars, int charsCount);  // Load font from file with extended parameters
// Font LoadFontFromImage(Image image, Color key, int firstChar);                        // Load font from Image (XNA style)
// Font LoadFontFromMemory(const char *fileType, const unsigned char *fileData, int dataSize, int fontSize, int *fontChars, int charsCount); // Load font from memory buffer, fileType refers to extension: i.e. "ttf"
// CharInfo *LoadFontData(const unsigned char *fileData, int dataSize, int fontSize, int *fontChars, int charsCount, int type);      // Load font data for further use
// Image GenImageFontAtlas(const CharInfo *chars, Rectangle **recs, int charsCount, int fontSize, int padding, int packMethod);      // Generate image font atlas using chars info
// void UnloadFontData(CharInfo *chars, int charsCount);                                 // Unload font chars info data (RAM)
// void UnloadFont(Font font);                                                           // Unload Font from GPU memory (VRAM)

// Text drawing functions
// void DrawFPS(int posX, int posY);                                                     // Shows current FPS
HB_FUNC( DRAWFPS )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL && hb_param( 2, HB_IT_INTEGER ) != NULL )
   {
      DrawFPS( hb_parni( 1 ), hb_parni( 2 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawText(const char *text, int posX, int posY, int fontSize, Color color);       // Draw text (using default font)
HB_FUNC( DRAWTEXT )
{
   PHB_ITEM pItem;

   if( hb_param( 1, HB_IT_STRING ) != NULL &&
      hb_param( 2, HB_IT_INTEGER ) != NULL &&
      hb_param( 3, HB_IT_INTEGER ) != NULL &&
      hb_param( 4, HB_IT_INTEGER ) != NULL &&
      ( pItem = hb_param( 5, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 4 )
   {

      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem, 4 );

      DrawText( hb_parc( 1 ), hb_parni( 2 ), hb_parni( 3 ), hb_parni( 4 ), color );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawTextEx(Font font, const char *text, Vector2 position, float fontSize, float spacing, Color tint);                // Draw text using font and additional parameters
// void DrawTextRec(Font font, const char *text, Rectangle rec, float fontSize, float spacing, bool wordWrap, Color tint);   // Draw text using font inside rectangle limits
// void DrawTextRecEx(Font font, const char *text, Rectangle rec, float fontSize, float spacing, bool wordWrap, Color tint, int selectStart, int selectLength, Color selectTint, Color selectBackTint);    // Draw text using font inside rectangle limits with support for text selection
// void DrawTextCodepoint(Font font, int codepoint, Vector2 position, float fontSize, Color tint);   // Draw one character (codepoint)

// Text misc. functions
// int MeasureText(const char *text, int fontSize);                                      // Measure string width for default font
HB_FUNC( MEASURETEXT )
{
   if( hb_param( 1, HB_IT_STRING ) != NULL && hb_param( 2, HB_IT_INTEGER ) != NULL )
   {
      hb_retni( MeasureText( hb_parc( 1 ), hb_parni( 2 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// Vector2 MeasureTextEx(Font font, const char *text, float fontSize, float spacing);    // Measure string size for Font
// int GetGlyphIndex(Font font, int codepoint);                                          // Get index position for a unicode character on font

// Text strings management functions (no utf8 strings, only byte chars)
// NOTE: Some strings allocate memory internally for returned strings, just be careful!

// int TextCopy(char *dst, const char *src);                                             // Copy one string to another, returns bytes copied

// bool TextIsEqual(const char *text1, const char *text2);                               // Check if two text string are equal
HB_FUNC( TEXTISEQUAL )
{
   if( hb_param( 1, HB_IT_STRING ) != NULL && hb_param( 2, HB_IT_STRING ) != NULL )
   {
      hb_retl( TextIsEqual( hb_parc( 1 ), hb_parc( 2 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// unsigned int TextLength(const char *text);                                            // Get text length, checks for '\0' ending
HB_FUNC( TEXTLENGTH )
{
   if( hb_param( 1, HB_IT_STRING ) != NULL )
   {
      hb_retni( ( unsigned int ) TextLength( hb_parc( 1 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// const char *TextFormat(const char *text, ...);                                        // Text formatting with variables (sprintf style)
HB_FUNC( TEXTFORMAT )
{
   if( hb_param( 1, HB_IT_STRING ) != NULL && hb_param( 2, HB_IT_INTEGER ) != NULL )
   {
      hb_retc( TextFormat( hb_parc( 1 ), hb_parni( 2 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// const char *TextSubtext(const char *text, int position, int length);                  // Get a piece of a text string
HB_FUNC( TEXTSUBTEXT )
{
   if( hb_param( 1, HB_IT_STRING ) != NULL && hb_param( 2, HB_IT_INTEGER ) != NULL && hb_param( 2, HB_IT_INTEGER ) != NULL )
   {
      hb_retc( TextSubtext( hb_parc( 1 ), hb_parni( 2 ), hb_parni( 3 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// char *TextReplace(char *text, const char *replace, const char *by);                   // Replace text string (memory must be freed!)
// char *TextInsert(const char *text, const char *insert, int position);                 // Insert text in a position (memory must be freed!)
// const char *TextJoin(const char **textList, int count, const char *delimiter);        // Join text strings with delimiter
// const char **TextSplit(const char *text, char delimiter, int *count);                 // Split text into multiple strings
// void TextAppend(char *text, const char *append, int *position);                       // Append text at specific position and move cursor!

// int TextFindIndex(const char *text, const char *find);                                // Find first text occurrence within a string
HB_FUNC( TEXTFINDINDEX )
{
   if( hb_param( 1, HB_IT_STRING ) != NULL && hb_param( 2, HB_IT_STRING ) != NULL )
   {
      hb_retni( TextFindIndex( hb_parc( 1 ), hb_parc( 2 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// const char *TextToUpper(const char *text);                      // Get upper case version of provided string
HB_FUNC( TEXTTOUPPER )
{
   if( hb_param( 1, HB_IT_STRING ) != NULL )
   {
      hb_retc( TextToUpper( hb_parc( 1 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// const char *TextToLower(const char *text);                      // Get lower case version of provided string
HB_FUNC( TEXTTOLOWER )
{
   if( hb_param( 1, HB_IT_STRING ) != NULL )
   {
      hb_retc( TextToLower( hb_parc( 1 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// const char *TextToPascal(const char *text);                     // Get Pascal case notation version of provided string
HB_FUNC( TEXTTOPASCAL )
{
   if( hb_param( 1, HB_IT_STRING ) != NULL )
   {
      hb_retc( TextToPascal( hb_parc( 1 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// int TextToInteger(const char *text);                            // Get integer value from text (negative values not supported)
HB_FUNC( TEXTTOINTEGER )
{
   if( hb_param( 1, HB_IT_STRING ) != NULL )
   {
      hb_retni( TextToInteger( hb_parc( 1 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// char *TextToUtf8(int *codepoints, int length);                  // Encode text codepoint into utf8 text (memory must be freed!)

// UTF8 text strings management functions

// int *GetCodepoints(const char *text, int *count);               // Get all codepoints in a string, codepoints count returned by parameters

// int GetCodepointsCount(const char *text);                       // Get total number of characters (codepoints) in a UTF8 encoded string
HB_FUNC( GETCODEPOINTSCOUNT )
{
   if( hb_param( 1, HB_IT_STRING ) != NULL )
   {
      hb_retni( GetCodepointsCount( hb_parc( 1 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// int GetNextCodepoint(const char *text, int *bytesProcessed);    // Returns next codepoint in a UTF8 encoded string; 0x3f('?') is returned on failure
HB_FUNC( GETNEXTCODEPOINT )
{
   if( hb_param( 1, HB_IT_STRING ) != NULL && hb_param( 2, HB_IT_INTEGER ) != NULL )
   {
      int bytesProcessed;
      hb_retni( GetNextCodepoint( hb_parc( 1 ), &bytesProcessed ) );
      hb_storni( bytesProcessed, 2 );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// const char *CodepointToUtf8(int codepoint, int *byteLength);    // Encode codepoint into utf8 text (char array length returned as parameter)
HB_FUNC( CODEPOINTTOUTF8 )
{
   if( hb_param( 1, HB_IT_STRING ) != NULL && hb_param( 2, HB_IT_INTEGER ) != NULL )
   {
      int byteLength;
      hb_retc( CodepointToUtf8( hb_parni( 1 ), &byteLength ) );
      hb_storni( byteLength, 2 );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}
