//ctbot
//---------------------------------------------------------------------
#include "CTBot.h";
CTBot myBot;
//bot telegram
String ssid = "XI TKJ 2 STI";
String pass = "";

String token = "1115994672:AAFvA4h6Gf09gqfDXREdES5G_t5W3Mkg";
const int groupID = -3660892;


//dht
//---------------------------------------------------------------------
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include "DHT.h"
#define DHTPIN  0
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
float t, h, a, b, c, d;
#define FIREBASE_HOST "smarthydroponic-ed50c.firebaseio.com"
#define FIREBASE_AUTH "O1SWEsN5JR"
#define WIFI_SSID "XI TKJ 2 STI"
#define WIFI_PASSWORD ""


//RELAY
//---------------------------------------------------------------------
#define pompa1   15
#define pompa2   13
#define kipas    12
#define pukcir   14



//RTC
//---------------------------------------------------------------------
#include <RTClib.h>
#include <Wire.h>
RTC_DS3231 rtc;
char r[32];




//----------------------------------------------------------------------

void setup() {
  Serial.begin(9600);
  dht.begin();
  Serial.println("Starting TelegramBot...");

  myBot.wifiConnect(ssid, pass);
  myBot.setTelegramToken(token);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  if (myBot.testConnection())
    Serial.println("\ntestConnection OK");
  else
    Serial.println("\ntestConnection NOK");

  Wire.begin(5, 4);   //Setting wire (5 untuk SDA dan 4 untuk SCL)
  rtc.begin();
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));


  pinMode(pompa1, OUTPUT);
  pinMode(pompa2, OUTPUT);
  pinMode(kipas, OUTPUT);
  pinMode(pukcir, OUTPUT);
  digitalWrite(pompa1, LOW);
  digitalWrite(pompa2, LOW);
  digitalWrite(kipas, LOW);
  digitalWrite(pukcir, LOW);

  myBot.sendMessage(groupID, "Selamat datang di Smart Hydroponic Technology di Desa.Morang, Kec. Kare, Kab. Madiun.");

  int n = 0;
}

void loop() {

  //Running 1
  //---------------------------------------------------------------

  digitalWrite(pompa1, LOW);
  Firebase.setFloat("a", 1);
  digitalWrite(pompa2, HIGH);
  Firebase.setFloat("b", 4);
  digitalWrite(pukcir, LOW);
  Firebase.setFloat("c", 5);
  delay(5000);

  //temp

  Firebase.setFloat("t", t);
  // handle error
  if (Firebase.failed()) {
    Serial.print("setting /t failed:");
    Serial.println(Firebase.error());
    return;
  }
  delay(100);

  // update value
  Firebase.setFloat("t", t);
  Firebase.setFloat("h", h);
  // handle error
  if (Firebase.failed()) {
    Serial.print("setting /h failed:");
    Serial.println(Firebase.error());
    return;
  }
  delay(100);
  // update value
  Firebase.setFloat("h", h);
  Firebase.setFloat("t", t);

  digitalWrite(pukcir, HIGH);
  Firebase.setFloat("c", 6);

  Serial.println("running 1");

  //bot
  delay(10000);
  myBot.sendMessage(groupID, "Sawi akan panen 5 hari lagi, yuk buruan order :)");


  //Running 2
  //---------------------------------------------------------------

  digitalWrite(pompa1, HIGH);
  Firebase.setFloat("a", 2);
  digitalWrite(pompa2, LOW);
  Firebase.setFloat("b", 3);
  digitalWrite(pukcir, LOW);
  Firebase.setFloat("c", 5);
  delay(5000);
  digitalWrite(pukcir, HIGH);
  Firebase.setFloat("c", 6);
  //temp

  Firebase.setFloat("t", t);
  // handle error
  if (Firebase.failed()) {
    Serial.print("setting /t failed:");
    Serial.println(Firebase.error());
    return;
  }
  delay(100);

  // update value
  Firebase.setFloat("t", t);
  Firebase.setFloat("h", h);
  // handle error
  if (Firebase.failed()) {
    Serial.print("setting /h failed:");
    Serial.println(Firebase.error());
    return;
  }
  delay(100);
  // update value
  Firebase.setFloat("h", h);
  Firebase.setFloat("t", t);

  digitalWrite(pukcir, HIGH);
  Firebase.setFloat("c", 6);

  Serial.println("pompa 2 nyala");
  Serial.println("pukcir nyala");
  Serial.println("running 2");

  delay(10000);

  //bot
  myBot.sendMessage(groupID, "Kangkung akan panen 5 hari lagi, yuk buruan order :)");


  //Running 3
  //---------------------------------------------------------------

  digitalWrite(pompa1, LOW);
  Firebase.setFloat("a", 1);
  digitalWrite(pompa2, HIGH);
  Firebase.setFloat("b", 4);
  digitalWrite(pukcir, LOW);
  Firebase.setFloat("c", 5);
  delay(5000);
  //temp

  Firebase.setFloat("t", t);
  // handle error
  if (Firebase.failed()) {
    Serial.print("setting /t failed:");
    Serial.println(Firebase.error());
    return;
  }
  delay(100);

  // update value
  Firebase.setFloat("t", t);
  Firebase.setFloat("h", h);
  // handle error
  if (Firebase.failed()) {
    Serial.print("setting /h failed:");
    Serial.println(Firebase.error());
    return;
  }
  delay(100);
  // update value
  Firebase.setFloat("h", h);
  Firebase.setFloat("t", t);

  digitalWrite(pukcir, HIGH);
  Firebase.setFloat("c", 6);

  digitalWrite(pukcir, HIGH);
  Firebase.setFloat("c", 6);
  Serial.println("running 3");
  delay(10000);

  //bot
  myBot.sendMessage(groupID, "Pakcoy akan panen 5 hari lagi, yuk buruan order :)");

 //Running 4
  //---------------------------------------------------------------

  digitalWrite(pompa1, LOW);
  Firebase.setFloat("a", 1);
  digitalWrite(pompa2, HIGH);
  Firebase.setFloat("b", 4);
  digitalWrite(pukcir, LOW);
  Firebase.setFloat("c", 5);
  delay(5000);

  //temp

  Firebase.setFloat("t", t);
  // handle error
  if (Firebase.failed()) {
    Serial.print("setting /t failed:");
    Serial.println(Firebase.error());
    return;
  }
  delay(100);

  // update value
  Firebase.setFloat("t", t);
  Firebase.setFloat("h", h);
  // handle error
  if (Firebase.failed()) {
    Serial.print("setting /h failed:");
    Serial.println(Firebase.error());
    return;
  }
  delay(100);
  // update value
  Firebase.setFloat("h", h);
  Firebase.setFloat("t", t);

  digitalWrite(pukcir, HIGH);
  Firebase.setFloat("c", 6);

  Serial.println("running 1");



  // SENSOR DHT
  // ---------------------------------------------------------- -
  h = dht.readHumidity();
  t = dht.readTemperature();
  if (isnan(h) || isnan(t))
  {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  if (t > 30) {
    digitalWrite(kipas, LOW);
    Firebase.setFloat("d", 7);
  }
  else {
    digitalWrite(kipas, HIGH);
    Firebase.setFloat("d", 8);
  }

  //FIREBASE
  //------------------------------------------------------------
  Firebase.setFloat("t", t);
  // handle error
  if (Firebase.failed()) {
    Serial.print("setting /t failed:");
    Serial.println(Firebase.error());
    return;
  }
  delay(100);

  // update value
  Firebase.setFloat("t", t);
  Firebase.setFloat("h", h);
  // handle error
  if (Firebase.failed()) {
    Serial.print("setting /h failed:");
    Serial.println(Firebase.error());
    return;
  }
  delay(100);
  // update value
  Firebase.setFloat("h", h);
  Firebase.setFloat("t", t);



  //TELEGRAM BOT
  // --------------------------------------------------------
  TBMessage group;
 if (myBot.getNewMessage(group)) {
     if (group.text.equalsIgnoreCase("order")) {
      myBot.sendMessage(groupID, "Untuk melakukan pemesanan Hubungi t.me/hidroponikmadiun \nAlamat: Jln. Raya Desa Nglandung, Kec.  Geger Kab. Madiun Kode Pos 63171");
      delay(500);
    }
    else if (group.text.equalsIgnoreCase("resep")) {
      myBot.sendMessage(groupID, "Daftar Resep Sayuran Hidroponik \n 1.Sawi \n 2.Pakcoy \n 3.Bayam \n 4.Kangkung");
      delay(500);
    }
    else if (group.text.equalsIgnoreCase("manfaat")) {
      myBot.sendMessage(groupID, "Manfaat Sayuran \n 1.Sawi \n https://doktersehat.com/manfaat-sawi/ \n 2.Pakcoy \n https://doktersehat.com/manfaat-pakcoy/ \n 3.Bayam \n https://doktersehat.com/manfaat-bayam/ \n 4.Kangkung \n https://doktersehat.com/manfat-kangkung-untuk-tubuh/");
      delay(500);
    }
    if (group.text.equalsIgnoreCase("sawi")) {
      myBot.sendMessage(groupID, "Silahkan Kunjungi: https://cookpad.com/id/cari/sawi");
      delay(500);
    }
    else if (group.text.equalsIgnoreCase("pakcoy")) {
      myBot.sendMessage(groupID, "Silahkan Kunjungi: https://cookpad.com/id/cari/pakcoy");
      delay(500);
    }

    if (group.text.equalsIgnoreCase("bayam")) {
      myBot.sendMessage(groupID, "Silahkan Kunjungi: https://cookpad.com/id/cari/bayam");
      delay(500);
    }
    else if (group.text.equalsIgnoreCase("kangkung")) {
      myBot.sendMessage(groupID, "Silahkan Kunjungi: https://cookpad.com/id/cari/kangkung");
      delay(500);
    }
  }
}
