#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
SoftwareSerial fromUNO(D4, D5); //Rx, Tx
String data;

////////////////Fill the below things only//////////////  
String ssid = "I_O";
String pass = "1.61803399";
String key = "bNfApMdg2Hj_rKeIHmglXZlAYZjSaJ5eHVEyanDG5hy";
String Event = "G_data";
////////////////////////////////////////////////////////

WiFiClient client;
      
String MakerIFTTT_Key ;
;String MakerIFTTT_Event;
char *append_str(char *here, String s) {  int i=0; while (*here++ = s[i]){i++;};return here-1;}
char *append_ul(char *here, unsigned long u) { char buf[20]; return append_str(here, ultoa(u, buf, 10));}
char post_rqst[256];char *p;char *content_length_here;char *json_start;int compi;
      
///////////////////////////////////////////////////////////////////////////////////

void setup()

{
   WiFi.disconnect();
  delay(3000);
  Serial.println("Connecting to ");
  Serial.print(ssid);
  WiFi.begin(ssid,pass);
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.print(".");
  }   
  Serial.println("Connected");
  Serial.println("IP: ");
  Serial.println((WiFi.localIP().toString()));

  
  Serial.begin(9600);
  fromUNO.begin(9600);
  
}


void loop()
{
  delay(300);
  if (fromUNO.available())
  {
     data = fromUNO.readStringUntil('\n');
     data.trim();
     String cpy=data;
     Serial.print(data);
     Serial.print('\n');
if (cpy != "leak"){
  
          if(client.connect("maker.ifttt.com",80)) {
      MakerIFTTT_Key = key;
      MakerIFTTT_Event = Event;
      p = post_rqst;
      p = append_str(p, "POST /trigger/");
      p = append_str(p, MakerIFTTT_Event);
      p = append_str(p, "/with/key/");
      p = append_str(p, MakerIFTTT_Key);
      p = append_str(p, " HTTP/1.1\r\n");
      p = append_str(p, "Host: maker.ifttt.com\r\n");
      p = append_str(p, "Content-Type: application/json\r\n");
      p = append_str(p, "Content-Length: ");
      content_length_here = p;
      p = append_str(p, "NN\r\n");
      p = append_str(p, "\r\n");
      json_start = p;
      p = append_str(p, "{\"value1\":\"");
      p = append_str(p, cpy);
      p = append_str(p, "\",\"value2\":\"");
      p = append_str(p, "No Leakage");
      p = append_str(p, "\"}");
      
      compi= strlen(json_start);
      content_length_here[0] = '0' + (compi/10);
      content_length_here[1] = '0' + (compi%10);
      client.print(post_rqst);
      Serial.print("data Send to google Sheet ");
      Serial.print(data);
      Serial.print("  ");
      Serial.println("No Leakage");
    }
    delay(3000);
    }

else{
    if(client.connect("maker.ifttt.com",80)) {
      MakerIFTTT_Key = key;
      MakerIFTTT_Event = Event;
      p = post_rqst;
      p = append_str(p, "POST /trigger/");
      p = append_str(p, MakerIFTTT_Event);
      p = append_str(p, "/with/key/");
      p = append_str(p, MakerIFTTT_Key);
      p = append_str(p, " HTTP/1.1\r\n");
      p = append_str(p, "Host: maker.ifttt.com\r\n");
      p = append_str(p, "Content-Type: application/json\r\n");
      p = append_str(p, "Content-Length: ");
      content_length_here = p;
      p = append_str(p, "NN\r\n");
      p = append_str(p, "\r\n");
      json_start = p;
      p = append_str(p, "{\"value1\":\"");
      p = append_str(p, cpy);
      p = append_str(p, "\",\"value2\":\"");
      p = append_str(p, "Leakage");
      p = append_str(p, "\"}");
      
      compi= strlen(json_start);
      content_length_here[0] = '0' + (compi/10);
      content_length_here[1] = '0' + (compi%10);
      client.print(post_rqst);
      Serial.print("data Send to google Sheet ");
      Serial.print(cpy);
      Serial.print("  ");
      Serial.println("Leakage");
    } 
    delay(3000);
}  
   
 }
  
}
