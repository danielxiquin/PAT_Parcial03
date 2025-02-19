#include "Ejercicio01.h"

Node<int>* Ejercicio01::mergeLists(Node<Node<int>*>* lists)
{
    auto compare = [](Node<int>* a, Node<int>* b) { return a->value < b->value; };
    priority_queue<Node<int>*, vector<Node<int>*>, decltype(compare)> pq(compare);


    while (lists != nullptr) {
        if (lists->value != nullptr) {
            pq.push(lists->value);
        }
        lists = lists->next;
    }

    Node<int> dummy{ 0 };
    Node<int>* tail = &dummy;


    while (!pq.empty()) {
        Node<int>* top = pq.top();
        pq.pop();

        if (top->next != nullptr) {
            pq.push(top->next);
        }

        tail->next = top;
        tail = tail->next;
    }

    return dummy.next;
}
