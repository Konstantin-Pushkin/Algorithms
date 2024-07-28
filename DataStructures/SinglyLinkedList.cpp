#include <iostream>
#include <cstdint>
#include <memory>

using std::cout;
using std::endl;
using std::unique_ptr;
using std::make_unique;

class Node
{
public:
    uint64_t data;
    unique_ptr<Node> next;

    explicit Node(uint64_t data) : data(data), next(nullptr) {}
};

class SinglyLinkedList
{
public:
    unique_ptr<Node> head;
    Node *tail;

    SinglyLinkedList() : head(nullptr), tail(nullptr) {}

    void push_back(uint64_t data)
    {
        auto node = make_unique<Node>(data);
        if(head == nullptr)
        {
            head = std::move(node);
            tail = head.get();
        }
        else
        {
            tail->next = std::move(node);
            tail = tail->next.get();
        }
    }

    void push_front(uint64_t data)
    {
        auto node = make_unique<Node>(data);
        node->next = std::move(head);
        head = std::move(node);
        if(tail == nullptr)
        {
            tail = head.get();
        }
    }

    void pop_back()
    {
        if(tail == nullptr)
        {
            return;
        }

        if(head.get() == tail)
        {
            head.reset();
            tail = nullptr;
            return;
        }

        Node *node = head.get();
        while(node->next.get() != tail)
        {
            node = node->next.get();
        }
        node->next.reset();
        tail = node;
    }

    void pop_front()
    {
        if(head == nullptr)
        {
            return;
        }

        head = std::move(head->next);
        if(head == nullptr)
        {
            tail = nullptr;
        }
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

        auto node = make_unique<Node>(data);
        node->next = std::move(left->next);
        left->next = std::move(node);
        if(left->next->next == nullptr)
        {
            tail = left->next.get();
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

        left->next = std::move(left->next->next);
        if(left->next == nullptr)
        {
            tail = left;
        }
    }

    void print() const
    {
        Node *current = head.get();
        while(current != nullptr)
        {
            cout << current->data << " ";
            current = current->next.get();
        }

        cout << endl;
    }

private:
    [[nodiscard]] Node *getAt(uint64_t pos) const
    {
        Node *node = head.get();
        uint64_t index = 0;
        while(node && index < pos)
        {
            node = node->next.get();
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