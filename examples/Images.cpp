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

		// Notez-bien : if the container of the image has a custom font
		// in it's style, nothing will be displayed corresponding symbole
		// is not part of it.
		// The solution is to apply built-in font like lv_font_montserrat_16
		// on the image. This font doesn't have to be declared.
	img = new Image( pg->getMyself() );
	img->seTexttFont( &lv_font_montserrat_16 );
	img->Set( LV_SYMBOL_BATTERY_FULL );
}
