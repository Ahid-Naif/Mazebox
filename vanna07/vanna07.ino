#include <OneWire.h>


#define start_but 34
#define stop_but 36


#define lock_door 23
#define motor_sliv 2
#define lock_hand 25
#define lock_potolok 27

#define akt_molot_up 51
#define akt_molot_down 53

#define lock_fish 29
#define led_mirror 3
#define led_mirror_lamp 4
#define lock_racovina 31
#define lock_tainic_vent 33

#define aktivator 5
#define strob 6
#define vent_on 49
#define light_lok 47
#define lock_button 35

//---------

#define pir_sensor A11
#define reed1 40
#define reed2 42
#define reed3 44
#define reed4 46

#define reed5 48
#define hall1 A0
#define hall2 A1
#define vent_foto1 A2
#define vent_foto2 A3
#define vent_foto3 A4

#define reed_molot A5
#define reed_open A6
#define water_leavle 50
#define shock_sensor A7
#define instrument A8
#define button_stop A9 


OneWire ds1(22);// Определяем пин подключения к ключу
OneWire ds2(24);
OneWire ds3(26);
OneWire ds4(28);
OneWire ds5(30);

int flag_aqua = 0;


byte addr[8]; // Обозначаем массив из 8 байт
int good = 0;
int bad = 0;

long d1 = 0;
long d2 = 0;
long d3 = 0;
long d4 = 0;

int debug = 0;
int count1 = 0;
int count2 = 0;
int count3 = 0;

int flag_kuv = 1;

int incomingByte = 0;
int Step = 0;

int count = 0;

int break_flag = 0;

int flag1 = 0;
int flag2 = 0;
int flag3 = 0;
int flag4 = 0;
int flag5 = 0;

int summ = 0;

int mass[4] = {1, 5, 3, 4};
int temp_mass[4] = {0, 0, 0, 0};



int mass_led[20] = {1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0};
long int time_mass[5] = {0, 0, 0, 0, 0};
long int pause = 900;
long int timers = 0;
int count_led = 0;
int flag_on = 0;
int count_error = 0;
int good_flag[5] = {0, 0, 0, 0, 0};
long int time_akt_door = 0;

int flag_button = 0;

byte addr_rom1[2][8] = {{1, 19, 11, 18, 0, 93, 0, 142},
                        {1, 242, 279, 197, 90, 93, 9, 190}};

byte addr_rom2[3][8] = {{1, 221, 9, 58, 0, 131, 0, 105},
                        {17, 2, 22, 0, 10, 90, 1, 150},
                        {1, 170, 239, 55, 0, 12, 0, 32}};

byte addr_rom3[2][8] = {{1, 240, 27, 17, 0, 93, 0, 10},
                        {1, 100, 19, 59, 10, 92, 0, 88}};

byte addr_rom4[2][8] = {{1, 71, 142, 17, 0, 93, 0, 237},
                        {1, 45, 254, 30, 0, 92, 0, 38}};

byte addr_rom5[2][8] = {{1, 186, 10, 58, 0, 131, 0, 97},
                        {1, 145, 148, 30, 0, 90, 0, 86}};


void setup() {

    for (int i = 34; i < 53; i += 2) {
    pinMode(i, INPUT_PULLUP);
  }
  for (int i = 23; i < 54; i += 2) {
    pinMode(i, OUTPUT);
    digitalWrite(i, 0);
  }
  for (int i = 2; i < 14; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, 0);
  }
  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
  pinMode(A2, INPUT_PULLUP);
  pinMode(A3, INPUT_PULLUP);
  pinMode(A4, INPUT_PULLUP);
  pinMode(A5, INPUT_PULLUP);
  pinMode(A6, INPUT_PULLUP);
  pinMode(A7, INPUT_PULLUP);
  pinMode(A8, INPUT_PULLUP);
  pinMode(A9, INPUT_PULLUP);
  pinMode(A10, INPUT_PULLUP);
  pinMode(A11, INPUT_PULLUP);
  pinMode(A12, INPUT_PULLUP);
  pinMode(A13, INPUT_PULLUP);
  pinMode(A14, INPUT_PULLUP);
  pinMode(A15, INPUT_PULLUP);


  Serial.begin(9600);
  
}

void loop() {

  //Serial.println(analogRead(A8));


  if(flag_kuv == 1) {
    if(!digitalRead(reed_open)) {
      delay(100);
      if(!digitalRead(reed_open)) {
        delay(500);
          flag_kuv = 0;
        digitalWrite(akt_molot_up, 0);
        digitalWrite(akt_molot_down, 1);
        delay(700);
        digitalWrite(akt_molot_up, 0);
        digitalWrite(akt_molot_down, 0);
      }
    }
  }
  if (Step == 0) {
    if (!digitalRead(start_but)) {
      delay(100);
      if (!digitalRead(start_but)) Start_Q();
    }
  }
  if (!digitalRead(stop_but)) {
    delay(100);
    if (!digitalRead(stop_but)) {
      Stop_Q();
      delay(5000);
        smartdelay(10000);
        if(break_flag == 0) Clear_Q();
    }
  }
//--------------

  if (Serial.available() > 0)
  {

    incomingByte = Serial.read();
    while (Serial.available()) Serial.read();
    switch (incomingByte)
    {

      case '8':
       Start_Q();
      break;

      case '9':
      if(Step != 0) {
       Serial.println("Aoff");
        }
        Stop_Q();
       break;
      
       case '0':
        Clear_Q();
       break;
      //---------

case 'B':
       goto B_fun;
      break;

      case 'D':
       goto D_fun;
      break;

      case 'I':
       goto I_fun;
      break;

      case 'J':
       goto J_fun;
      break;

      case 'F':
       goto F_fun;
      break;

      case 'K':
       goto K_fun;
      break;

      case 'L':
       goto L_fun;
      break;

      case 'M':
       goto M_fun;
      break;

      case 'N':
       goto N_fun;
      break;

      case 'O':
       goto O_fun;
      break;

      case 'Z':
       goto Z_fun;
      break;

      //----------
      case '1':
        if(digitalRead(lock_door)) {
          Serial.println("1on");
          digitalWrite(lock_door, 0);
        }
        else {
          Serial.println("1off");
          digitalWrite(lock_door, 1);
        }
       break;

        case '2':
        if(digitalRead(light_lok)) {
          Serial.println("2off");
          digitalWrite(light_lok, 0);
        }
        else {
          Serial.println("2on");
          digitalWrite(light_lok, 1);
        }
       break;


        case '4':
        if(digitalRead(vent_on)) {
          Serial.println("4off");
          digitalWrite(vent_on, 0);
        }
        else {
          Serial.println("4on");
          digitalWrite(vent_on, 1);
        }
       break;

//       case 'N':
//        goto N_fun;
//       break;
        
    }
  

    while (Serial.available()) Serial.read();
  }//--end-serial
  
if(Step == 1) {
if(analogRead(pir_sensor) < 800) {
  B_fun:
    count = 2000;
    if(!digitalRead(motor_sliv)) {
      digitalWrite(motor_sliv, 1);
      Serial.println("Bon");
    }
}
if(count > 0) { count--; delay(1); }
if(count < 3) {
  if(digitalRead(motor_sliv)) {
     digitalWrite(motor_sliv, 0);
      Serial.println("Boff");
  }
}
//  
//  if(count < 3) {
//    Serial.println("Bon"); 
//    digitalWrite(motor_sliv, 1);
//  }
//  count = 3000;
//}
//if(count > -1)  {
//  count--; 
//  if(count == 0) 
//  {
//    Serial.println("Boff");
//    delay(1); 
//    //digitalWrite(motor_sliv, 1);
//    }
//}
//if(count < 0) digitalWrite(motor_sliv, 0);


if(flag_button == 0) {
  if(!digitalRead(reed1)) {
    temp_mass[0] = temp_mass[1];
    temp_mass[1] = temp_mass[2];
    temp_mass[2] = temp_mass[3];
    temp_mass[3] = 1;
    flag_button = 1;
    count_error++;
  }

  if(!digitalRead(reed2)) {
    temp_mass[0] = temp_mass[1];
    temp_mass[1] = temp_mass[2];
    temp_mass[2] = temp_mass[3];
    temp_mass[3] = 2;
    flag_button = 1;
    count_error++;
  }

  if(!digitalRead(reed3)) {
    temp_mass[0] = temp_mass[1];
    temp_mass[1] = temp_mass[2];
    temp_mass[2] = temp_mass[3];
    temp_mass[3] = 3;
    flag_button = 1;
    count_error++;
  }

  if(!digitalRead(reed4)) {
    temp_mass[0] = temp_mass[1];
    temp_mass[1] = temp_mass[2];
    temp_mass[2] = temp_mass[3];
    temp_mass[3] = 4;
    flag_button = 1;
    count_error++;
  }

  if(!digitalRead(reed5)) {
    temp_mass[0] = temp_mass[1];
    temp_mass[1] = temp_mass[2];
    temp_mass[2] = temp_mass[3];
    temp_mass[3] = 5;
    flag_button = 1;
    count_error++;
  }
}

if(flag_button == 1) {
  if(digitalRead(reed1) && digitalRead(reed2) && digitalRead(reed3) && digitalRead(reed4) && digitalRead(reed5)) {
    summ = 0;
        for(int i = 0; i < 4; i++) {
          if(temp_mass[i] == mass[i]) summ++;
        }
    if(summ == 4) {
      D_fun:
      Serial.println("Don");
      digitalWrite(lock_potolok, 0);
        delay(300);
      digitalWrite(lock_hand, 0);
      Step = 2;
      digitalWrite(motor_sliv, 0);
      Serial.println("Boff");
    }
    else if(count_error == 12) {
      Serial.println("Eon");
      count_error = 0;
    }
    flag_button = 0;
  }
  
}
 

//---------  
}//end step1



if(Step == 2) {
  if(!digitalRead(reed_molot)) {
    delay(300);
    if(!digitalRead(reed_molot)) {
      delay(200);
      if(!digitalRead(reed_molot)) {
    F_fun:
    Serial.println("Fon");
    digitalWrite(light_lok, 0);
    Serial.println("2off");
        digitalWrite(akt_molot_up, 1);
        digitalWrite(akt_molot_down, 0);
        delay(700);
        digitalWrite(akt_molot_up, 0);
        digitalWrite(akt_molot_down, 0);
    digitalWrite(aktivator, 1);
      delay(300);
    digitalWrite(aktivator, 0);
      delay(500);
if(!digitalRead(reed_open)) {
      for(int i = 0; i < 10; i++) {
         digitalWrite(akt_molot_up, 1);
         digitalWrite(akt_molot_down, 0);
          delay(300 + i*10) ;
         digitalWrite(akt_molot_up, 0);
         digitalWrite(akt_molot_down, 0);
          delay(500);
          if(i == 2) Serial.println("Hon");
          if(digitalRead(reed_open)) i = 11;
                 }
      }
      Serial.println("Gon");
      delay(6000);
            digitalWrite(light_lok, 1);
            Serial.println("2on");
            
Step = 4;
  }
    }
  }
}

if((Step == 2) || (Step == 3) || (Step == 4) || (Step == 5) || (Step == 6))  {
  if(flag_aqua == 0) {
   
  if(!digitalRead(water_leavle)) {
    delay(100);
    if(!digitalRead(water_leavle)) {
      delay(300);
      if(!digitalRead(water_leavle)) {
        delay(300);
        if(!digitalRead(water_leavle)) {
          delay(300);
          if(!digitalRead(water_leavle)) {
          delay(300);
          if(!digitalRead(water_leavle)) {
          delay(500);
          if(!digitalRead(water_leavle)) {
          delay(500);
          if(!digitalRead(water_leavle)) {
      I_fun:
      Serial.println("Ion");
      digitalWrite(lock_fish, 0);
        delay(500);
      digitalWrite(lock_fish, 1);
      flag_aqua = 1;
    }
  }
}
          }
        }
      }
    }
  }
}
}

if(Step == 4) {
for(int i = 0; i < 5; i++) {
 good_flag[i] = 0;
 }

count1 = 0;
count2 = 0;
count3 = 0;

if (ds1.search(addr))
    {
if(debug)       Serial.print("ROM1 = ");
    for(int i = 0; i < 8; i++)
    {
      if(addr_rom1[0][i] == addr[i]) count1++;
      if(addr_rom1[1][i] == addr[i]) count2++;
                                   if(debug)    Serial.print(addr[i]);// Печатаем нужный байт в шестнадцатиричном виде
                                   if(debug)    Serial.print(", ");
    }
    
   
  if(debug) Serial.println();// В конце цикла переводим строку
  if(debug) Serial.print(count1);
  if(debug) Serial.println(count2);
  if(count1 == 8 || count2 == 8) good_flag[0] = 1;
  else good_flag[0] = 0;
ds1.reset_search();
}


count1 = 0;
count2 = 0;
count3 = 0;

if (ds2.search(addr))
    {
if(debug)       Serial.print("ROM2 = ");
    for(int i = 0; i < 8; i++)
    {
      if(addr_rom2[0][i] == addr[i]) count1++;
      if(addr_rom2[1][i] == addr[i]) count2++;
                                   if(debug)    Serial.print(addr[i]);// Печатаем нужный байт в шестнадцатиричном виде
                                   if(debug)    Serial.print(", ");
    }
    
   
  if(debug) Serial.println();// В конце цикла переводим строку
  if(debug) Serial.print(count1);
  if(debug) Serial.println(count2);
  if(count1 == 8 || count2 == 8) good_flag[1] = 1;
  else good_flag[1] = 0;
ds2.reset_search();
}


count1 = 0;
count2 = 0;
count3 = 0;

if (ds3.search(addr))
    {
if(debug)       Serial.print("ROM3 = ");
    for(int i = 0; i < 8; i++)
    {
      if(addr_rom3[0][i] == addr[i]) count1++;
      if(addr_rom3[1][i] == addr[i]) count2++;
                                   if(debug)    Serial.print(addr[i]);// Печатаем нужный байт в шестнадцатиричном виде
                                   if(debug)    Serial.print(", ");
    }
    
   
  if(debug) Serial.println();// В конце цикла переводим строку
  if(debug) Serial.print(count1);
  if(debug) Serial.println(count2);
  if(count1 == 8 || count2 == 8) good_flag[2] = 1;
  else good_flag[2] = 0;
ds3.reset_search();
}


count1 = 0;
count2 = 0;
count3 = 0;

if (ds4.search(addr))
    {
if(debug)       Serial.print("ROM4 = ");
    for(int i = 0; i < 8; i++)
    {
      if(addr_rom4[0][i] == addr[i]) count1++;
      if(addr_rom4[1][i] == addr[i]) count2++;
                                   if(debug)    Serial.print(addr[i]);// Печатаем нужный байт в шестнадцатиричном виде
                                   if(debug)    Serial.print(", ");
    }
    
   
  if(debug) Serial.println();// В конце цикла переводим строку
  if(debug) Serial.print(count1);
  if(debug) Serial.println(count2);
  if(count1 == 8 || count2 == 8) good_flag[3] = 1;
  else good_flag[3] = 0;
ds4.reset_search();
    }
    
count1 = 0;
count2 = 0;
count3 = 0;

    if (ds5.search(addr))
    {
if(debug)       Serial.print("ROM5 = ");
    for(int i = 0; i < 8; i++)
    {
      if(addr_rom5[0][i] == addr[i]) count1++;
      if(addr_rom5[1][i] == addr[i]) count2++;
                                   if(debug)    Serial.print(addr[i]);// Печатаем нужный байт в шестнадцатиричном виде
                                   if(debug)    Serial.print(", ");
    }
    
   
  if(debug) Serial.println();// В конце цикла переводим строку
  if(debug) Serial.print(count1);
  if(debug) Serial.println(count2);
  if(count1 == 8 || count2 == 8) good_flag[4] = 1;
  else good_flag[4] = 0;
ds5.reset_search();
    }
    
count1 = 0;
if(debug) Serial.print("all count:");
//for(int i = 0; i < 5; i++) {
//         if(debug) Serial.print(good_flag[i]);
//         if(debug) Serial.print(" ");
//         if(good_flag[i] == 1) count1++;
//        }   
//        if(debug) Serial.println("");

if(good_flag[1] == 1 && good_flag[3] == 1 && good_flag[4] == 1) {
  count1 = 5;
}
if(count1 == 5) {
  J_fun:
  Serial.println("Jon");
  for(int i = 0; i < 255; i++) {
    analogWrite(led_mirror, i);
    delay(3);
  }
    for(int i = 0; i < 255; i++) {
    analogWrite(led_mirror_lamp, i);
    delay(3);
  }
  Step = 5;
}


 
}//end step 4

if(Step == 5) {
  if(count_led > 16) {
  digitalWrite(led_mirror, 0);
  }
  else {
    analogWrite(led_mirror, random(20, 50));
  }
if((millis() - timers) > pause) {
digitalWrite(led_mirror_lamp, mass_led[count_led]);
//analogWrite(led_mirror, 255);
count_led++;
if(count_led > 20) {
  count_led = 0;
  digitalWrite(led_mirror_lamp, 1);
//  for(int i = 0; i < 10; i++) {
//    analogWrite(led, random(1,10));
//    delay(random(50, 100));
//    analogWrite(led, random(100,150));
//    delay(random(50, 100));
//  }
  digitalWrite(led_mirror_lamp, 0);
  delay(100);
  digitalWrite(led_mirror, 0);
}
timers = millis();  
}

  if(digitalRead(shock_sensor) && flag_on == 0) {
  
    flag_on = 1;
    time_mass[0] = time_mass[1];
    time_mass[1] = time_mass[2];
    time_mass[2] = time_mass[3];
    time_mass[3] = time_mass[4];
    time_mass[4] = millis();

    d1 = time_mass[1] - time_mass[0];
    d2 = time_mass[2] - time_mass[1];
    d3 = time_mass[3] - time_mass[2];
    d4 = time_mass[4] - time_mass[3];
    if(debug) {
        Serial.println(d1);
        Serial.println(d2);
        Serial.println(d3);
        Serial.println(d4);
        Serial.println("------");
        /*
         * 1449
            1066
            2413
            2367
         */
         
    }
        if((d1 > 600 && d1 < 1900) && (d2 > 600 && d2 < 1900) && (d3 > 800 && d3 < 2200) && (d4 > 800 && d4 < 2200)) {
          K_fun:
          Serial.println("Kon");
          digitalWrite(lock_racovina, 0);
          for(int i = 255; i > 0; i--) {
            analogWrite(led_mirror_lamp, i);
            delay(8);
          }
          digitalWrite(lock_racovina, 0);
          for(int i = 40; i > 0; i--) {
            analogWrite(led_mirror, i);
            delay(10);
          }
          digitalWrite(led_mirror_lamp, 0);
          digitalWrite(led_mirror, 0);
          Step = 6;
        }
   }
  
  if(flag_on == 1 && !digitalRead(shock_sensor)) { 
    delay(200);
      if(!digitalRead(shock_sensor)) {
        delay(400);
        if(!digitalRead(shock_sensor)) flag_on = 0;
      }
  }


}//end step 5

if(Step == 6) {
  if((!digitalRead(hall1)) && (!digitalRead(hall1))) {
    delay(100);
    if((!digitalRead(hall1)) && !digitalRead(hall2)){ 
      L_fun:
      Serial.println("Lon");
      digitalWrite(lock_tainic_vent, 0);
      Step = 7;
     time_akt_door = millis();
    }
  }
}

if(Step == 7) {

  if((analogRead(vent_foto1) < 700) && (analogRead(vent_foto2) < 700) && (analogRead(vent_foto3) < 700)) {
  M_fun:
  Serial.println("Mon");    
 // digitalWrite(vent_dimm, 0);
  //digitalWrite(strob, 1);
  //digitalWrite(light_lok, 0);
  //Serial.println("2off");
  Serial.println("Bfon");
  digitalWrite(lock_button, 0);
  Step = 8;
}
}


//  Serial.print(analogRead(vent_foto1));
//  Serial.print(" ");
//  Serial.print(analogRead(vent_foto2));
//  Serial.print(" ");
//  Serial.print(analogRead(vent_foto3));
//  Serial.println(" ");

if(Step == 8 || Step == 9) {

                if((millis() - time_akt_door) > 60000) {
                N_fun:
                Serial.println("Non");
                   for(int i = 0; i < 6; i++) {
                    digitalWrite(aktivator, 1);
                      delay(random(100, 700));
                    digitalWrite(aktivator, 0);
                    delay(random(300, 500));
                   }
                   time_akt_door = millis();
                   Serial.println("Noff");
                  }

}

if(Step == 8) {
 if(!digitalRead(button_stop)) {
  delay(100);
  if(!digitalRead(button_stop)) {
    Z_fun:
    Serial.println("Zon");
    digitalWrite(vent_on, 0);
    Serial.println("4off");
    Step = 9;
  digitalWrite(strob, 1);
  digitalWrite(light_lok, 0);
  Serial.println("2off");
  }
     
 }
}
  

  if(Step == 9) {
    if(analogRead(instrument) < 1005) {
      delay(100);
      if(analogRead(instrument) < 1005) {
        O_fun:
        Serial.println("Oon");
        Serial.println("Cfon");
        digitalWrite(strob, 0);
        digitalWrite(light_lok, 1);
        Serial.println("2on");
        digitalWrite(vent_on, 0);
        Serial.println("4off");
        digitalWrite(lock_door, 0);
        Serial.println("1on");
            delay(3000);
            for(int i = 0; i < 4; i++) {
                    digitalWrite(aktivator, 1);
                      delay(random(200, 700));
                    digitalWrite(aktivator, 0);
                    delay(random(700, 100));
                   }
         Stop_Q();
      }
    }
  }
}//--end-loop

void Start_Q() {
  Serial.println("8");
  Serial.println("Aon");
  Serial.println("Afon");

  Step = 1;

  digitalWrite(lock_door, 1);
  Serial.println("1off");
  digitalWrite(motor_sliv, 0);
  digitalWrite(lock_hand, 1);
  digitalWrite(lock_potolok, 1);
  digitalWrite(akt_molot_up, 0);
  digitalWrite(akt_molot_down, 0);
  digitalWrite(lock_fish, 1);
  digitalWrite(led_mirror, 0);
  digitalWrite(led_mirror_lamp, 0);
  digitalWrite(lock_racovina, 1);
  digitalWrite(lock_tainic_vent, 1);
  digitalWrite(aktivator, 0);
  digitalWrite(strob, 0);
  digitalWrite(vent_on, 1);
            Serial.println("4on");
//  digitalWrite(vent_dimm, 0);
  digitalWrite(light_lok, 1);
  Serial.println("2on");
  digitalWrite(lock_button, 1);

flag_aqua = 0;

Serial.println("Doff");
Serial.println("Ioff");
Serial.println("Joff");
Serial.println("Foff");
Serial.println("Koff");
Serial.println("Loff");
Serial.println("Moff");
Serial.println("Noff");
Serial.println("Ooff");
Serial.println("Boff");
Serial.println("Zoff");


}

void Stop_Q() {
  
  Serial.println("9");
  digitalWrite(lock_door, 0);
  Serial.println("1on");
  digitalWrite(motor_sliv, 0);
  digitalWrite(lock_hand, 0);
  digitalWrite(lock_potolok, 0);
  digitalWrite(akt_molot_up, 0);
  digitalWrite(akt_molot_down, 0);
  digitalWrite(lock_fish, 0);
  digitalWrite(led_mirror, 1);
  digitalWrite(led_mirror_lamp, 0);
  digitalWrite(lock_racovina, 0);
  digitalWrite(lock_tainic_vent, 0);
  digitalWrite(aktivator, 0);
  digitalWrite(strob, 0);
  digitalWrite(vent_on, 0);
  Serial.println("4off");
//  digitalWrite(vent_dimm, 0);
  digitalWrite(light_lok, 1);
  Serial.println("2on");
  digitalWrite(lock_button, 0);


Step = 0;

 

}



void Clear_Q() {
  Serial.println("0");
Serial.println("0fon");

digitalWrite(lock_door, 0);
Serial.println("1on");
  digitalWrite(motor_sliv, 0);
  digitalWrite(lock_hand, 1);
  digitalWrite(lock_potolok, 1);
  digitalWrite(akt_molot_up, 0);
  digitalWrite(akt_molot_down, 0);
  digitalWrite(lock_fish, 1);
  digitalWrite(led_mirror, 0);
  digitalWrite(led_mirror_lamp, 0);
  digitalWrite(lock_racovina, 1);
  digitalWrite(lock_tainic_vent, 1);
  digitalWrite(aktivator, 0);
  digitalWrite(strob, 0);
  digitalWrite(vent_on, 1);
            Serial.println("4on");
//  digitalWrite(vent_dimm, 0);
  digitalWrite(light_lok, 1);
  Serial.println("2on");
  digitalWrite(lock_button, 1);

  flag_kuv = 1;

Step = 0;


}

int smartdelay(long int a) {
  break_flag = 0;
  for(long int i = 0; i < a; i++) {
    delay(1);

      if (!digitalRead(start_but)) {
                    delay(100);
                    if (!digitalRead(start_but)) {
                      Start_Q();
                      break_flag = 1;
                      break;
                    }
                }
      if(!digitalRead(stop_but)) {
        delay(10);
        if(!digitalRead(stop_but)) {
          Stop_Q;
          break_flag = 1;
          break;
             }
       }

       
  if (Serial.available() > 0)
  {

    incomingByte = Serial.read();
    while (Serial.available()) Serial.read();
    switch (incomingByte)
    {

      case '8':
       Start_Q();
                 break_flag = 1;
i = a;
      break;

      case '9':
      if(Step != 0) {
       Serial.println("Aoff");
        }
        Stop_Q();
                  break_flag = 1;
          i = a;
       break;
      
       case '0':
        Clear_Q();
                  break_flag = 1;
          i = a;
       break;
      //---------

      
  
    
    while (Serial.available()) Serial.read();

    }
  }
}
}
