#define LED_PIN 4  // Arduino pin 4 (tương ứng với GPIO4 / PD4 trên ATmega32U4)
#define LED_PIN2 5  // Arduino pin 4 (tương ứng với GPIO4 / PD4 trên ATmega32U4)

char mystr[10];

void setup() 
{
  pinMode(LED_PIN, OUTPUT);  // cấu hình chân LED làm output
  pinMode(LED_PIN2, OUTPUT);  // cấu hình chân LED làm output
  Serial.begin(9600);
  Serial1.begin(9600);   //it was missing
}

void loop() 
{
  
  byte n = Serial1.available();
  if (n != 0)
  {
      byte m = Serial1.readBytes(mystr,5);  //blocking code
      mystr[m] = '\0';      //you need to place null character at the end of char array
      Serial.println(mystr);
      digitalWrite(LED_PIN, HIGH);  // bật LED
      digitalWrite(LED_PIN2, LOW);  // bật LED
      delay(500);
      digitalWrite(LED_PIN, LOW);   // tắt LED
      digitalWrite(LED_PIN2, HIGH);  // bật LED
      delay(500);
  }
}