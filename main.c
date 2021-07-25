#include "stm32f10x.h"                  // Device header

void Delays(int time);
int status=0;
int main(void)
{
	RCC->APB2ENR |= (1<<3); //// Enabling PORT A
	RCC->APB2ENR |= (1<<4); /// Enabling PORT C
	GPIOB->CRL &= 0xFFFFFF0F; /// A3 ve A6 pini resetlendi
	GPIOB->CRL |= 0x00000080; /// A3 ve A6 pini girisi push pull
	
	GPIOC->CRH &= 0xFF0FFFFF; /// Reset the pin 13
	GPIOC->CRH |= 0x00300000; /// Set PIN 13 as output
	GPIOC->ODR |= 0x2000;
	
	while(1)
	{
		

	if(GPIOB->IDR & 0X02){	
		status=!status;
		if(status==1) /// Checking status of PIN ! portA 
		{
			GPIOC->ODR &=~0x2000; /// Toggle the PIN state
		}
		else
		{
			GPIOC->ODR |=0x2000; /// Set the PIN 13 port C high
		}
		while(GPIOB->IDR & 0X02)
    Delays(5); // keeps a small delay
	}
 }
}


void Delays(int time) /// Random delay function
{
	int t;
	for(;time>0;time--)
	{
	 for(t=0;t<100000;t++)
		{}
	}
}
