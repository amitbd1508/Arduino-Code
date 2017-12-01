// www.TinkerHobby.com
// Natalia Fargasch Norman
// Dual seven-segment LED Display
// Common Anode digit 1 pin 10
// Common Anode digit 2 pin 5

//       CA1 G  F  A  B
//        |  |  |  |  |      -> pins and segments they control
//   ---------    ---------
//   |   A   |    |   A   |
//  F|       |B  F|       |B
//   |---G---|    |---G---|
//  E|       |C  E|       |C
//   |   D   |    |   D   |
//   ---------    ---------
//        |  |  |  |  |      -> pins and segments they control
//        D  DP E  C CA2

// Segments that make each number when lit:
// 0 => -FEDCBA
// 1 => ----BC-
// 2 => G-ED-BA
// 3 => G--DCBA
// 4 => GF--CB-
// 5 => GF-DC-A
// 6 => GFEDC-A
// 7 => ----CBA
// 8 => GFEDCBA
// 9 => GF-DCBA

// Arduino digital pins used to light up
// corresponding segments on the LED display
#define A 3
#define B 2
#define C 6
#define D 8
#define E 7
#define F_SEG 4
#define G 5

// Pins driving common anodes
#define CA1 11
#define CA2 12
#define LED 10
// Pins for A B C D E F G, in sequence
const int segs[7] = { A, B, C, D, E, F_SEG, G };

// Segments that make each number
//const byte numbers[10] = { 0b0111111, 0b0000110, 0b0011011, 0b1001111, 0b1100110, 0b1101101,
//0b1111101, 0b0000111, 0b1111111, 0b1101111 };

const byte numbers[10] = { 0b1000000, 0b1111001, 0b0100100, 0b0110000, 0b0011001, 0b0010010,
                           0b0000010, 0b1111000, 0b0000000, 0b0010000
                         };

int pinHigh=HIGH;
int pinLOW=LOW'
void setup() {
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F_SEG, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(CA1, OUTPUT);
  pinMode(CA2, OUTPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}
int n = 0 ;
int dx1, dx2;
int num = 0;
bool ys = false;
void loop() {

  if (Serial.available()) {
    num = readInt();

  }
  sprint(num);



}
int incomingValue = 0; // Max value is 65535
char incomingByte;
int integerValue = 0;
int readInt()
{
  // something came across serial
  integerValue = 0;         // throw away previous integerValue
  while (1) {           // force into a loop until 'n' is received
    incomingByte = Serial.read();
    if (incomingByte == '\n') break;   // exit the while(1), we're done receiving
    if (incomingByte == -1) continue;  // if no characters are in the buffer read() returns -1
    integerValue *= 10;  // shift left 1 decimal place
    // convert ASCII to integer, add, and shift left 1 decimal place
    integerValue = ((incomingByte - 48) + integerValue);
  }
  if (integerValue > 999)
  {

    integerValue = integerValue / 1000;
  }
  if (integerValue > 99)
  {
    ys = true;
    integerValue = integerValue / 10;
  }
  else ys = false;
  Serial.println(integerValue);   // Do something with the value
  return integerValue;

}
void sprint(int n)
{
  if (n > 99)
    n = 99;
  int d2 = n % 10;
  int d1 = n / 10;

  lightDigit1(numbers[d1]);
  delay(5);
  lightDigit2(numbers[d2]);
  if (ys)
    digitalWrite(LED, HIGH);
  if (!ys)
    digitalWrite(LED, LOW);

  delay(3);
}

void lightDigit1(byte number) {
  digitalWrite(CA1, LOW);
  digitalWrite(CA2, HIGH);
  lightSegments(number);
}

void lightDigit2(byte number) {
  digitalWrite(CA1, HIGH);
  digitalWrite(CA2, LOW);
  lightSegments(number);
}

void lightSegments(byte number) {
  for (int i = 0; i < 7; i++) {
    int bit = bitRead(number, i);
    digitalWrite(segs[i], bit);
  }
}
