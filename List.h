//
// Created by Egor Salkov on 09.05.2020.
//

#ifndef LAB3_4_OOP_LIST_H
#define LAB3_4_OOP_LIST_H

template <typename T>
class list
{
public:
    list();
    ~list();
    void pop_front();
    void push_back(T& data);
    void clear();
    int GetSize() const {return size;}
    T& operator[](const int index);
    T& operator[](const int index) const ;
    void push_front(T& data);
    void insert(T& data,int index);
    void removeAt(int index);
    void pop_back();
    T begin();
    T end();



private:
    int size;


    template<typename>
    class Node
    {
    public:
        Node *pNext;
        T data;
        Node(T data=T(),Node *pNext= nullptr)
        {
            this->data=data;
            this->pNext=pNext;
        }
    };
    Node<T> *head;
};

#endif //LAB3_4_OOP_LIST_H
