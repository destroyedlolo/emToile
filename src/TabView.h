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
};

#endif
