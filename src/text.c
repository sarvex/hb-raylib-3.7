/*
 * RayLib library: text.c
 * version 3.7
 *
 * Copyright 2021 Leonardo Mendez ( mlmgerencir at gmail com )
 * Copyright 2021 Maurizio la Cecilia ( m.lacecilia at gmail com )
 * Copyright 2020 - 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbraylib.h"

//------------------------------------------------------------------------------------
// Font Loading and Text Drawing Functions (Module: text)
//------------------------------------------------------------------------------------

// Font loading/unloading functions

// Font GetFontDefault(void);                                                            // Get the default Font
HB_FUNC( GETFONTDEFAULT )
{
   Font font = GetFontDefault();

   PHB_ITEM pFontArray = hb_itemArrayNew( 6 );

   hb_arraySetNI( pFontArray, 1, font.baseSize );
   hb_arraySetNI( pFontArray, 2, font.glyphCount );
   hb_arraySetNI( pFontArray, 3, font.glyphPadding );

      // Texture2D texture
      PHB_ITEM pSubarrayTexture2D = hb_arrayGetItemPtr( pFontArray, 4 );

      hb_arrayNew( pSubarrayTexture2D, 5 );
      hb_arraySetNI( pSubarrayTexture2D, 1, ( unsigned int ) font.texture.id );
      hb_arraySetNI( pSubarrayTexture2D, 2, font.texture.width );
      hb_arraySetNI( pSubarrayTexture2D, 3, font.texture.height );
      hb_arraySetNI( pSubarrayTexture2D, 4, font.texture.mipmaps );
      hb_arraySetNI( pSubarrayTexture2D, 5, font.texture.format );

   hb_arraySetPtr( pFontArray, 5, font.recs );
   hb_arraySetPtr( pFontArray, 6, font.glyphs );

   hb_itemReturnRelease( pFontArray );
}

// Font LoadFont(const char *fileName);                                                  // Load font from file into GPU memory (VRAM)
HB_FUNC( LOADFONT )
{
   if( hb_param( 1, HB_IT_STRING ) != NULL )
   {
      Font font = LoadFont( hb_parc( 1 ) );

      PHB_ITEM pFontArray = hb_itemArrayNew( 6 );

      hb_arraySetNI( pFontArray, 1, font.baseSize );
      hb_arraySetNI( pFontArray, 2, font.glyphCount );
      hb_arraySetNI( pFontArray, 3, font.glyphPadding );

         // Texture2D texture
         PHB_ITEM pSubarrayTexture2D = hb_arrayGetItemPtr( pFontArray, 4 );

         hb_arrayNew( pSubarrayTexture2D, 5 );
         hb_arraySetNI( pSubarrayTexture2D, 1, ( unsigned int ) font.texture.id );
         hb_arraySetNI( pSubarrayTexture2D, 2, font.texture.width );
         hb_arraySetNI( pSubarrayTexture2D, 3, font.texture.height );
         hb_arraySetNI( pSubarrayTexture2D, 4, font.texture.mipmaps );
         hb_arraySetNI( pSubarrayTexture2D, 5, font.texture.format );

      hb_arraySetPtr( pFontArray, 5, font.recs );
      hb_arraySetPtr( pFontArray, 6, font.glyphs );

      hb_itemReturnRelease( pFontArray );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// Font LoadFontEx(const char *fileName, int fontSize, int *fontChars, int charsCount);  // Load font from file with extended parameters
HB_FUNC( LOADFONTEX )
{
   if( hb_param( 1, HB_IT_STRING ) != NULL &&
       hb_param( 2, HB_IT_INTEGER ) != NULL &&
       hb_param( 3, HB_IT_INTEGER ) != NULL &&
       hb_param( 4, HB_IT_INTEGER ) != NULL )
   {
      Font font = LoadFontEx( hb_parc( 1 ), hb_parni( 2 ), ( int * ) hb_parptr( 3 ), hb_parni( 4 ) );

      PHB_ITEM pFontArray = hb_itemArrayNew( 6 );

      hb_arraySetNI( pFontArray, 1, font.baseSize );
      hb_arraySetNI( pFontArray, 2, font.glyphCount );
      hb_arraySetNI( pFontArray, 3, font.glyphPadding );

         // Texture2D texture
         PHB_ITEM pSubarrayTexture2D = hb_arrayGetItemPtr( pFontArray, 4 );

         hb_arrayNew( pSubarrayTexture2D, 5 );
         hb_arraySetNI( pSubarrayTexture2D, 1, ( unsigned int ) font.texture.id );
         hb_arraySetNI( pSubarrayTexture2D, 2, font.texture.width );
         hb_arraySetNI( pSubarrayTexture2D, 3, font.texture.height );
         hb_arraySetNI( pSubarrayTexture2D, 4, font.texture.mipmaps );
         hb_arraySetNI( pSubarrayTexture2D, 5, font.texture.format );

      hb_arraySetPtr( pFontArray, 5, font.recs );
      hb_arraySetPtr( pFontArray, 6, font.glyphs );

      hb_itemReturnRelease( pFontArray );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// Font LoadFontFromImage(Image image, Color key, int firstChar);                        // Load font from Image (XNA style)
HB_FUNC( LOADFONTFROMIMAGE )
{
   PHB_ITEM pItem1, pItem2;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 5 &&
       ( pItem2 = hb_param( 2, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 4 &&
                  hb_param( 3, HB_IT_INTEGER ) != NULL )
   {
      Image image;

      image.data    =  hb_arrayGetPtr( pItem1, 1 );
      image.width   =  hb_arrayGetNI( pItem1, 2 );
      image.height  =  hb_arrayGetNI( pItem1, 3 );
      image.mipmaps =  hb_arrayGetNI( pItem1, 4 );
      image.format  =  hb_arrayGetNI( pItem1, 5 );

      Color key;

      key.r = ( unsigned char ) hb_arrayGetNI( pItem2, 1 );
      key.g = ( unsigned char ) hb_arrayGetNI( pItem2, 2 );
      key.b = ( unsigned char ) hb_arrayGetNI( pItem2, 3 );
      key.a = ( unsigned char ) hb_arrayGetNI( pItem2, 4 );

      Font font = LoadFontFromImage( image, key, hb_parni( 3 ) );

      PHB_ITEM pFontArray = hb_itemArrayNew( 6 );

      hb_arraySetNI( pFontArray, 1, font.baseSize );
      hb_arraySetNI( pFontArray, 2, font.glyphCount );
      hb_arraySetNI( pFontArray, 3, font.glyphPadding );

         // Texture2D texture
         PHB_ITEM pSubarrayTexture2D = hb_arrayGetItemPtr( pFontArray, 4 );

         hb_arrayNew( pSubarrayTexture2D, 5 );
         hb_arraySetNI( pSubarrayTexture2D, 1, ( unsigned int ) font.texture.id );
         hb_arraySetNI( pSubarrayTexture2D, 2, font.texture.width );
         hb_arraySetNI( pSubarrayTexture2D, 3, font.texture.height );
         hb_arraySetNI( pSubarrayTexture2D, 4, font.texture.mipmaps );
         hb_arraySetNI( pSubarrayTexture2D, 5, font.texture.format );

      hb_arraySetPtr( pFontArray, 5, font.recs );
      hb_arraySetPtr( pFontArray, 6, font.glyphs );

      hb_itemReturnRelease( pFontArray );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// Font LoadFontFromMemory(const char *fileType, const unsigned char *fileData, int dataSize, int fontSize, int *fontChars, int charsCount); // Load font from memory buffer, fileType refers to extension: i.e. "ttf"
HB_FUNC( LoadFontFromMemory )
{
   if( hb_param( 1, HB_IT_STRING ) != NULL &&
       hb_param( 2, HB_IT_POINTER ) != NULL &&
       hb_param( 3, HB_IT_INTEGER ) != NULL &&
       hb_param( 4, HB_IT_INTEGER ) != NULL &&
       hb_param( 5, HB_IT_INTEGER ) != NULL &&
       hb_param( 6, HB_IT_INTEGER ) != NULL )
   {
      int fontChars;
      Font font = LoadFontFromMemory( hb_parc( 1 ), ( const unsigned char * ) hb_parptr( 2 ), hb_parni( 3 ), hb_parni( 4 ), &fontChars, hb_parni( 6 ) );
      hb_storni( fontChars, 5 );

      PHB_ITEM pFontArray = hb_itemArrayNew( 6 );

      hb_arraySetNI( pFontArray, 1, font.baseSize );
      hb_arraySetNI( pFontArray, 2, font.glyphCount );
      hb_arraySetNI( pFontArray, 3, font.glyphPadding );

         // Texture2D texture
         PHB_ITEM pSubarrayTexture2D = hb_arrayGetItemPtr( pFontArray, 4 );

         hb_arrayNew( pSubarrayTexture2D, 5 );
         hb_arraySetNI( pSubarrayTexture2D, 1, ( unsigned int ) font.texture.id );
         hb_arraySetNI( pSubarrayTexture2D, 2, font.texture.width );
         hb_arraySetNI( pSubarrayTexture2D, 3, font.texture.height );
         hb_arraySetNI( pSubarrayTexture2D, 4, font.texture.mipmaps );
         hb_arraySetNI( pSubarrayTexture2D, 5, font.texture.format );

      hb_arraySetPtr( pFontArray, 5, font.recs );
      hb_arraySetPtr( pFontArray, 6, font.glyphs );

      hb_itemReturnRelease( pFontArray );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// CharInfo *LoadFontData(const unsigned char *fileData, int dataSize, int fontSize, int *fontChars, int charsCount, int type);      // Load font data for further use
// Image GenImageFontAtlas(const CharInfo *chars, Rectangle **recs, int charsCount, int fontSize, int padding, int packMethod);      // Generate image font atlas using chars info
// void UnloadFontData(CharInfo *chars, int charsCount);                                 // Unload font chars info data (RAM)

// void UnloadFont(Font font);                                                           // Unload Font from GPU memory (VRAM)
HB_FUNC( UNLOADFONT )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 6 )
   {
      Font font;

      font.baseSize     = hb_arrayGetNI( pItem, 1 );
      font.glyphCount   = hb_arrayGetNI( pItem, 2 );
      font.glyphPadding = hb_arrayGetNI( pItem, 3 );

         // Texture2D texture
         PHB_ITEM pSubarrayTexture2D = hb_arrayGetItemPtr( pItem, 4 );

         font.texture.id      = ( unsigned int ) hb_arrayGetNI( pSubarrayTexture2D, 1 );
         font.texture.width   = hb_arrayGetNI( pSubarrayTexture2D, 2 );
         font.texture.height  = hb_arrayGetNI( pSubarrayTexture2D, 3 );
         font.texture.mipmaps = hb_arrayGetNI( pSubarrayTexture2D, 4 );
         font.texture.format  = hb_arrayGetNI( pSubarrayTexture2D, 5 );

      font.recs  = ( Rectangle * ) hb_arrayGetPtr( pItem, 5 );
      font.glyphs = ( GlyphInfo * ) hb_arrayGetPtr( pItem, 6 );

      UnloadFont( font );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// Text drawing functions
// void DrawFPS(int posX, int posY);                                                     // Shows current FPS
HB_FUNC( DRAWFPS )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL &&
       hb_param( 2, HB_IT_INTEGER ) != NULL )
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

   if( hb_param( 1, HB_IT_STRING )  != NULL &&
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
HB_FUNC( DRAWTEXTEX )
{
   PHB_ITEM pItem1, pItem2, pItem3;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 6 &&
                  hb_param( 2, HB_IT_STRING )  != NULL &&
       ( pItem2 = hb_param( 3, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 2 &&
                  hb_param( 4, HB_IT_NUMERIC ) != NULL &&
                  hb_param( 5, HB_IT_NUMERIC ) != NULL &&
       ( pItem3 = hb_param( 6, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem3 ) == 4 )
   {
      Font font;

      font.baseSize     = hb_arrayGetNI( pItem1, 1 );
      font.glyphCount   = hb_arrayGetNI( pItem1, 2 );
      font.glyphPadding = hb_arrayGetNI( pItem1, 3 );

         // Texture2D texture
         PHB_ITEM pSubarrayTexture2D = hb_arrayGetItemPtr( pItem1, 4 );

         font.texture.id      = ( unsigned int ) hb_arrayGetNI( pSubarrayTexture2D, 1 );
         font.texture.width   = hb_arrayGetNI( pSubarrayTexture2D, 2 );
         font.texture.height  = hb_arrayGetNI( pSubarrayTexture2D, 3 );
         font.texture.mipmaps = hb_arrayGetNI( pSubarrayTexture2D, 4 );
         font.texture.format  = hb_arrayGetNI( pSubarrayTexture2D, 5 );

      font.recs  = hb_arrayGetPtr( pItem1, 5 );
      font.glyphs = hb_arrayGetPtr( pItem1, 6 );

      Vector2 position;

      position.x = ( float ) hb_arrayGetND( pItem2, 1 );
      position.y = ( float ) hb_arrayGetND( pItem2, 2 );

      Color tint;

      tint.r = ( unsigned char ) hb_arrayGetNI( pItem3, 1 );
      tint.g = ( unsigned char ) hb_arrayGetNI( pItem3, 2 );
      tint.b = ( unsigned char ) hb_arrayGetNI( pItem3, 3 );
      tint.a = ( unsigned char ) hb_arrayGetNI( pItem3, 4 );

      DrawTextEx( font, hb_parc( 2 ), position, ( float ) hb_parnd( 4 ), ( float ) hb_parnd( 5 ), tint );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawTextPro(Font font, const char *text, Vector2 position, Vector2 origin, float rotation, float fontSize, float spacing, Color tint); // Draw text using Font and pro parameters (rotation)
HB_FUNC( DRAWTEXTPRO )
{
   PHB_ITEM pItem1, pItem2, pItem3, pItem4;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 6 &&
                  hb_param( 2, HB_IT_STRING )  != NULL &&
       ( pItem2 = hb_param( 3, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 2 &&
       ( pItem3 = hb_param( 4, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem3 ) == 2 &&
                  hb_param( 5, HB_IT_NUMERIC ) != NULL &&
                  hb_param( 6, HB_IT_NUMERIC ) != NULL &&
                  hb_param( 7, HB_IT_NUMERIC ) != NULL &&
       ( pItem4 = hb_param( 8, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem4 ) == 4 )
   {
      Font font;

      font.baseSize     = hb_arrayGetNI( pItem1, 1 );
      font.glyphCount   = hb_arrayGetNI( pItem1, 2 );
      font.glyphPadding = hb_arrayGetNI( pItem1, 3 );

         // Texture2D texture
         PHB_ITEM pSubarrayTexture2D = hb_arrayGetItemPtr( pItem1, 4 );

         font.texture.id      = ( unsigned int ) hb_arrayGetNI( pSubarrayTexture2D, 1 );
         font.texture.width   = hb_arrayGetNI( pSubarrayTexture2D, 2 );
         font.texture.height  = hb_arrayGetNI( pSubarrayTexture2D, 3 );
         font.texture.mipmaps = hb_arrayGetNI( pSubarrayTexture2D, 4 );
         font.texture.format  = hb_arrayGetNI( pSubarrayTexture2D, 5 );

      font.recs  = hb_arrayGetPtr( pItem1, 5 );
      font.glyphs = hb_arrayGetPtr( pItem1, 6 );

      Vector2 position;

      position.x = ( float ) hb_arrayGetND( pItem2, 1 );
      position.y = ( float ) hb_arrayGetND( pItem2, 2 );

      Vector2 origin;

      origin.x = ( float ) hb_arrayGetND( pItem3, 1 );
      origin.y = ( float ) hb_arrayGetND( pItem3, 2 );

      Color tint;

      tint.r = ( unsigned char ) hb_arrayGetNI( pItem4, 1 );
      tint.g = ( unsigned char ) hb_arrayGetNI( pItem4, 2 );
      tint.b = ( unsigned char ) hb_arrayGetNI( pItem4, 3 );
      tint.a = ( unsigned char ) hb_arrayGetNI( pItem4, 4 );

      DrawTextPro( font, hb_parc( 2 ), position, origin, ( float ) hb_parnd( 5 ), ( float ) hb_parnd( 6 ), ( float ) hb_parnd( 7 ), tint );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawTextCodepoint(Font font, int codepoint, Vector2 position, float fontSize, Color tint);   // Draw one character (codepoint)
HB_FUNC( DRAWTEXTCODEPOINT )
{
   PHB_ITEM pItem1, pItem2, pItem3;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 6 &&
                  hb_param( 2, HB_IT_INTEGER ) != NULL &&
       ( pItem2 = hb_param( 3, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 2 &&
                  hb_param( 4, HB_IT_NUMERIC ) != NULL &&
       ( pItem3 = hb_param( 5, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem3 ) == 4 )
   {
      Font font;

      font.baseSize     = hb_arrayGetNI( pItem1, 1 );
      font.glyphCount   = hb_arrayGetNI( pItem1, 2 );
      font.glyphPadding = hb_arrayGetNI( pItem1, 3 );

         // Texture2D texture
         PHB_ITEM pSubarrayTexture2D = hb_arrayGetItemPtr( pItem1, 4 );

         font.texture.id      = ( unsigned int ) hb_arrayGetNI( pSubarrayTexture2D, 1 );
         font.texture.width   = hb_arrayGetNI( pSubarrayTexture2D, 2 );
         font.texture.height  = hb_arrayGetNI( pSubarrayTexture2D, 3 );
         font.texture.mipmaps = hb_arrayGetNI( pSubarrayTexture2D, 4 );
         font.texture.format  = hb_arrayGetNI( pSubarrayTexture2D, 5 );

      font.recs  = hb_arrayGetPtr( pItem1, 5 );
      font.glyphs = hb_arrayGetPtr( pItem1, 6 );

      Vector2 position;

      position.x = ( float ) hb_arrayGetND( pItem2, 1 );
      position.y = ( float ) hb_arrayGetND( pItem2, 2 );

      Color tint;

      tint.r = ( unsigned char ) hb_arrayGetNI( pItem3, 1 );
      tint.g = ( unsigned char ) hb_arrayGetNI( pItem3, 2 );
      tint.b = ( unsigned char ) hb_arrayGetNI( pItem3, 3 );
      tint.a = ( unsigned char ) hb_arrayGetNI( pItem3, 4 );

      DrawTextCodepoint( font, hb_parni( 2 ), position, ( float ) hb_parnd( 4 ), tint );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// Text misc. functions
// int MeasureText(const char *text, int fontSize);                                      // Measure string width for default font
HB_FUNC( MEASURETEXT )
{
   if( hb_param( 1, HB_IT_STRING ) != NULL &&
       hb_param( 2, HB_IT_INTEGER ) != NULL )
   {
      hb_retni( MeasureText( hb_parc( 1 ), hb_parni( 2 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// Vector2 MeasureTextEx(Font font, const char *text, float fontSize, float spacing);    // Measure string size for Font
HB_FUNC( MEASURETEXTEX )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 6 &&
                 hb_param( 2, HB_IT_STRING )  != NULL &&
                 hb_param( 3, HB_IT_NUMERIC ) != NULL &&
                 hb_param( 4, HB_IT_NUMERIC ) != NULL )
   {
      Font font;

      font.baseSize     = hb_arrayGetNI( pItem, 1 );
      font.glyphCount   = hb_arrayGetNI( pItem, 2 );
      font.glyphPadding = hb_arrayGetNI( pItem, 3 );

         // Texture2D texture
         PHB_ITEM pSubarrayTexture2D = hb_arrayGetItemPtr( pItem, 4 );

         font.texture.id      = ( unsigned int ) hb_arrayGetNI( pSubarrayTexture2D, 1 );
         font.texture.width   = hb_arrayGetNI( pSubarrayTexture2D, 2 );
         font.texture.height  = hb_arrayGetNI( pSubarrayTexture2D, 3 );
         font.texture.mipmaps = hb_arrayGetNI( pSubarrayTexture2D, 4 );
         font.texture.format  = hb_arrayGetNI( pSubarrayTexture2D, 5 );

      font.recs  = hb_arrayGetPtr( pItem, 5 );
      font.glyphs = hb_arrayGetPtr( pItem, 6 );

      Vector2 vector2 = MeasureTextEx( font, hb_parc( 2 ), ( float ) hb_parnd( 3 ), ( float ) hb_parnd( 4 ) );

      PHB_ITEM pVector2Array = hb_itemArrayNew( 2 );

      hb_arraySetNI( pVector2Array, 1, ( float ) vector2.x );
      hb_arraySetNI( pVector2Array, 2, ( float ) vector2.y );

      hb_itemReturnRelease( pVector2Array );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// int GetGlyphIndex(Font font, int codepoint);                                          // Get index position for a unicode character on font
HB_FUNC( GETGLYPHINDEX )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 6 &&
                 hb_param( 2, HB_IT_INTEGER ) != NULL )
   {
      Font font;

      font.baseSize     = hb_arrayGetNI( pItem, 1 );
      font.glyphCount   = hb_arrayGetNI( pItem, 2 );
      font.glyphPadding = hb_arrayGetNI( pItem, 3 );

         // Texture2D texture
         PHB_ITEM pSubarrayTexture2D = hb_arrayGetItemPtr( pItem, 4 );

         font.texture.id      = ( unsigned int ) hb_arrayGetNI( pSubarrayTexture2D, 1 );
         font.texture.width   = hb_arrayGetNI( pSubarrayTexture2D, 2 );
         font.texture.height  = hb_arrayGetNI( pSubarrayTexture2D, 3 );
         font.texture.mipmaps = hb_arrayGetNI( pSubarrayTexture2D, 4 );
         font.texture.format  = hb_arrayGetNI( pSubarrayTexture2D, 5 );

      font.recs  = hb_arrayGetPtr( pItem, 5 );
      font.glyphs = hb_arrayGetPtr( pItem, 6 );

      GetGlyphIndex( font, hb_parni( 2 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// Text codepoints management functions (unicode characters)

// int *LoadCodepoints(const char *text, int *count);              // Load all codepoints from a UTF-8 text string, codepoints count returned by parameter
// void UnloadCodepoints(int *codepoints);                         // Unload codepoints data from memory
// int GetCodepointCount(const char *text);                       // Get total number of codepoints in a UTF-8 encoded string
// int GetCodepoint(const char *text, int *bytesProcessed);        // Get next codepoint in a UTF-8 encoded string, 0x3f('?') is returned on failure
// const char *CodepointToUTF8(int codepoint, int *byteSize);    // Encode one codepoint into UTF-8 byte array (array length returned as parameter)
// char *TextCodepointsToUTF8(int *codepoints, int length);        // Encode text as codepoints array into UTF-8 text string (WARNING: memory must be freed!)

// Text strings management functions (no utf8 strings, only byte chars)
// NOTE: Some strings allocate memory internally for returned strings, just be careful!
// int TextCopy(char *dst, const char *src);                                                               // Copy one string to another, returns bytes copied

// bool TextIsEqual(const char *text1, const char *text2);                                              // Check if two text string are equal
HB_FUNC( TEXTISEQUAL )
{
   if( hb_param( 1, HB_IT_STRING ) != NULL &&
       hb_param( 2, HB_IT_STRING ) != NULL )
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
   if( hb_param( 1, HB_IT_STRING ) != NULL )
   {
      hb_retc( TextFormat( hb_parc( 1 ), hb_parni( 2 ), hb_parni( 3 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

HB_FUNC( TEXTFORMATIF )
{
   if( hb_param( 1, HB_IT_STRING ) != NULL )
   {
      hb_retc( TextFormat( hb_parc( 1 ), hb_parni( 2 ), ( float ) hb_parnd( 3 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

HB_FUNC( TEXTFORMATII )
{
   if( hb_param( 1, HB_IT_STRING ) != NULL )
   {
      hb_retc( TextFormat( hb_parc( 1 ), hb_parni( 2 ), hb_parni( 3 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

HB_FUNC( TEXTFORMATSI )
{
   if( hb_param( 1, HB_IT_STRING ) != NULL )
   {
      hb_retc( TextFormat( hb_parc( 1 ), hb_parc( 2 ), hb_parni( 3 ) ) );
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
   if( hb_param( 1, HB_IT_STRING ) != NULL &&
       hb_param( 2, HB_IT_STRING ) != NULL )
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