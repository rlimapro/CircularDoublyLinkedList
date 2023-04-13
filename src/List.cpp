#include "List.h"
#include <iostream>
#include <stdexcept>

List::List() : m_size(0) 
{
    sentinel = new Node();
    head = sentinel;
}

List::List(const List& lst)
{
    // Inicialização da sentinela
    sentinel = new Node();
    Node *current = lst.sentinel->next;
    while(current != lst.sentinel)
    {
        push_back(current->data);
        current = current->next;
    }
    m_size = lst.m_size;
}

List::~List()
{
    clear();
    std::cerr << "Destroyed list\n";
}

bool List::empty() const 
{
    if(sentinel->next == sentinel)
    {
        return true;
    }
    else {return false;}
}

size_t List::size() const {return m_size;}

void List::clear() 
{
    // Enquanto a lista for != de vazia
    // será removido o  último elemento    
    while(!this->empty()) this->pop_back();
}

Item& List::front() 
{
    if(empty())
    {
        throw std::underflow_error("Empty list!");
    }
    return sentinel->next->data;
}

Item& List::back() 
{
    if(sentinel->next == sentinel)
    {
        throw std::underflow_error("Empty list!");
    }
    return sentinel->prev->data;
}

void List::push_front(const Item& data)
{
    Node *novo       = new Node(data);
    novo->next       = sentinel->next;
    sentinel->next   = novo;
    novo->prev       = sentinel;
    novo->next->prev = novo;
    m_size++;
}

void List::push_back(const Item& data)
{
    Node *novo       = new Node(data);
    novo->next       = sentinel;
    novo->prev       = sentinel->prev;
    novo->prev->next = novo;
    sentinel->prev   = novo;
    m_size++;
}

void List::pop_front()
{
    if(empty())
    {
        throw std::underflow_error("Empty list!");
    }
    Node *aux       = sentinel->next;
    sentinel->next  = aux->next;
    aux->next->prev = sentinel;
    delete aux;
    m_size--;
}

void List::pop_back()
{
    if(empty())
    {
        throw std::underflow_error("Empty list!");
    }
    Node *last       = sentinel->prev;
    sentinel->prev   = last->prev;
    last->prev->next = sentinel;
    delete last;
    m_size--;
}

void List::insertAt(const Item& data, int index)
{
    if(index < 0 || index > m_size) 
    {
        throw std::out_of_range("Invalid index!");
    }
    if(index == 0) // Caso 1: Inserção no início da lista
    {
        Node *novo = new Node(data);
        novo->next = sentinel->next;
        novo->prev = sentinel;
        sentinel->next->prev = novo;
        sentinel->next = novo;
        m_size++;
        return;
    }
    // Caso 2: Inserção nos índices 1+
    Node *novo = new Node(data);
    Node *aux  = sentinel->next;
    int cont   = 0;
    // Laço  com  auxilio  de contador para
    // parar na posição correta de inserção
    while (cont < index-1)
    {
        aux = aux->next;
        cont++;
    }
    novo->next      = aux->next;
    novo->prev      = aux;
    aux->next->prev = novo;
    aux->next       = novo;
    m_size++;
}

void List::removeAt(int index)
{
    if(index < 0 || index > m_size) 
    {
        throw std::out_of_range("Invalid index!");
    }
    // Caso especial com index no índice 0
    if(index == 0) 
    {
        Node *out       = sentinel->next;
        out->next->prev = sentinel;
        sentinel->next  = out->next;
        delete out;
        m_size--;
        return;
    }
    Node *aux = sentinel->next;
    int cont  = 0;
    // Laço com a mesma lógica da função insertAt
    // porém dessa vez com o intuito de remover o
    // elemento.
    while(cont < index - 1)
    {
        aux = aux->next;
        cont++;
    }
    Node *out       = aux->next;
    out->next->prev = aux;
    aux->next       = out->next;
    delete out;
    m_size--;
}

void List::removeAll(const Item& data)
{
    if(empty()) 
    {
        throw std::underflow_error("empty list");
    }
    Node *current = sentinel->next;
    while(current != sentinel)
    {
        if(current->data == data)
        {
            // Caso onde (Item data == data) e está na primeira posição
            if(current->prev == sentinel) 
            {
                sentinel->next = current->next;
                current->next->prev = current->prev;
                delete current;
                m_size--;
                current = sentinel->next;
            }
            // trecho para o restante dos casos onde (Item data == data)
            // pode estar nas demais posições
            else
            {
                current->next->prev = current->prev;
                current->prev->next = current->next;
                Node *aux = current->next;
                delete current;
                m_size--;
                current = aux;
            } 
        }
        // Se não for, então anda pro próximo elemento
        else {current = current->next;}
    }
}

void List::swap(List& lst)
{
    // Simplesmente trocando as sentinelas e sizes
    Node *aux    = sentinel;
    sentinel     = lst.sentinel;
    lst.sentinel = aux;
    size_t size  = m_size;
    m_size       = lst.m_size;
    lst.m_size   = size;
}

void List::concat(List& lst)
{
    if(lst.empty())
    {
        throw std::underflow_error("empty list");
    }
    Node *current = lst.sentinel->next;
    while(current != lst.sentinel)
    {
        // utilizando push_back() para inserir os
        // nós de lst no final da lista original
        push_back(current->data);
        current = current->next;
    }
    lst.clear();
}

List *List::copy()
{  
    // Nova lista 
    List *list    = new List();   
    Node *current = this->sentinel->next;
    while(current != sentinel)
    {
        // copiando a partir do primeiro item
        list->push_back(current->data);
        current = current->next;
    }
    return list;
}

void List::append(Item vec[], int n)
{
    for(int i = 0; i < n; i++)
    {
        push_back(vec[i]);
    }
}

bool List::equals(const List& lst) const
{
    if(m_size != lst.m_size) 
    {
        return false;
    }
    // Current e  otherCurrent  apontando  para  o  início
    // de cada lista respectivamente.
    Node *current      = sentinel->next;
    Node *otherCurrent = lst.sentinel->next;

    while(current->next != sentinel)
    {
        // Como temos o início de ambas as listas, podemos
        // comparar item a item se há algum diferente.
        if(current->data != otherCurrent->data)
        {
            return false;
        }
        current      = current->next;
        otherCurrent = otherCurrent->next;
    }
    // Retorna true apenas se chegar até esta linha
    return true;
}

void List::reverse()
{
    if(sentinel->next == sentinel)
    {
        throw std::underflow_error("empty list");
    }
    Node *aux = sentinel->next;
    Node *nex = sentinel->next;
    // Laço para percorrer a lista e inverter
    // next por prev em cada nó.
    while(aux != sentinel)
    {
        Node *out = aux->next;
        aux->next = aux->prev;
        aux->prev = out;
        aux = aux->prev;
    }
    // Ao final, bastar inverter a sentinela
    sentinel->next = sentinel->prev;
    sentinel->prev = nex;
}

void List::merge(List& lst)
{
    int cont = 0;
    if(lst.empty()) 
    {
        throw std::out_of_range("empty list");
    }
    else if(empty()) 
    {
        *this = lst, lst.clear();
    }
    else
    {
        Node *current = lst.sentinel->next;
        // i começando em 1 para não ocupar o primeiro indíce e sendo encrementado
        // em +2 para ser inserido de forma intercalada na lista original.
        for(int i = 1; i < m_size; i+=2)
        {
            insertAt(current->data, i);
            current = current->next;
            cont++;
        }
        // se restar elementos de lst, basta inseri-los ao final na ordem que estão.
        if(cont < lst.m_size)
        {
            // (lst.m_size - cont) pois queremos somente o que restou
            for(int i = 0; i < lst.m_size-cont; i++)
            {
                push_back(current->data);
                current = current->next;
            }
        }
        lst.clear();
    }
}

Ost& operator<<(Ost& out, const List& lst) 
{
    out << "(" <<  lst.m_size << " elements) ";
    if(lst.empty())
    {
        // se a lista está vazia então não há necessidade
        // de continuar esta função, dessa forma, retorna
        // apenas o número de elementos (zero).
        out << "\n";
        return out;
    }
    Node *temp = lst.sentinel->next;
    out << "[ ";
    while(temp != lst.sentinel)
    {
        out << "(" << temp->data << ") ";
        temp = temp->next;
    }
    out << "]\n";
    return out;
}

Item& List::operator[](int index)
{
    if(index < 0 || index >= m_size) 
    {
        throw std::out_of_range("Invalid index");
    }
    int cont = 0;
    Node *aux = sentinel->next;
    while(cont < index)
    {
        aux = aux->next;
        cont++;
    }
    return aux->data;
} 

List& List::operator=(const List& lst)
{
    if(lst.empty())
    {
        return *this;
    }
    // Lista que receberá os elementos deve ser esvaziada
    clear();
    Node *aux = lst.sentinel->next;
    while(aux->next != lst.sentinel)
    {
        push_back(aux->data);
        aux = aux->next;
    }
    m_size = lst.m_size;

    return *this;
}
