/********************************************************************
* Page's test
*********************************************************************/

#include "Gui.h"

#include <Page.h>
#include <Label.h>

	/*****
	 * objects
	 *****/
	
Gui *gui;

	/*****
	 * Tabs
	 *****/

	/* Tab with a long text inside */
class TabLT : public Page {
	Label *lbl;

public:
	TabLT( lv_obj_t *tv ) : Page(tv, true) {

			/* Add a label inside */
		this->lbl = new Label( **this );
		this->lbl->Align( LV_ALIGN_IN_TOP_MID );	// in the middle of the page
		this->lbl->setLongTextMode( LV_LABEL_LONG_BREAK );
		this->lbl->setWidth( 300 );			// its size
		this->lbl->AutoRealign( true );		// to ensure the aligment is correct
		this->lbl->setTextStatic("Lorem ipsum dolor sit amet, consectetur adipiscing elit,\n"
				"sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.\n"
				"Ut enim ad minim veniam, quis nostrud exercitation ullamco\n"
				"laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure\n"
				"dolor in reprehenderit in voluptate velit esse cillum dolore\n"
				"eu fugiat nulla pariatur.\n"
				"Excepteur sint occaecat cupidatat non proident, sunt in culpa\n"
				"qui officia deserunt mollit anim id est laborum."
		);
/*
		this->dumpObj("TabLT");
		this->lbl->dumpObj("Label");
*/
	}

};

class TabSL : public Page {
	Label *lbl;

public:
	TabSL( lv_obj_t *tv ) : Page(tv, true) {

			/* Add a label inside */
		this->lbl = new Label( **this );
		this->lbl->setReColor( true );
		this->lbl->Align( LV_ALIGN_CENTER );	// in the middle of the page
		this->lbl->setTextStatic("#0000ff 2nd#  tab");
	}
};


	/**** 
	 * Build the GUI
	 *****/

Gui::Gui( void ){
	this->tv = new TabView( lv_scr_act() );	// Create the TabView

		/* Create the 1st tab */
	lv_obj_t *t = lv_tabview_add_tab(**this->tv, "Long Text");	// Lvgl object
	TabLT *t1 = new TabLT(t);	// Assign it to a new page with dedicated content

		/* Create the 2nd tab */
	t = lv_tabview_add_tab(**this->tv, "Colored Text");
	TabSL *t2 = new TabSL(t);
}

