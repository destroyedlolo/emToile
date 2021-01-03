/************************************************
*	TabView : collection of tabs
*************************************************/

#ifndef TABV_H
#define TABV_H

#include "GfxObject.h"

class TabView : public GfxObject {
public:
	/* TabView constructor
	 * -> lv_obj_t *parent : parent object (default : NULL)
	 * -> const lv_obj_t *cloned : copy from this object (default : NULL)
	 *
	 *  NOTEZ-BIEN : constructor using lv_obj_t as parent doesn't anything
	 *  smart for U. i.e, the style is not copied, scrollbar are visible,
	 *  etc ...
	 */
	TabView( lv_obj_t *parent=NULL, const lv_obj_t *cloned=NULL ){
		this->_obj = lv_tabview_create( parent, cloned );
	}

	/* Add a tab
	 * -> const char *name : Text on the tab button
	 * <- lv_obj_t * : newly created lvgl page for this object
	 *
	 * Dev note : at first, I was thinking to create directly a page Object
	 * here, but it's not smart as it will void all the power of the OOP way
	 * to create page with sub object in the constructor.
	 * So only an Lvgl object pointer is returned and then, a Page needs to 
	 * be created using Page( lv_obj_t *, bool ) constructor.
	 */
	 lv_obj_t *AddTab( const char *name ){
	 	return lv_tabview_add_tab( this->getMyself(), name );
	 }

	/* Flash if an edge is reached
	 * -> bool : true flash, false don't flash
	 */
	void setEdgeFlash( bool en ){
		lv_page_set_edge_flash( this->getMyself(), en );
	}

};

#endif
