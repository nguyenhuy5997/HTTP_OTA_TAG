#include <WiFi.h>
#include <HTTPClient.h>
#include "uart.h"
#include "http_ota.h"
#define USE_SERIAL Serial

rx rx_buffer;
http_ota OTA_infor;
void setup()
{
  USE_SERIAL.begin(115200);
  USE_SERIAL.println("?ON");
  
}

void loop()
{
  UART_ISR(rx_buffer);
  if(rx_buffer.cpl == true)
  {
    if(rx_buffer.buff[0] == 'o')
    {
      if(sscanf(rx_buffer.buff,"%s %s %s %s", OTA_infor.header,  OTA_infor.url,  OTA_infor.ssid,  OTA_infor.password) == 4)
      {
        int retry = 0;
        WiFi.begin(OTA_infor.ssid, OTA_infor.password);
        while (WiFi.status() != WL_CONNECTED && retry < 10) 
        {
          delay(500);
          Serial.println(".");
        }
        if(WiFi.status() != WL_CONNECTED)
        {
          goto FAIL;
        }
        
      }
      else
      {
        goto FAIL;
      }
      FAIL: Serial.println("???");
    }
  }
  rx_buffer.cpl = 0;
}
