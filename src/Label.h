/************************************************
*	Label : display a text
*************************************************/

#ifndef LABEL_H
#define LABEL_H

#include "Container.h"

class Label : public GfxObject {
public:
	/* Container constructor
	 * -> Container *parent : parent object (default : NULL)
	 *  	if not null, its style is copied
	 * -> const lv_obj_t *cloned : copy from this object (default : NULL)
	 */
	Label( lv_obj_t *parent=NULL, const lv_obj_t *cloned=NULL ){
		this->_obj = lv_label_create( parent, cloned );
	}

	Label( GfxObject *parent, GfxObject *cloned=NULL ){
		this->_obj = lv_label_create( 
			parent->getMyself(), 
			cloned ? cloned->getMyself() : NULL
		);
	}

	Label( Style *style, GfxObject *parent, GfxObject *cloned=NULL ) :
		Label( parent, cloned )
	{
		this->addStyle( style );
	}

		/* Set text
		 * -> const char *text
		 */
	void setText( const char *text ){
		lv_label_set_text( this->getMyself(), text );
	}

	void setTextStatic( const char *text ){
		lv_label_set_text_static( this->getMyself(), text );
	}

		/* Enable recoloring
		 * -> bool : true or false depending if you want to recolor
		 */
	void setReColor( bool en ){
		lv_label_set_recolor( this->getMyself(), en );
	}

		/* Set long text mode
		 * -> lv_label_long_mode_t mode
		 *  see : https://docs.lvgl.io/latest/en/html/widgets/label.html
		 */
	void setLongTextMode( lv_label_long_mode_t mode ){
		lv_label_set_long_mode( this->getMyself(), mode );
	}

		/* Set align text inside the lable.
		 *
		 * Notez-bien : to make it working, the size of the label must
		 * be fix, so setLongTextMode( LV_LABEL_LONG_BREAK );
		 */
	void textAlign( lv_label_align_t align ){
		lv_label_set_align( this->getMyself(), align );
	}
};
#endif
