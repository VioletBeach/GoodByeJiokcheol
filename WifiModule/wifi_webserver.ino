#include <SPI.h>
#include "WizFi250.h"
#include "HX711.h"

char ssid[] = "jhzzang";            // your network SSID (name)
char pass[] = "11111111";        // your network password
int status = WL_IDLE_STATUS;
int jh=5; char value='0';
WiFiServer server(80);

// use a ring buffer to increase speed and reduce memory allocation
WizFiRingBuffer buf(50);

void sendHttpResponse(WiFiClient client);
void printWifiStatus();

void setup()
{
  Serial.begin(115200);   // initialize serial for debugging

  WiFi.init();

  // check for the presence of the shield
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    // don't continue
    while (true);
  }

  // attempt to connect to WiFi network
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to WPA SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network
    status = WiFi.begin(ssid, pass);
  }

  Serial.println("You're connected to the network");
  printWifiStatus();

  // start the web server on port 80
  server.begin();
   
}


void loop()
{
  WiFiClient client = server.available();  // listen for incoming clients
  if (client) {      
    Serial.println("New client");             // print a message out the serial port
    buf.init();                               // initialize the circular buffer
    while (client.connected()) {              // loop while the client's connected
      if (client.available()) {               // if there's bytes to read from the client,
        char c = (char)client.read();         // read a byte, then
        buf.push(c);                          // push it to the ring buffer

        // printing the stream to the serial monitor will slow down
        //Serial.write((char)c);

        // you got two newline characters in a row
        // that's the end of the HTTP request, so send a response
        if (buf.endsWith("\r\n\r\n")) {
          sendHttpResponse(client);
          break;
        }
      }
    }
    
    // close the connection
    client.stop();
    Serial.println("Client disconnected");
  }
}
void sendHttpResponse(WiFiClient client)
{
  while(Serial.available()){
  char data = Serial.read();
  Serial.print(data);
   if(data>=48&&data<=54){
    
value=data;
}}
  Serial.print((String)(char)value+"    value");
  client.println(F("HTTP/1.1 200 OK"));
  client.println(F("Content-type:text/html"));
  client.println();
  client.println(F("<!DOCTYPE HTML>"));
  client.println(F("<html>"));
  client.println(F("<meta charset='UTF-8'"));
  client.println(F("<head>"));
  client.println(F("<meta http-equiv='refresh' content='4'>"));
  client.println(F("<title>GOODBYE 지옥철</title>")); 
  client.println(F("<style>"));
  client.println(F("table,p{text-align:center; font-size:70px;}"));
  client.println(F("table,th,td{border:5px outset coral;border-collapse: collapse;margin:auto}"));
  client.println(F("td:nth-child(even){font-size:160px;padding:0;}"));
  client.println(F("</style>"));
  client.println(F("</head>"));
  client.println(F("<body style='background-color:gray;'>"));
  client.println(F("<br>"));
  client.println(F("<table style='width:90%'><caption><p><b><font color='black'>[<font color='white'>  Goodbye 지옥철 ♥  <font color='black'>]</b></p></Caption><br>"));
  client.println(F("<tr><th>호차</th><th>혼잡도</th></tr>"));
  client.println(F("<tr><td>"));
  client.println(F("<font color='yellow'>1호차</td><td><font color='yellow'>●●●○○"));
  
  client.println(F("</td></tr><tr><td>"));

  if(value=='6'){
  client.println(F("<font color='red'>2호차</td><td><font color='red'>●●●●●"));
  }
  else if(value=='5'||value=='4'){
  client.println(F("<font color='red'>2호차</td><td><font color='red'>●●●●○"));
  }
  else if(value>='3'){
    client.println(F("<font color='yellow'>2호차</td><td><font color='yellow'>●●●○○"));
    }
  else if(value=='2'){
     client.println(F("<font color='yellow'>2호차</td><td><font color='yellow'>●●○○○"));
    }
  else if(value=='1'){
    client.println(F("<font color='lime'>2호차</td><td><font color='lime'>●○○○○"));
    }
    else if(value=='0'){
    client.println(F("<font color='lime'>2호차</td><td><font color='lime'>○○○○○"));
    }
  client.println(F("</td></tr><tr><td><font color='red'>3호차</td>"));
  client.println(F("<td><font color='red'>●●●●●</td></tr></table>"));
  client.println(F("</body>"));
  client.println(F("</html>"));
}
void printWifiStatus()
{
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());
  IPAddress ip = WiFi.localIP();
  Serial.println(ip);
  Serial.println();
  Serial.println(ip);
  Serial.println();
}
