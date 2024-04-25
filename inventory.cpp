#include <iostream>
#include <string>

using namespace std;

struct inventoryItem {
    string name;
    int quantity;
    inventoryItem* next;
};

class inventory {
protected:
    inventoryItem* head;

public:
    inventory() : head(nullptr) {}

    ~inventory() {
        inventoryItem* current = head;
        while (current != nullptr) {
            inventoryItem* next = current->next;
            delete current;
            current = next;
        }
    }

    

    void addItem(const string& itemName, int quantity) {
        inventoryItem* newItem = new inventoryItem;
        newItem->name = itemName;
        newItem->quantity = quantity;
        newItem->next = nullptr;

        if (head == nullptr) {
            head = newItem;
            return;
        }

        inventoryItem* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newItem;
    }

    void dropItem() {

        int index;
        cout << "Please enter the index of the item to drop: " << endl;
        cin >> index;

        if (head == nullptr) {
            cout << "Inventory is empty." << endl;
            return;
        }

        if (index == 1) {
            inventoryItem* temp = head;
            head = head->next;
            delete temp;
            cout << "Item at index " << index << " dropped." << endl;
            return;
        }

        inventoryItem* prev = nullptr;
        inventoryItem* current = head;
        int currentIndex = 1;
        while (current != nullptr && currentIndex != index) {
            prev = current;
            current = current->next;
            currentIndex++;
        }
        if (current != nullptr) {
            prev->next = current->next;
            delete current;
            cout << "Item at index " << index << " dropped." << endl;
        }
        else {
            cout << "Index " << index << " out of bounds." << endl;
        }
    }


    inventoryItem* useItem() {
        int index;
        cout << "Please enter the index of the item to select: ";
        cin >> index;

        if (head == nullptr) {
            cout << "Inventory is empty." << endl;
            return nullptr;
        }

        inventoryItem* current = head;
        int currentIndex = 1;
        while (current != nullptr && currentIndex != index) {
            current = current->next;
            currentIndex++;
        }

        if (current != nullptr) {
            cout << "Selected item at index " << index << ":" << endl;
            return current;
        }
        else {
            cout << "Index " << index << " is out of bounds." << endl;
        }
        return nullptr;
    }

    void changeQuantity(inventoryItem* item, int amount) {
        item->quantity - amount;
    }

    inventoryItem* getItemByName(const string& itemName) {
        inventoryItem* current = head;
        while (current != nullptr) {
            if (current->name == itemName) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }



    void displayInventory() {
        cout << "\n\n-----------------------\nInventory:" << endl;
        inventoryItem* current = head;
        int index = 1;
        while (current != nullptr) {
            cout << "[" << index << "] " << current->name << ": " << current->quantity << endl;
            current = current->next;
            index++;
        }
        cout << endl;
    }
};