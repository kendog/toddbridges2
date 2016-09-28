/*
  AnalogPinValues
  Reads an analog input on pins 0-5.  Spits out values to Serial.
*/
// constants won't change. They're used here to 
// set pin numbers:
const int buttonPin = 11;     // the number of the pushbutton pin
const int STATUS_LED = 13;
const int MOTOR_FORWARD =  9;      // INA of motor driver board
const int MOTOR_REVERSE =  6;      // INB of motor driver board
const int POT = A0; // potentimeter pin.

int MOTOR_SPEED;
int MOTOR_MIN_SPEED = 0;
int MOTOR_MAX_SPEED = 150; //can adjust to 255 for full motor speed. 
int POT_VAL;
int buttonState = 0;         // variable for reading the pushbutton status

byte byteRead;



// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  pinMode(STATUS_LED,OUTPUT); //on board status LED
  pinMode(MOTOR_FORWARD,OUTPUT); 
  pinMode(MOTOR_REVERSE,OUTPUT); 
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT); 
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
  
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  // assign value POT_VAL to read values from POT pin.
  //POT_VAL = analogRead(POT); 

  // assign the range of variable MOTOR_SPEED to 'map' the values of the potentiometer to the values of our set motor speed
  MOTOR_SPEED = map (POT_VAL, 0, 1023, MOTOR_MIN_SPEED, MOTOR_MAX_SPEED);

  if(buttonState== LOW ){ 
    //switch direction of motor with button press
  //then change speed of motor with knob.
    analogWrite(MOTOR_FORWARD, MOTOR_SPEED);  //trigger forward pin
    digitalWrite(MOTOR_REVERSE, LOW);
    digitalWrite(STATUS_LED, HIGH);

  }

  if (buttonState==HIGH ){

    analogWrite(MOTOR_REVERSE, MOTOR_SPEED);  //trigger reverse pin
    digitalWrite(MOTOR_FORWARD, LOW);
    digitalWrite(STATUS_LED, LOW);
  }

  delay(1000);
    
}


/*
  SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.
 */
void serialEvent() {

  String inputString = "";
  
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
  }

  POT_VAL = inputString.toInt();
  
}


