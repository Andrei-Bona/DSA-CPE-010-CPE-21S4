#include <iostream>

using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node *next;

    Node(T newData) {
        data = newData;
        next = NULL;
    }
};

int countOccurrencesArray(int arr[], int size, int key) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            count++;
        }
    }
    return count;
}

template <typename T>
int countOccurrencesLinkedList(Node<T>* head, T key) {
    int count = 0;
    Node<T>* current = head;

    while (current != NULL) {
        if (current->data == key) {
            count++;
        }
        current = current->next;
    }

    return count;
}

int main() {
    int arr[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 18;

    int arrayCount = countOccurrencesArray(arr, size, key);
    cout << "Occurrences of " << key << " in array: " << arrayCount << endl;

    Node<int>* head = new Node<int>(15);
    head->next = new Node<int>(18);
    head->next->next = new Node<int>(2);
    head->next->next->next = new Node<int>(19);
    head->next->next->next->next = new Node<int>(18);
    head->next->next->next->next->next = new Node<int>(0);
    head->next->next->next->next->next->next = new Node<int>(8);
    head->next->next->next->next->next->next->next = new Node<int>(14);
    head->next->next->next->next->next->next->next->next = new Node<int>(19);
    head->next->next->next->next->next->next->next->next->next = new Node<int>(14);

    int linkedListCount = countOccurrencesLinkedList(head, key);
    cout << "Occurrences of " << key << " in linked list: " << linkedListCount << endl;

    Node<int>* current = head;
    while (current != NULL) {
        Node<int>* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}

