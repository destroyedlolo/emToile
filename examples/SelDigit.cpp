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
Style *myStyle;

	/**** 
	 * Build the GUI
	 *****/

	/* As LVGL callbacks can't be an object's method, we have to cheat a bit :
	 * we are calling each SelDigit's dispatchEvent() until one replies 'true'
	 * meaning the event has been processed.
	 * In this example, only one is used, but if 3 are used, the code will be :
	 *  if(!sdigit->dispatchEvent( object, event ))
	 *  	if(!sdigit2->dispatchEvent( object, event ))
	 *  		sdigit3->dispatchEvent( object, event );
	 */
void clicked( lv_obj_t *object, lv_event_t event ){
	sdigit->dispatchEvent( object, event );
}

void start_gui( void ){
	pg = new Page( lv_scr_act() );
	pg->setSize( 150, 200 );
	pg->Align( LV_ALIGN_CENTER );

	myStyle = new Style();
	myStyle->setBorderColor( LV_COLOR_BLACK );

	sdigit = new SelDigit( myStyle, **pg );
	sdigit->attachEventHandler( clicked );	// Attache the generic handler
}
