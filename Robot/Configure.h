#ifndef CONFIGURE_H
#define CONFIGURE_H

/*
 * configure file for the rockbot. This will include all the things that we,
 * the badass programing team, have decided that you muggals can change.
 * everything should be labeled pretty well and if not, I have included some
 * pretty awesome discriptions of the variables.
 * 
 * Please dont change the code. That is incredably hard to debug...Like if
 * you change one thing like i++ to i-- it will take us hours to figure out
 * what the fuck you changed and most likely will have to get a fresh copy 
 * of the code from the github. I mean thats not the biggest hassle but its
 * still inconveinent so just dont.Most likely we will have to scrap the 
 * code that you modified and start over so just dont. THAT MEANS YOU SAGE. 
 * JUST USE THE CONFIG FILE
 * 
 * Anything that is a pin or a sensor or an output pin to like a motor should
 * be a digital pin. So all you have to do to change that is change it from
 * like 2 to 5. If it is an analog READ not write, use A0 through A6.
 * 
 * if it is an analog out pin like for the motor use one of the PWM pins. 
 * If you dont know what that is, look on the arduino. It should be labeled 
 * with a ~ or PWM. If you still cant find that, look it up.
 */

/*
 * set this to 1 if you want the arduino to print to the serial for debugging
 */
#define DEBUG 0

/*
 * pin number for the button or switch that starts the robots
 */
#define START_BUTTON 2

/*
 * not sure if we need this or not but I think if we just label 1 pin for the
 * sensor grid then have the code assign the next 8 or so after that pin
 * as sensors, we should be good.
 */
 #define GRID_SENSOR 11

/*
 * cog settings
 */
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

#endif
