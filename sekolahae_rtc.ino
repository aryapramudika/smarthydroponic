//ctbot
//---------------------------------------------------------------------
#include "CTBot.h";
CTBot myBot;
//bot telegram
String ssid = "XI TKJ 2 STI";
String pass = "a1b2c3d4";
//String ssid = "PRODIPTE";
//String pass = "0987654321";
//String ssid = "SSID2";
//String pass = "kmzwa8awaa";

String token = "1115994672:AAFvA4h6Gf09gqfDXREdES5G_t5W3MkgyV8";
const int groupID = -325706378;


//dht
//---------------------------------------------------------------------
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include "DHT.h"
#define DHTPIN  0
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
float t, h, a;
#define FIREBASE_HOST "smarthydroponic-ed50c.firebaseio.com"
#define FIREBASE_AUTH "6YRyQopAGTU4PrLpDt6O4m4qDYUtiWO1SWEsN5JR"
#define WIFI_SSID "XI TKJ 2 STI"
#define WIFI_PASSWORD "a1b2c3d4"
//#define WIFI_SSID "PRODIPTE"
//#define WIFI_PASSWORD "0987654321"
//#define WIFI_SSID "SSID2"
//#define WIFI_PASSWORD "kmzwa8awaa"


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




  int n = 0;
}

void loop() {
  //RTC
  //-----------------------------------------------------------------------
  DateTime now = rtc.now();       //Menampilkan RTC pada variable now

  Serial.print("Tanggal : ");
  Serial.print(now.day());        //Menampilkan Tanggal
  Serial.print("/");
  Serial.print(now.month());      //Menampilkan Bulan
  Serial.print("/");
  Serial.print(now.year());       //Menampilkan Tahun
  Serial.print(" ");

  Serial.print("Jam : ");
  Serial.print(now.hour());       //Menampilkan Jam
  Serial.print(":");
  Serial.print(now.minute());     //Menampilkan Menit
  Serial.print(":");
  Serial.print(now.second());     //Menampilkan Detik
  Serial.println();

  delay(1000);

  //RTC RELAY
  //---------------------------------------------------------------
  if (now.hour() == 1) {
    digitalWrite(pompa1, LOW);
    Firebase.setFloat("a", 1);
    digitalWrite(pompa2, HIGH);
    Firebase.setFloat("a", 4);
    digitalWrite(pukcir, LOW);
    Firebase.setFloat("a", 5);
    delay(5000);
    digitalWrite(pukcir, HIGH);
    Firebase.setFloat("a", 6);
    Serial.println("running 1");
  }
  else if (now.hour() == 7) {
    digitalWrite(pompa1, HIGH);
    Firebase.setFloat("a", 2);
    digitalWrite(pompa2, LOW);
    Firebase.setFloat("a", 3);
    digitalWrite(pukcir, LOW);
    Firebase.setFloat("a", 5);
    delay(5000);
    digitalWrite(pukcir, HIGH);
    Firebase.setFloat("a", 6);
    Serial.println("pompa 2 nyala");
    Serial.println("pukcir nyala");
  }

  //bot
  myBot.sendMessage(id, "Sawi akan panen 5 hari lagi, yuk buruan order :)");
}

if (now.hour() == 7) {
  digitalWrite(pompa1, LOW);
  Firebase.setFloat("a", 1);
  digitalWrite(pompa2, HIGH);
  Firebase.setFloat("a", 4);
  digitalWrite(pukcir, LOW);
  Firebase.setFloat("a", 5);
  delay(5000);
  digitalWrite(pukcir, HIGH);
  Firebase.setFloat("a", 6);
  Serial.println("running 1");
}


else if (now.hour() == 13) {
  digitalWrite(pompa1, HIGH);
  Firebase.setFloat("a", 2);
  digitalWrite(pompa2, LOW);
  Firebase.setFloat("a", 3);
  digitalWrite(pukcir, LOW);
  Firebase.setFloat("a", 5);
  delay(5000);
  digitalWrite(pukcir, HIGH);
  Firebase.setFloat("a", 6);
  Serial.println("pompa 2 nyala");
  Serial.println("pukcir nyala");
}
//bot
myBot.sendMessage(id, "Kangkung akan panen 5 hari lagi, yuk buruan order :)");

if (now.hour() == 13) {
  digitalWrite(pompa1, LOW);
  Firebase.setFloat("a", 1);
  digitalWrite(pompa2, HIGH);
  Firebase.setFloat("a", 4);
  digitalWrite(pukcir, LOW);
  Firebase.setFloat("a", 5);
  delay(5000);
  digitalWrite(pukcir, HIGH);
  Firebase.setFloat("a", 6);
  Serial.println("running 1");
}
else if (now.hour() == 19) {
  digitalWrite(pompa1, HIGH);
  Firebase.setFloat("a", 2);
  digitalWrite(pompa2, LOW);
  Firebase.setFloat("a", 3);
  digitalWrite(pukcir, LOW);
  Firebase.setFloat("a", 5);
  delay(5000);
  digitalWrite(pukcir, HIGH);
  Firebase.setFloat("a", 6);
  Serial.println("pompa 2 nyala");
  Serial.println("pukcir nyala");
}
//bot
myBot.sendMessage(id, "Pakcoy akan panen 5 hari lagi, yuk buruan order :)");


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
  Firebase.setFloat("a", 7);
}
else {
  digitalWrite(kipas, HIGH);
  Firebase.setFloat("a", 8);
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
