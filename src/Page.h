/************************************************
*	Page : scrollable area
*************************************************/

#ifndef PAGE_H
#define PAGE_H

#include "GfxObject.h"

class Page : public GfxObject {
public:
	/* Page constructor
	 * -> lv_obj_t *parent : parent object (default : NULL)
	 * -> const lv_obj_t *cloned : copy from this object (default : NULL)
	 *
	 *  NOTEZ-BIEN : constructor using lv_obj_t as parent doesn't anything
	 *  smart for U. i.e, the style is not copied, scrollbar are visible,
	 *  etc ...
	 */
	Page( lv_obj_t *parent=NULL, const lv_obj_t *cloned=NULL ){
		this->_obj = lv_page_create( parent, cloned );
	}

	/* As page can be created by 'externals' we need this default constructor
	 * which is creating an invalid object.
	 * CAUTION : using it as it is will wake up the Guru ! You've been warned
	 * initFromExternal() has to be called first
	 */
	Page(){
		this->_obj = NULL;
	}
	void initFromExternal(lv_obj_t *p){
		this->_obj = p;
	}

	/* last but not least, this one initialize the object from an already
	 * existing LVGL one.
	 * -> lv_obj_t * p : pointer to an lvgl's page
	 * -> boot fake : only to differentiate against the 1st constructor
	 */
	Page( lv_obj_t *p, bool ){
		this->_obj = p;
	}

	/* Set anim time
	 * -> uint16_t time in ms
	 */
	void setAnimTime( uint16_t time ){
		lv_page_set_anim_time( this->getMyself(), time );
	}

	uint16_t getAnimTime( void ){
		return lv_page_get_anim_time( this->getMyself() );
	}

	/* Set scroll bar show policy
	 * -> lv_scrollbar_mode_t mode ! mode to apply
	 */
	void SetScrollbarMode( lv_scrollbar_mode_t mode ){
		lv_page_set_scrlbar_mode( this->getMyself(), mode );
	}

	/* Enable the scroll propagation feature
	 * If enabled, the page will move its parent if there is no more
	 * space to scroll
	 * -> bool enable or not
	 */
	void setScrollPropagation( bool en ){
		lv_page_set_scroll_propagation( this->getMyself(), en );
	}

	/* Set width of the scrollable part of a page
	 * -> lv_coord_t width
	 */
	void setScrollWidth( lv_coord_t w ){
		lv_page_set_scrl_width( this->getMyself(), w );
	}

	/* Set height of the scrollable part of a page
	 * -> lv_coord_t height
	 */
	void setScrollHeight( lv_coord_t h ){
		lv_page_set_scrl_height( this->getMyself(), h );
	}

	/* Flash if an edge is reached
	 * -> bool : true flash, false don't flash
	 */
	void setEdgeFlash( bool en ){
		lv_page_set_edge_flash( this->getMyself(), en );
	}

	/* Get that width which fit in the visible area
	 * <- lv_coord_t width
	 */
	lv_coord_t getWidthFit( void ){
		return lv_page_get_width_fit( this->getMyself() );
	}

	/* Get that height which fit in the visible area
	 * <- lv_coord_t height
	 */
	lv_coord_t getHeightFit( void ){
		return lv_page_get_height_fit( this->getMyself() );
	}
};

#endif
