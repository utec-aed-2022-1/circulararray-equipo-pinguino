#include "circulararray.h"

template <typename T>
class StackArray : public CircularArray<T> { 
    public:
        StackArray(); 
        StackArray(int _capacity):CircularArray<T>(_capacity){}; 
        bool empty(){
            return this->is_empty;
        }
        int stack_size(){
            return this->size;
        }

        void push(T data){
            this->push_front(data);
        }
        void emplace(T data, int pos){
            this->insert(data, pos)
        }

        T pop(){
            return this->pop_front();
        }
};
