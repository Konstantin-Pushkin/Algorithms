#include <iostream>
#include <cstdint>
#include <memory>

using std::cout;
using std::endl;
using std::shared_ptr;
using std::make_shared;

class Node
{
public:
    uint64_t data;
    shared_ptr<Node> prev;
    shared_ptr<Node> next;

    explicit Node(uint64_t data): data(data), prev(nullptr), next(nullptr)
    {

    }
};

class DoublyLinkedList
{
public:
    shared_ptr<Node> head;
    shared_ptr<Node> tail;

    DoublyLinkedList() : head(nullptr), tail(nullptr)
    {

    }

    ~DoublyLinkedList() = default;

    shared_ptr<Node> push_front(uint64_t data)
    {
        auto ptr = make_shared<Node>(data);
        ptr->next = head;
        if(head != nullptr)
        {
            head->prev = ptr;
        }

        if(tail == nullptr)
        {
            tail = ptr;
        }

        head = ptr;

        return ptr;
    }

    shared_ptr<Node> push_back(uint64_t data)
    {
        auto ptr = make_shared<Node>(data);
        ptr->prev = tail;
        if(tail != nullptr)
        {
            tail->next = ptr;
        }

        if(head == nullptr)
        {
            head = ptr;
        }

        tail = ptr;

        return ptr;
    }

    void pop_front()
    {
        if(head == nullptr)
        {
            return;
        }

        auto ptr = head->next;
        if(ptr != nullptr)
        {
            ptr->prev.reset();
        }
        else
        {
            tail.reset();
        }

        head = ptr;
    }

    void pop_back()
    {
        if(tail == nullptr)
        {
            return;
        }

        auto ptr = tail->prev;
        if(ptr != nullptr)
        {
            ptr->next.reset();
        }
        else
        {
            head.reset();
        }

        tail = ptr;
    }

    [[nodiscard]] shared_ptr<Node> getAt(uint64_t index) const
    {
        auto ptr = head;
        uint64_t tempCount = 0;

        while(tempCount != index)
        {
            if(ptr == nullptr)
            {
                return nullptr;
            }

            ptr = ptr->next;
            tempCount++;
        }

        return ptr;
    }

    shared_ptr<Node> operator[](uint64_t index) const
    {
        return getAt(index);
    }

    shared_ptr<Node> insert(uint64_t index, uint64_t data)
    {
        auto right = getAt(index);
        if(right == nullptr)
        {
            return push_back(data);
        }

        auto left = right->prev;
        if(left == nullptr)
        {
            return push_front(data);
        }

        auto ptr = make_shared<Node>(data);
        ptr->prev = left;
        ptr->next = right;
        left->next = ptr;
        right->prev = ptr;

        return ptr;
    }

    void erase(uint64_t index)
    {
        auto ptr = getAt(index);
        if(ptr == nullptr)
        {
            return;
        }

        if(ptr->prev == nullptr)
        {
            pop_front();
            return;
        }

        if(ptr->next == nullptr)
        {
            pop_back();
            return;
        }

        auto left = ptr->prev;
        auto right = ptr->next;
        left->next = right;
        right->prev = left;
    }

    void print() const
    {
        auto current = head;
        while(current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }
};

int main()
{
    DoublyLinkedList list;

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
