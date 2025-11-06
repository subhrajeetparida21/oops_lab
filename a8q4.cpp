#include <iostream>
#include <stdexcept>
using namespace std;

class EmptyQueueException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Empty Queue Exception: Queue is empty.";
    }
};

class ExhaustedQueueException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Exhausted Queue Exception: Queue capacity exhausted.";
    }
};

class MemoryAllocationException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Memory Allocation Exception: Failed to allocate memory.";
    }
};

struct Node
{
    int data;
    Node *next;
};

class Queue
{
    Node *front;
    Node *rear;
    int size;
    int maxSize;

public:
    Queue(int maxSize)
    {
        this->front = nullptr;
        this->rear = nullptr;
        this->size = 0;
        this->maxSize = maxSize;
    }

    void enqueue(int value)
    {
        if (size >= maxSize)
            throw ExhaustedQueueException();

        Node *newNode = new(nothrow) Node;
        if (!newNode)
            throw MemoryAllocationException();

        newNode->data = value;
        newNode->next = nullptr;

        if (rear == nullptr)
            front = rear = newNode;
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    int dequeue()
    {
        if (front == nullptr)
            throw EmptyQueueException();

        Node *temp = front;
        int val = temp->data;
        front = front->next;

        if (front == nullptr)
            rear = nullptr;

        delete temp;
        size--;
        return val;
    }

    void display()
    {
        if (front == nullptr)
            throw EmptyQueueException();

        Node *temp = front;
        cout << "Queue: ";
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    try
    {
        int maxSize;
        cout << "Enter maximum queue size: ";
        cin >> maxSize;

        Queue q(maxSize);
        int choice, value;

        while (true)
        {
            cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                q.enqueue(value);
                cout << "Enqueued: " << value << endl;
                break;
            case 2:
                cout << "Dequeued: " << q.dequeue() << endl;
                break;
            case 3:
                q.display();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice\n";
            }
        }
    }
    catch (const EmptyQueueException &e)
    {
        cout << "Exception: " << e.what() << endl;
    }
    catch (const ExhaustedQueueException &e)
    {
        cout << "Exception: " << e.what() << endl;
    }
    catch (const MemoryAllocationException &e)
    {
        cout << "Exception: " << e.what() << endl;
    }
    catch (...)
    {
        cout << "Unknown Exception Occurred." << endl;
    }

    return 0;
}
