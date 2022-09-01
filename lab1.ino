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

#define ECHO_PIN 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define TRIG_PIN 3 //attach pin D3 Arduino to pin Trig of HC-SR04

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

void redLightCycle(int);
void yellowLightCycle(int);
void greenLightCycle(int);

void setup() 
{
 	pinMode(LED_BUILTIN, OUTPUT);                           // initialize digital pin LED_BUILTIN as an output. Same as Pin 13
    pinMode(LED_PIN_12, OUTPUT);
    pinMode(LED_PIN_11, OUTPUT);

    pinMode(TRIG_PIN, OUTPUT);                              // Sets the TRIG_PIN as an OUTPUT
    pinMode(ECHO_PIN, INPUT);                               // Sets the ECHO_PIN as an INPUT
    Serial.begin(9600);                                     // Serial Communication is starting with 9600 of baudrate speed
    Serial.println("Ultrasonic Sensor HC-SR04 Test");       // print some text in Serial Monitor
    Serial.println("with Arduino UNO R3");
}

void loop() 
{
    redLightCycle(FIVE_SECONDS);                            // red light turns on for five seconds
    yellowLightCycle(TWO_SECONDS);                          // yellow light turns on for two seconds
    greenLightCtycle(THREE_SECONDS);                        // green light turns on for three seconds      

    // Clears the TRIG_PIN condition
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    // Sets the TRIG_PIN HIGH (ACTIVE) for 10 microseconds
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
    // Reads the ECHO_PIN, returns the sound wave travel time in microseconds
    duration = pulseIn(ECHO_PIN, HIGH);
    // Calculating the distance
    distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
    // Displays the distance on the Serial Monitor
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
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
void greenLightCtycle(int duration)
{
    digitalWrite(LED_PIN_11, HIGH);  // turn the LED on
 	delay(duration);                                                     
 	digitalWrite(LED_PIN_11, LOW);   // turn the LED off
}
