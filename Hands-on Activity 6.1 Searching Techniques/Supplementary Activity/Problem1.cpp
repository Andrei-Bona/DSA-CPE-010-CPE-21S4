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

int sequentialSearchArray(int arr[], int size, int key) {
    int comparisons = 0;
    for (int i = 0; i < size; i++) {
        comparisons++;
        if (arr[i] == key) {
            return comparisons;
        }
    }
    return comparisons;
}

template <typename T>
int sequentialSearchLinkedList(Node<T>* head, T key) {
    int comparisons = 0;
    Node<T>* current = head;

    while (current != NULL) {
        comparisons++;
        if (current->data == key) {
            return comparisons;
        }
        current = current->next;
    }

    return comparisons;
}

int main() {
    int arr[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 18;

    int arrayComparisons = sequentialSearchArray(arr, size, key);
    cout << "Comparisons in array: " << arrayComparisons << endl;

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

    int linkedListComparisons = sequentialSearchLinkedList(head, key);
    cout << "Comparisons in linked list: " << linkedListComparisons << endl;

    Node<int>* current = head;
    while (current != NULL) {
        Node<int>* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}

