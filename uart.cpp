#include "uart.h"

void UART_ISR(rx uart)
{
  int index = 0;
  while(Serial2.available())
  {
    uart.buff[index++] = Serial2.read();
    if(uart.buff[index-1] == '\r' || uart.buf[index-1] == '\n')
    {
      uart.cpl = true;
    }
  }
}
