#pragma once
#include <iostream>
#include <string>
#include "stack.h"

struct Node {
    std::string value;
    Node* next;
};

void init_stack(Node* head);
void SPUSH(Node** head, std::string new_value);
std::string SPOP(Node** head);
