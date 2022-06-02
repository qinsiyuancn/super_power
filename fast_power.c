#include "fast_power.h"
long long fast_power(long long base, unsigned long long power, unsigned int mod)
{
    long long result = 1;
    while (power) {
        if (power & 0x1) result = result * base % mod;
        power >>= 1;
	base = base * base % mod;
    }
    return result;
}
