/********************************************************************
* Image with a symbole test
*
* Create an image displaying a symbole
*********************************************************************/

#include <Page.h>
#include <Image.h>

	/*****
	 * objects
	 *****/

Page *pg;
Image *img;

	/**** 
	 * Build the GUI
	 *****/
void start_gui( void ){
	pg = new Page( lv_scr_act() );
	pg->setSize( 150, 200 );
	pg->Align( LV_ALIGN_CENTER );

	img = new Image( pg->getMyself() );
	img->Set( LV_SYMBOL_BATTERY_FULL );
}
