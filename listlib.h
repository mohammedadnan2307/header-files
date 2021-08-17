struct Node              // Node for Sorted Linked List
{
    int data;
    Node* next;
}*p = nullptr;          // *p is general purpose pointer
class list
{
public:
    int size;
    Node* head = nullptr, * rear = nullptr;
    void create_list(vector<int>);
    void destroy_list(void);
    void insert_node(int);
    int search_node(int);
    int delete_node(int);
    void reverse(void);
    void display(void);
};
void list::create_list(vector<int> list_data)
{
    size = list_data.size();
    head = new Node;
    head->data = list_data[0];
    head->next = nullptr;
    rear = head;

    for (int i = 1; i < size; ++i)
    {
        p = new Node;
        p->data = list_data[i];
        p->next = nullptr;
        rear->next = p;
        rear = p;
    }
}
void list::destroy_list()
{
    while (head)
    {
        p = head;
        head = head->next;
        delete p;
    }
    size = 0;
    rear = nullptr;
}
void list::display()
{
    cout << endl << "The list is : ";
    p = head;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << "[" << size << "]" << endl;
}
void list::insert_node(int value)
{
    p = new Node;
    p->data = value;
    p->next = nullptr;

    if (head == nullptr)
        head = rear = p;
    else
    {
        Node* q = head, * r = nullptr;
        while ((q) && (q->data < value))
        {
            r = q;
            q = q->next;
        }
        if (q == head)
        {
            p->next = head;
            head = p;
        }
        else if (q == nullptr)
        {
            r->next = p;
            rear = p;
        }
        else
        {
            p->next = r->next;
            r->next = p;
        }
    }
    size = size + 1;
}
void list::reverse()
{
    p = head;
    rear = head;
    Node* q = nullptr, * r = nullptr;
    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
}
int list::search_node(int value)
{
    int index = 0;
    p = head;
    while (p)
    {
        if (p->data == value)
            return index;
        p = p->next;
        ++index;
    }
    return -1;
}
int list::delete_node(int index)
{
    if ((index < 0) || (index >= size) || (head == nullptr))
    {
        cout << "\nERROR !" << '\a' << endl;
        return 0;
    }

    int x;
    p = head;
    if (index == 0)
    {
        head = head->next;
        x = p->data;
        delete p;
    }
    else
    {
        Node* q = nullptr;
        for (int i = 1; i <= index; ++i)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
        if (index == size - 1)
            rear = q;
    }
    size = size - 1;
    return x;
}