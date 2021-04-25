/************************************************
*	Container : Display zone restricting other objects
*************************************************/

#ifndef CONT_H
#define CONT_H

#include <Arduino.h>

#include "GfxObject.h"

class TileView;

class Container : public GfxObject {
public:

	/* Container constructor
	 * -> lv_obj_t *parent : parent object (default : NULL)
	 * -> const lv_obj_t *cloned : copy from this object (default : NULL)
	 */
	Container( lv_obj_t *parent=NULL, const lv_obj_t *cloned=NULL ){
		this->_obj = lv_cont_create( parent, cloned );
	}

	Container( Container *parent, Container *cloned=NULL );
	Container( TileView *parent, TileView *cloned=NULL );

	/* Set layout policy
	 * lv_layout_t layout
	 */
	void setLayout( lv_layout_t layout ){
		lv_cont_set_layout( this->getMyself(), layout );
	}

	/* Set the fit policy
	 *	-> lv_fit_t all : policy in all directions
	 *	-> lv_fit_t hor,ver
	 *	-> lv_fit_t left, right, top, bottom
	 */
	void setFit( lv_fit_t all ){
		lv_cont_set_fit( this->getMyself(), all );
	}
	void setFit( lv_fit_t hor, lv_fit_t ver ){
		lv_cont_set_fit2( this->getMyself(), hor, ver );
	}
	void setFit( lv_fit_t left, lv_fit_t right, lv_fit_t top, lv_fit_t bottom ){
		lv_cont_set_fit4( this->getMyself(), left, right, top, bottom );
	}

	/*	set position as a tile
	 * 	lv_point_t pos
	 *
	 * 	CAUTION : works only if the tile has the size of its tileview
	 */
	void setTilePos( lv_point_t pos );
};
#endif
