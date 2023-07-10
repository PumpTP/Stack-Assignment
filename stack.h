#ifndef stack_h
#define stack_h

class Node;
typedef Node* NodePtr;

class Stack {
private:
    NodePtr top;
    int length;

public:
    Stack(NodePtr t = nullptr);
    ~Stack();
    char get_top();
    void push(char x);
    char pop();
    void printall();
    void clear();
    bool isEmpty();
};

char Stack::get_top(){
  return top->get_value();
}

Stack::Stack(NodePtr t) {
    if (t) {
        top = t;
        length = 1;
    } else {
        top = nullptr;
        length = 0;
    }
}

void Stack::push(char x) {
    NodePtr newnode = new Node(x);
    if (newnode) {
        newnode->set_next(top);
        top = newnode;
        length++;
    } else {
        throw std::bad_alloc();
    }
}

char Stack::pop() {
    if (top) {
        NodePtr t = top;
        char value = t->get_value();
        top = t->get_next();
        delete t;
        length--;
        return value;
    }
    return 0;
}

void Stack::printall() {
    NodePtr t = top;
    while (t) {
        cout << t->get_value();
        t = t->get_next();
        if (t) {
            std::cout << " ";
        }
    }
    cout << endl;
}

void Stack::clear() {
    while (top) {
        NodePtr t = top;
        top = top->get_next();
        delete t;
    }
    length = 0;
}

Stack::~Stack() {
    clear();
}

bool Stack::isEmpty() {
    return (top == nullptr);
}

#endif
