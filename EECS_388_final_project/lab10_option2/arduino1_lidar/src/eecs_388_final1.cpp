/******************************************************************************
 *   Header Includes
 *******************************************************************************/
#include <Arduino.h>
#include <stdint.h>
#include <stdio.h>

#include "eecs_388_lib.h"

/******************************************************************************
 *   Function: setup() - Initializes the Arduino System
 *      Pre condition: 
 *          Hardware must be properly connected (sensors, LEDS, etc.)
 *      Post condition: 
 *          Runs initialization calls one time on power up
 *          Input/Output (IO) pins are configured
 *******************************************************************************/
void setup() 
{
uart_init();

return;
}

/******************************************************************************
 *   Function: loop() - Main execution loop
 *      Pre condition: 
 *          setup() has been executed and system is initialized
 *      Post condition: 
 *          Performs a single iteration of the system's function
 *          Repeates indefinetely unless the board is reset or powered off
 *******************************************************************************/
void loop() 
{
uint16_t dist = 0;              /* LIDAR distance data is 16 bits. */

ser_printline("Setup completed.");
ser_write( '\n' );

while( 1 )
    { 
    /* 
        - read a data frame from the TFmini sensor
        
        - from Table 6, we know each LIDAR measurement sends 9 bytes
        - the function `ser_read()` can process 1 byte per function call

        - This if-statement below will read (and check) the first two bytes of a valid data frame
        - You will need to write code to read the subsequent bytes to get the distance data
        - You will need to process the data received from the sensor to get the correct distance value
    */
    if ('Y' == ser_read() && 'Y' == ser_read()) 
        {
        /* 

            - print the measured value to the console (i.e. the serial monitor) 
            - You can use ser_printf() or ser_printline() or ser_write()
            
            - Helpful guide for printing with variadic function similiar to printf()
            - https://en.cppreference.com/w/cpp/io/c/fprintf


			- Send the distance to Arduino2
        */
            uint8_t distL = ser_read();// Read distance low byte
            uint8_t distH = ser_read();// Read distance high byte



            dist = distL | (distH << 8);// Combine into one 16 byte value

            if (dist <= 60) {
                ser_write('X');
            } else if (dist > 60 && dist <= 100) {
                ser_write('R');
            } else if (dist > 100 && dist <= 200) {
                ser_write('Y');
            } else {
                ser_write('G');
            }

            // Use the remaining data bytes
            for(int i = 0; i < 5; i++){
                ser_read();
            }

            // ser_write(dist);

        }
    }

return;
}