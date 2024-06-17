#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include <string>

// Define the Node class template
template <typename T>
class Node {
public:
    T data;
    Node* left;  // Pointer to the left child
    Node* right; // Pointer to the right child

    // Constructor to initialize the data and pointers
    Node(T value) : data(value), left(nullptr), right(nullptr) {}
};

#endif // NODE_HPP