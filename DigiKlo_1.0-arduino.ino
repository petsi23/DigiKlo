int tasterPin = 2;  // Taster gegen Masse schalten
int relaisPuPin = 3;  // Pumpenrelais
int relaisM1Pin = 4;  // Motorrelais 1
int relaisM2Pin = 5;  // Motorrelais 2
int spuelZeit = 4000;  // Pumpenlaufzeit
int ruehrTeilZeitRunter = 7000;  // Rührwerk Untergrabzeit
int ruehrTeilZeitHoch = 2000;  // Rührwerk Aufhäufzeit
int ruehrZeitHochFinal = 10000;  // Rührwerk Aufhäufzeit


// --------------------------- ab hier nichts mehr ändern -------------------------

unsigned long jetztZeit;
unsigned long warZeit;
int neuTast = 0;


void setup() {
  // put your setup code here, to run once:
pinMode(tasterPin, INPUT_PULLUP);
pinMode(relaisM1Pin, OUTPUT);
  digitalWrite(relaisM1Pin, HIGH);
pinMode(relaisM2Pin, OUTPUT);
  digitalWrite(relaisM2Pin, HIGH);
pinMode(relaisPuPin, OUTPUT);
  digitalWrite(relaisPuPin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (digitalRead(tasterPin) == HIGH){
    // Taster ist nicht gedrückt

    // prüfen ob Taster vorher gedrückt war

    if (neuTast == 1){
      // Taster war gedrückt

      jetztZeit = millis();

      if (jetztZeit - warZeit < 5000){
        // Tastendruck war unter 5 Sekunden lang
        
        // Spülpumpe
        digitalWrite(relaisPuPin, LOW);
        delay(spuelZeit);
        digitalWrite(relaisPuPin, HIGH);
        // Kurz warten
        delay(500);

        for(int i=0;i<10;i++){
          // Mehrfach unter- und hochrühren
          
          // Rührwerk runter
          digitalWrite(relaisM1Pin, LOW);
          delay(ruehrTeilZeitRunter);
          digitalWrite(relaisM1Pin, HIGH);
          
          // Kurz warten
          delay(500);
          
          // Rührwerk hoch
          digitalWrite(relaisM2Pin, LOW);
          delay(ruehrTeilZeitHoch);
          digitalWrite(relaisM2Pin, HIGH);
          
          // Kurz warten
          delay(500);
          }
        
        // Rührwerk hoch, macht einen Hügel als Grundlage für nächstes mal
        digitalWrite(relaisM2Pin, LOW);
        delay(ruehrZeitHochFinal);
        digitalWrite(relaisM2Pin, HIGH);        
        
        // Reset
        neuTast = 0;

        // Ende Taster unter 5 Sekunden
      }

      if (jetztZeit - warZeit >= 5000){
        // Tastendruck war über 5 Sekunde lang
        
        // Reset
        neuTast = 0;
      }

if (jetztZeit - warZeit > 10000){
        // Tastendruck war über 10 Sekunden lang
        
        // Reset
        neuTast = 0;
      }


    // Ende Taster war gedrückt
    }

  // Ende Taster nicht gedrückt
  } else {
    // Taster ist gedrückt

    // prüfen ob der Tastendruck schon erkannt wurde

    if (neuTast == 0){ 
      // Tastendruck wurde noch nicht vorher erkannt
      neuTast = 1; 
      warZeit = millis();
      } 

  // Ende Taster ist gedrückt
  }




// Ende Loop
}
