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

	/* Set text color
	 * -> lv_color_t color
	 * -> uint8_t part (default : LV_OBJ_PART_MAIN)
	 */
	void setTextColor( lv_color_t color, uint8_t part=LV_OBJ_PART_MAIN ){
		lv_style_set_text_color( &this->_style, part, color );
	}

	/* Set text opacity
	 * -> uint8_t value
	 * -> uint8_t part (default : LV_OBJ_PART_MAIN)
	 */
	void setTextOpacity( uint8_t value, uint8_t part=LV_OBJ_PART_MAIN ){
		lv_style_set_text_opa( &this->_style, part, value );
	}

	/* Set text font
	 * -> lv_font_t *font : font to use
	 * -> int state (default : LV_STATE_DEFAULT)
	 */
	void setFont( lv_font_t *font, int state=LV_STATE_DEFAULT ){
		lv_style_set_text_font( &this->_style, state, font );
	}

	/* Set text decoration
	 * -> lv_text_decor_t decoration
	 * -> int state (default : LV_STATE_DEFAULT)
	 */
	void setTextDecoration( lv_text_decor_t decoration, int state=LV_STATE_DEFAULT ){
		lv_style_set_text_decor( &this->_style, state, decoration );
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
	 * -> uint8_t part (default : LV_OBJ_PART_MAIN)
	 */
	void setBgColor( lv_color_t color, uint8_t part=LV_OBJ_PART_MAIN ){
		lv_style_set_bg_color( &this->_style, part, color );
	}

	/* Set background opacity
	 * -> uint8_t value
	 * -> uint8_t part (default : LV_OBJ_PART_MAIN)
	 */
	void setBgOpacity( uint8_t value, uint8_t part=LV_OBJ_PART_MAIN ){
		lv_style_set_bg_opa( &this->_style, part, value );
	}

	/* set border color
	 * -> lv_color_t color
	 * -> uint8_t part (default : LV_OBJ_PART_MAIN)
	 */
	void setBorderColor( lv_color_t color, uint8_t part=LV_OBJ_PART_MAIN ){
		lv_style_set_border_color( &this->_style, part, color );
	}

	/* set border width
	 * -> lv_style_int_t value
	 * -> uint8_t part (default : LV_OBJ_PART_MAIN)
	 */
	void setBorderWidth( lv_style_int_t value, uint8_t part=LV_OBJ_PART_MAIN){
		lv_style_set_border_width( &this->_style, part, value );
	}

	/* set shadow color
	 * -> lv_color_t color
	 * -> uint8_t part (default : LV_OBJ_PART_MAIN)
	 */
	void setShadowColor( lv_color_t color, uint8_t part=LV_OBJ_PART_MAIN ){
		lv_style_set_shadow_color( &this->_style, part, color );
	}

	/* set shadow opacity 
	 * -> lv_color_t color
	 * -> uint8_t part (default : LV_OBJ_PART_MAIN)
	 */
	void setShadowOpacity( lv_opa_t opa, uint8_t part=LV_OBJ_PART_MAIN ){
		lv_style_set_shadow_opa( &this->_style, part, opa );
	}

	/* set shadow width
	 * -> lv_style_int_t value
	 * -> uint8_t part (default : LV_OBJ_PART_MAIN)
	 */
	void setShadowWidth( lv_style_int_t value, uint8_t part=LV_OBJ_PART_MAIN){
		lv_style_set_shadow_width( &this->_style, part, value );
	}

	/* set shadow offset
	 * -> lv_style_int_t offset_x
	 * -> lv_style_int_t offset_y
	 * -> uint8_t part (default : LV_OBJ_PART_MAIN)
	 */
	void setShadowOffset( lv_style_int_t offset_x, lv_style_int_t offset_y, uint8_t part=LV_OBJ_PART_MAIN){
		lv_style_set_shadow_ofs_x( &this->_style, part, offset_x );
		lv_style_set_shadow_ofs_y( &this->_style, part, offset_y );
	}

	/* set shadow spread
	 * -> lv_style_int_t value
	 * -> uint8_t part (default : LV_OBJ_PART_MAIN)
	 */
	void setShadowSpread( lv_style_int_t value, uint8_t part=LV_OBJ_PART_MAIN){
		lv_style_set_shadow_spread( &this->_style, part, value );
	}

	/* Set caption string (value in LGVL's)
	 * -> const char *txt
	 * -> uint8_t part (default : LV_OBJ_PART_MAIN)
	 */
	void setCaptionString( const char *txt, uint8_t part=LV_OBJ_PART_MAIN){
		lv_style_set_value_str( &this->_style, part, txt );
	}

	/* Set caption color (value in LGVL's)
	 * -> lv_color_t color
	 * -> uint8_t part (default : LV_OBJ_PART_MAIN)
	 */
	void setCaptionColor( lv_color_t color, uint8_t part=LV_OBJ_PART_MAIN){
		lv_style_set_value_color( &this->_style, part, color );
	}

	/* Set caption opacity (value in LGVL's)
	 * -> lv_opa_t opacity
	 * -> uint8_t part (default : LV_OBJ_PART_MAIN)
	 */
	void setCaptionOpacity( lv_opa_t opacity, uint8_t part=LV_OBJ_PART_MAIN){
		lv_style_set_value_opa( &this->_style, part, opacity );
	}

	/* Set caption font (value in LGVL's)
	 * -> const lv_font_t *font
	 * -> uint8_t part (default : LV_OBJ_PART_MAIN)
	 */
	void setCaptionFont( const lv_font_t *font, uint8_t part=LV_OBJ_PART_MAIN){
		lv_style_set_value_font( &this->_style, part, font );
	}

	/* Set caption align (value in LGVL's)
	 * -> lv_align_t align
	 * -> uint8_t part (default : LV_OBJ_PART_MAIN)
	 */
	void setCaptionAlign( lv_align_t align, uint8_t part=LV_OBJ_PART_MAIN){
		lv_style_set_value_align( &this->_style, part, align );
	}

	/* set caption offset (value in LGVL's)
	 * -> lv_style_int_t offset_x
	 * -> lv_style_int_t offset_y
	 * -> uint8_t part (default : LV_OBJ_PART_MAIN)
	 */
	void setCaptionOffset( lv_style_int_t offset_x, lv_style_int_t offset_y, uint8_t part=LV_OBJ_PART_MAIN){
		lv_style_set_value_ofs_x( &this->_style, part, offset_x );
		lv_style_set_value_ofs_y( &this->_style, part, offset_y );
	}

	/* Set line color
	 * -> lv_color_t color
	 * -> uint8_t part (default : LV_OBJ_PART_MAIN)
	 */
	void setLineColor( lv_color_t color, uint8_t part=LV_OBJ_PART_MAIN){
		lv_style_set_line_color( &this->_style, part, color );
	}

	/* Set line opacity
	 * -> lv_opa_t opacity
	 * -> uint8_t part (default : LV_OBJ_PART_MAIN)
	 */
	void setLineOpacity( lv_opa_t opacity, uint8_t part=LV_OBJ_PART_MAIN){
		lv_style_set_line_opa( &this->_style, part, opacity );
	}

	/* set line width
	 * -> lv_style_int_t value
	 * -> uint8_t part (default : LV_OBJ_PART_MAIN)
	 */
	void setLineWidth( lv_style_int_t value, uint8_t part=LV_OBJ_PART_MAIN){
		lv_style_set_line_width( &this->_style, part, value );
	}

	/* set line dash width
	 * -> lv_style_int_t value
	 * -> uint8_t part (default : LV_OBJ_PART_MAIN)
	 */
	void setLineDashWidth( lv_style_int_t value, uint8_t part=LV_OBJ_PART_MAIN){
		lv_style_set_line_dash_width( &this->_style, part, value );
	}

	/* set line dash gap
	 * -> lv_style_int_t value
	 * -> uint8_t part (default : LV_OBJ_PART_MAIN)
	 */
	void setLineDashGap( lv_style_int_t value, uint8_t part=LV_OBJ_PART_MAIN){
		lv_style_set_line_dash_gap( &this->_style, part, value );
	}

	/* set line rounded
	 * -> bool value (default : true)
	 * -> uint8_t part (default : LV_OBJ_PART_MAIN)
	 */
	void setLineRounded( bool value=true, uint8_t part=LV_OBJ_PART_MAIN){
		lv_style_set_line_rounded( &this->_style, part, value );
	}
};

#endif
