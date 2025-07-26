#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node* next;
} Node; 

class Chain
{
public:
    Node* head;
    Chain() { head = nullptr; }
    void insert(int value);
    void create(int n);
    bool isExist(int value);
    Chain cal(Chain& other);
    void print();
};

void Chain::insert(int value) {
    if (isExist(value)) {
        return;
    }
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void Chain::create(int n) {
    int value;
    for (int i = 0; i < n; i++) {
        cin >> value;
        insert(value);
    }
}

bool Chain::isExist(int value) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == value) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

Chain Chain::cal(Chain& other) {
    Chain result;

    Node* temp = this->head;
    while (temp != nullptr) {
        result.insert(temp->data);
        temp = temp->next;
    }

    temp = other.head;
    while (temp != nullptr) {
        result.insert(temp->data);
        temp = temp->next;
    }

    return result;
}

void Chain::print() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Chain setA, setB;
    int n, m;cin >> n >> m;
    setA.create(n);
    setB.create(m);
    Chain res = setA.cal(setB);
    res.print();
    return 0;
}