#include <inttypes.h>
#include <math.h>

/*
* c2c was taken from resynctool, from otpd
* http://sourceforge.net/projects/otpd/
*/
void c2c(uint64_t counter, unsigned char challenge[])
{
  challenge[0] = counter >> 56;
  challenge[1] = counter >> 48;
  challenge[2] = counter >> 40;
  challenge[3] = counter >> 32;
  challenge[4] = counter >> 24;
  challenge[5] = counter >> 16;
  challenge[6] = counter >> 8;
  challenge[7] = counter;
}

