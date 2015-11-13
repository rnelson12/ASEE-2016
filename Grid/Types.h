#ifndef TYPES_H
#define TYPES_H

typedef enum{
  BLACK,
  WHITE,
  RED,
  NO_COLOR,

  ADJUST_LEFT,
  ADJUST_RIGHT,
  RETURN_TO_NORMAL,
  NO_ADJUST,

  TURN_LEFT,
  TURN_RIGHT,
  FORWARD,
  CONTINUE
} State;

#endif
