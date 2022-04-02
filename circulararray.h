#include <iostream>
#include <cmath>
using namespace std;

template <class T>
class CircularArray
{
private:
    T *array;
    int capacity;
    int back, front;
    
public:
    CircularArray(); //completado
    CircularArray(int _capacity); //completado
    virtual ~CircularArray(); //completado
    void push_front(T data); //completado
    void push_back(T data);  //completado
    void insert(T data, int pos); //completado
    T pop_front();  //completado
    T pop_back();  //completado
    bool is_full();  //completado
    bool is_empty();  //completado
    int size();  //completado 
    void clear(); //completado
    T &operator[](int); //completado
    void sort(); //completado 
    bool is_sorted(); //completado
    void reverse(); //completado
    string to_string(string sep=" "); //completado

private:
    int next(int);
    int prev(int);
};

template <class T>
CircularArray<T>::CircularArray()
{
    CircularArray(0);
}

template <class T>
CircularArray<T>::CircularArray(int _capacity)
{
    this->array = new T[_capacity];
    this->capacity = _capacity;
    this->front = this->back = -1;
}

template <class T>
CircularArray<T>::~CircularArray()
{
    delete[] array;
}

template <class T>
int CircularArray<T>::prev(int index)
{
    return (index == 0) ? capacity - 1 : index - 1;
}

template <class T>
int CircularArray<T>::next(int index)
{
    return (index + 1) % capacity;
}

template <class T> 
void CircularArray<T>::push_front(T data)
{
    if(is_full()) {
        cout << endl <<"Its full" << endl;
    } else {

    if(is_empty()) 
        this->front = this->back = 0; 
    else{
        if(this->front == 0) {
            this->front = this->capacity - 1; 
        } else {
            this -> front = prev(front);
        }
    }
    this -> array[front] = data; 
    }
}

template <class T> 
void CircularArray<T>::push_back(T data)
{
    if(is_full()) {
        cout << endl <<"Its full" << endl;
    } else {

    if(is_empty()) 
        this->front = this->back = 0; 
    else 
        this -> back = next(back);
    this -> array[back] = data; 
    }
}

template <class T>
void CircularArray<T>::insert(T data, int pos)
{
    string result = ""; 
    int temp = this->front;
    int i = 0; 
    if(back != -1 && front != -1){
        while (true){
            if (temp == this->capacity) temp = 0;  
            if(i == pos) {
                *(array + temp ) = data; 
                break; 
            }
            if(temp == this->back) break; 
            temp++; 
            i++; 
        }
    }  
}

template <class T> 
T CircularArray<T>::pop_front()
{
    if(is_empty()) {
        cout << "Its empty";
    } else {
    this -> front = next(front);
    }
}

template <class T> 
T CircularArray<T>::pop_back()
{
    if(is_empty()) {
        cout << "Its empty";
    } else {
    this -> back = prev(back);
    }
}

template <class T> 
bool CircularArray<T>::is_full()
{
    if(this->back + 1 == this->front) return true; 
    return false; 
}

template <class T> 
bool CircularArray<T>::is_empty()
{
    if(this->front == -1 && this->back == -1){
        return true; 
    }
    return false; 
}

template <class T> 
int CircularArray<T>::size(){
    if (this -> back == -1 || this -> front == -1) return 0;  
    int resultado = this->back - this->front; 
    if(this->back < this->front){
        resultado = capacity - front + back; 
    }
    if (resultado < 0) resultado = resultado * -1; 
    resultado++; 
    return resultado; 
}

template <class T> 
void CircularArray<T>::clear(){
    delete[] array;
    this->array = new T[this->capacity];
    this->front = this->back = -1;
}

template <class T> 
T& CircularArray<T>::operator[](int index)
{   
    int temp = this->front; 
    if (temp + index >= this->capacity) {
        temp = 0;
        index = index - this->back; 
    };  
    return array[temp + index];
}

template <class T> 
void CircularArray<T>::sort(){
    int temp  = this->front;
    T aux; 
    int auxindex = 0; 
    for(int i = 0; i < size(); i++){
        aux = *(array + front); 
        temp = this->front;
        for(int j = 0; j < size() - i; j++){
           if (temp == this->capacity) temp = 0;
            if(aux <= *(array + temp)){
                aux = *(array + temp);
                auxindex = temp; 
            }
            temp++; 
        }
        temp--; 
        *(array + auxindex) = *(array + temp);
        *(array + temp) = aux; 
    }  
}

template <class T> 
bool CircularArray<T>::is_sorted()
{
    int temp  = this->front;
    T valor1 = *(array + temp);
    if (temp + 1 == this->capacity) temp = 0;
    T valor2 = *(array + temp + 1);
    T aux; 
    int i = 0; 
    if (valor1 > valor2){
        for(int i = 0; i < size(); i++){
            aux = *(array + front); 
            temp = this->front;
            for(int j = 0; j < size() - i; j++){
               if (temp == this->capacity) temp = 0;
                if(aux < *(array + temp)){
                    return false;
                }
                temp++; 
            }
            temp--; 
        }
    } else {
        for(int i = 0; i < size(); i++){
            aux = *(array + front); 
            temp = this->front;
            for(int j = 0; j < size() - i; j++){
               if (temp == this->capacity) temp = 0;
                if(aux > *(array + temp)){
                    return false;
                }
                temp++; 
            }
            temp--; 
        }
    }

    return true; 
}

template <class T> 
void CircularArray<T>::reverse(){
    int tempF = this->front;
    int tempB = this->back;
    T aux; 
    if (size() % 2 == 0){
        for(int i = 0; i < size()/2; i++){
            if (tempF == this->capacity) tempF = 0;
            if (tempB == this->capacity) tempF = size()-1;
            aux = *(array + tempF);
            *(array + tempF) = *(array + tempB); 
            *(array + tempB) = aux; 
            tempF++; 
            tempB--;
        }
    } else {
        for(int i = 0; i < (size()+1)/2; i++){
            if (tempF == this->capacity) tempF = 0;
            if (tempB == this->capacity) tempF = size()-1;
            if(i != ((size()+1)/2) - 1){
                aux = *(array + tempF);
                *(array + tempF) = *(array + tempB); 
                *(array + tempB) = aux; 
                tempF++; 
                tempB--;
            }
        }
    }
}

template <class T>
string CircularArray<T>::to_string(string sep)
{
    string result = ""; 
    for (int i = 0; i < size(); i++)
        result += std::to_string((*this)[i]) + sep;
    return result;    
}