/*
Exemplo não concluido!
Obs: Compilar junto com hbct
*/

#include "hbraylib.ch"

#define MAX_SAMPLES               512
#define MAX_SAMPLES_PER_UPDATE   4096

#define VECTOR2_X	1
#define VECTOR2_Y	2
#define PI			3.141592

procedure main
// Initialization
//--------------------------------------------------------------------------------------
local i
local fp
local screenWidth := 800
local screenHeight := 450
local stream
local data
local writeBuf
local mousePosition
local frequency
local oldFrequency
local readCursor
local waveLength
local position
local oldWavelength
local writeCursor
local writeLength
local readLength

InitWindow(screenWidth, screenHeight, "raylib [audio] example - raw audio streaming");

InitAudioDevice();              // Initialize audio device

// Init raw audio stream (sample rate: 22050, sample size: 16bit-short, channels: 1-mono)
stream := LoadAudioStream(22050, 16, 1)

// Buffer for the single cycle waveform we are synthesizing
data := MAX_SAMPLES

// Frame buffer, describing the waveform when repeated over the course of a frame
writeBuf := MAX_SAMPLES_PER_UPDATE

PlayAudioStream(stream)        // Start processing stream buffer (no data loaded currently)

// Cycles per second (hz)
frequency := 440.0

// Previous value, used to test if sine needs to be rewritten, and to smoothly modulate frequency
oldFrequency := 1.0

// Cursor to read and copy the samples of the sine wave buffer
readCursor := 0

// Computed size in samples of the sine wave
waveLength := 1

position := { 0, 0 }

SetTargetFPS(30)               // Set our game to run at 30 frames-per-second
//--------------------------------------------------------------------------------------

// Main game loop
do while (!WindowShouldClose())    // Detect window close button or ESC key
	// Update
	//----------------------------------------------------------------------------------

   // Sample mouse input.
   mousePosition := GetMousePosition()

   if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
   	fp := mousePosition[VECTOR2_Y]
      frequency = 40.0 + fp
   endif	

   // Rewrite the sine wave.
   // Compute two cycles to allow the buffer padding, simplifying any modulation, resampling, etc.
   if (frequency != oldFrequency)
   	// Compute wavelength. Limit size in both directions.
      oldWavelength := waveLength

      waveLength := int(22050/frequency)
      if waveLength > (MAX_SAMPLES/2)
			waveLength := (MAX_SAMPLES/2)
		endif
      if (waveLength < 1)
			waveLength := 1
		endif

      // Write sine wave.
      for i := 1 to (waveLength*2)+1
     		data[i] := sin(((2*PI*i/waveLength)))*32000
      next

      // Scale read cursor's position to minimize transition artifacts
      readCursor := int(readCursor * (waveLength / oldWavelength))
      oldFrequency := frequency
	endif

  	// Refill audio stream if required
   if IsAudioStreamProcessed(stream)
   	// Synthesize a buffer that is exactly the requested size
      writeCursor := 0
      do while (writeCursor < MAX_SAMPLES_PER_UPDATE)
      	// Start by trying to write the whole chunk at once
         writeLength := MAX_SAMPLES_PER_UPDATE-writeCursor

         // Limit to the maximum readable size
         readLength := waveLength-readCursor
         if (writeLength > readLength)
	 			writeLength := readLength
			endif

         // Write the slice
         //memcpy(writeBuf + writeCursor, data + readCursor, writeLength)
         writeBuf := data + readCursor

        	// Update cursors and loop audio
         readCursor := (readCursor + writeLength) % waveLength
         writeCursor += writeLength
      enddo
      // Copy finished frame to audio stream
      UpdateAudioStream(stream, writeBuf, MAX_SAMPLES_PER_UPDATE)
   endif

   //----------------------------------------------------------------------------------
   // Draw
   //----------------------------------------------------------------------------------
   BeginDrawing()
   ClearBackground(RAYWHITE)
   DrawText(TextFormat("sine frequency: %i", int(frequency), GetScreenWidth() - 220, 10, 20, RED))
   DrawText("click mouse button to change frequency", 10, 10, 20, DARKGRAY)
   // Draw the current buffer state proportionate to the screen
   for i := 0 to screenWidth
   	position[VECTOR2_X] := i
      position[VECTOR2_Y] := 250 + 50*data[i*MAX_SAMPLES/screenWidth]/32000.0
      DrawPixelV(position, RED)
	next
   EndDrawing()
enddo
//----------------------------------------------------------------------------------
// De-Initialization
//--------------------------------------------------------------------------------------
//free(data)                 // Unload sine wave data
//free(writeBuf)             // Unload write buffer
UnloadAudioStream(stream)   // Close raw audio stream and delete buffers from RAM
CloseAudioDevice()         // Close audio device (music streaming is automatically stopped)
CloseWindow()              // Close window and OpenGL context
//--------------------------------------------------------------------------------------
return