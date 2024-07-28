#include <iostream>
#include <cstdint>

using std::cout;
using std::endl;

class Node
{
public:
    uint64_t data;
    Node *next;

    explicit Node(uint64_t data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class SinglyLinkedList
{
public:
    Node *head;
    Node *tail;

    SinglyLinkedList()
    {
        this->head = this->tail = nullptr;
    }

    ~SinglyLinkedList()
    {
        while(head != nullptr)
        {
            pop_front();
        }
    }

    void push_back(uint64_t data)
    {
        Node *node = new Node(data);
        if(head == nullptr)
        {
            head = tail = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
    }

    void push_front(uint64_t data)
    {
        Node *node = new Node(data);
        node->next = head;
        head = node;
        if(tail == nullptr)
        {
            tail = node;
        }
    }

    void pop_back()
    {
        if(tail == nullptr)
        {
            return;
        }

        if(head == tail)
        {
            delete tail;
            head = tail = nullptr;
            return;
        }

        Node *node = head;
        while(node->next != tail)
        {
            node = node->next;
        }
        node->next = nullptr;
        delete tail;
        tail = node;
    }

    void pop_front()
    {
        if(head == nullptr)
        {
            return;
        }

        Node *node = head;
        head = node->next;
        if(head == nullptr)
        {
            tail = nullptr;
        }

        delete node;
    }

    void insert(uint64_t pos, uint64_t data)
    {
        if(pos == 0)
        {
            push_front(data);
            return;
        }

        Node *left = getAt(pos - 1);
        if(left == nullptr)
        {
            return;
        }

        Node *right = left->next;
        Node *node = new Node(data);

        left->next = node;
        node->next = right;
        if(right == nullptr)
        {
            tail = node;
        }
    }

    void erase(uint64_t pos)
    {
        if(pos == 0)
        {
            pop_front();
            return;
        }

        Node *left = getAt(pos - 1);
        if(left == nullptr || left->next == nullptr)
        {
            return;
        }

        Node *node = left->next;
        Node *right = node->next;

        left->next = right;
        if(node == tail)
        {
            tail = left;
        }

        delete node;
    }

    void print() const
    {
        Node *current = head;
        while(current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }

private:
    [[nodiscard]] Node *getAt(uint64_t pos) const
    {
        Node *node = head;
        uint64_t index = 0;
        while(node && index < pos)
        {
            node = node->next;
            index++;
        }

        return (index == pos) ? node : nullptr;
    }
};

int main()
{
    SinglyLinkedList list;

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    cout << "List after push_back: ";
    list.print();

    list.push_front(5);
    cout << "List after push_front: ";
    list.print();

    list.insert(2, 15);
    cout << "List after insert at position 2: ";
    list.print();

    list.erase(3);
    cout << "List after erase at position 3: ";
    list.print();

    list.pop_front();
    cout << "List after pop_front: ";
    list.print();

    list.pop_back();
    cout << "List after pop_back: ";
    list.print();

    return EXIT_SUCCESS;
}