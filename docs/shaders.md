---
layout: default
title: module shaders
permalink: shaders
---

# **Function reference module: shaders**

## Shader loading/unloading functions

#### LoadShader()

```c

Shader LoadShader( const char *vsFileName, const char *fsFileName );

```

Load shader from files and bind default locations

---

#### LoadShaderCode()

```c

Shader LoadShaderCode( const char *vsCode, const char *fsCode );

```

Load shader from code strings and bind default locations

---

#### UnloadShader()

```c

void UnloadShader( Shader shader );

```

Unload shader from GPU memory ( VRAM )

---

#### GetShaderDefault()

```c

Shader GetShaderDefault( void );

```

Get default shader

---

#### GetTextureDefault()

```c

Texture2D GetTextureDefault( void );

```

Get default texture

---

#### GetShapesTexture()

```c

Texture2D GetShapesTexture( void );

```

Get texture to draw shapes

---

#### GetShapesTextureRec()

```c

Rectangle GetShapesTextureRec( void );

```

Get texture rectangle to draw shapes

---

#### SetShapesTexture()

```c

void SetShapesTexture( Texture2D texture, Rectangle source );

```

Define default texture used to draw shapes

---

## Shader configuration functions

#### GetShaderLocation()

```c

int GetShaderLocation( Shader shader, const char *uniformName );

```

Get shader uniform location

---

#### GetShaderLocationAttrib()

```c

int GetShaderLocationAttrib( Shader shader, const char *attribName );

```

Get shader attribute location

---

#### SetShaderValue()

```c

void SetShaderValue( Shader shader, int uniformLoc, const void *value, int uniformType );

```

Set shader uniform value

---

#### SetShaderValueV()

```c

void SetShaderValueV( Shader shader, int uniformLoc, const void *value, int uniformType, int count );

```

Set shader uniform value vector

---

#### SetShaderValueMatrix()

```c

void SetShaderValueMatrix( Shader shader, int uniformLoc, Matrix mat );

```

Set shader uniform value ( matrix 4x4 )

---

#### SetShaderValueTexture()

```c

void SetShaderValueTexture( Shader shader, int uniformLoc, Texture2D texture );

```

Set shader uniform value for texture

---

#### SetMatrixProjection()

```c

void SetMatrixProjection( Matrix proj );

```

Set a custom projection matrix ( replaces internal projection matrix )

---

#### SetMatrixModelview()

```c

void SetMatrixModelview( Matrix view );

```

Set a custom modelview matrix ( replaces internal modelview matrix )

---

#### GetMatrixModelview()

```c

Matrix GetMatrixModelview( void );

```

Get internal modelview matrix

---

#### GetMatrixProjection()

```c

Matrix GetMatrixProjection( void );

```

Get internal projection matrix

---

## Shading begin/end functions

#### BeginShaderMode()

```c

void BeginShaderMode( Shader shader );

```

Begin custom shader drawing

---

#### EndShaderMode()

```c

void EndShaderMode( void );

```

End custom shader drawing ( use default shader )

---

#### BeginBlendMode()

```c

void BeginBlendMode( int mode );

```

Begin blending mode ( alpha, additive, multiplied )

---

#### EndBlendMode()

```c

void EndBlendMode( void );

```

End blending mode ( reset to default: alpha blending )

---

## VR control functions

#### InitVrSimulator()

```c

void InitVrSimulator( void );

```

Init VR simulator for selected device parameters

---

#### CloseVrSimulator()

```c

void CloseVrSimulator( void );

```

Close VR simulator for current device

---

#### UpdateVrTracking()

```c

void UpdateVrTracking( Camera *camera );

```

Update VR tracking ( position and orientation ) and camera

---

#### SetVrConfiguration()

```c

void SetVrConfiguration( VrDeviceInfo info, Shader distortion );

```

Set stereo rendering configuration parameters

---

#### IsVrSimulatorReady()

```c

bool IsVrSimulatorReady( void );

```

Detect if VR simulator is ready

---

#### ToggleVrMode()

```c

void ToggleVrMode( void );

```

Enable/Disable VR experience

---

#### BeginVrDrawing()

```c

void BeginVrDrawing( void );

```

Begin VR simulator stereo rendering

---

#### EndVrDrawing()

```c

void EndVrDrawing( void );

```

End VR simulator stereo rendering

---
