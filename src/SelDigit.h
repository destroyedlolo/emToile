/************************************************
* Select a digit
*
* it's a container containing a single digit label
* and +/- buttons to increase/decrease the value
*************************************************/

#ifndef SELDIGIT_H
#define SELDIGIT_H

#include <Style.h>
#include <Container.h>
#include <Label.h>

class SelDigit : public Container {
	Label	*incButton;
	Label	*digit;
	Label	*decButton;

	uint8_t val;
	uint8_t min;
	uint8_t max;

	void incVal( lv_obj_t *, lv_event_t event ){
		Serial.print("inc");
	}

public:
	/* SelDigit's constructor
	 *	-> Container *parent : parent object (default : NULL)
	 *  	if not null, its style is copied
	 * -> Container *cloned : copy from this object (default : NULL)
	 */
	SelDigit( lv_obj_t *parent, lv_obj_t *cloned=NULL );
	SelDigit( Style *style, lv_obj_t *parent, lv_obj_t *cloned=NULL ) :
		SelDigit( parent, cloned )
	{
		this->addStyle( style );
		this->incButton->addStyle( style );
		this->decButton->addStyle( style );
	}

	void setButtonStyle( Style *style ){
		this->incButton->addStyle( style );
		this->decButton->addStyle( style );
	}

	/* Limit for this field 
	 *
	 * CAUTION : there is no security at all, the developer is supposed
	 * knowing what he's doing :)
	 */
	void setLimit( uint8_t amin, uint8_t amax ){
		min = amin;
		max = amax;

		this->setValue( this-> val );	// Ensure the value is inside the new boundaries
	}

	void setValue( uint8_t v );

	/******
	 * Event handler
	 * Unfortunately, LVGL's callback can't be an object's method.
	 * So the workaround is to have an external function that dispatch
	 * to objects. See SelDigit.cpp example.
	 ******/

		/* Attach an event handler */
	void attachEventHandler( lv_event_cb_t );

		/* an event has been received
		 * <- true if the event has been treaded
		 * <- false if the event doesn't concern this object
		 */
	bool dispatchEvent( lv_obj_t *, lv_event_t );
};

#endif
