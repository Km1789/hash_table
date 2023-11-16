#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <fstream>
#include "hash_table.hpp"
using namespace std;

int main()
{
    // if (test())
    // {
    //     cout << "Test passed!" << endl;
    // }
    // else
    // {
    //     cout << "Test failed!" << endl;
    // }
    // hash_table h;
    // for (int i = 0; i < 10; i++)
    // {
    //     if (!h.insert({to_string(i * 7), i * 7}))
    //     {
    //         cout << "can not insert" << i * 7 << endl;
    //     }
    // }
    // for (int i = 0; i < 10; i++)
    // {
    //     if (!h.insert({to_string(i * 7), i * 7}))
    //     {
    //         cout << i * 7 << " : " << (h.find({to_string(i * 7), i * 7}) ? "found" : "not found") << endl;
    //     }
    // }
    // h.add_to_str("0", 100);
    // h.sub_from_str("0", 100);
    // h.print_table();
    // h.erase({"0", 0});
    // h.print_table();
    cout << "--------------------" << endl;
    hash_table sp = read_from_file("input.txt");
    sp.print_table();
    return 0;
}