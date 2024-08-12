int Q1=1;  
int Q2=2;
int Q3=3;
int Q4=4;
int i=0;

void setup() {
pinMode(Q1,OUTPUT);
pinMode(Q2,OUTPUT);
pinMode(Q3,OUTPUT);
pinMode(Q4,OUTPUT);
}

void loop() {
digitalWrite(Q4,LOW);
digitalWrite(Q3,LOW);
digitalWrite(Q2,LOW);
digitalWrite(Q1,LOW);
delay(500);

i++;

if((i % 2) > 0) { digitalWrite(Q1, HIGH); } 
  else { digitalWrite(Q1, LOW); }
if((i % 4) > 1) { digitalWrite(Q2, HIGH); } 
  else { digitalWrite(Q2, LOW); }
if((i % 8) > 3) { digitalWrite(Q3, HIGH); } 
  else { digitalWrite(Q3, LOW); }
if((i % 16) > 7) { digitalWrite(Q4, HIGH); } 
  else { digitalWrite(Q4, LOW); }
delay(500);

}