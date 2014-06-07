#define ROW0 2
#define ROW1 3
#define ROW2 4
#define ROW3 5

#define COL0 6
#define COL1 7
#define COL2 8
#define COL3 9

char m[4][4];

void setup(){
  pinMode(ROW0, OUTPUT);
  pinMode(ROW1, OUTPUT);
  pinMode(ROW2, OUTPUT);
  pinMode(ROW3, OUTPUT);
  digitalWrite(ROW0, HIGH);
  digitalWrite(ROW1, HIGH);
  digitalWrite(ROW2, HIGH);
  digitalWrite(ROW3, HIGH);
  
  pinMode(COL0, INPUT_PULLUP);
  pinMode(COL1, INPUT_PULLUP);
  pinMode(COL2, INPUT_PULLUP);
  pinMode(COL3, INPUT_PULLUP);
  
  int i;
  int j;
  
  for(i=0; i<4; i++){
    for(j=0; j<4; j++){
      m[i][j] = 0;
    }
  }
  
  Serial.begin(9600);
}

void loop(){
  char lins[] = {ROW0, ROW1, ROW2, ROW3};
  char cols[] = {COL0, COL1, COL2, COL3};

  // Ativaçao das linhas
  char i;
  char j;
  for (i=0; i < 4; i++) {  
    /*digitalWrite(ROW0, HIGH);
    digitalWrite(ROW1, HIGH);
    digitalWrite(ROW2, HIGH);
    digitalWrite(ROW3, HIGH);*/
    pinMode(ROW0, INPUT);
    pinMode(ROW1, INPUT);
    pinMode(ROW2, INPUT);
    pinMode(ROW3, INPUT);
    
    pinMode(lins[i], OUTPUT);
    digitalWrite(lins[i], LOW);
    for(j=0; j < 4; j++){
      m[i][j] = digitalRead(cols[j]);
    }
  }

  // Leitura do teclado
  for(i=0; i<4; i++){
    for(j=0; j<4; j++){
      Serial.print(getChar(i, j));
    }
    Serial.println();
  }
  Serial.println();
  delay(1000);
  
}


char getChar(int i, int j){
      if (!m[i][j]) {
          if (i==0 && j==0) return '1';
          if (i==0 && j==1) return '2';
          if (i==0 && j==2) return '3';
          if (i==0 && j==3) return 'A';
          if (i==1 && j==0) return '4';
          if (i==1 && j==1) return '5';
          if (i==1 && j==2) return '6';
          if (i==1 && j==3) return 'B';
          if (i==2 && j==0) return '7';
          if (i==2 && j==1) return '8';
          if (i==2 && j==2) return '9';
          if (i==2 && j==3) return 'C';
          if (i==3 && j==0) return '*';
          if (i==3 && j==1) return '0';
          if (i==3 && j==2) return '#';
          if (i==3 && j==3) return 'D';
      }
      return 'X';
}

