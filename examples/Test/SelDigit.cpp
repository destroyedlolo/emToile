/********************************************************************
* SelDigit's test
*
* Create a SelDigit in the middle of the screen
*********************************************************************/

#include <Page.h>
#include <SelDigit.h>

	/*****
	 * objects
	 *****/

Page *pg;
SelDigit *sdigit;


	/**** 
	 * Build the GUI
	 *****/

void clicked( lv_obj_t *object, lv_event_t event ){
	sdigit->dispatchEvent( object, event );
}

void start_gui( void ){
	pg = new Page( lv_scr_act() );
	pg->setSize( 150, 200 );
	pg->Align( LV_ALIGN_CENTER );

	sdigit = new SelDigit( **pg );
	sdigit->attachEventHandler( clicked );
}
