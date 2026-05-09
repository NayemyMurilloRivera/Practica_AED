
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
            head = head->next;
            delete i->next;
            i->next = head;
            
        }
        
        for (; i->next->value==x; i = i->next) 
        {};
        Node* temp = i->next;
        i->next = i->next->next;
        delete temp;
    }
