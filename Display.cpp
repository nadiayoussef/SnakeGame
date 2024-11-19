#include <iostream>
#include <cstdlib>
#include <ncurses.h>
#include "Display.hpp"

// Display *init_display(int upper_left_x, int upper_left_y, int width, int height)
// {
//     Display *g;
//     g = (Display *) malloc(sizeof(Display));
//     g->upper_left_x = upper_left_x;
//     g->upper_left_y = upper_left_y;
//     g->width = width;
//     g->height = height;
//     g->draw_char = '#';
//     g->color[0] = 0;
//     g->color[1] = 0;
//     g->color[2] = 255;
//     return (g);
// }

// void draw_display(Display *d)
// {
//     start_color();
//     init_pair(2, COLOR_MAGENTA, COLOR_BLACK);
//     attron(COLOR_PAIR(2));
//     int row_counter, column_counter;

//     // Draw Top of room
//     for (row_counter = d->upper_left_x;
//          row_counter <= (d->upper_left_x + d->width);
//          row_counter++) {
//         mvprintw(d->upper_left_y, row_counter, "%c", d->draw_char);
//     }

//     // Draw left side of room
//     for (column_counter = d->upper_left_y;
//          column_counter <= (d->upper_left_y + d->height);
//          column_counter++) {
//         mvprintw(column_counter, d->upper_left_x, "%c", d->draw_char);
//     }

//     // Draw right side of room
//     for (column_counter = d->upper_left_y;
//          column_counter <= (d->upper_left_y + d->height);
//          column_counter++) {
//         mvprintw(column_counter, (d->upper_left_x + d->width), "%c", d->draw_char);
//     }

//     // Draw Bottom of room
//     for (row_counter = d->upper_left_x;
//          row_counter <= (d->upper_left_x + d->width);
//          row_counter++) {
//         mvprintw(d->upper_left_y + d->height, row_counter, "%c", d->draw_char);
//     }
//     attroff(COLOR_PAIR(2));

// }

