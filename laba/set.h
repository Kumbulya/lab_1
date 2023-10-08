#pragma once


#include <iostream>
#include <string>
#include "set.h"


struct Set {
    std::string key;
    std::string data;
};

long hashFuncSet(std::string key);
void init_table_set(Set* tbl);
void SADD(Set* tbl, std::string key);
void SREM(Set* tbl, std::string key);
std::string SISMEMBER(Set* tbl, std::string key);