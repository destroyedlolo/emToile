/************************************************
*	Clickable Button
*************************************************/

#include "Button.h"

Button::Button( Container *parent, Container *cloned ){
	this->_obj = lv_btn_create( 
		parent->getMyself(),
		cloned ? cloned->getMyself() : NULL
	);
}

