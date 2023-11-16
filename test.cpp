#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <fstream>
#include "hash_table.hpp"
using namespace std;

bool test()
{
    hash_table h(17);
    for (int i = 0; i < 16; i++)
    {
        if (!h.insert({to_string(i * 7), i * 7}))
        {
            return false;
        }
    }
    if (h.find({"77", 77}))
    {
        return true;
    }
    return false;
}