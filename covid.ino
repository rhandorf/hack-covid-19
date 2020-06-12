//USBtinyISP(ATTinyCore) upload using programmer
//Atinny841(Optiboot)
#include <avr/pgmspace.h>

const int ROW_1 = 10;     //LED row 1
const int ROW_2 = 9;     //LED row 2    
const int ROW_3 = 8;     //LED row 3
const int ROW_4 = 7;
const int ROW_5 = 3;

unsigned long next;

const static char spike[] PROGMEM  = "auguuuguuuuucuuguuuuauugccacuagucucuagucaguguguuaaucuuacaaccagaacucaauuacccccugcauacacuaauucuuucacacgugguguuuauuacccugacaaaguuuucagauccucaguuuuacauucaacucaggacuuguucuuaccuuucuuuuccaauguuacuugguuccaugcuauacaugucucugggaccaaugguacuaagagguuugauaacccuguccuaccauuuaaugaugguguuuauuuugcuuccacugagaagucuaacauaauaagaggcuggauuuuugguacuacuuuagauucgaagacccagucccuacuuauuguuaauaacgcuacuaauguuguuauuaaagucugugaauuucaauuuuguaaugauccauuuuuggguguuuauuaccacaaaaacaacaaaaguuggauggaaagugaguucagaguuuauucuagugcgaauaauugcacuuuugaauaugucucucagccuuuucuuauggaccuugaaggaaaacaggguaauuucaaaaaucuuagggaauuuguguuuaagaauauugaugguuauuuuaaaauauauucuaagcacacgccuauuaauuuagugcgugaucucccucaggguuuuucggcuuuagaaccauugguagauuugccaauagguauuaacaucacuagguuucaaacuuuacuugcuuuacauagaaguuauuugacuccuggugauucuucuucagguuggacagcuggugcugcagcuuauuauguggguuaucuucaaccuaggacuuuucuauuaaaauauaaugaaaauggaaccauuacagaugcuguagacugugcacuugacccucucucagaaacaaaguguacguugaaauccuucacuguagaaaaaggaaucuaucaaacuucuaacuuuagaguccaaccaacagaaucuauuguuagauuuccuaauauuacaaacuugugcccuuuuggugaaguuuuuaacgccaccagauuugcaucuguuuaugcuuggaacaggaagagaaucagcaacuguguugcugauuauucuguccuauauaauuccgcaucauuuuccacuuuuaaguguuauggagugucuccuacuaaauuaaaugaucucugcuuuacuaaugucuaugcagauucauuuguaauuagaggugaugaagucagacaaaucgcuccagggcaaacuggaaagauugcugauuauaauuauaaauuaccagaugauuuuacaggcugcguuauagcuuggaauucuaacaaucuugauucuaagguuggugguaauuauaauuaccuguauagauuguuuaggaagucuaaucucaaaccuuuugagagagauauuucaacugaaaucuaucaggccgguagcacaccuuguaaugguguugaagguuuuaauuguuacuuuccuuuacaaucauaugguuuccaacccacuaaugguguugguuaccaaccauacagaguaguaguacuuucuuuugaacuucuacaugcaccagcaacuguuuguggaccuaaaaagucuacuaauuugguuaaaaacaaaugugucaauuucaacuucaaugguuuaacaggcacagguguucuuacugagucuaacaaaaaguuucugccuuuccaacaauuuggcagagacauugcugacacuacugaugcuguccgugauccacagacacuugagauucuugacauuacaccauguucuuuugguggugucaguguuauaacaccaggaacaaauacuucuaaccagguugcuguucuuuaucaggauguuaacugcacagaagucccuguugcuauucaugcagaucaacuuacuccuacuuggcguguuuauucuacagguucuaauguuuuucaaacacgugcaggcuguuuaauaggggcugaacaugucaacaacucauaugagugugacauacccauuggugcagguauaugcgcuaguuaucagacucagacuaauucuccucggcgggcacguaguguagcuagucaauccaucauugccuacacuaugucacuuggugcagaaaauucaguugcuuacucuaauaacucuauugccauacccacaaauuuuacuauuaguguuaccacagaaauucuaccagugucuaugaccaagacaucaguagauuguacaauguacauuuguggugauucaacugaaugcagcaaucuuuuguugcaauauggcaguuuuuguacacaauuaaaccgugcuuuaacuggaauagcuguugaacaagacaaaaacacccaagaaguuuuugcacaagucaaacaaauuuacaaaacaccaccaauuaaagauuuuggugguuuuaauuuuucacaaauauuaccagauccaucaaaaccaagcaagaggucauuuauugaagaucuacuuuucaacaaagugacacuugcagaugcuggcuucaucaaacaauauggugauugccuuggugauauugcugcuagagaccucauuugugcacaaaaguuuaacggccuuacuguuuugccaccuuugcucacagaugaaaugauugcucaauacacuucugcacuguuagcggguacaaucacuucugguuggaccuuuggugcaggugcugcauuacaaauaccauuugcuaugcaaauggcuuauagguuuaaugguauuggaguuacacagaauguucucuaugagaaccaaaaauugauugccaaccaauuuaauagugcuauuggcaaaauucaagacucacuuucuuccacagcaagugcacuuggaaaacuucaagauguggucaaccaaaaugcacaagcuuuaaacacgcuuguuaaacaacuuagcuccaauuuuggugcaauuucaaguguuuuaaaugauauccuuucacgucuugacaaaguugaggcugaagugcaaauugauagguugaucacaggcagacuucaaaguuugcagacauaugugacucaacaauuaauuagagcugcagaaaucagagcuucugcuaaucuugcugcuacuaaaaugucagaguguguacuuggacaaucaaaaagaguugauuuuuguggaaagggcuaucaucuuauguccuucccucagucagcaccucaugguguagucuucuugcaugugacuuaugucccugcacaagaaaagaacuucacaacugcuccugccauuugucaugauggaaaagcacacuuuccucgugaaggugucuuuguuucaaauggcacacacugguuuguaacacaaaggaauuuuuaugaaccacaaaucauuacuacagacaacacauuugugucugguaacugugauguuguaauaggaauugucaacaacacaguuuaugauccuuugcaaccugaauuagacucauucaaggaggaguuagauaaauauuuuaagaaucauacaucaccagauguugauuuaggugacaucucuggcauuaaugcuucaguuguaaacauucaaaaagaaauugaccgccucaaugagguugccaagaauuuaaaugaaucucucaucgaucuccaagaacuuggaaaguaugagcaguauauaaaauggccaugguacauuuggcuagguuuuauagcuggcuugauugccauaguaauggugacaauuaugcuuugcuguaugaccaguugcuguaguugucucaagggcuguuguucuuguggauccugcugcaaauuugaugaagacgacucugagccagugcucaaaggagucaaauuacauuacacauaaacgaacuu\N";


//augc

// the setup function runs once when you press reset or power the board
void setup() {
  next = millis() + 5000;
}

// the loop function runs over and over again forever
void loop() {
  if (((signed long)(millis() - next)) > 0) {
    sparkle();
    spin();
    spin3();
    seq();
    turnoff();
    next = millis() + random(1000,5000);
  }
}

void turnoff() {
  pinMode(ROW_1, INPUT);
  pinMode(ROW_2, INPUT);
  pinMode(ROW_3, INPUT);
  pinMode(ROW_4, INPUT);
  pinMode(ROW_5, INPUT);
}

void sparkle() {
  turnoff();
  for (int i=0; i<5; i++) {
    led13();
    delay(15*i);
    led14();
    delay(15*i);
    //15 being wonky
    led15();
    delay(15*i);
    led16();
    delay(15*i);
    led17();
    delay(15*i);
    led18();
    delay(15*i);
  }
}

void seq() {
  //int i=0;
  char c;
  //while((c = pgm_read_byte(str++))) {
  for (int i=0; i<strlen_P(spike); i++) {
    c =  pgm_read_byte_near(spike + i);  
    if (c=='a') {
      led1();
      delay(1);
      led5();
      delay(1);
      led9();
      delay(1);
    }
    if (c=='u') {
      led2();
      delay(1);
      led6();
      delay(1);
      led10();
      delay(1);

    }
    if (c=='g') {
      led3();
      delay(1);
      led7();
      delay(1);
      led11();
      delay(1);
    }
    if (c=='c') {
      led4();
      delay(1);
      led8();
      delay(1);
      led12();
      delay(1);
    }
    delay(1);
  }
}

void spin() {
  for (int i=0; i<5; i++) {
    led1();
    delay(15*i);  
    led2();
    delay(15*i);
    led3();
    delay(15*i);
    led4();
    delay(15*i);
    led5();
    delay(15*i);
    led6();
    delay(15*i);
    led7();
    delay(15*i);  
    led8();
    delay(15*i);
    led9();
    delay(15*i);
    led10();
    delay(15*i);
    led11();
    delay(15*i);
    led12();
    delay(15*i);
  }
}

void spin3() {
  for (int i=0; i<10; i++) {
    for (int j=0; j<5; j++) {
      led1();
      delay(5);
      led4();
      delay(5);
      led7();
      delay(5);
      led10();
      delay(5);
    }
    delay(10*i);
    for (int j=0; j<5; j++) {
      led2();
      delay(5);
      led5();
      delay(5);
      led8();
      delay(5);
      led11();
      delay(5);
    }
    delay(10*i);
    for (int j=0; j<5; j++) {
      led3();
      delay(5);
      led6();
      delay(5);
      led9();
      delay(5);
      led12();
      delay(5);
    }
    delay(10*i);
  }
}

void led1() {
  turnoff();
  pinMode(ROW_1, OUTPUT);     //row 2
  digitalWrite(ROW_1, LOW);  
  pinMode(ROW_2, OUTPUT);     //row 3
  digitalWrite(ROW_2, HIGH);
}

void led2() {
  turnoff();
  pinMode(ROW_1, OUTPUT);     //row 2
  digitalWrite(ROW_1, HIGH);  
  pinMode(ROW_2, OUTPUT);     //row 3
  digitalWrite(ROW_2, LOW);
}

void led3() {
  turnoff();
  pinMode(ROW_2, OUTPUT);     //row 2
  digitalWrite(ROW_2, LOW);  
  pinMode(ROW_3, OUTPUT);     //row 3
  digitalWrite(ROW_3, HIGH);
}

void led4() {
  turnoff();
  pinMode(ROW_2, OUTPUT);     //row 2
  digitalWrite(ROW_2, HIGH);  
  pinMode(ROW_3, OUTPUT);     //row 3
  digitalWrite(ROW_3, LOW);
}

void led5() {
  turnoff();
  pinMode(ROW_3, OUTPUT);     //row 2
  digitalWrite(ROW_3, LOW);  
  pinMode(ROW_4, OUTPUT);     //row 3
  digitalWrite(ROW_4, HIGH);
}

void led6() {
  turnoff();
  pinMode(ROW_3, OUTPUT);     //row 2
  digitalWrite(ROW_3, HIGH);  
  pinMode(ROW_4, OUTPUT);     //row 3
  digitalWrite(ROW_4, LOW);
}

void led7() {
  turnoff();
  pinMode(ROW_4, OUTPUT);     //row 2
  digitalWrite(ROW_4, LOW);  
  pinMode(ROW_5, OUTPUT);     //row 3
  digitalWrite(ROW_5, HIGH);
}

void led8() {
  turnoff();
  pinMode(ROW_4, OUTPUT);     //row 2
  digitalWrite(ROW_4, HIGH);  
  pinMode(ROW_5, OUTPUT);     //row 3
  digitalWrite(ROW_5, LOW);
}

void led9() {
  turnoff();
  pinMode(ROW_1, OUTPUT);     //row 2
  digitalWrite(ROW_1, LOW);  
  pinMode(ROW_3, OUTPUT);     //row 3
  digitalWrite(ROW_3, HIGH);
}

void led10() {
  turnoff();
  pinMode(ROW_1, OUTPUT);     //row 2
  digitalWrite(ROW_1, HIGH);  
  pinMode(ROW_3, OUTPUT);     //row 3
  digitalWrite(ROW_3, LOW);
}

void led11() {
  turnoff();
  pinMode(ROW_2, OUTPUT);     //row 2
  digitalWrite(ROW_2, LOW);  
  pinMode(ROW_4, OUTPUT);     //row 3
  digitalWrite(ROW_4, HIGH);
}

void led12() {
  turnoff();
  pinMode(ROW_2, OUTPUT);     //row 2
  digitalWrite(ROW_2, HIGH);  
  pinMode(ROW_4, OUTPUT);     //row 3
  digitalWrite(ROW_4, LOW);
}

void led13() {
  turnoff();
  pinMode(ROW_3, OUTPUT);     //row 2
  digitalWrite(ROW_3, HIGH);  
  pinMode(ROW_5, OUTPUT);     //row 3
  digitalWrite(ROW_5, LOW);
}

void led14() {
  turnoff();
  pinMode(ROW_3, OUTPUT);     //row 2
  digitalWrite(ROW_3, LOW);  
  pinMode(ROW_5, OUTPUT);     //row 3
  digitalWrite(ROW_5, HIGH);
}

//here
void led15() {
  turnoff();
  pinMode(ROW_1, OUTPUT);     //row 2
  digitalWrite(ROW_1, LOW);  
  pinMode(ROW_4, OUTPUT);     //row 3
  digitalWrite(ROW_4, HIGH);
}

void led16() {
  turnoff();
  pinMode(ROW_1, OUTPUT);     //row 2
  digitalWrite(ROW_1, HIGH);  
  pinMode(ROW_4, OUTPUT);     //row 3
  digitalWrite(ROW_4, LOW);
}

void led17() {
  turnoff();
  pinMode(ROW_2, OUTPUT);     //row 2
  digitalWrite(ROW_2, LOW);  
  pinMode(ROW_5, OUTPUT);     //row 3
  digitalWrite(ROW_5, HIGH);
}

void led18() {
  turnoff();
  pinMode(ROW_2, OUTPUT);     //row 2
  digitalWrite(ROW_2, HIGH);  
  pinMode(ROW_5, OUTPUT);     //row 3
  digitalWrite(ROW_5, LOW);
}



