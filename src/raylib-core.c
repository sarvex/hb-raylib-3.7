/*
 * RayLib library: raylib-core.
 *
 * Copyright 2020 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbraylib.h"

/* --- Window-related functions --- */

// void InitWindow( int width, int height, const char *title );
HB_FUNC( INITWINDOW )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL && hb_param( 2, HB_IT_INTEGER ) != NULL && hb_param( 3, HB_IT_STRING ) != NULL )
   {
      InitWindow( hb_parni( 1 ), hb_parni( 2 ), hb_parc( 3 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// bool WindowShouldClose( void );
HB_FUNC( WINDOWSHOULDCLOSE )
{
   hb_retl( WindowShouldClose() );
}

// void CloseWindow( void );
HB_FUNC( CLOSEWINDOW )
{
   CloseWindow();
}

// bool IsWindowReady( void );
HB_FUNC( ISWINDOWREADY )
{
   hb_retl( IsWindowReady() );
}

// bool IsWindowMinimized( void );
HB_FUNC( ISWINDOWMINIMIZED )
{
   hb_retl( IsWindowMinimized() );
}

// bool IsWindowResized( void );
HB_FUNC( ISWINDOWRESIZED )
{
   hb_retl( IsWindowResized() );
}

// bool IsWindowHidden( void );
HB_FUNC( ISWINDOWHIDDEN )
{
   hb_retl( IsWindowHidden() );
}

// bool IsWindowFullscreen( void );
HB_FUNC( ISWINDOWFULLSCREEN )
{
   hb_retl( IsWindowFullscreen() );
}

// void ToggleFullscreen( void );
HB_FUNC( TOGGLEFULLSCREEN )
{
   ToggleFullscreen();
}

// void UnhideWindow( void );
HB_FUNC( UNHIDEWINDOW )
{
   UnhideWindow();
}

// void HideWindow( void );
HB_FUNC( HIDEWINDOW )
{
   HideWindow();
}

// void SetWindowIcon( Image image );
HB_FUNC( SETWINDOWICON )
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

      SetWindowIcon( image );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void SetWindowTitle( const char *title );
HB_FUNC( SETWINDOWTITLE )
{
   if( hb_param( 1, HB_IT_STRING ) != NULL )
   {
      SetWindowTitle( hb_parc( 1 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void SetWindowPosition( int x, int y );
HB_FUNC( SETWINDOWPOSITION )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL && hb_param( 2, HB_IT_INTEGER ) != NULL )
   {
      SetWindowPosition( hb_parni( 1 ), hb_parni( 2 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void SetWindowMonitor( int monitor );
HB_FUNC( SETWINDOWMONITOR )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL )
   {
      SetWindowMonitor( hb_parni( 1 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void SetWindowMinSize( int width, int height );
HB_FUNC( SETWINDOWMINSIZE )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL && hb_param( 2, HB_IT_INTEGER ) != NULL )
   {
      SetWindowMinSize( hb_parni( 1 ), hb_parni( 2 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void SetWindowSize( int width, int height );
HB_FUNC( SETWINDOWSIZE )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL && hb_param( 2, HB_IT_INTEGER ) != NULL )
   {
      SetWindowSize( hb_parni( 1 ), hb_parni( 2 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void *GetWindowHandle( void );
HB_FUNC( GETWINDOWHANDLE )
{
   hb_retptr( GetWindowHandle() );
}

// int GetScreenWidth( void );
HB_FUNC( GETSCREENWIDTH )
{
   hb_retni( GetScreenWidth() );
}

// int GetScreenHeight( void );
HB_FUNC( GETSCREENHEIGHT )
{
   hb_retni( GetScreenHeight() );
}

// int GetMonitorCount( void );
HB_FUNC( GETMONITORCOUNT )
{
   hb_retni( GetMonitorCount() );
}

// int GetMonitorWidth( int monitor );
HB_FUNC( GETMONITORWIDTH )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL )
   {
      hb_retni( GetMonitorWidth( hb_parni( 1 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// int GetMonitorHeight( int monitor );
HB_FUNC( GETMONITORHEIGHT )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL )
   {
      hb_retni( GetMonitorHeight( hb_parni( 1 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// int GetMonitorPhysicalWidth( int monitor );
HB_FUNC( GETMONITORPHYSICALWIDTH )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL )
   {
      hb_retni( GetMonitorPhysicalWidth( hb_parni( 1 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// int GetMonitorPhysicalHeight( int monitor );
HB_FUNC( GETMONITORPHYSICALHEIGHT )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL )
   {
      hb_retni( GetMonitorPhysicalHeight( hb_parni( 1 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// Vector2 GetWindowPosition( void );
HB_FUNC( GETWINDOWPOSITION )
{
   PHB_ITEM info = hb_itemArrayNew( 2 );

   Vector2 vector2 = GetWindowPosition();

   hb_arraySetNI( info, 1, vector2.x );
   hb_arraySetNI( info, 2, vector2.y );

   hb_itemReturnRelease( info );
}

// const char *GetMonitorName( int monitor );
HB_FUNC( GETMONITORNAME )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL )
   {
      hb_retc( GetMonitorName( hb_parni( 1 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// const char *GetClipboardText( void );
HB_FUNC( GETCLIPBOARDTEXT )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL )
   {
      hb_retc( GetClipboardText() );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void SetClipboardText( const char *text );
HB_FUNC( SETCLIPBOARDTEXT )
{
   if( hb_param( 1, HB_IT_STRING ) != NULL )
   {
      SetClipboardText( hb_parc( 1 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

/* --- Cursor-related functions --- */

// void ShowCursor( void );
HB_FUNC( SHOWCURSOR )
{
   ShowCursor();
}

// void HideCursor( void );
HB_FUNC( HIDECURSOR )
{
   HideCursor();
}

// bool IsCursorHidden( void );
HB_FUNC( ISCURSORHIDDEN )
{
   hb_retl( IsCursorHidden() );
}

// void EnableCursor( void );
HB_FUNC( ENABLECURSOR )
{
   EnableCursor();
}

// void DisableCursor( void );
HB_FUNC( DISABLECURSOR )
{
   DisableCursor();
}

/* --- Drawing-related functions --- */

// void ClearBackground( Color color );
HB_FUNC( CLEARBACKGROUND )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 4 )
   {
      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem, 4 );

      ClearBackground( color );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void BeginDrawing( void );
HB_FUNC( BEGINDRAWING )
{
   BeginDrawing();
}

// void EndDrawing( void );
HB_FUNC( ENDDRAWING )
{
   EndDrawing();
}

// void BeginMode2D( Camera2D camera );
// void EndMode2D( void );
// void BeginMode3D( Camera3D camera );
// void EndMode3D( void );
// void BeginTextureMode( RenderTexture2D target );
// void EndTextureMode( void );
// void BeginScissorMode( int x, int y, int width, int height );
// void EndScissorMode( void );

/* --- Screen-space-related functions --- */

// Ray GetMouseRay( Vector2 mousePosition, Camera camera );
// Matrix GetCameraMatrix( Camera camera );
// Matrix GetCameraMatrix2D( Camera2D camera );
// Vector2 GetWorldToScreen( Vector3 position, Camera camera );
// Vector2 GetWorldToScreenEx( Vector3 position, Camera camera,int width, int height );
// Vector2 GetWorldToScreen2D( Vector2 position, Camera2D camera );
// Vector2 GetScreenToWorld2D( Vector2 position, Camera2D camera );

/* --- Timing-related functions --- */

// void SetTargetFPS( int fps );
HB_FUNC( SETTARGETFPS )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL )
   {
      SetTargetFPS( hb_parni( 1 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// int GetFPS( void );
HB_FUNC( GETFPS )
{
   hb_retni( GetFPS() );
}
// float GetFrameTime( void );

// double GetTime( void );

/* --- Color-related functions --- */

// int ColorToInt( Color color );
HB_FUNC( COLORTOINT )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 4 )
   {
      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem, 4 );

      hb_retni( ColorToInt( color ) );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// Vector4 ColorNormalize( Color color );

// Color ColorFromNormalized( Vector4 normalized );

// Vector3 ColorToHSV( Color color );
HB_FUNC( COLORTOHSV )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 4 )
   {
      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem, 4 );

      Vector3 vector3 = ColorToHSV( color );

      PHB_ITEM info = hb_itemArrayNew( 3 );

      hb_arraySetND( info, 1, ( float ) vector3.x );
      hb_arraySetND( info, 2, ( float ) vector3.y );
      hb_arraySetND( info, 3, ( float ) vector3.z );

      hb_itemReturnRelease( info );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// Color ColorFromHSV( Vector3 hsv );
HB_FUNC( COLORFROMHSV )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 3 )
   {
      Vector3 hsv;

      hsv.x = ( float ) hb_arrayGetND( pItem, 1 );
      hsv.y = ( float ) hb_arrayGetND( pItem, 2 );
      hsv.z = ( float ) hb_arrayGetND( pItem, 3 );

      Color color = ColorFromHSV( hsv );

      PHB_ITEM info = hb_itemArrayNew( 4 );

      hb_arraySetNI( info, 1, ( unsigned char ) color.r );
      hb_arraySetNI( info, 2, ( unsigned char ) color.g );
      hb_arraySetNI( info, 3, ( unsigned char ) color.b );
      hb_arraySetNI( info, 4, ( unsigned char ) color.a );

      hb_itemReturnRelease( info );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// Color GetColor( int hexValue );
HB_FUNC( GETCOLOR )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL )
   {
      Color color = GetColor( hb_parni( 1 ) );

      PHB_ITEM info = hb_itemArrayNew( 4 );

      hb_arraySetNI( info, 1, ( unsigned char ) color.r );
      hb_arraySetNI( info, 2, ( unsigned char ) color.g );
      hb_arraySetNI( info, 3, ( unsigned char ) color.b );
      hb_arraySetNI( info, 4, ( unsigned char ) color.a );

      hb_itemReturnRelease( info );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// Color Fade( Color color, float alpha );
HB_FUNC( FADE )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 4 && hb_param( 2, HB_IT_DOUBLE ) != NULL )
   {
      Color color;

      color.r = ( unsigned char ) hb_arrayGetNI( pItem, 1 );
      color.g = ( unsigned char ) hb_arrayGetNI( pItem, 2 );
      color.b = ( unsigned char ) hb_arrayGetNI( pItem, 3 );
      color.a = ( unsigned char ) hb_arrayGetNI( pItem, 4 );

      Color ret = Fade( color, hb_parnd( 2 ) );

      PHB_ITEM info = hb_itemArrayNew( 4 );

      hb_arraySetNI( info, 1, ( unsigned char ) ret.r );
      hb_arraySetNI( info, 2, ( unsigned char ) ret.g );
      hb_arraySetNI( info, 3, ( unsigned char ) ret.b );
      hb_arraySetNI( info, 4, ( unsigned char ) ret.a );

      hb_itemReturnRelease( info );
   }
   else
   {
      hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

/* --- Misc. functions --- */

// void SetConfigFlags( unsigned int flags );
HB_FUNC( SETCONFIGFLAGS )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL )
   {
      SetConfigFlags( hb_parni( 1 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void SetTraceLogLevel( int logType );
// void SetTraceLogExit( int logType );
// void SetTraceLogCallback( TraceLogCallback callback );
// void TraceLog( int logType, const char *text, ...  );
// void TakeScreenshot( const char *fileName );

// int GetRandomValue( int min, int max );
HB_FUNC( GETRANDOMVALUE )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL && hb_param( 2, HB_IT_INTEGER ) != NULL )
   {
      hb_retni( GetRandomValue( hb_parni( 1 ), hb_parni( 2 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

/* --- Files management functions --- */

// unsigned char *LoadFileData( const char *fileName, int *bytesRead );
// void SaveFileData( const char *fileName, void *data, int bytesToWrite );
// char *LoadFileText( const char *fileName );
// void SaveFileText( const char *fileName, char *text );
// bool FileExists( const char *fileName );
// bool IsFileExtension( const char *fileName, const char *ext );
// bool DirectoryExists( const char *dirPath );
// const char *GetExtension( const char *fileName );
// const char *GetFileName( const char *filePath );
// const char *GetFileNameWithoutExt( const char *filePath );
// const char *GetDirectoryPath( const char *filePath );
// const char *GetPrevDirectoryPath( const char *dirPath );
// const char *GetWorkingDirectory( void );
// char **GetDirectoryFiles( const char *dirPath, int *count );
// void ClearDirectoryFiles( void );
// bool ChangeDirectory( const char *dir );
// bool IsFileDropped( void );
// char **GetDroppedFiles( int *count );
// void ClearDroppedFiles( void );
// long GetFileModTime( const char *fileName );

// unsigned char *CompressData( unsigned char *data, int dataLength, int *compDataLength );
// unsigned char *DecompressData( unsigned char *compData, int compDataLength, int *dataLength );

/* --- Persistent storage management --- */

// int LoadStorageValue( int position );
// void SaveStorageValue( int position, int value );

// void OpenURL( const char *url );

//------------------------------------------------------------------------------------
// Input Handling Functions
//------------------------------------------------------------------------------------

/* --- Input-related functions: keyb --- */

// bool IsKeyPressed( int key );
HB_FUNC( ISKEYPRESSED )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL )
   {
      hb_retl( IsKeyPressed( hb_parni( 1 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// bool IsKeyDown( int key );
HB_FUNC( ISKEYDOWN )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL )
   {
      hb_retl( IsKeyDown( hb_parni( 1 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// bool IsKeyReleased( int key );
HB_FUNC( ISKEYRELEASED )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL )
   {
      hb_retl( IsKeyReleased( hb_parni( 1 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// bool IsKeyUp( int key );
HB_FUNC( ISKEYUP )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL )
   {
      hb_retl( IsKeyUp( hb_parni( 1 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// int GetKeyPressed( void );
HB_FUNC( GETKEYPRESSED )
{
   hb_retni( GetKeyPressed() );
}

// void SetExitKey( int key );
HB_FUNC( SETEXITKEY )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL )
   {
      SetExitKey( hb_parni( 1 ) ) ;
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

/* --- Input-related functions: gamepads --- */

// bool IsGamepadAvailable( int gamepad );
// bool IsGamepadName( int gamepad, const char *name );
// const char *GetGamepadName( int gamepad );
// bool IsGamepadButtonPressed( int gamepad, int button );
// bool IsGamepadButtonDown( int gamepad, int button );
// bool IsGamepadButtonReleased( int gamepad, int button );
// bool IsGamepadButtonUp( int gamepad, int button );
// int GetGamepadButtonPressed( void );
// int GetGamepadAxisCount( int gamepad );
// float GetGamepadAxisMovement( int gamepad, int axis );

/* --- Input-related functions: mouse --- */

// bool IsMouseButtonPressed( int button );
HB_FUNC( ISMOUSEBUTTONPRESSED )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL )
   {
      hb_retl( IsMouseButtonPressed( hb_parni( 1 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// bool IsMouseButtonDown( int button );
HB_FUNC( ISMOUSEBUTTONDOWN )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL )
   {
      hb_retl( IsMouseButtonDown( hb_parni( 1 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// bool IsMouseButtonReleased( int button );
HB_FUNC( ISMOUSEBUTTONRELEASED )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL )
   {
      hb_retl( IsMouseButtonReleased( hb_parni( 1 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// bool IsMouseButtonUp( int button );
HB_FUNC( ISMOUSEBUTTONUP )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL )
   {
      hb_retl( IsMouseButtonUp( hb_parni( 1 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// int GetMouseX( void );
HB_FUNC( GETMOUSEX )
{
   hb_retni( GetMouseX() );
}

// int GetMouseY( void );
HB_FUNC( GETMOUSEY )
{
   hb_retni( GetMouseY() );
}

// Vector2 GetMousePosition( void );
HB_FUNC( GETMOUSEPOSITION )
{
   PHB_ITEM info = hb_itemArrayNew( 2 );

   Vector2 vector2 = GetMousePosition();

   hb_arraySetNI( info, 1, vector2.x );
   hb_arraySetNI( info, 2, vector2.y );

   hb_itemReturnRelease( info );
}

// void SetMousePosition( int x, int y );
HB_FUNC( SETMOUSEPOSITION )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL && hb_param( 2, HB_IT_INTEGER ) != NULL )
   {
      SetMousePosition( hb_parni( 1 ), hb_parni( 2 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void SetMouseOffset( int offsetX, int offsetY );
HB_FUNC( SETMOUSEOFFSET )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL && hb_param( 2, HB_IT_INTEGER ) != NULL )
   {
      SetMouseOffset( hb_parni( 1 ), hb_parni( 2 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void SetMouseScale( float scaleX, float scaleY );
// int GetMouseWheelMove( void );

/* --- Input-related functions: touch --- */

// int GetTouchX( void );
// int GetTouchY( void );
// Vector2 GetTouchPosition( int index );

//------------------------------------------------------------------------------------
// Gestures and Touch Handling Functions ( Module: gestures )
//------------------------------------------------------------------------------------

// void SetGesturesEnabled( unsigned int gestureFlags );
// bool IsGestureDetected( int gesture );
// int GetGestureDetected( void );
// int GetTouchPointsCount( void );
// float GetGestureHoldDuration( void );
// Vector2 GetGestureDragVector( void );
// float GetGestureDragAngle( void );
// Vector2 GetGesturePinchVector( void );
// float GetGesturePinchAngle( void );

//------------------------------------------------------------------------------------
// Camera System Functions ( Module: camera )
//------------------------------------------------------------------------------------

// void SetCameraMode( Camera camera, int mode );
// void UpdateCamera( Camera *camera );

// void SetCameraPanControl( int panKey );
// void SetCameraAltControl( int altKey );
// void SetCameraSmoothZoomControl( int szKey );
// void SetCameraMoveControls( int frontKey, int backKey, int rightKey, int leftKey, int upKey, int downKey );
