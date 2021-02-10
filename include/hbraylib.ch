
#ifndef HBRAYLIB_CH_
#define HBRAYLIB_CH_

// Some Basic Colors
// NOTE: Custom raylib color palette for amazing visuals on WHITE background
#define LIGHTGRAY  { 200, 200, 200, 255 }   // Light Gray
#define GRAY       { 130, 130, 130, 255 }   // Gray
#define DARKGRAY   { 80, 80, 80, 255 }      // Dark Gray
#define YELLOW     { 253, 249, 0, 255 }     // Yellow
#define GOLD       { 255, 203, 0, 255 }     // Gold
#define ORANGE     { 255, 161, 0, 255 }     // Orange
#define PINK       { 255, 109, 194, 255 }   // Pink
#define RED        { 230, 41, 55, 255 }     // Red
#define MAROON     { 190, 33, 55, 255 }     // Maroon
#define GREEN      { 0, 228, 48, 255 }      // Green
#define LIME       { 0, 158, 47, 255 }      // Lime
#define DARKGREEN  { 0, 117, 44, 255 }      // Dark Green
#define SKYBLUE    { 102, 191, 255, 255 }   // Sky Blue
#define BLUE       { 0, 121, 241, 255 }     // Blue
#define DARKBLUE   { 0, 82, 172, 255 }      // Dark Blue
#define PURPLE     { 200, 122, 255, 255 }   // Purple
#define VIOLET     { 135, 60, 190, 255 }    // Violet
#define DARKPURPLE { 112, 31, 126, 255 }    // Dark Purple
#define BEIGE      { 211, 176, 131, 255 }   // Beige
#define BROWN      { 127, 106, 79, 255 }    // Brown
#define DARKBROWN  { 76, 63, 47, 255 }      // Dark Brown

#define WHITE      { 255, 255, 255, 255 }   // White
#define BLACK      { 0, 0, 0, 255 }         // Black
#define BLANK      { 0, 0, 0, 0 }           // Blank (Transparent)
#define MAGENTA    { 255, 0, 255, 255 }     // Magenta
#define RAYWHITE   { 245, 245, 245, 255 }   // My own White (raylib logo)

//----------------------------------------------------------------------------------
// Enumerators Definition
//----------------------------------------------------------------------------------
/* --- System config flags --- */
/* --- NOTE: Used for bit masks --- */
#define   FLAG_RESERVED                   1       // Reserved
#define   FLAG_FULLSCREEN_MODE            2       // Set to run program in fullscreen
#define   FLAG_WINDOW_RESIZABLE           4       // Set to allow resizable window
#define   FLAG_WINDOW_UNDECORATED         8       // Set to disable window decoration (frame and buttons)
#define   FLAG_WINDOW_TRANSPARENT         16      // Set to allow transparent window
#define   FLAG_WINDOW_HIDDEN              128     // Set to create the window initially hidden
#define   FLAG_WINDOW_ALWAYS_RUN          256     // Set to allow windows running while minimized
#define   FLAG_MSAA_4X_HINT               32      // Set to try enabling MSAA 4X
#define   FLAG_VSYNC_HINT                 64      // Set to try enabling V-Sync on GPU

/* --- Trace log type --- */
#define   LOG_ALL                         0       // Display all logs
#define   LOG_TRACE                       1
#define   LOG_DEBUG                       2
#define   LOG_INFO                        3
#define   LOG_WARNING                     4
#define   LOG_ERROR                       5
#define   LOG_FATAL                       6
#define   LOG_NONE                        7       // Disable logging

/* --- Keyboard keys --- */
/* --- Alphanumeric keys --- */
#define   KEY_APOSTROPHE                  39
#define   KEY_COMMA                       44
#define   KEY_MINUS                       45
#define   KEY_PERIOD                      46
#define   KEY_SLASH                       47
#define   KEY_ZERO                        48
#define   KEY_ONE                         49
#define   KEY_TWO                         50
#define   KEY_THREE                       51
#define   KEY_FOUR                        52
#define   KEY_FIVE                        53
#define   KEY_SIX                         54
#define   KEY_SEVEN                       55
#define   KEY_EIGHT                       56
#define   KEY_NINE                        57
#define   KEY_SEMICOLON                   59
#define   KEY_EQUAL                       61
#define   KEY_A                           65
#define   KEY_B                           66
#define   KEY_C                           67
#define   KEY_D                           68
#define   KEY_E                           69
#define   KEY_F                           70
#define   KEY_G                           71
#define   KEY_H                           72
#define   KEY_I                           73
#define   KEY_J                           74
#define   KEY_K                           75
#define   KEY_L                           76
#define   KEY_M                           77
#define   KEY_N                           78
#define   KEY_O                           79
#define   KEY_P                           80
#define   KEY_Q                           81
#define   KEY_R                           82
#define   KEY_S                           83
#define   KEY_T                           84
#define   KEY_U                           85
#define   KEY_V                           86
#define   KEY_W                           87
#define   KEY_X                           88
#define   KEY_Y                           89
#define   KEY_Z                           90

/* --- Function keys --- */
#define   KEY_SPACE                       32
#define   KEY_ESCAPE                      256
#define   KEY_ENTER                       257
#define   KEY_TAB                         258
#define   KEY_BACKSPACE                   259
#define   KEY_INSERT                      260
#define   KEY_DELETE                      261
#define   KEY_RIGHT                       262
#define   KEY_LEFT                        263
#define   KEY_DOWN                        264
#define   KEY_UP                          265
#define   KEY_PAGE_UP                     266
#define   KEY_PAGE_DOWN                   267
#define   KEY_HOME                        268
#define   KEY_END                         269
#define   KEY_CAPS_LOCK                   280
#define   KEY_SCROLL_LOCK                 281
#define   KEY_NUM_LOCK                    282
#define   KEY_PRINT_SCREEN                283
#define   KEY_PAUSE                       284
#define   KEY_F1                          290
#define   KEY_F2                          291
#define   KEY_F3                          292
#define   KEY_F4                          293
#define   KEY_F5                          294
#define   KEY_F6                          295
#define   KEY_F7                          296
#define   KEY_F8                          297
#define   KEY_F9                          298
#define   KEY_F10                         299
#define   KEY_F11                         300
#define   KEY_F12                         301
#define   KEY_LEFT_SHIFT                  340
#define   KEY_LEFT_CONTROL                341
#define   KEY_LEFT_ALT                    342
#define   KEY_LEFT_SUPER                  343
#define   KEY_RIGHT_SHIFT                 344
#define   KEY_RIGHT_CONTROL               345
#define   KEY_RIGHT_ALT                   346
#define   KEY_RIGHT_SUPER                 347
#define   KEY_KB_MENU                     348
#define   KEY_LEFT_BRACKET                91
#define   KEY_BACKSLASH                   92
#define   KEY_RIGHT_BRACKET               93
#define   KEY_GRAVE                       96

/* --- Keypad keys --- */
#define   KEY_KP_0                        320
#define   KEY_KP_1                        321
#define   KEY_KP_2                        322
#define   KEY_KP_3                        323
#define   KEY_KP_4                        324
#define   KEY_KP_5                        325
#define   KEY_KP_6                        326
#define   KEY_KP_7                        327
#define   KEY_KP_8                        328
#define   KEY_KP_9                        329
#define   KEY_KP_DECIMAL                  330
#define   KEY_KP_DIVIDE                   331
#define   KEY_KP_MULTIPLY                 332
#define   KEY_KP_SUBTRACT                 333
#define   KEY_KP_ADD                      334
#define   KEY_KP_ENTER                    335
#define   KEY_KP_EQUAL                    336

/* --- Android buttons --- */
#define   KEY_BACK                        4
#define   KEY_MENU                        82
#define   KEY_VOLUME_UP                   24
#define   KEY_VOLUME_DOWN                 25

/* --- Mouse buttons --- */
#define   MOUSE_LEFT_BUTTON               0
#define   MOUSE_RIGHT_BUTTON              1
#define   MOUSE_MIDDLE_BUTTON             2

/* --- Gamepad number --- */
#define   GAMEPAD_PLAYER1                 0
#define   GAMEPAD_PLAYER2                 1
#define   GAMEPAD_PLAYER3                 2
#define   GAMEPAD_PLAYER4                 3

/* --- Gamepad Buttons --- */
/* --- This is here just for error checking
#define   GAMEPAD_BUTTON_UNKNOWN          0

/* --- This is normally a DPAD --- */
#define   GAMEPAD_BUTTON_LEFT_FACE_UP     1
#define   GAMEPAD_BUTTON_LEFT_FACE_RIGHT  2
#define   GAMEPAD_BUTTON_LEFT_FACE_DOWN   3
#define   GAMEPAD_BUTTON_LEFT_FACE_LEFT   5

/* --- This normally corresponds with PlayStation and Xbox controllers --- */
/* --- XBOX: [YXAB] --- */
/* --- PS3: [TriangleSquareCrossCircle] --- */
/* --- No support for 6 button controllers though.. --- */
#define   GAMEPAD_BUTTON_RIGHT_FACE_UP    6
#define   GAMEPAD_BUTTON_RIGHT_FACE_RIGHT 7
#define   GAMEPAD_BUTTON_RIGHT_FACE_DOWN  8
#define   GAMEPAD_BUTTON_RIGHT_FACE_LEFT  9

/* --- Triggers --- */
#define   GAMEPAD_BUTTON_LEFT_TRIGGER_1   10
#define   GAMEPAD_BUTTON_LEFT_TRIGGER_2   11
#define   GAMEPAD_BUTTON_RIGHT_TRIGGER_1  12
#define   GAMEPAD_BUTTON_RIGHT_TRIGGER_2  13

/* --- These are buttons in the center of the gamepad --- */
#define   GAMEPAD_BUTTON_MIDDLE_LEFT      14     //PS3 Select
#define   GAMEPAD_BUTTON_MIDDLE           15     //PS Button/XBOX Button
#define   GAMEPAD_BUTTON_MIDDLE_RIGHT     16     //PS3 Start

/* --- These are the joystick press in buttons --- */
#define   GAMEPAD_BUTTON_LEFT_THUMB       17
#define   GAMEPAD_BUTTON_RIGHT_THUMB      18

/* --- This is here just for error checking --- */
#define   GAMEPAD_AXIS_UNKNOWN            1

/* --- Left stick --- */
#define   GAMEPAD_AXIS_LEFT_X             2
#define   GAMEPAD_AXIS_LEFT_Y             3

/* --- Right stick --- */
#define   GAMEPAD_AXIS_RIGHT_X            4
#define   GAMEPAD_AXIS_RIGHT_Y            5

/* --- Pressure levels for the back triggers --- */
#define   GAMEPAD_AXIS_LEFT_TRIGGER       6      // [1..-1] (pressure-level)
#define   GAMEPAD_AXIS_RIGHT_TRIGGER      7      // [1..-1] (pressure-level)

/* --- Shader location point type --- */
#define   LOC_VERTEX_POSITION             0
#define   LOC_VERTEX_TEXCOORD01           1
#define   LOC_VERTEX_TEXCOORD02           2
#define   LOC_VERTEX_NORMAL               3
#define   LOC_VERTEX_TANGENT              4
#define   LOC_VERTEX_COLOR                5
#define   LOC_MATRIX_MVP                  6
#define   LOC_MATRIX_MODEL                7
#define   LOC_MATRIX_VIEW                 8
#define   LOC_MATRIX_PROJECTION           9
#define   LOC_VECTOR_VIEW                 10
#define   LOC_COLOR_DIFFUSE               11
#define   LOC_COLOR_SPECULAR              12
#define   LOC_COLOR_AMBIENT               13
#define   LOC_MAP_ALBEDO                  14       // LOC_MAP_DIFFUSE
#define   LOC_MAP_METALNESS               15       // LOC_MAP_SPECULAR
#define   LOC_MAP_NORMAL                  16
#define   LOC_MAP_ROUGHNESS               17
#define   LOC_MAP_OCCLUSION               18
#define   LOC_MAP_EMISSION                19
#define   LOC_MAP_HEIGHT                  20
#define   LOC_MAP_CUBEMAP                 21
#define   LOC_MAP_IRRADIANCE              22
#define   LOC_MAP_PREFILTER               23
#define   LOC_MAP_BRDF                    24

#define LOC_MAP_DIFFUSE      LOC_MAP_ALBEDO
#define LOC_MAP_SPECULAR     LOC_MAP_METALNESS

/* --- Shader uniform data types --- */
#define   UNIFORM_FLOAT                   0
#define   UNIFORM_VEC2                    1
#define   UNIFORM_VEC3                    2
#define   UNIFORM_VEC4                    3
#define   UNIFORM_INT                     4
#define   UNIFORM_IVEC2                   5
#define   UNIFORM_IVEC3                   6
#define   UNIFORM_IVEC4                   7
#define   UNIFORM_SAMPLER2D               8

/* --- Material map type --- */
#define   MAP_ALBEDO                      0       // MAP_DIFFUSE
#define   MAP_METALNESS                   1       // MAP_SPECULAR
#define   MAP_NORMAL                      2
#define   MAP_ROUGHNESS                   3
#define   MAP_OCCLUSION                   4
#define   MAP_EMISSION                    5
#define   MAP_HEIGHT                      6
#define   MAP_CUBEMAP                     7       // NOTE: Uses GL_TEXTURE_CUBE_MAP
#define   MAP_IRRADIANCE                  8       // NOTE: Uses GL_TEXTURE_CUBE_MAP
#define   MAP_PREFILTER                   9       // NOTE: Uses GL_TEXTURE_CUBE_MAP
#define   MAP_BRDF                        10

#define MAP_DIFFUSE      MAP_ALBEDO
#define MAP_SPECULAR     MAP_METALNESS

/* --- Pixel formats --- */
/* --- NOTE: Support depends on OpenGL version and platform --- */
#define   UNCOMPRESSED_GRAYSCALE          1       // 8 bit per pixel (no alpha)
#define   UNCOMPRESSED_GRAY_ALPHA         2       // 8*2 bpp (2 channels)
#define   UNCOMPRESSED_R5G6B5             3       // 16 bpp
#define   UNCOMPRESSED_R8G8B8             4       // 24 bpp
#define   UNCOMPRESSED_R5G5B5A1           5       // 16 bpp (1 bit alpha)
#define   UNCOMPRESSED_R4G4B4A4           6       // 16 bpp (4 bit alpha)
#define   UNCOMPRESSED_R8G8B8A8           7       // 32 bpp
#define   UNCOMPRESSED_R32                8       // 32 bpp (1 channel - float)
#define   UNCOMPRESSED_R32G32B32          9       // 32*3 bpp (3 channels - float)
#define   UNCOMPRESSED_R32G32B32A32       10      // 32*4 bpp (4 channels - float)
#define   COMPRESSED_DXT1_RGB             11      // 4 bpp (no alpha)
#define   COMPRESSED_DXT1_RGBA            12      // 4 bpp (1 bit alpha)
#define   COMPRESSED_DXT3_RGBA            13      // 8 bpp
#define   COMPRESSED_DXT5_RGBA            14      // 8 bpp
#define   COMPRESSED_ETC1_RGB             15      // 4 bpp
#define   COMPRESSED_ETC2_RGB             16      // 4 bpp
#define   COMPRESSED_ETC2_EAC_RGBA        17      // 8 bpp
#define   COMPRESSED_PVRT_RGB             18      // 4 bpp
#define   COMPRESSED_PVRT_RGBA            19      // 4 bpp
#define   COMPRESSED_ASTC_4x4_RGBA        20      // 8 bpp
#define   COMPRESSED_ASTC_8x8_RGBA        21      // 2 bpp

/* --- Texture parameters: filter mode --- */
/* --- NOTE 1: Filtering considers mipmaps if available in the texture --- */
/* --- NOTE 2: Filter is accordingly set for minification and magnification --- */
#define   FILTER_POINT                    0       // No filter just pixel aproximation
#define   FILTER_BILINEAR                 1       // Linear filtering
#define   FILTER_TRILINEAR                2       // Trilinear filtering (linear with mipmaps)
#define   FILTER_ANISOTROPIC_4X           3       // Anisotropic filtering 4x
#define   FILTER_ANISOTROPIC_8X           4       // Anisotropic filtering 8x
#define   FILTER_ANISOTROPIC_16X          5       // Anisotropic filtering 16x

/* --- Cubemap layout type --- */
#define   CUBEMAP_AUTO_DETECT             0       // Automatically detect layout type
#define   CUBEMAP_LINE_VERTICAL           1       // Layout is defined by a vertical line with faces
#define   CUBEMAP_LINE_HORIZONTAL         2       // Layout is defined by an horizontal line with faces
#define   CUBEMAP_CROSS_THREE_BY_FOUR     3       // Layout is defined by a 3x4 cross with cubemap faces
#define   CUBEMAP_CROSS_FOUR_BY_THREE     4       // Layout is defined by a 4x3 cross with cubemap faces
#define   CUBEMAP_PANORAMA                5       // Layout is defined by a panorama image (equirectangular map)

/* --- Texture parameters: wrap mode --- */
#define   WRAP_REPEAT                     0       // Repeats texture in tiled mode
#define   WRAP_CLAMP                      1       // Clamps texture to edge pixel in tiled mode
#define   WRAP_MIRROR_REPEAT              2       // Mirrors and repeats the texture in tiled mode
#define   WRAP_MIRROR_CLAMP               3       // Mirrors and clamps to border the texture in tiled mode

/* --- Font type defines generation method --- */
#define   FONT_DEFAULT                    0       // Default font generation anti-aliased
#define   FONT_BITMAP                     1       // Bitmap font generation no anti-aliasing
#define   FONT_SDF                        2       // SDF font generation requires external shader

/* --- Color blending modes (pre-defined) --- */
#define   BLEND_ALPHA                     0       // Blend textures considering alpha (default)
#define   BLEND_ADDITIVE                  1       // Blend textures adding colors
#define   BLEND_MULTIPLIED                2       // Blend textures multiplying colors

/* --- Gestures type --- */
/* --- NOTE: It could be used as flags to enable only some gestures --- */
#define   GESTURE_NONE                    0
#define   GESTURE_TAP                     1
#define   GESTURE_DOUBLETAP               2
#define   GESTURE_HOLD                    4
#define   GESTURE_DRAG                    8
#define   GESTURE_SWIPE_RIGHT             16
#define   GESTURE_SWIPE_LEFT              32
#define   GESTURE_SWIPE_UP                64
#define   GESTURE_SWIPE_DOWN              128
#define   GESTURE_PINCH_IN                256
#define   GESTURE_PINCH_OUT               512

/* --- Camera system modes --- */
#define   CAMERA_CUSTOM                   0
#define   CAMERA_FREE                     1
#define   CAMERA_ORBITAL                  2
#define   CAMERA_FIRST_PERSON             3
#define   CAMERA_THIRD_PERSON             4

/* --- Camera projection modes --- */
#define   CAMERA_PERSPECTIVE              0
#define   CAMERA_ORTHOGRAPHIC             1

/* --- Type of n-patch --- */
#define   NPT_9PATCH                      0       // Npatch defined by 3x3 tiles
#define   NPT_3PATCH_VERTICAL             1       // Npatch defined by 1x3 tiles
#define   NPT_3PATCH_HORIZONTAL           2       // Npatch defined by 3x1 tiles

#endif /* HBRAYLIB_CH_ */
