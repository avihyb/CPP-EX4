#ifndef NODE_HPP
#define NODE_HPP

#include <vector>

template <typename T>
class Node {
public:
    T value;
    std::vector<Node<T>*> children;

    Node(T val) : value(val) {}

    T get_value() const { return value; }

    void add_child(const Node<T>& child) {
        children.push_back(new Node<T>(child));
    }

    std::vector<Node<T>*> get_children() const { return children; }
};

#endif // NODE_HPP