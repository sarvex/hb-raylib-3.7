/*
 * RayLib library: core.c
 *
 * Copyright 2020 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbiup.h"

/* --- Image* support --- */
static HB_GARBAGE_FUNC( hb_image_destructor )
{
   void** ppImage = ( void** )Cargo;

   /* Check if pointer is not NULL to avoid multiple freeing */
   if( ppImage && *ppImage )
   {
      /* set pointer to NULL to avoid multiple freeing */
      *ppImage = NULL;
   }
}

static const HB_GC_FUNCS s_gcImageFuncs =
{
   hb_image_destructor,
   hb_gcDummyMark
};

Ihandle* hb_Image_par( int iParam )
{
   void** ppImage = ( void** )hb_parptrGC( &s_gcImageFuncs, iParam );

   return ppImage ? ( Ihandle* ) *ppImage : NULL;
}

void hb_Image_ret( Ihandle* pImage )
{
   if( pImage )
   {
      void** ppImage = ( void** )hb_gcAllocate( sizeof( Ihandle* ), &s_gcImageFuncs );

      *ppImage = pImage;

      hb_retptrGC( ppImage );
   }
   else
   {
      hb_retptr( NULL );
   }
}
