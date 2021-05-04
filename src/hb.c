/*
 * RayLib library: hb.c
 * version 3.7
 *
 * Copyright 2020 - 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbraylib.h"

HB_FUNC( LTON )
{
   hb_retni( hb_parl( 1 ) );
}

HB_FUNC( NTOL )
{
   hb_retl( hb_parni( 1 ) );
}

HB_FUNC( INTTOF )
{
   hb_retnd( ( float ) hb_parni( 1 ) );
}
