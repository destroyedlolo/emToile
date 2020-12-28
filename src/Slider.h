/************************************************
 * Slider
*************************************************/

#ifndef SLDR_H
#define SLDR_H

class Slider : public GfxObject {
	bool dispval;	// Display value on the knob

public:
	/* Slider constructor
	 * -> Container *parent : parent object (default : NULL)
	 * -> Container *cloned : copy from this object (default : NULL)
	 * -> int16_t min,max : min and maximum value (default 0, 100)
	 * -> displayval : true, display slider value above
	 *
	 *  Notez-bien : the parent style is not copied, as container's one
	 *  are more annoying than useful.
	 */
	Slider( Container *parent=NULL, Container *cloned=NULL, int16_t min=0, int16_t max=100, bool displayval = false ){
		this->_obj = lv_slider_create( 
			parent ? parent->getMyself() : NULL, 
			cloned ? cloned->getMyself() : NULL
		);

		lv_slider_set_range( this->_obj, min, max );

		if( (this->dispval = displayval) ){
		    lv_obj_set_style_local_value_font(this->_obj, LV_SLIDER_PART_KNOB, LV_STATE_DEFAULT, lv_theme_get_font_small());
		    lv_obj_set_style_local_value_opa(this->_obj, LV_SLIDER_PART_KNOB, LV_STATE_DEFAULT, LV_OPA_60);
		    lv_obj_set_style_local_value_opa(this->_obj, LV_SLIDER_PART_KNOB, LV_STATE_FOCUSED, LV_OPA_COVER);
		    lv_obj_set_style_local_transition_time(this->_obj, LV_SLIDER_PART_KNOB, LV_STATE_DEFAULT, 300);
		}
	}

	/* Set minimum and the maximum values of the slider
	 * int16_t min,max : extreme values
	 */
	void setRange( int16_t min, int16_t max ){
		lv_slider_set_range( this->_obj, min, max );
	}

	/* Set the value
	 * -> int16_t value : new value
	 * -> lv_anim_enable_t anim : LV_ANIM_ON (default) / LV_ANIM_OFF
	 */
	void setValue( int16_t val, lv_anim_enable_t anim=LV_ANIM_ON ){
		lv_slider_set_value( this->_obj, val, anim );
	}

	/* Get slider value
	 * <-  int16_t
	 */
	int16_t getValue( void ){
		return lv_slider_get_value( this->_obj );
	}

	/* Set the anim time
	 * -> uint16_t time in ms
	 */
	void setAnimTime( uint16_t time ){
		lv_slider_set_anim_time( this->_obj, time );
	}

	/* Set the slider type
	 * -> lv_slider_type_t type
	 */
	void setType( lv_slider_type_t type ){
		lv_slider_set_type( this->_obj, type );
	}

	/* Update knob text
	 *	-> char * : buffer string to hold the result
	 *	-> const uint8_t size : size of the temporary buffer
	 *	-> const char *format : printf's style format to display (the value is an integer)
	 */
	void refreshKnob( char *t, const uint8_t size, const char *format ){
		if(this->dispval){
			snprintf(t, size, format, lv_slider_get_value(this->_obj));
			lv_obj_set_style_local_value_str( this->_obj, LV_SLIDER_PART_KNOB, LV_STATE_DEFAULT, t);
		}
	}

	/* Update knob text
	 * static version to be used from a callback
	 * (up to user code to know if it has to be called or not).
	 *	-> lv_obj_t *obj : slider object
	 *	-> char * : buffer string to hold the result
	 *	-> const uint8_t size : size of the temporary buffer
	 *	-> const char *format : printf's style format to display (the value is an integer)
	 */
	static void refreshKnob(lv_obj_t *obj, char *t, const uint8_t size, const char *format ){
		snprintf(t, size, format, lv_slider_get_value(obj));
		lv_obj_set_style_local_value_str( obj, LV_SLIDER_PART_KNOB, LV_STATE_DEFAULT, t);
	}
};

#endif
