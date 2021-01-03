/********************************************************************
* Page's test
*********************************************************************/

#include "Gui.h"

#include "Label.h"

	/*****
	 * objects
	 *****/
	
Gui *gui;

Label *lbl;

	/**** 
	 * Build the GUI
	 *****/

Gui::Gui( void ){
	this->pg = new Page( lv_scr_act() );
	this->pg->setSize( 150, 200 );
	this->pg->Align( LV_ALIGN_CENTER );

	lbl = new Label( **this->pg );
	lbl->SetLongTextMode( LV_LABEL_LONG_BREAK );
	lbl->setWidth( this->pg->getWidthFit() );
	lbl->setText("Lorem ipsum dolor sit amet, consectetur adipiscing elit,\n"
				"sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.\n"
				"Ut enim ad minim veniam, quis nostrud exercitation ullamco\n"
				"laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure\n"
				"dolor in reprehenderit in voluptate velit esse cillum dolore\n"
				"eu fugiat nulla pariatur.\n"
				"Excepteur sint occaecat cupidatat non proident, sunt in culpa\n"
				"qui officia deserunt mollit anim id est laborum.");
}
