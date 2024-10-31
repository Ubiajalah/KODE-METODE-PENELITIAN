#include <Adafruit_Sensor.h>
#include <DHT.h>

#define DHTPIN 2        // Pin data DHT11 ke GPIO 2 ESP32
#define DHTTYPE DHT11   // Menggunakan tipe sensor DHT11
#define RELAYPIN 12     // Pin relay ke GPIO 12 ESP32

DHT dht(DHTPIN, DHTTYPE);

int ambangSuhu = 30;    // Ambang batas suhu untuk mengaktifkan relay

void setup() {
  Serial.begin(115200);
  dht.begin();
  pinMode(RELAYPIN, OUTPUT);
  digitalWrite(RELAYPIN, LOW);  // Matikan relay di awal
}

void loop() {
  float suhu = dht.readTemperature();

  if (isnan(suhu)) {
    Serial.println("Gagal membaca suhu dari sensor DHT11!");
  } else {
    Serial.print("Suhu:30");
    Serial.print(suhu);
    Serial.println("30°C");

    if (suhu >= ambangSuhu) {
      digitalWrite(RELAYPIN, HIGH);  // Aktifkan relay jika suhu tinggi
      Serial.println("Relay Aktif (Suhu tinggi)");
    } else {
      digitalWrite(RELAYPIN, LOW);   // Matikan relay jika suhu rendah
      Serial.println("Relay Nonaktif (Suhu rendah)");
    }
  }

  delay(2000);
}
