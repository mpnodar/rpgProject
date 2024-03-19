#include <iostream>

using namespace std;


class node {


public:

    string item;
    int quantity = 0;
    node* next;


    void printList(node* n) {

        while (n != NULL) {
            cout << n->item << endl;
            n = n->next;
        }
    }

    void getElementAt(node* n) {

        int count = 0;
        int index;

        cout << "Please enter the index you would like to find: ";
        cin >> index;

        for (int i = 0; i <= index; i++) {
            if (count == index) {
                cout << n->item << endl;
                break;
            }

            n = n->next;
            count++;

        }
    }

    void push_back(node* n) {

        int input;

        node* newNode = new node;
        newNode->quantity += 1;
        newNode->next = NULL;

        n->next = newNode;

        cout << "Please enter the item for your new node: ";
        cin >> input;

        newNode->item = input;
    }

    int size(node* n) {

        int count = 0;

        while (n != NULL) {
            count++;
            n = n->next;
        }
        return count;
    }

    void  pop_back(node* n) {

        cout << "\nPop_back last element: " << endl;

        int count = size(n);

        for (int i = 1; i <= count; i++) {

            if (i == (count - 1)) {
                n->next = NULL;
            }

            else {
                n = n->next;
            }
        }

        cout << endl;

    }

    void delete_at(node*& head) {
    int index;
    cout << "\nWhat index position would you like to drop?" << endl;
    cin >> index;

    if (index < 0 || head == nullptr) {
        cout << "Invalid input!" << endl;
        return;
    }

    if (index == 0) { // If the first node is to be deleted
        node* temp = head->next;
        delete head; // Delete the current node
        head = temp; // Update the head pointer
        return;
    }

    int count = 0;
    node* prev = nullptr;
    node* n = head;
    while (n != nullptr) {
        if (count == index) {
            prev->next = n->next;
            delete n; // Delete the current node
            return;
        }
        prev = n;
        n = n->next;
        count++;
    }

    cout << "Invalid input!" << endl; // Index exceeds list size
}




    void  insert_at(node* n) {

        int index;
        int inputitem;

        cout << endl << "\nWhat index position and item would you like to insert?" << endl;
        cin >> index >> inputitem;

        node* newNode = new node;
        newNode->item = inputitem;



        for (int i = 0; i <= index; i++) {

            if (i == (index - 1)) {

                node* temp = new node;

                temp = n->next;

                n->next = newNode;
                newNode->next = temp;

            }
        }
    }
};


class Stack {

private:

    node* top;
    int size;

public:

    Stack() {
        top = nullptr;
        size = 0;
    }

    ~Stack() {
        while (top != nullptr) {
            node* temp = top;
            top = top->next;
            delete temp;
        }
    }


    void push(node* newNode) {
        newNode->next = top;
        newNode->quantity += 1;
        top = newNode;
        size++;
    }

    void print() {
    if (isEmpty()) {
        cout << "There are no items in your inventory." << endl;
    } else {
        node* current = top;
        while (current != nullptr) {
            cout << current->item << " (" << current->quantity << ")" << endl;
            current = current->next;
        }
    }
    cout << endl;
}


    int Size() {
        return size;
    }

    node* peek() {
        return top;
    }

    void pop() {
        if (top == nullptr) {
            cout << "There are no items in your inventory." << endl;
        }

        else {
            node* temp = top;
            top = top->next;
            size--;
        }
    }

    bool isEmpty() {
        if (top == nullptr) {
            return true;
        }
        return false;
    }

    void popN(int n) {

        if (n >= size) {
            while (top != nullptr) {
                node* temp = top;
                top = top->next;
                delete temp;
            }
            size = 0;
        }

        else {
            for (int i = 1; i <= n; i++) {
                node* temp = top;
                top = top->next;
                delete temp;
                size--;
            }
        }

    }

    void dropItem() {


        print();

        top->delete_at(top);

        print();

}

};

void createInventory (Stack& _Inventory) {


    node* node1 = new node;
    node1->item = "Longsword";

    node* node2 = new node;
    node2->item = "Battle-Axe";

    node* node3 = new node;
    node3->item = "Health Potions";
    node3->quantity = 2;

    node* node4 = new node;
    node4->item = "Stamina Potions";
    node4->quantity = 2;

    _Inventory.push(node1);
    _Inventory.push(node2);
    _Inventory.push(node3);
    _Inventory.push(node4);

}

void inventory (Stack& _inventory) {
    int input;
    _inventory.print();

    cout << "What would you like to do?" << endl;

    do {

    cout << "1. Equip Item\n2. Drop Item\n3. Back" << endl;
    cin >> input;

    switch (input) {
        case 1: 
        cout << "No, you dumbass." << endl;
        break;

        case 2:
        _inventory.dropItem();
        break;

        case 3:
        cout << "See ya later, idiot." << endl;
        break;
    }

    }

    while (input != 3);



}