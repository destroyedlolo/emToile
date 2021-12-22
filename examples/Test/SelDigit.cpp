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
// Label *sdigit;


	/**** 
	 * Build the GUI
	 *****/
void start_gui( void ){
	pg = new Page( lv_scr_act() );
	pg->setSize( 150, 200 );
	pg->Align( LV_ALIGN_CENTER );

	sdigit = new SelDigit( **pg );
}
