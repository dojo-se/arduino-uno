#define LEDVERDE    3
#define LEDAMARELO  5
#define LEDVERMELHO 6
#define SENSOR      7

#define LEDR 9
#define LEDG 10
#define LEDB 11

void setup(){
  pinMode(LEDVERDE, OUTPUT);
  pinMode(LEDAMARELO, OUTPUT);
  pinMode(LEDVERMELHO, OUTPUT);
  pinMode(LEDVERDE, OUTPUT);
  pinMode(LEDAMARELO, OUTPUT);
  pinMode(LEDVERMELHO, OUTPUT);
  
  pinMode(SENSOR, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop(){
  int t1;
  int t2;
  
  digitalWrite(LEDVERDE, HIGH);
  digitalWrite(LEDR, HIGH);
  
  t1 = millis();
  
  while(((millis() - t1) < 5000) && digitalRead(SENSOR));
  
      
    if(!digitalRead(SENSOR)){

        digitalWrite(LEDVERDE, LOW);
        digitalWrite(LEDR, LOW);
        digitalWrite(LEDAMARELO, HIGH);
        delay(2000);
        digitalWrite(LEDG, HIGH);
        delay(5000);
        digitalWrite(LEDAMARELO, LOW);
        digitalWrite(LEDG, LOW);
        digitalWrite(LEDB, HIGH);
        
        delay(2000);
        digitalWrite(LEDVERMELHO, HIGH);

        delay(5000);
        
        digitalWrite(LEDVERMELHO, LOW);
        digitalWrite(LEDB, LOW);
        
        Serial.println(digitalRead(SENSOR));
  }

}



