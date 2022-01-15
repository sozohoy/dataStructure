
#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    int myData;
    Node* next;
}; // 노드 구현

class linkedList {
public:
    Node *head;
    Node *tail;
    int readData;
    linkedList(){
        head = NULL;
        tail = NULL;
    }
}; // head 노드와 tail 노드 구현

class List {
private:
    linkedList listADT;

public:
    void add(int men) { // 삽입
        Node *newNode = new Node();
        newNode->myData = men;
        newNode->next = NULL;
        
        if (listADT.head == NULL) {
            listADT.head = newNode;
            listADT.tail = newNode;
        }
        else {
            listADT.tail->next = newNode;
            listADT.tail = newNode;
        }
    }
    
    void del(int men) { // 삭제
        
        if (listADT.head == NULL) {
            return;
        }
        for(Node *now = listADT.head; now != NULL; now = now->next) {
            if (now->myData == men){
                if (now == listADT.head){
                    listADT.head = now->next;
                    delete now;
                }
                else {
                    Node *pre = listADT.head;
                    while(pre->next != now) pre = pre->next;
                    pre->next = now->next;
                    delete now;
                }
            }
        }
    }
    
    void displayAll() {
        for (Node *now = listADT.head; now != NULL; now = now->next) {
            cout << now->myData << " ";
        }
    }
    
};

int main() {
    List list1;
    list1.add(1);
    list1.add(2);
    list1.add(30);
    list1.del(2);
    list1.displayAll();
}
