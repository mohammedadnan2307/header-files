struct binaryTree_node
{
    int value;
    binaryTree_node* left, * right;
};

struct binaryTree_list
{
    binaryTree_node* address;
    binaryTree_list* next;
};

class binaryTree
{
public:
    binaryTree_list* head = nullptr, * rear = nullptr;
    binaryTree_node* root = nullptr;
    binaryTree_node* searchBinaryNode(int, binaryTree_node*);
    binaryTree_node* insertBinaryNode(int);
    void insertBinaryNode(binaryTree_node*, binaryTree_node*);
    void mirrorBinaryTree(binaryTree_node*);
    void displayBinaryTree(void);
    void displayBinaryTree(binaryTree_node*);
    void createBinaryTree(vector<int>);
    void destroyBinaryTree(void);
    void searchBinaryNode(int);
};
void binaryTree::insertBinaryNode(binaryTree_node* node, binaryTree_node* p)
{
    if (node->value <= p->value)
    {
        if (node->right == nullptr)
        {
            node->right = p;
            return;
        }
        else return insertBinaryNode(node->right, p);
    }
    else
    {
        if (node->left == nullptr)
        {
            node->left = p;
            return;
        }
        else return insertBinaryNode(node->left, p);
    }
}
binaryTree_node* binaryTree::searchBinaryNode(int key, binaryTree_node* node)
{
    if ((node == nullptr) || (node->value == key))
        return node;
    else if (node->value < key)
        return searchBinaryNode(key, node->right);
    else
        return searchBinaryNode(key, node->left);
}
void binaryTree::searchBinaryNode(int key)
{
    searchBinaryNode(key, root);
}
binaryTree_node* binaryTree::insertBinaryNode(int value)
{
    binaryTree_node* p = new binaryTree_node;
    p->value = value;
    p->left = p->right = nullptr;

    binaryTree_list* x = new binaryTree_list;
    x->address = p;
    x->next = nullptr;
    rear->next = x;
    rear = x;

    insertBinaryNode(root, p);
    return p;
}
void binaryTree::destroyBinaryTree(void)
{
    binaryTree_list* x;
    while (head)
    {
        x = head;
        head = head->next;
        delete (x->address);
        delete x;
    }
}
void binaryTree::displayBinaryTree(binaryTree_node* node)
{
    if (node == nullptr)
        return;
    displayBinaryTree(node->left);
    cout << node->value << " ";
    displayBinaryTree(node->right);
}
void binaryTree::displayBinaryTree(void)
{
    displayBinaryTree(root);
}
void binaryTree::createBinaryTree(vector<int> tree_data)
{
    if (tree_data.size() == 0)
        return;

    root = new binaryTree_node;
    root->value = tree_data[0];
    root->left = root->right = nullptr;

    head = new binaryTree_list;
    head->address = root;
    head->next = nullptr;
    rear = head;

    for (int i = 1; i < tree_data.size(); ++i)
        insertBinaryNode(tree_data[i]);
}
void binaryTree::mirrorBinaryTree(binaryTree_node* node)
{
    if (node == nullptr)
        return;
    else
    {
        mirrorBinaryTree(node->left);
        mirrorBinaryTree(node->right);

        binaryTree_node* temp = node->right;
        node->right = node->left;
        node->left = temp;
    }
}