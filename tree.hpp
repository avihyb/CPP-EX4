#ifndef TREE_HPP
#define TREE_HPP



template <typename T>

class Tree {
    public:
        Tree();  // Constructor
        ~Tree(); // Destructor
        void add_root(Node<T> root_node);

    private:
        Node<T> root;
        
};

#endif // TREE_HPP