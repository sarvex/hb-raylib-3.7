/*
 * RayLib library: hbraylib.c
 * version 3.7
 *
 * Copyright 2020 - 2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbraylib.h"

// Global gui modification functions
// void GuiEnable(void);                                         // Enable gui controls (global state)
// void GuiDisable(void);                                        // Disable gui controls (global state)
// void GuiLock(void);                                           // Lock gui controls (global state)
// void GuiUnlock(void);                                         // Unlock gui controls (global state)
// void GuiFade(float alpha);                                    // Set gui controls alpha (global state), alpha goes from 0.0f to 1.0f

// void GuiSetState(int state);                                  // Set gui state (global state)
// int GuiGetState(void);                                        // Get gui state (global state)

// void GuiSetFont(Font font);                                   // Set gui custom font (global state)
// Font GuiGetFont(void);                                        // Get gui custom font (global state)

// Style set/get functions

void GuiSetStyle( int control, int property, int value );       // Set one style property
HB_FUNC( GUISETSTYLE )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL &&
       hb_param( 2, HB_IT_INTEGER ) != NULL &&
       hb_param( 3, HB_IT_INTEGER ) != NULL )
   {
      GuiSetStyle( hb_parni( 1 ), hb_parni( 2 ), hb_parni( 3 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

int GuiGetStyle( int control, int property );                   // Get one style property
HB_FUNC( GUIGETSTYLE )
{
   if( hb_param( 1, HB_IT_INTEGER ) != NULL &&
       hb_param( 2, HB_IT_INTEGER ) != NULL )
   {
      hb_retni( GuiGetStyle( hb_parni( 1 ), hb_parni( 2 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// #if defined(RAYGUI_TEXTBOX_EXTENDED)
// GuiTextBox() extended functions
// void GuiTextBoxSetActive(Rectangle bounds);                   // Sets the active textbox
// Rectangle GuiTextBoxGetActive(void);                          // Get bounds of active textbox
// void GuiTextBoxSetCursor(int cursor);                         // Set cursor position of active textbox
// int GuiTextBoxGetCursor(void);                                // Get cursor position of active textbox
// void GuiTextBoxSetSelection(int start, int length);           // Set selection of active textbox
// Vector2 GuiTextBoxGetSelection(void);                         // Get selection of active textbox (x - selection start  y - selection length)
// bool GuiTextBoxIsActive(Rectangle bounds);                    // Returns true if a textbox control with specified `bounds` is the active textbox
// GuiTextBoxState GuiTextBoxGetState(void);                     // Get state for the active textbox
// void GuiTextBoxSetState(GuiTextBoxState state);               // Set state for the active textbox (state must be valid else things will break)
// void GuiTextBoxSelectAll(const char *text);                   // Select all characters in the active textbox (same as pressing `CTRL` + `A`)
// void GuiTextBoxCopy(const char *text);                        // Copy selected text to clipboard from the active textbox (same as pressing `CTRL` + `C`)
// void GuiTextBoxPaste(char *text, int textSize);               // Paste text from clipboard into the textbox (same as pressing `CTRL` + `V`)
// void GuiTextBoxCut(char *text);                               // Cut selected text in the active textbox and copy it to clipboard (same as pressing `CTRL` + `X`)
// int GuiTextBoxDelete(char *text, int length, bool before);    // Deletes a character or selection before from the active textbox (depending on `before`). Returns bytes deleted.
// int GuiTextBoxGetByteIndex(const char *text, int start, int from, int to); // Get the byte index for a character starting at position `from` with index `start` until position `to`.
// #endif

// Container/separator controls, useful for controls organization

bool GuiWindowBox( Rectangle bounds, const char *title );                                       // Window Box control, shows a window that can be closed
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

void GuiGroupBox( Rectangle bounds, const char *text );                                         // Group Box control with text name
HB_FUNC( GUIGROUPBOX )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 4 && hb_param( 2, HB_IT_STRING ) != NULL )
   {
      Rectangle bounds;

      bounds.x      = ( float ) hb_arrayGetND( pItem, 1 );
      bounds.y      = ( float ) hb_arrayGetND( pItem, 2 );
      bounds.width  = ( float ) hb_arrayGetND( pItem, 3 );
      bounds.height = ( float ) hb_arrayGetND( pItem, 4 );

      GuiGroupBox( bounds, hb_parc( 2 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// void GuiLine(Rectangle bounds, const char *text);                                             // Line separator control, could contain text
// void GuiPanel(Rectangle bounds);                                                              // Panel control, useful to group controls

Rectangle GuiScrollPanel( Rectangle bounds, Rectangle content, Vector2 *scroll );               // Scroll Panel control
HB_FUNC( GUISCROLLPANEL )
{
   PHB_ITEM pItem1, pItem2, pItem3 ;

   if( ( pItem1 = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem1 ) == 4 &&
       ( pItem2 = hb_param( 2, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem2 ) == 4 &&
       ( pItem3 = hb_param( 3, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem3 ) == 2 )
   {
      Rectangle bounds;

      bounds.x      = ( float ) hb_arrayGetND( pItem1, 1 );
      bounds.y      = ( float ) hb_arrayGetND( pItem1, 2 );
      bounds.width  = ( float ) hb_arrayGetND( pItem1, 3 );
      bounds.height = ( float ) hb_arrayGetND( pItem1, 4 );

      Rectangle content;

      content.x      = ( float ) hb_arrayGetND( pItem2, 1 );
      content.y      = ( float ) hb_arrayGetND( pItem2, 2 );
      content.width  = ( float ) hb_arrayGetND( pItem2, 3 );
      content.height = ( float ) hb_arrayGetND( pItem2, 4 );

      Vector2 scroll;

      scroll.x = ( float ) hb_arrayGetND( pItem3, 1 );
      scroll.y = ( float ) hb_arrayGetND( pItem3, 2 );

      Rectangle rec = GuiScrollPanel( bounds, content, &scroll );

      PHB_ITEM info = hb_itemArrayNew( 4 );

      hb_arraySetND( info, 1, ( float ) rec.x );
      hb_arraySetND( info, 2, ( float ) rec.y );
      hb_arraySetND( info, 3, ( float ) rec.width );
      hb_arraySetND( info, 4, ( float ) rec.height );

      hb_itemReturnRelease( info );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// Basic controls set

void GuiLabel( Rectangle bounds, const char *text );                                            // Label control, shows text
HB_FUNC( GUILABEL )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 4 && hb_param( 2, HB_IT_STRING ) != NULL )
   {
      Rectangle bounds;

      bounds.x      = ( float ) hb_arrayGetND( pItem, 1 );
      bounds.y      = ( float ) hb_arrayGetND( pItem, 2 );
      bounds.width  = ( float ) hb_arrayGetND( pItem, 3 );
      bounds.height = ( float ) hb_arrayGetND( pItem, 4 );

      GuiLabel( bounds, hb_parc( 2 ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// bool GuiButton(Rectangle bounds, const char *text);                                           // Button control, returns true when clicked
// bool GuiLabelButton(Rectangle bounds, const char *text);                                      // Label button control, show true when clicked
// bool GuiImageButton(Rectangle bounds, const char *text, Texture2D texture);                   // Image button control, returns true when clicked
// bool GuiImageButtonEx(Rectangle bounds, const char *text, Texture2D texture, Rectangle texSource);    // Image button extended control, returns true when clicked

bool GuiToggle( Rectangle bounds, const char *text, bool active );                              // Toggle Button control, returns true when active
HB_FUNC( GUITOGGLE )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 4 &&
      hb_param( 2, HB_IT_STRING ) != NULL &&
      hb_param( 3, HB_IT_LOGICAL ) != NULL )
   {
      Rectangle bounds;

      bounds.x      = ( float ) hb_arrayGetND( pItem, 1 );
      bounds.y      = ( float ) hb_arrayGetND( pItem, 2 );
      bounds.width  = ( float ) hb_arrayGetND( pItem, 3 );
      bounds.height = ( float ) hb_arrayGetND( pItem, 4 );

      hb_retl( GuiToggle( bounds, hb_parc( 2 ), hb_parl( 3 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// int GuiToggleGroup(Rectangle bounds, const char *text, int active);                           // Toggle Group control, returns active toggle index

bool GuiCheckBox( Rectangle bounds, const char *text, bool checked );                           // Check Box control, returns true when active
HB_FUNC( GUICHECKBOX )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 4 &&
      hb_param( 2, HB_IT_STRING ) != NULL &&
      hb_param( 3, HB_IT_LOGICAL ) != NULL )
   {
      Rectangle bounds;

      bounds.x      = ( float ) hb_arrayGetND( pItem, 1 );
      bounds.y      = ( float ) hb_arrayGetND( pItem, 2 );
      bounds.width  = ( float ) hb_arrayGetND( pItem, 3 );
      bounds.height = ( float ) hb_arrayGetND( pItem, 4 );

      hb_retl( GuiCheckBox( bounds, hb_parc( 2 ), hb_parl( 3 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// int GuiComboBox(Rectangle bounds, const char *text, int active);                              // Combo Box control, returns selected item index
// bool GuiDropdownBox(Rectangle bounds, const char *text, int *active, bool editMode);          // Dropdown Box control, returns selected item

bool GuiSpinner( Rectangle bounds, const char *text, int *value, int minValue, int maxValue, bool editMode );     // Spinner control, returns selected value
HB_FUNC( GUISPINNER )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 4 &&
                 hb_param( 2, HB_IT_STRING )  != NULL &&
                 hb_param( 3, HB_IT_INTEGER ) != NULL &&
                 hb_param( 4, HB_IT_INTEGER ) != NULL &&
                 hb_param( 5, HB_IT_INTEGER ) != NULL &&
                 hb_param( 6, HB_IT_LOGICAL ) != NULL )
   {
      Rectangle bounds;

      bounds.x      = ( float ) hb_arrayGetND( pItem, 1 );
      bounds.y      = ( float ) hb_arrayGetND( pItem, 2 );
      bounds.width  = ( float ) hb_arrayGetND( pItem, 3 );
      bounds.height = ( float ) hb_arrayGetND( pItem, 4 );

      int value;
      hb_retl( GuiSpinner( bounds, hb_parc( 2 ), &value, hb_parni( 4 ), hb_parni( 5 ), hb_parl( 6 ) ) );
      hb_storni( value, 3 );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// bool GuiValueBox(Rectangle bounds, const char *text, int *value, int minValue, int maxValue, bool editMode);    // Value Box control, updates input text with numbers
// bool GuiTextBox(Rectangle bounds, char *text, int textSize, bool editMode);                   // Text Box control, updates input text
// bool GuiTextBoxMulti(Rectangle bounds, char *text, int textSize, bool editMode);              // Text Box control with multiple lines
// float GuiSlider(Rectangle bounds, const char *textLeft, const char *textRight, float value, float minValue, float maxValue);       // Slider control, returns selected value

float GuiSliderBar( Rectangle bounds, const char *textLeft, const char *textRight, float value, float minValue, float maxValue );    // Slider Bar control, returns selected value
HB_FUNC( GUISLIDERBAR )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 4 &&
                 hb_param( 2, HB_IT_STRING )  != NULL &&
                 hb_param( 2, HB_IT_STRING )  != NULL &&
                 hb_param( 4, HB_IT_NUMERIC ) != NULL &&
                 hb_param( 5, HB_IT_NUMERIC ) != NULL &&
                 hb_param( 6, HB_IT_NUMERIC ) != NULL )
   {
      Rectangle bounds;

      bounds.x      = ( float ) hb_arrayGetND( pItem, 1 );
      bounds.y      = ( float ) hb_arrayGetND( pItem, 2 );
      bounds.width  = ( float ) hb_arrayGetND( pItem, 3 );
      bounds.height = ( float ) hb_arrayGetND( pItem, 4 );

      hb_retnd( ( float ) GuiSliderBar( bounds, hb_parc( 2 ), hb_parc( 3 ), ( float ) hb_parnd( 4 ), ( float ) hb_parnd( 5 ), ( float ) hb_parnd( 6 ) ) );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// float GuiProgressBar(Rectangle bounds, const char *textLeft, const char *textRight, float value, float minValue, float maxValue);  // Progress Bar control, shows current progress value
// void GuiStatusBar(Rectangle bounds, const char *text);                                        // Status Bar control, shows info text
// void GuiDummyRec(Rectangle bounds, const char *text);                                         // Dummy control for placeholders
// int GuiScrollBar(Rectangle bounds, int value, int minValue, int maxValue);                    // Scroll Bar control

Vector2 GuiGrid( Rectangle bounds, float spacing, int subdivs );                                // Grid control
HB_FUNC( GUIGRID )
{
   PHB_ITEM pItem;

   if( ( pItem = hb_param( 1, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pItem ) == 4 &&
      hb_param( 2, HB_IT_NUMERIC ) != NULL &&
      hb_param( 3, HB_IT_INTEGER ) != NULL )
   {
      Rectangle bounds;

      bounds.x      = ( float ) hb_arrayGetND( pItem, 1 );
      bounds.y      = ( float ) hb_arrayGetND( pItem, 2 );
      bounds.width  = ( float ) hb_arrayGetND( pItem, 3 );
      bounds.height = ( float ) hb_arrayGetND( pItem, 4 );

      Vector2 vector2 = GuiGrid( bounds, ( float ) hb_parnd( 2 ), hb_parni( 3 )  );

      PHB_ITEM info = hb_itemArrayNew( 2 );

      hb_arraySetNI( info, 1, ( float ) vector2.x );
      hb_arraySetNI( info, 2, ( float ) vector2.y );

      hb_itemReturnRelease( info );
   }
   else
   {
      hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
   }
}

// Advance controls set
// int GuiListView(Rectangle bounds, const char *text, int *scrollIndex, int active);            // List View control, returns selected list item index
// int GuiListViewEx(Rectangle bounds, const char **text, int count, int *focus, int *scrollIndex, int active);      // List View with extended parameters
// int GuiMessageBox(Rectangle bounds, const char *title, const char *message, const char *buttons);                 // Message Box control, displays a message
// int GuiTextInputBox(Rectangle bounds, const char *title, const char *message, const char *buttons, char *text);   // Text Input Box control, ask for text
// Color GuiColorPicker(Rectangle bounds, Color color);                                          // Color Picker control

// Styles loading functions
// void GuiLoadStyle(const char *fileName);              // Load style file (.rgs)
// void GuiLoadStyleProps(const int *props, int count);  // Load style properties from array
// void GuiLoadStyleDefault(void);                       // Load style default over global style
// void GuiUpdateStyleComplete(void);                    // Updates full style properties set with default values

/*
typedef GuiStyle (unsigned int *)
// GuiStyle LoadGuiStyle(const char *fileName);          // Load style from file (.rgs)
// void UnloadGuiStyle(GuiStyle style);                  // Unload style
*/

// const char *GuiIconText(int iconId, const char *text); // Get text with icon id prepended
