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
    void Push_front(int data)
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
    void Push_back(int data)
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
    void Pop_front()
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
    void Pop_back()
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
    void Display()
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
    void Sort()
    {
        if (head != nullptr)
        {
            Node* tempNode = new Node(0);
            Node* currentNode = head;
            Node* currentNode2 = head->next;
            while (currentNode->next != nullptr)
            {
                while (currentNode2 != nullptr)
                {
                    if (currentNode->data > currentNode2->data)
                    {
                        tempNode->data = currentNode->data;
                        currentNode->data = currentNode2->data;
                        currentNode2->data = tempNode->data;
                    }
                    currentNode2 = currentNode2->next;
                }
                currentNode = currentNode->next;
                currentNode2 = currentNode->next;
            }
            delete tempNode;
        }
    }
    void DeleteDuplicates()
    {
        if (head != nullptr)
        {
            Node* currentNode = head;
            while (currentNode != nullptr)
            {
                Node* nextNode = currentNode->next;
                while (nextNode != nullptr)
                {
                    if (currentNode->data == nextNode->data)
                    {
                        Node* foundDuplicate = nextNode;
                        nextNode = nextNode->next;
                        if (foundDuplicate->prev != nullptr)
                        {
                            foundDuplicate->prev->next = foundDuplicate->next;
                        }
                        if (foundDuplicate->next != nullptr)
                        {
                            foundDuplicate->next->prev = foundDuplicate->prev;
                        }
                        if (foundDuplicate == head)
                        {
                            head = foundDuplicate->next;
                        }
                        if (foundDuplicate == tail)
                        {
                            tail = foundDuplicate->prev;
                        }
                        delete foundDuplicate;
                    }
                    else
                    {
                        nextNode = nextNode->next;
                    }
                }
                currentNode = currentNode->next;
            }
        }
    }
};

int main()
{
    DoubleLinkedList list;
    short selection;
    do
    {
        std::cout << "\n-----------------------------------\n";
        std::cout << "1 - add front element\n2 - add back element\n3 - remove front element\n4 - remove back element\n5 - show list\n6 - sort list\n7 - delete duplcates\n9 - leave\nselect: ";
        std::cin >> selection;
        std::cout << "\n-----------------------------------\n";
        switch (selection)
        {
            case 1:
            {
                int elem;
                std::cout << "enter element: ";
                std::cin >> elem;
                list.Push_front(elem);
                std::cout << "\nelement added";
                break;
            }
            case 2:
            {
                int elem;
                std::cout << "enter element: ";
                std::cin >> elem;
                list.Push_back(elem);
                std::cout << "\nelement added";
                break;
            }
            case 3:
            {
                list.Pop_front();
                std::cout << "\nremoved front element";
                break;
            }
            case 4:
            {
                list.Pop_back();
                std::cout << "\nremoved back element";
                break;
            }
            case 5:
            {
                list.Display();
                break;
            }
            case 6:
            {
                list.Sort();
                std::cout << "\nsorted";
                break;
            }
            case 7:
            {
                list.DeleteDuplicates();
                std::cout << "\ndeleted duplicates";
                break;
            }
        }
    } while (selection != 8);

}