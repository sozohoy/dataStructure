#include <iostream>
#define maxSize 10;
using namespace std;

class Queue{

private:
    int front;
    int rear;
    int number;
    int size;
    int *values;
public:
    Queue(){
        front = 0;
        rear = 0;
        number = 0;
        size = maxSize;
        values = new int[size];
    }

    bool isFull(){
        if (number == size){
            return true;
        }else{
            return false;
        }
    }

    bool isEmpty(){
        if (number == 0){
            return true;
        }else{
            return false;
        }
    }

    void enqueue(int value){
        if(isFull() == true){
            cout << "Queue is full" << endl;
        }else{
            values[rear] = value;
            rear = (rear + 1) % size;
            number = number + 1;
        }
    }

    void dequeue(){
        if(isEmpty() == true){
            cout << "Queue is empty" << endl;
        }else{
            front = (front + 1) % size;
            number = number - 1;
        }
    }

    void qSize(){
        cout << number << endl;
        cout << endl;
    }
    
    void qPrint(){

        int x = front;

        if (isEmpty() == true){
            cout << "Queue is Empty" << endl;
        }else{
            for(int i = 0; i < number; i++){
                cout << values[x]<< endl;
                x = (x + 1) % size;
            }
        }
        cout << endl;
    }

};

int main(){
    Queue x;
    x.enqueue(50);
    x.enqueue(20);
    x.enqueue(10);
    x.enqueue(60);
    x.qPrint();
    x.qSize();
    x.dequeue();
    x.dequeue();
    x.dequeue();
    x.qPrint();
    x.qSize();
}