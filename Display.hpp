#ifndef DISPLAY_H
#define DISPLAY_H
#include <iostream>
#include <cstdlib>
#include <ncurses.h>
#include "Date.hpp"
using namespace std;

//class Date;

#define WELL_WIDTH 50
#define WELL_HEIGHT 25

struct Display
{
  int upper_left_x;
  int upper_left_y;
  int width;
  int height;
  char draw_char;
  char color[3];
};


Display *init_display(int, int, int, int); // the borders
void draw_display(Display *d);

void draw_timetable(Display *d, Date day);
void undraw_timetable(Display *d, Date day);
#endif