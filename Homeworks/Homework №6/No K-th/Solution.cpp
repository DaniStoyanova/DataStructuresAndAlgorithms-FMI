#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std; 

class BST
{
    int data;
    BST* left, * right;

public:
    BST();
    BST(int);

    BST* insert(BST*, int);
    BST* minValueNode(BST* node);
    BST* deleteNode(BST* root, int key);

    void printLevelOrder(BST* root);
};

BST::BST(): data(0), left(nullptr), right(nullptr){}

BST::BST(int value)
{
    data = value;
    left =  nullptr;
    right = nullptr; 
}

BST* BST::insert(BST* root, int value)
{
    if (!root)
    {
        return new BST(value);
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }

    return root;
}

BST* BST::minValueNode(BST* node)
{
    BST* current = node;

    while (current != nullptr && current->left != nullptr)
        current = current->left;

    return current;
}

BST* BST::deleteNode(BST* root, int data)
{
    if (root == nullptr)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else 
    {
        if (root->left == nullptr and root->right == nullptr)
            return nullptr;
        else if (root->right == nullptr)
        {
            BST* temp = root->left;
            free(root);
            return temp;
        }
        else if (root->left == nullptr)
        {
            BST* temp = root->right;
            free(root);
            return temp;
        }
        else
        {
            BST* temp = minValueNode(root->right);

            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

void BST::printLevelOrder(BST* root)
{
    if (root == nullptr) return;

    queue<BST*> p;
    p.push(root);

    while (p.empty() == false)
    {
        int counter = p.size();

        while (counter > 0)
        {
            BST* node = p.front();
            cout << node->data << " ";
            p.pop();
            if (node->left != nullptr)
                p.push(node->left);
            if (node->right != nullptr)
                p.push(node->right);
            counter--;
        }
    }
}


int main()
{
    int N, K; 
    cin >> N >> K; 

    int num; 
    cin >> num; 

    BST b; 
    BST* root = nullptr;
    root = b.insert(root, num);

    vector<int> numbers; 
    numbers.push_back(num);

    for (int i = 0; i < N - 1; i++)
    {
        int num1; 
        cin >> num1; 
        b.insert(root, num1);
        numbers.push_back(num1);
    }

    sort(numbers.begin(), numbers.end());
    b.deleteNode(root, numbers[N - K]);
    b.printLevelOrder(root);

    return 0;
}
