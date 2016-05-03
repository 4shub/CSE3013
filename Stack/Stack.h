// Stack.h

#ifndef _STACK_H
#define _STACK_H

#include "LinkedList.h"

using namespace std;



template<class T>
class Stack : public LinkedList<T>{
	public:
	Stack(); //Constructor
	~Stack(); //Destructor
	void push(T value); //Inserts a new element at the front of the stack
	T pop(); //Removes the first element of the Stack. It also returns the element poppped
	T top(); //returns a reference to the top element of the stack
};


// Constructor
template<class T> Stack<T>::Stack(){
    //
}

// Destructor
template<class T> Stack<T>::~Stack(){
		  //
}

//Inserts a value at the beginning
template<class T> void Stack<T>::push(T value){
    LinkedList<T>::insertAtBack(value);
}

//Removes a value from the beginning
template<class T> T Stack<T>::pop(){
    return LinkedList<T>::removeFromBack();
}

template<class T> T Stack<T>::top(){
    return LinkedList<T>::tip();
}


#endif


