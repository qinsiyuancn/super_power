#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "fast_power.h"

using namespace std;

#define chect_param_count(n) do {\
        if(argc < n){\
	    cout << 0 << endl;\
            exit(1);\
        }\
    }while(0)

#define ton(in, out) do {\
        stringstream(in) >> out;\
    }while(0)


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
