/*
 * RayLib library: models.c
 *
 * Copyright 2020 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbraylib.h"

/* --- Basic geometric 3D shapes drawing functions --- */
// void DrawLine3D( Vector3 startPos, Vector3 endPos, Color color );
// void DrawPoint3D( Vector3 position, Color color );
// void DrawCircle3D( Vector3 center, float radius, Vector3 rotationAxis, float rotationAngle, Color color );
// void DrawCube( Vector3 position, float width, float height, float length, Color color );
// void DrawCubeV( Vector3 position, Vector3 size, Color color );
// void DrawCubeWires( Vector3 position, float width, float height, float length, Color color );
// void DrawCubeWiresV( Vector3 position, Vector3 size, Color color );
// void DrawCubeTexture( Texture2D texture, Vector3 position, float width, float height, float length, Color color );
// void DrawSphere( Vector3 centerPos, float radius, Color color );
// void DrawSphereEx( Vector3 centerPos, float radius, int rings, int slices, Color color );
// void DrawSphereWires( Vector3 centerPos, float radius, int rings, int slices, Color color );
// void DrawCylinder( Vector3 position, float radiusTop, float radiusBottom, float height, int slices, Color color );
// void DrawCylinderWires( Vector3 position, float radiusTop, float radiusBottom, float height, int slices, Color color );
// void DrawPlane( Vector3 centerPos, Vector2 size, Color color );
// void DrawRay( Ray ray, Color color );
// void DrawGrid( int slices, float spacing );
// void DrawGizmo( Vector3 position );

/* --- Model loading/unloading functions --- */
// Model LoadModel( const char *fileName );
// Model LoadModelFromMesh( Mesh mesh );
// void UnloadModel( Model model );

/* --- Mesh loading/unloading functions --- */
// Mesh *LoadMeshes( const char *fileName, int *meshCount );
// void ExportMesh( Mesh mesh, const char *fileName );
// void UnloadMesh( Mesh mesh );

/* --- Material loading/unloading functions --- */
// Material *LoadMaterials( const char *fileName, int *materialCount );
// Material LoadMaterialDefault( void );
// void UnloadMaterial( Material material );
// void SetMaterialTexture( Material *material, int mapType, Texture2D texture );
// void SetModelMeshMaterial( Model *model, int meshId, int materialId );

/* --- Model animations loading/unloading functions --- */
// ModelAnimation *LoadModelAnimations( const char *fileName, int *animsCount );
// void UpdateModelAnimation( Model model, ModelAnimation anim, int frame );
// void UnloadModelAnimation( ModelAnimation anim );
// bool IsModelAnimationValid( Model model, ModelAnimation anim );

/* --- Mesh generation functions --- */
// Mesh GenMeshPoly( int sides, float radius );
// Mesh GenMeshPlane( float width, float length, int resX, int resZ );
// Mesh GenMeshCube( float width, float height, float length );
// Mesh GenMeshSphere( float radius, int rings, int slices );
// Mesh GenMeshHemiSphere( float radius, int rings, int slices );
// Mesh GenMeshCylinder( float radius, float height, int slices );
// Mesh GenMeshTorus( float radius, float size, int radSeg, int sides );
// Mesh GenMeshKnot( float radius, float size, int radSeg, int sides );
// Mesh GenMeshHeightmap( Image heightmap, Vector3 size );
// Mesh GenMeshCubicmap( Image cubicmap, Vector3 cubeSize );

/* --- Mesh manipulation functions --- */
// BoundingBox MeshBoundingBox( Mesh mesh );
// void MeshTangents( Mesh *mesh );
// void MeshBinormals( Mesh *mesh );

/* --- Model drawing functions --- */
// void DrawModel( Model model, Vector3 position, float scale, Color tint );
// void DrawModelEx( Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint );
// void DrawModelWires( Model model, Vector3 position, float scale, Color tint );
// void DrawModelWiresEx( Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint );
// void DrawBoundingBox( BoundingBox box, Color color );
// void DrawBillboard( Camera camera, Texture2D texture, Vector3 center, float size, Color tint );
// void DrawBillboardRec( Camera camera, Texture2D texture, Rectangle sourceRec, Vector3 center, float size, Color tint );

/* --- Collision detection functions --- */
// bool CheckCollisionSpheres( Vector3 centerA, float radiusA, Vector3 centerB, float radiusB );
// bool CheckCollisionBoxes( BoundingBox box1, BoundingBox box2 );
// bool CheckCollisionBoxSphere( BoundingBox box, Vector3 center, float radius );
// bool CheckCollisionRaySphere( Ray ray, Vector3 center, float radius );
// bool CheckCollisionRaySphereEx( Ray ray, Vector3 center, float radius, Vector3 *collisionPoint );
// bool CheckCollisionRayBox( Ray ray, BoundingBox box );
// RayHitInfo GetCollisionRayModel( Ray ray, Model model );
// RayHitInfo GetCollisionRayTriangle( Ray ray, Vector3 p1, Vector3 p2, Vector3 p3 );
// RayHitInfo GetCollisionRayGround( Ray ray, float groundHeight );
