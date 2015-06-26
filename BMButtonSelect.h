///////////////////////////////////////////////////////////
///////// LED SCOOTER BURNING MAN 2015 w/ BUTTON //////////
///////////////////////////////////////////////////////////

// v1.1 12-mode w/ Button selection
// Rainbow, Rainbow Stripe, Party, Heat, Ocean, Forrest, Cloud, White, Pink, Red, Caution, Fire, Pyro, LEO
// With help from GyroGearloose, Jarrod Wagner and Jarrod Hiscock
 
//INCLUDE LIBRARIES//
#include <FastLED.h>                                       //Include FastLED Library
 
//LED SETUP//
#define LED_PIN 6                                          //LED Strip Data Pin
#define BUTTON_PIN 4 
#define LED_TYPE    WS2811                                 //LED Type
#define COLOR_ORDER GRB                                    //LED Color Order
#define NUM_LEDS 156                                       //Number of LEDs
CRGB leds[NUM_LEDS];                                       //Name of LED Array
CRGBPalette256 currentPalette;                             //Color Palette
TBlendType    currentBlending;                             //Color Blending
 
//BUTTON SETUP//
byte prevKeyState = HIGH;        
 
//MODE VARIABLES//
int ledMode = 0;                                           //FIRST ACTIVE MODE
int BRIGHTNESS = 255;                                      //0-255.  Lower number saves battery life, higher number is screamingly bright
int SATURATION = 255;                                      //0 is white (no color) and 255 is fully saturated with color
int HUE = 0;                                               //0-255, around the color wheel
int STEPS = 4;                                             //Wider or narrower bands of color
int SPEEDO = 10;                                           //The speed of the animation

// container for blink function
bool colorORblack=true;
// container for removing delay();
unsigned long lastUpdate=0;
 
//SETUP//
void setup() {
  delay( 2000 );                                           // power-up safety delay
  pinMode(BUTTON_PIN, INPUT_PULLUP);

//  Serial.begin (115200);
 
 //FASTLED//
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  BRIGHTNESS );
  currentBlending = BLEND;
 
 }
 
//DEFINE NUMBER OF EFFECTS//
#define NUM_MODES 13                                       //Change this to max number of effects
 
//MAIN LOOP//
void loop() {

  switch (ledMode) {
       case 0: BRIGHTNESS=240; Rainbow(); break;
       case 1: BRIGHTNESS=240; RainbowStripe(); break;
       case 2: BRIGHTNESS=240; PartyColors(); break;
       case 3: BRIGHTNESS=128; HeatColors(); break;
       case 4: BRIGHTNESS=128; Ocean(); break;
       case 5: BRIGHTNESS=128; Forest(); break;
       case 6: BRIGHTNESS=128; Cloud(); break;
       case 7: BRIGHTNESS=240; White(); break;
       case 8: BRIGHTNESS=128; Pink(); break;
       case 9: BRIGHTNESS=128; Red(); break;
       case 10: BRIGHTNESS=240; blink(CRGB::Orange, CRGB::Black, 1000); break;
       case 11: BRIGHTNESS=240; blink(CRGB::Red, CRGB::White, 250); break;
       case 12: BRIGHTNESS=255; blink(CRGB::Red, CRGB::Orange, 100); break;
       case 13: BRIGHTNESS=240; blink(CRGB::Red,CRGB::Blue, 250); break;
}  
 
//BUTTON MANAGEMENT//
 byte currKeyState = digitalRead(BUTTON_PIN);
        if ((prevKeyState == LOW) && (currKeyState == HIGH)) {
            keyRelease();
        }
        prevKeyState = currKeyState;  
}

//LIGHT PATTERNS//
//Rainbow colors
void Rainbow() {
  FastLED.setBrightness(  BRIGHTNESS );
  currentPalette = RainbowColors_p;
  static uint8_t startIndex = 0;
  startIndex = startIndex + 1;
  FillLEDsFromPaletteColors( startIndex);
  FastLED.show();
  FastLED.delay(SPEEDO);  
}
 
//Rainbow stripe
void RainbowStripe() {
  FastLED.setBrightness(  BRIGHTNESS );
  currentPalette = RainbowStripeColors_p;
  static uint8_t startIndex = 0;
  startIndex = startIndex + 1;
  FillLEDsFromPaletteColors( startIndex);
  FastLED.show();
  FastLED.delay(SPEEDO);  
}
 
//Party colors
void PartyColors() {
  FastLED.setBrightness(  BRIGHTNESS );
  currentPalette = PartyColors_p;
  static uint8_t startIndex = 0;
  startIndex = startIndex + 1;
  FillLEDsFromPaletteColors( startIndex);
  FastLED.show();
  FastLED.delay(SPEEDO);  
}
 
//Heat colors
void HeatColors() {
  FastLED.setBrightness(  BRIGHTNESS );
  currentPalette = HeatColors_p;
  static uint8_t startIndex = 0;
  startIndex = startIndex + 1;
  FillLEDsFromPaletteColors( startIndex);
  FastLED.show();
  FastLED.delay(SPEEDO);  
}
 
//Ocean colors
void Ocean() {
  FastLED.setBrightness(  BRIGHTNESS );
  currentPalette = OceanColors_p;
  static uint8_t startIndex = 0;
  startIndex = startIndex + 1;
  FillLEDsFromPaletteColors( startIndex);
  FastLED.show();
  FastLED.delay(SPEEDO);  
}
 
//Cloud colors
void Cloud() {
  FastLED.setBrightness(  BRIGHTNESS );
  currentPalette = CloudColors_p;
  static uint8_t startIndex = 0;
  startIndex = startIndex + 1;
  FillLEDsFromPaletteColors( startIndex);
  FastLED.show();
  FastLED.delay(SPEEDO);  
}
 
//Forrest colors
void Forest() {
  FastLED.setBrightness(  BRIGHTNESS );
  currentPalette = ForestColors_p;
  static uint8_t startIndex = 0;
  startIndex = startIndex + 1;
  FillLEDsFromPaletteColors( startIndex);
  FastLED.show();
  FastLED.delay(SPEEDO);  
}
 
//Lava colors
void Lava() {
  FastLED.setBrightness(  BRIGHTNESS );
  currentPalette = LavaColors_p;
  static uint8_t startIndex = 0;
  startIndex = startIndex + 1;
  FillLEDsFromPaletteColors( startIndex);
  FastLED.show();
  FastLED.delay(SPEEDO);  
}
 
//Fill colors
void FillLEDsFromPaletteColors( uint8_t colorIndex) {
  for( int i = 0; i < NUM_LEDS; i++) {
    leds[i] = ColorFromPalette( currentPalette, colorIndex, BRIGHTNESS, currentBlending);
    colorIndex += STEPS;
  }
}
 
//White solid
void White() {
   fill_solid(leds, NUM_LEDS, CRGB::White);  
   FastLED.show();
}
 
//Pink solid
void Pink() {
   fill_solid(leds, NUM_LEDS, CRGB::HotPink);  
   FastLED.show();
}
 
//Red solid
void Red() {
   fill_solid(leds, NUM_LEDS, CRGB::Red);  
   FastLED.show();
}
 
//JW Edit BLINK FIX ***************************************
//function made to take in 2 colors, and their respective wait times
void blink(CRGB color1, CRGB color2, long delTime)
{
        //if colorORblack==true, update the array with that color and show it
        if(colorORblack)
        {
                fill_solid(leds,NUM_LEDS, color1);
                FastLED.show();
        }
        //else, if it's not, update it with the second color and show
        else
        {
                fill_solid(leds,NUM_LEDS,color2);
                FastLED.show();
        }
       
        //blink without delay example
        if(millis()-lastUpdate>delTime)
        {
                //switch the current color if we've overrun the timer
                colorORblack=!colorORblack;
                //update the counter
                lastUpdate=millis();
        }
}
 
//BUTTON CONTROL//
void shortKeyPress() {
    Serial.println("short");
    ledMode++;
    if (ledMode > NUM_MODES){
    ledMode=0; }
}

void keyRelease() {
    Serial.println("key release");
        shortKeyPress();
    }

//END//
