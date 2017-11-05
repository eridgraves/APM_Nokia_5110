// Nokia 5110 LCD-Display (84 wide x 48 high)

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
}

// Define point-pair struct
typedef struct{

  // Front
  int f_x;
  int f_y;

  // Back 
  int b_x;
  int b_y;
} pp;

// Define starting points here:
pp top = {42, 8, 42, 2};
pp r = {61, 27, 61, 21};
pp bot = {42, 46, 42, 40};
pp l = {23, 27, 23, 21};


void loop(){

  // Starting with each pair of points as corners of the cube
  // Starting cube position as a diamond (standing on edge)

  display.writePixel(top.f_x,top.f_y,BLACK); // F_top
  display.writePixel(top.b_x,top.b_y,BLACK); // B_top
  
  display.writePixel(r.f_x,r.f_y,BLACK); // F_R
  display.writePixel(r.b_x,r.b_y,BLACK); // B_R
   
  display.writePixel(bot.f_x,bot.f_y,BLACK); // F_B
  display.writePixel(bot.b_x,bot.b_y,BLACK); // B_B

  display.writePixel(l.f_x,l.f_y,BLACK); // F_L
  display.writePixel(l.b_x,l.b_y,BLACK); // B_L

  display.display();
  delay(500);
  
  // Draw vertical connecting lines
  display.writeLine(top.f_x,top.f_y,top.b_x,top.b_y,BLACK);
  display.writeLine(bot.f_x,bot.f_y,bot.b_x,bot.b_y,BLACK);
  display.writeLine(r.f_x,r.f_y,r.b_x,r.b_y,BLACK);
  display.writeLine(l.f_x,l.f_y,l.b_x,l.b_y,BLACK);

  // Draw diagonal connecting lines
  display.writeLine(top.f_x,top.f_y,r.f_x,r.f_y, BLACK);
  display.writeLine(r.f_x,r.f_y,bot.f_x,bot.f_y, BLACK);
  display.writeLine(bot.f_x,bot.f_y,l.f_x,l.f_y, BLACK);
  display.writeLine(l.f_x,l.f_y,top.f_x,top.f_y, BLACK);

  display.writeLine(top.b_x,top.b_y,r.b_x,r.b_y, BLACK);
  display.writeLine(r.b_x,r.b_y,bot.b_x,bot.b_y, BLACK);
  display.writeLine(bot.b_x,bot.b_y,l.b_x,l.b_y, BLACK);
  display.writeLine(l.b_x,l.b_y,top.b_x,top.b_y, BLACK);
  
}

