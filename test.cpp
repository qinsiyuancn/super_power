#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#if FAST_POWER
#else
#endif

using namespace std;

#define chect_param_count(n) do {\
        if(argc < n){\
	    cout << 0 << endl;\
            exit(1);\
        }\
    }while(0)

#define ton(in, out) do {\
        stringstream ss;\
	ss << in;\
	ss >> out;\
    }while(0)

#if FAST_POWER

#include "fast_power.h"
int main(int argc, char **argv)
{
    long long base = 0;
    unsigned long long power = 0, mod = -1ull;
    chect_param_count(3);
    ton(argv[1], base);
    ton(argv[2], power);
    if(argc > 3) ton(argv[3], mod);
    cout << fast_power(base, power , mod) << endl;
    return 0;
}
#else

#include "super_power.h"

int main(int argc, char **argv)
{
    long long base = 0;
    unsigned long long mod = -1ull;
    string power_str = argv[2];
    vector<unsigned char> power_vec(power_str.size());
    chect_param_count(3);
    ton(argv[1], base);
    if(argc > 3) ton(argv[3], mod);
    for(unsigned long long i = 0; i < power_str.size(); i++)
        power_vec[i] = power_str[i] - '0';
    cout << super_power(base, power_vec.data(), power_vec.size(), mod) << endl;
    return 0;
}
#endif
