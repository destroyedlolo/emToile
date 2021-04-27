/************************************************
*	DropDown : Drop down list to select a value
*************************************************/

#ifndef DROPDOWN_H
#define DROPDOWN_H

#include "Container.h"

class DropDown : public GfxObject {
public:
	/* Container constructor
	 * -> Container *parent : parent object (default : NULL)
	 *  	if not null, its style is copied
	 * -> const lv_obj_t *cloned : copy from this object (default : NULL)
	 */
	DropDown( lv_obj_t *parent=NULL, const lv_obj_t *cloned=NULL ){
		this->_obj = lv_dropdown_create( parent, cloned );
	}

	DropDown( Container *parent, DropDown *cloned=NULL ){
		this->_obj = lv_dropdown_create( 
			parent->getMyself(), 
			cloned ? cloned->getMyself() : NULL
		);

		this->copyStyle( parent->getStyle() );
		this->applyStyle();
	}

	/* Set the text of the list
	 *
	 * CAUTION : the text is NOT COPIED, only a reference (pointer)
	 */
	void setTextStatic( const char *txt ){
		lv_dropdown_set_text( this->getMyself(), txt );
	}

	/* Set choices from a string
	 *
	 * 	-> const char *txt : '\n' separated list of choice
	 * 	-> bool _static (default = false) : if true, only a reference to
	 * 	the string is used. So it has to remain as long as the DropDown.
	 */
	void setChoices( const char *txt, bool _static=false ){
		if( _static )
			lv_dropdown_set_options_static( this->getMyself(), txt );
		else
			lv_dropdown_set_options( this->getMyself(), txt );
	}

	/* Add an additional choice
	 *
	 * -> const char *txt : option to add
	 * -> uint32_t pos : where to put the option
	 *  	0 : first
	 *		LV_DROPDOWN_POS_LAST : last one (default)
	 *
	 * Notez-bien : works only if the dropdown is dynamic
	 */
	void addChoice( const char *txt, uint32_t pos=LV_DROPDOWN_POS_LAST){
		lv_dropdown_add_option( this->getMyself(), txt, pos );
	}

	/* Empty choices list
	 */
	void clear( void ){
		lv_dropdown_clear_options( this->getMyself() );
	}

	/* Set selected choice
	 *
	 * -> uint16_t pos : the position, starting 0
	 */
	void setSelected( uint16_t pos ){
		lv_dropdown_set_selected( this->getMyself(), pos );
	}

	/* Do we have to highlight the last selected choice
	 *
	 * -> bool show
	 */
	void setShow( bool show ){
		lv_dropdown_set_show_selected( this->getMyself(), show );
	}

	/* get selected choice
	 *
	 * <- uint16_t : order starting 0
	 * <- const char * (if text)
	 */
	uint16_t getSelected( void ){
		return lv_dropdown_get_selected( this->getMyself() );
	}
	const char *getSelectedText( void ){
		return lv_dropdown_get_text( this->getMyself() );
	}
	
};

#endif
