/************************************************
*	Container : Display zone restricting other objects
*************************************************/

#include "Container.h"
#include "TileView.h"

Container::Container( Container *parent, Container *cloned ){
	this->_obj = lv_cont_create( 
		parent->getMyself(),
		cloned ? cloned->getMyself() : NULL
	);

	if(parent){
		this->copyStyle( parent->getStyle() );
		this->applyStyle();
	}
}

Container::Container( TileView *parent, TileView *cloned ){
	this->_obj = lv_cont_create( 
		parent->getMyself(),
		cloned ? cloned->getMyself() : NULL
	);

	if(parent)
		this->copyStyle( parent->getStyle() );
}

void Container::setTilePos( lv_point_t pos ){
	this->setPosXY( pos.x * lv_obj_get_width(this->getMyself()), pos.y * lv_obj_get_height(this->getMyself()) );
}
