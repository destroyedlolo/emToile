/************************************************
*	Style : Style container
*************************************************/

#ifndef STYLE_H
#define STYLE_H

#include <lvgl/lvgl.h>

class Style {

protected:
	lv_style_t	_style;

public:

	/* Style constructor
	 * initialize an empty style
	 */
	Style(){
		lv_style_init( &this->_style );
	}

	/* Get a pointer to the local style
	 */
	lv_style_t *getStyle( void ){
		return( &this->_style );
	}
	lv_style_t *operator *( void ){
		return( &this->_style );
	}

	/* Copy a style to local one
	 * -> lv_style_t *style : original style to copy from
	 */
	void copyStyle( lv_style_t *style ){
		lv_style_copy( &this->_style, style );
	}

	/* Set text font
	 * -> lv_font_t *font : font to use
	 * -> int state (default : LV_STATE_DEFAULT)
	 */
	void setFont( lv_font_t *font, int state=LV_STATE_DEFAULT ){
		lv_style_set_text_font( &this->_style, state, font );
	}

	/* Set text color
	 * -> lv_color_t color
	 * -> uint8_t part (default : LV_OBJ_PART_MAIN)
	 */
	void setTextColor( lv_color_t color, uint8_t part=LV_OBJ_PART_MAIN ){
		lv_style_set_text_color( &this->_style, part, color );
	}

	/* Image recolor
	 * -> lv_color_t color
	 * -> uint8_t part (default : LV_OBJ_PART_MAIN)
	 */
	void setImageRecolor( lv_color_t color, uint8_t part=LV_OBJ_PART_MAIN ){
		lv_style_set_text_color( &this->_style, part, color );
	}

	/* Set radius
	 * -> uint16_t size
	 * -> uint8_t part (default : LV_OBJ_PART_MAIN)
	 */
	void setRadius( uint16_t size, uint8_t part=LV_OBJ_PART_MAIN){
		lv_style_set_radius( &this->_style, part, size );
	}

	/* Set backgound color
	 * -> lv_color_t color
	 * -> int state (default : LV_STATE_DEFAULT)
	 */
	void setBgColor( lv_color_t color, int state = LV_STATE_DEFAULT){
		lv_style_set_bg_color( &this->_style, state, color );
	}

	/* Set background opacity
	 * -> uint8_t value
	 * -> uint8_t part (default : LV_OBJ_PART_MAIN)
	 */
	void setBgOpacity( uint8_t value, uint8_t part=LV_OBJ_PART_MAIN){
		lv_style_set_bg_opa( &this->_style, part, value );
	}

	/* set border width
	 * -> uint16_t value
	 * -> uint8_t part (default : LV_OBJ_PART_MAIN)
	 */
	void setBorderWidth( uint16_t value, uint8_t part=LV_OBJ_PART_MAIN){
		lv_style_set_border_width( &this->_style, part, value );
	}
};

#endif
