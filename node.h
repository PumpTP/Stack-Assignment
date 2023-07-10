#ifndef node_h
#define node_h

class NODE {
private:
    char data;
    NODE* nextPtr;

public:
    NODE(char);
    char get_value();
    void set_next(NODE*);
    NODE* get_next();
};

typedef NODE* NodePtr;

NODE::NODE(char x) {
    data = x;
    nextPtr = nullptr;
}

char NODE::get_value() {
    return data;
}

NODE* NODE::get_next() {
    return nextPtr;
}

void NODE::set_next(NODE* t) {
    nextPtr = t;
}

#endif
