#include <FastLED.h>

#define NUM_STRIPS 16
#define NUM_LEDS_PER_STRIP 16
CRGB leds[NUM_STRIPS][NUM_LEDS_PER_STRIP];
String message = "";

class digit{
  public:
  int posx;
  int posy;
  void numGen(int num){
    switch(num){
      case 0:
        seg0 = false;
        seg1 = true;
        seg2 = true;
        seg3 = true;
        seg4 = true;
        seg5 = true;
        seg6 = true;
        digitBuild();
        FastLED.show();
        break;
      case 1:
        seg0 = false;
        seg1 = false;
        seg2 = false;
        seg3 = true;
        seg4 = true;
        seg5 = false;
        seg6 = false;
        digitBuild();
        FastLED.show();
        break;
      case 2:
        seg0 = true;
        seg1 = false;
        seg2 = true;
        seg3 = true;
        seg4 = false;
        seg5 = true;
        seg6 = true;
        digitBuild();
        FastLED.show();
        break;
      case 3:
        seg0 = true;
        seg1 = false;
        seg2 = true;
        seg3 = true;
        seg4 = true;
        seg5 = true;
        seg6 = false;
        digitBuild();
        FastLED.show();
        break;
      case 4:
        seg0 = true;
        seg1 = true;
        seg2 = false;
        seg3 = true;
        seg4 = true;
        seg5 = false;
        seg6 = false;
        digitBuild();
        FastLED.show();
        break;
      case 5:
        seg0 = true;
        seg1 = true;
        seg2 = true;
        seg3 = false;
        seg4 = true;
        seg5 = true;
        seg6 = false;
        digitBuild();
        FastLED.show();
        break;
     case 6:
        seg0 = true;
        seg1 = true;
        seg2 = true;
        seg3 = false;
        seg4 = true;
        seg5 = true;
        seg6 = true;
        digitBuild();
        FastLED.show();
        break;
      case 7:
        seg0 = false;
        seg1 = false;
        seg2 = true;
        seg3 = true;
        seg4 = true;
        seg5 = false;
        seg6 = false;
        digitBuild();
        FastLED.show();
        break;
      case 8:
        seg0 = true;
        seg1 = true;
        seg2 = true;
        seg3 = true;
        seg4 = true;
        seg5 = true;
        seg6 = true;
        digitBuild();
        FastLED.show();
        break;
      case 9:
        seg0 = true;
        seg1 = true;
        seg2 = true;
        seg3 = true;
        seg4 = true;
        seg5 = false;
        seg6 = false;
        digitBuild();
        FastLED.show();
        break; 
     }
  }
  private:
  bool seg0;
  bool seg1;
  bool seg2;
  bool seg3;
  bool seg4;
  bool seg5;
  bool seg6; 
  
  void digitBuild(void){
    midLine(posx,posy,seg0);
    vertLine(posx-1,posy,seg1);
    hortLine(posx-1,posy+4,seg2);
    vertLine(posx+2,posy+1,seg3);
    vertLine(posx+2,posy-3,seg4);
    hortLine(posx,posy-4,seg5);
    vertLine(posx-1,posy-4,seg6);
  }
  void vertLine(int x, int y, bool state){
    if(state){
      for( int i = y; i < y+4; i++){
        leds[x][i] = CRGB(0,0,200);
      } 
    }else{
      for( int i = y; i < y+4; i++){
        leds[x][i] = CRGB(0,0,0);
      } 
    }
    
  }
  void hortLine(int x, int y, bool state){
    if(state){
      for( int i = x; i < x+3;i++){
        leds[i][y] = CRGB(0,0,200);
      }
    }else{
      for( int i = x; i < x+3;i++){
        leds[i][y] = CRGB(0,0,0);
      }
    }
    
  }
  void midLine(int x, int y, bool state){
    if(state){
      leds[x][y] = CRGB(0,0,200);
      leds[x+1][y] = CRGB(0,0,200);
    }else{
      leds[x][y] = CRGB(0,0,0);
      leds[x+1][y] = CRGB(0,0,0);
    }
  }
};
digit hour;
digit minute;
digit minute2;
void setup() {
  FastLED.addLeds<NEOPIXEL, 23>(leds[0], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 25>(leds[1], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 27>(leds[2], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 29>(leds[3], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 31>(leds[4], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 33>(leds[5], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 35>(leds[6], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 37>(leds[8], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 39>(leds[9], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 41>(leds[10], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 43>(leds[11], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 45>(leds[12], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 47>(leds[7], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 49>(leds[13], NUM_LEDS_PER_STRIP);  
  FastLED.addLeds<NEOPIXEL, 51>(leds[14], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 53>(leds[15], NUM_LEDS_PER_STRIP);
  Serial2.begin(9800);
  hour.posx = 3;
  hour.posy = 8;
  minute.posx = 8;
  minute.posy = 8;
  minute2.posx = 13;
  minute2.posy = 8;
}

void loop() { 
  hour.numGen(1);
//  while(Serial2.available()){
//    char c = Serial2.read();
//      switch (c){
//        case 'a':
//          int colonPosition = message.indexOf('a');
//          message.setCharAt(colonPosition, ' '); 
//          num = message.toInt();
//          hour.numGen(num)
//          break;
//        case 'b':
//          int colonPosition = message.indexOf('a');
//          message.setCharAt(colonPosition, ' '); 
//          num = message.toInt();
//          hour.numGen(num)
//        default:
//          message += c;
//          break;
//      }
//    }
//  }
}
