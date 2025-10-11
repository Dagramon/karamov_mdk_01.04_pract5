#include <iostream>
struct Node
{
    int data;
    Node* next;
    Node* prev;
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};
class DoubleLinkedList
{
public:
    DoubleLinkedList() : head(nullptr), tail(nullptr) {}
    Node* head;
    Node* tail;
    void push_front(int data)
    {
        Node* newNode = new Node(data);
        if (head != nullptr)
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        else
        {
            head = newNode;
            tail = newNode;
        }
    }
    void push_back(int data)
    {
        Node* newNode = new Node(data);
        if (tail != nullptr)
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        else
        {
            head = newNode;
            tail = newNode;
        }
    }
    void pop_front()
    {
        if (head != nullptr)
        {
            if (head->next == nullptr)
            {
                head = nullptr;
                tail = nullptr;
                return;
            }
            head = head->next;
            head->prev = nullptr;
        }
    }
    void pop_back()
    {
        if (tail != nullptr)
        {
            if (tail->prev == nullptr)
            {
                head = nullptr;
                tail = nullptr;
                return;
            }
            tail = tail->prev;
            tail->next = nullptr;
        }
    }
    void display()
    {
        if (head != nullptr)
        {
            Node* currentNode = head;
            do
            {
                std::cout << currentNode->data << "\n";
                currentNode = currentNode->next;

            } while (currentNode != head->prev);
        }
    }
    void sort()
    {
        if (head != nullptr)
        {
            Node* tempNode;
            Node* currentNode = head;
            do
            {
                Node* currentNode2 = currentNode->next;
                do 
                {
                    if (currentNode->data < currentNode2->data)
                    {
                        tempNode = currentNode;
                        currentNode = currentNode2;
                        currentNode2 = tempNode;
                    }

                    currentNode2 = currentNode2->next;

                } while (currentNode2 != head->prev);

                currentNode = currentNode->next;
            } while (currentNode != head->prev);
        }

    }
};
int main()
{
    DoubleLinkedList list;
    list.push_front(2);
    list.push_front(3);
    list.push_front(6);
    list.push_back(1);
    list.display();
    list.sort();
    std::cout << "head - " << list.head->data << "\n";
    std::cout << "tail - " << list.tail->data << "\n";
    list.display();
}