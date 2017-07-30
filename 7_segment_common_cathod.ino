
//showing digit from 0-9 in 7 segment 
//code from common anode
int a = 2;  //For displaying segment "a"
int b = 3;  //For displaying segment "b"
int c = 4;  //For displaying segment "c"
int d = 5;  //For displaying segment "d"
int e = 6;  //For displaying segment "e"
int f = 8;  //For displaying segment "f"
int g = 9;  //For displaying segment "g"

void setup() {
  // put your setup code here, to run once:
  pinMode(a, OUTPUT);  //A
  pinMode(b, OUTPUT);  //B
  pinMode(c, OUTPUT);  //C
  pinMode(d, OUTPUT);  //D
  pinMode(e, OUTPUT);  //E
  pinMode(f, OUTPUT);  //F
  pinMode(g, OUTPUT);  //G
  Serial.begin(9600);

}
void displayDigit(int digit)
{
  //Conditions for displaying segment a
  if (digit != 1 && digit != 4)
    digitalWrite(a, LOW);

  //Conditions for displaying segment b
  if (digit != 5 && digit != 6)
    digitalWrite(b, LOW);

  //Conditions for displaying segment c
  if (digit != 2)
    digitalWrite(c, LOW);

  //Conditions for displaying segment d
  if (digit != 1 && digit != 4 && digit != 7)
    digitalWrite(d, LOW);

  //Conditions for displaying segment e
  if (digit == 2 || digit == 6 || digit == 8 || digit == 0)
    digitalWrite(e, LOW);

  //Conditions for displaying segment f
  if (digit != 1 && digit != 2 && digit != 3 && digit != 7)
    digitalWrite(f, LOW);
  if (digit != 0 && digit != 1 && digit != 7)
    digitalWrite(g, LOW);

}
void turnOn()
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void turnOff()
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*for(int i=0;i<10;i++)
    {
    displayDigit(3);
    delay(1000);

    }*/
    if(Serial.available())
    {
      char state=Serial.read();
      if(state=='a')
        input();
      else if(state=='b')
        inc();
       else if(state=='c')
        dec();
    }





}
void inc(){
  for(int i=0;i<=10;i++)
  {
    if(i==10)
    {
      i=0;
    }
     if (Serial.available())
     {
       if(Serial.read()=='x')
       break;
     }
    displayDigit(i);
    delay(1000);
    turnOff();
  }
}

void dec(){
  for(int ii=9;ii>=0;ii--)
  {
    
    displayDigit(ii);
    delay(1000);
    turnOff();
     if (Serial.available())
     {
       if(Serial.read()=='x')
       break;
     }
    
    if(ii==0)
    {
      ii=10;
    }
  }
}
void input()
{
  int x = 0;
  while (1)
  {
    if (Serial.available())
    {
      x = Serial.read();
      if(x==(char)'x')
        break;



    }
    displayDigit(x - 48);
    Serial.println(x);
    delay(1000);
    turnOff();
  }
}
