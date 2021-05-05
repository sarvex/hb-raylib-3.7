/*
 * RayLib library: shapes.c
 * version 3.7
 *
 * Copyright 2021 Leonardo Mendez ( mlmgerencir at gmail com )
 * Copyright 2020 - 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbraylib.h"


// Set texture and rectangle to be used on shapes drawing
// NOTE: It can be useful when using basic shapes and one single font,
// defining a font char white rectangle would allow drawing everything in a single draw call
//void SetShapesTexture(Texture2D texture, Rectangle source);

/* --- Basic shapes drawing functions --- */

// void DrawPixel( int posX, int posY, Color color );
HB_FUNC( DRAWPIXEL )
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

      DrawPixel( hb_parni( 1 ), hb_parni( 2 ), color );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawPixelV( Vector2 position, Color color );
HB_FUNC( DRAWPIXELV )
{
   PHB_ITEM pItem1, pItem2;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 2 &&
       ( pItem2 = hb_param( 2, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 4 )
   {
      Vector2 position;

      position.x = ( float ) hb_arrayGetND( pItem1, 1 );
      position.y = ( float ) hb_arrayGetND( pItem1, 2 );

      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem2, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem2, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem2, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem2, 4 );

      DrawPixelV( position, color );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawLine( int startPosX, int startPosY, int endPosX, int endPosY, Color color );
HB_FUNC( DRAWLINE )
{
   PHB_ITEM pItem;

   if( hb_param( 1, HB_IT_INTEGER ) != NULL &&
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

      DrawLine( hb_parni( 1 ), hb_parni( 2 ), hb_parni( 3 ), hb_parni( 4 ), color );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawLineV( Vector2 startPos, Vector2 endPos, Color color );
HB_FUNC( DRAWLINEV )
{
   PHB_ITEM pItem1, pItem2, pItem3;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 2 &&
       ( pItem2 = hb_param( 2, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 2 &&
       ( pItem3 = hb_param( 3, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem3 ) == 4 )
   {
      Vector2 startPos;

      startPos.x = ( float ) hb_arrayGetND( pItem1, 1 );
      startPos.y = ( float ) hb_arrayGetND( pItem1, 2 );

      Vector2 endPos;

      endPos.x = ( float ) hb_arrayGetND( pItem2, 1 );
      endPos.y = ( float ) hb_arrayGetND( pItem2, 2 );

      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem3, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem3, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem3, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem3, 4 );

      DrawLineV( startPos, endPos, color );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawLineEx( Vector2 startPos, Vector2 endPos, float thick, Color color );
HB_FUNC( DRAWLINEEX )
{
   PHB_ITEM pItem1, pItem2, pItem3;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 2 &&
       ( pItem2 = hb_param( 2, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 2 &&
                  hb_param( 3, HB_IT_NUMERIC ) != NULL &&
       ( pItem3 = hb_param( 4, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem3 ) == 4 )
   {
      Vector2 startPos;

      startPos.x = ( float ) hb_arrayGetND( pItem1, 1 );
      startPos.y = ( float ) hb_arrayGetND( pItem1, 2 );

      Vector2 endPos;

      endPos.x = ( float ) hb_arrayGetND( pItem2, 1 );
      endPos.y = ( float ) hb_arrayGetND( pItem2, 2 );

      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem3, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem3, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem3, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem3, 4 );

      DrawLineEx( startPos, endPos, ( float ) hb_parnd( 3 ), color );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawLineBezier( Vector2 startPos, Vector2 endPos, float thick, Color color );
HB_FUNC( DRAWLINEBEZIER )
{
   PHB_ITEM pItem1, pItem2, pItem3;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 2 &&
       ( pItem2 = hb_param( 2, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 2 &&
                  hb_param( 3, HB_IT_NUMERIC ) != NULL &&
       ( pItem3 = hb_param( 4, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem3 ) == 4 )
   {
      Vector2 startPos;

      startPos.x = ( float ) hb_arrayGetND( pItem1, 1 );
      startPos.y = ( float ) hb_arrayGetND( pItem1, 2 );

      Vector2 endPos;

      endPos.x = ( float ) hb_arrayGetND( pItem2, 1 );
      endPos.y = ( float ) hb_arrayGetND( pItem2, 2 );

      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem3, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem3, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem3, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem3, 4 );

      DrawLineBezier( startPos, endPos, ( float ) hb_parnd( 3 ), color );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

//void DrawLineBezierQuad(Vector2 startPos, Vector2 endPos, Vector2 controlPos, float thick, Color color); //Draw line using quadratic bezier curves with a control point

// void DrawLineStrip( Vector2 *points, int pointsCount, Color color);
HB_FUNC( DRAWLINESTRIP )
{
   PHB_ITEM pItem1, pItem2;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 2 &&
                  hb_param( 2, HB_IT_INTEGER ) != NULL &&
       ( pItem2 = hb_param( 3, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 4 )
   {
      Vector2 points;

      points.x = ( float ) hb_arrayGetND( pItem1, 1 );
      points.y = ( float ) hb_arrayGetND( pItem1, 2 );

      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem2, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem2, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem2, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem2, 4 );

      DrawLineStrip( &points, hb_parni( 2 ), color );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawCircle( int centerX, int centerY, float radius, Color color );
HB_FUNC( DRAWCIRCLE )
{
   PHB_ITEM pItem;

   if( hb_param( 1, HB_IT_INTEGER ) != NULL &&
       hb_param( 2, HB_IT_INTEGER ) != NULL &&
       hb_param( 3, HB_IT_NUMERIC ) != NULL &&
       ( pItem = hb_param( 4, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 4 )
   {
      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem, 4 );

      DrawCircle( hb_parni( 1 ), hb_parni( 2 ), ( float ) hb_parnd( 3 ), color );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}


//void DrawCircleSector(Vector2 center, float radius, float startAngle, float endAngle, int segments, Color color);
HB_FUNC( DRAWCIRCLESECTOR )
{
   PHB_ITEM pItem1, pItem2;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 2 &&
       hb_param( 2, HB_IT_NUMERIC ) != NULL &&
       hb_param( 3, HB_IT_NUMERIC ) != NULL &&
       hb_param( 4, HB_IT_NUMERIC ) != NULL &&
       hb_param( 5, HB_IT_INTEGER ) != NULL &&
       ( pItem2 = hb_param( 6, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 4 )
   {
      Vector2 center;

      center.x = ( float ) hb_arrayGetND( pItem1, 1 );
      center.y = ( float ) hb_arrayGetND( pItem1, 2 );

      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem2, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem2, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem2, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem2, 4 );

      DrawCircleSector( center, ( float ) hb_parnd( 2 ), ( float ) hb_parnd( 3 ), ( float ) hb_parnd( 4 ), hb_parni( 5 ), color );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

 //void DrawCircleSectorLines(Vector2 center, float radius, float startAngle, float endAngle, int segments, Color color);
HB_FUNC( DRAWCIRCLESECTORLINES )
{
  PHB_ITEM pItem1, pItem2;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 2 &&
       hb_param( 2, HB_IT_NUMERIC ) != NULL &&
       hb_param( 3, HB_IT_NUMERIC ) != NULL &&
       hb_param( 4, HB_IT_NUMERIC ) != NULL &&
       hb_param( 5, HB_IT_INTEGER ) != NULL &&
       ( pItem2 = hb_param( 6, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 4 )
   {
      Vector2 center;

      center.x = ( float ) hb_arrayGetND( pItem1, 1 );
      center.y = ( float ) hb_arrayGetND( pItem1, 2 );

      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem2, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem2, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem2, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem2, 4 );

      DrawCircleSectorLines( center, ( float ) hb_parnd( 2 ), ( float ) hb_parnd( 3 ), ( float ) hb_parnd( 4 ), hb_parni( 5 ), color );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawCircleGradient( int centerX, int centerY, float radius, Color color1, Color color2 );
HB_FUNC( DRAWCIRCLEGRADIENT )
{
  PHB_ITEM pItem1, pItem2;

   if( hb_param( 1, HB_IT_INTEGER ) != NULL &&
       hb_param( 2, HB_IT_INTEGER ) != NULL &&
       hb_param( 3, HB_IT_NUMERIC ) != NULL &&
       ( pItem1 = hb_param( 4, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 4 &&
       ( pItem2 = hb_param( 5, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 4 )
   {
      Color color1;

      color1.r = ( unsigned char ) hb_arrayGetNI( pItem1, 1 );
      color1.g = ( unsigned char ) hb_arrayGetNI( pItem1, 2 );
      color1.b = ( unsigned char ) hb_arrayGetNI( pItem1, 3 );
      color1.a = ( unsigned char ) hb_arrayGetNI( pItem1, 4 );

      Color color2;

      color2.r = ( unsigned char ) hb_arrayGetNI( pItem2, 1 );
      color2.g = ( unsigned char ) hb_arrayGetNI( pItem2, 2 );
      color2.b = ( unsigned char ) hb_arrayGetNI( pItem2, 3 );
      color2.a = ( unsigned char ) hb_arrayGetNI( pItem2, 4 );

      DrawCircleGradient( hb_parni( 1 ), hb_parni( 2 ), ( float ) hb_parnd( 3 ), color1, color2 );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawCircleV( Vector2 center, float radius, Color color );
HB_FUNC( DRAWCIRCLEV )
{
   PHB_ITEM pItem1, pItem2;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 2 &&
                  hb_param( 2, HB_IT_NUMERIC ) != NULL &&
       ( pItem2 = hb_param( 3, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 4 )
   {
      Vector2 center;

      center.x = ( float ) hb_arrayGetND( pItem1, 1 );
      center.y = ( float ) hb_arrayGetND( pItem1, 2 );

      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem2, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem2, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem2, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem2, 4 );

      DrawCircleV( center, ( float ) hb_parnd( 2 ), color );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawCircleLines( int centerX, int centerY, float radius, Color color );
HB_FUNC( DRAWCIRCLELINES )
{
   PHB_ITEM pItem;

   if( hb_param( 1, HB_IT_INTEGER ) != NULL &&
       hb_param( 2, HB_IT_INTEGER ) != NULL &&
       hb_param( 3, HB_IT_NUMERIC ) != NULL &&
       ( pItem = hb_param( 4, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 4 )
   {
      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem, 4 );

      DrawCircleLines( hb_parni( 1 ), hb_parni( 2 ), ( float ) hb_parnd( 3 ), color );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawEllipse( int centerX, int centerY, float radiusH, float radiusV, Color color );
HB_FUNC( DRAWELLIPSE )
{
   PHB_ITEM pItem;

   if( hb_param( 1, HB_IT_INTEGER ) != NULL &&
       hb_param( 2, HB_IT_INTEGER ) != NULL &&
       hb_param( 3, HB_IT_NUMERIC ) != NULL &&
       hb_param( 4, HB_IT_NUMERIC ) != NULL &&
       ( pItem = hb_param( 5, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 4 )
   {
      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem, 4 );

      DrawEllipse( hb_parni( 1 ), hb_parni( 2 ), ( float ) hb_parnd( 3 ), ( float ) hb_parnd( 4 ), color );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawEllipseLines( int centerX, int centerY, float radiusH, float radiusV, Color color );
HB_FUNC( DRAWELLIPSELINES )
{
   PHB_ITEM pItem;

   if( hb_param( 1, HB_IT_INTEGER ) != NULL &&
       hb_param( 2, HB_IT_INTEGER ) != NULL &&
       hb_param( 3, HB_IT_NUMERIC ) != NULL &&
       hb_param( 4, HB_IT_NUMERIC ) != NULL &&
       ( pItem = hb_param( 5, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 4 )
   {
      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem, 4 );

      DrawEllipseLines( hb_parni( 1 ), hb_parni( 2 ), ( float ) hb_parnd( 3 ), ( float ) hb_parnd( 4 ), color );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}
//void DrawRing(Vector2 center, float innerRadius, float outerRadius, float startAngle, float endAngle, int segments, Color color); // Draw ring
HB_FUNC( DRAWRING )
{
   PHB_ITEM pItem1, pItem2;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 2 &&
       hb_param( 2, HB_IT_NUMERIC ) != NULL &&
       hb_param( 3, HB_IT_NUMERIC ) != NULL &&
       hb_param( 4, HB_IT_NUMERIC ) != NULL &&
       hb_param( 5, HB_IT_NUMERIC ) != NULL &&
       hb_param( 6, HB_IT_INTEGER ) != NULL &&
       ( pItem2 = hb_param( 7, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 4 )
   {
      Vector2 center;

      center.x = ( float ) hb_arrayGetND( pItem1, 1 );
      center.y = ( float ) hb_arrayGetND( pItem1, 2 );

      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem2, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem2, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem2, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem2, 4 );

      DrawRing( center, ( float ) hb_parnd( 2 ), ( float ) hb_parnd( 3 ), ( float ) hb_parnd( 4 ), hb_parnd( 5 ), hb_parni( 6 ), color );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

//void DrawRingLines(Vector2 center, float innerRadius, float outerRadius, float startAngle, float endAngle, int segments, Color color);    // Draw ring outline
HB_FUNC( DRAWRINGLINES )
{
   PHB_ITEM pItem1, pItem2;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 2 &&
       hb_param( 2, HB_IT_NUMERIC ) != NULL &&
       hb_param( 3, HB_IT_NUMERIC ) != NULL &&
       hb_param( 4, HB_IT_NUMERIC ) != NULL &&
       hb_param( 5, HB_IT_NUMERIC ) != NULL &&
       hb_param( 6, HB_IT_INTEGER ) != NULL &&
       ( pItem2 = hb_param( 7, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 4 )
   {
      Vector2 center;

      center.x = ( float ) hb_arrayGetND( pItem1, 1 );
      center.y = ( float ) hb_arrayGetND( pItem1, 2 );

      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem2, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem2, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem2, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem2, 4 );

      DrawRingLines( center, ( float ) hb_parnd( 2 ), ( float ) hb_parnd( 3 ), ( float ) hb_parnd( 4 ), ( float ) hb_parnd( 5 ), hb_parni( 6 ), color );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawRectangle( int posX, int posY, int width, int height, Color color );
HB_FUNC( DRAWRECTANGLE )
{
   PHB_ITEM pItem;

   if( hb_param( 1, HB_IT_INTEGER ) != NULL &&
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

      DrawRectangle( hb_parni( 1 ), hb_parni( 2 ), hb_parni( 3 ), hb_parni( 4 ), color );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawRectangleV( Vector2 position, Vector2 size, Color color );
HB_FUNC( DRAWRECTANGLEV )
{
   PHB_ITEM pItem1, pItem2, pItem3;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 2 &&
       ( pItem2 = hb_param( 2, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 2 &&
       ( pItem3 = hb_param( 3, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem3 ) == 4 )
   {
      Vector2 position;

      position.x = ( float ) hb_arrayGetND( pItem1, 1 );
      position.y = ( float ) hb_arrayGetND( pItem1, 2 );

      Vector2 size;

      size.x = ( float ) hb_arrayGetND( pItem2, 1 );
      size.y = ( float ) hb_arrayGetND( pItem2, 2 );

      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem3, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem3, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem3, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem3, 4 );

      DrawRectangleV( position, size, color );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawRectangleRec( Rectangle rec, Color color );
HB_FUNC( DRAWRECTANGLEREC )
{
   PHB_ITEM pItem1, pItem2;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 4 &&
       ( pItem2 = hb_param( 2, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 4 )
   {
      Rectangle rec;

      rec.x      = ( float ) hb_arrayGetND( pItem1, 1 );
      rec.y      = ( float ) hb_arrayGetND( pItem1, 2 );
      rec.width  = ( float ) hb_arrayGetND( pItem1, 3 );
      rec.height = ( float ) hb_arrayGetND( pItem1, 4 );

      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem2, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem2, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem2, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem2, 4 );

      DrawRectangleRec( rec, color );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawRectanglePro( Rectangle rec, Vector2 origin, float rotation, Color color );
HB_FUNC( DRAWRECTANGLEPRO )
{
   PHB_ITEM pItem1, pItem2, pItem3;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 4 &&
       ( pItem2 = hb_param( 2, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 2 &&
                  hb_param( 3, HB_IT_NUMERIC ) != NULL &&
       ( pItem3 = hb_param( 4, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem3 ) == 4 )
   {
      Rectangle rec;

      rec.x      = ( float ) hb_arrayGetND( pItem1, 1 );
      rec.y      = ( float ) hb_arrayGetND( pItem1, 2 );
      rec.width  = ( float ) hb_arrayGetND( pItem1, 3 );
      rec.height = ( float ) hb_arrayGetND( pItem1, 4 );

      Vector2 origin;

      origin.x = ( float ) hb_arrayGetND( pItem2, 1 );
      origin.y = ( float ) hb_arrayGetND( pItem2, 2 );

      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem3, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem3, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem3, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem3, 4 );

      DrawRectanglePro( rec, origin, ( float ) hb_parnd( 3 ), color );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawRectangleGradientV( int posX, int posY, int width, int height, Color color1, Color color2 );
HB_FUNC( DRAWRECTANGLEGRADIENTV )
{
   PHB_ITEM pItem1, pItem2;

   if( hb_param( 1, HB_IT_INTEGER ) != NULL &&
       hb_param( 2, HB_IT_INTEGER ) != NULL &&
       hb_param( 3, HB_IT_INTEGER ) != NULL &&
       hb_param( 4, HB_IT_INTEGER ) != NULL &&
       ( pItem1 = hb_param( 5, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 4 &&
       ( pItem2 = hb_param( 6, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 4 )
   {
      Color color1;

      color1.r = ( unsigned char ) hb_arrayGetNI( pItem1, 1 );
      color1.g = ( unsigned char ) hb_arrayGetNI( pItem1, 2 );
      color1.b = ( unsigned char ) hb_arrayGetNI( pItem1, 3 );
      color1.a = ( unsigned char ) hb_arrayGetNI( pItem1, 4 );

      Color color2;

      color2.r = ( unsigned char ) hb_arrayGetNI( pItem2, 1 );
      color2.g = ( unsigned char ) hb_arrayGetNI( pItem2, 2 );
      color2.b = ( unsigned char ) hb_arrayGetNI( pItem2, 3 );
      color2.a = ( unsigned char ) hb_arrayGetNI( pItem2, 4 );

      DrawRectangleGradientV( hb_parni( 1 ), hb_parni( 2 ), hb_parni( 3 ), hb_parni( 4 ), color1, color2 );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawRectangleGradientH( int posX, int posY, int width, int height, Color color1, Color color2 );
HB_FUNC( DRAWRECTANGLEGRADIENTH )
{
   PHB_ITEM pItem1, pItem2;

   if( hb_param( 1, HB_IT_INTEGER ) != NULL &&
       hb_param( 2, HB_IT_INTEGER ) != NULL &&
       hb_param( 3, HB_IT_INTEGER ) != NULL &&
       hb_param( 4, HB_IT_INTEGER ) != NULL &&
       ( pItem1 = hb_param( 5, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 4 &&
       ( pItem2 = hb_param( 6, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 4 )
   {
      Color color1;

      color1.r = ( unsigned char ) hb_arrayGetNI( pItem1, 1 );
      color1.g = ( unsigned char ) hb_arrayGetNI( pItem1, 2 );
      color1.b = ( unsigned char ) hb_arrayGetNI( pItem1, 3 );
      color1.a = ( unsigned char ) hb_arrayGetNI( pItem1, 4 );

      Color color2;

      color2.r = ( unsigned char ) hb_arrayGetNI( pItem2, 1 );
      color2.g = ( unsigned char ) hb_arrayGetNI( pItem2, 2 );
      color2.b = ( unsigned char ) hb_arrayGetNI( pItem2, 3 );
      color2.a = ( unsigned char ) hb_arrayGetNI( pItem2, 4 );

      DrawRectangleGradientH( hb_parni( 1 ), hb_parni( 2 ), hb_parni( 3 ), hb_parni( 4 ), color1, color2 );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawRectangleGradientEx( Rectangle rec, Color col1, Color col2, Color col3, Color col4 );
HB_FUNC( DRAWRECTANGLEGRADIENTEX )
{
   PHB_ITEM pItem1, pItem2, pItem3, pItem4, pItem5;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 4 &&
       ( pItem2 = hb_param( 2, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 4 &&
       ( pItem3 = hb_param( 3, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem3 ) == 4 &&
       ( pItem4 = hb_param( 4, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem4 ) == 4 &&
       ( pItem5 = hb_param( 5, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem5 ) == 4 )
   {
      Rectangle rec;

      rec.x      = ( float ) hb_arrayGetND( pItem1, 1 );
      rec.y      = ( float ) hb_arrayGetND( pItem1, 2 );
      rec.width  = ( float ) hb_arrayGetND( pItem1, 3 );
      rec.height = ( float ) hb_arrayGetND( pItem1, 4 );

      Color col1;

      col1.r = ( unsigned char ) hb_arrayGetNI( pItem2, 1 );
      col1.g = ( unsigned char ) hb_arrayGetNI( pItem2, 2 );
      col1.b = ( unsigned char ) hb_arrayGetNI( pItem2, 3 );
      col1.a = ( unsigned char ) hb_arrayGetNI( pItem2, 4 );

      Color col2;

      col2.r = ( unsigned char ) hb_arrayGetNI( pItem3, 1 );
      col2.g = ( unsigned char ) hb_arrayGetNI( pItem3, 2 );
      col2.b = ( unsigned char ) hb_arrayGetNI( pItem3, 3 );
      col2.a = ( unsigned char ) hb_arrayGetNI( pItem3, 4 );

      Color col3;

      col3.r = ( unsigned char ) hb_arrayGetNI( pItem4, 1 );
      col3.g = ( unsigned char ) hb_arrayGetNI( pItem4, 2 );
      col3.b = ( unsigned char ) hb_arrayGetNI( pItem4, 3 );
      col3.a = ( unsigned char ) hb_arrayGetNI( pItem4, 4 );

      Color col4;

      col4.r = ( unsigned char ) hb_arrayGetNI( pItem5, 1 );
      col4.g = ( unsigned char ) hb_arrayGetNI( pItem5, 2 );
      col4.b = ( unsigned char ) hb_arrayGetNI( pItem5, 3 );
      col4.a = ( unsigned char ) hb_arrayGetNI( pItem5, 4 );

      DrawRectangleGradientEx( rec, col1, col2, col3, col4 );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawRectangleLines( int posX, int posY, int width, int height, Color color );
HB_FUNC( DRAWRECTANGLELINES )
{
   PHB_ITEM pItem;

   if( hb_param( 1, HB_IT_INTEGER ) != NULL &&
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

      DrawRectangleLines( hb_parni( 1 ), hb_parni( 2 ), hb_parni( 3 ), hb_parni( 4 ), color );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawRectangleLinesEx( Rectangle rec, int lineThick, Color color );
HB_FUNC( DRAWRECTANGLELINESEX )
{
   PHB_ITEM pItem1, pItem2;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 4 &&
                  hb_param( 2, HB_IT_INTEGER ) != NULL &&
       ( pItem2 = hb_param( 3, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 4 )
   {
      Rectangle rec;

      rec.x      = ( float ) hb_arrayGetND( pItem1, 1 );
      rec.y      = ( float ) hb_arrayGetND( pItem1, 2 );
      rec.width  = ( float ) hb_arrayGetND( pItem1, 3 );
      rec.height = ( float ) hb_arrayGetND( pItem1, 4 );

      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem2, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem2, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem2, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem2, 4 );

      DrawRectangleLinesEx( rec, hb_parni( 2 ), color );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawRectangleRounded( Rectangle rec, float roundness, int segments, Color color );
HB_FUNC( DRAWRECTANGLEROUNDED )
{
   PHB_ITEM pItem1, pItem2;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 4 &&
                  hb_param( 2, HB_IT_NUMERIC ) != NULL &&
                  hb_param( 3, HB_IT_INTEGER ) != NULL &&
       ( pItem2 = hb_param( 4, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 4 )
   {
      Rectangle rec;

      rec.x      = ( float ) hb_arrayGetND( pItem1, 1 );
      rec.y      = ( float ) hb_arrayGetND( pItem1, 2 );
      rec.width  = ( float ) hb_arrayGetND( pItem1, 3 );
      rec.height = ( float ) hb_arrayGetND( pItem1, 4 );

      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem2, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem2, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem2, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem2, 4 );

      DrawRectangleRounded( rec, ( float ) hb_parnd( 2 ), hb_parni( 3 ), color );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawRectangleRoundedLines( Rectangle rec, float roundness, int segments, int lineThick, Color color );
HB_FUNC( DRAWRECTANGLEROUNDEDLINES )
{
   PHB_ITEM pItem1, pItem2;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 4 &&
       hb_param( 2, HB_IT_NUMERIC ) != NULL &&
       hb_param( 3, HB_IT_INTEGER ) != NULL &&
       hb_param( 4, HB_IT_INTEGER ) != NULL &&
       ( pItem2 = hb_param( 5, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 4 )
   {
      Rectangle rec;

      rec.x      = ( float ) hb_arrayGetND( pItem1, 1 );
      rec.y      = ( float ) hb_arrayGetND( pItem1, 2 );
      rec.width  = ( float ) hb_arrayGetND( pItem1, 3 );
      rec.height = ( float ) hb_arrayGetND( pItem1, 4 );

      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem2, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem2, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem2, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem2, 4 );

      DrawRectangleRoundedLines( rec, ( float ) hb_parnd( 2 ), hb_parni( 3 ), hb_parni( 4 ), color );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawTriangle( Vector2 v1, Vector2 v2, Vector2 v3, Color color );
HB_FUNC( DRAWTRIANGLE )
{
   PHB_ITEM pItem1, pItem2, pItem3, pItem4;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 2 &&
       ( pItem2 = hb_param( 2, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 2 &&
       ( pItem3 = hb_param( 3, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem3 ) == 2 &&
       ( pItem4 = hb_param( 4, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem4 ) == 4 )
   {
      Vector2 v1;

      v1.x = ( float ) hb_arrayGetND( pItem1, 1 );
      v1.y = ( float ) hb_arrayGetND( pItem1, 2 );

      Vector2 v2;

      v2.x = ( float ) hb_arrayGetND( pItem2, 1 );
      v2.y = ( float ) hb_arrayGetND( pItem2, 2 );

      Vector2 v3;

      v3.x = ( float ) hb_arrayGetND( pItem3, 1 );
      v3.y = ( float ) hb_arrayGetND( pItem3, 2 );

      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem4, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem4, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem4, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem4, 4 );

      DrawTriangle( v1, v2, v3, color );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawTriangleLines( Vector2 v1, Vector2 v2, Vector2 v3, Color color );
HB_FUNC( DRAWTRIANGLELINES )
{
   PHB_ITEM pItem1, pItem2, pItem3, pItem4;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 2 &&
       ( pItem2 = hb_param( 2, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 2 &&
       ( pItem3 = hb_param( 3, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem3 ) == 2 &&
       ( pItem4 = hb_param( 4, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem4 ) == 4 )
   {
      Vector2 v1;

      v1.x = ( float ) hb_arrayGetND( pItem1, 1 );
      v1.y = ( float ) hb_arrayGetND( pItem1, 2 );

      Vector2 v2;

      v2.x = ( float ) hb_arrayGetND( pItem2, 1 );
      v2.y = ( float ) hb_arrayGetND( pItem2, 2 );

      Vector2 v3;

      v3.x = ( float ) hb_arrayGetND( pItem3, 1 );
      v3.y = ( float ) hb_arrayGetND( pItem3, 2 );

      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem4, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem4, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem4, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem4, 4 );

      DrawTriangleLines( v1, v2, v3, color );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawTriangleFan( Vector2 *points, int pointsCount, Color color );
HB_FUNC( DRAWTRIANGLEFAN )
{
   PHB_ITEM pItem1, pItem2;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 2 &&
                  hb_param( 2, HB_IT_INTEGER ) != NULL &&
       ( pItem2 = hb_param( 3, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 4 )
   {
      Vector2 points;

      points.x = ( float ) hb_arrayGetND( pItem1, 1 );
      points.y = ( float ) hb_arrayGetND( pItem1, 2 );

      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem2, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem2, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem2, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem2, 4 );

      DrawTriangleFan( &points, hb_parni( 2 ), color );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawTriangleStrip( Vector2 *points, int pointsCount, Color color );
HB_FUNC( DRAWTRIANGLESTRIP )
{
   PHB_ITEM pItem1, pItem2;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 2 &&
                  hb_param( 2, HB_IT_INTEGER ) != NULL &&
       ( pItem2 = hb_param( 3, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 4 )
   {
      Vector2 points;

      points.x = ( float ) hb_arrayGetND( pItem1, 1 );
      points.y = ( float ) hb_arrayGetND( pItem1, 2 );

      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem2, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem2, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem2, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem2, 4 );

      DrawTriangleStrip( &points, hb_parni( 2 ), color );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawPoly( Vector2 center, int sides, float radius, float rotation, Color color );
HB_FUNC( DRAWPOLY )
{
   PHB_ITEM pItem1, pItem2;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 2 &&
                  hb_param( 2, HB_IT_INTEGER ) != NULL &&
                  hb_param( 3, HB_IT_NUMERIC ) != NULL &&
                  hb_param( 4, HB_IT_NUMERIC ) != NULL &&
       ( pItem2 = hb_param( 5, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 4 )
   {
      Vector2 center;

      center.x = ( float ) hb_arrayGetND( pItem1, 1 );
      center.y = ( float ) hb_arrayGetND( pItem1, 2 );

      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem2, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem2, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem2, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem2, 4 );

      DrawPoly( center, hb_parni( 2 ), ( float ) hb_parnd( 3 ), ( float ) hb_parnd( 4 ), color );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawPolyLines( Vector2 center, int sides, float radius, float rotation, Color color );
HB_FUNC( DRAWPOLYLINES )
{
   PHB_ITEM pItem1, pItem2;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 2 &&
                  hb_param( 2, HB_IT_INTEGER ) != NULL &&
                  hb_param( 3, HB_IT_NUMERIC ) != NULL &&
                  hb_param( 4, HB_IT_NUMERIC ) != NULL &&
       ( pItem2 = hb_param( 5, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 4 )
   {
      Vector2 center;

      center.x = ( float ) hb_arrayGetND( pItem1, 1 );
      center.y = ( float ) hb_arrayGetND( pItem1, 2 );

      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem2, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem2, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem2, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem2, 4 );

      DrawPolyLines( center, hb_parni( 2 ), ( float ) hb_parnd( 3 ), ( float ) hb_parnd( 4 ), color );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

/* --- Basic shapes collision detection functions --- */

// bool CheckCollisionRecs( Rectangle rec1, Rectangle rec2 );
HB_FUNC( CHECKCOLLISIONRECS )
{
   PHB_ITEM pItem1, pItem2;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 4 &&
       ( pItem2 = hb_param( 2, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 4 )
   {
      Rectangle rec1;

      rec1.x      = ( float ) hb_arrayGetND( pItem1, 1 );
      rec1.y      = ( float ) hb_arrayGetND( pItem1, 2 );
      rec1.width  = ( float ) hb_arrayGetND( pItem1, 3 );
      rec1.height = ( float ) hb_arrayGetND( pItem1, 4 );

      Rectangle rec2;

      rec2.x      = ( float ) hb_arrayGetND( pItem2, 1 );
      rec2.y      = ( float ) hb_arrayGetND( pItem2, 2 );
      rec2.width  = ( float ) hb_arrayGetND( pItem2, 3 );
      rec2.height = ( float ) hb_arrayGetND( pItem2, 4 );

      hb_retl( CheckCollisionRecs( rec1, rec2 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// bool CheckCollisionCircles( Vector2 center1, float radius1, Vector2 center2, float radius2 );
HB_FUNC( CHECKCOLLISIONCIRCLES )
{
   PHB_ITEM pItem1, pItem2;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 2 &&
                  hb_param( 2, HB_IT_NUMERIC ) != NULL &&
       ( pItem2 = hb_param( 3, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 2 &&
                  hb_param( 2, HB_IT_NUMERIC ) != NULL )
   {
      Vector2 center1;

      center1.x = ( float ) hb_arrayGetND( pItem1, 1 );
      center1.y = ( float ) hb_arrayGetND( pItem1, 2 );

      Vector2 center2;

      center2.x = ( float ) hb_arrayGetND( pItem2, 1 );
      center2.y = ( float ) hb_arrayGetND( pItem2, 2 );

      hb_retl( CheckCollisionCircles( center1, ( float ) hb_parnd( 2 ), center2, ( float ) hb_parnd( 4 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// bool CheckCollisionCircleRec( Vector2 center, float radius, Rectangle rec );
HB_FUNC( CHECKCOLLISIONCIRCLEREC )
{
   PHB_ITEM pItem1, pItem2;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 2 &&
                  hb_param( 2, HB_IT_NUMERIC ) != NULL &&
       ( pItem2 = hb_param( 3, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 4 )
   {
      Vector2 center;

      center.x = ( float ) hb_arrayGetND( pItem1, 1 );
      center.y = ( float ) hb_arrayGetND( pItem1, 2 );

      Rectangle rec;

      rec.x      = ( float ) hb_arrayGetND( pItem2, 1 );
      rec.y      = ( float ) hb_arrayGetND( pItem2, 2 );
      rec.width  = ( float ) hb_arrayGetND( pItem2, 3 );
      rec.height = ( float ) hb_arrayGetND( pItem2, 4 );

      hb_retl( CheckCollisionCircleRec( center, ( float ) hb_parnd( 2 ), rec ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// bool CheckCollisionPointRec( Vector2 point, Rectangle rec );
HB_FUNC( CHECKCOLLISIONPOINTREC )
{
   PHB_ITEM pItem1, pItem2;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 2 &&
       ( pItem2 = hb_param( 2, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 4 )
   {
      Vector2 point;

      point.x = ( float ) hb_arrayGetND( pItem1, 1 );
      point.y = ( float ) hb_arrayGetND( pItem1, 2 );

      Rectangle rec;

      rec.x      = ( float ) hb_arrayGetND( pItem2, 1 );
      rec.y      = ( float ) hb_arrayGetND( pItem2, 2 );
      rec.width  = ( float ) hb_arrayGetND( pItem2, 3 );
      rec.height = ( float ) hb_arrayGetND( pItem2, 4 );

      hb_retl( CheckCollisionPointRec( point, rec ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// bool CheckCollisionPointCircle( Vector2 point, Vector2 center, float radius );
HB_FUNC( CHECKCOLLISIONPOINTCIRCLE )
{
   PHB_ITEM pItem1, pItem2;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 2 &&
       ( pItem2 = hb_param( 2, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 2 &&
                  hb_param( 3, HB_IT_NUMERIC ) != NULL )
   {
      Vector2 point;

      point.x = ( float ) hb_arrayGetND( pItem1, 1 );
      point.y = ( float ) hb_arrayGetND( pItem1, 2 );

      Vector2 center;

      center.x = ( float ) hb_arrayGetND( pItem2, 1 );
      center.y = ( float ) hb_arrayGetND( pItem2, 2 );

      hb_retl( CheckCollisionPointCircle( point, center, ( float ) hb_parnd( 3 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// bool CheckCollisionPointTriangle( Vector2 point, Vector2 p1, Vector2 p2, Vector2 p3 );
HB_FUNC( CHECKCOLLISIONPOINTTRIANGLE )
{
   PHB_ITEM pItem1, pItem2, pItem3, pItem4;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 2 &&
       ( pItem2 = hb_param( 2, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 2 &&
       ( pItem3 = hb_param( 3, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem3 ) == 2 &&
       ( pItem4 = hb_param( 4, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem4 ) == 2 )
   {
      Vector2 point;

      point.x = ( float ) hb_arrayGetND( pItem1, 1 );
      point.y = ( float ) hb_arrayGetND( pItem1, 2 );

      Vector2 p1;

      p1.x = ( float ) hb_arrayGetND( pItem2, 1 );
      p1.y = ( float ) hb_arrayGetND( pItem2, 2 );

      Vector2 p2;

      p2.x = ( float ) hb_arrayGetND( pItem3, 1 );
      p2.y = ( float ) hb_arrayGetND( pItem3, 2 );

      Vector2 p3;

      p3.x = ( float ) hb_arrayGetND( pItem4, 1 );
      p3.y = ( float ) hb_arrayGetND( pItem4, 2 );

      hb_retl( CheckCollisionPointTriangle( point, p1, p2, p3 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// bool CheckCollisionLines( Vector2 startPos1, Vector2 endPos1, Vector2 startPos2, Vector2 endPos2, Vector2 *collisionPoint );
HB_FUNC( CHECKCOLLISIONLINES )
{
   PHB_ITEM pItem1, pItem2, pItem3, pItem4, pItem5;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 2 &&
       ( pItem2 = hb_param( 2, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 2 &&
       ( pItem3 = hb_param( 3, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem3 ) == 2 &&
       ( pItem4 = hb_param( 4, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem4 ) == 2 &&
       ( pItem5 = hb_param( 5, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem5 ) == 2 )
   {
      Vector2 startPos1;

      startPos1.x = ( float ) hb_arrayGetND( pItem1, 1 );
      startPos1.y = ( float ) hb_arrayGetND( pItem1, 2 );

      Vector2 endPos1;

      endPos1.x = ( float ) hb_arrayGetND( pItem2, 1 );
      endPos1.y = ( float ) hb_arrayGetND( pItem2, 2 );

      Vector2 startPos2;

      startPos2.x = ( float ) hb_arrayGetND( pItem3, 1 );
      startPos2.y = ( float ) hb_arrayGetND( pItem3, 2 );

      Vector2 endPos2;

      endPos2.x = ( float ) hb_arrayGetND( pItem4, 1 );
      endPos2.y = ( float ) hb_arrayGetND( pItem4, 2 );

      Vector2 collisionPoint;

      endPos2.x = ( float ) hb_arrayGetND( pItem5, 1 );
      endPos2.y = ( float ) hb_arrayGetND( pItem5, 2 );

      hb_retl( CheckCollisionLines( startPos1, endPos1, startPos2, endPos2, &collisionPoint ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// Rectangle GetCollisionRec( Rectangle rec1, Rectangle rec2 );
HB_FUNC( GETCOLLISIONREC )
{
   PHB_ITEM pItem1, pItem2;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 4 &&
       ( pItem2 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 4 )
   {
      Rectangle rec1;

      rec1.x      = ( float ) hb_arrayGetND( pItem1, 1 );
      rec1.y      = ( float ) hb_arrayGetND( pItem1, 2 );
      rec1.width  = ( float ) hb_arrayGetND( pItem1, 3 );
      rec1.height = ( float ) hb_arrayGetND( pItem1, 4 );

      Rectangle rec2;

      rec2.x      = ( float ) hb_arrayGetND( pItem2, 1 );
      rec2.y      = ( float ) hb_arrayGetND( pItem2, 2 );
      rec2.width  = ( float ) hb_arrayGetND( pItem2, 3 );
      rec2.height = ( float ) hb_arrayGetND( pItem2, 4 );

      Rectangle rec = GetCollisionRec( rec1, rec2 );

      PHB_ITEM info = hb_itemArrayNew( 4 );

      hb_arraySetND( info, 1, ( float ) rec.x );
      hb_arraySetND( info, 2, ( float ) rec.y );
      hb_arraySetND( info, 3, ( float ) rec.width );
      hb_arraySetND( info, 4, ( float ) rec.height );

      hb_itemReturnRelease( info );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}
