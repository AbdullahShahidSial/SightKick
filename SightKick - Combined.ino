#define echo1Pin 2 
#define trig1Pin 4
#define echo2Pin 7 
#define trig2Pin 8
#define echo3Pin 11 
#define trig3Pin 12
#define echo4Pin 13 
#define trig4Pin A1 

#define vib1 3
#define vib2 5
#define vib3 6
#define vib4 9
#define vib5 10

// defines variables
long duration1;
long duration2;
long duration3;
long duration4;
 
int distance1;
int distance2;
int distance3;
int distance4;

int avg;

void setup() {
  
  pinMode(trig1Pin, OUTPUT); 
  pinMode(echo1Pin, INPUT);
  pinMode(trig2Pin, OUTPUT); 
  pinMode(echo2Pin, INPUT);
  pinMode(trig3Pin, OUTPUT); 
  pinMode(echo3Pin, INPUT);
  pinMode(trig4Pin, OUTPUT); 
  pinMode(echo4Pin, INPUT); 

  pinMode(vib1, OUTPUT);
  pinMode(vib2, OUTPUT);
  pinMode(vib3, OUTPUT);
  pinMode(vib4, OUTPUT);
  pinMode(vib5, OUTPUT);
  
  Serial.begin(9600); 
}
void loop() {
  // Clears the trigPin condition
  
  digitalWrite(trig1Pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig1Pin, 1);
  delayMicroseconds(10);
  duration1 = pulseIn(echo1Pin, HIGH);
  distance1 = duration1 * 0.034 / 2;
  
  digitalWrite(trig2Pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig2Pin, 1);
  delayMicroseconds(10);
  duration2 = pulseIn(echo2Pin, HIGH);
  distance2 = duration2 * 0.034 / 2;
  
  digitalWrite(trig3Pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig3Pin, 1);
  delayMicroseconds(10);
  duration3 = pulseIn(echo3Pin, HIGH);
  distance3 = duration3 * 0.034 / 2;
  
  digitalWrite(trig4Pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig4Pin, 1);
  delayMicroseconds(10);
  duration4 = pulseIn(echo4Pin, HIGH);
  distance4 = duration4 * 0.034 / 2;

//  digitalWrite(trig1Pin, LOW);
//  digitalWrite(trig2Pin, LOW);
//  digitalWrite(trig3Pin, LOW);
//  digitalWrite(trig4Pin, LOW);

  if(distance1>85)
  {
    distance1=85;
  }
  if(distance2>85)
  {
    distance2=85;
  }
  if(distance3>85)
  {
    distance3=85;
  }
  if(distance4>85)
  {
    distance4=85;
  }

  Serial.print("Distance1: ");
  Serial.print(distance1);
  Serial.println("cm");
  Serial.print("Distance2: ");
  Serial.print(distance2);
  Serial.println("cm");
  Serial.print("Distance3: ");
  Serial.print(distance3);
  Serial.println("cm");
  Serial.print("Distance4: ");
  Serial.print(distance4);
  Serial.println("cm");
 

  Serial.println(" ");
  delay(100);
    
  if(distance1<60 &&distance2<60 && distance3<60 && distance4<60) // 1111
  {
    avg = (distance2 + distance3)/2;
    
    analogWrite(vib1,0);
    analogWrite(vib2,map(avg,70,3,50,150));
    analogWrite(vib3,map(avg,70,3,50,255));
    analogWrite(vib4,map(avg,70,3,50,150));
    analogWrite(vib5,0);

  }
  else if(distance1>60 && distance2<60 && distance3>60 && distance4>60) // 0100
  {
    avg = distance2;
    
    analogWrite(vib1,0);
    analogWrite(vib2,map(avg,70,3,50,250));
    analogWrite(vib3,map(avg,70,3,50,100));
    analogWrite(vib4,0);
    analogWrite(vib5,0);
  }
  else if(distance1>60 && distance2>60 && distance3<60 && distance4>60) // 0010
  {
    avg = distance3;
    
    analogWrite(vib1,0);
    analogWrite(vib2,0);
    analogWrite(vib3,map(avg,70,3,50,100));
    analogWrite(vib4,map(avg,70,3,50,250));
    analogWrite(vib5,0);
  }
  else if(distance1<60 && distance2<60 && distance3>60 && distance4>60) // 1100
  {
    avg = (distance1 + distance2)/2;
    
    analogWrite(vib1,map(avg,70,3,50,250));
    analogWrite(vib2,map(avg,70,3,50,150));
    analogWrite(vib3,0);
    analogWrite(vib4,0);
    analogWrite(vib5,0);
  }
  else if(distance1>60 && distance2>60 && distance3<60 && distance4<60) // 0011
  {
    avg = (distance3 + distance4)/2;
    
    analogWrite(vib1,0);
    analogWrite(vib2,0);
    analogWrite(vib3,0);
    analogWrite(vib4,map(avg,70,3,50,150));
    analogWrite(vib5,map(avg,70,3,50,250));
  }
  else if(distance1<60 && distance2>60 && distance3>60 && distance4>60) // 1000
  {
    avg = distance1;
    
    analogWrite(vib1,map(avg,70,3,50,250));
    analogWrite(vib2,0);
    analogWrite(vib3,0);
    analogWrite(vib4,0);
    analogWrite(vib5,0);
  }
  else if(distance1>60 && distance2>60 && distance3>60 && distance4<60) // 0001
  {
    avg = distance4;
    
    analogWrite(vib1,0);
    analogWrite(vib2,0);
    analogWrite(vib3,0);
    analogWrite(vib4,0);
    analogWrite(vib5,map(avg,70,3,50,250));
  }

  else if(distance1>60 && distance2>60 && distance3>60 && distance4>60) // 0000
  {
    analogWrite(vib1,0);
    analogWrite(vib2,0);
    analogWrite(vib3,0);
    analogWrite(vib4,0);
    analogWrite(vib5,0);
  }
  
  else
  {
    analogWrite(vib1,map(distance1,85,3,50,250));
    analogWrite(vib2,map(distance2,85,3,50,250));
    analogWrite(vib3,map(((distance2 + distance3)/2),85,3,50,250));
    analogWrite(vib4,map(distance3,85,3,50,250));
    analogWrite(vib4,map(distance4,85,3,50,250));
  }

delay(500);  
}
