#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);


void stopped(){
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void straight(){
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void back(){
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void right(){
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void left(){
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void velocity(int v){
  motor1.setSpeed(v);
  motor2.setSpeed(v);
  motor3.setSpeed(v);
  motor4.setSpeed(v);
}

void setup() { 
  velocity(255);
  stopped();
}

void loop() {
  right();
  delay(2500);
  stopped();
}
  /*
  delay(7800);
  straight();
  delay(11000);
  stopped();
  right();
  delay(1900);
  stopped();
 delay(2100);
  left();
  delay(2000);
  stopped();
    
  back();
  delay(4500);
  stopped();  
  straight();
  delay(4500);
  stopped();
 
  delay(300000);
}
*/
