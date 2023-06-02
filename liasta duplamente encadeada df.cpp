#include <iostream>
 
using namespace std;
 
void menu();        //construindo as instuções do menu
 
struct Node
{
    int data;
    Node* next;
    Node* prev;
    Node(int);
};
 
Node::Node(int value)       // Construtor da arvore
{
    data = value;
    next = prev = NULL;
}
 
class DoublyLinkedList
{
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void insert_front(int);
    void insert_back(int);
    int delete_front();
    int delete_back();
    bool is_empty();
    void display();
    int length();
    void search(int);
 
private:
    Node* head;
    Node* tail;
    int size;
 
};
 
DoublyLinkedList::DoublyLinkedList()
{
    head = tail = NULL;
    size = 0;
}
 
DoublyLinkedList::~DoublyLinkedList()
{
}
 
void DoublyLinkedList::insert_front(int value)// insere na cabeca
{
    Node* temp = new Node(value);
 
    if (head == NULL)
        head = tail = temp;
    else if(head!=NULL)
    {
        head->prev = temp;
        temp->next = head;
        head = temp;
    }
    else
    {
        temp = NULL;
    }
    size++;
}
 
void DoublyLinkedList::insert_back(int value)// insere na cauda
{
    Node* temp = new Node(value);
 
    if (tail == NULL)
        head = tail = temp;
    else if(tail!=NULL)
    {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    else
    {
        temp = NULL;
    }
    size++;
}
 
int DoublyLinkedList::delete_front()//delete no cabeca
{
    if (!is_empty())
    {
        Node* temp = head;
        if (head == tail)
        {
            tail = NULL;
        }
        int delValue = temp->data;
        head = head->next;
 
        delete temp;
 
        size--;
 
        return delValue;
 
    }
    return 0;
}
 
int DoublyLinkedList::delete_back()// delete no calda
{
    if (!is_empty())
    {
        Node* temp = tail;
        if (head == tail)
        {
            head = NULL;
        }
        int delValue = temp->data;
        tail->next = NULL;
        tail = tail->prev;
 
        delete temp;
 
        size--;
 
        return delValue;
 
    }
    return 0;
}
 
bool DoublyLinkedList::is_empty()//lista vazia
{
    if (size <= 0)
    {
        return true;
    }
 
    return false;
}
 
void DoublyLinkedList::display()//lista com conteudo sera exibida
{
    Node* temp = head;
 
    cout << "\n\nDisplay in forward order\n";
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << " NULL";
}
 
int DoublyLinkedList::length()//tamanho
{
    return size;
}
 
void DoublyLinkedList::search(int value)//busca no
{
    if (!is_empty())
    {
        Node* temp = head;
        while (temp)
        {
            if (temp->data == value)
            {
                cout << "YES! got it." << endl;
                break;
            }
            temp = temp->next;
        }
    }
    else
    {
        cout << "List is empty" << endl;
    }
}
 
 
int main()
{
    DoublyLinkedList* dll = new DoublyLinkedList();
 
    menu();
 
    int choice, nn;
 
    do
    {
        cout << "\nEnter your option: ";
        cin >> choice;
 
        switch (choice)
        {
        case 1:
            cout << "Enter data: ";
            cin >> nn;
            dll->insert_front(nn);
            break;
 
        case 2:
            cout << "Enter data: ";
            cin >> nn;
            dll->insert_back(nn);
            break;
 
        case 3:
            cout << "Deleted value is: " << dll->delete_front();
            break;
 
        case 4:
            cout << "Deleted value is: " << dll->delete_back();
            break;
 
        case 5:
            dll->display();
            break;
 
        case 6:
            cout << "Total Nodes = " << dll->length();
            break;
 
        case 7:
            int searchVal;
            cout << "Enter search data: ";
            cin >> searchVal;
            dll->search(searchVal);
            break;
 
        default:
            cout << "Sorry Wrong choice" << endl;
            break;
        }
    } while (choice != 8);
 
    return 0;
}
 
void menu()
{
    cout << "-------- MENU ---------" << endl
        << "1. Insert at Front" << endl
        << "2. Insert at Back" << endl
        << "3. Delete from front" << endl
        << "4. Delete from Back" << endl
        << "5. Display" << endl
        << "6. Total Nodes" << endl
        << "7. Search" << endl
        << "8. Exit" << endl;
}