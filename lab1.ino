/*
    Matthew Delgado
    ECE 3551: Microcomputer Systems 1
    Lab 1: Arduino Lab #1
    Blink

 	Turns LEDs on and off in a similar way to a traffic light
*/
#define LED_PIN_12 12
#define LED_PIN_11 11
#define FIVE_SECONDS 5000
#define TWO_SECONDS 2000
#define THREE_SECONDS 3000
#define TWO_MICROSECONDS 2
#define TEN_MICROSECONDS 10

#define ECHO_PIN 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define TRIG_PIN 3 // attach pin D3 Arduino to pin Trig of HC-SR04

float duration; 
float distance; // variable for the duration and distance measurement

void redLightCycle(int);
void yellowLightCycle(int);
void greenLightCycle(int);

void clearTrigPin(int);
void activateTrigPin(int);

void setup() 
{
    Serial.begin(9600);                                     // Serial Communication is starting with 9600 of baudrate speed

 	pinMode(LED_BUILTIN, OUTPUT);                           // initialize digital pin LED_BUILTIN as an output. Same as Pin 13
    pinMode(LED_PIN_12, OUTPUT);                            // yellow LED
    pinMode(LED_PIN_11, OUTPUT);                            // green LED

    pinMode(TRIG_PIN, OUTPUT);                              // Sets the TRIG_PIN as an OUTPUT
    pinMode(ECHO_PIN, INPUT);                               // Sets the ECHO_PIN as an INPUT
}

void loop() 
{    
    digitalWrite(LED_BUILTIN, HIGH);                          // red light HIGH until car approaches intersection

    clearTrigPin(TWO_MICROSECONDS);                           // Clears the TRIG_PIN condition
    activateTrigPin(TEN_MICROSECONDS);                        // Sets the TRIG_PIN HIGH (ACTIVE) for 10 microseconds

    duration = pulseIn(ECHO_PIN, HIGH);                       // Reads the ECHO_PIN, returns the sound wave travel time in microseconds
    distance = (duration / 2) * 0.0343;                       // Speed of sound wave divided by 2
    
    Serial.print("Distance: ");                               // Displays the distance on the Serial Monitor
    if (distance <= 50 && distance >= 2)                      // Trigger the stop light functions
    {
        Serial.println("Vehicle approaching..."); 
        redLightCycle(FIVE_SECONDS);                            // red light turns on for five seconds
        greenLightCycle(THREE_SECONDS);                        // green light turns on for three seconds
        yellowLightCycle(TWO_SECONDS);                          // yellow light turns on for two seconds
    } else {
        Serial.println("Out of range.");                        
    }
}

void activateTrigPin(int duration) {
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
}

void clearTrigPin(int duration) {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(duration);
}

// function cycles red light
void redLightCycle(int duration)
{
    digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on
 	delay(duration);                                                           
 	digitalWrite(LED_BUILTIN, LOW);   // turn the LED off
}

// function cycles red light
void yellowLightCycle(int duration)
{
    digitalWrite(LED_PIN_12, HIGH);  // turn the LED on
 	delay(duration);                                                      
 	digitalWrite(LED_PIN_12, LOW);   // turn the LED off
}

// function cycles red light
void greenLightCycle(int duration)
{
    digitalWrite(LED_PIN_11, HIGH);  // turn the LED on
 	delay(duration);                                                     
 	digitalWrite(LED_PIN_11, LOW);   // turn the LED off
}
