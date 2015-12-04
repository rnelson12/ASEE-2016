#ifndef CONFIGURE_H
#define CONFIGURE_H

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
#define NEXT_RING 180

/*
 * right wheel settings
 */
#define WHEEL_RADIUS 10
#define RIGHT_MOTOR_POWER 225
#define RIGHT_WHEEL_PIN 5
#define RIGHT_REVERSE_PIN 7
#define RIGHT_WHEEL_OFFSET 0

/*
 * left wheel settings
 */
#define LEFT_MOTOR_POWER 225
#define LEFT_WHEEL_PIN 6
#define LEFT_REVERSE_PIN 8
#define LEFT_WHEEL_OFFSET 0

/*
 * configuration for the sensors
 */
#define WHITE_VALUE 42
#define BLACK_VALUE 1020

#endif
