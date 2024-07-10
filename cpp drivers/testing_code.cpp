
//#define _DEBUG
#include "init.h"
#include "gpio_cores.h"


// blink once per second for 5 times.
// provide a sanity check for timer (based on SYS_CLK_FREQ)
// led_p pointer to led instance
void timer_check(GpoCore *led_p) {
   int i;

   for (i = 0; i < 5; i++) {
      led_p->write(0xffff);
      sleep_ms(500);
      led_p->write(0x0000);
      sleep_ms(500);
      debug("timer check - (loop #)/now: ", i, now_ms());
   }
}


// check individual led
// led_p pointer to led instance
// n number of led
void led_check(GpoCore *led_p, int n) {
   int i;

   for (i = 0; i < n; i++) {
      led_p->write(1, i);
      sleep_ms(200);
      led_p->write(0, i);
      sleep_ms(200);
   }
}


// leds flash according to switch positions.
// led_p pointer to led instance
// sw_p pointer to switch instance
void sw_check(GpoCore *led_p, GpiCore *sw_p) {
   int i, s;

   s = sw_p->read();
   for (i = 0; i < 30; i++) {
      led_p->write(s);
      sleep_ms(50);
      led_p->write(0);
      sleep_ms(50);
   }
}


//uart transmits test line.
 //uart instance is declared as global variable in io_basic.h
void uart_check() {
   static int loop = 0;
   uart.disp("uart test #");
   uart.disp(loop);
   uart.disp("\n\r");
   loop++;
}


// instantiate switch, led
GpoCore led(get_slot_addr(BRIDGE_BASE, S2_LED));
GpiCore sw(get_slot_addr(BRIDGE_BASE, S3_SW));


int main()
{

   while (1) 
   {
      timer_check(&led);
      led_check(&led, 16);
      sw_check(&led, &sw);
      uart_check();
      debug("main - switch value / up time : ", sw.read(), now_ms());
   }
} 

