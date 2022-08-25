#include <stdio.h>
#include <math.h>
#include "calculating.h"

#define WIDTH 80
#define HEIGHT 25
#define X 0    // centre of coordinate
#define Y 13   // centre of coordinate  because E = {-1; 1}
#define XMAX 80    // maximum in X axis
#define XMIN 0  //  minimum in X axis ()
#define YMAX 13   //  maximum in Y axis
#define YMIN -12  //  minimum in Y axis

char field[HEIGHT][WIDTH];   // static massive for printing

int graph(int x, int y);    //  function that prints '*' in specific coordinate
void init_pole(void);       //  function that initialize the field with dots
void show_display(void);         //  function that prints the field

int rendering(char **rpn, int rpn_size) {
    float x;

    init_pole();
    for (x = 0 ; x <= 4 * 3.14159; x += 0.08) {  //  the D = {0; 4Pi}
        float y;
        y = value_calculating(x, rpn, rpn_size);           // place where we put or previous function
        graph(rintf(x * 6.2), rintf(y * 13));   // give coordinates for a graph with float roanding
    }
    show_display();

    return(0);
}

int graph(int x, int y) {
    // if ( x > XMAX || x < XMIN || y > YMAX || y < YMIN )  //  check to stay in massive
    //     return(-1);

    field[Y+y][X+x] = '*';
    return(0);
}

void init_pole(void) {
    int x, y;

    for (y = 0; y < HEIGHT ; y++)
        for ( x = 0; x < WIDTH; x++)
            field[y][x] = '.';
}
void show_display(void) {
    int x, y;

    for (y = 0 ; y < HEIGHT ; y++) {
        for (x = 0; x < WIDTH ; x++) {
            putchar(field[y][x]); }
        putchar('\n');
    }
}
