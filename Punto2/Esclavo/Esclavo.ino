void setup() {  
    Serial.begin(9600);           
    pinMode(13, OUTPUT);           
}

void loop() {  
    if (Serial.available() > 0) { 
        String mensaje = Serial.readString();  
        if (mensaje == "ON") {  
            digitalWrite(13, HIGH);        
        } else if (mensaje == "OFF") { 
            digitalWrite(13, LOW);            
        }
    }
}
