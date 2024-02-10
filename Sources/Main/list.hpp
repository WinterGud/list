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
        return m_lastNode->m_item;
    }
    
private:
    struct node
    {
        node* m_nextNode;
        node* m_previousNode;
        T m_item;
        node();
    };

    int m_size;
    node* m_beginNode; 
    node* m_lastNode;
    
};

template <typename T>
list<T>::list()
    : m_size(0), m_beginNode(nullptr), m_lastNode(nullptr)
{
}

template <typename T>
list<T>::list(int size)
    : m_size(size), m_lastNode(nullptr), m_beginNode(nullptr)
{
    node newNode = new node;
    newNode.m_item = 0;
}

template <typename T>
void list<T>::push_back(const T& elem)
{
    if(m_size == 0)
    {
        node* newNode = new node;
        newNode->m_item = elem;
        newNode->m_previousNode = m_lastNode;
        m_lastNode = newNode;
        m_beginNode = newNode;
    }
    else
    {
        node* newNode = new node;
        newNode->m_item = elem;
        newNode->m_previousNode = m_lastNode;
        m_lastNode = newNode;
    }
}

template <typename T>
list<T>::node::node()
    : m_nextNode(nullptr), m_previousNode(nullptr)
{
}
