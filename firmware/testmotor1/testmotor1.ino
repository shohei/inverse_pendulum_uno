int m1_1 = 4;
int m1_2 = 5;
int m1_pwm = 6;
int m2_1 = 7;
int m2_2 = 8;
int m2_pwm = 9;

void setup(){
	pinMode(m1_1,OUTPUT); 
	pinMode(m1_2,OUTPUT); 
	pinMode(m1_pwm,OUTPUT); 
	pinMode(m2_1,OUTPUT); 
	pinMode(m2_2,OUTPUT); 
	pinMode(m2_pwm,OUTPUT); 

	Serial.begin(9600);
}

void loop(){
  run(100,100);
  delay(2000);
  run(0,0);
  delay(2000);
  run(-100,-100);
  delay(2000);
}
  

void run(int speed1, int speed2){
  if(speed1>255) {
    speed1=255; 
    } else if(speed1<-255){
    speed1=-255;  
    } else if(speed1==0){
    speed1=0; 
  }

  if(speed2>255) {
    speed2=255; 
    } else if(speed2<-255){
    speed2=-255;  
    } else if(speed2==0){
    speed2=0; 
  }

  analogWrite(m1_pwm,speed1);
  analogWrite(m2_pwm,speed2);

  if(speed1>0){
    digitalWrite(m1_1,HIGH);
    digitalWrite(m1_2,LOW);
  } else if(speed1<0){
    digitalWrite(m1_1,LOW);
    digitalWrite(m1_2,HIGH);
  } else if(speed1==0){
    digitalWrite(m1_1,LOW);
    digitalWrite(m1_2,LOW);
  }
  
  if(speed2>0){
    digitalWrite(m2_1,HIGH);
    digitalWrite(m2_2,LOW);
  } else if(speed2<0){
    digitalWrite(m1_1,LOW);
    digitalWrite(m2_1,LOW);
    digitalWrite(m2_2,HIGH);
  } else if(speed2==0){
    digitalWrite(m2_1,LOW);
    digitalWrite(m2_2,LOW);
  }
}

