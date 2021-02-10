/*
 * RayLib library: core.c
 *
 * Copyright 2020 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbraylib.h"

/* --- Image* support --- */
static HB_GARBAGE_FUNC( hb_raylib_destructor )
{
   Image ** ppImage = ( Image ** ) Cargo;

   if( *ppImage )
   {
      *ppImage = NULL;
   }
}

static const HB_GC_FUNCS s_gcRaylibFuncs =
{
   hb_raylib_destructor,
   hb_gcDummyMark
};

Image * hb_raylib_param( int iParam )
{
   Image ** ppImage = ( Image ** ) hb_parptrGC( &s_gcRaylibFuncs, iParam );

   if( ppImage && *ppImage )
   {
      return *ppImage;
   }
   else
   {
   hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   return NULL;
   }
}
