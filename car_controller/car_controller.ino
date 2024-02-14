#include <esp_now.h>
#include <WiFi.h>
#include <ESP32Servo.h>

Servo myservo;  // create servo object to control a servo
// 16 servo objects can be created on the ESP32

int pos = 0;    // variable to store the servo position
int servoPin = 4;



const int freq = 3000;
const int pwmChannel = 0;
const int resolution = 8;
int dutyCycle = 200;

void i_received_data_from_remote(const uint8_t * mac, const uint8_t *incomingData, int len) {
  Serial.print("Bytes received: ");
  Serial.println(len);
  Serial.print("Message type: ");
  Serial.println(incomingData[0]);
  Serial.print("X: ");
  Serial.println(incomingData[1]);
    Serial.print("Y: ");
  Serial.println(incomingData[2]);
  if (incomingData[1] > 130){
    int pwm = (double)(255.0/130.0) * (double)(incomingData[1] - 130);
      Serial.print("FWD: ");
  Serial.println(pwm);
  digitalWrite(6, 1); //LPWM L motor
    digitalWrite(5, 0); //LPWM L motor

  analogWrite(7, pwm); //LPWM L motor
  }else if(incomingData[1] < 100){
        int pwm = (double)(255.0/100.0) *(double)((-1)*(incomingData[1] - 100));
      Serial.print("Back: ");
  Serial.println(pwm);
  digitalWrite(6, 0); //LPWM L motor
    digitalWrite(5, 1); //LPWM L motor
  analogWrite(7, pwm); //LPWM L motor
  }else if (incomingData[1] > 100 && incomingData[1] < 130){
      analogWrite(7, 0); //LPWM L motor
  }

    if (incomingData[2] > 130){
    int pwm = (double)(255.0/130.0) * (double)(incomingData[1] - 130);
      Serial.print("FWD: ");
  Serial.println(pwm);
  digitalWrite(18, 1); //LPWM L motor
    digitalWrite(19, 0); //LPWM L motor

  analogWrite(9, pwm); //LPWM L motor
  }else if(incomingData[2] < 100){
        int pwm = (double)(255.0/100.0) *(double)((-1)*(incomingData[1] - 100));
      Serial.print("Back: ");
  Serial.println(pwm);
  digitalWrite(18, 0); //LPWM L motor
    digitalWrite(19, 1); //LPWM L motor
  analogWrite(9, pwm); //LPWM L motor
  }else if (incomingData[2] > 100 && incomingData[2] < 130){
      analogWrite(9, 0); //LPWM L motor
      digitalWrite(18, 0); //LPWM L motor
    digitalWrite(19, 0); //LPWM L motor
  }

}
 
void setup() {
  Serial.begin(115200);
  
  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  /*pinMode(9, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);*/

  digitalWrite(2, 1); // pwm
  digitalWrite(1, 1); //set forward direction
  digitalWrite(10, 0); //standby direction
  //digitalWrite(11, 1); // back for a motor



  // Allow allocation of all timers
	ESP32PWM::allocateTimer(0);
	ESP32PWM::allocateTimer(1);
	ESP32PWM::allocateTimer(2);
	ESP32PWM::allocateTimer(3);
	myservo.setPeriodHertz(50);    // standard 50 hz servo
	myservo.attach(servoPin, 500, 2400); // attaches the servo on pin 18 to the servo object
	// using default min/max of 1000us and 2000us
	// different servos may require different min/max settings
	// for an accurate 0 to 180 sweep


  
  esp_now_register_recv_cb(i_received_data_from_remote);
  
}
 
void loop() {  

  /*for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
		// in steps of 1 degree
		myservo.write(pos);    // tell servo to go to position in variable 'pos'
		delay(5);             // waits 15ms for the servo to reach the position
	}
	for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
		myservo.write(pos);    // tell servo to go to position in variable 'pos'
		delay(5);             // waits 15ms for the servo to reach the position
	}*/

}
