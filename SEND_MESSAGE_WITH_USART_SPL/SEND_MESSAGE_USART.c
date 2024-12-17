#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
#include <stdio.h>

char str[50];

GPIO_InitTypeDef	GPIO_InitStruct;
USART_InitTypeDef	USART_InitStruct;

void gpio_config(void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART2);

	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_Init(GPIOA, &GPIO_InitStruct);
}

void usart_config(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);

	USART_InitStruct.USART_BaudRate = 115200;
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStruct.USART_Mode = USART_Mode_Tx;
	USART_InitStruct.USART_Parity = USART_Parity_No;
	USART_InitStruct.USART_StopBits = USART_StopBits_1;
	USART_InitStruct.USART_WordLength = USART_WordLength_8b;

	USART_Init(USART2, &USART_InitStruct);
	USART_Cmd(USART2, ENABLE);
}

void usart_puts(USART_TypeDef* USARTx, volatile char *str)
{
	while (*str)
	{
		while (!(USARTx->SR & 0x00000040));

		USART_SendData(USARTx, *str);
		*str++;
	}
}


int main(void)
{
	gpio_config();
	usart_config();
  while (1)
  {
	  sprintf(str, "Hello World!\r\n");
	  usart_puts(USART2, str);

	  for (uint32_t time = 0; time < 1680000; time++);
  }
}

