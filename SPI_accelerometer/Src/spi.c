/*
 * spi.c
 *
 *  Created on: Apr 3, 2024
 *      Author: nikam
 */
#include"spi.h"

void SPI_Init(void){





}
uint16_t SPI_Transmit(uint8_t dataw){
while(!(SPI1->SR & SPI_SR_TXE))
	;
uint32_t frame=dataw;
SPI1->DR=frame;
while(!(SPI1->SR & SPI_SR_RXNE))
	;
frame=SPI1->DR;
return frame;

}
uint16_t SPI_Receive(void){
uint32_t val=SPI_Transmit(0x00);
return val;

}
void SPI_CS_Enable(void){
	GPIOE->BSRR=BV(SPI_CS_CLR_BIT);
}
void SPI_CS_Disable(void){
	GPIOE->BSRR=BV(SPI_CS_SET_BIT);
}
