int A=1;  
int AandB=2;
int B=3;
int C=4;
int CorD=5;
int D=6;
int E=7;
int notE=8;
bool StateA=0;
bool StateB=0;
bool StateC=0;
bool StateD=0;
bool StateE=0;

void setup() {
  pinMode(A, INPUT);
  pinMode(AandB,OUTPUT);
  pinMode(B,INPUT);
  pinMode(C, INPUT);
  pinMode(CorD,OUTPUT);
  pinMode(D,INPUT);
  pinMode(E, INPUT);
  pinMode(notE,OUTPUT);
}

void loop() {
  StateA = digitalRead(A);
  StateB = digitalRead(B);
  StateC = digitalRead(C);
  StateD = digitalRead(D);
  StateE = digitalRead(E);
  delay(500);

  // AND program :
  digitalWrite(AandB, StateA & StateB); 
  
  // OR program :
  digitalWrite(CorD, StateC || StateD); 
  
  // NOT program :
  digitalWrite(notE, !StateE);

delay(500);

}