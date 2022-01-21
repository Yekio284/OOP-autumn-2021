#include <iostream>

using namespace std;

struct Node {
    string value;
    Node *next;

    Node(string val) : value(val), next(nullptr) {}
};

struct Stack_element {
    int digit;
    Stack_element *prev;
};

class List {
protected:
    Node *first, *last;

public:
    List(nullptr_t ptr1, nullptr_t ptr2) : first(ptr1), last(ptr2) {
        cout << "LIST:\n";
    }
    List() : first(nullptr), last(nullptr) {}
    bool is_empty() {
        return first == nullptr;
    }
    void push_back(string val) {
        Node *p = new Node(val);
        
        if (is_empty()) {
            first = p;
            last = p;
            return;
        }
        
        last->next = p;
        last = p;
    }
    void list_print() {
        if (is_empty())
            return;
        
        Node *p = first;
        while (p) {
            cout << p->value << " ";
            p = p->next;
        }
        cout << endl;
    }
    Node find(string find_val) {
        Node *p = first;
        
        while (p && p->value != find_val)
            p = p->next;
        
        Node *ret = (p && p->value == find_val) ? p : nullptr;
        return *ret;
    }
    void remove_first() {
        if (is_empty())
            return;
        Node *p = first;
        first = p->next;
        delete p;
    }
    void remove_last() {
        if (is_empty())
            return;
        
        if (first == last) {
            remove_first();
            return;
        }
        
        Node *p = first;
        while (p->next != last)
            p = p->next;
        p->next = nullptr;
        
        delete last;
        last = p;
    }
    void remove_element(string val) {
        if (is_empty())
            return;
        
        if (first->value == val) {
            remove_first();
            return;
        }
        
        else if (last->value == val) {
            remove_last();
            return;
        }

        Node *slow = first;
        Node *fast = first->next;
        while (fast && fast->value != val) {
            fast = fast->next;
            slow = slow->next;
        }
        if (!fast) {
            cout << "This element does not exist" << endl;
            return;
        }
        slow->next = fast->next;
        delete fast;
    }
    Node *operator[](const int index) {
        if (is_empty())
            return nullptr;
        Node *p = first;
        for (int i = 0; i < index; i++) {
            p = p->next;
            if (!p)
                return nullptr;
        }
        return p;
    }
};

class Stack : public List {
private:
    Stack_element *last_data, *first_data;

public:
    Stack() : last_data(NULL), first_data(NULL) {
        cout << "STACK:\n";
    }
    void stack_push(int digit) {
        Stack_element *p = new Stack_element();
        p->digit = digit;
        if (last_data)
            p->prev = last_data;
        else // empty Stack
        {
            p->prev = nullptr;
            first_data = p;
        }
        last_data = p;
    }
    void stack_pop() {
        if (last_data) {
            Stack_element *tp = last_data;
            last_data = last_data->prev;
            delete tp;
        }
    }
    void stack_print() {
        Stack_element *tmp = last_data;
        try {
            if (!tmp) {
                throw 1;
            }
            
            while (tmp) {
                cout << tmp->digit << " ";
                tmp = tmp->prev;
            }
            
            cout << endl;
        }
        catch (int i) {
            cout << "Stack is empty\n";
        }
    }
};

class Queue : public List {
private:
    static const int SIZE = 100;
    int *queue;
    int head, tail;

public:
    Queue() : queue(new int[SIZE]), head(0), tail(0) {
        cout << "QUEUE:\n";
    }
    void queue_print(Queue q) {
        for (int i = q.head + 1; i < q.tail + 1; i++) {
            cout << q.queue[i] << " "; 
        }
        cout << endl;
    }
    void queue_push(int value) {
        if (tail + 1 == head || (tail + 1 == SIZE && !head)) {
            cout << "Queue is full\n";
            return;
        }
        
        tail++;
        
        if (tail == SIZE)
            tail = 0;
        
        queue[tail] = value;
    }
    void queue_pop() {
        if (head == tail) {
            cout << "Queue is empty\n";
            return;
        }
        
        head++;
        
        if (head == SIZE)
            head = 0;
    }
    int get_size() {
        int s = 0;
        for (int i = head; i < tail; i++) {
            s++;
        }
        return s;
    }
    int get_back_element() {
        return queue[tail];
    }
    int get_front_element() {
        return queue[head + 1];
    }
};
