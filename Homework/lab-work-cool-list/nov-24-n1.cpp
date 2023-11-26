/*
Лабораторная Работа "Крутой список"
*/


#include <cstddef>
#include <iostream>

using namespace std;


enum list_errors
{
    LIST_NO_MEMORY = 1,
};

template <class T>
class Node
{
private:
    Node *next;
    Node *prev;
    T data;

public:
    void set_next(Node *next)
    {
        this->next = next;
    }

    void set_prev(Node *prev)
    {
        this->prev = prev;
    }

    Node *get_next()
    {
        return this->next;
    }

    const Node *get_const_next() const
    {
        return this->next;
    }

    Node *get_prev()
    {
        return this->prev;
    }

    void set_data(T next)
    {
        this->data = data;
    }

    T get_data()
    {
        return this->data;
    }

    const T get_const_data() const
    {
        return this->data;
    }

    Node(T data)
    {
        this->next = NULL;
        this->prev = NULL;
        this->data = data;
    }

    ~Node(){};
};


template <class T>
class LinkedList
{
private:
    Node<T> *head;

public:
    Node<T> *get_head()
    {
        return this->head;
    }

    const Node<T> *get_const_head() const
    {
        return this->head;
    }

    int push(T data)
    {
        Node<T> *tmp = new Node<T>(data);
        if (!tmp)
        {
            return LIST_NO_MEMORY;
        }

        Node<T> *cur = this->get_head();
        if (!cur)
        {
            this->head = tmp;
            return EXIT_SUCCESS;
        }

        while (cur->get_next())
            cur = cur->get_next();

        cur->set_next(tmp);

        return EXIT_SUCCESS;
    }

    bool find(T data)
    {
        Node<T> *cur = this->get_head;

        while (cur)
        {
            if (cur->get_data == data)
                return true;

            cur = cur->get_next();
        }

        return false;
    }

    bool remove(T data)
    {
        Node<T> *cur = this->get_head;

        while (cur)
        {
            if (cur->get_data == data)
            {
                cur->prev->set_next(cur->get_next());
                ~Node(cur);
                return true;
            }

            cur = cur->get_next();
        }

        return false;
    }

    void sort()
    {
        Node<T> *cur;
        cur->get_prev() != NULL;

        // поменять местами текущий и предыдущий
        // T tmp = cur->get_data();
        // cur->set_data(cur->get_prev()->get_data());
        // cur->get_prev()->set_data(tmp);

        Node<T> *prev = cur->get_prev();
        prev->set_next(cur->get_next());
        cur->set_next(prev);
        cur->set_prev(prev->get_prev());
        prev->set_prev(cur);
    }

    bool insert(T data, size_t index)
    {
        Node<T> *tmp = new Node<T>(data);
        if (!tmp)
        {
            return false;
        }

        if (index == 0)
        {
            tmp->set_next(this->head);
            this->head = tmp;

            return true;
        }

        Node<T> *cur = this->get_head();
        for (size_t i = 0; i < index; ++i, cur = cur->get_next())
        {
            if (!cur)
                return false;
        }

        tmp->set_next(cur);
        tmp->set_prev(cur->get_prev());
        cur->get_prev()->set_next(tmp);

        return true;
    }

    LinkedList(T data)
    {
        this->head = new Node<T>(data);
    }

    LinkedList()
    {
        this->head = NULL;
    }

    ~LinkedList()
    {
        Node<T> *cur = this->head;
        while (cur)
        {
            Node<T> *tmp = cur->get_next();
            cur->Node<T>::~Node();
            cur = tmp;
        }
        this->head = NULL;
    }
};


template <class T>
ostream &operator<<(ostream &os, const LinkedList<T> &list)
{
    const Node<T> *cur = list.get_const_head();

    while (cur)
    {
        cout << cur->get_const_data() << ' ';
        cur = cur->get_const_next();
    }

    os << endl;

    return os;
}


int main()
{
    LinkedList<int> lst;

    lst.push(9);
    lst.push(3);
    lst.push(45);
    lst.push(2);
    lst.push(7);

    cout << lst;

    lst.sort();

    cout << lst;

    return 0;
}