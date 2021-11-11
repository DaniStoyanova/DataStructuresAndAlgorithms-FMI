#include <iostream>
#include <string>

using namespace std;

class Node 
{
public:
    int data;
    Node* prev;
    Node* next;

    Node(int node_data) 
    {
        this->data = node_data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class List 
{
public:
    Node* head;
    Node* mid;
    Node* tail;

    int mid_ind; 
    int num_elements;

    List() 
    {
        this->head = NULL;
        this->tail = NULL;
        this->mid = NULL;

        num_elements = 0; 
        mid_ind = 0; 
    }

    void add(int newElement) 
    {
        Node* temp;
        temp = new Node(newElement);
        temp->prev = tail;

        if (tail == NULL)
        {
            head = temp;
        }
        else
            tail->next = temp;

        tail = temp;
        num_elements++;

        if (num_elements == 1)
        {
            mid = temp;
        }
        else if (num_elements / 2 != mid_ind)
        {
            mid = mid->next;
            mid_ind = num_elements / 2; 
        }
    }

    void gun() 
    {
        Node* nodeToDelete = tail;
        tail = tail->prev;

        if (tail)
            tail->next = NULL;
        else
        {
            mid = NULL;
            head = NULL;
        }

        delete nodeToDelete;
        num_elements--;

        if (num_elements == 0)
        {
            mid = NULL;
        }
        else if (num_elements == 1)
        {
            mid = head;
        }
        else if (num_elements / 2 != mid_ind)
        {
            mid = mid->prev;
        }
        mid_ind = num_elements / 2;
    }

    void milen()
    {
        Node* a = tail;
        Node* b = head; 
        tail->next = head;
        head->prev = tail; 
        tail = mid->prev;
        tail->next = nullptr;
        head = mid;

        if (num_elements % 2 == 0)
        {
            mid = b; 
        }
        else 
        {
            mid = a; 
        }
    }

    void print() const
    {
        cout << num_elements << endl;

        Node* current = head;

        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    int N; 
    cin >> N;

    List my_list; 

    for (int i = 0; i < N; i++)
    {
        string input; 
        cin >> input;

        if (input == "gun")
        {
            my_list.gun();
        }
        else if (input == "add")
        {
            int num;
            cin >> num;
            my_list.add(num);
        }
        else
            my_list.milen(); 
    }

    my_list.print(); 
}
