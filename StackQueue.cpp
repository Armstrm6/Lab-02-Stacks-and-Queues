// StackQueues.cpp : Defines the exported functions for the DLL application.
//

#include "StackQueue.h"


int ArrayBasedStack::peek()
{
	if (this->isEmpty())
	{
		throw "ADT is emtpy";
	}
	else
	{
		return m_array[top];
	}
}

bool ArrayBasedStack::pop()
{

	if(this->isEmpty()){
		return false;
	}
		top--;
		return true;

}

bool ArrayBasedStack::push(int val)
{
		if(top < capacity -1){
			top++;
			m_array[top] = val;
			return true;
		}else{
			return false;
		}
}


ArrayBasedStack::ArrayBasedStack() : top(-1){
//default constructor
}

ArrayBasedStack::~ArrayBasedStack(){
//default destructor
}

bool ArrayBasedStack::isEmpty() const{
	//used book to help simplify and condense code
	return top < 0;
}

std::string ArrayBasedStack::toString(){
	std::string str = "";
	
	for(int i = top; i >= 0; i--){
		if(str == ""){
			str = std::to_string(m_array[i]); 
		}else{
			str = str + " " + std::to_string(m_array[i]);
		}
	}

	return str;
}

int ArrayBasedStack::getSizeS(){
	if(this->isEmpty()){
		return 0;
	}else{
		return top;
	}
}


ArrayBasedQueue::ArrayBasedQueue(): numTerms(-1){
	//same construtor as the stack based queue
}

ArrayBasedQueue::~ArrayBasedQueue(){

}

bool ArrayBasedQueue::isEmpty() const{
	//same code as stack implementation
	return numTerms < 0;
}

bool ArrayBasedQueue::enQueue(std::string val)
{
	if(numTerms < capacity - 1){
		numTerms++;
		m_array[numTerms] = val;
		return true;
	}else{
		return false;
	}
	

}

bool ArrayBasedQueue::deQueue()
{
	if(numTerms < 0){
		return false;
	}else{
		numTerms--;
		for(int i = 0; i <= numTerms; i++){
			m_array[i] = m_array[i+1];
		}
		m_array[numTerms + 1] = "";
		return true;
	}
	
}

int ArrayBasedQueue:: getSizeQ(){
	if(this->isEmpty()){
		return 0;
	}else{
		return numTerms;
	}
}

std::string ArrayBasedQueue::peekFront()
{
	if (this->isEmpty())
	{
		throw "ADT is emtpy";
	}
	else
	{
		return m_array[0];
	}
}
