#include <iostream>
#include <string>
#include "set.h"

extern const int capacity;

long hashFuncSet(std::string key)
{
    long hash = 5381;
    for (int i = 0; i < key.length(); i++)
    {
        hash = ((hash << 5) + hash);
    }
    return hash;
}

void init_table_set(Set* tbl)
{
    for (int i = 0; i < capacity; i++)
    {
        tbl[i].key = '0';
        tbl[i].data = '0';
    }
}

void SADD(Set* tbl, std::string key)
{
    int index = hashFuncSet(key);
    if (tbl[index % capacity].key == "0")
    {
        tbl[index % capacity].key = key;
        std::cout << "Key " << key << " has inserted" << '\n';
    }
    else
    {
        std::cout << "Hash collision" << '\n';
    }
}

void SREM(Set* tbl, std::string key)
{
    int index = hashFuncSet(key);
    std::string value;
    if (tbl[index % capacity].key == "0")
    {
        return ;
    }
    else
    {
        value = tbl[index % capacity].key;
        tbl[index % capacity].key = "0";
    }
}

std::string SISMEMBER(Set* tbl, std::string key)
{
    int index = hashFuncSet(key);
    if (tbl[index % capacity].key == "0")
    {
        return "No";
    }
    else
    {
        if (tbl[index % capacity].key == key)
        {
            return "Yes";

        }
    }
}