#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

///////////////////////////////////////////////////////
/////////////////Structs and Enumerators///////////////
///////////////////////////////////////////////////////

typedef struct __vector2{
    double x;
    double y;
}vector2;

typedef struct __vector3{
    double x;
    double y;
    double z;
}vector3;

typedef struct __vectorN{
    double *a;
    int dimensions;
}vectorN;

typedef enum __ERL_STATUS{
    ERLSTATUS_OK                = 0,
    ERLSTATUS_ERROR             = 1,
    ERLSTATUS_MALLOC_FAIL       = 2
}ERL_STATUS;

///////////////////////////////////////////////////////
/////////////////Math Helper Functions/////////////////
///////////////////////////////////////////////////////

/**
 * @brief generates a psudorandom value based on the key
 * 
 * @param key       Determines what value the function returns
 * 
 * @return double   A psudorandom value between 0 and 1
 */
double psudoRand (int key, int octaves);

ERL_STATUS perlinNoise(double *heightmap, int x, int y, double scale, int octaves, int keyOverride);

