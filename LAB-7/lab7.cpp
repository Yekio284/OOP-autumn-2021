#include <iostream>
#include "Classes.hpp"

using namespace std;

int main() {
    List list(nullptr, nullptr);
    cout << list.is_empty() << endl;
    list.push_back("a");
    list.push_back("b");
    list.list_print();
    cout << list.is_empty() << endl;
    list.push_back("ivt");
    list.push_back("aes");
    list.list_print();
    list.remove_first();
    list.remove_last();
    list.list_print();
    list.remove_element("b");
    list.list_print();
    cout << endl;

    Stack stack;
    stack.stack_push(5);
    stack.stack_push(10);
    stack.stack_push(15);
    stack.stack_print();
    stack.stack_pop();
    stack.stack_print();
    stack.stack_pop();
    stack.stack_print();
    cout << endl;

    Queue queue;
    queue.queue_push(2);
    queue.queue_push(8);
    queue.queue_push(18);
    queue.queue_print(queue);
    queue.queue_pop();
    queue.queue_print(queue);
    cout << queue.get_size() << endl;
    queue.queue_push(25);
    queue.queue_push(49);
    queue.queue_print(queue);
    cout << queue.get_size() << endl;
    cout << queue.get_front_element() << endl;
    cout << queue.get_back_element() << endl;

    return 0;
}
