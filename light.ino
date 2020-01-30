#include <ESP8266WiFi.h>


const char* ssid="WIFI name";
const char* password = "WIFI PASSWORD";



int ledPin = 13;



void setup() {
  
  pinMode(ledPin,OUTPUT);
  digitalWrite(ledPin,LOW);



Serial.begin(115200);
  Serial.println();
  Serial.print("Wifi connecting to ");
  Serial.println( ssid );



WiFi.begin(ssid,password);



Serial.println();
  Serial.print("Connecting");



while( WiFi.status() != WL_CONNECTED ){
      delay(500);
      Serial.print(".");        
  }



digitalWrite( ledPin , HIGH);
  Serial.println();



Serial.println("Wifi Connected Success!");
  Serial.print("NodeMCU IP Address : ");
  Serial.println(WiFi.localIP() );



}



void loop() {
  // put your main code here, to run repeatedly:



}


Project Code 

/*
    This sketch demonstrates how to set up a simple HTTP-like server.
    The server will set a GPIO pin depending on the request over Android app.
       http://server_ip/gpio/0  will set the GPIO2 low,
       http://server_ip/gpio/0  will set the GPIO2 high
    server_ip is the IP address of the ESP8266 module, will be
    printed to Serial when the module is connected.
*/


/*project tutorial by ashraf minhaj  http://ashrafminhajfb.blogspot.com   */


#include <ESP8266WiFi.h>


const char* ssid = "WiFi name";
const char* password = "Password";


// Create an instance of the server
// specify the port to listen on as an argument
WiFiServer server(80);


void setup() {
  Serial.begin(115200);
  delay(10);


// prepare GPIO2
  pinMode(2, OUTPUT);
  digitalWrite(2, 0);


// Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);


WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);


while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");


// Start the server
  server.begin();
  Serial.println("Server started");


// Print the IP address
  Serial.println(WiFi.localIP());
}


void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }


// Wait until the client sends some data
  Serial.println("new client");
  while (!client.available()) {
    delay(1);
  }


// Read the first line of the request
  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();


// Match the request
  int val;
  if (req.indexOf("/gpio/0") != -1) {
    val = 0;
  } else if (req.indexOf("/gpio/1") != -1) {
    val = 1;
  } else {
    Serial.println("invalid request");
    client.stop();
    return;
  }


// Set GPIO2 according to the request
  digitalWrite(2, val);


client.flush();


// Prepare the response
  String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n\r\n\r\nGPIO is now ";
  s += (val) ? "high" : "low";
  s += "";


"\n";
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
