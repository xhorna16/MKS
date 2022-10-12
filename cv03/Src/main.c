/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include "sct.h"
#include "stm32f0xx.h"

int main(void)
{
	sct_init();

	while (1) {
		/*
		for(uint32_t i = 0; i<1000; i+=111){
			sct_value(i);
			for (volatile uint32_t ii = 0; ii < 100000; ii++) {} //pocita se dlouho, aby se udelalo zpozdeni
		}
		*/
        sct_value (71);
	}
}
