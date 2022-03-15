#ifndef _UART_H_
#define _UART_H_
#include "stdio.h"
#include <Arduino.h>
typedef struct _rx
{
  char buff[50];
  bool cpl;
}rx;

void UART_ISR(rx uart);

#endif /* _UART_H_ */
