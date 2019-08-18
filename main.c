#include "ERLib.h"

double *heightmap;

int main()
{
    //quick test to see if psudorand is reasonable.
    int frequencies[10];
    printf("Frequencies initalizing\n");
    for(int i = 0; i < 10; i++)
    {
        frequencies[i] = 0;
    }
    printf("Looping\n");
    for(int i = 0; i < 0xFFFF; i++)
    {
        int randVal = (int) floor((psudoRand(i, 5) - psudoRand(i+1, 5) + 1) * 5.0);
        if(randVal < 10 || randVal >= 0)
        {
            frequencies[randVal]++;
        } else {
            printf("Error: Psudorandom value {%f} out of bounds\n",psudoRand(i, 5));
            exit(0);
        }
    }
    printf("Printing results\n");
    for(int i = 0; i < 10; i++)
    {
        printf("[%d] = %d\n", i ,frequencies[i]);
    }
    exit(0);
}