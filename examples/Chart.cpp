/********************************************************************
* Chart's test
*
* Simple one value chart test
*********************************************************************/

#include <Chart.h>

	/*****
	 * objects
	 *****/
	
Chart *chart;
Chart::Serie *serie;

	/*****
	 * Build the chart
	 *****/

void start_gui( void ){
		/* Create the chart */
	chart = new Chart( 10, lv_scr_act() );
	chart->setSize( 300, 200 );
	chart->Align( LV_ALIGN_CENTER );

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

