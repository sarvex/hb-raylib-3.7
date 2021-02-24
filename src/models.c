/*
 * RayLib library: models.c
 * version 3.5
 *
 * Copyright 2020 -2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbraylib.h"

//------------------------------------------------------------------------------------
// Model 3d Loading and Drawing Functions (Module: models)
//------------------------------------------------------------------------------------

// Model loading/unloading functions
// Model LoadModel(const char *fileName);                                                            // Load model from files (meshes and materials)
// Model LoadModelFromMesh(Mesh mesh);                                                               // Load model from generated mesh (default material)
// void UnloadModel(Model model);                                                                    // Unload model (including meshes) from memory (RAM and/or VRAM)
// void UnloadModelKeepMeshes(Model model);                                                          // Unload model (but not meshes) from memory (RAM and/or VRAM)

// Mesh loading/unloading functions
// Mesh *LoadMeshes(const char *fileName, int *meshCount);                                           // Load meshes from model file
// void UnloadMesh(Mesh mesh);                                                                       // Unload mesh from memory (RAM and/or VRAM)
// bool ExportMesh(Mesh mesh, const char *fileName);                                                 // Export mesh data to file, returns true on success

// Material loading/unloading functions
// Material *LoadMaterials(const char *fileName, int *materialCount);                                // Load materials from model file
// Material LoadMaterialDefault(void);                                                               // Load default material (Supports: DIFFUSE, SPECULAR, NORMAL maps)
// void UnloadMaterial(Material material);                                                           // Unload material from GPU memory (VRAM)
// void SetMaterialTexture(Material *material, int mapType, Texture2D texture);                      // Set texture for a material map type (MAP_DIFFUSE, MAP_SPECULAR...)
// void SetModelMeshMaterial(Model *model, int meshId, int materialId);                              // Set material for a mesh

// Model animations loading/unloading functions
// ModelAnimation *LoadModelAnimations(const char *fileName, int *animsCount);                       // Load model animations from file
// void UpdateModelAnimation(Model model, ModelAnimation anim, int frame);                           // Update model animation pose
// void UnloadModelAnimation(ModelAnimation anim);                                                   // Unload animation data
// bool IsModelAnimationValid(Model model, ModelAnimation anim);                                     // Check model animation skeleton match

// Mesh generation functions
// Mesh GenMeshPoly(int sides, float radius);                                                        // Generate polygonal mesh
// Mesh GenMeshPlane(float width, float length, int resX, int resZ);                                 // Generate plane mesh (with subdivisions)
// Mesh GenMeshCube(float width, float height, float length);                                        // Generate cuboid mesh
// Mesh GenMeshSphere(float radius, int rings, int slices);                                          // Generate sphere mesh (standard sphere)
// Mesh GenMeshHemiSphere(float radius, int rings, int slices);                                      // Generate half-sphere mesh (no bottom cap)
// Mesh GenMeshCylinder(float radius, float height, int slices);                                     // Generate cylinder mesh
// Mesh GenMeshTorus(float radius, float size, int radSeg, int sides);                               // Generate torus mesh
// Mesh GenMeshKnot(float radius, float size, int radSeg, int sides);                                // Generate trefoil knot mesh
// Mesh GenMeshHeightmap(Image heightmap, Vector3 size);                                             // Generate heightmap mesh from image data
// Mesh GenMeshCubicmap(Image cubicmap, Vector3 cubeSize);                                           // Generate cubes-based map mesh from image data

// Mesh manipulation functions
// BoundingBox MeshBoundingBox(Mesh mesh);                                                           // Compute mesh bounding box limits
// void MeshTangents(Mesh *mesh);                                                                    // Compute mesh tangents
// void MeshBinormals(Mesh *mesh);                                                                   // Compute mesh binormals
// void MeshNormalsSmooth(Mesh *mesh);                                                               // Smooth (average) vertex normals

// Model drawing functions
// void DrawModel(Model model, Vector3 position, float scale, Color tint);                           // Draw a model (with texture if set)
// void DrawModelEx(Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint); // Draw a model with extended parameters
// void DrawModelWires(Model model, Vector3 position, float scale, Color tint);                      // Draw a model wires (with texture if set)
// void DrawModelWiresEx(Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint); // Draw a model wires (with texture if set) with extended parameters
// void DrawBoundingBox(BoundingBox box, Color color);                                               // Draw bounding box (wires)
// void DrawBillboard(Camera camera, Texture2D texture, Vector3 center, float size, Color tint);     // Draw a billboard texture
// void DrawBillboardRec(Camera camera, Texture2D texture, Rectangle source, Vector3 center, float size, Color tint); // Draw a billboard texture defined by source

// Collision detection functions
// bool CheckCollisionSpheres(Vector3 center1, float radius1, Vector3 center2, float radius2);       // Detect collision between two spheres
// bool CheckCollisionBoxes(BoundingBox box1, BoundingBox box2);                                     // Detect collision between two bounding boxes
// bool CheckCollisionBoxSphere(BoundingBox box, Vector3 center, float radius);                      // Detect collision between box and sphere
// bool CheckCollisionRaySphere(Ray ray, Vector3 center, float radius);                              // Detect collision between ray and sphere
// bool CheckCollisionRaySphereEx(Ray ray, Vector3 center, float radius, Vector3 *collisionPoint);   // Detect collision between ray and sphere, returns collision point
// bool CheckCollisionRayBox(Ray ray, BoundingBox box);                                              // Detect collision between ray and box
// RayHitInfo GetCollisionRayMesh(Ray ray, Mesh mesh, Matrix transform);                             // Get collision info between ray and mesh
// RayHitInfo GetCollisionRayModel(Ray ray, Model model);                                            // Get collision info between ray and model
// RayHitInfo GetCollisionRayTriangle(Ray ray, Vector3 p1, Vector3 p2, Vector3 p3);                  // Get collision info between ray and triangle
// RayHitInfo GetCollisionRayGround(Ray ray, float groundHeight);                                    // Get collision info between ray and ground plane (Y-normal plane)
