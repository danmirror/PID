    // Install Pin change interrupt for a pin, can be called multiple times
     
    void pciSetup(byte pin)
    {
        *digitalPinToPCMSK(pin) |= bit (digitalPinToPCMSKbit(pin));  // enable pin
        PCIFR  |= bit (digitalPinToPCICRbit(pin)); // clear any outstanding interrupt
        PCICR  |= bit (digitalPinToPCICRbit(pin)); // enable interrupt for the group
    }
     
    // Use one Routine to handle each group
     
    ISR (PCINT0_vect) // handle pin change interrupt for D8 to D13 here
     {    
         digitalWrite(13,digitalRead(8) and digitalRead(9));
     }
     
    ISR (PCINT1_vect) // handle pin change interrupt for A0 to A5 here
     {
         digitalWrite(13,digitalRead(A0));
     }  
     
    ISR (PCINT2_vect) // handle pin change interrupt for D0 to D7 here
     {
         digitalWrite(13,digitalRead(7));
     }  
     
    void setup() {  
    int i;
     
    // set pullups, if necessary
      for (i=0; i<=12; i++)
          digitalWrite(i,HIGH);  // pinMode( ,INPUT) is default
     
      for (i=A0; i<=A5; i++)
          digitalWrite(i,HIGH);
     
      pinMode(13,OUTPUT);  // LED
     
    // enable interrupt for pin...
      pciSetup(7);
      pciSetup(8);
      pciSetup(9);
      pciSetup(A0);
    }
     
     
    void loop() {
      // Nothing needed
    }
