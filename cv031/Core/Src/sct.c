/*
 * sct.c
 *
 *  Created on: 12. 10. 2022
 *      Author: xhorna16
 */


#include <stdint.h>
#include "sct.h"
#include "stm32f0xx.h"
#include <main.h>

//#define sct_nla(x) do { if (x) GPIOB->BSRR = (1 << 5); else GPIOB->BRR = (1 << 5); } while (0)
//#define sct_sdi(x) do { if (x) GPIOB->BSRR = (1 << 4); else GPIOB->BRR = (1 << 4); } while (0)
//#define sct_clk(x) do { if (x) GPIOB->BSRR = (1 << 3); else GPIOB->BRR = (1 << 3); } while (0)
//#define sct_noe(x) do { if (x) GPIOB->BSRR = (1 << 10); else GPIOB->BRR = (1 << 10); } while (0)

void sct_init(void) {
//	RCC->AHBENR |= RCC_AHBENR_GPIOBEN; //povoleni hodin
//	GPIOB->MODER |= GPIO_MODER_MODER5_0; // vystup
//	GPIOB->MODER |= GPIO_MODER_MODER4_0;
//	GPIOB->MODER |= GPIO_MODER_MODER3_0;
//	GPIOB->MODER |= GPIO_MODER_MODER10_0;
	sct_led(0); //pouze toto zustava
//	sct_noe(0);
}

void sct_led(uint32_t value) { //zapis do registru od 0 do 31
	for (uint8_t i = 0; i < 32; i++) {
//		sct_sdi (value&1);
//		value >>= 1;
//		sct_clk(1);
//		sct_clk(0);
		HAL_GPIO_WritePin(SCT_SDI_GPIO_Port, SCT_SDI_Pin, value&1);
		value >>= 1;
		HAL_GPIO_WritePin(SCT_CLK_GPIO_Port, SCT_CLK_Pin, 1);
		HAL_GPIO_WritePin(SCT_CLK_GPIO_Port, SCT_CLK_Pin, 0);
	}
//	sct_nla(1);
//	sct_nla(0);
	HAL_GPIO_WritePin(SCT_NLA_GPIO_Port, SCT_NLA_Pin, 1);
	HAL_GPIO_WritePin(SCT_NLA_GPIO_Port, SCT_NLA_Pin, 0);
}

static const uint32_t reg_values[3][10] = {
		{
				//PCDE--------GFAB @ DIS1
				0b0111000000000111 << 16,
				0b0100000000000001 << 16,
				0b0011000000001011 << 16,
				0b0110000000001011 << 16,
				0b0100000000001101 << 16,
				0b0110000000001110 << 16,
				0b0111000000001110 << 16,
				0b0100000000000011 << 16,
				0b0111000000001111 << 16,
				0b0110000000001111 << 16,
		},
		{
				//----PCDEGFAB---- @ DIS2
				0b0000011101110000 << 0,
				0b0000010000010000 << 0,
				0b0000001110110000 << 0,
				0b0000011010110000 << 0,
				0b0000010011010000 << 0,
				0b0000011011100000 << 0,
				0b0000011111100000 << 0,
				0b0000010000110000 << 0,
				0b0000011111110000 << 0,
				0b0000011011110000 << 0,
		},
		{
				//PCDE--------GFAB @ DIS3
				0b0111000000000111 << 0,
				0b0100000000000001 << 0,
				0b0011000000001011 << 0,
				0b0110000000001011 << 0,
				0b0100000000001101 << 0,
				0b0110000000001110 << 0,
				0b0111000000001110 << 0,
				0b0100000000000011 << 0,
				0b0111000000001111 << 0,
				0b0110000000001111 << 0,
		},
};

void sct_value(uint16_t value) {
	uint32_t reg = 0; //cislo k zobrazeni
	reg |= reg_values[0][value / 100 % 10]; //stovky
	reg |= reg_values[1][value / 10 % 10]; //desitky
	reg |= reg_values[2][value / 1 % 10]; //jednotky
	sct_led (reg); //zapis do registru
}
