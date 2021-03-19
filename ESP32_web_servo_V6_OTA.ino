/*********
  Sketch based on Rui Santos at http://randomnerdtutorials.com
  HelTec Automation(TM) ESP32 Series Dev boards OLED draw UI test code by Aaron.Lee from HelTec AutoMation, https://github.com/HelTecAutomation/Heltec_ESP32  
  OTA code by Andreas Spiess
*********/

//Point your web browser to http://192.168.4.1
//WiFi AP
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>

//Servo
#include <Servo.h>

//OLED
#include <heltec.h>
#include "images.h"

//OTA
//#define ESP32_RTOS  // Uncomment this line if you want to use the code with freertos only on the ESP32.  Has to be done before including "OTA.h"
//
//#include "OTA.h"
//#include "credentials.h"
//uint32_t entry;

//Servo (Create servo objects, upto twelve servo objects can be created on most boards)
Servo servoH;
Servo servoV;


// GPIO the servo is attached to

static const int servoPinH = 2;    // pin 02 Horzontal pan
static const int servoPinV = 13;   // pin 13 Vertical tilt

// SSID and password for Soft AP
const char* ssid     = "Skull";
const char* password = "";

// Set web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;

// Decode HTTP GET value

String valueStringH = String(5);
String valueStringV = String(5);

int pos1 = 0;
int pos2 = 0;

// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0; 
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;


// Blink the builtin LED n times
void blink(int n)
{
  for(int i = 0; i < n; i++)
  {
    digitalWrite(25, LOW);    
    delay(250);                    
    digitalWrite(25, HIGH);  
    delay(250);
    digitalWrite(25, LOW);
  }
}

void setup() {
  Serial.begin(115200);

  // Enable OTA updates
//  setupOTA("ESPSkull", mySSID, myPASSWORD);


  // OLED splash screen
  Heltec.begin(true /*DisplayEnable Enable*/, false /*LoRa Disable*/, true /*Serial Enable*/);  //Start OLED
 
  Heltec.display->clear();
  Heltec.display->drawXbm(0, 0, Skull_width, Skull_height, Skull_bits);
  Heltec.display->setTextAlignment(TEXT_ALIGN_LEFT);
  Heltec.display->setFont(ArialMT_Plain_16);
  Heltec.display->drawStringMaxWidth(50, 20, 128, "WiFi skull controller");
  Heltec.display->display();
  delay(2000);
  Heltec.display->clear();
  Heltec.display->drawXbm(114, 0, WIFI_width, WIFI_height, WIFI_bits);  //WiFi icon
  Heltec.display->drawStringMaxWidth(0, 0, 128, "Connect to access point:");
  Heltec.display->drawStringMaxWidth(0, 40, 128, (ssid));
  Heltec.display->display();
  delay(4000);
  Heltec.display->clear();
  blink(5);
  Heltec.display->drawStringMaxWidth(20, 40, 128, "here we go...");
  Heltec.display->display();
  delay(3000);
  Heltec.display->clear();
   Heltec.display->setFont(ArialMT_Plain_24);
  Heltec.display->drawStringMaxWidth(20, 30, 128, "ready");
  Heltec.display->display();
  Heltec.display->clear();

//  myservo.attach(servoPin);  // attaches the servo on the servoPin to the servo object
  servoH.attach(servoPinH);
  servoV.attach(servoPinV);

// Connect to Wi-Fi network with SSID and password
  Serial.println("Connecting to ");
  Serial.println(ssid);
  
  WiFi.softAP(ssid);
  IPAddress IP = WiFi.softAPIP();
  Serial.println();
  Serial.println("AP IP Address: ");   // Print local IP address and start web server
  Serial.println(IP);
  server.begin();
  
  Serial.println("Server started");

}

void loop(){

//OTA
//  #ifdef defined(ESP32_RTOS) && defined(ESP32)
//#else // If you do not use FreeRTOS, you have to regulary call the handle method.
//  ArduinoOTA.handle();
//#endif


//Webserver  
  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    currentTime = millis();
    previousTime = currentTime;
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected() && currentTime - previousTime <= timeoutTime) { // loop while the client's connected
      currentTime = millis();
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
                                            // if the current line is blank, you got two newline characters in a row.
                                            // that's the end of the client HTTP request, so send a response:
       
  if (currentLine.length() == 0) {
     client.println("HTTP/1.1 200 OK");// HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK) and a content-type so the client knows what's coming, then a blank line:
     client.println("Content-type:text/html");
     client.println("Connection: close");
     client.println();

// Display the HTML web page
     client.println("<!DOCTYPE html><html>");
     client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
     client.println("<link rel=\"icon\" href=\"data:,\">");
    // CSS to style the on/off buttons. Feel free to change the background-color and font-size attributes to fit your preferences
     client.println("<style>body { text-align: center; font-family: \"Trebuchet MS\", Arial; margin-left:auto; margin-right:auto;}");
     client.println(".sliderH {  width: 50%;  height: 25px;  background: #d3d3d3;  outline: none;    opacity: 0.7;  -webkit-transition: .2s;  transition: opacity .2s;}");
     client.println(".sliderV {  position: absolute;  left: 30%;  top: 50%;  width: 50%;  height: 25px;  background: #d3d3d3;  outline: none;  transform: rotate(90deg);  opacity: 0.7;  -webkit-transition: .2s;  transition: opacity .2s;}</style>");
     client.println("<script src=\"https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js\"></script>");
    
                     
    // Web Page
     client.println("</head><body><h1>Electric Skull Positioner</h1>");
//     client.println("<p>Position: <span id=\"servoPos\"></span></p>");

    // Horizontal slider
     client.println("<input type=\"range\" min=\"0\" max=\"180\" class=\"sliderH\" id=\"servoSliderH\" onchange=\"servo(this.value)\" value=\""+valueStringH+"\"/>");

     client.println("<script>var sliderH = document.getElementById(\"servoSliderH\");");
     client.println("var servoPH = document.getElementById(\"servoPosH\"); servoPH.innerHTML = sliderH.value;");
     client.println("sliderH.oninput = function() { sliderH.value = this.value; servoPH.innerHTML = this.value; }");
     client.println("$.ajaxSetup({timeout:1000}); function servoH(pos) { ");
     client.println("$.get(\"/servoH/?value=\" + pos + \"&\"); {Connection: close};}</script>");

 // Vertical slider
     client.println("<input type=\"range\" min=\"0\" max=\"180\" class=\"sliderV\" id=\"servoSliderV\" onchange=\"servo(this.value)\" value=\""+valueStringV+"\"/>");   
       
     client.println("<script>var sliderV = document.getElementById(\"servoSliderV\");");
     client.println("var servoPV = document.getElementById(\"servoPosV\"); servoPV.innerHTML = sliderV.value;");
     client.println("sliderV.oninput = function() { sliderV.value = this.value; servoPV.innerHTML = this.value; }");
     client.println("$.ajaxSetup({timeout:1000}); function servoV(pos) { ");
     client.println("$.get(\"/servoV/?value=\" + pos + \"&\"); {Connection: close};}</script>");
       
//Original slider
     client.println("<script>var slider = document.getElementById(\"servoSlider\");");
     client.println("var servoP = document.getElementById(\"servoPos\"); servoP.innerHTML = slider.value;");
     client.println("slider.oninput = function() { slider.value = this.value; servoP.innerHTML = this.value; }");
     client.println("$.ajaxSetup({timeout:1000}); function servo(pos) { ");
     client.println("$.get(\"/?value=\" + pos + \"&\"); {Connection: close};}</script>");
       
   
     client.println("</body></html>");     

   //Horizontal Servo GET /?value=180& HTTP/1.1
     if(header.indexOf("GET /?value=")>=0) {
        pos1 = header.indexOf('=');
        pos2 = header.indexOf('&');
        valueStringH = header.substring(pos1+1, pos2);
              
   // Horizontal servo rotate
        servoH.write(valueStringH.toInt());
        Serial.println(valueStringH); 
   }         

   //Vertical Servo GET /?value=180& HTTP/1.1
     if(header.indexOf("GET /servoV/?value=")>=0) {
        pos1 = header.indexOf('=');
        pos2 = header.indexOf('&');
        valueStringV = header.substring(pos1+1, pos2);
              
   // Vertical servo rotate
        servoH.write(valueStringV.toInt());
        Serial.println(valueStringV); 
   }

//Realtime position display on OLED
     Heltec.display->clear();
     Heltec.display->setTextAlignment(TEXT_ALIGN_LEFT);
     Heltec.display->setFont(ArialMT_Plain_24);
     Heltec.display->drawString(0, 0, "H pos: "+String(valueStringH));
     Heltec.display->drawString(0,35, "V pos: "+String(valueStringV));
     blink(1);
     Heltec.display->display();
         
            
            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
