#include <iostream>
using namespace std;

// Structure for a node
struct Node {
    int data;
    Node* next;
};

// Function to insert a node at the beginning
void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node{value, head};
    head = newNode;
}

// Function to insert a node at the end
void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to insert a node at a specific position
void insertAtPosition(Node*& head, int value, int position) {
    if (position == 1) {
        insertAtBeginning(head, value);
        return;
    }
    Node* temp = head;
    for (int i = 1; temp && i < position - 1; i++) {
        temp = temp->next;
    }
    if (!temp) {
        cout << "Position out of bounds" << endl;
        return;
    }
    Node* newNode = new Node{value, temp->next};
    temp->next = newNode;
}

// Function to delete a node from the beginning
void deleteFromBeginning(Node*& head) {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

// Function to delete a node from the end
void deleteFromEnd(Node*& head) {
    if (!head) return;
    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

// Function to delete a node from a specific position
void deleteFromPosition(Node*& head, int position) {
    if (!head) return;
    if (position == 1) {
        deleteFromBeginning(head);
        return;
    }
    Node* temp = head;
    for (int i = 1; temp->next && i < position - 1; i++) {
        temp = temp->next;
    }
    if (!temp->next) {
        cout << "Position out of bounds" << endl;
        return;
    }
    Node* delNode = temp->next;
    temp->next = temp->next->next;
    delete delNode;
}

// Function to search for a value in the list
bool search(Node* head, int value) {
    while (head) {
        if (head->data == value) return true;
        head = head->next;
    }
    return false;
}

// Function to display the list
void display(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Function to reverse the linked list
void reverse(Node*& head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

int main() {
    Node* head = nullptr;
    int choice, value, position;
    
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete from Position\n";
        cout << "7. Search\n";
        cout << "8. Display\n";
        cout << "9. Reverse\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertAtBeginning(head, value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertAtEnd(head, value);
                break;
            case 3:
                cout << "Enter value and position: ";
                cin >> value >> position;
                insertAtPosition(head, value, position);
                break;
            case 4:
                deleteFromBeginning(head);
                break;
            case 5:
                deleteFromEnd(head);
                break;
            case 6:
                cout << "Enter position: ";
                cin >> position;
                deleteFromPosition(head, position);
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> value;
                cout << (search(head, value) ? "Found" : "Not Found") << endl;
                break;
            case 8:
                display(head);
                break;
            case 9:
                reverse(head);
                break;
            case 10:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 10);
    
    return 0;
}
