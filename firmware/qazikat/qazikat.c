#if defined(RGBLIGHT_ENABLE)
#include "rgblight.h"
#endif

#include "action_layer.h"
#include "led.h"

#define INACTIVE_H (20)
#define ACTIVE_H (160)
 
 void keyboard_post_init_kb(void) 
 {
	rgblight_set_effect_range(3,18);
	rgblight_sethsv_range(INACTIVE_H, 200,20, 0, 3);
 }
 
 bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if(res) {
        if (!led_state.num_lock) {rgblight_sethsv_at(ACTIVE_H,200,20,1); }
	    else                    {rgblight_sethsv_at(INACTIVE_H,200,20,2); }
		
		if (led_state.caps_lock) {rgblight_sethsv_at(ACTIVE_H,200,20,1); }
	    else                     {rgblight_sethsv_at(INACTIVE_H,200,20,1); }
    }
    return res;
}

layer_state_t default_layer_state_set_kb(layer_state_t state) {
	static layer_state_t cur_layer = 0;
	
	if (cur_layer != get_highest_layer(state)) 
	{
		switch (get_highest_layer(state)) {
		case 0:
			rgblight_sethsv_at(INACTIVE_H,200,20,0);
			cur_layer = 0;
			break;
		case 5:
			rgblight_sethsv_at(ACTIVE_H,200,20,0);
			cur_layer = 5;
			break;
		default: 
			break;
		}
	}
  return state;
}

