#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "super_power.h"

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
