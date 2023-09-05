#define BLYNK_TEMPLATE_ID "TMPL3eByIUuaV" 
#define BLYNK_TEMPLATE_NAME "Lalithashree K" 
#define BLYNK_AUTH_TOKEN "iLqO4DkHbpV_e7AWzZVcLHDR3PfDpFTw"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h> 
#include <BlynkSimpleEsp8266.h>

#define tilt_in D8
#define fire_in D7
#define PIR_in  D6
#define vib_in  D5

const char* ssid = "vivo 1909";  // Enter SSID here
const char* pass = "Lalith@123";
char auth[] = BLYNK_AUTH_TOKEN;
BlynkTimer timer;


void Read_Send_Sensor()
{
  int tilt_value=digitalRead(tilt_in);
  int fire_value=digitalRead(fire_in);
  int PIR_value=digitalRead(PIR_in);
  int vib_value= digitalRead(vib_in);
  
  Blynk.virtualWrite(V0, tilt_value);
  Blynk.virtualWrite(V1, fire_value);
  Blynk.virtualWrite(V2, PIR_value);
  Blynk.virtualWrite(V3, vib_value);
}


void setup() 

{
  pinMode(tilt_in,INPUT);
  pinMode(fire_in,INPUT);
  pinMode(PIR_in,INPUT);
  pinMode(vib_in,INPUT);
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, Read_Send_Sensor);// put your setup code here, to run once:_
}

void loop() 

{
  Blynk.run();
  timer.run();// put your main code here, to run repeatedly:

}
