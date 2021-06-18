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

	/* Copy a style to local one
	 * -> lv_style_t *style : original style to copy from
	 */
	void copyStyle( lv_style_t *style ){
		lv_style_copy( &this->_style, style );
	}
	void copyStyle( Style *style ){
		lv_style_copy( &this->_style, &style->_style );
	}

	/* Reset the style a free all used ressources */
	void Reset( void ){
		lv_style_reset( &this->_style );
	}

	/* Set text color
	 * -> lv_color_t color
	 * -> uint8_t state (default : LV_STATE_DEFAULT)
	 */
	void setTextColor( lv_color_t color, uint8_t state=LV_STATE_DEFAULT ){
		lv_style_set_text_color( &this->_style, state, color );
	}

	/* Set text opacity
	 * -> uint8_t value
	 * -> uint8_t state (default : LV_STATE_DEFAULT)
	 */
	void setTextOpacity( uint8_t value, uint8_t state=LV_STATE_DEFAULT ){
		lv_style_set_text_opa( &this->_style, state, value );
	}

	/* Set text font
	 * -> lv_font_t *font : font to use
	 * -> int state (default : LV_STATE_DEFAULT)
	 */
	void seTexttFont( lv_font_t *font, int state=LV_STATE_DEFAULT ){
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
	 * -> int state (default : LV_STATE_DEFAULT)
	 */
	void setImageRecolor( lv_color_t color, uint8_t state=LV_STATE_DEFAULT ){
		lv_style_set_image_recolor( &this->_style, state, color );
	}

	/* Image recolor opacity
	 * -> lv_opa_t value
	 * -> int state (default : LV_STATE_DEFAULT)
	 */
	void setImageRecolorOpacity( lv_opa_t value, uint8_t state=LV_STATE_DEFAULT ){
		lv_style_set_image_recolor_opa( &this->_style, state, value );
	}
	void setIntensity( uint32_t intense=LV_OPA_COVER, uint8_t state=LV_STATE_DEFAULT ){
		lv_style_set_image_recolor_opa( &this->_style, state, intense );	
	}

	/* Image opacity
	 * -> lv_opa_t value
	 * -> int state (default : LV_STATE_DEFAULT)
	 */
	void setImageOpacity( lv_opa_t value, uint8_t state=LV_STATE_DEFAULT ){
		lv_style_set_image_opa( &this->_style, state, value );
	}

	/* Image blend mode
	 * -> lv_blend_mode_t value
	 * -> int state (default : LV_STATE_DEFAULT)
	 */
	void setImageBlendMode( lv_blend_mode_t value, uint8_t state=LV_STATE_DEFAULT ){
		lv_style_set_image_blend_mode( &this->_style, state, value );
	}

	/* Set radius
	 * -> lv_style_int_t size
	 * -> int state (default : LV_STATE_DEFAULT)
	 */
	void setRadius( lv_style_int_t size, uint8_t state=LV_STATE_DEFAULT){
		lv_style_set_radius( &this->_style, state, size );
	}

	/* Enlarge the object (by axis)
	 * -> lv_style_int_t hfactor : horizontal factor
	 * -> lv_style_int_t vfactor : vertical factor
	 *		0 : original size
	 * -> int state (default : LV_STATE_DEFAULT)
	 */
	void Enlarge( lv_style_int_t hfactor, lv_style_int_t vfactor, uint8_t state=LV_STATE_DEFAULT ){
		lv_style_set_transform_width( &this->_style, state, hfactor );
		lv_style_set_transform_height( &this->_style, state, vfactor );
	}

	/* Zoom the object
	 * -> lv_style_int_t zoom : zoom factor
	 *  	The reference is 256 (or LV_IMG_ZOOM_NONE), so
	 *  		128 is 1/2
	 *  		512 is x2
	 * -> int state (default : LV_STATE_DEFAULT)
	 */
	void Zoom( lv_style_int_t zoom, uint8_t state=LV_STATE_DEFAULT ){
		lv_style_set_transform_zoom( &this->_style, state, zoom );
	}

	/* Set padding
	 * -> pad : all directions
	 * -> h,v: horizontal and vertical
	 * -> top,bottom,left,right
	 * -> int state (default : LV_STATE_DEFAULT)
	 */
	void setPadding( lv_style_int_t pad ) { this->setPadding( pad, pad, pad, pad ); };
	void setPadding( lv_style_int_t h, lv_style_int_t v) { this->setPadding( h, h, v, v ); };
	void setPadding( lv_style_int_t top, lv_style_int_t bottom, lv_style_int_t left, lv_style_int_t right, uint8_t state=LV_STATE_DEFAULT );

	void setInnerPadding( lv_style_int_t pad, uint8_t state=LV_STATE_DEFAULT );

	/* Set margin 
	 * -> pad : all directions
	 * -> h,v: horizontal and vertical
	 * -> top,bottom,left,right
	 * -> int state (default : LV_STATE_DEFAULT)
	 */
	void setMargin( lv_style_int_t pad ) { this->setMargin( pad, pad, pad, pad ); };
	void setMargin( lv_style_int_t h, lv_style_int_t v) { this->setMargin( h, h, v, v ); };
	void setMargin( lv_style_int_t top, lv_style_int_t bottom, lv_style_int_t left, lv_style_int_t right, uint8_t state=LV_STATE_DEFAULT );

	/* Set backgound color
	 * -> lv_color_t color
	 * -> uint8_t state (default : LV_STATE_DEFAULT)
	 */
	void setBgColor( lv_color_t color, int state=LV_STATE_DEFAULT ){
		lv_style_set_bg_color( &this->_style, state, color );
	}

	/* Set backgound gardian target color
	 * -> lv_color_t color
	 * -> uint8_t state (default : LV_STATE_DEFAULT)
	 */
	void setBgGradColor( lv_color_t color, int state=LV_STATE_DEFAULT ){
		lv_style_set_bg_grad_color( &this->_style, state, color );
	}

	/* Set backgound gardian direction
	 * -> int direction (LV_GRAD_DIR_VER or LV_GRAD_DIR_HOR)
	 * -> uint8_t state (default : LV_STATE_DEFAULT)
	 */
	void setBgGradDir( int direction, int state=LV_STATE_DEFAULT ){
		lv_style_set_bg_grad_dir( &this->_style, state, direction );
	}

	/* where the main color stops and the gradiant start
	 * -> uint8_t where
	 * -> uint8_t state (default : LV_STATE_DEFAULT)
	 */
	void setBgGradStart( uint8_t where, int state=LV_STATE_DEFAULT ){
		lv_style_set_bg_main_stop( &this->_style, state, where );
	}

	/* where the gradiant stops
	 * -> uint8_t where
	 * -> uint8_t state (default : LV_STATE_DEFAULT)
	 */
	void setBgGradStop( uint8_t where, int state=LV_STATE_DEFAULT ){
		lv_style_set_bg_grad_stop( &this->_style, state, where );
	}

	/* Set background opacity
	 * -> uint8_t value
	 * -> uint8_t state (default : LV_STATE_DEFAULT)
	 */
	void setBgOpacity( uint8_t value, uint8_t state=LV_STATE_DEFAULT ){
		lv_style_set_bg_opa( &this->_style, state, value );
	}

	/* set border color
	 * -> lv_color_t color
	 * -> uint8_t state (default : LV_STATE_DEFAULT)
	 */
	void setBorderColor( lv_color_t color, uint8_t state=LV_STATE_DEFAULT ){
		lv_style_set_border_color( &this->_style, state, color );
	}

	/* set border width
	 * -> lv_style_int_t value
	 * -> uint8_t state (default : LV_STATE_DEFAULT)
	 */
	void setBorderWidth( lv_style_int_t value, uint8_t state=LV_STATE_DEFAULT){
		lv_style_set_border_width( &this->_style, state, value );
	}

	/* set shadow color
	 * -> lv_color_t color
	 * -> uint8_t state (default : LV_STATE_DEFAULT)
	 */
	void setShadowColor( lv_color_t color, uint8_t state=LV_STATE_DEFAULT ){
		lv_style_set_shadow_color( &this->_style, state, color );
	}

	/* set shadow opacity 
	 * -> lv_color_t color
	 * -> uint8_t state (default : LV_STATE_DEFAULT)
	 */
	void setShadowOpacity( lv_opa_t opa, uint8_t state=LV_STATE_DEFAULT ){
		lv_style_set_shadow_opa( &this->_style, state, opa );
	}

	/* set shadow width
	 * -> lv_style_int_t value
	 * -> uint8_t state (default : LV_STATE_DEFAULT)
	 */
	void setShadowWidth( lv_style_int_t value, uint8_t state=LV_STATE_DEFAULT){
		lv_style_set_shadow_width( &this->_style, state, value );
	}

	/* set shadow offset
	 * -> lv_style_int_t offset_x
	 * -> lv_style_int_t offset_y
	 * -> uint8_t state (default : LV_STATE_DEFAULT)
	 */
	void setShadowOffset( lv_style_int_t offset_x, lv_style_int_t offset_y, uint8_t state=LV_STATE_DEFAULT){
		lv_style_set_shadow_ofs_x( &this->_style, state, offset_x );
		lv_style_set_shadow_ofs_y( &this->_style, state, offset_y );
	}

	/* set shadow spread
	 * -> lv_style_int_t value
	 * -> uint8_t state (default : LV_STATE_DEFAULT)
	 */
	void setShadowSpread( lv_style_int_t value, uint8_t state=LV_STATE_DEFAULT){
		lv_style_set_shadow_spread( &this->_style, state, value );
	}

	/* Set caption string (value in LGVL's)
	 * -> const char *txt
	 * -> uint8_t state (default : LV_STATE_DEFAULT)
	 */
	void setCaptionString( const char *txt, uint8_t state=LV_STATE_DEFAULT){
		lv_style_set_value_str( &this->_style, state, txt );
	}

	/* Set caption color (value in LGVL's)
	 * -> lv_color_t color
	 * -> uint8_t state (default : LV_STATE_DEFAULT)
	 */
	void setCaptionColor( lv_color_t color, uint8_t state=LV_STATE_DEFAULT){
		lv_style_set_value_color( &this->_style, state, color );
	}

	/* Set caption opacity (value in LGVL's)
	 * -> lv_opa_t opacity
	 * -> uint8_t state (default : LV_STATE_DEFAULT)
	 */
	void setCaptionOpacity( lv_opa_t opacity, uint8_t state=LV_STATE_DEFAULT){
		lv_style_set_value_opa( &this->_style, state, opacity );
	}

	/* Set caption font (value in LGVL's)
	 * -> const lv_font_t *font
	 * -> uint8_t state (default : LV_STATE_DEFAULT)
	 */
	void setCaptionFont( const lv_font_t *font, uint8_t state=LV_STATE_DEFAULT){
		lv_style_set_value_font( &this->_style, state, font );
	}

	/* Set caption align (value in LGVL's)
	 * -> lv_align_t align
	 * -> uint8_t state (default : LV_STATE_DEFAULT)
	 */
	void setCaptionAlign( lv_align_t align, uint8_t state=LV_STATE_DEFAULT){
		lv_style_set_value_align( &this->_style, state, align );
	}

	/* set caption offset (value in LGVL's)
	 * -> lv_style_int_t offset_x
	 * -> lv_style_int_t offset_y
	 * -> uint8_t state (default : LV_STATE_DEFAULT)
	 */
	void setCaptionOffset( lv_style_int_t offset_x, lv_style_int_t offset_y, uint8_t state=LV_STATE_DEFAULT){
		lv_style_set_value_ofs_x( &this->_style, state, offset_x );
		lv_style_set_value_ofs_y( &this->_style, state, offset_y );
	}

	/* Set line color
	 * -> lv_color_t color
	 * -> uint8_t state (default : LV_STATE_DEFAULT)
	 */
	void setLineColor( lv_color_t color, uint8_t state=LV_STATE_DEFAULT){
		lv_style_set_line_color( &this->_style, state, color );
	}

	/* Set line opacity
	 * -> lv_opa_t opacity
	 * -> uint8_t state (default : LV_STATE_DEFAULT)
	 */
	void setLineOpacity( lv_opa_t opacity, uint8_t state=LV_STATE_DEFAULT){
		lv_style_set_line_opa( &this->_style, state, opacity );
	}

	/* set line width
	 * -> lv_style_int_t value
	 * -> uint8_t state (default : LV_STATE_DEFAULT)
	 */
	void setLineWidth( lv_style_int_t value, uint8_t state=LV_STATE_DEFAULT){
		lv_style_set_line_width( &this->_style, state, value );
	}

	/* set line dash width
	 * -> lv_style_int_t value
	 * -> uint8_t state (default : LV_STATE_DEFAULT)
	 */
	void setLineDashWidth( lv_style_int_t value, uint8_t state=LV_STATE_DEFAULT){
		lv_style_set_line_dash_width( &this->_style, state, value );
	}

	/* set line dash gap
	 * -> lv_style_int_t value
	 * -> uint8_t state (default : LV_STATE_DEFAULT)
	 */
	void setLineDashGap( lv_style_int_t value, uint8_t state=LV_STATE_DEFAULT){
		lv_style_set_line_dash_gap( &this->_style, state, value );
	}

	/* set line rounded
	 * -> bool value (default : true)
	 * -> uint8_t state (default : LV_STATE_DEFAULT)
	 */
	void setLineRounded( bool value=true, uint8_t state=LV_STATE_DEFAULT){
		lv_style_set_line_rounded( &this->_style, state, value );
	}
};

#endif
