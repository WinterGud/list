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
    ~list();

    class iterator
    {
    public:
        iterator();
        iterator(const iterator& right);
        iterator(node* right);
        ~iterator();

        iterator& operator=(const iterator& right);
        bool operator==(const iterator& right) const;
        bool operator!=(const iterator& right) const;
        iterator& operator++(T);
        iterator& operator--(T);
        iterator& operator++();
        iterator& operator--();
        friend void erase(const iterator&);
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
    void pop_back();
    iterator& begin();
    iterator& end();
    void insert(const iterator& it, const T& val);
    void erase(const iterator& it);
    

    T& front();
    T& back();

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
list<T>::~list()
{
    std::cout << "destructor (list);\n";
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
    m_node = right.m_node;
    std::cout << "copy constructor (iterator);\n";
}

template <typename T>
list<T>::iterator::iterator(node* right)
{
    m_node = right;
}

template <typename T>
list<T>::iterator::~iterator()
{
    std::cout << "destructor (iterator);\n";
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
bool list<T>::iterator::operator==(const iterator& right) const
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
bool list<T>::iterator::operator!=(const iterator& right) const
{
    if (m_node->item == right.m_node->item ||
        m_node->previousNode == right.m_node->previousNode ||
        m_node->nextNode == right.m_node->nextNode)
    {
        return false;
    }
    return true;
}

template <typename T>
typename list<T>::iterator& list<T>::iterator::operator++(T)
{
    if(m_node->nextNode == nullptr)
    {
        throw "error";
    }
    iterator temp(m_node);
    this->operator++();
    return std::move(temp);
}


template <typename T>
typename list<T>::iterator& list<T>::iterator::operator--(T)
{
    if(m_node->previousNode == nullptr)
    {
        throw "error";
    }
    iterator temp(m_node);
    this->operator--();
    return std::move(temp);
}

template <typename T>
typename list<T>::iterator& list<T>::iterator::operator++()
{
    if(m_node->nextNode == nullptr)
    {
        throw "error";
    }
    m_node = m_node->nextNode;
    return *this;
}

template <typename T>
typename list<T>::iterator& list<T>::iterator::operator--()
{
    if(m_node->previousNode == nullptr)
    {
        throw "error";
    }
    m_node = m_node->previousNode;
    return *this;
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
void list<T>::pop_back()
{
    m_lastNode = m_lastNode->previousNode;
    delete m_lastNode->nextNode;
    m_size--;
}

template <typename T>
typename list<T>::iterator& list<T>::begin()
{
    iterator temp(m_beginNode);
    return std::move(temp);
}

template <typename T>
typename list<T>::iterator& list<T>::end()
{
    iterator temp(m_lastNode);
    return std::move(temp);
}

template <typename T>
void list<T>::insert(const iterator& it, const T& val)
{
}

template <typename T>
void list<T>::erase(const iterator& it)
{
    node* temp = it.m_node->nextNode;
    --it;
    delete it.m_node->nextNode;
    it.m_node->nextNode = temp;
}

template <typename T>
T& list<T>::front()
{
    return m_beginNode->item;
}

template <typename T>
T& list<T>::back()
{
    return m_lastNode->item;
}

template <typename T>
list<T>::node::node()
    : nextNode(nullptr)
    , previousNode(nullptr)
{
}
