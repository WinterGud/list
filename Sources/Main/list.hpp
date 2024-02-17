#pragma once
#include <memory>
#include <iostream>

template <typename T>
class list
{
    struct node;

public:
    list();
    list(int size);
    ~list();

    class iterator
    {
        friend class list<T>;

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
        T& operator*();
        friend iterator find(const iterator& itFrom, const iterator& itTo, T& elem);
        friend void sort(const iterator& itFrom, const iterator& itTo);

    private:
        node* m_node;
    };

    int size() const { return m_size; }
    void push_back(const T& elem);
    void push_front(const T& elem);
    void pop_back();
    void pop_front();
    iterator begin();
    iterator end();
    void insert(const iterator& it, const T& val);
    void erase(const iterator& it);
    bool empty();
    void clear();
    void remove(const T* elem);
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
    node* temp = m_lastNode;
    while (m_beginNode != nullptr)
    {
        temp = m_beginNode;
        m_beginNode = m_beginNode->nextNode;
        delete temp;
    }
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
    iterator temp(m_node);
    m_node = m_node->nextNode;
    return std::move(temp);
}


template <typename T>
typename list<T>::iterator& list<T>::iterator::operator--(T)
{
    if (m_node->previousNode == nullptr)
    {
        throw "error";
    }
    iterator temp(m_node);
    m_node = m_node->previousNode;
    return std::move(temp);
}

template <typename T>
typename list<T>::iterator& list<T>::iterator::operator++()
{
    if (m_node->nextNode == nullptr)
    {
        throw "error";
    }
    m_node = m_node->nextNode;
    return *this;
}

template <typename T>
typename list<T>::iterator& list<T>::iterator::operator--()
{
    if (m_node->previousNode == nullptr)
    {
        throw "error";
    }
    m_node = m_node->previousNode;
    return *this;
}

template <typename T>
T& list<T>::iterator::operator*()
{
    return m_node->item;
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
void list<T>::push_front(const T& elem)
{
    node* temp = new node;
    temp->item = elem;
    temp->nextNode = m_beginNode;
    m_beginNode = temp;
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
void list<T>::pop_front()
{
    node* temp = m_beginNode->nextNode;
    delete m_beginNode;
    m_beginNode = temp;
    m_size--;
}

template <typename T>
typename list<T>::iterator list<T>::begin()
{
    iterator temp(m_beginNode);
    return temp;
}

template <typename T>
typename list<T>::iterator list<T>::end()
{
    iterator temp(m_lastNode);
    return temp;
}

template <typename T>
void list<T>::insert(const iterator& it, const T& val)
{
    node* temp = new node;
    temp->item = val;
    temp->previousNode = it.m_node->previousNode;
    temp->nextNode = it.m_node;
    if (it.m_node->previousNode != nullptr)
    {
        it.m_node->previousNode->nextNode = temp;
    }
    it.m_node->previousNode = temp;
    m_beginNode = temp;
    m_size++;
}

template <typename T>
void list<T>::erase(const iterator& it)
{
    node* temp = it.m_node;
    if (temp == m_beginNode)
    {
        temp->nextNode->previousNode = nullptr;
    }
    else
    {
        temp->previousNode->nextNode = temp->nextNode;
    }
    m_beginNode = it.m_node->nextNode;
    delete temp;
    m_size--;
}

template <typename T>
bool list<T>::empty()
{
    return m_size == 0;
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
auto find(const typename list<T>::iterator& itFrom,
          const typename list<T>::iterator& itTo,
          const T& elem) -> typename list<T>::iterator
{
    typename list<T>::iterator it(itFrom);
    while (*it != elem)
    {
        if (it == itTo)
        {
            return it;
        }
        ++it;
    }
    return it;
}

template <typename  T>
auto sort(const typename list<T>::iterator& itFrom,
          const typename list<T>::iterator& itTo) -> void
{
    
}

template <typename T>
list<T>::node::node()
    : nextNode(nullptr)
    , previousNode(nullptr)
{
}
