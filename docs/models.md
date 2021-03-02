---
layout: default
title: module models
permalink: models
---

# **Function reference module: models**

## Basic geometric 3D shapes drawing functions

#### DrawLine3D()

```c

void DrawLine3D( Vector3 startPos, Vector3 endPos, Color color );

```

Draw a line in 3D world space

---

#### DrawPoint3D()

```c

void DrawPoint3D( Vector3 position, Color color );

```

Draw a point in 3D space, actually a small line

---

#### DrawCircle3D()

```c

void DrawCircle3D( Vector3 center, float radius, Vector3 rotationAxis, float rotationAngle, Color color );

```

Draw a circle in 3D world space

---

#### DrawTriangle3D()

```c

void DrawTriangle3D( Vector3 v1, Vector3 v2, Vector3 v3, Color color );

```

Draw a color-filled triangle ( vertex in counter-clockwise order! )

---

#### DrawTriangleStrip3D()

```c

void DrawTriangleStrip3D( Vector3 *points, int pointsCount, Color color );

```

Draw a triangle strip defined by points

---

#### DrawCube()

```c

void DrawCube( Vector3 position, float width, float height, float length, Color color );

```

Draw cube

---

#### DrawCubeV()

```c

void DrawCubeV( Vector3 position, Vector3 size, Color color );

```

Draw cube ( Vector version )

---

#### DrawCubeWires()

```c

void DrawCubeWires( Vector3 position, float width, float height, float length, Color color );

```

Draw cube wires

---

#### DrawCubeWiresV()

```c

void DrawCubeWiresV( Vector3 position, Vector3 size, Color color );

```

Draw cube wires ( Vector version )

---

#### DrawCubeTexture()

```c

void DrawCubeTexture( Texture2D texture, Vector3 position, float width, float height, float length, Color color );

```

Draw cube textured

---

#### DrawSphere()

```c

void DrawSphere( Vector3 centerPos, float radius, Color color );

```

Draw sphere

---

#### DrawSphereEx()

```c

void DrawSphereEx( Vector3 centerPos, float radius, int rings, int slices, Color color );

```

Draw sphere with extended parameters

---

#### DrawSphereWires()

```c

void DrawSphereWires( Vector3 centerPos, float radius, int rings, int slices, Color color );

```

Draw sphere wires

---

#### DrawCylinder()

```c

void DrawCylinder( Vector3 position, float radiusTop, float radiusBottom, float height, int slices, Color color );

```

Draw a cylinder/cone

---

#### DrawCylinderWires()

```c

void DrawCylinderWires( Vector3 position, float radiusTop, float radiusBottom, float height, int slices, Color color );

```

Draw a cylinder/cone wires

---

#### DrawPlane()

```c

void DrawPlane( Vector3 centerPos, Vector2 size, Color color );

```

Draw a plane XZ

---

#### DrawRay()

```c

void DrawRay( Ray ray, Color color );

```

Draw a ray line

---

#### DrawGrid()

```c

void DrawGrid( int slices, float spacing );

```

Draw a grid ( centered at ( 0, 0, 0 ) )

---

#### DrawGizmo()

```c

void DrawGizmo( Vector3 position );

```

Draw simple gizmo

---

## Model loading/unloading functions

#### LoadModel()

```c

Model LoadModel( const char *fileName );

```

Load model from files ( meshes and materials )

---

#### LoadModelFromMesh()

```c

Model LoadModelFromMesh( Mesh mesh );

```

Load model from generated mesh ( default material )

---

#### UnloadModel()

```c

void UnloadModel( Model model );

```

Unload model ( including meshes ) from memory ( RAM and/or VRAM )

---

#### UnloadModelKeepMeshes()

```c

void UnloadModelKeepMeshes( Model model );

```

Unload model ( but not meshes ) from memory ( RAM and/or VRAM )

---

## Mesh loading/unloading functions

#### LoadMeshes()

```c

Mesh *LoadMeshes( const char *fileName, int *meshCount );

```

Load meshes from model file

---

#### UnloadMesh()

```c

void UnloadMesh( Mesh mesh );

```

Unload mesh from memory ( RAM and/or VRAM )

---

#### ExportMesh()

```c

bool ExportMesh( Mesh mesh, const char *fileName );

```

Export mesh data to file, returns true on success

---

## Material loading/unloading functions

#### LoadMaterials()

```c

Material *LoadMaterials( const char *fileName, int *materialCount );

```

Load materials from model file

---

#### LoadMaterialDefault()

```c

Material LoadMaterialDefault( void );

```

Load default material ( Supports: DIFFUSE, SPECULAR, NORMAL maps )

---

#### UnloadMaterial()

```c

void UnloadMaterial( Material material );

```

Unload material from GPU memory ( VRAM )

---

#### SetMaterialTexture()

```c

void SetMaterialTexture( Material *material, int mapType, Texture2D texture );

```

Set texture for a material map type ( MAP_DIFFUSE, MAP_SPECULAR... )

---

#### SetModelMeshMaterial()

```c

void SetModelMeshMaterial( Model *model, int meshId, int materialId );

```

Set material for a mesh

----

## Model animations loading/unloading functions

#### LoadModelAnimations()

```c

ModelAnimation *LoadModelAnimations( const char *fileName, int *animsCount );

```

Load model animations from file

---

#### UpdateModelAnimation()

```c

void UpdateModelAnimation( Model model, ModelAnimation anim, int frame );

```

Update model animation pose

---

#### UnloadModelAnimation()

```c

void UnloadModelAnimation( ModelAnimation anim );

```

Unload animation data

---

#### IsModelAnimationValid()

```c

bool IsModelAnimationValid( Model model, ModelAnimation anim );

```

Check model animation skeleton match

---

## Mesh generation functions

#### GenMeshPoly()

```c

Mesh GenMeshPoly( int sides, float radius );

```

Generate polygonal mesh

---

#### GenMeshPlane()

```c

Mesh GenMeshPlane( float width, float length, int resX, int resZ );

```

Generate plane mesh ( with subdivisions )

---

#### GenMeshCube()

```c

Mesh GenMeshCube( float width, float height, float length );

```

Generate cuboid mesh

---

#### GenMeshSphere()

```c

Mesh GenMeshSphere( float radius, int rings, int slices );

```

Generate sphere mesh ( standard sphere )

---

#### GenMeshHemiSphere()

```c

Mesh GenMeshHemiSphere( float radius, int rings, int slices );

```

Generate half-sphere mesh ( no bottom cap )

---

#### GenMeshCylinder()

```c

Mesh GenMeshCylinder( float radius, float height, int slices );

```

Generate cylinder mesh

---

#### GenMeshTorus()

```c

Mesh GenMeshTorus( float radius, float size, int radSeg, int sides );

```

Generate torus mesh

---

#### GenMeshKnot()

```c

Mesh GenMeshKnot( float radius, float size, int radSeg, int sides );

```

Generate trefoil knot mesh

---

#### GenMeshHeightmap()

```c

Mesh GenMeshHeightmap( Image heightmap, Vector3 size );

```

Generate heightmap mesh from image data

---

#### GenMeshCubicmap()

```c

Mesh GenMeshCubicmap( Image cubicmap, Vector3 cubeSize );

```

Generate cubes-based map mesh from image data

----

## Mesh manipulation functions

#### MeshBoundingBox()

```c

BoundingBox MeshBoundingBox( Mesh mesh );

```

Compute mesh bounding box limits

---

#### MeshTangents()

```c

void MeshTangents( Mesh *mesh );

```

Compute mesh tangents

---

#### MeshBinormals()

```c

void MeshBinormals( Mesh *mesh );

```

Compute mesh binormals

---

#### MeshNormalsSmooth()

```c

void MeshNormalsSmooth( Mesh *mesh );

```

Smooth ( average ) vertex normals

---

## Model drawing functions

#### DrawModel()

```c

void DrawModel( Model model, Vector3 position, float scale, Color tint );

```

Draw a model ( with texture if set )

---

#### DrawModelEx()

```c

void DrawModelEx( Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint );

```

Draw a model with extended parameters

---

#### DrawModelWires()

```c

void DrawModelWires( Model model, Vector3 position, float scale, Color tint );

```

Draw a model wires ( with texture if set )

---

#### DrawModelWiresEx()

```c

void DrawModelWiresEx( Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint );

```

Draw a model wires ( with texture if set ) with extended parameters

---

#### DrawBoundingBox()

```c

void DrawBoundingBox( BoundingBox box, Color color );

```

Draw bounding box ( wires )

---

#### DrawBillboard()

```c

void DrawBillboard( Camera camera, Texture2D texture, Vector3 center, float size, Color tint );

```

Draw a billboard texture

---

#### DrawBillboardRec()

```c

void DrawBillboardRec( Camera camera, Texture2D texture, Rectangle source, Vector3 center, float size, Color tint );

```

Draw a billboard texture defined by source

---

## Collision detection functions

#### CheckCollisionSpheres()

```c

bool CheckCollisionSpheres( Vector3 center1, float radius1, Vector3 center2, float radius2 );

```

Detect collision between two spheres

---

#### CheckCollisionBoxes()

```c

bool CheckCollisionBoxes( BoundingBox box1, BoundingBox box2 );

```

Detect collision between two bounding boxes

---

#### CheckCollisionBoxSphere()

```c

bool CheckCollisionBoxSphere( BoundingBox box, Vector3 center, float radius );

```

Detect collision between box and sphere

---

#### CheckCollisionRaySphere()

```c

bool CheckCollisionRaySphere( Ray ray, Vector3 center, float radius );

```

Detect collision between ray and sphere

---

#### CheckCollisionRaySphereEx()

```c

bool CheckCollisionRaySphereEx( Ray ray, Vector3 center, float radius, Vector3 *collisionPoint );

```

Detect collision between ray and sphere, returns collision point

---

#### CheckCollisionRayBox()

```c

bool CheckCollisionRayBox( Ray ray, BoundingBox box );

```

Detect collision between ray and box

---

#### GetCollisionRayMesh()

```c

RayHitInfo GetCollisionRayMesh( Ray ray, Mesh mesh, Matrix transform );

```

Get collision info between ray and mesh

---

#### GetCollisionRayModel()

```c

RayHitInfo GetCollisionRayModel( Ray ray, Model model );

```

Get collision info between ray and model

---

#### GetCollisionRayTriangle()

```c

RayHitInfo GetCollisionRayTriangle( Ray ray, Vector3 p1, Vector3 p2, Vector3 p3 );

```

Get collision info between ray and triangle

---

#### GetCollisionRayGround()

```c

RayHitInfo GetCollisionRayGround( Ray ray, float groundHeight );

```

Get collision info between ray and ground plane ( Y-normal plane )

---
