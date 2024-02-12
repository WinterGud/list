#pragma once
#include <memory>
#include <iostream>

template <typename T>
class list
{
private:
    struct node;

public:
    list();
    list(int size);

    class iterator
    {
    public:
        iterator();
        iterator(const iterator& right);
        ~iterator();

        iterator& operator=(const iterator& right);
        bool operator==(const iterator& right);
        bool operator!=(const iterator& right);

        friend std::ostream& operator<<(std::ostream& os, const iterator& it)
        {
            os << it.m_node->item;
            return os;
        }

    private:
        node* m_node;
    };

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
      m_beginNode(nullptr)
      , m_lastNode(nullptr)
{
    std::cout << "default constructor (list);\n";
}

template <typename T>
list<T>::list(int size)
    : m_size(0)
      , m_beginNode(nullptr)
      , m_lastNode(nullptr)
{
    for (int i = 0; i < size; i++)
    {
        this->push_back(T());
    }
    std::cout << "size constructor (list);\n";
}

template <typename T>
list<T>::iterator::iterator()
    : m_node(nullptr)
{
    std::cout << "default constructor (iterator);\n";
}

template <typename T>
list<T>::iterator::iterator(const iterator& right)
{
    if (this == right)
    {
        return *this;
    }
    m_node->item = right.m_node->item;
    m_node->previousNode = right.m_node->previousNode;
    m_node->nextNode = right.m_node->nextNode;
    std::cout << "copy constructor (iterator);\n";
    return *this;
}

template <typename T>
list<T>::iterator::~iterator()
{
    std::cout  << "destructor (iterator);\n";
}

template <typename T>
typename list<T>::iterator& list<T>::iterator::operator=(const iterator& right)
{
    if (this == right)
    {
        return *this;
    }
    m_node->item = right.m_node->item;
    m_node->previousNode = right.m_node->previousNode;
    m_node->nextNode = right.m_node->nextNode;
    std::cout << "operator= (iterator);\n";
    return *this;
}

template <typename T>
bool list<T>::iterator::operator==(const iterator& right)
{
    if (m_node->item != right.m_node->item ||
        m_node->previousNode != right.m_node->previousNode ||
        m_node->nextNode != right.m_node->nextNode)
    {
        return false;
    }
    return true;
}

template <typename T>
bool list<T>::iterator::operator!=(const iterator& right)
{
    return !(this == right);
}

template <typename T>
void list<T>::push_back(const T& elem)
{
    node* newNode = new node;
    newNode->item = elem;
    newNode->previousNode = m_lastNode;

    if (m_size == 0)
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
    : nextNode(nullptr)
      , previousNode(nullptr)
{
}
