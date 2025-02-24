
/*RAHUL ATKARE
202301040008
A1 , ROLL NO.6
*/

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

// Node structure for the BST
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a node
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Function to insert a new node in BST
Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return new Node(data);
    }

    // If data is smaller, insert in the left subtree
    if (data <= root->data) {
        root->left = insert(root->left, data);
    } 
    // If data is greater, insert in the right subtree
    else {
        root->right = insert(root->right, data);
    }

    return root;
}

// Function to search for an element in BST
int search(Node* root, int data) {
    if (root == nullptr) {
        return 0; // Element not found
    }

    if (root->data == data) {
        return 1; // Element found
    } 
    // Search in left or right subtree based on value
    else if (data < root->data) {
        return search(root->left, data);
    } 
    else {
        return search(root->right, data);
    }
}

// Recursive Preorder Traversal (Root -> Left -> Right)
void preorder(Node* root) {
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Recursive Inorder Traversal (Left -> Root -> Right)
void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Recursive Postorder Traversal (Left -> Right -> Root)
void postorder(Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Non-recursive Preorder Traversal using Stack
void NonRecursivePreorder(Node* root) {
    if(root == NULL) return;

    stack<Node*> s;
    s.push(root);
    while(!s.empty()) {
        Node* curr = s.top();
        s.pop();
        cout << curr->data << " ";
        
        if(curr->right != NULL) {
            s.push(curr->right);
        } 
        if(curr->left != NULL) {
            s.push(curr->left);
        }
    }
}

// Non-recursive Inorder Traversal using Stack
void NonRecursiveInorder(Node* root) {
    if(root == NULL) return;

    stack<Node*> s;
    Node* curr = root;
    while(curr != NULL || !s.empty()) {
        while (curr != NULL) {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }   
}

// Non-recursive Postorder Traversal using two stacks
void NonRecursivePostorder(Node* root) {
    if(root == NULL) return;

    stack<Node*> s1, s2;
    s1.push(root);
    
    while(!s1.empty()) {
        Node* temp = s1.top();
        s1.pop();
        s2.push(temp);

        if(temp->left)
            s1.push(temp->left);
        if(temp->right)
            s1.push(temp->right);
    }

    while(!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

// Function to find the height of the BST
int maxDepth(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);
    return 1 + max(lh, rh);
}

// Function to delete a node from BST
Node* del(Node* root, int value) {
    if (root == nullptr) {
        cout << "No node to delete" << endl;
        return NULL;
    }

    if(value < root->data) {
        root->left = del(root->left, value);
    } 
    else if(value > root->data) {
        root->right = del(root->right, value);
    } 
    else {
        // Case 1: Node has no children (leaf node)
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        // Case 2: Node has only one child
        else if(root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Node has two children
        Node* temp = root->right;
        while(temp->left != nullptr) {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = del(root->right, temp->data);
    }
    return root;
}

// Breadth-First Search (Level Order Traversal)
void BFS(Node* root) {
    if(root == NULL) {
        cout << "Tree is empty" << endl;
        return;
    }

    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";

        if (temp->left != NULL)
            q.push(temp->left);

        if(temp->right != NULL)
            q.push(temp->right);
    }
}

// Main function
int main() {
    int n, ch;
    Node* root = nullptr;
    cout << "How many nodes do you want to insert: ";
    cin >> n;

    if (n <= 0) {
        cout << "Node inserted is invalid" << endl;
        return 0;
    }

    cout << "Enter the nodes" << endl;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        root = insert(root, value);
    }

    // Menu-driven operations
    do {
        cout << "Enter which action do you want to perform:" << endl;
        cout << "1. Search the data\n2. Insert the data\n3. PreOrder (Recursive)\n4. InOrder (Recursive)\n5. PostOrder (Recursive)\n";
        cout << "6. PreOrder (Non-recursive)\n7. InOrder (Non-Recursive)\n8. PostOrder (Non-Recursive)\n";
        cout << "9. BFS (Level Order Traversal)\n10. Height of the Tree\n11. Delete a Node\n12. Exit\n";
        cin >> ch;

        switch (ch) {
            case 1:
                int num;
                cout << "Enter a number to search: ";
                cin >> num;
                cout << (search(root, num) ? "Data found\n" : "Data not found\n");
                break;

            case 2:
                int data;
                cout << "Enter data to insert: ";
                cin >> data;
                root = insert(root, data);
                break;

            case 3: preorder(root); cout << endl; break;
            case 4: inorder(root); cout << endl; break;
            case 5: postorder(root); cout << endl; break;
            case 6: NonRecursivePreorder(root); cout << endl; break;
            case 7: NonRecursiveInorder(root); cout << endl; break;
            case 8: NonRecursivePostorder(root); cout << endl; break;
            case 9: BFS(root); cout << endl; break;
            case 10: cout << "Height: " << maxDepth(root) << endl; break;
            case 11:
                int value;
                cout << "Enter value to delete: ";
                cin >> value;
                root = del(root, value);
                break;
            case 12:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice, try again." << endl;
        }
    } while (ch != 12);

    return 0;
}
