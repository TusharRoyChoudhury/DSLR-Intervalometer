//DIP Switch Intervalometer
//Modified By Tushar Jyoti Roy Choudhury
int DIP9 = 0;
int DIP10 = 0;
int DIP11 = 0;
int DIP12 = 0;
int DIP7 = 0;
int DIP6 = 0;
int DIP5 = 0;
int DIP4 = 0;
int A=0;
int B=0;
int C=0;
int D=0;
int E=0;
int F=0;
int G=0;
int H=0;
int I=0;
int J=0;
int K=0;
int L=0;
int M=0;
int N=0;

void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT); //Pin 3 triggers camera via opto-isolator
  pinMode(LED_BUILTIN, OUTPUT); //Output to LED for testing - optional

  pinMode(4, INPUT_PULLUP); //5 second input (pullups result in switch on = low)
  pinMode(5, INPUT_PULLUP); //10 second input
  pinMode(6, INPUT_PULLUP); //20 second input
  pinMode(7, INPUT_PULLUP); //30 second input
  pinMode(9, INPUT_PULLUP); //40 second input (pullups result in switch on = low)
  pinMode(10, INPUT_PULLUP); //50 second input
  pinMode(11, INPUT_PULLUP); //60 second input
  pinMode(12, INPUT_PULLUP); //90 second input
}

// the loop function runs over and over again forever
void loop() {
  DIP4 = digitalRead(4);
  DIP5 = digitalRead(5);
  DIP6 = digitalRead(6);
  DIP7 = digitalRead(7);
  DIP9 = digitalRead(9);
  DIP10 = digitalRead(10);
  DIP11 = digitalRead(11);
  DIP12 = digitalRead(12);
  
  Serial.println(DIP4);
  Serial.println(DIP5);
  Serial.println(DIP6);
  Serial.println(DIP7);
  Serial.println(DIP9);
  Serial.println(DIP10);
  Serial.println(DIP11);
  Serial.println(DIP12);

  if (DIP4 == LOW) {
    B=5;
  }
  else {
      B=0;
    }//5 second delay
  
  if (DIP5 == LOW) {
    C=10;
  }
  else {
      C=0;
    }//10 second delay

  if (DIP6 == LOW) {
    D=20;
  }
  else {
      D=0;
    }//20 second delay

  if (DIP7 == LOW) {
    E=30;
  }
  else {
      E=0;
    }//30 second delay
  
  if (DIP9 == LOW) {
    F=30;
    G=10;
  }
  else {
    F=0;
    G=0;
    }//40 second delay
  
  if (DIP10 == LOW) {
    H=30;
    I=20;
  }
    else {
    H=0;
    I=0;
  } //50 second delay

  if (DIP11 == LOW) {
    J=30;
    K=30;
  }
      else {
      J=0;
      K=0;
    } //60 second delay

  if (DIP12 == LOW) {
    L=30; 
    M=30;
    N=30;
  }
  else {
      L=0;
      M=0;
      N=0;
    }
     //90 second delay

  A=B+C+D+E+F+G+H+I+J+K+L+M+N;

if (DIP4 == LOW || DIP5 == LOW || DIP6 == LOW || DIP7 == LOW || DIP9 == LOW || DIP10 == LOW || DIP11 == LOW || DIP12 == LOW) {
    digitalWrite(3, HIGH);
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("trigger active");
    Serial.println(A);
    delay(B*1000);
    delay(C*1000);
    delay(D*1000);
    delay(E*1000);
    delay(F*1000);
    delay(G*1000);
    delay(H*1000);
    delay(I*1000);
    delay(J*1000);
    delay(K*1000);
    delay(L*1000);
    delay(M*1000);
    delay(N*1000);
digitalWrite(3, LOW);
digitalWrite(LED_BUILTIN, LOW);
delay(2100);
    }
}