#include <iostream>
#include <string>
#include "stack.h"

void init_stack(Node* head)
{
    head->next = NULL;
}

void SPUSH(Node** head, std::string new_value)
{
    Node* new_node = new Node();
    new_node->value = new_value;
    new_node->next = (*head);
    *head = new_node;
}

std::string SPOP(Node** head)
{
    if ((*head) == NULL)
    {
        return "Empty stack";
    }
    Node* new_node = (*head);
    std::string result;
    result = new_node->value;
    (*head) = new_node->next;
    delete new_node;
    return result;
}
