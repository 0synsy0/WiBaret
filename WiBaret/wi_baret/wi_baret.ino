#define BLYNK_PRINT Serial

/* Fill-in your Template ID (only if using Blynk.Cloud) */
//#define BLYNK_TEMPLATE_ID   "YourTemplateID"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "";
char pass[] = "";

const int LDR = A0;
int input_val = 0;
const int buzzer =  4;


void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  
  delay(1500);
  pinMode(buzzer, OUTPUT);
}

void loop()
{
  Blynk.run();
  input_val = analogRead(LDR);
  Serial.print("LDR value is : " );
  Serial.println(input_val);
  delay(50);


  if (input_val < 75) {
    digitalWrite(buzzer, HIGH);
    
  }
  else {
    Blynk.notify("Baret Çıkarıldı.");
    digitalWrite(buzzer, LOW);
    delay(200);
    digitalWrite(buzzer, HIGH);
    delay(200);
    digitalWrite(buzzer, LOW);
    delay(200);
    digitalWrite(buzzer, HIGH);
    delay(1250);
  }
}
