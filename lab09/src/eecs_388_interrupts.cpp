#include <Arduino.h>
#include "eecs_388_lib.h"

volatile uint8_t interrupt_count = 0;
volatile uint8_t is_red = 1;
volatile uint8_t led_state = 0;

void setup()
{
    // init GPIO pins
    gpio_mode(GPIO_13, GPIO_OUTPUT); // red
    gpio_mode(GPIO_12, GPIO_OUTPUT); // blue
    gpio_mode(GPIO_11, GPIO_OUTPUT); // green
    
    gpio_write(GPIO_13, OFF);
    gpio_write(GPIO_12, OFF);
    gpio_write(GPIO_11, OFF);

    // setup timer for 100 ms
    enable_timer_interrupt();
    set_cycles(25000); // Task 3.1 - Determine the amount of cycles for a 100ms interrupt timer

    enable_interrupt();
}

/******************************************************************************
 *  INTERRUPT SERVICE ROUTINE. This is the function the ATmega328P jumps to when TCNT1 == OCR1A
 *******************************************************************************/
ISR(TIMER1_COMPA_vect) {
	//Task 3.2 - Write code to blink the red LED every 100ms for 1 second.  Then
	//alternate to the green LED and blink every 100ms for 1 second.  Keep alternating 
	//between the two
    interrupt_count++;

    if(interrupt_count == 10){
        interrupt_count = 0;
        is_red = !is_red;
    }

    led_state = !led_state;

    if(is_red){
        gpio_write(GPIO_13, led_state);
        gpio_write(GPIO_12, OFF);
    } else {
        gpio_write(GPIO_13, OFF);
        gpio_write(GPIO_12, led_state);
    }


}

void loop() {
	//Our main loop can run and will only have brief interruptions when the 100ms timer expires
    delay_ms(1000);
    gpio_write(GPIO_12, ON);
    delay_ms(1000);
    gpio_write(GPIO_12, OFF);
}