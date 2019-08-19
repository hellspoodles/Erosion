#include "ERLib.h"

//////////////////////////////////////////////////////////////
/////////////////Private Math Helper Variables////////////////
//////////////////////////////////////////////////////////////

double primes[256];
int primesCalc = 0;

//////////////////////////////////////////////////////////////
/////////////////Private Math Helper Functions////////////////
//////////////////////////////////////////////////////////////

static double sawWave(double time, double frequency)
{
    double tf = time/frequency;
    return tf - floor(tf);
}

static void calcPrimes()
{
    int i = 0;
    int prime = 2;
    while(i < 256)
    {
        int notAPrime = 1;
        for(int j = 2; j < prime; j++)
        {
            if(prime % j == 0)
                notAPrime = 0;
        }
        if(notAPrime)
        {
            primes[i] = (double) prime;
            i++;
        }
        prime++;
    }
    primesCalc = 1;
}

//////////////////////////////////////////////////////////////
/////////////////Public Math Helper Functions/////////////////
//////////////////////////////////////////////////////////////

double psudoRand(int key, int octaves)
{
    if(primesCalc == 0)
        calcPrimes();
    double dkey = (double) key;
    double sum = 0.0;
    for(int i = 1; i <= octaves; i++)
    {
        sum += sawWave((double) key * primes[(i * 15) % 255], primes[(i * 20) % 255]);
    }
    return sum / octaves;
}

ERL_STATUS perlinNoise(double *heightmap, int x, int y, double scale, int octaves, int keyOverride)
{

}