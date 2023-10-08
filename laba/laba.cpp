#include <iostream>
#include <string>
#include <fstream>

#include "hashmap.h"
#include "queue.h"
#include "set.h"
#include "stack.h"

#include <map>

extern const int capacity = 200; 

int main() {
	std::string command, container_name;

	std::map<std::string, Node*> Stacks;
	std::map<std::string, List*> Queues;

	Set MySet[capacity];
	Hashtb MyHash[capacity];
	init_table_hash(MyHash);
	init_table_set(MySet);
	List* Queue;
	Node* Stack;
	while (1)
	{
		std::string line;
		getline(std::cin, line);
		std::string words[4];
		std::string word = "";
		int j = 0;
		for (size_t i = 0; i < line.length(); i++)
		{
			if (i == line.length() - 1)
			{
				word += line[i];
				words[j++] = word;
				word = "";
				continue;
			}
			if (line[i] == ' ')
			{
				words[j++] = word;
				word = "";
				continue;
			}
			word += line[i];
		}

		command = words[0];
		container_name = words[1];


		if (command[0] == 'S' && command[1] == 'P')			//Stack
		{
			std::map <std::string, Node*>::iterator it;
			it = Stacks.find(container_name);
			if (it != Stacks.end())
			{
				Stack = it->second;
				if (command == "SPUSH")
				{
					SPUSH(&Stack, words[2]);
					Stacks[container_name] = Stack;
				}
				else if (command == "SPOP")
				{
					std::cout << SPOP(&Stack) << '\n';
					Stacks[container_name] = Stack;
				}
				else
				{
					std::cout << "Unknown command!" << '\n';
				}
			}
			else
			{
				Stack = new Node();
				init_stack(Stack);
				if (command == "SPUSH")
				{
					SPUSH(&Stack, words[2]);
				}
				else if (command == "SPOP")
				{
					std::cout << "Error" << '\n';
				}
				else
				{
					std::cout << "Unknown command!" << '\n';
				}
				Stacks.insert(make_pair(container_name, Stack));
			}
		}
		else if (command[0] == 'Q')			//Queue
		{
			std::map<std::string, List*>::iterator it;
			it = Queues.find(container_name);
			if (it != Queues.end())
			{
				Queue = it->second;

				if (command == "QPUSH")
				{
					QPUSH(Queue, words[2]);
					Queues[container_name] = Queue;
				}
				else if (command == "QPOP")
				{
					std::cout << QPOP(Queue) << '\n';
					Queues[container_name] = Queue;
				}
				else
				{
					std::cout << "Unknown command!" << '\n';
				}
			}
			else
			{
				Queue = new List();
				init_list(Queue);
				if (command == "QPUSH")
				{
					QPUSH(Queue, words[2]);
				}
				else if (command == "QPOP")
				{
					std::cout << "Error" << '\n';
				}
				else
				{
					std::cout << "Unknown command!" << '\n';
				}
				Queues.insert(make_pair(container_name, Queue));
			}

			continue;
		}

		else if (command[0] == 'S')			//Set
		{

			if (command == "SADD")
			{
				SADD(MySet, words[1]);
			}
			else if (command == "SREM")
			{
				SREM(MySet, words[1]);
			}
			else if (command == "SISMEMBER")
			{
				std::cout << SISMEMBER(MySet, words[1]) << '\n';
			}
			else
			{
				std::cout << "Unknown command!" << '\n';
			}
			continue;
		}
		else if (command[0] == 'H')			//Hash
		{
			if (command == "HSET")
			{
				HSET(MyHash, stoi(words[1]), words[2]);
			}
			else if (command == "HDEL")
			{
				HDEL(MyHash, stoi(words[1]));
			}
			else if (command == "HGET")
			{
				std::cout << HGET(MyHash, stoi(words[1])) << '\n';
			}
			else
			{
				std::cout << "Unknown command!" << '\n';
			}
			continue;
		}
	}
	
}