#include <iostream>

// Node structure
struct Node {
    int data;
    Node* prev;
    Node* next;
    
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Doubly Linked List class
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    
public:
    // Constructor
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    
    // push_back method to add at the end
    void push_back(int value) {
        Node* newNode = new Node(value);
        if (!head) { // If list is empty
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    
    // push_front method to add at the beginning
    void push_front(int value) {
        Node* newNode = new Node(value);
        if (!head) { // If list is empty
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    
    // pop_back method to remove from the end
    void pop_back() {
        if (!tail) { // If list is empty
            std::cout << "List is empty. Cannot pop_back.\n";
            return;
        }
        
        Node* temp = tail;
        if (head == tail) { // Only one element
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }
    
    // pop_front method to remove from the beginning
    void pop_front() {
        if (!head) { // If list is empty
            std::cout << "List is empty. Cannot pop_front.\n";
            return;
        }
        
        Node* temp = head;
        if (head == tail) { // Only one element
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }
    
    // Function to display the list
    void display() const {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " <-> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }
    
    // Destructor to clean up memory
    ~DoublyLinkedList() {
        Node* current = head;
        while (current) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    DoublyLinkedList dll;
    
    // Using push_back and push_front
    dll.push_back(10);
    dll.push_back(20);
    dll.push_front(5);
    dll.push_front(1);
    
    std::cout << "Doubly Linked List after push operations: ";
    dll.display();
    
    // Using pop_back and pop_front
    dll.pop_back();
    dll.pop_front();
    
    std::cout << "Doubly Linked List after pop operations: ";
    dll.display();
    
    // Attempting to pop from empty list
    dll.pop_front();
    dll.pop_back();
    dll.pop_front(); // Should indicate that the list is empty
    
    return 0;
}
