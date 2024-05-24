
//motor receiver code 

#include <esp_now.h>
#include <WiFi.h>

int enA = 18;
int in1 = 15;
int in2 = 2;

int enB = 25;
int in3 = 4;
int in4 = 5;

// Structure example to receive data
// Must match the sender structure
typedef struct struct_message {
    float e;
    float f;
    float g;

} struct_message;

// Create a struct_message called myData
struct_message myData;

// callback function that will be executed when data is received
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&myData, incomingData, sizeof(myData));
  analogWrite(enA, 255);
  analogWrite(enB, 255);
  Serial.print("X: ");
  Serial.println(myData.e);

  Serial.print("Y: ");
  Serial.println(myData.f);

  Serial.print("Z: ");
  Serial.println(myData.g);

  if (0.60<myData.g&&myData.g<0.95){
   Serial.print("Forward");
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }

  else if (0.80<myData.f&&myData.f<0.99){
     Serial.print("Right");
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }

  else if (0.70<myData.e&&myData.e<1.01){
    Serial.print("Backward");
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }
  else if (0.10<myData.e&&myData.e<0.21){
    Serial.print("Left");
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
    else {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    }


  Serial.println();
}
 
void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  
  // Once ESPNow is successfully Init, we will register for recv CB to
  // get recv packer info
  esp_now_register_recv_cb(OnDataRecv);
}
 
void loop() {

}
