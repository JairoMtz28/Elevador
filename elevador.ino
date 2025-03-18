//PROGRAMA ELEVADOR
//TI - 401
//CIRCUITOS ELECTRICOS Y ELECTRONICOS


#include <Stepper.h>

//BOTONES DE CADA PISO
int buttonPin1 = 22;
int buttonPin2 = 24;
int buttonPin3 = 26;

int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
//---------------------

//PINES DEL SENSOR ULTRASONICO
const int echo = 10;
const int trigger = 9;
int pisoActual = 0;
//---------------------

//PINES DEL DISPLAY
int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int f = 7;
int g = 8;
//---------------------

//PIN DE LOS LEDS
const int ledPin = 28;
//---------------------

//MOTOR A PASOS
int stepsPerRevolution = 2048;
Stepper motor(stepsPerRevolution, 14, 16, 15, 17);
//---------------------

//SONIDO DEL BUZZER
int melody1[] = {1760, 2093, 2349, 2794, 2349, 2093};
int noteDurations1[] = {4, 4, 4, 4, 4, 4};

int melody2[] = {523, 659, 784, 932, 784, 659};
int noteDurations2[] = {4, 4, 4, 4, 4, 4};

const int buzzerPin = 30;
//---------------------

void setup() {
  Serial.begin(9600);

  //BOTONES DE CADA PISO
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  //---------------------

  //PINES DEL SENSOR ULTRASONICO
  pinMode(echo, INPUT);
  pinMode(trigger, OUTPUT);
  digitalWrite(trigger, LOW);
  //---------------------
  
  //PINES DEL DISPLAY
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  //---------------------

  //PIN DE LOS LEDS
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  //---------------------

  //MOTOR A PASOS
  motor.setSpeed(18);
  //---------------------

  //SONIDO DEL BUZZER
  pinMode(buzzerPin, OUTPUT);
  //---------------------
}

void loop() {
  //PINES DEL SENSOR ULTRASONICO
  long tiempo = 0;
  long distancia = 0;

  digitalWrite(trigger, HIGH);
  delay(10);
  digitalWrite(trigger, LOW);

  tiempo = pulseIn(echo, HIGH);
  distancia = tiempo / 59;

  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.print(" cm");
  Serial.println("");

  if (distancia == 0) {
    
  }

  if (distancia < 15) {
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
    
    pisoActual = 1;
  }  
  else if(distancia < 25) {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, LOW);
    digitalWrite(g, HIGH);

    pisoActual = 2;
  }
  else if(distancia < 40) {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, HIGH);
    
    pisoActual = 3;
  }
  //---------------------

  //BOTONES DE CADA PISO
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  
  if (buttonState1 == HIGH) {
    Serial.print("boton 1 presionado");
    
    if (pisoActual != 1) {
      if (pisoActual == 2) {
        for (int i = 0; i < sizeof(melody2)/sizeof(int); i++) {
          tone(buzzerPin, melody2[i], 1000/noteDurations2[i]);
          delay(1000/noteDurations2[i] * 1.30);
        }
        delay(100);

        motor.step(18452);

        for (int i = 0; i < sizeof(melody1)/sizeof(int); i++) {
          tone(buzzerPin, melody1[i], 1000/noteDurations1[i]);
          delay(1000/noteDurations1[i] * 1.30);
        }
      }
      else if (pisoActual == 3) {
        for (int i = 0; i < sizeof(melody2)/sizeof(int); i++) {
          tone(buzzerPin, melody2[i], 1000/noteDurations2[i]);
          delay(1000/noteDurations2[i] * 1.30);
        }
        delay(100);

        Serial.print("boton 2 presionado");
        motor.step(18452);
        motor.step(18452);

        for (int i = 0; i < sizeof(melody1)/sizeof(int); i++) {
          tone(buzzerPin, melody1[i], 1000/noteDurations1[i]);
          delay(1000/noteDurations1[i] * 1.30);
        }
      }
    }
  }
  else if (buttonState2 == HIGH) {
    Serial.print("boton 2 presionado");
    
    if (pisoActual != 2) {
      if (pisoActual == 1) {
        for (int i = 0; i < sizeof(melody2)/sizeof(int); i++) {
          tone(buzzerPin, melody2[i], 1000/noteDurations2[i]);
          delay(1000/noteDurations2[i] * 1.30);
        }
        delay(100);
        
        motor.step(-18452);

        for (int i = 0; i < sizeof(melody1)/sizeof(int); i++) {
          tone(buzzerPin, melody1[i], 1000/noteDurations1[i]);
          delay(1000/noteDurations1[i] * 1.30);
        }
      }
      else if (pisoActual == 3) {
        for (int i = 0; i < sizeof(melody2)/sizeof(int); i++) {
          tone(buzzerPin, melody2[i], 1000/noteDurations2[i]);
          delay(1000/noteDurations2[i] * 1.30);
        }
        delay(100);
        
        motor.step(18452);

        for (int i = 0; i < sizeof(melody1)/sizeof(int); i++) {
          tone(buzzerPin, melody1[i], 1000/noteDurations1[i]);
          delay(1000/noteDurations1[i] * 1.30);
        }
      }
    }
  }
  else if (buttonState3 == HIGH) {
    Serial.print("boton 3 presionado");
    
    if (pisoActual != 3) {
      if (pisoActual == 1) {
        for (int i = 0; i < sizeof(melody2)/sizeof(int); i++) {
          tone(buzzerPin, melody2[i], 1000/noteDurations2[i]);
          delay(1000/noteDurations2[i] * 1.30);
        }
        delay(100);
        
        motor.step(-18452);
        motor.step(-18452);

        for (int i = 0; i < sizeof(melody1)/sizeof(int); i++) {
          tone(buzzerPin, melody1[i], 1000/noteDurations1[i]);
          delay(1000/noteDurations1[i] * 1.30);
        }
      }
      else if (pisoActual == 2) {
        for (int i = 0; i < sizeof(melody2)/sizeof(int); i++) {
          tone(buzzerPin, melody2[i], 1000/noteDurations2[i]);
          delay(1000/noteDurations2[i] * 1.30);
        }
        delay(100);
        
        motor.step(-18452);

        for (int i = 0; i < sizeof(melody1)/sizeof(int); i++) {
          tone(buzzerPin, melody1[i], 1000/noteDurations1[i]);
          delay(1000/noteDurations1[i] * 1.30);
        }
      }
    }
  }
  //---------------------
}
