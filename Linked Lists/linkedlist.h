struct linkedList_node
{
    int data;
    linkedList_node* next;
}*p = nullptr;  

class linkedList
{
public:
    unsigned int size;
    linkedList_node* head = nullptr, * rear = nullptr;
    linkedList_node* insertNode(int);
    linkedList_node* searchNode(int);
    void createList(vector<int>);
    void destroyList(void);
    void reverseList(void);
    void displayList(void);
    int deleteNode(int);
};

void linkedList::createList(vector<int> list_data)
{
    size = list_data.size();
    if (size == 0) return;

    head = new linkedList_node;
    head->data = list_data[0];
    head->next = nullptr;
    rear = head;

    for (int i = 1; i < size; ++i)
    {
        p = new linkedList_node;
        p->data = list_data[i];
        p->next = nullptr;
        rear->next = p;
        rear = p;
    }
}
void linkedList::destroyList()
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
void linkedList::displayList()
{
    p = head;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
}
linkedList_node* linkedList::insertNode(int value)
{
    p = new linkedList_node;
    p->data = value;
    p->next = nullptr;

    if (head == nullptr)
        head = rear = p;
    else
    {
        linkedList_node* q = head, * r = nullptr;
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
    return p;
}
void linkedList::reverseList()
{
    p = head;
    rear = head;
    linkedList_node* q = nullptr, * r = nullptr;
    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
}
linkedList_node* linkedList::searchNode(int value)
{
    p = head;
    while (p)
    {
        if (p->data == value)
            return p;
        p = p->next;
    }
    return nullptr;
}
int linkedList::deleteNode(int index)
{
    if ((index < 0) || (index >= size) || (head == nullptr))
    {
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
        linkedList_node* q = nullptr;
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
