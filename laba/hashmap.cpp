#include <iostream>
#include <cmath>
#include <string>
#include "hashmap.h"

extern const int capacity;

int hashFunc(int key)
{
    return (key % capacity);
}

void init_table_hash(Hashtb* tbl)
{
    for (int i = 0; i < capacity; i++)
    {
        tbl[i].key = 0;
        tbl[i].data = '0';
    }
}

void HSET(Hashtb* tbl, int key, std::string data)
{
    int index = hashFunc(key);
    if (tbl[index].data == "0")
    {
        tbl[index].key = key;
        tbl[index].data = data;
        std::cout << "Key " << key << " has inserted" << '\n';
    }
    else
    {
        std::cout << "Hash collision" << '\n';
    }
}

void HDEL(Hashtb* tbl, int key)
{
    int index = hashFunc(key);
    std::string value;
    if (tbl[index].data == "0")
    {
        std::cout << "No such key exists" << '\n';
        return ;
    }
    else
    {
        value = tbl[index].data;
        tbl[index].key = 0;
        tbl[index].data = "0";
    }
    return ;
}

std::string HGET(Hashtb* tbl, int key)
{
    int index = hashFunc(key);
    if (tbl[index].data == "0")
    {
        return "No such key exists";
    }
    else
    {
        return tbl[index].data;
    }
}