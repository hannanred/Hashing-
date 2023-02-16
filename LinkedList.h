#ifndef __LIST_H
#define __LIST_H
#include <cstdlib>

/* This class just holds a single data item. */
template <class T>
struct ListItem
{
    T value;
    ListItem<T> *next;
    ListItem<T> *prev;

    ListItem(T theVal)
    {
        this->value = theVal;
        this->next = NULL;
        this->prev = NULL;
    }
};


template <class T>
class LinkedList
{
    ListItem<T> *head;

public:

    // Constructor
    LinkedList();

    // Copy Constructor
    LinkedList(const LinkedList<T>& otherList);

    // Destructor
    ~LinkedList();

    void insertAtHead(T item);
    void insertAtTail(T item);
    void insertAfter(T toInsert, T afterWhat);
    ListItem<T> *getHead();
    ListItem<T> *getTail();
    ListItem<T> *searchFor(T item);
    void deleteItem(T item);
    void deleteHead();
    void deleteTail();
    int length();
};

#endif
