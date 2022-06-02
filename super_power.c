#include "super_power.h"
#include "fast_power.h"

long long super_power(long long base, const unsigned char * power, unsigned long long power_size, unsigned int mod)
{
    long long result = 1;
    for(unsigned long long i = 0; i < power_size; i++){
        result = fast_power(base, power[power_size - i - 1], mod) * result % mod;
	base = fast_power(base, 10, mod);
    }
    return result;
}

