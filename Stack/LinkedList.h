#ifndef LINKEDLIST_H
#define LINKEDLIST_H

using namespace std;

// Representation of an element in the linked list
template<class T>
struct Node
{
    T val; // Value of the node
    Node *next; // Pointer to the next node
};

template<class T>
class LinkedList
{
    // Public Functions/Variables
    public:
        /* IMPLEMENT THESE FUNCTIONS FOR EXERCISE1 */
        LinkedList(); // Constructor
        ~LinkedList(); // Destructor
        void insertAtBack(T valueToInsert);
        bool removeFromBack();
        void print();
        bool isEmpty();
        int size();
        void clear();

        /* IMPLEMENT THSES FUNCTIONS FOR EXERCISE2 */
        void insertAtFront(T valueToInsert);
        bool removeFromFront();
        T tip(); // top

        Node<T> *first; // Pointer pointing to the begining of the list
        Node<T> *last; // Pointer pointing to the end of the list
};

template<class T> LinkedList<T>::LinkedList(){ //constructor
    first = NULL;
    last = NULL;
}

template<class T> LinkedList<T>::~LinkedList(){ // desctructor
    // call the clear function
    clear();
}

template<class T> void LinkedList<T>::insertAtBack(T valueToInsert){
    Node<T>* newnode = new Node<T>();
    newnode -> val = valueToInsert;
    
    /*
     Object representation ref (for personal reference)
     node : {
     val: valueToInsert
     next: NULL (or whatever is the next)
     }
     }
     
     
     */
    
    if(first == NULL){ // if the initial value is null (aka this is a clean linked list)
        first = newnode; // both values point to the same element
        last = newnode;
    } else { //  if it's not a clean list
        last -> next = newnode; //  sets the next value as a new node
        newnode -> next = NULL; // then sets the next value as the first value
        last = newnode; // then sets the last value to point to the next value
    }
}

template<class T> bool LinkedList<T>::removeFromBack(){
    Node<T>* thisnode = first; // inits new node to first
    Node<T>* prevnode = thisnode;
    
    if(first == NULL){ // you can't remove something that doesn't exist
        return false;
    } else if( last == first){ //completely destroys the linked list since there's only one element
        delete thisnode;
        last = NULL;
        first = NULL;
    } else {
        while( thisnode -> next != NULL){ // goes through the linked list until last node
            prevnode = thisnode; // sets prevnode to the last node
            thisnode = thisnode -> next; // sets that node to next
        }
        delete thisnode;
        last = prevnode;
        prevnode -> next = NULL;
    }
    return true;
}

template<class T> void LinkedList<T>::print(){
    Node<T>* thisnode = first;
    
    while(thisnode != NULL){
        cout << thisnode -> val; // prints out the value
        if(thisnode -> next != NULL){
            cout << ", ";
        }
        thisnode = thisnode -> next; // goes to the next linked object
    }
}

template<class T> bool LinkedList<T>::isEmpty(){ // checked if list is empty
    return (first == NULL); // if first is empty, it's gotta be empty
}

template<class T> int LinkedList<T>::size(){ // gets the size of the linked list
    // traverses the linked list and adds a number
    Node<T> * thisnode = first; // sets it as an initial order
    int count = 0;
    while( thisnode != NULL)
    {
        count++;
        thisnode = thisnode-> next; // goes to the next linked object
        
    }
    return count;
    
}

template<class T> void LinkedList<T>::clear(){ // clears the linked list
    while(!isEmpty()) //loops until empty
        removeFromFront();
}

template<class T> T LinkedList<T>::tip(){ // moves to the top
    if(first == NULL)
        return false;
    Node<T>* mynode = last;
    return mynode -> val;
}




template<class T> void LinkedList<T>::insertAtFront(T valueToInsert){ // inserts a value at the front
    
    Node<T>* newnode = new Node<T>(); // initializes the new node
    newnode -> val = valueToInsert; // gets that value
    newnode -> next = first; // pushes the old first to the next value
    first = newnode; // sets the initial value
}

template<class T> bool LinkedList<T>::removeFromFront(){ // removes the value from the front
    if(first == NULL) // if it's empty then dont do anything
        return false;
    Node<T> * thisnode = first; // defines thisnode
    first = thisnode -> next; // sets the first to the next, since we're shifting up
    delete thisnode; // deletes the node
    return true;
}




#endif

