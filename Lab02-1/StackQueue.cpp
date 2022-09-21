// StackQueues.cpp : Defines the exported functions for the DLL application.
//
#include "iostream"
#include "StackQueue.h"
#include "ctype.h"

using namespace std;

ArrayBasedStack::ArrayBasedStack()
{
	s_size = 100;
	s_vals = new int[s_size];

	for(int i = 0; i <= s_size - 1; i++)
	{
		s_vals[i] = 0;
	}

	s_front = 0;
	s_last = 0;
}

ArrayBasedStack::~ArrayBasedStack()
{
	delete[] s_vals;
}

bool ArrayBasedStack::isEmpty() const
{
	if(s_last == 0)
	{
		return true;
	}
	return false;

}

bool ArrayBasedStack::push(const int &val)
{
	s_vals[s_last] = val;
	++s_last;
	return true;
	
}

bool ArrayBasedStack::pop()
{
	if(!isEmpty() && s_last != 0)
	{

		for(int i = 0; i >= s_last - 1; i--)
		{
			s_vals[i] = s_vals[i + 1];
		}

		s_vals[s_last] = 0;
		--s_last;
	
		return true;
	}
	return false;
}

int ArrayBasedStack::peek() const
{
	if (this->isEmpty())
	{
		throw "ADT is emtpy";
	}
	else
	{
		return s_vals[s_last - 1];
	}
	return 0;

}

std::string ArrayBasedStack::toString() const
{
	string temp_str = "";

	for(int i = 0; i <= s_last; i++)
	{
		temp_str += to_string(s_vals[i]);
	}

	return temp_str;
}



ArrayBasedQueue::ArrayBasedQueue() //constructor
{
	q_size = 100;
	q_vals = new string[q_size];
	q_last = 0;
}

bool ArrayBasedQueue::isEmpty() const
{
	if(q_last == 0)
	{
		return true;
	}
	return false;
}

bool ArrayBasedQueue::enQueue(const std::string &val)
{
	q_vals[q_last] = val;
	++q_last;
	return true;
}

bool ArrayBasedQueue::deQueue()
{
	if(!isEmpty())
	{
		for(int i = 0; i <= q_last - 1; i++)
		{
			q_vals[i] = q_vals[i + 1];
		}

		q_vals[q_last] = "";
		--q_last;

		return true;
	}
	return false;
}

std::string ArrayBasedQueue::peek() const
{
	if (this->isEmpty())
	{
		throw "ADT is emtpy";
	}
	else
	{
		return q_vals[0];
	}


}

std::string ArrayBasedQueue::toString() const
{
	return 0;
}

ArrayBasedQueue::~ArrayBasedQueue()
{
	delete[] q_vals; 
}