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

	/* Reset the style a free all used ressources */
	void Reset( void ){
		lv_style_reset( &this->_style );
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
	 * -> lv_style_int_t size
	 * -> uint8_t part (default : LV_OBJ_PART_MAIN)
	 */
	void setRadius( lv_style_int_t size, uint8_t part=LV_OBJ_PART_MAIN){
		lv_style_set_radius( &this->_style, part, size );
	}

	/* Enlarge the object (by axis)
	 * -> lv_style_int_t hfactor : horizontal factor
	 * -> lv_style_int_t vfactor : vertical factor
	 *		0 : original size
	 * -> uint8_t part (default : LV_OBJ_PART_MAIN)
	 */
	void Enlarge( lv_style_int_t hfactor, lv_style_int_t vfactor, uint8_t part=LV_OBJ_PART_MAIN ){
		lv_style_set_transform_width( &this->_style, part, hfactor );
		lv_style_set_transform_height( &this->_style, part, vfactor );
	}

	/* Zoom the object
	 * -> lv_style_int_t zoom : zoom factor
	 *  	The reference is 256 (or LV_IMG_ZOOM_NONE), so
	 *  		128 is 1/2
	 *  		512 is x2
	 * -> uint8_t part (default : LV_OBJ_PART_MAIN)
	 */
	void Zoom( lv_style_int_t zoom, uint8_t part=LV_OBJ_PART_MAIN ){
		lv_style_set_transform_zoom( &this->_style, part, zoom );
	}

	/* Set padding
	 * -> pad : all directions
	 * -> h,v: horizontal and vertical
	 * -> top,bottom,left,right
	 * -> uint8_t part (only if 4 padding provided)
	 */
	void setPadding( lv_style_int_t pad ) { this->setPadding( pad, pad, pad, pad ); };
	void setPadding( lv_style_int_t h, lv_style_int_t v) { this->setPadding( h, h, v, v ); };
	void setPadding( lv_style_int_t top, lv_style_int_t bottom, lv_style_int_t left, lv_style_int_t right, uint8_t part=LV_OBJ_PART_MAIN );

	void setInnerPadding( lv_style_int_t pad, uint8_t part=LV_OBJ_PART_MAIN );

	/* Set margin 
	 * -> pad : all directions
	 * -> h,v: horizontal and vertical
	 * -> top,bottom,left,right
	 * -> uint8_t part (only if 4 margin provided)
	 * -> int state (default : LV_STATE_DEFAULT)
	 */
	void setMargin( lv_style_int_t pad ) { this->setMargin( pad, pad, pad, pad ); };
	void setMargin( lv_style_int_t h, lv_style_int_t v) { this->setMargin( h, h, v, v ); };
	void setMargin( lv_style_int_t top, lv_style_int_t bottom, lv_style_int_t left, lv_style_int_t right, uint8_t part=LV_OBJ_PART_MAIN );

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
