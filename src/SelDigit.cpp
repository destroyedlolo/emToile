/************************************************
* Select a digit
*************************************************/

#include "SelDigit.h"

SelDigit::SelDigit( lv_obj_t *parent, lv_obj_t *cloned ) : 
	Container( parent, cloned ),
	val(0), min(0), max(9)
{
	this->setClickable( false );

	this->AutoRealign();
	this->setSize( 100, 100 );
	this->setFit( LV_FIT_TIGHT );
	this->setLayout( LV_LAYOUT_COLUMN_MID );

	this->incButton = new Label( this );
	this->incButton->setText( "+" );
	this->incButton->setClickable( true );
	
	this->digit = new Label( this );
	this->digit->setText( "?" );

	this->decButton = new Label( this );
	this->decButton->setText( "-" );
	this->decButton->setClickable( true );
}

void SelDigit::setValue( uint8_t v ){
	if(v < min)
		v = min;
	if(v > max)
		v = max;

	char t[] = { (char)(v+'0'), 0 };
	this->digit->setText( t );
}

void SelDigit::attachEventHandler( lv_event_cb_t callback ){
	this->incButton->attachEventHandler( callback );
	this->decButton->attachEventHandler( callback );
}

bool SelDigit::dispatchEvent( lv_obj_t *obj, lv_event_t evt ){
	if( evt == LV_EVENT_CLICKED ){
		Serial.print("click : ");
		if( obj == this->incButton->getMyself() )
			Serial.println("inc");
		if( obj == this->decButton->getMyself() )
			Serial.println("dec");
	}
	return false;
}
