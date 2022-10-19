/*
 * sct.h
 *
 *  Created on: 12. 10. 2022
 *      Author: xhorna16
 */

#ifndef SCT_H_
#define SCT_H_

static const uint32_t reg_values[4][10];

void sct_init(void);
void sct_led(uint32_t value);
void sct_value(uint16_t value, uint8_t led);


#endif /* SCT_H_ */
