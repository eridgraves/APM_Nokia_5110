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
  
  pinMode(LED_BUILTIN, OUTPUT); // Enables pulse
  Serial.begin(9600); // enables debug output
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

/*
// Resets to original values
  void reset(void){
    Serial.print("The pp values have been reset!\n");
    pp top = {42, 8, 42, 2};
    pp r = {61, 27, 61, 21};
    pp bot = {42, 46, 42, 40};
    pp l = {23, 27, 23, 21};
  }
*/

int x = 1; // The animation variable in x direction
int y = 1; // in y direction

void loop(){
 // Serial.print("\nIS THIS WORKING?\n"); // debug statement
  // Starting with each pair of points as corners of the cube
  // Starting cube position as a diamond (standing on edge)

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

  display.display(); // why does this work here, but not befor previous blocks of code?

  delay(20); // delay for 20ms
  
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN)); // Toggle "pulse"
  
    // Clear drawn lines
  display.writeLine(top.f_x,top.f_y,r.f_x,r.f_y, WHITE);
  display.writeLine(r.f_x,r.f_y,bot.f_x,bot.f_y, WHITE);
  display.writeLine(bot.f_x,bot.f_y,l.f_x,l.f_y, WHITE);
  display.writeLine(l.f_x,l.f_y,top.f_x,top.f_y, WHITE);

  display.writeLine(top.b_x,top.b_y,r.b_x,r.b_y, WHITE);
  display.writeLine(r.b_x,r.b_y,bot.b_x,bot.b_y, WHITE);
  display.writeLine(bot.b_x,bot.b_y,l.b_x,l.b_y, WHITE);
  display.writeLine(l.b_x,l.b_y,top.b_x,top.b_y, WHITE);

  display.writeLine(top.f_x,top.f_y,top.b_x,top.b_y,WHITE);
  display.writeLine(bot.f_x,bot.f_y,bot.b_x,bot.b_y,WHITE);
  display.writeLine(r.f_x,r.f_y,r.b_x,r.b_y,WHITE);
  display.writeLine(l.f_x,l.f_y,l.b_x,l.b_y,WHITE);

  delay(20); // total delay gives ~ 25 fps

  // Move the points of the cube

  if(top.f_x == 23){
   // y = 0;

    top.f_y += y;
    top.b_y += y;

    bot.f_y -= y;
    bot.b_y -= y;    
    
  }
  else{
    top.f_x -= x;
    top.b_x -= x;

    bot.f_x += x;
    bot.b_x += x;

  }

  if(r.f_y == 8){
    // x = 0;

     r.f_x -= x;
     r.b_x -= x;

     l.f_x += x;
     l.b_x += x;

  }
  else{
    r.f_y -= y;
    r.b_y -= y;

    l.f_y += y;
    l.b_y += y;
  }

  // Reset statement
  if((r.f_x == 23) && (top.f_y == 8) ){
      
       
  }
  
}

