#ifndef LIST_H
#define LIST_H
#include <iostream>

using Ost = std::ostream;

using Item = int;
struct Node
{
    Item data;
    Node *next;
    Node *prev;

    Node() : next(this), prev(this) { } // Sentinel constructor

    Node(Item data) : data(data) {next = nullptr, prev = nullptr;}
};

class List 
{
    private:
        size_t m_size;
        Node *sentinel;
        Node *head;

    public:
        List(); 
        List(const List& lst); // Copy constructor
        ~List(); 

    public:
        // Member functions
        bool empty() const;
        size_t size() const; 
        void clear();
        Item& front();
        Item& back();
        void push_front(const Item& data);
        void push_back(const Item& data);
        void pop_front();
        void pop_back();
        void insertAt(const Item& data, int index);
        void removeAt(int index);
        void removeAll(const Item& data);
        void swap(List& lst);
        void concat(List& lst);
        List *copy();
        void append(Item vec[], int n);
        bool equals(const List& lst) const;
        void reverse();
        void merge(List& lst);
        // Operators 
        friend Ost& operator<<(Ost& out, const List& lst);
        Item& operator[](int index);
        List& operator=(const List& lst); 
};

#endif