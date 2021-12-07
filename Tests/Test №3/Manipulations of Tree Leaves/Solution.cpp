#include <iostream> 
#include <deque>


using namespace std;

class Node {
public:
    int data;
    Node* leftNode;
    Node* rightNode;
    Node(int d) {
        data = d;
        leftNode = NULL;
        rightNode = NULL;
    }
};

class Solution {
public:
    Node* insert(Node* root, int data) {
        if (root == NULL) {
            return new Node(data);
        }
        else {
            Node* cur;
            if (data <= root->data) {
                cur = insert(root->leftNode, data);
                root->leftNode = cur;
            }
            else {
                cur = insert(root->rightNode, data);
                root->rightNode = cur;
            }

            return root;
        }
    }


    void leaves(Node* root) {
        if (root == nullptr)
            cout << "0";

        deque<Node*> q;
        q.push_back(root);
        int sum = 0;

        while (q.size() != 0)
        {
            Node* curr = q.front();

            if (curr->leftNode != nullptr)
                q.push_back(curr->leftNode);
            if (curr->rightNode != nullptr)
                q.push_back(curr->rightNode);

            if (curr->rightNode == nullptr && curr->leftNode == nullptr && curr->data % 2 != 0)
                sum += curr->data;

            q.pop_front();
        }

        cout << sum;
    }


}; //End of Solution

int main() {

    Solution myTree;
    Node* root = NULL;

    int t;
    int data;

    std::cin >> t;

    while (t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    myTree.leaves(root);
    return 0;
}
