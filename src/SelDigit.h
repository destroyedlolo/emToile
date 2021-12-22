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
};

#endif
