#include <ESP8266WiFi.h>
#include <Servo.h>
Servo myservo;// ESP8266WiFi.h library
const char* ssid     = "kaustav";
const char* password = "123456789";
const char* host = "api.thingspeak.com";
const char* writeAPIKey = "WEQMMI9YRZ36WV6O";
const int trigPin = 4;
const int echoPin = 5;
int IR=1;
WiFiClient client;
// defines variables
long duration;
int distance;
void setup() {
  myservo.attach(3);
  pinMode (IR,INPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(115200);
 WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println(".");
   
  }
  }



void loop() {
  digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
int a=digitalRead(IR);
if(a==0){
  myservo.write(60);
  delay(1000);
  myservo.write(0);
}
else{
  myservo.write(0);
  delay(1000);
  myservo.write(0);
}

WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    return;
  }

  String url = "/update?key=";
  url+=writeAPIKey;
  url+="&field1=";
  url+=String(distance);
  url+="&field2=";
  url+=String(a);
   
  url+="\r\n";
  //Serial.print("Temperature: ");
                            Serial.print(distance);
                            Serial.print(a);
                             Serial.print(" distance, Humidity: ");
                             
                             Serial.println("%. Send to Thingspeak.");
 
  // Request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Connection: close\r\n\r\n");
    delay(60000);
  // put your main code here, to run repeatedly:

  // put your main code here, to run repeatedly:

}