#include <print>
#include <stack>

template <typename T>
struct Node {
    T data;
    Node* left;
    Node* right;

    Node(T data) : data(data), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinaryTree {
private:
    Node<T>* root;

public:
    BinaryTree() : root(nullptr) {}

    void insert(T data) {
        if (!root) {
            root = new Node<T>(data);
            return;
        }

        Node<T>* current = root;
        while (true) {
            if (data < current->data) {
                if (!current->left) {
                    current->left = new Node<T>(data);
                    return;
                }
                current = current->left;
            } else {
                if (!current->right) {
                    current->right = new Node<T>(data);
                    return;
                }
                current = current->right;
            }
        }
    }

    class Iterator {
    private:
        std::stack<Node<T>*> stack;

    public:
        Iterator(Node<T>* root) {
            while (root) {
                stack.push(root);
                root = root->left;
            }
        }

        bool operator!=(const Iterator& other) const {
            return stack != other.stack;
        }

        T operator*() const {
            return stack.top()->data;
        }

        Iterator& operator++() {
            Node<T>* node = stack.top();
            stack.pop();

            if (node->right) {
                node = node->right;
                while (node) {
                    stack.push(node);
                    node = node->left;
                }
            }

            return *this;
        }
    };

    Iterator begin() const {
        return Iterator(root);
    }

    Iterator end() const {
        return Iterator(nullptr);
    }
};

int main() {
    BinaryTree<int> tree;
    tree.insert(4);
    tree.insert(2);
    tree.insert(6);
    tree.insert(1);
    tree.insert(3);
    tree.insert(5);
    tree.insert(7);

    for (int value : tree) {
        std::print("{} ", value);
    }

    return 0;
}
