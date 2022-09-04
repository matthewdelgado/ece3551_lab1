# ece3551_lab1
## PURPOSE
The purpose of this lab was to be an introductory lesson/refresher to the Arduino microcontroller. The aim was to use resistors, LEDs, connectors, and an HRS04 sensor to mimic the function of a typical traffic light. Ultimately this allows the developer to interface with the Serial Monitor, basic LED manipulation, as well as the use of sensors to cause a desired action by the microcontroller.

## METHOD
The went about completing this lab by starting with the basic implementation of turning an LED on and off repeatedly. I then started to add more LEDs in the form of a traffic light and made them cycle through being on and off to mimic the same cycle as a traffic light.
This was cycling repeatedly forever at the same pace, so I then added the HRS04 sensor to add a smarter feel to the sketch. This could allow for objects to approach the sensor triggering the lights to turn green. The light cycles back to red and stays red until another object approaches the sensor.
I tried to separate the majority of functionality into separate functions to keep my code clean and easy to read. I also made a git repository to keep track of all the versions of my code as I changed it and added more components.

## RESULTS
The result of completing this lab was that the Arduino board could act as a simple traffic light. If an object approaches the HRS04 sensor then the LEDs on the board cycle through from a Green light, to a Yellow light, and finally settles on a Red light until another object approaches. It can be seen in Image 3, that when I place my hand in front of the board it set the green light to high and cycles through. The Serial Monitor alerts the user that objects are out of range until an object moves within 50cm of the HRs04 sensor. 

## CODE EXPLANATION 
The code for this lab is quite simple. I will explain it starting from the top of the lab1.ino file. 
First, I define all the variables used in the sketch in order to make the code more readable. I also declare all of the functions I wrote just below the definition of all the variables. I prefer my function definitions to be at the bottom of my files for organizational purposes. 
Next, the setup() function is used to initialize the Serial monitor at a baud rate of 9600. I set all of my pin modes to corresponding input and outputs. 
Lastly, the loop() function runs forever and keeps the red LED HIGH until an object approaches the HRs04 sensor. If an object comes between 2cm and 50cm then the Serial Monitor notifies the user that a “vehicle” has approached the traffic light, and then the traffic light turns green for some specified time and cycles back to yellow and finally red. 

## CONCLUSION 
In conclusion, I ran into no errors along the way of completing this lab and the Arduino’s LEDs, cables, resistors, and HRS04 sensor worked properly from the start. If I were to go back and improve this lab I would make the light stay green for 20 seconds and if an object is still within range it would cycle to yellow then red. If an object moved out of range and a new object did not move within range in 5 seconds, then the light would cycle to red. This would mimic a traffic light reacting to whether or not cars are sensed at the light. 
