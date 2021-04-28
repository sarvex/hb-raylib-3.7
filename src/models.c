/*
 * RayLib library: models.c
 * version 3.5
 *
 * Copyright 2020 -2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbraylib.h"

//------------------------------------------------------------------------------------
// Basic 3d Shapes Drawing Functions (Module: models)
//------------------------------------------------------------------------------------

// Basic geometric 3D shapes drawing functions

// void DrawLine3D(Vector3 startPos, Vector3 endPos, Color color);                                    // Draw a line in 3D world space
HB_FUNC( DRAWLINE3D )
{
   PHB_ITEM pItem1, pItem2, pItem3;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 3 &&
       ( pItem2 = hb_param( 2, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 3 &&
       ( pItem3 = hb_param( 3, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem3 ) == 4 )
   {
      Vector3 startPos;

      startPos.x = ( float ) hb_arrayGetND( pItem1, 1 );
      startPos.y = ( float ) hb_arrayGetND( pItem1, 2 );
      startPos.z = ( float ) hb_arrayGetND( pItem1, 3 );

      Vector3 endPos;

      endPos.x = ( float ) hb_arrayGetND( pItem2, 1 );
      endPos.y = ( float ) hb_arrayGetND( pItem2, 2 );
      endPos.z = ( float ) hb_arrayGetND( pItem2, 3 );

      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem3, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem3, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem3, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem3, 4 );

      DrawLine3D( startPos, endPos, color );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawPoint3D(Vector3 position, Color color);                                                   // Draw a point in 3D space, actually a small line
HB_FUNC( DRAWPOINT3D )
{
   PHB_ITEM pItem1, pItem2;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 3 &&
       ( pItem2 = hb_param( 2, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 4 )
   {
      Vector3 position;

      position.x = ( float ) hb_arrayGetND( pItem1, 1 );
      position.y = ( float ) hb_arrayGetND( pItem1, 2 );
      position.z = ( float ) hb_arrayGetND( pItem1, 3 );

      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem2, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem2, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem2, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem2, 4 );

      DrawPoint3D( position, color );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawCircle3D(Vector3 center, float radius, Vector3 rotationAxis, float rotationAngle, Color color); // Draw a circle in 3D world space
HB_FUNC( DRAWCIRCLE3D )
{
   PHB_ITEM pItem1, pItem2, pItem3;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 3 &&
                  hb_param( 2, HB_IT_NUMERIC ) != NULL &&
       ( pItem2 = hb_param( 3, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 3 &&
                  hb_param( 4, HB_IT_NUMERIC ) != NULL &&
       ( pItem3 = hb_param( 5, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem3 ) == 4 )
   {
      Vector3 center;

      center.x = ( float ) hb_arrayGetND( pItem1, 1 );
      center.y = ( float ) hb_arrayGetND( pItem1, 2 );
      center.z = ( float ) hb_arrayGetND( pItem1, 3 );

      Vector3 rotationAxis;

      rotationAxis.x = ( float ) hb_arrayGetND( pItem2, 1 );
      rotationAxis.y = ( float ) hb_arrayGetND( pItem2, 2 );
      rotationAxis.z = ( float ) hb_arrayGetND( pItem2, 3 );

      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem3, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem3, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem3, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem3, 4 );

      DrawCircle3D( center, ( float ) hb_parnd( 2 ), rotationAxis, ( float ) hb_parnd( 4 ), color );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawTriangle3D(Vector3 v1, Vector3 v2, Vector3 v3, Color color);                              // Draw a color-filled triangle (vertex in counter-clockwise order!)
HB_FUNC( DRAWTRIANGLE3D )
{
   PHB_ITEM pItem1, pItem2, pItem3, pItem4;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 3 &&
       ( pItem2 = hb_param( 2, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 3 &&
       ( pItem3 = hb_param( 3, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem3 ) == 3 &&
       ( pItem4 = hb_param( 4, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem4 ) == 4 )
   {
      Vector3 v1;

      v1.x = ( float ) hb_arrayGetND( pItem1, 1 );
      v1.y = ( float ) hb_arrayGetND( pItem1, 2 );
      v1.z = ( float ) hb_arrayGetND( pItem1, 3 );

      Vector3 v2;

      v2.x = ( float ) hb_arrayGetND( pItem2, 1 );
      v2.y = ( float ) hb_arrayGetND( pItem2, 2 );
      v2.z = ( float ) hb_arrayGetND( pItem2, 3 );

      Vector3 v3;

      v3.x = ( float ) hb_arrayGetND( pItem3, 1 );
      v3.y = ( float ) hb_arrayGetND( pItem3, 2 );
      v3.z = ( float ) hb_arrayGetND( pItem3, 3 );

      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem4, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem4, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem4, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem4, 4 );

      DrawTriangle3D( v1, v2, v3, color );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawTriangleStrip3D(Vector3 *points, int pointsCount, Color color);                           // Draw a triangle strip defined by points
HB_FUNC( DRAWTRIANGLESTRIP3D )
{
   PHB_ITEM pItem1, pItem2;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 3 &&
                  hb_param( 2, HB_IT_INTEGER ) != NULL &&
       ( pItem2 = hb_param( 3, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 4 )
   {
      Vector3 points;

      points.x = ( float ) hb_arrayGetND( pItem1, 1 );
      points.y = ( float ) hb_arrayGetND( pItem1, 2 );
      points.z = ( float ) hb_arrayGetND( pItem1, 3 );

      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem2, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem2, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem2, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem2, 4 );

      DrawTriangleStrip3D( &points, hb_parni( 2 ), color );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawCube(Vector3 position, float width, float height, float length, Color color);             // Draw cube
HB_FUNC( DRAWCUBE )
{
   PHB_ITEM pItem1, pItem2;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 3 &&
                  hb_param( 2, HB_IT_NUMERIC ) != NULL &&
                  hb_param( 3, HB_IT_NUMERIC ) != NULL &&
                  hb_param( 4, HB_IT_NUMERIC ) != NULL &&
       ( pItem2 = hb_param( 5, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 4 )
   {
      Vector3 position;

      position.x = ( float ) hb_arrayGetND( pItem1, 1 );
      position.y = ( float ) hb_arrayGetND( pItem1, 2 );
      position.z = ( float ) hb_arrayGetND( pItem1, 3 );

      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem2, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem2, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem2, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem2, 4 );

      DrawCube( position, ( float ) hb_parnd( 2 ), ( float ) hb_parnd( 3 ), ( float ) hb_parnd( 4 ), color );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawCubeV(Vector3 position, Vector3 size, Color color);                                       // Draw cube (Vector version)
HB_FUNC( DRAWCUBEV )
{
   PHB_ITEM pItem1, pItem2, pItem3;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 3 &&
       ( pItem2 = hb_param( 2, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 3 &&
       ( pItem3 = hb_param( 3, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem3 ) == 4 )
   {
      Vector3 position;

      position.x = ( float ) hb_arrayGetND( pItem1, 1 );
      position.y = ( float ) hb_arrayGetND( pItem1, 2 );
      position.z = ( float ) hb_arrayGetND( pItem1, 3 );

      Vector3 size;

      size.x = ( float ) hb_arrayGetND( pItem2, 1 );
      size.y = ( float ) hb_arrayGetND( pItem2, 2 );
      size.z = ( float ) hb_arrayGetND( pItem2, 3 );

      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem3, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem3, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem3, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem3, 4 );

      DrawCubeV( position, size, color );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawCubeWires(Vector3 position, float width, float height, float length, Color color);        // Draw cube wires
HB_FUNC( DRAWCUBEWIRES )
{
   PHB_ITEM pItem1, pItem2;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 3 &&
                  hb_param( 2, HB_IT_NUMERIC ) != NULL &&
                  hb_param( 3, HB_IT_NUMERIC ) != NULL &&
                  hb_param( 4, HB_IT_NUMERIC ) != NULL &&
       ( pItem2 = hb_param( 5, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 4 )
   {
      Vector3 position;

      position.x = ( float ) hb_arrayGetND( pItem1, 1 );
      position.y = ( float ) hb_arrayGetND( pItem1, 2 );
      position.z = ( float ) hb_arrayGetND( pItem1, 3 );

      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem2, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem2, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem2, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem2, 4 );

      DrawCubeWires( position, ( float ) hb_parnd( 2 ), ( float ) hb_parnd( 3 ), ( float ) hb_parnd( 4 ), color );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawCubeWiresV(Vector3 position, Vector3 size, Color color);                                  // Draw cube wires (Vector version)
HB_FUNC( DRAWCUBEWIRESV )
{
   PHB_ITEM pItem1, pItem2, pItem3;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 3 &&
       ( pItem2 = hb_param( 2, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 3 &&
       ( pItem3 = hb_param( 3, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem3 ) == 4 )
   {
      Vector3 position;

      position.x = ( float ) hb_arrayGetND( pItem1, 1 );
      position.y = ( float ) hb_arrayGetND( pItem1, 2 );
      position.z = ( float ) hb_arrayGetND( pItem1, 3 );

      Vector3 size;

      size.x = ( float ) hb_arrayGetND( pItem2, 1 );
      size.y = ( float ) hb_arrayGetND( pItem2, 2 );
      size.z = ( float ) hb_arrayGetND( pItem2, 3 );

      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem3, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem3, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem3, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem3, 4 );

      DrawCubeWiresV( position, size, color );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawCubeTexture(Texture2D texture, Vector3 position, float width, float height, float length, Color color); // Draw cube textured
HB_FUNC( DRAWCUBETEXTURE )
{
   PHB_ITEM pItem1, pItem2, pItem3;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 5 &&
       ( pItem2 = hb_param( 2, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 3 &&
                  hb_param( 3, HB_IT_NUMERIC ) != NULL &&
                  hb_param( 4, HB_IT_NUMERIC ) != NULL &&
                  hb_param( 5, HB_IT_NUMERIC ) != NULL &&
       ( pItem3 = hb_param( 6, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem3 ) == 4 )
   {
      Texture2D texture;

      texture.id      = ( unsigned int ) hb_arrayGetNI( pItem1, 1 );
      texture.width   = hb_arrayGetNI( pItem1, 2 );
      texture.height  = hb_arrayGetNI( pItem1, 3 );
      texture.mipmaps = hb_arrayGetNI( pItem1, 4 );
      texture.format  = hb_arrayGetNI( pItem1, 5 );

      Vector3 position;

      position.x = ( float ) hb_arrayGetND( pItem2, 1 );
      position.y = ( float ) hb_arrayGetND( pItem2, 2 );
      position.z = ( float ) hb_arrayGetND( pItem2, 3 );

      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem3, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem3, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem3, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem3, 4 );

      DrawCubeTexture( texture, position, ( float ) hb_parnd( 3 ), ( float ) hb_parnd( 4 ), ( float ) hb_parnd( 5 ), color );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawSphere(Vector3 centerPos, float radius, Color color);                                     // Draw sphere
HB_FUNC( DRAWSPHERE )
{
   PHB_ITEM pItem1, pItem2;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 3 &&
                  hb_param( 2, HB_IT_NUMERIC ) != NULL &&
       ( pItem2 = hb_param( 3, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 4 )
   {
      Vector3 centerPos;

      centerPos.x = ( float ) hb_arrayGetND( pItem1, 1 );
      centerPos.y = ( float ) hb_arrayGetND( pItem1, 2 );
      centerPos.z = ( float ) hb_arrayGetND( pItem1, 3 );

      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem2, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem2, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem2, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem2, 4 );

      DrawSphere( centerPos, ( float ) hb_parnd( 2 ), color );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawSphereEx(Vector3 centerPos, float radius, int rings, int slices, Color color);            // Draw sphere with extended parameters
HB_FUNC( DRAWSPHEREEX )
{
   PHB_ITEM pItem1, pItem2;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 3 &&
                  hb_param( 2, HB_IT_NUMERIC ) != NULL &&
                  hb_param( 3, HB_IT_INTEGER ) != NULL &&
                  hb_param( 4, HB_IT_INTEGER ) != NULL &&
       ( pItem2 = hb_param( 5, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 4 )
   {
      Vector3 centerPos;

      centerPos.x = ( float ) hb_arrayGetND( pItem1, 1 );
      centerPos.y = ( float ) hb_arrayGetND( pItem1, 2 );
      centerPos.z = ( float ) hb_arrayGetND( pItem1, 3 );

      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem2, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem2, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem2, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem2, 4 );

      DrawSphereEx( centerPos, ( float ) hb_parnd( 2 ), hb_parni( 3 ), hb_parni( 4 ), color );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawSphereWires(Vector3 centerPos, float radius, int rings, int slices, Color color);         // Draw sphere wires
HB_FUNC( DRAWSPHEREWIRES )
{
   PHB_ITEM pItem1, pItem2;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 3 &&
                  hb_param( 2, HB_IT_NUMERIC ) != NULL &&
                  hb_param( 3, HB_IT_INTEGER ) != NULL &&
                  hb_param( 4, HB_IT_INTEGER ) != NULL &&
       ( pItem2 = hb_param( 5, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 4 )
   {
      Vector3 centerPos;

      centerPos.x = ( float ) hb_arrayGetND( pItem1, 1 );
      centerPos.y = ( float ) hb_arrayGetND( pItem1, 2 );
      centerPos.z = ( float ) hb_arrayGetND( pItem1, 3 );

      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem2, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem2, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem2, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem2, 4 );

      DrawSphereWires( centerPos, ( float ) hb_parnd( 2 ), hb_parni( 3 ), hb_parni( 4 ), color );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawCylinder(Vector3 position, float radiusTop, float radiusBottom, float height, int slices, Color color); // Draw a cylinder/cone
HB_FUNC( DRAWCYLINDER )
{
   PHB_ITEM pItem1, pItem2;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 3 &&
                  hb_param( 2, HB_IT_NUMERIC ) != NULL &&
                  hb_param( 3, HB_IT_NUMERIC ) != NULL &&
                  hb_param( 4, HB_IT_NUMERIC ) != NULL &&
                  hb_param( 5, HB_IT_INTEGER ) != NULL &&
       ( pItem2 = hb_param( 6, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 4 )
   {
      Vector3 position;

      position.x = ( float ) hb_arrayGetND( pItem1, 1 );
      position.y = ( float ) hb_arrayGetND( pItem1, 2 );
      position.z = ( float ) hb_arrayGetND( pItem1, 3 );

      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem2, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem2, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem2, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem2, 4 );

      DrawCylinder( position, ( float ) hb_parnd( 2 ), ( float ) hb_parnd( 3 ), ( float ) hb_parnd( 4 ), hb_parni( 5 ), color );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawCylinderWires(Vector3 position, float radiusTop, float radiusBottom, float height, int slices, Color color); // Draw a cylinder/cone wires
HB_FUNC( DRAWCYLINDERWIRES )
{
   PHB_ITEM pItem1, pItem2;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 3 &&
                  hb_param( 2, HB_IT_NUMERIC ) != NULL &&
                  hb_param( 3, HB_IT_NUMERIC ) != NULL &&
                  hb_param( 4, HB_IT_NUMERIC ) != NULL &&
                  hb_param( 5, HB_IT_INTEGER ) != NULL &&
       ( pItem2 = hb_param( 6, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 4 )
   {
      Vector3 position;

      position.x = ( float ) hb_arrayGetND( pItem1, 1 );
      position.y = ( float ) hb_arrayGetND( pItem1, 2 );
      position.z = ( float ) hb_arrayGetND( pItem1, 3 );

      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem2, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem2, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem2, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem2, 4 );

      DrawCylinderWires( position, ( float ) hb_parnd( 2 ), ( float ) hb_parnd( 3 ), ( float ) hb_parnd( 4 ), hb_parni( 5 ), color );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawPlane(Vector3 centerPos, Vector2 size, Color color);                                      // Draw a plane XZ
HB_FUNC( DRAWPLANE )
{
   PHB_ITEM pItem1, pItem2, pItem3;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 3 &&
       ( pItem2 = hb_param( 2, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 2 &&
       ( pItem3 = hb_param( 3, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem3 ) == 4 )
   {
      Vector3 centerPos;

      centerPos.x = ( float ) hb_arrayGetND( pItem1, 1 );
      centerPos.y = ( float ) hb_arrayGetND( pItem1, 2 );
      centerPos.z = ( float ) hb_arrayGetND( pItem1, 3 );

      Vector2 size;

      size.x = ( float ) hb_arrayGetND( pItem2, 1 );
      size.y = ( float ) hb_arrayGetND( pItem2, 2 );

      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem3, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem3, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem3, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem3, 4 );

      DrawPlane( centerPos, size, color );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawRay(Ray ray, Color color);                                                                // Draw a ray line
HB_FUNC( DRAWRAY )
{
   PHB_ITEM pItem1, pItem2;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 2 &&
       ( pItem2 = hb_param( 2, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 4 )
   {
      Ray ray;

      // Vector3 position
      PHB_ITEM pSubarray1Vector3 = hb_arrayGetItemPtr( pItem1, 1 );

      ray.position.x = ( float ) hb_arrayGetND( pSubarray1Vector3, 1 );
      ray.position.y = ( float ) hb_arrayGetND( pSubarray1Vector3, 2 );
      ray.position.z = ( float ) hb_arrayGetND( pSubarray1Vector3, 3 );

      // Vector3 direction
      PHB_ITEM pSubarray2Vector3 = hb_arrayGetItemPtr( pItem1, 2 );

      ray.direction.x = ( float ) hb_arrayGetND( pSubarray2Vector3, 1 );
      ray.direction.y = ( float ) hb_arrayGetND( pSubarray2Vector3, 2 );
      ray.direction.z = ( float ) hb_arrayGetND( pSubarray2Vector3, 3 );

      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem2, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem2, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem2, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem2, 4 );

      DrawRay( ray, color );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void DrawGrid(int slices, float spacing);                                                          // Draw a grid (centered at (0, 0, 0))
HB_FUNC( DRAWGRID )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL &&
       hb_param( 2, HB_IT_NUMERIC ) != NULL )
   {
      DrawGrid( hb_parni( 1 ), ( float ) hb_parnd( 2 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

//Model loading/unloading functions
//Model LoadModel(const char *fileName);                                                             // Load model from files (meshes and materials)
//Model LoadModelFromMesh(Mesh mesh);                                                                // Load model from generated mesh (default material)
//void UnloadModel(Model model);                                                                     // Unload model (including meshes) from memory (RAM and/or VRAM)
//void UnloadModelKeepMeshes(Model model);                                                           // Unload model (but not meshes) from memory (RAM and/or VRAM)

//Mesh loading/unloading functions
//void UploadMesh(Mesh *mesh, bool dynamic);                                                         // Upload vertex data into GPU and provided VAO/VBO ids
//void UpdateMeshBuffer(Mesh mesh, int index, void *data, int dataSize, int offset);                  // Update mesh vertex data in GPU for a specific buffer index
//void DrawMesh(Mesh mesh, Material material, Matrix transform);                                     // Draw a 3d mesh with material and transform
//void DrawMeshInstanced(Mesh mesh, Material material, Matrix *transforms, int instances);           // Draw multiple mesh instances with material and different transforms
//void UnloadMesh(Mesh mesh);                                                                        // Unload mesh data from CPU and GPU
//bool ExportMesh(Mesh mesh, const char *fileName);                                                  // Export mesh data to file, returns true on success

//Material loading/unloading functions
//Material *LoadMaterials(const char *fileName, int *materialCount);                                 // Load materials from model file
//Material LoadMaterialDefault(void);                                                                // Load default material (Supports: DIFFUSE, SPECULAR, NORMAL maps)
//void UnloadMaterial(Material material);                                                            // Unload material from GPU memory (VRAM)
//void SetMaterialTexture(Material *material, int mapType, Texture2D texture);                       // Set texture for a material map type (MATERIAL_MAP_DIFFUSE, MATERIAL_MAP_SPECULAR...)
//void SetModelMeshMaterial(Model *model, int meshId, int materialId);                               // Set material for a mesh

//Model animations loading/unloading functions
//ModelAnimation *LoadModelAnimations(const char *fileName, int *animsCount);                        // Load model animations from file
//void UpdateModelAnimation(Model model, ModelAnimation anim, int frame);                            // Update model animation pose
//void UnloadModelAnimation(ModelAnimation anim);                                                    // Unload animation data
//void UnloadModelAnimations(ModelAnimation* animations, unsigned int count);                        // Unload animation array data
//bool IsModelAnimationValid(Model model, ModelAnimation anim);                                      // Check model animation skeleton match

//Mesh generation functions
//Mesh GenMeshPoly(int sides, float radius);                                                         // Generate polygonal mesh
//Mesh GenMeshPlane(float width, float length, int resX, int resZ);                                  // Generate plane mesh (with subdivisions)
//Mesh GenMeshCube(float width, float height, float length);                                         // Generate cuboid mesh
//Mesh GenMeshSphere(float radius, int rings, int slices);                                           // Generate sphere mesh (standard sphere)
//Mesh GenMeshHemiSphere(float radius, int rings, int slices);                                       // Generate half-sphere mesh (no bottom cap)
//Mesh GenMeshCylinder(float radius, float height, int slices);                                      // Generate cylinder mesh
//Mesh GenMeshTorus(float radius, float size, int radSeg, int sides);                                // Generate torus mesh
//Mesh GenMeshKnot(float radius, float size, int radSeg, int sides);                                 // Generate trefoil knot mesh
//Mesh GenMeshHeightmap(Image heightmap, Vector3 size);                                              // Generate heightmap mesh from image data
//Mesh GenMeshCubicmap(Image cubicmap, Vector3 cubeSize);                                            // Generate cubes-based map mesh from image data

//Mesh manipulation functions
//BoundingBox MeshBoundingBox(Mesh mesh);                                                            // Compute mesh bounding box limits
//void MeshTangents(Mesh *mesh);                                                                     // Compute mesh tangents
//void MeshBinormals(Mesh *mesh);                                                                    // Compute mesh binormals

//Model drawing functions
//void DrawModel(Model model, Vector3 position, float scale, Color tint);                            // Draw a model (with texture if set)
//void DrawModelEx(Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint); // Draw a model with extended parameters
//void DrawModelWires(Model model, Vector3 position, float scale, Color tint);                       // Draw a model wires (with texture if set)
//void DrawModelWiresEx(Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint); // Draw a model wires (with texture if set) with extended parameters
//void DrawBoundingBox(BoundingBox box, Color color);                                                // Draw bounding box (wires)
//void DrawBillboard(Camera camera, Texture2D texture, Vector3 center, float size, Color tint);      // Draw a billboard texture
//void DrawBillboardRec(Camera camera, Texture2D texture, Rectangle source, Vector3 center, float size, Color tint); // Draw a billboard texture defined by source

//Collision detection functions
//bool CheckCollisionSpheres(Vector3 center1, float radius1, Vector3 center2, float radius2);        // Detect collision between two spheres
//bool CheckCollisionBoxes(BoundingBox box1, BoundingBox box2);                                      // Detect collision between two bounding boxes
//bool CheckCollisionBoxSphere(BoundingBox box, Vector3 center, float radius);                       // Detect collision between box and sphere
//bool CheckCollisionRaySphere(Ray ray, Vector3 center, float radius);                               // Detect collision between ray and sphere
//bool CheckCollisionRaySphereEx(Ray ray, Vector3 center, float radius, Vector3 *collisionPoint);    // Detect collision between ray and sphere, returns collision point
//bool CheckCollisionRayBox(Ray ray, BoundingBox box);                                               // Detect collision between ray and box
//RayHitInfo GetCollisionRayMesh(Ray ray, Mesh mesh, Matrix transform);                              // Get collision info between ray and mesh
//RayHitInfo GetCollisionRayModel(Ray ray, Model model);                                             // Get collision info between ray and model
//RayHitInfo GetCollisionRayTriangle(Ray ray, Vector3 p1, Vector3 p2, Vector3 p3);                   // Get collision info between ray and triangle
//RayHitInfo GetCollisionRayGround(Ray ray, float groundHeight);                                     // Get collision info between ray and ground plane (Y-normal plane)
