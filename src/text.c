/*
 * RayLib library: text.c
 *
 * Copyright 2020 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbraylib.h"

/* --- Font loading/unloading functions --- */
// Font GetFontDefault( void );

// Font LoadFont( const char *fileName );

// Font LoadFontEx( const char *fileName, int fontSize, int *fontChars, int charsCount );
// Font LoadFontFromImage( Image image, Color key, int firstChar );
// CharInfo *LoadFontData( const char *fileName, int fontSize, int *fontChars, int charsCount, int type );
// Image GenImageFontAtlas( const CharInfo *chars, Rectangle **recs, int charsCount, int fontSize, int padding, int packMethod );
// void UnloadFont( Font font );

/* --- Text drawing functions --- */
// void DrawFPS( int posX, int posY );
HB_FUNC( DRAWFPS )
{
   if( hb_param( 1, HB_IT_STRING ) != NULL && hb_param( 2, HB_IT_STRING ) != NULL )
   {
      DrawFPS( hb_parni( 1 ), hb_parni( 2 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawText( const char *text, int posX, int posY, int fontSize, Color color );
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

// void DrawTextEx( Font font, const char *text, Vector2 position, float fontSize, float spacing, Color tint );
HB_FUNC( DRAWTEXTEX )
{
   PHB_ITEM pItem1, pItem2, pItem3;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 5 &&
      hb_param( 2, HB_IT_STRING ) != NULL &&
      ( pItem2 = hb_param( 3, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 2 &&
      hb_param( 4, HB_IT_INTEGER ) != NULL &&
      hb_param( 5, HB_IT_INTEGER ) != NULL &&
      ( pItem3 = hb_param( 6, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem3 ) == 4 )
   {

      Font font;

      font.baseSize   = hb_arrayGetNI( pItem1, 1 );
      font.charsCount = hb_arrayGetNI( pItem1, 2 );
      font.texture    = hb_arrayGetTD( pItem1, 3 );
      font.recs       = hb_arrayGetPtr( pItem1, 4 );
      font.chars      = hb_arrayGetPtr( pItem1, 5 );

      Vector2 position;

      position.x = hb_arrayGetNI( pItem2, 1 );
      position.y = hb_arrayGetNI( pItem2, 2 );

      Color tint;

      tint.r = ( unsigned char ) hb_arrayGetNI( pItem3, 1 );
      tint.g = ( unsigned char ) hb_arrayGetNI( pItem3, 2 );
      tint.b = ( unsigned char ) hb_arrayGetNI( pItem3, 3 );
      tint.a = ( unsigned char ) hb_arrayGetNI( pItem3, 4 );

      DrawTextEx( font, hb_parc( 2 ), position, hb_parni( 4 ), hb_parni( 5 ), tint );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawTextRec( Font font, const char *text, Rectangle rec, float fontSize, float spacing, bool wordWrap, Color tint );
// void DrawTextRecEx( Font font, const char *text, Rectangle rec, float fontSize, float spacing, bool wordWrap, Color tint, int selectStart, int selectLength, Color selectTint, Color selectBackTint );
// void DrawTextCodepoint( Font font, int codepoint, Vector2 position, float scale, Color tint );

/* --- Text misc. functions --- */
// int MeasureText( const char *text, int fontSize );
// Vector2 MeasureTextEx( Font font, const char *text, float fontSize, float spacing );
// int GetGlyphIndex( Font font, int codepoint );

/* --- Text strings management functions( no utf8 strings, only byte chars ) --- */
/* --- NOTE: Some strings allocate memory internally for returned strings, just be careful! --- */
// int TextCopy( char *dst, const char *src );
// bool TextIsEqual( const char *text1, const char *text2 );
// unsigned int TextLength( const char *text );
// const char *TextFormat( const char *text, ... );
// const char *TextSubtext( const char *text, int position, int length );
// char *TextReplace( char *text, const char *replace, const char *by );
// char *TextInsert( const char *text, const char *insert, int position );
// const char *TextJoin( const char **textList, int count, const char *delimiter );
// const char **TextSplit( const char *text, char delimiter, int *count );
// void TextAppend( char *text, const char *append, int *position );
// int TextFindIndex( const char *text, const char *find );
// const char *TextToUpper( const char *text );
// const char *TextToLower( const char *text );
// const char *TextToPascal( const char *text );
// int TextToInteger( const char *text );
// char *TextToUtf8( int *codepoints, int length );

/* --- UTF8 text strings management functions --- */
// int *GetCodepoints( const char *text, int *count );
// int GetCodepointsCount( const char *text );
// int GetNextCodepoint( const char *text, int *bytesProcessed );
// const char *CodepointToUtf8( int codepoint, int *byteLength );
