/* Eample Code for Supreme RS485 Nano-Wing 
 * Matthias Kubisch
 * Jetpack Cogintion Lab
 * Dec. 23th 2019
 * 
 * This code is enables recv mode and blinks 
 * the LED on each character received. 
 *
 * To test this, use a USB-to-RS485 interface, 
 * e.g. the FTDI: https://www.ftdichip.com/Support/Documents/DataSheets/Cables/DS_USB_RS485_PCB.pdf
 * and setup a serial terminal program, e.g. screen
 * using: 
 * 
 * $ screen /dev/ttyUSB0 115200
 * 
 * and type on the keyboard, see the 'L' LED blinking on the nano board.
 * 
 * PLEASE NOTE: Depending on how your serial communication is implemented, 
 * it might interfere with uploading code via the Arduino IDE, since the same RX/TX pins are used.
 * It is hence generally recommended to remove the Nano from the RS485Wing in case you notice upload problems.
 */


#define DE 2
#define NRE 4
#define LED 13

void sendmode(bool mode) {
  digitalWrite(DE , mode);
  digitalWrite(NRE, mode);
}

void setup() {
  pinMode(DE , OUTPUT); /* set drive enable pin for output */
  pinMode(NRE, OUTPUT); /* set read disable pin for output */
  pinMode(LED, OUTPUT); /* set nano onboard led for output */
  Serial.begin(115200);
  
  sendmode(false); // read mode
}

void loop() {
  if (Serial.available() > 0) {
    char c = Serial.read();
    digitalWrite(LED, HIGH);
    delay(250); // ms
    digitalWrite(LED, LOW);
    delay(250); // ms
  }
  else 
    delay(10); // ms
}
