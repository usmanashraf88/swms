#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(13,12); // RX,TX 

String apiKey = "E1L0Y89CUJ49C3IO";     //  Enter your Write API key from ThingSpeak
String channelID = "1736185"; 
const char* ssid = "Ghost";
const char* pass = "Chintoo.1#";
const char* server = "api.thingspeak.com";

String txtMsg = ""; 
unsigned char msg1size=0,msg2size=0,msg3size=0,msg4size=0,msg5size=0,msg6size=0;
char msg1[15];
char msg2[15];
char msg3[15];
char msg4[15];
char msg5[15];
char msg6[15];

uint8_t x =0;
WiFiClient client;

//WiFiServer server(80);
 
void setup(){
  //Serial.begin(115200);
  Serial.begin(9600);
  mySerial.begin(9600);
  delay(10);
  // Connect to WiFi network
//  Serial.println();
//  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, pass);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
 // server.begin();
 // Serial.println("Server started");
 
  // Print the IP address
//  Serial.print("Use this URL to connect: ");
//  Serial.print("http://");
// Serial.print(WiFi.localIP());
//  Serial.println("/");
}
 
void loop() {
//Serial.print("test");
  serialEvent();
  
                         if (client.connect(server,80))   //   "184.106.153.149" or api.thingspeak.com
                      {  
                            
                             String postStr = apiKey;
                             postStr +="&field1=";
                             postStr += String(msg1);
                             postStr +="&field2=";
                             postStr += String(msg2);
                             postStr +="&field3=";
                             postStr += String(msg3);
                             postStr +="&field4=";
                             postStr += String(msg4);
                             postStr +="&field5=";
                             postStr += String(msg5);
                             postStr +="&field6=";
                             postStr += String(msg6);
                             
                             postStr += "\r\n\r\n";
 
                             client.print("POST /update HTTP/1.1\n");
                             client.print("Host: api.thingspeak.com\n");
                             client.print("Connection: close\n");
                             client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
                             client.print("Content-Type: application/x-www-form-urlencoded\n");
                             client.print("Content-Length: ");
                             client.print(postStr.length());
                             client.print("\n\n");
                             client.print(postStr);
 
                       //      Serial.print("AmbientC: ");
                       //      Serial.print(msg1);
                       //      Serial.print(" 'C, ObjectC: ");
                       //      Serial.print(msg2);
                       //      Serial.print("ECG: ");
                       //      Serial.print(msg3);
                         
                        //     Serial.print("Heart Rate: ");
                        //     Serial.print(msg3);
                        //     Serial.print(" BPM, Pulse Oximetr: ");
                        //     Serial.print(msg4);
                        //     Serial.println(" 'C Send to Thingspeak.");
                        }
          client.stop();
 
       //   Serial.println("Waiting...");
  
  // thingspeak needs minimum 15 sec delay between updates
  delay(1000);
}


void serialEvent() {
  //Serial.print("hope");
  uint8_t x;
  while (mySerial.available()) {
    char inChar = (char)mySerial.read();
    Serial.println (inChar);
    txtMsg += inChar;
 if (inChar == '\n' or inChar == '\r') {
 /*****************SETTING FOR MESSAGE 1******************************/
     if(txtMsg.charAt(0) == 'A' and txtMsg.charAt(1) == 'V'){masg1();}
  /**************************SETTING FOR MESSAGE 2 ******************************/
else if(txtMsg.charAt(0) == 'B' and txtMsg.charAt(1) == 'V'){masg2();}
  /**************************SETTING FOR MESSAGE 3 ******************************/
else if(txtMsg.charAt(0) == 'C' and txtMsg.charAt(1) == 'V'){masg3();}
  /**************************SETTING FOR MESSAGE 4 ******************************/
else if(txtMsg.charAt(0) == 'D' and txtMsg.charAt(1) == 'V'){masg4();}
  /**************************SETTING FOR MESSAGE 4 ******************************/
else if(txtMsg.charAt(0) == 'E' and txtMsg.charAt(1) == 'V'){masg5();}
  /**************************SETTING FOR MESSAGE 4 ******************************/
else if(txtMsg.charAt(0) == 'F' and txtMsg.charAt(1) == 'V'){masg6();}       
        ///////////////EMPTYIING THE BUFFER//////////////////////////
        txtMsg = "";
        mySerial.flush();
        }//END OF ONE LINE
    }//END OF SERIAL AVAILABLE
}

void masg1(){
msg1size = txtMsg.length()-2;
for(x =0;x<msg1size;x++){
msg1[x]= txtMsg.charAt(x+3);
}  
Serial.print("message 1 =");Serial.println(msg1);
}

void masg2(){
msg2size = txtMsg.length()-2;    
for(x =0;x<msg2size;x++){
msg2[x]= txtMsg.charAt(x+3);
}
Serial.print("message 2 =");Serial.println(msg2); 
}

void masg3(){
msg3size = txtMsg.length()-2;    
for(x =0;x<msg3size;x++){
msg3[x]= txtMsg.charAt(x+3);
}
Serial.print("message 3 =");Serial.println(msg3); 
}


void masg4(){
msg4size = txtMsg.length()-2;    
for(x =0;x<msg4size;x++){
msg4[x]= txtMsg.charAt(x+3);
}
Serial.print("message 4 =");Serial.println(msg4); 
}

void masg5(){
msg5size = txtMsg.length()-2;    
for(x =0;x<msg5size;x++){
msg5[x]= txtMsg.charAt(x+3);
}
Serial.print("message 5 =");Serial.println(msg5); 
}

void masg6(){
msg6size = txtMsg.length()-2;    
for(x =0;x<msg6size;x++){
msg6[x]= txtMsg.charAt(x+3);
}
Serial.print("message 6 =");Serial.println(msg6); 
}
