#pragma once
#include <iostream>
#include <string>
#include "queue.h"
#include "stack.h"


struct List {
    Node* head;
    Node* tail;
    size_t size;
};

void init_list(List* ls);

void QPUSH(List* ls, std::string new_value);

std::string QPOP(List* ls);
