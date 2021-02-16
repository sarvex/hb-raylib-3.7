/*
 * RayLib library: shapes.c
 *
 * Copyright 2020 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbraylib.h"

/* --- Basic shapes drawing functions --- */

// void DrawPixel( int posX, int posY, Color color );
HB_FUNC( DRAWPIXEL )
{
   PHB_ITEM pItem;

   if( hb_param( 1, HB_IT_INTEGER ) != NULL && hb_param( 2, HB_IT_INTEGER ) != NULL && ( pItem = hb_param( 3, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 4 )
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

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 2 && ( pItem2 = hb_param( 2, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 4 )
   {
      Vector2 position;

      position.x = hb_arrayGetNI( pItem1, 1 );
      position.y = hb_arrayGetNI( pItem1, 2 );

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

      startPos.x = hb_arrayGetNI( pItem1, 1 );
      startPos.y = hb_arrayGetNI( pItem1, 2 );

      Vector2 endPos;

      endPos.x = hb_arrayGetNI( pItem2, 1 );
      endPos.y = hb_arrayGetNI( pItem2, 2 );

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
         hb_param( 3, HB_IT_INTEGER ) != NULL &&
       ( pItem3 = hb_param( 4, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem3 ) == 4 )
   {
      Vector2 startPos;

      startPos.x = hb_arrayGetNI( pItem1, 1 );
      startPos.y = hb_arrayGetNI( pItem1, 2 );

      Vector2 endPos;

      endPos.x = hb_arrayGetNI( pItem2, 1 );
      endPos.y = hb_arrayGetNI( pItem2, 2 );

      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem3, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem3, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem3, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem3, 4 );

      DrawLineEx( startPos, endPos, hb_parni( 3 ), color );
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
         hb_param( 3, HB_IT_INTEGER ) != NULL &&
       ( pItem3 = hb_param( 4, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem3 ) == 4 )
   {
      Vector2 startPos;

      startPos.x = hb_arrayGetNI( pItem1, 1 );
      startPos.y = hb_arrayGetNI( pItem1, 2 );

      Vector2 endPos;

      endPos.x = hb_arrayGetNI( pItem2, 1 );
      endPos.y = hb_arrayGetNI( pItem2, 2 );

      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem3, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem3, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem3, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem3, 4 );

      DrawLineBezier( startPos, endPos, hb_parni( 3 ), color );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawLineStrip( Vector2 *points, int numPoints, Color color );
HB_FUNC( DRAWLINESTRIP )
{
   PHB_ITEM pItem1, pItem2;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 2 &&
         hb_param( 2, HB_IT_INTEGER ) != NULL &&
       ( pItem2 = hb_param( 3, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 4 )
   {
      Vector2 points;

      points.x = hb_arrayGetNI( pItem1, 1 );
      points.y = hb_arrayGetNI( pItem1, 2 );

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

   if( hb_param( 1, HB_IT_INTEGER ) != NULL && hb_param( 2, HB_IT_INTEGER ) != NULL && hb_param( 3, HB_IT_INTEGER ) != NULL &&
       ( pItem = hb_param( 4, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 4 )
   {
      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem, 4 );

      DrawCircle( hb_parni( 1 ), hb_parni( 2 ), hb_parni( 3 ), color );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawCircleSector( Vector2 center, float radius, int startAngle, int endAngle, int segments, Color color );
HB_FUNC( DRAWCIRCLESECTOR )
{
   PHB_ITEM pItem1, pItem2;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 2 &&
         hb_param( 2, HB_IT_INTEGER ) != NULL &&
         hb_param( 3, HB_IT_INTEGER ) != NULL &&
         hb_param( 4, HB_IT_INTEGER ) != NULL &&
         hb_param( 5, HB_IT_INTEGER ) != NULL &&
       ( pItem2 = hb_param( 6, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 4 )
   {
      Vector2 center;

      center.x = hb_arrayGetNI( pItem1, 1 );
      center.y = hb_arrayGetNI( pItem1, 2 );

      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem2, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem2, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem2, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem2, 4 );

      DrawCircleSector( center, hb_parni( 2 ), hb_parni( 3 ), hb_parni( 4 ), hb_parni( 5 ), color );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawCircleSectorLines( Vector2 center, float radius, int startAngle, int endAngle, int segments, Color color );
HB_FUNC( DRAWCIRCLESECTORLINES )
{
  PHB_ITEM pItem1, pItem2;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 2 &&
         hb_param( 2, HB_IT_INTEGER ) != NULL &&
         hb_param( 3, HB_IT_INTEGER ) != NULL &&
         hb_param( 4, HB_IT_INTEGER ) != NULL &&
         hb_param( 5, HB_IT_INTEGER ) != NULL &&
       ( pItem2 = hb_param( 6, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 4 )
   {
      Vector2 center;

      center.x = hb_arrayGetNI( pItem1, 1 );
      center.y = hb_arrayGetNI( pItem1, 2 );

      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem2, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem2, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem2, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem2, 4 );

      DrawCircleSectorLines( center, hb_parni( 2 ), hb_parni( 3 ), hb_parni( 4 ), hb_parni( 5 ), color );
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
         hb_param( 3, HB_IT_INTEGER ) != NULL &&
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

      DrawCircleGradient( hb_parni( 1 ), hb_parni( 2 ), hb_parni( 3 ), color1, color2 );
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

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 2 && hb_param( 2, HB_IT_INTEGER ) != NULL &&
      ( pItem2 = hb_param( 3, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 4 )
   {
      Vector2 center;

      center.x = hb_arrayGetNI( pItem1, 1 );
      center.y = hb_arrayGetNI( pItem1, 2 );

      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem2, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem2, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem2, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem2, 4 );

      DrawCircleV( center, hb_parni( 2 ), color );
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
      hb_param( 3, HB_IT_INTEGER ) != NULL &&
      ( pItem = hb_param( 4, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 4 )
   {
      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem, 4 );

      DrawCircleLines( hb_parni( 1 ), hb_parni( 2 ), hb_parni( 3 ), color );
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
      hb_param( 3, HB_IT_INTEGER ) != NULL &&
      hb_param( 4, HB_IT_INTEGER ) != NULL &&
      ( pItem = hb_param( 5, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 4 )
   {
      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem, 4 );

      DrawEllipse( hb_parni( 1 ), hb_parni( 2 ), hb_parni( 3 ), hb_parni( 4 ), color );
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
      hb_param( 3, HB_IT_INTEGER ) != NULL &&
      hb_param( 4, HB_IT_INTEGER ) != NULL &&
      ( pItem = hb_param( 5, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 4 )
   {
      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem, 4 );

      DrawEllipseLines( hb_parni( 1 ), hb_parni( 2 ), hb_parni( 3 ), hb_parni( 4 ), color );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawRing( Vector2 center, float innerRadius, float outerRadius, int startAngle, int endAngle, int segments, Color color );
HB_FUNC( DRAWRING )
{
   PHB_ITEM pItem1, pItem2;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 2 &&
      hb_param( 2, HB_IT_INTEGER ) != NULL &&
      hb_param( 3, HB_IT_INTEGER ) != NULL &&
      hb_param( 4, HB_IT_INTEGER ) != NULL &&
      hb_param( 5, HB_IT_INTEGER ) != NULL &&
      hb_param( 6, HB_IT_INTEGER ) != NULL &&
      ( pItem2 = hb_param( 7, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 4 )
   {
      Vector2 center;

      center.x = hb_arrayGetNI( pItem1, 1 );
      center.y = hb_arrayGetNI( pItem1, 2 );

      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem2, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem2, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem2, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem2, 4 );

      DrawRing( center, hb_parni( 2 ), hb_parni( 3 ), hb_parni( 4 ), hb_parni( 5 ), hb_parni( 6 ), color );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawRingLines( Vector2 center, float innerRadius, float outerRadius, int startAngle, int endAngle, int segments, Color color );
HB_FUNC( DRAWRINGLINES )
{
   PHB_ITEM pItem1, pItem2;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 2 &&
      hb_param( 2, HB_IT_INTEGER ) != NULL &&
      hb_param( 3, HB_IT_INTEGER ) != NULL &&
      hb_param( 4, HB_IT_INTEGER ) != NULL &&
      hb_param( 5, HB_IT_INTEGER ) != NULL &&
      hb_param( 6, HB_IT_INTEGER ) != NULL &&
      ( pItem2 = hb_param( 7, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 4 )
   {
      Vector2 center;

      center.x = hb_arrayGetNI( pItem1, 1 );
      center.y = hb_arrayGetNI( pItem1, 2 );

      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem2, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem2, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem2, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem2, 4 );

      DrawRingLines( center, hb_parni( 2 ), hb_parni( 3 ), hb_parni( 4 ), hb_parni( 5 ), hb_parni( 6 ), color );
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
      ( pItem2 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 2 &&
      ( pItem3 = hb_param( 7, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem3 ) == 4 )
   {
      Vector2 position;

      position.x = hb_arrayGetNI( pItem1, 1 );
      position.y = hb_arrayGetNI( pItem1, 2 );

      Vector2 size;

      size.x = hb_arrayGetNI( pItem2, 1 );
      size.y = hb_arrayGetNI( pItem2, 2 );

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

      rec.x      = hb_arrayGetNI( pItem1, 1 );
      rec.y      = hb_arrayGetNI( pItem1, 2 );
      rec.width  = hb_arrayGetNI( pItem1, 3 );
      rec.height = hb_arrayGetNI( pItem1, 4 );

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
// void DrawRectangleGradientV( int posX, int posY, int width, int height, Color color1, Color color2 );
// void DrawRectangleGradientH( int posX, int posY, int width, int height, Color color1, Color color2 );
// void DrawRectangleGradientEx( Rectangle rec, Color col1, Color col2, Color col3, Color col4 );
// void DrawRectangleLines( int posX, int posY, int width, int height, Color color );
// void DrawRectangleLinesEx( Rectangle rec, int lineThick, Color color );
// void DrawRectangleRounded( Rectangle rec, float roundness, int segments, Color color );
// void DrawRectangleRoundedLines( Rectangle rec, float roundness, int segments, int lineThick, Color color );
// void DrawTriangle( Vector2 v1, Vector2 v2, Vector2 v3, Color color );
// void DrawTriangleLines( Vector2 v1, Vector2 v2, Vector2 v3, Color color );
// void DrawTriangleFan( Vector2 *points, int numPoints, Color color );
// void DrawTriangleStrip( Vector2 *points, int pointsCount, Color color );
// void DrawPoly( Vector2 center, int sides, float radius, float rotation, Color color );
// void DrawPolyLines( Vector2 center, int sides, float radius, float rotation, Color color );

/* --- Basic shapes collision detection functions --- */
// bool CheckCollisionRecs( Rectangle rec1, Rectangle rec2 );
// bool CheckCollisionCircles( Vector2 center1, float radius1, Vector2 center2, float radius2 );
// bool CheckCollisionCircleRec( Vector2 center, float radius, Rectangle rec );
// Rectangle GetCollisionRec( Rectangle rec1, Rectangle rec2 );
// bool CheckCollisionPointRec( Vector2 point, Rectangle rec );
// bool CheckCollisionPointCircle( Vector2 point, Vector2 center, float radius );
// bool CheckCollisionPointTriangle( Vector2 point, Vector2 p1, Vector2 p2, Vector2 p3 );
