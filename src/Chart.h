/************************************************
*	Chart : Display data charts
*************************************************/
#ifndef CHART_H
#define CHART_H

#include "GfxObject.h"

class Chart : public GfxObject {
public:

	class Serie {
		lv_obj_t *_chart;

	protected:
		lv_chart_series_t *_dt;

	public:
		Serie( lv_obj_t *chart, lv_color_t color ) : _chart(chart) {
			this->_dt = lv_chart_add_series( chart, color );
		}

		~Serie(){
			lv_chart_remove_series( this->_chart, this->_dt );
		}

		lv_chart_series_t *operator *(){
			return _dt;
		}

		/* Clear all serie's points */
		void Clear( void ){
			lv_chart_clear_series( this->_chart, this->_dt );
		}

		/* Hide or not a serie from its chart
		 *
		 * -> bool hide (default : true)
		 */
		void Hide( bool hide=true ){
			lv_chart_hide_series( this->_chart, this->_dt, hide );
		}

		/* Use external Array
		 * Instead of instead of the dynamically allocated internal one
		 *
		 * -> lv_coord_t array[]
		 * -> uint16_t point_cnt : size of the array
		 */
		void useExternalArray( lv_coord_t array[], uint16_t point_cnt ){
			lv_chart_set_ext_array( this->_chart, this->_dt, array, point_cnt );
		}

		/* Set points
		 *
		 * -> lv_coord_t val : from an uniq value
		 * -> lv_coord_t y_array[] : from an array
		 *  	NOTEZ-BIEN : the array *must* have at least as much
		 *  	as elements of the serie
		 */
		void Init( lv_coord_t val ){
			lv_chart_init_points( this->_chart, this->_dt, val );
		}
		void Init( lv_coord_t y_array[] ){
			lv_chart_set_points( this->_chart, this->_dt, y_array );
		}

		/* Insert a new data at the end of the serie.
		 * The previous 1st one is evicted.
		 *
		 * -> lv_coord_t val : value to insert
		 */
		void Insert( lv_coord_t val ){
			lv_chart_set_next( this->_chart, this->_dt, val );
		}

		/* Set a value from its index
		 *
		 * -> lv_coord_t val,
		 *  ->uint16_t idx
		 */
		void Set( lv_coord_t val, uint16_t idx ){
			lv_chart_set_point_id( this->_chart, this->_dt, val, idx );
		}
		lv_coord_t Get( uint16_t idx ){
			return lv_chart_get_point_id( this->_chart, this->_dt, idx );
		}
	
		/* set the starting point
		 *
		 * uint16_t idx : index starting point
		 */
		void setStartIndex( uint16_t idx ){
			lv_chart_set_x_start_point( this->_chart, this->_dt, idx );
		}
		uint16_t getStartIndex( void ){
			return lv_chart_get_x_start_point( this->_dt );
		}

		/* set the Y axis
		 *
		 * lv_chart_axis_t axis : LV_CHART_AXIS_PRIMARY_Y or LV_CHART_AXIS_SECONDARY_Y
		 */
		void setAxis( lv_chart_axis_t axis ){
			lv_chart_set_series_axis( this->_chart, this->_dt, axis );
		}
		lv_chart_axis_t getAxis( void ){
			return lv_chart_get_series_axis( this->_chart, this->_dt );
		}
	};

	/* Char constructor
	 * -> lv_obj_t *parent : parent object (default : NULL)
	 * -> const lv_obj_t *cloned : copy from this object (default : NULL)
	 */
	Chart( lv_obj_t *parent=NULL, const lv_obj_t *cloned=NULL ){
		this->_obj = lv_chart_create( parent, cloned );
	}
	
};
#endif
