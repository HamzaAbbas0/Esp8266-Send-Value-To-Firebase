#include <ESP8266WiFi.h>                                                    // esp8266 library                                             // firebase library
#include <FirebaseESP8266.h>
#define FIREBASE_HOST "ledtest-8fdb3-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "JFwaxBUm9QmrNz7LZXH6YWzXGwOSIK2ACpQt8ypv"
#define WIFI_SSID "TP-Link_5F3A"
#define WIFI_PASSWORD "Balti@@1"

FirebaseConfig config;
FirebaseData firebaseData;
FirebaseJson json;
int val =0;
void setup() {
  Serial.begin(115200);
  Serial.println("esp8266 serial initialize");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();
  Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
  delay(1000);

}
void loop() {
  
if  (Firebase.setInt(firebaseData,"/leddata","/DHT11", val)){
  Serial.println("value upload successfully");
  Serial.print("Val = ");
  Serial.println(val);
  delay(1000);
  val ++ ;
  delay(1000); 
}  
  }
