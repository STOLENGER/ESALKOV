//
// Created by Egor Salkov on 09.05.2020.
//

#include "List.h"
#include "iostream"
using namespace std;


template<typename T>
list<T>::list() {
    size=0;
    head= nullptr;

}
template<typename T>
list<T>::~list(){
    clear();
}

template<typename T>
void list<T>::push_back(T& data) {
    if(head== nullptr)
    {
        head=new Node<T>(data);
    } else
    {
        Node<T>*current= this->head;
        while (current!= nullptr)
        {
            current=current->pNext;
        }
        current->pNext=new Node<T>(data);
    }
    size++;

}

template<typename T>
T &list<T>::operator[](const int index) {
    int  counter=0;
    Node<T> *current= this->head;
    while (current!= nullptr)
    {
        if(counter==index)
        {
            return current->data;
        }
        current=current->pNext;
        counter++;
    }
}

template<typename T>
void list<T>::pop_front() {
    Node<T> *temp=head;
    head=head->pNext;
    delete temp;
    size--;
}

template<typename T>
void list<T>::clear() {
    while (size)
    {
        pop_front();
    }

}

template<typename T>
void list<T>::push_front(T& data) {
    head=new Node<T>(data,head);
    size++;
}

template<typename T>
void list<T>::insert(T& data, int index) {
    if(index==0)
    {
        push_front(data);
    } else
    {
        Node<T> *previous= this->head;
        for (int i = 0; i <index-1 ; ++i)
        {
            previous=previous->pNext;
        }
        Node<T> *newNode=new Node<T>(data,previous->pNext);
        previous->pNext=newNode;
        size++;
    }

}

template<typename T>
void list<T>::removeAt(int index)
{
    if(index==0)
    {
        pop_front();
    } else
    {
        Node<T> *previous= this->head;
        for (int i = 0; i <index-1 ; ++i)
        {
            previous=previous->pNext;
        }
        Node<T> *toDelete=previous->pNext;
        previous->pNext=toDelete->pNext;
        delete  toDelete;
        size--;
    }
}

template<typename T>
void list<T>::pop_back()
{
removeAt(size-1);
}

template<typename T>
T &list<T>::operator[](const int index) const {
    int  counter=0;
    Node<T> *current= this->head;
    while (current!= nullptr)
    {
        if(counter==index)
        {
            return current->data;
        }
        current=current->pNext;
        counter++;
    }
}

template<typename T>
T list<T>::begin() {
    return this->head;
}
template<typename T>
T list<T>::end()
{
    Node<T> *current= this->head;
    while (current!= nullptr)
    {
        current=current->pNext;
    }
    return current;
}


