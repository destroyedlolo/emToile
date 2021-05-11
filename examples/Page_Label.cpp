/********************************************************************
* Label's test
*
* Create a Label in the middle of the screen
*********************************************************************/

#include <Page.h>
#include <Label.h>

	/*****
	 * objects
	 *****/

Page *pg;
Label *lbl;


	/**** 
	 * Build the GUI
	 *****/
void start_gui( void ){
	pg = new Page( lv_scr_act() );
	pg->setSize( 150, 200 );
	pg->Align( LV_ALIGN_CENTER );

	lbl = new Label( pg );
	lbl->setLongTextMode( LV_LABEL_LONG_BREAK );
	lbl->setWidth( pg->getWidthFit() );
	lbl->setText("Lorem ipsum dolor sit amet, consectetur adipiscing elit,\n"
				"sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.\n"
				"Ut enim ad minim veniam, quis nostrud exercitation ullamco\n"
				"laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure\n"
				"dolor in reprehenderit in voluptate velit esse cillum dolore\n"
				"eu fugiat nulla pariatur.\n"
				"Excepteur sint occaecat cupidatat non proident, sunt in culpa\n"
				"qui officia deserunt mollit anim id est laborum.");
}
