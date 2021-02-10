/*
 * RayLib library: rlgl.c
 *
 * Copyright 2020 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbraylib.h"

/* --- Shader loading/unloading functions ---*/
// Shader LoadShader( const char *vsFileName, const char *fsFileName );
// Shader LoadShaderCode( char *vsCode, char *fsCode );
// void UnloadShader( Shader shader );

// Shader GetShaderDefault( void );
// Texture2D GetTextureDefault( void );
// Texture2D GetShapesTexture( void );
// Rectangle GetShapesTextureRec( void );
// void SetShapesTexture( Texture2D texture, Rectangle source );

/* --- Shader configuration functions --- */
// int GetShaderLocation( Shader shader, const char *uniformName );
// void SetShaderValue( Shader shader, int uniformLoc, const void *value, int uniformType );
// void SetShaderValueV( Shader shader, int uniformLoc, const void *value, int uniformType, int count );
// void SetShaderValueMatrix( Shader shader, int uniformLoc, Matrix mat );
// void SetShaderValueTexture( Shader shader, int uniformLoc, Texture2D texture );
// void SetMatrixProjection( Matrix proj );
// void SetMatrixModelview( Matrix view );
// Matrix GetMatrixModelview( void );
// Matrix GetMatrixProjection( void );

/* --- Shading begin/end functions --- */
// void BeginShaderMode( Shader shader );
// void EndShaderMode( void );
// void BeginBlendMode( int mode );
// void EndBlendMode( void );

/* --- VR control functions --- */
// void InitVrSimulator( void );
// void CloseVrSimulator( void );
// void UpdateVrTracking( Camera *camera );
// void SetVrConfiguration( VrDeviceInfo info, Shader distortion );
// bool IsVrSimulatorReady( void );
// void ToggleVrMode( void );
// void BeginVrDrawing( void );
// void EndVrDrawing( void );
