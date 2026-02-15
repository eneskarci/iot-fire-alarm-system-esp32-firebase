#include <DHT.h>
#include <WiFi.h>
#include <IOXhop_FirebaseESP32.h>
#include <Wire.h>

DHT dht(19, DHT11);

#define BUZZER 17
#define PIR 15
#define LED 4
#define Wifi_id "ENESNET"
#define Wifi_Pw "123321aaa"
#define FIREBASE "https://alerting-system-for-muhtas-default-rtdb.europe-west1.firebasedatabase.app/"
#define FIREBASE_TOKEN "C5NAUHFuYNVzRRa4mVOobMUjcZdQPQuZKhQngcFc"

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(BUZZER, OUTPUT);
  pinMode(PIR, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  WiFi.begin(Wifi_id, Wifi_Pw);
  Firebase.begin(FIREBASE, FIREBASE_TOKEN);
}

void loop() {
  int alarm = 0;
  float sicaklik, nem, ates;
  bool pir;

  readSensorData(sicaklik, nem, ates, pir);

  if (sicaklik >= 0) {
    Serial.println("\nOdanızın sıcaklığı normal değerin üzerindedir.");

    if (ates >= 0) {
      Serial.println("Odada alev algılandı.");

      if (pir == HIGH) {
        digitalWrite(LED, HIGH);
        Serial.println("Odanızda yangın alarm sistemi devreye girdi.");
        alarm = 1;
        activateBuzzer();
      } else {
        digitalWrite(LED, LOW);
        alarm = 0;
      }
    }
  }

  updateFirebaseData(nem, sicaklik, ates, alarm);
}

void readSensorData(float &sicaklik, float &nem, float &ates, bool &pir) {
  sicaklik = dht.readTemperature();
  nem = dht.readHumidity();
  ates = analogRead(A0);
  pir = digitalRead(PIR);

  ates = map(ates, 0.0, 1023.0, 0.0, 25.0);
  ates = 100 - ates;

  Serial.print("\nSıcaklık=");
  Serial.print(sicaklik);
  Serial.print("\nNem=");
  Serial.print(nem);
  Serial.print("\nAteş=");
  Serial.print(ates);
  Serial.print("\nSensör=");
  Serial.print(pir);

  delay(300);
}

void activateBuzzer() {
  digitalWrite(BUZZER, HIGH);
  delay(300);
  digitalWrite(BUZZER, LOW);
  delay(300);
}

void updateFirebaseData(float nem, float sicaklik, float ates, int alarm) {
  Firebase.setFloat("Sensor_Verileri/DHT11/Nem", nem);
  Firebase.setFloat("Sensor_Verileri/DHT11/Sicaklik", sicaklik);
  Firebase.setFloat("Sensor_Verileri/Fire/Ates", ates);
  Firebase.setBool("Sensor_Verileri/PIR/Hareket", alarm);
}
