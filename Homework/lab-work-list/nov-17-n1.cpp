/*
Лабораторная Работа "Список"
*/

#include <cstddef>
#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *next;
};

class LinkedList {
public:
  bool add_element(int data);
  bool find_element(int data);
  bool delete_element(int data);
  bool insert(int data, int position);

  LinkedList(int data);
  LinkedList();
  ~LinkedList();

private:
  Node *first;
  Node *last;
};

bool LinkedList::add_element(int data) {
  Node *nd = new Node{data, nullptr};

  if (last == nullptr) {
    first = nd;
    last = nd;

    return true;
  }

  last->next = nd;
  last = nd;

  return true;
}

bool LinkedList::find_element(int data) {
  if (last != nullptr) {
    Node *current = first;

    while (current != nullptr) {

      if (current->data == data)
        return true;
      current = current->next;
    }
  }

  return false;
}

bool LinkedList::delete_element(int data) {
  if (first != nullptr) {
    Node *current = first;
    Node *previous = nullptr;

    while (current != nullptr) {
      if (current->data == data) {
        if (current == first)
          first = current->next;
        else if (current == first)
          last = previous;

        previous->next = current->next;
        delete current;
      }

      previous = current;
      current = current->next;
    }
  }

  return false;
}

bool LinkedList::insert(int data, int position) {
  if (last != nullptr) {

    Node *current = first;
    size_t i = 0;

    while (current != nullptr) {

      if (i == position - 1) {

        Node *nd = new Node{data, current->next};
        current->next = nd;

        return true;
      }

      current = current->next;
      i += 1;
    }
  }

  return false;
}

LinkedList::LinkedList() {
  first = nullptr;
  last = nullptr;
}

LinkedList::LinkedList(int data) {
  Node *nd = new Node{data};

  first = nd;
  last = nd;
  last->next = nullptr;
}

LinkedList::~LinkedList() {
  if (last != nullptr) {
    Node *current = first;

    while (current != nullptr) {
      delete current;

      first = first->next;
      current = first;
    }
  }
}

int main() {
  LinkedList lst;

  lst.~LinkedList();
  return 0;
}