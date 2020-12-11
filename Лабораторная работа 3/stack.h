#ifndef LAB3_STACK_H
#define LAB3_STACK_H

class stack
{
    class node {
    public:
        node(char v) {
            value = v;
            next = nullptr;
        };

        int getValue() {
            return value;
        }

        void setValue(char v) {
            value = v;
        }

        node* getNext() {
            return next;
        }
        void setNext(node* n) {
            next = n;
        }

    private:
        char value;
        node* next;
    };

private:
    node* head;
public:
    stack();

    void push(char val);
    char pop();
    char top();
    bool isempty() {
        return (head == nullptr);
    };
};


#endif 
