#define TRIG_PIN A2
#define ECHO_PIN A3


void setup() {
pinMode(13,OUTPUT);  
pinMode(12,OUTPUT);   
pinMode(11,OUTPUT);  
pinMode(10,OUTPUT);
Serial.begin(9600);
pinMode(ECHO_PIN, INPUT); //Set the connection pin output mode Echo pin
pinMode(TRIG_PIN, OUTPUT);//Set the connection pin output mode trig pin
}

void loop() {
  
  int temp = readPing();
 

  Serial.flush();

  //printing time in seconds
  Serial.print("distance : ");
  Serial.print(temp,DEC);
  delay(100);

 if (readPing() >10){
    Forward();
  }
  if (readPing()<10){
    Stop();
    delay(500);
    Backward();
    delay(500);
    Stop();
    delay(100);
    Left();
    delay(500);
    
  }
}

int Stop(){
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
}
int Forward(){
  digitalWrite(13,HIGH);
  digitalWrite(11,HIGH);
  
  
  }


int Backward(){
  digitalWrite(12,HIGH);
  digitalWrite(10,HIGH); 
  
  }

int Left(){

    digitalWrite(11,HIGH);
    

}

int Right(){

    digitalWrite(13,HIGH);

}

int readPing()
{
  // establish variables for duration of the ping,
  // and the distance result in inches and centimeters:
  long duration, cm;
  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(TRIG_PIN, OUTPUT);
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(5);
  digitalWrite(TRIG_PIN, LOW);

  pinMode(ECHO_PIN, INPUT);
  duration = pulseIn(ECHO_PIN, HIGH);

  // convert the time into a distance
  cm = microsecondsToCentimeters(duration);
  return cm ;
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
