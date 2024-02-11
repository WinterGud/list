#pragma once
#include <memory>

class node;

template <typename T>
class list
{
public:
    list();
    list(int size);
    
    
    int size() const { return m_size; }
    void push_back(const T& elem);
    T& last()
    {
        return m_lastNode->item;
    }
    
private:
    struct node
    {
        node* nextNode;
        node* previousNode;
        T item;
        node();
    };

    int m_size;
    node* m_beginNode; 
    node* m_lastNode;
    
};

template <typename T>
list<T>::list()
    : m_size(0),
      m_beginNode(nullptr),
      m_lastNode(nullptr)
{
}

template <typename T>
list<T>::list(int size)
    : m_size(0),
      m_beginNode(nullptr),
      m_lastNode(nullptr)
{
    for (int i = 0; i < size; i++)
    {
        this->push_back(0);
    }
}

template <typename T>
void list<T>::push_back(const T& elem)
{
    node* newNode = new node;
    newNode->item = elem;
    newNode->previousNode = m_lastNode;
    
    if(m_size == 0)
    {
        m_beginNode = newNode;
    }
    else
    {
        m_lastNode->nextNode = newNode;
    }
    m_lastNode = newNode;
    m_size++;
}

template <typename T>
list<T>::node::node()
    : nextNode(nullptr),
      previousNode(nullptr)
{
}
