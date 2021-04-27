/************************************************
*	Gfx object abstraction
*
*	contains methods shared by all objects
*************************************************/
#include <Arduino.h>

#include "GfxObject.h"
#include "Container.h"
#include "Label.h"
#include "Image.h"
#include "DropDown.h"

void GfxObject::Align( lv_align_t align, Container *base, lv_coord_t x_mod, lv_coord_t y_mod){
	lv_obj_align( this->getMyself(), base->getMyself(), align, x_mod, y_mod );
}

void GfxObject::Align( lv_align_t align, Label *base, lv_coord_t x_mod, lv_coord_t y_mod){
	lv_obj_align( this->getMyself(), base->getMyself(), align, x_mod, y_mod );
}

void GfxObject::Align( lv_align_t align, Image *base, lv_coord_t x_mod, lv_coord_t y_mod){
	lv_obj_align( this->getMyself(), base->getMyself(), align, x_mod, y_mod );
}

void GfxObject::Align( lv_align_t align, DropDown *base, lv_coord_t x_mod, lv_coord_t y_mod){
	lv_obj_align( this->getMyself(), base->getMyself(), align, x_mod, y_mod );
}

void GfxObject::setPadding( lv_style_int_t top, lv_style_int_t bottom, lv_style_int_t left, lv_style_int_t right, uint8_t part ){
	lv_obj_set_style_local_pad_top(this->getMyself(), part, LV_STATE_DEFAULT, top);
	lv_obj_set_style_local_pad_bottom(this->getMyself(), part, LV_STATE_DEFAULT, bottom);
	lv_obj_set_style_local_pad_left(this->getMyself(), part, LV_STATE_DEFAULT, left);
	lv_obj_set_style_local_pad_right(this->getMyself(), part, LV_STATE_DEFAULT, right);
}

void GfxObject::setInnerPadding( lv_style_int_t pad, uint8_t part ){
	lv_obj_set_style_local_pad_inner(this->getMyself(), part, LV_STATE_DEFAULT, pad);
}

void GfxObject::dumpObj( const char *name ){
	if( name )
		Serial.print( name );

	Serial.printf(" Geo : %d,%d %dx%d", 
		this->getX(), this->getY(), this->getWidth(), this->getHeight()
	);

	Serial.printf(" - style sz: %d pad: %d %d %d %d %d mgr: %d %d %d %d opa: %d\n",
		lv_obj_get_style_size(this->getMyself(),  LV_OBJ_PART_MAIN),

		lv_obj_get_style_pad_top(this->getMyself(), LV_OBJ_PART_MAIN),
		lv_obj_get_style_pad_bottom(this->getMyself(), LV_OBJ_PART_MAIN),
		lv_obj_get_style_pad_left(this->getMyself(), LV_OBJ_PART_MAIN),
		lv_obj_get_style_pad_right(this->getMyself(), LV_OBJ_PART_MAIN),
		lv_obj_get_style_pad_inner(this->getMyself(), LV_OBJ_PART_MAIN),

		lv_obj_get_style_margin_top(this->getMyself(), LV_OBJ_PART_MAIN),
		lv_obj_get_style_margin_bottom(this->getMyself(), LV_OBJ_PART_MAIN),
		lv_obj_get_style_margin_left(this->getMyself(), LV_OBJ_PART_MAIN),
		lv_obj_get_style_margin_right(this->getMyself(), LV_OBJ_PART_MAIN),

		lv_obj_get_style_bg_opa(this->getMyself(), LV_OBJ_PART_MAIN)
	);
}
