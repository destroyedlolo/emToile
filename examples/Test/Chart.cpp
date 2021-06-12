/********************************************************************
* Chart's test
*
* Simple one value chart test
*********************************************************************/

#include <Chart.h>
#include <Style.h>

	/*****
	 * objects
	 *****/
	
Chart *chart;
Chart::Serie *serie;

Style *mainStyle;
Style *popupStyle;

	/*****
	 * Build the chart
	 *****/

void start_gui( void ){
		/* Main style */
	mainStyle = new Style();
	mainStyle->setRadius( 0 );
	mainStyle->setBgColor( LV_COLOR_GRAY );
	mainStyle->setBgOpacity( LV_OPA_0 );
	mainStyle->setBorderWidth( 0 );
	mainStyle->setTextColor( LV_COLOR_WHITE );

	popupStyle = new Style();
	popupStyle->copyStyle( mainStyle );
	popupStyle->setBgColor( LV_COLOR_WHITE );
	popupStyle->setBgOpacity( LV_OPA_80 );
	popupStyle->setBorderWidth( 2 );
	popupStyle->setCaptionFont( &lv_font_montserrat_22 );
	popupStyle->setCaptionAlign( LV_ALIGN_IN_TOP_MID );
	popupStyle->setCaptionColor( LV_COLOR_BLACK );

		/* Ticks' style */
	popupStyle->setTextColor( LV_COLOR_RED );
		// need LV_FONT_MONTSERRAT_10 set to 1 in src/lv_conf.h
	popupStyle->seTexttFont( &lv_font_montserrat_10 );	

		/* Create the chart */
	chart = new Chart( 10, lv_scr_act() );
	chart->setSize( 300, 200 );
	chart->Align( LV_ALIGN_CENTER );
	chart->addStyle( popupStyle );

	chart->setCaptionString( "Chart example" );

		/* Add ticks on the left */
	chart->setPadding( 5, 5, 4 * (LV_DPI / 10), 0, LV_CHART_PART_BG );	// set space on the left
	chart->yTicks( "Max\nMin" );

		/* Add data series */
	serie = chart->addSerie( LV_COLOR_RED );
	serie->Insert( 0 );
	serie->Insert( 10 );
	serie->Insert( 20 );
	serie->Insert( 20 );
	serie->Insert( 20 );
	serie->Insert( 40 );
	serie->Insert( 60 );
	serie->Insert( 70 );
	serie->Insert( 90 );
	serie->Insert( 100 );
}

