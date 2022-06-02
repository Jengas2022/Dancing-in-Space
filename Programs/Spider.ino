#include <Servo.h>
#include <Adafruit_NeoPixel.h>
Servo servos[13];
Adafruit_NeoPixel strip = Adafruit_NeoPixel(6, A1, NEO_GRB + NEO_KHZ800); //NEO_KHZ400+NEO_RGB
int n=0;

boolean areLeftLegsRaised = false;

int distance() {
  
  long duration, centimeters;               // initialize variables
  digitalWrite(A2, LOW);
  delay(2);
  digitalWrite(A2, HIGH);
  delay(5);
  digitalWrite(A2, LOW);
  duration = pulseIn(A3, HIGH);            
  centimeters = duration / 29 / 2;          // convert the time into a centimeters
  return centimeters ;
}

void rotate(int index, int angle) {
  servos[index - 2].write(angle);           // create a method for every servo rotations
}

void balancedPosition() {                   // create a balanced position method
  for (int i = 2; i < 14; i++) {           
    rotate(i,90);
  }
}

 void slowBalancedPosition(int val, int t){
  for (int i=0; i<val; i++){
    rotate(2,180-i);
    rotate(4,180-i);
    rotate(6,180-i);
    rotate(8,i);
    rotate(10,i);
    rotate(12,i);
    delay(t);
  }
}

void slowUnbalancedPosition(int val,int t){     //create an unbalanced position method 
  balancedPosition();
  for (int i=90;i>val;i--){
    rotate(2,180-i);
    rotate(4,180-i);
    rotate(6,180-i);
    rotate(8,i);
    rotate(10,i);
    rotate(12,i);
    delay(t);
  }
}

void straight(int t) {                     //create a movement method
  
  if (!areLeftLegsRaised) {                //control if left legs are raised
    //raises left legs
    rotate(2,60);
    rotate(6,60);
    rotate(10,120);
    delay(t);

    areLeftLegsRaised = true;
  }  

  //rotate left hips
  rotate(3,120);
  rotate(7,120);
  rotate(11,60);
  delay(t);

  //lower left legs
  rotate(2,90);
  rotate(6,90);
  rotate(10,90);
  delay(t);

  //raise right legs
  rotate(4, 60);
  rotate(8, 120);
  rotate(12, 120);
  delay(t);

  //rotate left hips
  rotate(3, 90);
  rotate(7, 90);
  rotate(11, 90);
  delay(t);

  //rotate right hips
  rotate(5, 120);
  rotate(9, 60);
  rotate(13, 60);
  delay(t);

  //lower right legs
  rotate(4, 90);
  rotate(8, 90);
  rotate(12, 90);
  delay(t);

  //raise left legs
  rotate(2, 60);
  rotate(6, 60);
  rotate(10, 120);
  delay(t);

  //rotate right hips
  rotate(5, 90);
  rotate(9, 90);
  rotate(13, 90);
  delay(t);
}


void back(int t) {                          // create a movement method
   
  if (!areLeftLegsRaised) {                 // control if left legs are raised
    //raises left legs
    rotate(2, 60);
    rotate(6, 60);
    rotate(10, 120);
    delay(t);

    areLeftLegsRaised = true;
  }

  //rotate left hips
  rotate(3, 60);
  rotate(7, 60);
  rotate(11, 120);
  delay(t);

  //lower left legs
  rotate(2, 90);
  rotate(6, 90);
  rotate(10, 90);
  delay(t);

  //raise right legs
  rotate(4, 60);
  rotate(8, 120);
  rotate(12, 120);
  delay(t);

  //rotate left hips
  rotate(3, 90);
  rotate(7, 90);
  rotate(11, 90);
  delay(t);

  //rotate right hips
  rotate(5, 60);
  rotate(9, 120);
  rotate(13, 120);
  delay(t);

  //lower right legs
  rotate(4, 90);
  rotate(8, 90);
  rotate(12, 90);
  delay(t);

  //raise left legs
  rotate(2, 60);
  rotate(6, 60);
  rotate(10, 120);
  delay(t);

  //rotate right hips
  rotate(5, 90);
  rotate(9, 90);
  rotate(13, 90);
  delay(t);
}

void clockwise(int t) {                       // create a rotation method

  rotate(2, 60);
  rotate(6, 60);
  rotate(10, 120);
  delay(t);

  rotate(3, 116);
  rotate(7, 116);
  rotate(11, 116);
  delay(t);

  rotate(2, 90);
  rotate(6, 90);
  rotate(10, 90);
  delay(t);

  rotate(4, 60);
  rotate(8, 120);
  rotate(12, 120);
  delay(t);

  rotate(3, 90);
  rotate(7, 90);
  rotate(11, 90);
  delay(t);

  rotate(5, 116);
  rotate(9, 116);
  rotate(13, 116);
  delay(t);

  rotate(4, 90);
  rotate(8, 90);
  rotate(12, 90);
  delay(t);

  rotate(2, 60);
  rotate(6, 60);
  rotate(10, 120);
  delay(t);

  rotate(5, 90);
  rotate(9, 90);
  rotate(13, 90);
  delay(t);
}

void counterClockwise(int t) {              //create a rotation method

  rotate(2, 60);
  rotate(6, 60);
  rotate(10, 120);
  delay(t);

  rotate(3, 64);
  rotate(7, 64);
  rotate(11, 64);
  delay(t);

  rotate(2, 90);
  rotate(6, 90);
  rotate(10, 90);
  delay(t);

  rotate(4, 60);
  rotate(8, 120);
  rotate(12, 120);
  delay(t);

  rotate(3, 90);
  rotate(7, 90);
  rotate(11, 90);
  delay(t);

  rotate(5, 64);
  rotate(9, 64);
  rotate(13, 64);
  delay(t);

  rotate(4, 90);
  rotate(8, 90);
  rotate(12, 90);
  delay(t);

  rotate(2, 60);
  rotate(6, 60);
  rotate(10, 120);
  delay(t);

  rotate(5, 90);
  rotate(9, 90);
  rotate(13, 90);
  delay(t);
}

void ninetyDegreesClockwiseTurn(int rotation) {                         //create a 90 degreese movement
  for (int i = 0; i < rotation; i++) {
    clockwise(50);
  }
  balancedPosition();
}

void ninetyDegreesCounterclockwiseTurn(int rotation){                   // create a -90 degreese movement
  balancedPosition();
  for (int i = 0; i < rotation; i++) {
    counterClockwise(50);
  }
  balancedPosition();
}

void headRotation(int t){
  balancedPosition();

  delay(750);
  servos[0].attach(14);

  for (int i = 90; i > 0; i--) {                            //set servo pins
    rotate(2,i);
    delay(t);
  }
  
  delay(500);
  
  for (int i = 0; i < 180; i++) {                            //set servo pins
    rotate(2,i);
    delay(t);
  }
  
  rotate(2,90);
  delay(750);

  servos[0].attach(2);

}

void greet(){
  ninetyDegreesCounterclockwiseTurn(4);
  delay(1000);

  rotate(9,60);
  delay(50);
  
  rotate(8,180);
  delay(500);
  rotate(8,120);
  delay(250);
  rotate(8,180);
  delay(250);
  rotate(8,90);
  delay(500);

  rotate(9,90);
  
  ninetyDegreesClockwiseTurn(8);
  delay(1000);

  rotate(3,120);
  delay(50);
  
  rotate(2,0);
  delay(500);
  rotate(2,60);
  delay(250);
  rotate(2,0);
  delay(250);
  rotate(2,90);
  delay(500);

  rotate(3,90);

  ninetyDegreesCounterclockwiseTurn(5);
}

void alert(){
  balancedPosition();
  delay(50);
  rotate(3,10);
  rotate(5,40);
  rotate(7,60);
  rotate(9,170);
  rotate(11,140);
  rotate(13,120);
}

void greetR(){
  rotate(9,60);
  delay(50);
  
  rotate(8,180);
  delay(500);
  rotate(8,120);
  delay(250);
  rotate(8,180);
  delay(250);
  rotate(8,90);
  delay(500);

  rotate(9,90);
}

void swing(){

  for (int i=90; i<151; i++){
    rotate(8,i);
    rotate(10,i);
    rotate(12,i);
    delay(11);
  }
  
  rotate(8,90);
  rotate(10,90);
  rotate(12,90);
  
  for (int i=90; i>29; i--){
    rotate(2,i);
    rotate(4,i);
    rotate(6,i);
    delay(11);
  }
  
  rotate(2,90);
  rotate(4,90);
  rotate(6,90);
}

void drums (){
  balancedPosition();
  delay(300);
  rotate(5,160);
  rotate(7,20);
  rotate(3,160);
  rotate(9,20);
  rotate(11,20);
  rotate(13,160);
  delay(300);

  for (int i=90; i>0; i--){
    rotate(2,i);
    delay(5);
  }

  for (int i=0; i<90; i++){
    rotate(2,i);
    rotate(8,i+90);
    delay(5);
  }
    
  for (int i=90; i>0; i--){
    rotate(2,i);
    rotate(8,i+90);
    delay(5);
  }

  for (int i=0; i<90; i++){
    rotate(2,i);
    rotate(8,i+90);
    delay (5);  
  }

  for (int i=180; i>90; i--){
    rotate(8,i);
    delay(5);
  }
}

void alternatingMode (){
  rotate(8,160);
  delay(300);
  rotate(4,20);
  delay(300);
  rotate(12,160);
  delay(300);
  
  rotate(4,50);
  rotate(8,130);
  rotate(12,130);
  delay(300);

  rotate(4,0);
  rotate(8,180);
  rotate(12,180);
  delay(300);
  balancedPosition();
  
  rotate(2,20);
  delay(300);
  rotate(10,160);
  delay(300);
  rotate(6,20);
  delay(300);
  
  rotate(2,50);
  rotate(6,50);
  rotate(10,130);
  delay(300);

  rotate(2,0);
  rotate(6,0);
  rotate(10,180);
  delay(300);
  balancedPosition();

  rotate(8,160);
  delay(300);
  rotate(4,20);
  delay(300);
  rotate(12,160);
  delay(300);
  
  rotate(4,50);
  rotate(8,130);
  rotate(12,130);
  delay(300);

  rotate(4,0);
  rotate(8,180);
  rotate(12,180);
  delay(300);
  balancedPosition();
  
  rotate(2,20);
  delay(300);
  rotate(10,160);
  delay(300);
  rotate(6,20);
  delay(300);
  
  rotate(2,50);
  rotate(6,50);
  rotate(10,130);
  delay(300);

  rotate(2,0);
  rotate(6,0);
  rotate(10,180);
}  

void pushUp(int val){
  for (int i=0; i<val; i++){
    slowUnbalancedPosition(15,5);
    delay(300);
    slowBalancedPosition(90,5);
    delay(300);
  }
}

void wwry_1(){
  slowUnbalancedPosition(15,4);
  delay(40);
  slowBalancedPosition(90,4);
  delay(80);
  
  rotate(5,130);
  rotate(7,50);
  rotate(11,50);
  rotate(13,130);
  rotate(2,20);
  rotate(8,160);
  delay(500);
  
  balancedPosition();
  delay(325);
  slowUnbalancedPosition(15,5);
  delay(40);
  slowBalancedPosition(90,5);
}

void setup(){

  strip.begin();                                            // initialize led strip
  strip.setBrightness(100);                                  // set brightness strip
  
  strip.setPixelColor(0,strip.Color(255,0,0));
  strip.setPixelColor(1,strip.Color(255,255,255));
  strip.setPixelColor(2,strip.Color(0,255,0));
  strip.setPixelColor(3,strip.Color(0,255,0));
  strip.setPixelColor(4,strip.Color(255,255,255));
  strip.setPixelColor(5,strip.Color(255,0,0));

  strip.show();
  
  pinMode(A3, INPUT);                                       //A3 echoPin
  pinMode(A2, OUTPUT);                                      //A2 trigPin

  for (int i = 0; i < 12; i++) {                            //set servo pins
    servos[i].attach(i + 2);
  }

  balancedPosition();
  
}

void loop(){
 
  headRotation(10);
  greet();
  delay(500);

  for(int i=0;i<5;i++){
    straight(50);
  }
  delay(500);
  
  headRotation(5);
  delay(250);
  
  for(int i=0;i<5;i++){
    back(50);
  }
  delay(500);
  
  slowUnbalancedPosition(0,15);
  delay(500);
  balancedPosition();
  delay(300);
  
  ninetyDegreesCounterclockwiseTurn(4);
  delay(500);
  
  alert();
  delay(2250);
  balancedPosition();
  delay(500);
  greetR();
  delay(500);                                                                                                                                                                                                                                                                                                                                                                                                                                                      
  ninetyDegreesClockwiseTurn(3);  
  balancedPosition();
  delay(950);
  
  wwry_1(); 
  delay(500);
  ninetyDegreesCounterclockwiseTurn(16);
  delay(500);
  balancedPosition();
  delay(1000);
  for(int i=0;i<5;i++){
    swing();
  }
  delay(1000);
  
  balancedPosition();
  delay (2000);
  for(int i=0;i<4;i++){
    straight(50);
  }

  /*  
  pushUp(5);
  delay(500);
  drums();
  delay(1000);
  balancedPosition();
  delay(500);
  alternatingMode();
  delay(1000); 
  pushUp(); 
  delay(1000);                                                                                                             

}
