#ifndef __LIST_CPP
#define __LIST_CPP
#include <iostream>
#include <cstdlib>
#include "LinkedList.h"
using namespace std;
template <class T>
LinkedList<T>::LinkedList()
{	
	
	head=NULL;

}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& otherLinkedList)
{	
	
	if (otherLinkedList.head==NULL)
	{
		
		head==NULL;	
	}

	else if (otherLinkedList.head->next==NULL)

	{
		
		insertAtHead(otherLinkedList.head->value);
	}
	
	else 

	{  
		insertAtHead(otherLinkedList.head->value);

		ListItem<T> * current=otherLinkedList.head;
		head=new ListItem <T>(getHead()->value);

		ListItem<T>*previous_=head;
		ListItem<T> *current_newnode;

		while ( current->next!=NULL)
		{
			current= current->next;
			current_newnode=new ListItem<T>( current->value);
			previous_->next=current_newnode;
			current_newnode->prev=previous_;
			previous_=current_newnode;
		}
			
	}

}

template <class T>
LinkedList<T>::~LinkedList()
{
	ListItem<T>* currentnode=head;
	ListItem<T>* temp;

	if (head==NULL)
	{
		return;
	}

	else if(head->next==NULL) 
	{
		delete head;
		head=NULL;
	}

	else 
	{
		while (currentnode->next!=NULL)
		{
			temp=currentnode;
			currentnode=currentnode->next;
			delete temp;
		}
		temp=NULL;
		delete currentnode;
		currentnode=NULL;
	}
}

template <class T>
void LinkedList<T>::insertAtHead(T item)
{
	if (head==NULL)
	{
		head=new ListItem<T>(item);
	}

	else 
	{	ListItem<T> *newnode = new ListItem<T>(item);

	 	newnode->prev=NULL;
	 	newnode->next=head;

	 	head->prev=newnode;
	 	head=newnode;
	}
}

template <class T>
void LinkedList<T>::insertAtTail(T item)
{
	if (head==NULL)
	{
		head=new ListItem<T>(item);
	}
	else 
	{
		ListItem<T>* tail=getTail();
	
		ListItem<T> *newnode = new ListItem<T>(item);

		newnode->next=NULL;
		newnode->prev=tail;

		tail->next=newnode;
		tail=newnode;
	}



}

template <class T>
void LinkedList<T>::insertAfter(T toInsert, T afterWhat)
{	
	 ListItem<T> *current_node=head;
	 ListItem<T> *previousnode;
	
	if ((head->value==afterWhat) && (head->next==NULL)) 
	{
		ListItem<T> *newnode=new ListItem<T>(toInsert);
		newnode->next=NULL;
		newnode->prev=head;
		head->next=newnode; 
		
	}
	else if (getTail()->value==afterWhat)
	{	
		insertAtTail(toInsert);

	}

	else 
	{  	
		bool Found=false;
		while ((current_node->next!=NULL) && (Found==false))
		{	
			if (current_node->value==afterWhat)
			{	
				previousnode=current_node;
				current_node=current_node->next;
				Found=true;
				ListItem<T> *newnode=new ListItem<T>(toInsert);
				previousnode->next=newnode;
				current_node->prev=newnode;

				newnode->next=current_node;
				newnode->prev=previousnode;
			}
			else 

			{
				current_node=current_node->next;
			}

		}

	}

}

template <class T>
ListItem<T>* LinkedList<T>::getHead()
{	
	return head;
}

template <class T>
ListItem<T>* LinkedList<T>::getTail()
{	

	if (head==NULL)
	{
		return NULL;
	}
	else 
	{
		ListItem<T>* tail;
		tail=head;

		while(tail->next!=NULL)
		{
			tail=tail->next;
		}
		return tail;
	}

}

template <class T>
ListItem<T> *LinkedList<T>::searchFor(T item)
{	
	if (head==NULL)
	{
		return NULL;
	}

	else if (head->value==item)
	{
		return head;
	}

	else if (getTail()->value==item)
	{
		return getTail();
	}
	else 
	{	 ListItem<T> *current_node=head;
		while(current_node->next!=NULL)
		{
			if (current_node->value==item)
			{
				return current_node;
			}

			else 
			{
				current_node=current_node->next;
			}	
		}

		return NULL;
	}
}

template <class T>
void LinkedList<T>::deleteItem(T item)
{
	if (head->value==item)
	{	
		deleteHead();
	}

	else if (getTail()->value==item)
	{	
		deleteTail();
	}

	else
	{ 	
		ListItem<T> *current=searchFor(item);
		
		if (current==NULL)
		{
			return ;
		}

		else 
		{  
			ListItem<T> *previous_=current->prev;
			ListItem<T> *nextnode=current->next;
			previous_->next=nextnode;
			nextnode->prev=previous_;
			delete current;
			current=NULL;
			return;
		}
	}
}

template <class T>
void LinkedList<T>::deleteHead()
{	
	ListItem<T> *current_node=head;
	if (head->next==NULL) 
	{
		delete head;
		head=NULL;

	}
	else 
	{	
		 head=head->next;
		 head->prev=NULL;
		 delete current_node;
		 current_node=NULL;
	}
}

template <class T>
void LinkedList<T>::deleteTail()
{
	if (getTail()->prev==NULL) 
	{
		ListItem<T> *current_tail;
		current_tail=getTail();
		delete current_tail;
		head=NULL;
	}

	else 
	{	
		ListItem<T> *current_tail;
		current_tail=getTail();
		ListItem<T> *previousnode=current_tail->prev;
		previousnode->next=NULL;
		delete current_tail;
		current_tail=NULL;

	}
}

template <class T>
int LinkedList<T>::length()
	 
{
	ListItem<T> *current_node=head;

	if (head->next==NULL)
	{
		return 1;
	}
	else if (head==NULL)
	{
		return 0;
	}
	else 	
	{	int counter=0;

		while (current_node->next!=NULL)
		{
			counter = counter + 1;
			current_node=current_node->next;
		}
		counter = counter + 1;
		return counter;
	}

}

#endif
