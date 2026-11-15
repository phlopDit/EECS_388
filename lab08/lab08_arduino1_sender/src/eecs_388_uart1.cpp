/******************************************************************************
 *   Header Includes
 *******************************************************************************/
#include <Arduino.h>

#include "eecs_388_lib1.h"

char data[] = {'r', 'g', 'b'};
uint8_t index;

/******************************************************************************
 *   Function: setup() - Initializes the Arduino System
 *      Pre condition: 
 *          Hardware must be properly connected (RX/TX lines to Arduino2 receiver)
 *      Post condition: 
 *          Runs initialization calls one time on power up
 *          uart is initialized to send
 *			index is initialized to 0, to send the first character 'r'.
 *******************************************************************************/
void setup() 
{
uart_init();

index = 0;

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
if( index < sizeof(data) ) 
  {
  //Task 1.1 - Write code here to:
  //Send the first element of the data[] array
  //Receive the acknowledgement 'A' from the other arduino
  //When A is received, delay for 1 second.
  //When A is received, increment the index by 1, so they next loop sends the next character
  
    ser_write(data[index]); // Send next char in data[]

    char ack = ser_read(); // Wait for acknowledgement character from reciever
    
    // If valid acknowledgements is received delay for one second and increment index
    if(ack == 'A'){
      delay_ms(1000);// One second delay
      index++;
    }
  }

//Repeat the characters starting back at index 0.
if( index > 2 )
  {
  index = 0;
  }

return;
}