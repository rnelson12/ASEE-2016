#ifndef CONFIGURE_H
#define CONFIGURE_H

/*
 * This is the configure file for the rockbot. YES ALLY, IT IS A ROCKBOT STOP RUEING THIS FOR 
 * ME! This will include all the things that we, the badass programing team, have decided that you
 * muggals can change. Everything should be labeled pretty well and if not, I have included some
 * pretty awesome descriptions of the variables.
 * 
 * By the way, this file is riddled with spelling error and grammar mistakes so if you come up to me
 * and say “Hey, this word is misspelled in the config file” I will say “your mother”. Also, I added all of
 * these funny comments because I know how frustrating it is to debug shit so take it lightly and as a
 * joke because thats how it was written. Except for the parts where I may say stuff to you. I will still 
 * say those :D
 * 
 * Please don’t change the code. That is incredibly hard to debug...Like if
 * you change one thing like i++ to i-- it will take us hours to figure out
 * what the fuck you changed and most likely will have to get a fresh copy 
 * of the code from the github. I mean thats not the biggest hassle but its
 * still inconvenient so just don’t. Most likely we will have to scrap the 
 * code that you modified and start over so just don’t. THAT MEANS YOU SAGE. 
 * JUST USE THE CONFIG FILE
 * 
 * Anything that is a pin or a sensor or an output pin to like a motor should
 * be a digital pin. So all you have to do to change that is change it from
 * like 2 to 5. If it is an analog READ not write, use A0 through A6.
 * 
 * if it is an analog out pin like for the motor use one of the PWM pins. 
 * If you don’t know what that is, look on the Arduino. It should be labeled 
 * with a ~ or PWM. If you still cant find that, look it up. Still can't find it,
 * shut up.
 */

/*
 * set this to 1 if you want the Arduino to print to the serial for debugging
 * FOR THE LOVE OF GOD! CHANGE THIS BACK TO 0 BEFORE WE GO TO THE CONTEST!
 */
#define DEBUG 0

/*
 * set this to 0 if the robot is going to the right.
 * or set this to 1 if the robot is going to go to the left
 */
 #define ROBOT_DIRECTION 0

/*
 * pin number for the button or switch that starts the robots
 */
#define START_BUTTON 2

/*
 * This is the address for the sensor bar. DON’T CHANGE THIS. UNLESS WE 
 * NEED TO CHANGE THIS TO AVOID ADDRESSING PROBLEMS. IN THAT CASE, FOR THE
 * LOVE OF GOD DON’T NOT CHANGE IT. The possible addresses for
 * the SensorBar are labeled on the SensorBar. You will need to do some 
 * soldering on the SensorBar so check that out.
 * I’m not defining the other sensors we are using because they use static addresses. You shouldn’t 
 * be trying to change those so don’t ask me how because I will slap you or start singing cry me a
 * river.
 */
 #define SENSOR_BAR_ADDRESS 0xE3

/*
 * these are for the PID settings. It was recommended by the all powerful 
 * and all knowing internet that we try with something small and be 
 * scientific about it to find the right value for us. Weird right? the
 * internet is trying to make us learn stuff! BAHAHA weird.
 * Anyways I set them to 1 for now and I think if we increase it the robot
 * may get more accurate. Or not. I don’t really know, I'm just a bad-ass 
 * programmer not a chemist.
 */
 #define kp 0
 #define kd 0
 #define ki 0

/*
 * The target is the center of the array (0-100)
 */
 #define TARGET 50

/*
 * cog settings
 */

//different powers that you may to drive the motors at turns and whatnot
#define MAX_POWER 100
#define THREE_FOURTHS_POWER 75
#define HALF_POWER 50
#define QUARTER_POWER 25
#define LOW_POWER 10
 
#define LEFT_RINGS 6
#define RIGHT_RINGS 6
#define RIGHT_COG_PIN 9
#define LEFT_COG_PIN 10
//this is the degrees that the motor needs to turn to drop another ring.
#define NEXT_RING 180

#define WHEEL_RADIUS 10

/*
 * right wheel settings
 */
#define RIGHT_MOTOR_POWER 100
#define RIGHT_WHEEL_PIN 5
#define RIGHT_REVERSE_PIN 7
#define RIGHT_WHEEL_OFFSET 0
//this one is a percent!! NOT a value so dont fuck up
#define RIGHT_ADJUSTMENT 10

/*
 * left wheel settings
 */
#define LEFT_MOTOR_POWER 100
#define LEFT_WHEEL_PIN 6
#define LEFT_REVERSE_PIN 8
#define LEFT_WHEEL_OFFSET 0
//this one is a percent!! NOT a value so dont fuck up
#define LEFT_ADJUSTMENT 10

/*
 * configuration for the sensors
 * 
 * these are values for the line following sensors. White is the wood and you
 * should know that so dont come to me and say "Kelly, what does the white
 * value do?" because I'm going to say go read the config file then do some
 * kind of z formation snap or maybe inquire that your mother is a prostitute.
 */
#define WHITE_VALUE 42
#define BLACK_VALUE 1020

/*
 * configuration for the color sensor. This value is what the robot will be
 * comparing to the red box.
 */

 #define RED 6

/*
 * configuration for the times for States.h
 * This is how long the motors need to run
 */

//todo: change these values
#define ROBOT1_RIGHT_TURN_TIME 1000
#define ROBOT1_LEFT_TURN_TIME 1000

#define ROBOT2_RIGHT_TURN_TIME 1000
#define ROBOT2_LEFT_TURN_TIME 1000

#define ROBOT1_EAST_STRAIGHTAWAY_TIME 2000
#define ROBOT2_WEST_STRAIGHTAWAY_TIME 2000

#endif
