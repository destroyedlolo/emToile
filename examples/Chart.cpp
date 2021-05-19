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

	chart->setCaptionString( "Chart example" );

		/* Add ticks on the left */
	chart->setPadding( 5, 5, 4 * (LV_DPI / 10), 0, LV_CHART_PART_BG );	// set space on the left
	chart->yTicks( "600\n500\n400\n300\n200" );

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

