#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>
class Tree {

public:

    T value;
    Tree<T>** children;
    int num_children;
    int capacity;

    Tree() : value(), children(nullptr), num_children(0), capacity(0) {}

    Tree(const T& val) : value(val), children(nullptr), num_children(0), capacity(0) {}

    Tree(const Tree<T>& other) : value(other.value), num_children(other.num_children), capacity(other.capacity) {

        children = new Tree<T>*[capacity];

        for (int i = 0; i < num_children; i++) {

            children[i] = new Tree<T>(*other.children[i]);

        }
    }

    ~Tree() {

        for (int i = 0; i < num_children; i++) {

            delete children[i];

        }

        delete[] children;

    }

    Tree<T>* add_node(const T& val, Tree<T>* parent = nullptr) {

        Tree<T>* new_node = new Tree<T>(val);

        if (parent == nullptr)
            parent = this;

        if (parent->num_children == parent->capacity) {

            int new_capacity = parent->capacity == 0 ? 1 : 2 * parent->capacity;

            Tree<T>** new_children = new Tree<T>*[new_capacity];

            for (int i = 0; i < parent->num_children; i++)
                new_children[i] = parent->children[i];

            delete[] parent->children;

            parent->children = new_children;
            parent->capacity = new_capacity;

        }

        parent->children[parent->num_children++] = new_node;

        return new_node;

    }

    Tree<T>* get_node(int index, Tree<T>* parent = nullptr) {

        if (parent == nullptr)
            parent = this;

        if (index >= 0 && index < parent->num_children)
            return parent->children[index];
        else
            return nullptr;

    }

    void delete_node(Tree<T>* node) {

        if (node == nullptr)
            return;

        Tree<T>* parent = nullptr;

        for (int i = 0; i < num_children; i++) {

            if (children[i] == node) {

                parent = this;

                for (int j = i + 1; j < num_children; j++)
                    children[j - 1] = children[j];

                children[--num_children] = nullptr;

                break;

            }
        }
        if (parent == nullptr)
            for (int i = 0; i < num_children; i++)
                children[i]->delete_node(node);

    }

    Tree<T>* find(bool (*cmp)(const T&)) {  //callback

        if (cmp(value))
            return this;

        for (int i = 0; i < num_children; i++) {

            Tree<T>* found = children[i]->find(cmp);

            if (found != nullptr)
                return found;

        }

        return nullptr;

    }

    void insert(const T& val, Tree<T>* parent, int index) {

        Tree<T>* new_node = new Tree<T>(val);

        if (parent == nullptr)
            parent = this;

        if (parent->num_children == parent->capacity) {

            int new_capacity = parent->capacity == 0 ? 1 : 2 * parent->capacity;

            Tree<T>** new_children = new Tree<T>*[new_capacity];

            std::copy(parent->children, parent->children + parent->num_children, new_children);

            delete[] parent->children;

            parent->children = new_children;
            parent->capacity = new_capacity;

        }

        if (index < 0)
            index = 0;

        if (index > parent->num_children)
            index = parent->num_children;

        for (int i = parent->num_children - 1; i >= index; i--)
            parent->children[i + 1] = parent->children[i];

        parent->children[index] = new_node;
        parent->num_children++;

    }

    void sort(bool (*cmp)(const T&) = nullptr) {

        if (num_children > 0) {

            if (cmp == nullptr)
                std::sort(children, children + num_children, [](const Tree<T>* a, const Tree<T>* b) {return a->value < b->value; });
            else
                std::sort(children, children + num_children, [cmp](const Tree<T>* a, const Tree<T>* b) {return cmp(a->value) < cmp(b->value); });

            for (int i = 0; i < num_children; i++)
                children[i]->sort(cmp);

        }

    }

    int count(Tree<T>* parent = nullptr) const {

        if (parent == nullptr)
            parent = const_cast<Tree<T>*>(this);

        int total_count = parent->num_children;

        for (int i = 0; i < parent->num_children; i++)
            total_count += parent->children[i]->count();

        return total_count;

    }

    int count_if(const Tree<T>* node, bool (*condition)(const T&)) {

        if (node == nullptr)
            return 0;

        int count = condition(node->value) ? 1 : 0;

        for (int i = 0; i < node->num_children; i++)
            count += count_if(node->children[i], condition);

        return count;

    }

};

bool is_even(const int& n) {

    return n % 2 == 0;

}

int main() {

    Tree<int> root(0);

    Tree<int>* n1 = root.add_node(1);
    Tree<int>* n2 = root.add_node(2);
    Tree<int>* n3 = root.add_node(3);

    n1->add_node(4);
    n1->add_node(5);

    n2->add_node(6);
    n2->add_node(7);

    n3->add_node(8);
    n3->add_node(9);
    n3->add_node(10);

    std::cout << "Number of nodes: " << root.count() << '\n';

    Tree<int>* found = root.find([](const int& n) {
        return n == 7;
        });
    if (found != nullptr) {
        std::cout << "Found node with value 7" << '\n';
    }
    else {
        std::cout << "Could not find node with value 7" << '\n';
    }

    root.insert(11, n3, 1);

    std::cout << "Sorted children of node 3: ";
    n3->sort();
    for (int i = 0; i < n3->num_children; i++) {
        std::cout << n3->children[i]->value << " ";
    }
    std::cout << '\n';

    std::cout << "Number of even nodes: " << root.count_if(&root, is_even) << '\n';

    root.delete_node(n2);

    std::cout << "Number of nodes after deleting node 2: " << root.count() << '\n';

    return 0;

}
