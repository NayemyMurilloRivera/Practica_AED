
//  En el siguiente código implementa el método ADD y DEL de la 
//clase CircularLinkedList que es una lista circular ordenada.
#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node* next;

    Node(int v)
    {
        value = v;
        next = nullptr;
    }
};

class CircularLinkedList
{
private:
    Node* head;

public:

    CircularLinkedList()
    {
        head = nullptr;
    }


    bool find(int x) {
        if (!head) { return false; }
        Node* i = head;
        for (; i->next != head; i = i->next) {
            if (i->value == x) {
                return true;
            }
        };

        if (i->value==x) {
            return true;
        }
        return false;

    }

    bool ADD(int x) {
        if (find(x)) {
            return false;
        }
       
        Node* nuevo = nullptr;
        if (head == nullptr) {
            nuevo = new Node(x);
            head = nuevo;
            nuevo->next = head;
            return true;
        }

        Node* i = head;

        if (x < head->value) { // si esta al inicio
            nuevo = new Node(x);
            nuevo->next = head;
           

            for (; i->next != head; i = i->next) {};
            i->next = nuevo;
            head = nuevo;
            return true;
        }

        for (; i->next != head; i = i->next) {
            if (i->value < x && x<i->next->value) {
                nuevo = new Node(x);
                nuevo->next = i->next;
                i->next = nuevo;
                return true;
            }
        };

        nuevo = new Node(x);
        i->next = nuevo;
        nuevo->next = head;
        return true;

    }

    bool DEL(int x) {
        if (!find(x)) { return false; }
        if (head == nullptr) {
            return false;
        }
        if (head->next == head) {
            delete head;
            head = nullptr;
            return true;
        }
        Node* i = head;
        if (x == head->value) {
            
            for (; i->next != head; i = i->next) {};
            Node* temp = head;
            head = head->next;
            
            i->next = head;
            delete temp;
            return true;
            
        }
        
        for (; i->next->value!=x; i = i->next) 
        {};
        Node* temp = i->next;
        i->next = i->next->next;
        delete temp;
        return true;
    }

    void PRINT()
    {
        if (!head)
        {
            cout << "Lista vacia\n";
            return;
        }

        Node* p = head;

        do
        {
            cout << p->value << " ";
            p = p->next;

        } while (p != head);

        cout << "\n";
    }
};

int main()
{
    CircularLinkedList L;

    L.ADD(8);
    L.ADD(3);
    L.ADD(10);
    L.ADD(1);
    L.ADD(5);

    L.PRINT();

    L.DEL(1);
    L.DEL(8);

    L.PRINT();
}
