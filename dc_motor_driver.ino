
const int motorPin1  = 3;  
const int motorPin2  = 5;  



void setup(){
 
    //Set pins as outputs
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(A0, INPUT);
    Serial.begin(9600);
    

   
}
void loop(){

  int x=analogRead(A0);
    int speed = map(x,0,60,0,200);
    Serial.println(x);
    
    if (speed >= 0 && speed <= 255)
    {
    analogWrite(motorPin1, speed);
    }
    delay(100);
}

