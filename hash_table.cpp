#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <fstream>
#include "hash_table.hpp"

hash_table::hash_table(int n)
{
    s = new pair<string, int>[this->n = n];
    set = new char[n];
    memset(set, 0, n);
    m = 0;
}

void hash_table::CopyOnly(const hash_table &b)
{
    Clean();
    SetZero();
    if (!b.empty())
    {
        this->n = b.n;
        this->m = 0;
        s = new pair<string, int>[this->n];
        set = new char[n];
        memset(set, 0, n);
        for (int i = 0; i < n; i++)
        {
            if (b.set[i] == true)
            {
                this->insert(b.s[i]);
            }
        }
    }
}

hash_table::hash_table(const hash_table &b)
{
    CopyOnly(b);
}

hash_table::~hash_table()
{
    Clean();
}

void hash_table::Clean()
{
    delete[] s;
    delete[] set;
}

void hash_table::SetZero()
{
    s = nullptr;
    set = nullptr;
    n = 0;
    m = 0;
}

int hash_table::h(pair<string, int> p)const
{
    unsigned long long int hash = 0, x = static_cast<unsigned long long int>(pow(2, 3)) + 1;
    for (int i = 0; static_cast<unsigned long long int>(i) < p.first.length(); i++)
    {
        hash += static_cast<unsigned long long int>(pow(x, i)) * static_cast<unsigned long long int>(p.first[i]);
    }
    hash *= p.second;
    return hash % n;
}

void hash_table::inc(int &i)const
{
    i = (i + 1) % n;
}

bool hash_table::find(pair<string, int> p)const
{
    for (int i = h(p); set[i]; inc(i))
    {
        if (s[i] == p)
        {
            return true;
        }
    }
    return false;
}

bool hash_table::find_str(string st)const
{
    for (int i = 0; i < n; i++)
    {
        if (s[i].first == st)
        {
            return true;
        }
    }
    return false;
}

bool hash_table::filled() const
{
    return m >= n - 1;
}

bool hash_table::empty() const
{
    return m == 0;
}

int hash_table::size()const
{
    return n;
}

int hash_table::used()const
{
    return m;
}

bool hash_table::insert(pair<string, int> p)
{
    if (filled())
    {
        return false;
    }
    int i = h(p);
    for (; set[i]; inc(i))
    {
        if (s[i] == p)
        {
            return false;
        }
    }
    s[i] = p;
    set[i] = true;
    m++;
    return true;
}

bool hash_table::erase(pair<string, int> p)
{
    for (int i = h(p); set[i]; inc(i))
    {
        if (s[i] == p)
        {
            erase_(i);
            m--;
            return true;
        }
    }
    return false;
}

void hash_table::erase_(int i)
{
    set[i] = false;
    int j = i;
    for (inc(j); set[j]; inc(j))
    {
        if ((h(s[j]) <= i && i < j) || (j < h(s[j]) && h(s[j]) <= i) || (i < j && j < h(s[j])))
        {
            s[i] = s[j];
            set[i] = true;
            erase_(j);
            break;
        }
    }
}

int hash_table::find_max_len() const
{
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        if (set[i] == true)
        {
            int l = to_string(s[i].second).length();
            if (s[i].first.length() > static_cast<unsigned long long int>(m) || l > m)
            {
                m = max(static_cast<int>(s[i].first.length()), l);
            }
        }
    }
    return m;
}

void hash_table::print_table() const
{
    int m = find_max_len();
    if (m < 7)
    {
        m = 7;
    }
    m += 1;
    cout << setw(m) << "key" << setw(m) << "string" << setw(m) << "int" << endl;
    for (int i = 0; i < n; i++)
    {
        if (set[i] == true)
        {
            cout << setw(m) << i << setw(m) << s[i].first << setw(m) << s[i].second << endl;
        }
    }
}

bool hash_table::add_to_str(string st, int k)
{
    bool counter = false;
    hash_table h1(this->n);
    for (int i = 0; i < n; i++)
    {
        if (set[i] == true)
        {
            if (s[i].first == st)
            {
                h1.insert({s[i].first, s[i].second + k});
                counter = true;
            }
            else
            {
                h1.insert(s[i]);
            }
        }
    }
    this->CopyOnly(h1);
    return counter;
}

bool hash_table::sub_from_str(string st, int k)
{
    bool counter = false;
    hash_table h1(this->n);
    for (int i = 0; i < n; i++)
    {
        if (set[i] == true)
        {
            if (s[i].first == st)
            {
                h1.insert({s[i].first, s[i].second - k});
                counter = true;
            }
            else
            {
                h1.insert(s[i]);
            }
        }
    }
    this->CopyOnly(h1);
    return counter;
}

hash_table read_from_file(string path)
{
    ifstream file(path);
    string word;
    int count = 0;
    if (file.is_open())
    {
        while (file >> word)
        {
            count++;
        }
        file.close();
    }
    else
    {
        hash_table t(0);
        return t;
    }
    hash_table h(count + 1);
    ifstream file1(path);
    if (file1.is_open())
    {   
        while (file1 >> word)
        {
            if (h.find_str(word))
            {
                h.add_to_str(word, 1);
            }
            else
            {
                h.insert({word, 1});
            }
        }
        file1.close();
    }
    else
    {
        hash_table t(0);
        return t;
    }
    return h;
}