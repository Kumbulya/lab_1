#include <iostream>
#include <string>
#include "queue.h"
#include "stack.h"


void init_list(List* ls)
{
    ls->head = NULL;
    ls->tail = NULL;
    ls->size = 0;
}

void QPUSH(List* ls, std::string new_value)
{
    Node* new_node = new Node();
    new_node->value = new_value;
    new_node->next = ls->tail;
    if (ls->size == 0)
    {
        ls->head = new_node;
    }
    else
    {
        ls->tail->next = new_node;
    }
    ls->tail = new_node;
    ls->size++;
}

std::string QPOP(List* ls)
{
    if (ls->size == 0)
    {
        return "Empty queue";
    }
    Node* new_node = ls->head;
    std::string result = ls->head->value;
    if (ls->size == 1)
    {
        ls->head = NULL;
        ls->tail = NULL;
    }
    else
    {
        ls->head = new_node->next;
    }
    delete new_node;
    ls->size--;
    return result;
}
