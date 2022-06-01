#include <SPI.h>
#include <Ethernet.h>

EthernetServer server(23);
  
void setup() {
  Serial.begin(9600);
  IPAddress ip(192, 168, 1, 10);
  IPAddress gateway(192, 168, 1, 1);
  IPAddress dns(192, 168, 1, 1);
  IPAddress subnet(255, 255, 255, 0);
  
  byte mac[] = { 0x90, 0xa2, 0xda, 0x0e, 0x98, 0x34 };
  Ethernet.begin(mac, ip, gateway, dns, subnet);
  Serial.print("The server IP address is: ");
  Serial.println(Ethernet.localIP());
  server.begin();
}

void loop() {
  char incoming;
  EthernetClient client = server.available();
  if(client)
  {
    Serial.println("Client connected");
    while(client.connected()){
      if(client.available()) {
        incoming = client.read();
        Serial.print(incoming);
        client.print(incoming);
      }
    }
    Serial.println("Client disconnected");
  }
}
