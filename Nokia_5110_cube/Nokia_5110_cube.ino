// Nokia 5110 LCD-Display (84 wide x 48 high)

// Optimized version: Base the cube off of one point, so that it takes up less space. 

// Optimized size goal: use < 10% dynamic memory

#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

// Board Setup
// D7 - Serial clock out (SCLK)
// D6 - Serial data out (DN<MOSI>)
// D5 - Data/Command select (D/C)
// D4 - LCD chip select (SCE)
// D3 - LCD reset (RST)

Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);

void setup()   {

  // Display initialization
  display.begin();

  // Set contrast
  display.setContrast(100);
  
  // Clear the screen/buffer
  display.clearDisplay(); 
  
  pinMode(LED_BUILTIN, OUTPUT); // Enables pulse
  Serial.begin(9600); // enables debug output
}

// Everything in terms of top front point:
int x = 42;
int y = 8;

void loop(){
 // Serial.print("\nIS THIS WORKING?\n"); // debug statement
  // Starting with each pair of points as corners of the cube
  // Starting cube position as a diamond (standing on edge)

  // Draw vertical connecting lines
  display.writeLine(x,y,x,(y-6),BLACK);
  display.writeLine((84 - x),(48 - y),(84 - x),(42 - y),BLACK);
  /*
  display.writeLine(r.f_x,r.f_y,r.b_x,r.b_y,BLACK);
  display.writeLine(l.f_x,l.f_y,l.b_x,l.b_y,BLACK);

  // Draw diagonal connecting lines
  display.writeLine(x,y,r.f_x,r.f_y, BLACK);
  display.writeLine(r.f_x,r.f_y,(84 - x),(48 - y), BLACK);
  display.writeLine((84 - x),(48 - y),l.f_x,l.f_y, BLACK);
  display.writeLine(l.f_x,l.f_y,x,y, BLACK);

  display.writeLine(x,(y + 6),r.b_x,r.b_y, BLACK);
  display.writeLine(r.b_x,r.b_y,(84 - x),(42 - y), BLACK);
  display.writeLine((84 - x),(42 - y),l.b_x,l.b_y, BLACK);
  display.writeLine(l.b_x,l.b_y,x,(y + 6), BLACK);
*/
  display.display(); // why does this work here, but not befor previous blocks of code?

}

