/*
 * RayLib library: textures.c
 * version 3.5
 *
 * Copyright 2020 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbraylib.h"

//------------------------------------------------------------------------------------
// Texture Loading and Drawing Functions (Module: textures)
//------------------------------------------------------------------------------------

// Image loading functions
// NOTE: This functions do not require GPU access

// Image LoadImage(const char *fileName);                                                             // Load image from file into CPU memory (RAM)
HB_FUNC( LOADIMAGE )
{
   if( hb_param( 1, HB_IT_STRING ) != NULL )
   {
      Image image = LoadImage( hb_parc( 1 ) );

      PHB_ITEM info = hb_itemArrayNew( 5 );

      hb_arraySetPtr( info, 1, image.data );
      hb_arraySetNI( info, 2, image.width );
      hb_arraySetNI( info, 3, image.height );
      hb_arraySetNI( info, 4, image.mipmaps );
      hb_arraySetNI( info, 5, image.format );

      hb_itemReturnRelease( info );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// Image LoadImageRaw(const char *fileName, int width, int height, int format, int headerSize);       // Load image from RAW file data
HB_FUNC( LOADIMAGERAW )
{
   if( hb_param( 1, HB_IT_STRING ) != NULL &&
      hb_param( 2, HB_IT_INTEGER ) != NULL &&
      hb_param( 3, HB_IT_INTEGER ) != NULL &&
      hb_param( 4, HB_IT_INTEGER ) != NULL &&
      hb_param( 5, HB_IT_INTEGER ) != NULL )
   {
      Image image = LoadImageRaw( hb_parc( 1 ), hb_parni( 2 ), hb_parni( 3 ), hb_parni( 4 ), hb_parni( 5 ) );

      PHB_ITEM info = hb_itemArrayNew( 5 );

      hb_arraySetPtr( info, 1, image.data );
      hb_arraySetNI( info, 2, image.width );
      hb_arraySetNI( info, 3, image.height );
      hb_arraySetNI( info, 4, image.mipmaps );
      hb_arraySetNI( info, 5, image.format );

      hb_itemReturnRelease( info );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// Image LoadImageAnim(const char *fileName, int *frames);                                            // Load image sequence from file (frames appended to image.data)
HB_FUNC( LOADIMAGEANIM )
{
   if( hb_param( 1, HB_IT_STRING ) != NULL &&
      hb_param( 2, HB_IT_INTEGER ) != NULL )
   {
      int frames = hb_parni( 2 );
      Image image = LoadImageAnim( hb_parc( 1 ), &frames );

      PHB_ITEM info = hb_itemArrayNew( 5 );

      hb_arraySetPtr( info, 1, image.data );
      hb_arraySetNI( info, 2, image.width );
      hb_arraySetNI( info, 3, image.height );
      hb_arraySetNI( info, 4, image.mipmaps );
      hb_arraySetNI( info, 5, image.format );

      hb_itemReturnRelease( info );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// Image LoadImageFromMemory(const char *fileType, const unsigned char *fileData, int dataSize);      // Load image from memory buffer, fileType refers to extension: i.e. "png"
HB_FUNC( LOADIMAGEFROMMEMORY )
{
   if( hb_param( 1, HB_IT_STRING ) != NULL &&
       hb_param( 2, HB_IT_INTEGER ) != NULL &&
       hb_param( 3, HB_IT_INTEGER ) != NULL )
   {
      const unsigned char fileData = ( const unsigned char ) hb_parni( 2 );
      Image image = LoadImageFromMemory( hb_parc( 1 ), &fileData, hb_parni( 3 ) );

      PHB_ITEM info = hb_itemArrayNew( 5 );

      hb_arraySetPtr( info, 1, image.data );
      hb_arraySetNI( info, 2, image.width );
      hb_arraySetNI( info, 3, image.height );
      hb_arraySetNI( info, 4, image.mipmaps );
      hb_arraySetNI( info, 5, image.format );

      hb_itemReturnRelease( info );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void UnloadImage(Image image);                                                                     // Unload image from CPU memory (RAM)
HB_FUNC( UNLOADIMAGE )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 5 )
   {
      Image image;

      image.data    =  hb_arrayGetPtr( pItem, 1 );
      image.width   =  hb_arrayGetNI( pItem, 2 );
      image.height  =  hb_arrayGetNI( pItem, 3 );
      image.mipmaps =  hb_arrayGetNI( pItem, 4 );
      image.format  =  hb_arrayGetNI( pItem, 5 );

      UnloadImage( image );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// bool ExportImage(Image image, const char *fileName);                                               // Export image data to file, returns true on success
HB_FUNC( EXPORTIMAGE )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 5 && hb_param( 2, HB_IT_STRING ) != NULL )
   {
      Image image;

      image.data    =  hb_arrayGetPtr( pItem, 1 );
      image.width   =  hb_arrayGetNI( pItem, 2 );
      image.height  =  hb_arrayGetNI( pItem, 3 );
      image.mipmaps =  hb_arrayGetNI( pItem, 4 );
      image.format  =  hb_arrayGetNI( pItem, 5 );

      hb_retl( ExportImage( image, hb_parc( 2 ) ) );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// bool ExportImageAsCode(Image image, const char *fileName);                                         // Export image as code file defining an array of bytes, returns true on success
HB_FUNC( EXPORTIMAGEASCODE )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 5 && hb_param( 2, HB_IT_STRING ) != NULL )
   {
      Image image;

      image.data    =  hb_arrayGetPtr( pItem, 1 );
      image.width   =  hb_arrayGetNI( pItem, 2 );
      image.height  =  hb_arrayGetNI( pItem, 3 );
      image.mipmaps =  hb_arrayGetNI( pItem, 4 );
      image.format  =  hb_arrayGetNI( pItem, 5 );

      hb_retl( ExportImageAsCode( image, hb_parc( 2 ) ) );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// Image generation functions

// Image GenImageColor(int width, int height, Color color);                                           // Generate image: plain color
HB_FUNC( GENIMAGECOLOR )
{
   PHB_ITEM pItem;

   if( hb_param( 1, HB_IT_INTEGER ) != NULL &&
       hb_param( 2, HB_IT_INTEGER ) != NULL &&
       ( pItem = hb_param( 3, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 4 )
   {
      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem, 4 );

      Image image = GenImageColor( hb_parni( 1 ), hb_parni( 2 ), color );

      PHB_ITEM info = hb_itemArrayNew( 5 );

      hb_arraySetPtr( info, 1, image.data );
      hb_arraySetNI( info, 2, image.width );
      hb_arraySetNI( info, 3, image.height );
      hb_arraySetNI( info, 4, image.mipmaps );
      hb_arraySetNI( info, 5, image.format );

      hb_itemReturnRelease( info );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// Image GenImageGradientV(int width, int height, Color top, Color bottom);                           // Generate image: vertical gradient
HB_FUNC( GENIMAGEGRADIENTV )
{
   PHB_ITEM pItem1, pItem2;

   if( hb_param( 1, HB_IT_INTEGER ) != NULL &&
       hb_param( 2, HB_IT_INTEGER ) != NULL &&
       ( pItem1 = hb_param( 3, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 4 &&
       ( pItem2 = hb_param( 4, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 4 )
   {
      Color top;

      top.r = ( unsigned char ) hb_arrayGetNI( pItem1, 1 );
      top.g = ( unsigned char ) hb_arrayGetNI( pItem1, 2 );
      top.b = ( unsigned char ) hb_arrayGetNI( pItem1, 3 );
      top.a = ( unsigned char ) hb_arrayGetNI( pItem1, 4 );

      Color bottom;

      bottom.r = ( unsigned char ) hb_arrayGetNI( pItem2, 1 );
      bottom.g = ( unsigned char ) hb_arrayGetNI( pItem2, 2 );
      bottom.b = ( unsigned char ) hb_arrayGetNI( pItem2, 3 );
      bottom.a = ( unsigned char ) hb_arrayGetNI( pItem2, 4 );

      Image image = GenImageGradientV( hb_parni( 1 ), hb_parni( 2 ), top, bottom );

      PHB_ITEM info = hb_itemArrayNew( 5 );

      hb_arraySetPtr( info, 1, image.data );
      hb_arraySetNI( info, 2, image.width );
      hb_arraySetNI( info, 3, image.height );
      hb_arraySetNI( info, 4, image.mipmaps );
      hb_arraySetNI( info, 5, image.format );

      hb_itemReturnRelease( info );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// Image GenImageGradientH(int width, int height, Color left, Color right);                           // Generate image: horizontal gradient
HB_FUNC( GENIMAGEGRADIENTH )
{
   PHB_ITEM pItem1, pItem2;

   if( hb_param( 1, HB_IT_INTEGER ) != NULL &&
       hb_param( 2, HB_IT_INTEGER ) != NULL &&
       ( pItem1 = hb_param( 3, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 4 &&
       ( pItem2 = hb_param( 4, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 4 )
   {
      Color left;

      left.r = ( unsigned char ) hb_arrayGetNI( pItem1, 1 );
      left.g = ( unsigned char ) hb_arrayGetNI( pItem1, 2 );
      left.b = ( unsigned char ) hb_arrayGetNI( pItem1, 3 );
      left.a = ( unsigned char ) hb_arrayGetNI( pItem1, 4 );

      Color right;

      right.r = ( unsigned char ) hb_arrayGetNI( pItem2, 1 );
      right.g = ( unsigned char ) hb_arrayGetNI( pItem2, 2 );
      right.b = ( unsigned char ) hb_arrayGetNI( pItem2, 3 );
      right.a = ( unsigned char ) hb_arrayGetNI( pItem2, 4 );

      Image image = GenImageGradientH( hb_parni( 1 ), hb_parni( 2 ), left, right );

      PHB_ITEM info = hb_itemArrayNew( 5 );

      hb_arraySetPtr( info, 1, image.data );
      hb_arraySetNI( info, 2, image.width );
      hb_arraySetNI( info, 3, image.height );
      hb_arraySetNI( info, 4, image.mipmaps );
      hb_arraySetNI( info, 5, image.format );

      hb_itemReturnRelease( info );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// Image GenImageGradientRadial(int width, int height, float density, Color inner, Color outer);      // Generate image: radial gradient
HB_FUNC( GenImageGradientRadial )
{
   PHB_ITEM pItem1, pItem2;

   if( hb_param( 1, HB_IT_INTEGER ) != NULL &&
       hb_param( 2, HB_IT_INTEGER ) != NULL &&
       hb_param( 3, HB_IT_NUMERIC ) != NULL &&
       ( pItem1 = hb_param( 4, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 4 &&
       ( pItem2 = hb_param( 5, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 4 )
   {
      Color inner;

      inner.r = ( unsigned char ) hb_arrayGetNI( pItem1, 1 );
      inner.g = ( unsigned char ) hb_arrayGetNI( pItem1, 2 );
      inner.b = ( unsigned char ) hb_arrayGetNI( pItem1, 3 );
      inner.a = ( unsigned char ) hb_arrayGetNI( pItem1, 4 );

      Color outer;

      outer.r = ( unsigned char ) hb_arrayGetNI( pItem2, 1 );
      outer.g = ( unsigned char ) hb_arrayGetNI( pItem2, 2 );
      outer.b = ( unsigned char ) hb_arrayGetNI( pItem2, 3 );
      outer.a = ( unsigned char ) hb_arrayGetNI( pItem2, 4 );

      Image image = GenImageGradientRadial( hb_parni( 1 ), hb_parni( 2 ), ( float ) hb_parnd( 3 ), inner, outer );

      PHB_ITEM info = hb_itemArrayNew( 5 );

      hb_arraySetPtr( info, 1, image.data );
      hb_arraySetNI( info, 2, image.width );
      hb_arraySetNI( info, 3, image.height );
      hb_arraySetNI( info, 4, image.mipmaps );
      hb_arraySetNI( info, 5, image.format );

      hb_itemReturnRelease( info );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// Image GenImageChecked(int width, int height, int checksX, int checksY, Color col1, Color col2);    // Generate image: checked
HB_FUNC( GENIMAGECHECKED )
{
   PHB_ITEM pItem1, pItem2;

   if( hb_param( 1, HB_IT_INTEGER ) != NULL &&
       hb_param( 2, HB_IT_INTEGER ) != NULL &&
       hb_param( 3, HB_IT_INTEGER ) != NULL &&
       hb_param( 4, HB_IT_INTEGER ) != NULL &&
       ( pItem1 = hb_param( 5, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 4 &&
       ( pItem2 = hb_param( 6, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 4 )
   {
      Color col1;

      col1.r = ( unsigned char ) hb_arrayGetNI( pItem1, 1 );
      col1.g = ( unsigned char ) hb_arrayGetNI( pItem1, 2 );
      col1.b = ( unsigned char ) hb_arrayGetNI( pItem1, 3 );
      col1.a = ( unsigned char ) hb_arrayGetNI( pItem1, 4 );

      Color col2;

      col2.r = ( unsigned char ) hb_arrayGetNI( pItem2, 1 );
      col2.g = ( unsigned char ) hb_arrayGetNI( pItem2, 2 );
      col2.b = ( unsigned char ) hb_arrayGetNI( pItem2, 3 );
      col2.a = ( unsigned char ) hb_arrayGetNI( pItem2, 4 );

      Image image = GenImageChecked( hb_parni( 1 ), hb_parni( 2 ), hb_parni( 3 ), hb_parni( 4 ), col1, col2 );

      PHB_ITEM info = hb_itemArrayNew( 5 );

      hb_arraySetPtr( info, 1, image.data );
      hb_arraySetNI( info, 2, image.width );
      hb_arraySetNI( info, 3, image.height );
      hb_arraySetNI( info, 4, image.mipmaps );
      hb_arraySetNI( info, 5, image.format );

      hb_itemReturnRelease( info );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// Image GenImageWhiteNoise(int width, int height, float factor);                                     // Generate image: white noise
HB_FUNC( GENIMAGEWHITENOISE )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL &&
       hb_param( 2, HB_IT_INTEGER ) != NULL &&
       hb_param( 3, HB_IT_NUMERIC ) != NULL )
   {
      Image image = GenImageWhiteNoise( hb_parni( 1 ), hb_parni( 2 ), ( float ) hb_parnd( 3 ) );

      PHB_ITEM info = hb_itemArrayNew( 5 );

      hb_arraySetPtr( info, 1, image.data );
      hb_arraySetNI( info, 2, image.width );
      hb_arraySetNI( info, 3, image.height );
      hb_arraySetNI( info, 4, image.mipmaps );
      hb_arraySetNI( info, 5, image.format );

      hb_itemReturnRelease( info );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// Image GenImagePerlinNoise(int width, int height, int offsetX, int offsetY, float scale);           // Generate image: perlin noise
HB_FUNC( GENIMAGEPERLINNOISE )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL &&
       hb_param( 2, HB_IT_INTEGER ) != NULL &&
       hb_param( 3, HB_IT_INTEGER ) != NULL &&
       hb_param( 4, HB_IT_INTEGER ) != NULL &&
       hb_param( 5, HB_IT_NUMERIC ) != NULL )
   {
      Image image = GenImagePerlinNoise( hb_parni( 1 ), hb_parni( 2 ), hb_parni( 3 ), hb_parni( 4 ), ( float ) hb_parnd( 5 ) );

      PHB_ITEM info = hb_itemArrayNew( 5 );

      hb_arraySetPtr( info, 1, image.data );
      hb_arraySetNI( info, 2, image.width );
      hb_arraySetNI( info, 3, image.height );
      hb_arraySetNI( info, 4, image.mipmaps );
      hb_arraySetNI( info, 5, image.format );

      hb_itemReturnRelease( info );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// Image GenImageCellular(int width, int height, int tileSize);                                       // Generate image: cellular algorithm. Bigger tileSize means bigger cells
HB_FUNC( GENIMAGECELLULAR )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL &&
       hb_param( 2, HB_IT_INTEGER ) != NULL &&
       hb_param( 3, HB_IT_INTEGER ) != NULL )
   {
      Image image = GenImageCellular( hb_parni( 1 ), hb_parni( 2 ), hb_parni( 3 ) );

      PHB_ITEM info = hb_itemArrayNew( 5 );

      hb_arraySetPtr( info, 1, image.data );
      hb_arraySetNI( info, 2, image.width );
      hb_arraySetNI( info, 3, image.height );
      hb_arraySetNI( info, 4, image.mipmaps );
      hb_arraySetNI( info, 5, image.format );

      hb_itemReturnRelease( info );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// Image manipulation functions

// Image ImageCopy(Image image);                                                                      // Create an image duplicate (useful for transformations)
HB_FUNC( IMAGECOPY )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 5 )
   {
      Image image;

      image.data    =  hb_arrayGetPtr( pItem, 1 );
      image.width   =  hb_arrayGetNI( pItem, 2 );
      image.height  =  hb_arrayGetNI( pItem, 3 );
      image.mipmaps =  hb_arrayGetNI( pItem, 4 );
      image.format  =  hb_arrayGetNI( pItem, 5 );

      Image imageRet = ImageCopy( image );

      PHB_ITEM info = hb_itemArrayNew( 5 );

      hb_arraySetPtr( info, 1, imageRet.data );
      hb_arraySetNI( info, 2, imageRet.width );
      hb_arraySetNI( info, 3, imageRet.height );
      hb_arraySetNI( info, 4, imageRet.mipmaps );
      hb_arraySetNI( info, 5, imageRet.format );

      hb_itemReturnRelease( info );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// Image ImageFromImage(Image image, Rectangle rec);                                                  // Create an image from another image piece
HB_FUNC( IMAGEFROMIMAGE )
{
   PHB_ITEM pItem1, pItem2;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 5 &&
       ( pItem2 = hb_param( 2, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 4 )
   {
      Image image;

      image.data    =  hb_arrayGetPtr( pItem1, 1 );
      image.width   =  hb_arrayGetNI( pItem1, 2 );
      image.height  =  hb_arrayGetNI( pItem1, 3 );
      image.mipmaps =  hb_arrayGetNI( pItem1, 4 );
      image.format  =  hb_arrayGetNI( pItem1, 5 );

      Rectangle rec;

      rec.x      = ( float ) hb_arrayGetND( pItem2, 1 );
      rec.y      = ( float ) hb_arrayGetND( pItem2, 2 );
      rec.width  = ( float ) hb_arrayGetND( pItem2, 3 );
      rec.height = ( float ) hb_arrayGetND( pItem2, 4 );

      Image imageRet = ImageFromImage( image, rec );

      PHB_ITEM info = hb_itemArrayNew( 5 );

      hb_arraySetPtr( info, 1, imageRet.data );
      hb_arraySetNI( info, 2, imageRet.width );
      hb_arraySetNI( info, 3, imageRet.height );
      hb_arraySetNI( info, 4, imageRet.mipmaps );
      hb_arraySetNI( info, 5, imageRet.format );

      hb_itemReturnRelease( info );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// Image ImageText(const char *text, int fontSize, Color color);                                      // Create an image from text (default font)
HB_FUNC( IMAGETEXT )
{
     PHB_ITEM pItem;

   if( hb_param( 1, HB_IT_STRING ) != NULL &&
       hb_param( 2, HB_IT_INTEGER ) != NULL &&
       ( pItem = hb_param( 3, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 4 )
   {
      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem, 4 );

      Image image = ImageText( hb_parc( 1 ), hb_parni( 2 ), color );

      PHB_ITEM info = hb_itemArrayNew( 5 );

      hb_arraySetPtr( info, 1, image.data );
      hb_arraySetNI( info, 2, image.width );
      hb_arraySetNI( info, 3, image.height );
      hb_arraySetNI( info, 4, image.mipmaps );
      hb_arraySetNI( info, 5, image.format );

      hb_itemReturnRelease( info );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// Image ImageTextEx(Font font, const char *text, float fontSize, float spacing, Color tint);         // Create an image from text (custom sprite font)

// void ImageFormat(Image *image, int newFormat);                                                     // Convert image data to desired format
HB_FUNC( IMAGEFORMAT )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 5 &&
        hb_param( 2, HB_IT_INTEGER ) != NULL )
   {
      Image image;

      image.data    =  hb_arrayGetPtr( pItem, 1 );
      image.width   =  hb_arrayGetNI( pItem, 2 );
      image.height  =  hb_arrayGetNI( pItem, 3 );
      image.mipmaps =  hb_arrayGetNI( pItem, 4 );
      image.format  =  hb_arrayGetNI( pItem, 5 );

      ImageFormat( &image, hb_parni( 2 ) );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void ImageToPOT(Image *image, Color fill);                                                         // Convert image to POT (power-of-two)
HB_FUNC( IMAGETOPOT )
{
   PHB_ITEM pItem1, pItem2;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 5 &&
       ( pItem2 = hb_param( 2, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 4 )
   {
      Image image;

      image.data    =  hb_arrayGetPtr( pItem1, 1 );
      image.width   =  hb_arrayGetNI( pItem1, 2 );
      image.height  =  hb_arrayGetNI( pItem1, 3 );
      image.mipmaps =  hb_arrayGetNI( pItem1, 4 );
      image.format  =  hb_arrayGetNI( pItem1, 5 );

      Color fill;

      fill.r = ( unsigned char ) hb_arrayGetNI( pItem2, 1 );
      fill.g = ( unsigned char ) hb_arrayGetNI( pItem2, 2 );
      fill.b = ( unsigned char ) hb_arrayGetNI( pItem2, 3 );
      fill.a = ( unsigned char ) hb_arrayGetNI( pItem2, 4 );

      ImageToPOT( &image, fill );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void ImageCrop(Image *image, Rectangle crop);                                                      // Crop an image to a defined rectangle
HB_FUNC( IMAGECROP )
{
   PHB_ITEM pItem1, pItem2;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 5 &&
       ( pItem2 = hb_param( 2, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 4 )
   {
      Image image;

      image.data    =  hb_arrayGetPtr( pItem1, 1 );
      image.width   =  hb_arrayGetNI( pItem1, 2 );
      image.height  =  hb_arrayGetNI( pItem1, 3 );
      image.mipmaps =  hb_arrayGetNI( pItem1, 4 );
      image.format  =  hb_arrayGetNI( pItem1, 5 );

      Rectangle crop;

      crop.x      = ( float ) hb_arrayGetND( pItem2, 1 );
      crop.y      = ( float ) hb_arrayGetND( pItem2, 2 );
      crop.width  = ( float ) hb_arrayGetND( pItem2, 3 );
      crop.height = ( float ) hb_arrayGetND( pItem2, 4 );

      ImageCrop( &image, crop );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void ImageAlphaCrop(Image *image, float threshold);                                                // Crop image depending on alpha value
HB_FUNC( IMAGEALPHACROP )
{
   PHB_ITEM pItem1;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 5 && hb_param( 2, HB_IT_NUMERIC ) != NULL )
   {
      Image image;

      image.data    =  hb_arrayGetPtr( pItem1, 1 );
      image.width   =  hb_arrayGetNI( pItem1, 2 );
      image.height  =  hb_arrayGetNI( pItem1, 3 );
      image.mipmaps =  hb_arrayGetNI( pItem1, 4 );
      image.format  =  hb_arrayGetNI( pItem1, 5 );

      ImageAlphaCrop( &image, ( float ) hb_parnd( 2 ) );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void ImageAlphaClear(Image *image, Color color, float threshold);                                  // Clear alpha channel to desired color
HB_FUNC( IMAGEALPHACLEAR )
{
   PHB_ITEM pItem1, pItem2;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 5 &&
       ( pItem2 = hb_param( 2, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 4 && hb_param( 3, HB_IT_NUMERIC ) != NULL )
   {
      Image image;

      image.data    =  hb_arrayGetPtr( pItem1, 1 );
      image.width   =  hb_arrayGetNI( pItem1, 2 );
      image.height  =  hb_arrayGetNI( pItem1, 3 );
      image.mipmaps =  hb_arrayGetNI( pItem1, 4 );
      image.format  =  hb_arrayGetNI( pItem1, 5 );

      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem2, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem2, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem2, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem2, 4 );

      ImageAlphaClear( &image, color, ( float ) hb_parnd( 3 ) );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void ImageAlphaMask(Image *image, Image alphaMask);                                                // Apply alpha mask to image
HB_FUNC( ImageAlphaMask )
{
   PHB_ITEM pItem1, pItem2;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 5 &&
       ( pItem2 = hb_param( 2, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 5 )
   {
      Image image;

      image.data    =  hb_arrayGetPtr( pItem1, 1 );
      image.width   =  hb_arrayGetNI( pItem1, 2 );
      image.height  =  hb_arrayGetNI( pItem1, 3 );
      image.mipmaps =  hb_arrayGetNI( pItem1, 4 );
      image.format  =  hb_arrayGetNI( pItem1, 5 );

      Image alphaMask;

      alphaMask.data    =  hb_arrayGetPtr( pItem2, 1 );
      alphaMask.width   =  hb_arrayGetNI( pItem2, 2 );
      alphaMask.height  =  hb_arrayGetNI( pItem2, 3 );
      alphaMask.mipmaps =  hb_arrayGetNI( pItem2, 4 );
      alphaMask.format  =  hb_arrayGetNI( pItem2, 5 );

      ImageAlphaMask( &image, alphaMask );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void ImageAlphaPremultiply(Image *image);                                                          // Premultiply alpha channel
HB_FUNC( IMAGEALPHAPREMULTIPLY )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 5 )
   {
      Image image;

      image.data    =  hb_arrayGetPtr( pItem, 1 );
      image.width   =  hb_arrayGetNI( pItem, 2 );
      image.height  =  hb_arrayGetNI( pItem, 3 );
      image.mipmaps =  hb_arrayGetNI( pItem, 4 );
      image.format  =  hb_arrayGetNI( pItem, 5 );

      ImageAlphaPremultiply( &image );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void ImageResize(Image *image, int newWidth, int newHeight);                                       // Resize image (Bicubic scaling algorithm)
HB_FUNC( IMAGERESIZE )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 5 &&
      hb_param( 2, HB_IT_INTEGER ) != NULL &&
      hb_param( 3, HB_IT_INTEGER ) != NULL )
   {
      Image image;

      image.data    =  hb_arrayGetPtr( pItem, 1 );
      image.width   =  hb_arrayGetNI( pItem, 2 );
      image.height  =  hb_arrayGetNI( pItem, 3 );
      image.mipmaps =  hb_arrayGetNI( pItem, 4 );
      image.format  =  hb_arrayGetNI( pItem, 5 );

      ImageResize( &image, hb_parni( 2 ), hb_parni( 3 ) );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void ImageResizeNN(Image *image, int newWidth,int newHeight);                                      // Resize image (Nearest-Neighbor scaling algorithm)
HB_FUNC( IMAGERESIZENN )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 5 &&
      hb_param( 2, HB_IT_INTEGER ) != NULL &&
      hb_param( 3, HB_IT_INTEGER ) != NULL )
   {
      Image image;

      image.data    =  hb_arrayGetPtr( pItem, 1 );
      image.width   =  hb_arrayGetNI( pItem, 2 );
      image.height  =  hb_arrayGetNI( pItem, 3 );
      image.mipmaps =  hb_arrayGetNI( pItem, 4 );
      image.format  =  hb_arrayGetNI( pItem, 5 );

      ImageResizeNN( &image, hb_parni( 2 ), hb_parni( 3 ) );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void ImageResizeCanvas(Image *image, int newWidth, int newHeight, int offsetX, int offsetY, Color fill);  // Resize canvas and fill with color
HB_FUNC( IMAGERESIZECANVAS )
{
   PHB_ITEM pItem1, pItem2;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 5 &&
      hb_param( 2, HB_IT_INTEGER ) != NULL &&
      hb_param( 3, HB_IT_INTEGER ) != NULL &&
      hb_param( 4, HB_IT_INTEGER ) != NULL &&
      hb_param( 5, HB_IT_INTEGER ) != NULL &&
      ( pItem2 = hb_param( 2, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 4 )
   {
      Image image;

      image.data    =  hb_arrayGetPtr( pItem1, 1 );
      image.width   =  hb_arrayGetNI( pItem1, 2 );
      image.height  =  hb_arrayGetNI( pItem1, 3 );
      image.mipmaps =  hb_arrayGetNI( pItem1, 4 );
      image.format  =  hb_arrayGetNI( pItem1, 5 );

      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem2, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem2, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem2, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem2, 4 );

      ImageResizeCanvas( &image, hb_parni( 2 ), hb_parni( 3 ), hb_parni( 4 ), hb_parni( 5 ), color );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void ImageMipmaps(Image *image);                                                                   // Generate all mipmap levels for a provided image
HB_FUNC( IMAGEMIPMAPS )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 5 )
   {
      Image image;

      image.data    =  hb_arrayGetPtr( pItem, 1 );
      image.width   =  hb_arrayGetNI( pItem, 2 );
      image.height  =  hb_arrayGetNI( pItem, 3 );
      image.mipmaps =  hb_arrayGetNI( pItem, 4 );
      image.format  =  hb_arrayGetNI( pItem, 5 );

      ImageMipmaps( &image );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void ImageDither(Image *image, int rBpp, int gBpp, int bBpp, int aBpp);                            // Dither image data to 16bpp or lower (Floyd-Steinberg dithering)
HB_FUNC( IMAGEDITHER )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 5 &&
      hb_param( 2, HB_IT_INTEGER ) != NULL &&
      hb_param( 3, HB_IT_INTEGER ) != NULL &&
      hb_param( 4, HB_IT_INTEGER ) != NULL &&
      hb_param( 5, HB_IT_INTEGER ) != NULL )
   {
      Image image;

      image.data    =  hb_arrayGetPtr( pItem, 1 );
      image.width   =  hb_arrayGetNI( pItem, 2 );
      image.height  =  hb_arrayGetNI( pItem, 3 );
      image.mipmaps =  hb_arrayGetNI( pItem, 4 );
      image.format  =  hb_arrayGetNI( pItem, 5 );

      ImageDither( &image, hb_parni( 2 ), hb_parni( 3 ), hb_parni( 4 ), hb_parni( 5 ) );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void ImageFlipVertical(Image *image);                                                              // Flip image vertically
HB_FUNC( IMAGEFLIPVERTICAL )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 5 )
   {
      Image image;

      image.data    =  hb_arrayGetPtr( pItem, 1 );
      image.width   =  hb_arrayGetNI( pItem, 2 );
      image.height  =  hb_arrayGetNI( pItem, 3 );
      image.mipmaps =  hb_arrayGetNI( pItem, 4 );
      image.format  =  hb_arrayGetNI( pItem, 5 );

      ImageFlipVertical( &image );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void ImageFlipHorizontal(Image *image);                                                            // Flip image horizontally
HB_FUNC( IMAGEFLIPHORIZONTAL )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 5 )
   {
      Image image;

      image.data    =  hb_arrayGetPtr( pItem, 1 );
      image.width   =  hb_arrayGetNI( pItem, 2 );
      image.height  =  hb_arrayGetNI( pItem, 3 );
      image.mipmaps =  hb_arrayGetNI( pItem, 4 );
      image.format  =  hb_arrayGetNI( pItem, 5 );

      ImageFlipHorizontal( &image );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void ImageRotateCW(Image *image);                                                                  // Rotate image clockwise 90deg
HB_FUNC( IMAGEROTATECW )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 5 )
   {
      Image image;

      image.data    =  hb_arrayGetPtr( pItem, 1 );
      image.width   =  hb_arrayGetNI( pItem, 2 );
      image.height  =  hb_arrayGetNI( pItem, 3 );
      image.mipmaps =  hb_arrayGetNI( pItem, 4 );
      image.format  =  hb_arrayGetNI( pItem, 5 );

      ImageRotateCW( &image );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void ImageRotateCCW(Image *image);                                                                 // Rotate image counter-clockwise 90deg
HB_FUNC( IMAGEROTATECCW )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 5 )
   {
      Image image;

      image.data    =  hb_arrayGetPtr( pItem, 1 );
      image.width   =  hb_arrayGetNI( pItem, 2 );
      image.height  =  hb_arrayGetNI( pItem, 3 );
      image.mipmaps =  hb_arrayGetNI( pItem, 4 );
      image.format  =  hb_arrayGetNI( pItem, 5 );

      ImageRotateCCW( &image );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void ImageColorTint(Image *image, Color color);                                                    // Modify image color: tint

// void ImageColorInvert(Image *image);                                                               // Modify image color: invert
HB_FUNC( IMAGECOLORINVERT )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 5 )
   {
      Image image;

      image.data    =  hb_arrayGetPtr( pItem, 1 );
      image.width   =  hb_arrayGetNI( pItem, 2 );
      image.height  =  hb_arrayGetNI( pItem, 3 );
      image.mipmaps =  hb_arrayGetNI( pItem, 4 );
      image.format  =  hb_arrayGetNI( pItem, 5 );

      ImageColorInvert( &image );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void ImageColorGrayscale(Image *image);                                                            // Modify image color: grayscale
// void ImageColorContrast(Image *image, float contrast);                                             // Modify image color: contrast (-100 to 100)
// void ImageColorBrightness(Image *image, int brightness);                                           // Modify image color: brightness (-255 to 255)
// void ImageColorReplace(Image *image, Color color, Color replace);                                  // Modify image color: replace color
// Color *LoadImageColors(Image image);                                                               // Load color data from image as a Color array (RGBA - 32bit)
// Color *LoadImagePalette(Image image, int maxPaletteSize, int *colorsCount);                        // Load colors palette from image as a Color array (RGBA - 32bit)
// void UnloadImageColors(Color *colors);                                                             // Unload color data loaded with LoadImageColors()
// void UnloadImagePalette(Color *colors);                                                            // Unload colors palette loaded with LoadImagePalette()
// Rectangle GetImageAlphaBorder(Image image, float threshold);                                       // Get image alpha border rectangle

// Image drawing functions
// NOTE: Image software-rendering functions (CPU)
// void ImageClearBackground(Image *dst, Color color);                                                // Clear image background with given color
// void ImageDrawPixel(Image *dst, int posX, int posY, Color color);                                  // Draw pixel within an image
// void ImageDrawPixelV(Image *dst, Vector2 position, Color color);                                   // Draw pixel within an image (Vector version)
// void ImageDrawLine(Image *dst, int startPosX, int startPosY, int endPosX, int endPosY, Color color); // Draw line within an image
// void ImageDrawLineV(Image *dst, Vector2 start, Vector2 end, Color color);                          // Draw line within an image (Vector version)
// void ImageDrawCircle(Image *dst, int centerX, int centerY, int radius, Color color);               // Draw circle within an image
// void ImageDrawCircleV(Image *dst, Vector2 center, int radius, Color color);                        // Draw circle within an image (Vector version)
// void ImageDrawRectangle(Image *dst, int posX, int posY, int width, int height, Color color);       // Draw rectangle within an image
// void ImageDrawRectangleV(Image *dst, Vector2 position, Vector2 size, Color color);                 // Draw rectangle within an image (Vector version)
// void ImageDrawRectangleRec(Image *dst, Rectangle rec, Color color);                                // Draw rectangle within an image
// void ImageDrawRectangleLines(Image *dst, Rectangle rec, int thick, Color color);                   // Draw rectangle lines within an image
// void ImageDraw(Image *dst, Image src, Rectangle srcRec, Rectangle dstRec, Color tint);             // Draw a source image within a destination image (tint applied to source)
// void ImageDrawText(Image *dst, const char *text, int posX, int posY, int fontSize, Color color);   // Draw text (using default font) within an image (destination)
// void ImageDrawTextEx(Image *dst, Font font, const char *text, Vector2 position, float fontSize, float spacing, Color tint); // Draw text (custom sprite font) within an image (destination)

// Texture loading functions
// NOTE: These functions require GPU access
// Texture2D LoadTexture(const char *fileName);                                                       // Load texture from file into GPU memory (VRAM)
// Texture2D LoadTextureFromImage(Image image);                                                       // Load texture from image data
// TextureCubemap LoadTextureCubemap(Image image, int layoutType);                                    // Load cubemap from image, multiple image cubemap layouts supported
// RenderTexture2D LoadRenderTexture(int width, int height);                                          // Load texture for rendering (framebuffer)
// void UnloadTexture(Texture2D texture);                                                             // Unload texture from GPU memory (VRAM)
// void UnloadRenderTexture(RenderTexture2D target);                                                  // Unload render texture from GPU memory (VRAM)
// void UpdateTexture(Texture2D texture, const void *pixels);                                         // Update GPU texture with new data
// void UpdateTextureRec(Texture2D texture, Rectangle rec, const void *pixels);                       // Update GPU texture rectangle with new data
// Image GetTextureData(Texture2D texture);                                                           // Get pixel data from GPU texture and return an Image
// Image GetScreenData(void);                                                                         // Get pixel data from screen buffer and return an Image (screenshot)
// Texture configuration functions
// void GenTextureMipmaps(Texture2D *texture);                                                        // Generate GPU mipmaps for a texture
// void SetTextureFilter(Texture2D texture, int filterMode);                                          // Set texture scaling filter mode
// void SetTextureWrap(Texture2D texture, int wrapMode);                                              // Set texture wrapping mode

// Texture drawing functions
// void DrawTexture(Texture2D texture, int posX, int posY, Color tint);                               // Draw a Texture2D
// void DrawTextureV(Texture2D texture, Vector2 position, Color tint);                                // Draw a Texture2D with position defined as Vector2
// void DrawTextureEx(Texture2D texture, Vector2 position, float rotation, float scale, Color tint);  // Draw a Texture2D with extended parameters
// void DrawTextureRec(Texture2D texture, Rectangle source, Vector2 position, Color tint);         // Draw a part of a texture defined by a rectangle
// void DrawTextureQuad(Texture2D texture, Vector2 tiling, Vector2 offset, Rectangle quad, Color tint);  // Draw texture quad with tiling and offset parameters
// void DrawTextureTiled(Texture2D texture, Rectangle source, Rectangle dest, Vector2 origin, float rotation, float scale, Color tint);  // Draw part of a texture (defined by a rectangle) with rotation and scale tiled into dest.
// void DrawTexturePro(Texture2D texture, Rectangle source, Rectangle dest, Vector2 origin, float rotation, Color tint);       // Draw a part of a texture defined by a rectangle with 'pro' parameters
// void DrawTextureNPatch(Texture2D texture, NPatchInfo nPatchInfo, Rectangle dest, Vector2 origin, float rotation, Color tint);  // Draws a texture (or part of it) that stretches or shrinks nicely

// Color/pixel related functions
// Color Fade(Color color, float alpha);                                 // Returns color with alpha applied, alpha goes from 0.0f to 1.0f
// int ColorToInt(Color color);                                          // Returns hexadecimal value for a Color
// Vector4 ColorNormalize(Color color);                                  // Returns Color normalized as float [0..1]
// Color ColorFromNormalized(Vector4 normalized);                        // Returns Color from normalized values [0..1]
// Vector3 ColorToHSV(Color color);                                      // Returns HSV values for a Color
// Color ColorFromHSV(float hue, float saturation, float value);         // Returns a Color from HSV values
// Color ColorAlpha(Color color, float alpha);                           // Returns color with alpha applied, alpha goes from 0.0f to 1.0f
// Color ColorAlphaBlend(Color dst, Color src, Color tint);              // Returns src alpha-blended into dst color with tint
// Color GetColor(int hexValue);                                         // Get Color structure from hexadecimal value
// Color GetPixelColor(void *srcPtr, int format);                        // Get Color from a source pixel pointer of certain format
// void SetPixelColor(void *dstPtr, Color color, int format);            // Set color formatted into destination pixel pointer
// int GetPixelDataSize(int width, int height, int format);              // Get pixel data size in bytes for certain format
