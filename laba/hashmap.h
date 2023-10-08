#pragma once


#include <iostream>
#include <string>
#include "hashmap.h"


struct Hashtb {
    int key;
    std::string data;
};


int hashFunc(int key);


void init_table_hash(Hashtb* tbl);

void HSET(Hashtb* tbl, int key, std::string data);

void HDEL(Hashtb* tbl, int key);

std::string HGET(Hashtb* tbl, int key);