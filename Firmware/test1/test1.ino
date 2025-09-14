#include <QMC5883LCompass.h>
#include <Wire.h>

QMC5883LCompass compass;

// #define LED_PIN 4  
// #define LED_PIN2 5  

// int pwmPins[] = {6, 7}; 

void setup() {
  // Define UART
  Serial1.begin(9600);

  //Define I2C
  Wire.begin();
  
//   //Define PIN OUT
//   pinMode(LED_PIN, OUTPUT);
//   pinMode(LED_PIN2, OUTPUT); 

//   //Define PWM
//   for (int i = 0; i < 2; i++) {
//     pinMode(pwmPins[i], OUTPUT);
//   }

    // ====== PC7 (OC4A, Timer4) ======
    // DDRC |= (1 << PC7);                 // PC7 output
    // TCCR4A = (1 << COM4A1) | (1 << PWM4A); // Fast PWM, non-inverting
    // TCCR4B = (1 << CS41);               // prescaler = 8
    // OCR4A = 128;                        // duty 50%

    // // ====== PC6 (OC3A, Timer3) ======
    // DDRC |= (1 << PC6);                 // PC6 output
    // TCCR3A = (1 << COM3A1) | (1 << WGM30); // Fast PWM 8-bit
    // TCCR3B = (1 << WGM32) | (1 << CS31);   // prescaler = 8
    // OCR3A = 128;                        // duty 50%

    // // ====== PB6 (OC1B, Timer1) ======
    // DDRB |= (1 << PB6);                 // PB6 output
    // TCCR1A = (1 << COM1B1) | (1 << WGM10); // Fast PWM 8-bit
    // TCCR1B = (1 << WGM12) | (1 << CS11);   // prescaler = 8
    // OCR1B = 128;                        // duty 50%

    // // ====== PB5 (OC1A, Timer1) ======
    // DDRB |= (1 << PB5);                 // PB5 output
    // TCCR1A |= (1 << COM1A1);               // bật OC1A
    // OCR1A = 128;                        // duty 50%

    // compass.init();
}

void loop() {

  //   //TEST UART
  Serial1.println("I2C Scanner");

//   // TEST LED
//   // digitalWrite(LED_PIN, HIGH);  // bật LED
//   // digitalWrite(LED_PIN2, LOW);  // bật LED
//   // delay(500);
//   // digitalWrite(LED_PIN, LOW);   // tắt LED
//   // digitalWrite(LED_PIN2, HIGH);  // bật LED
//   // delay(500);

//   //TEST PWM
//   //   analogWrite(9, 64);   // ~25%
//   // analogWrite(10, 128); // ~50%
//   // analogWrite(5, 192);  // ~75%
//   // analogWrite(13, 255); // 100% (ON)
//   // analogWrite(12, 32);  // ~12%
//   // analogWrite(6, 160);  // ~62%
//   // analogWrite(11, 96);  // ~37%
//   for(int i = 0; i < 2; i++){
//     for(int j = 0; j < 255; j++){
//         analogWrite(pwmPins[i], j);
//         delay(1000);
//       }
//   }

  // for (int val = 254; val < 255; val++) {
  //   OCR4A = val;  // PC7
  //   OCR3A = val;  // PC6
  //   OCR1A = val;  // PB5
  //   OCR1B = val;  // PB6
  //   delay(10);
  // }

    int x, y, z;
  
  byte error, address;
  int nDevices = 0;

  for (address = 1; address < 255; address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial1.print("I2C device found at 0x");
      Serial1.println(address, HEX);
      nDevices++;
    }

  }

  if (nDevices == 0) {
    Serial1.println("No I2C devices found\n");
  }
  
  delay(100);
}


