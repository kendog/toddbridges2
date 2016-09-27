/*
  AnalogPinValues
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Graphical representation is available using serial plotter (Tools > Serial Plotter menu)
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.
*/

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {

  // read the input on analog pins:
  int pinValue_A0 = analogRead(A0);
  int pinValue_A1 = analogRead(A1);
  int pinValue_A2 = analogRead(A2);
  int pinValue_A3 = analogRead(A3);
  int pinValue_A4 = analogRead(A4);
  int pinValue_A5 = analogRead(A5);

  Serial.print("&A0=");
  Serial.print(pinValue_A0);
  Serial.print("&A1=");
  Serial.print(pinValue_A1);
  Serial.print("&A2=");
  Serial.print(pinValue_A2);
  Serial.print("&A3=");
  Serial.print(pinValue_A3);
  Serial.print("&A4=");
  Serial.print(pinValue_A4);
  Serial.print("&A5=");
  Serial.print(pinValue_A5);
  Serial.println("&");
  
  delay(1000);        // delay in between reads for stability
    
}
