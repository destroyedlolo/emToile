/************************************************
*	Style : Style container
*************************************************/

#include <Style.h>

void Style::setPadding( lv_style_int_t top, lv_style_int_t bottom, lv_style_int_t left, lv_style_int_t right, uint8_t part ){
	lv_style_set_pad_top(this->getStyle(), part, top);
	lv_style_set_pad_bottom(this->getStyle(), part, bottom);
	lv_style_set_pad_left(this->getStyle(), part, left);
	lv_style_set_pad_right(this->getStyle(), part, right);
}

void Style::setInnerPadding( lv_style_int_t pad, uint8_t part ){
	lv_style_set_pad_inner(this->getStyle(), part, pad);
}

void Style::setMargin( lv_style_int_t top, lv_style_int_t bottom, lv_style_int_t left, lv_style_int_t right, uint8_t part ){
	lv_style_set_margin_top(this->getStyle(), part, top);
	lv_style_set_margin_bottom(this->getStyle(), part, bottom);
	lv_style_set_margin_left(this->getStyle(), part, left);
	lv_style_set_margin_right(this->getStyle(), part, right);
}
