/*
 * RayLib library: core.c
 * version 3.7
 *
 * Copyright 2020 - 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbraylib.h"

/* --- Image* support --- */
static HB_GARBAGE_FUNC( hb_image_destructor )
{
   Image ** ppImage = ( Image ** ) Cargo;

   if( *ppImage )
   {
      *ppImage = NULL;
   }
}

static const HB_GC_FUNCS s_gcImageFuncs =
{
   hb_image_destructor,
   hb_gcDummyMark
};

Image * hb_image_param( int iParam )
{
   Image ** ppImage = ( Image ** ) hb_parptrGC( &s_gcImageFuncs, iParam );

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
