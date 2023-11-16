#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;

class hash_table
{
    pair<string, int> *s = nullptr;
    int n = 0, m = 0;
    char *set = nullptr;

public:
    hash_table(int n = 11);

    void CopyOnly(const hash_table &b);

    hash_table(const hash_table &b);

    ~hash_table();

    void Clean();

    void SetZero();

    int h(pair<string, int> p)const;

    void inc(int &i)const;

    bool find(pair<string, int> p)const;

    bool find_str(string st)const;

    bool filled() const;

    bool empty() const;

    bool insert(pair<string, int> p);

    bool erase(pair<string, int> p);

    void erase_(int i);

    int find_max_len() const;

    void print_table() const;

    bool add_to_str(string st, int k);

    bool sub_from_str(string st, int k);

    int size()const;

    int used()const;
};

hash_table read_from_file(string path);

bool test();