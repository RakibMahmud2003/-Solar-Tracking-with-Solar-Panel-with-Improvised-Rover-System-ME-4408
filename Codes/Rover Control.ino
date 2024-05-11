
char t;               

#define OUT1 8
#define OUT2 9
#define OUT3 7
#define OUT4 6
 
void setup() {
pinMode(OUT1,OUTPUT);   
pinMode(OUT2,OUTPUT);   
pinMode(OUT3,OUTPUT);   
pinMode(OUT4,OUTPUT); 
Serial.begin(9600);
 
}
 
void loop() {
if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}
 
if(t == 'F'){            
  digitalWrite(OUT1,HIGH);
  digitalWrite(OUT3,HIGH);
}
 
else if(t == 'B'){     
  digitalWrite(OUT2,HIGH);
  digitalWrite(OUT4,HIGH);

}
 
else if(t == 'R'){      
  digitalWrite(OUT3,HIGH);

}
 
else if(t == 'L'){     
  digitalWrite(OUT1,HIGH);

}
else if (t == 'I'){
  digitalWrite(OUT3,HIGH);
  digitalWrite(OUT2,HIGH);
}
else if(t == 'G'){
  digitalWrite(OUT4,HIGH);
  digitalWrite(OUT1,HIGH);
}
 
else if(t == 'S'){      
  digitalWrite(OUT1,LOW);
  digitalWrite(OUT2,LOW);
  digitalWrite(OUT3,LOW);
  digitalWrite(OUT4,LOW);
}

}
