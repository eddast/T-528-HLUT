#ifndef MYSTACK_H
#define MYSTACK_H
#include <deque>

using namespace std;

template <class T>
class MyStack
{
    public:
        // Constructors and destructors intentionally empty
        MyStack() : stack_() {}
        virtual ~MyStack(){}

        // Operations to add and remove elements of stack
        void push (T elem){ stack_.push_front(elem); }
        void pop () { stack_.pop_front(); }

        // Returns top element of stack
        T top(){ return stack_.at(0); }

        // Checks for stack size and if it's empty
        bool empty(){ return stack_.empty(); }
        int size(){ return stack_.size(); }

    private:
        // Stack implemented via deque container
        deque<T> stack_;
};

#endif // MYSTACK_H
