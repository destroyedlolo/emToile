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

	/* Change tab name
	 * -> uint16_t id : index to change
	 * -> char *name
	 */
	void setTabName( uint16_t id, char *name ){
		lv_tabview_set_tab_name( this->getMyself(), id, name );
	}

	/* Delete all children of a tab
	 */
	void DeleteChilds( void ){
		lv_tabview_clean_tab( this->getMyself() );
	}
	void Clean( void ){
		lv_tabview_clean_tab( this->getMyself() );
	}

	/* Set active tab
	 * -> uint16_t id : index of the tab to become active
	 * -> lv_anim_enable_t anim : animation to be done ?
	 *  	LV_ANIM_ON : yes (default)
	 *  	LV_ANIM_OFF : no
	 */
	void setActiveTab( uint16_t id, lv_anim_enable_t anim = LV_ANIM_ON ){
		lv_tabview_set_tab_act( this->getMyself(), id, anim );
	}
	uint16_t getActiveTab( void ){
		return lv_tabview_get_tab_act( this->getMyself() );
	}

	/* set Button position
	 * -> lv_tabview_btns_pos_t btns_pos : button position
	 */
	void setButtonPosition( lv_tabview_btns_pos_t btns_pos ){
		return lv_tabview_set_btns_pos( this->getMyself(), btns_pos );
	}

	/* Flash if an edge is reached
	 * -> bool : true flash, false don't flash
	 */
	void setEdgeFlash( bool en ){
		lv_page_set_edge_flash( this->getMyself(), en );
	}

};

#endif
