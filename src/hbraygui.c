/*
 * RayLib library: hbraylib.c
 * version 3.5
 *
 * Copyright 2020 - 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbraylib.h"

// bool GuiWindowBox(Rectangle bounds, const char *title);                                       // Window Box control, shows a window that can be closed
HB_FUNC( GUIWINDOWBOX )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 4 && hb_param( 2, HB_IT_STRING ) != NULL )
   {
      Rectangle bounds;

      bounds.x      = ( float ) hb_arrayGetND( pItem, 1 );
      bounds.y      = ( float ) hb_arrayGetND( pItem, 2 );
      bounds.width  = ( float ) hb_arrayGetND( pItem, 3 );
      bounds.height = ( float ) hb_arrayGetND( pItem, 4 );

      hb_retl( GuiWindowBox( bounds, hb_parc( 2 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }

}
