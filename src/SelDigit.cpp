/************************************************
* Select a digit
*************************************************/

#include "SelDigit.h"

SelDigit::SelDigit( lv_obj_t *parent, lv_obj_t *cloned ) : 
	Container( parent, cloned ),
	val(0), min(0), max(9)
{
	this->AutoRealign();
	this->setSize( 100, 100 );
	this->setFit( LV_FIT_TIGHT );
	this->setLayout( LV_LAYOUT_COLUMN_MID );

	this->incButton = new Label( this );
	this->incButton->setText( "+" );
	
	this->digit = new Label( this );
	this->digit->setText( "?" );

	this->decButton = new Label( this );
	this->decButton->setText( "-" );
}

void SelDigit::setValue( uint8_t v ){
	if(v < min)
		v = min;
	if(v > max)
		v = max;

	char t[] = { (char)(v+'0'), 0 };
	this->digit->setText( t );
}
