/************************************************
*	Gfx object abstraction
*
*	contains methods shared by all objects
*************************************************/
#ifndef GFXOBJ_H
#define GFXOBJ_H

#include <Arduino.h>
#include <Style.h>

#include <lvgl/lvgl.h>

class Container;
class Label;
class Image;
class DropDown;

class GfxObject {
protected:
	lv_obj_t 	*_obj;

public:
	virtual lv_obj_t *getMyself( void ){ return this->_obj; }
	lv_obj_t *operator*(){ return this->getMyself(); }

	virtual ~GfxObject(){
		lv_obj_del( this->_obj );
	}

	/***
	 * Position related
	 *
	 * Notez-bien : positions are _ALWAYS_ related to object's parent
	 ***/

	/* set position
	 * 	lv_coord_t x,y
	 */
	void setX( lv_coord_t x ){
		lv_obj_set_x( this->getMyself(), x );
	}

	void setY( lv_coord_t y ){
		lv_obj_set_y( this->getMyself(), y );
	}

	void setPosXY( lv_coord_t x, lv_coord_t y ){
		lv_obj_set_pos( this->getMyself(), x, y );
	}
	
	/* get position
	 */
	lv_coord_t getX( void ){
		return lv_obj_get_x( this->getMyself() );
	}

	lv_coord_t getY( void ){
		return lv_obj_get_y( this->getMyself() );
	}

	/***
	 * Size related
	 ***/

	/* Get object's width
	 * <- lv_coord_t : width
	 */
	lv_coord_t getWidth( void ){
		return lv_obj_get_width( this->getMyself() );
	}

	/* Get object's height
	 * <- lv_coord_t : height
	 */
	lv_coord_t getHeight( void ){
		return lv_obj_get_height( this->getMyself() );
	}

	/* Set object's size
	 * -> lv_coord_t width
	 * -> lv_coord_t height
	 */
	void setSize( lv_coord_t width, lv_coord_t height ){
		lv_obj_set_size( this->getMyself(), width, height );
	}

	void setSize( GfxObject *source ){
		lv_obj_set_size(
			this->getMyself(),
			source->getWidth(), source->getHeight()
		);
	}

	void setWidth( lv_coord_t width ){
		lv_obj_set_width( this->getMyself(), width );
	}

	void setHeight( lv_coord_t height ){
		lv_obj_set_height( this->getMyself(), height );
	}

	/***
	 * Align related
	 ***/

	/* Set Align attribut
	 * -> lv_align_t align : type of alignment
	 * -> const lv_obj_t *base : Pointer to object to align too (default: NULL)
	 * -> lv_coord_t x_mod, y_mod : offsets (default: 0)
	 */
	void Align( lv_align_t align, const lv_obj_t *base=NULL, lv_coord_t x_mod=0, lv_coord_t y_mod=0){
		lv_obj_align( this->getMyself(), base, align, x_mod, y_mod );
	}
	void Align( lv_align_t align, Container *base, lv_coord_t x_mod=0, lv_coord_t y_mod=0);
	void Align( lv_align_t align, Label *base, lv_coord_t x_mod=0, lv_coord_t y_mod=0);
	void Align( lv_align_t align, Image *base, lv_coord_t x_mod=0, lv_coord_t y_mod=0);
	void Align( lv_align_t align, DropDown *base, lv_coord_t x_mod=0, lv_coord_t y_mod=0);

	/* Set Auto-Realign attribut
	 * -> bool activate : if true activate, desactivate otherwise (default: true)
	 */
	void AutoRealign( bool activate=true ){
		lv_obj_set_auto_realign( this->getMyself(), activate );
	}


	/***
	 * Style related
	 ***/

	/* Add a style
	 * -> Style &style : the style to add
	 * -> uint8_t part : which part to update (LV_OBJ_PART_MAIN)
	 *
	 * NOTEZ-BIEN :
	 * 		Ignored if the derived class' getMyself() returns
	 *		something different than NULL
	 */
	void addStyle( Style *style, uint8_t part=LV_OBJ_PART_MAIN ){
		lv_obj_add_style( this->getMyself(), part, style->getStyle() );
	}
	void addStyle( lv_style_t *style, uint8_t part=LV_OBJ_PART_MAIN ){
		lv_obj_add_style( this->getMyself(), part, style );
	}

	/* Reset the given part's style
	 * -> uint8_t part : which part to reset (LV_OBJ_PART_MAIN)
	 */
	void resetStyle( uint8_t part=LV_OBJ_PART_MAIN ){
		lv_obj_reset_style_list( this->getMyself(), part );
	}

	/* Refresh the object as per its styles values
	 * (for example if a style has changed)
	 * -> uint8_t part : which part to refresh (default : all)
	 * -> uint8_t properties : properties to refresh (default : all)
	 */
	void refreshStyle( uint8_t part = LV_OBJ_PART_ALL, uint8_t properties = LV_STYLE_PROP_ALL ){
		lv_obj_refresh_style( this->getMyself(), part, properties );
	}

	/* Set font
	 *
	 * -> lv_font_t *font : font to use
	 * -> uint8_t part (default : LV_OBJ_PART_MAIN)
	 * -> int state (default : LV_STATE_DEFAULT)
	 */
	void seTexttFont( lv_font_t *font, uint8_t part = LV_OBJ_PART_MAIN, int state = LV_STATE_DEFAULT){
		lv_obj_set_style_local_text_font( this->getMyself(), part, state, font );
	}

	/* Set text color
	 * -> lv_color_t color
	 * -> uint8_t part (default : LV_OBJ_PART_MAIN)
	 * -> uint8_t state (default : LV_STATE_DEFAULT)
	 */
	void setTextColor( lv_color_t color, uint8_t part = LV_OBJ_PART_MAIN, uint8_t state=LV_STATE_DEFAULT ){
		lv_obj_set_style_local_text_color( this->getMyself(), part, state, color );
	}

	/* Set padding 
	 * -> pad : all directions
	 * -> h,v: horizontal and vertical
	 * -> top,bottom,left,right
	 * -> uint8_t part (only if 4 padding provided)
	 * -> int state (default : LV_STATE_DEFAULT)
	 */
	void setPadding( lv_style_int_t pad ) { this->setPadding( pad, pad, pad, pad ); };
	void setPadding( lv_style_int_t h, lv_style_int_t v) { this->setPadding( h, h, v, v ); };
	void setPadding( lv_style_int_t top, lv_style_int_t bottom, lv_style_int_t left, lv_style_int_t right, uint8_t part=LV_OBJ_PART_MAIN, int state=LV_STATE_DEFAULT );

	void setInnerPadding( lv_style_int_t pad, uint8_t part=LV_OBJ_PART_MAIN, int state=LV_STATE_DEFAULT );

	/* Set margin 
	 * -> pad : all directions
	 * -> h,v: horizontal and vertical
	 * -> top,bottom,left,right
	 * -> uint8_t part (only if 4 margin provided)
	 * -> int state (default : LV_STATE_DEFAULT)
	 */
	void setMargin( lv_style_int_t pad ) { this->setMargin( pad, pad, pad, pad ); };
	void setMargin( lv_style_int_t h, lv_style_int_t v) { this->setMargin( h, h, v, v ); };
	void setMargin( lv_style_int_t top, lv_style_int_t bottom, lv_style_int_t left, lv_style_int_t right, uint8_t part=LV_OBJ_PART_MAIN, int state=LV_STATE_DEFAULT );

	/* Set backgound color
	 * -> lv_color_t color
	 * -> uint8_t part (default : LV_OBJ_PART_MAIN)
	 * -> int state (default : LV_STATE_DEFAULT)
	 */
	void setBgColor( lv_color_t color, uint8_t part=LV_OBJ_PART_MAIN, int state=LV_STATE_DEFAULT ){
		lv_obj_set_style_local_bg_color( this->getMyself(), part, state, color );
	}

	/* Set backgound gardian target color
	 * -> lv_color_t color
	 * -> uint8_t part (default : LV_OBJ_PART_MAIN)
	 * -> uint8_t state (default : LV_STATE_DEFAULT)
	 */
	void setBgGradColor( lv_color_t color, uint8_t part=LV_OBJ_PART_MAIN, int state=LV_STATE_DEFAULT ){
		lv_obj_set_style_local_bg_grad_color( this->getMyself(), part, state, color );
	}

	/* Set backgound gardian direction
	 * -> int direction (LV_GRAD_DIR_VER or LV_GRAD_DIR_HOR)
	 * -> uint8_t part (default : LV_OBJ_PART_MAIN)
	 * -> uint8_t state (default : LV_STATE_DEFAULT)
	 */
	void setBgGradDir( int direction, uint8_t part=LV_OBJ_PART_MAIN, int state=LV_STATE_DEFAULT ){
		lv_obj_set_style_local_bg_grad_dir( this->getMyself(), part, state, direction );
	}

	/* where the main color stops and the gradiant start
	 * -> uint8_t where
	 * -> uint8_t part (default : LV_OBJ_PART_MAIN)
	 * -> uint8_t state (default : LV_STATE_DEFAULT)
	 */
	void setBgGradStart( uint8_t where, uint8_t part=LV_OBJ_PART_MAIN, int state=LV_STATE_DEFAULT ){
		lv_obj_set_style_local_bg_main_stop( this->getMyself(), part, state, where );
	}

	/* where the gradiant stops
	 * -> uint8_t where
	 * -> uint8_t part (default : LV_OBJ_PART_MAIN)
	 * -> uint8_t state (default : LV_STATE_DEFAULT)
	 */
	void setBgGradStop( uint8_t where, uint8_t part=LV_OBJ_PART_MAIN, int state=LV_STATE_DEFAULT ){
		lv_obj_set_style_local_bg_grad_stop( this->getMyself(), part, state, where );
	}

	/* Set background opacity
	 * -> uint8_t value
	 * -> uint8_t part (default : LV_OBJ_PART_MAIN)
	 * -> int state (default : LV_STATE_DEFAULT)
	 */
	void setBgOpacity( uint8_t value, uint8_t part=LV_OBJ_PART_MAIN, int state=LV_STATE_DEFAULT ){
		lv_obj_set_style_local_bg_opa( this->getMyself(), part, state, value );
	}

	/* Set caption string (value in LGVL's)
	 * -> const char *txt
	 * -> uint8_t part (default : LV_OBJ_PART_MAIN)
	 * -> int state (default : LV_STATE_DEFAULT)
	 */
	void setCaptionString( const char *txt, uint8_t part=LV_OBJ_PART_MAIN, int state=LV_STATE_DEFAULT ){
		lv_obj_set_style_local_value_str( this->getMyself(), part, state, txt );
	}

	/* Set caption color (value in LGVL's)
	 * -> lv_color_t color
	 * -> uint8_t part (default : LV_OBJ_PART_MAIN)
	 * -> int state (default : LV_STATE_DEFAULT)
	 */
	void setCaptionColor( lv_color_t color, uint8_t part=LV_OBJ_PART_MAIN, int state=LV_STATE_DEFAULT ){
		lv_obj_set_style_local_value_color( this->getMyself(), part, state, color );
	}

	/* Set caption opacity (value in LGVL's)
	 * -> lv_opa_t opacity
	 * -> uint8_t part (default : LV_OBJ_PART_MAIN)
	 * -> int state (default : LV_STATE_DEFAULT)
	 */
	void setCaptionOpacity( lv_opa_t opacity, uint8_t part=LV_OBJ_PART_MAIN, int state=LV_STATE_DEFAULT){
		lv_obj_set_style_local_value_opa( this->getMyself(), part, state, opacity );
	}

	/* Set caption font (value in LGVL's)
	 * -> const lv_font_t *font
	 * -> uint8_t part (default : LV_OBJ_PART_MAIN)
	 * -> int state (default : LV_STATE_DEFAULT)
	 */
	void setCaptionFont( const lv_font_t *font, uint8_t part=LV_OBJ_PART_MAIN, int state=LV_STATE_DEFAULT ){
		lv_obj_set_style_local_value_font( this->getMyself(), part, state, font );
	}

	/* Set caption align (value in LGVL's)
	 * -> lv_align_t align
	 * -> uint8_t part (default : LV_OBJ_PART_MAIN)
	 * -> int state (default : LV_STATE_DEFAULT)
	 */
	void setCaptionAlign( lv_align_t align, uint8_t part=LV_OBJ_PART_MAIN, int state=LV_STATE_DEFAULT ){
		lv_obj_set_style_local_value_align( this->getMyself(), part, state, align );
	}

	/* set caption offset (value in LGVL's)
	 * -> lv_style_int_t offset_x
	 * -> lv_style_int_t offset_y
	 * -> uint8_t part (default : LV_OBJ_PART_MAIN)
	 */
	void setCaptionOffset( lv_style_int_t offset_x, lv_style_int_t offset_y, uint8_t part=LV_OBJ_PART_MAIN, int state=LV_STATE_DEFAULT ){
		lv_obj_set_style_local_value_ofs_x( this->getMyself(), part, state, offset_x );
		lv_obj_set_style_local_value_ofs_y( this->getMyself(), part, state, offset_y );
	}

	/***
	 * Misc
	 ***/

	/* Enable or disable the clicking of an object
	 * if disabled, clicking events are transfered to parent
	 */
	void setClickable( bool en ){
		lv_obj_set_click( this->getMyself(), en );
	}

	/* Set if the object is visible or not
	 * -> bool hidden
	 */
	void setHidden( bool hidden ){
		lv_obj_set_hidden( this->getMyself(), hidden );
	}

	/* Attach a callback event
	 * -> lv_event_cb_t callback
	 */
	void attachEventHandler( lv_event_cb_t callback ){
		lv_obj_set_event_cb( this->getMyself(), callback );
	}

	/* Dump object value
	 * Output on the serial console
	 */
	void dumpObj( const char *name=NULL );
};
#endif
