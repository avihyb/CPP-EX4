#include <iostream>
#include <string>
#include "node.hpp"
#include "tree.hpp" 
#include "complex.hpp"

using namespace std;
int main()
{
    // Binary tree
    Node<double> root_node = Node<double>(1.1);
    Tree<double> tree; // Binary tree that contains doubles.
    tree.add_root(root_node);
    Node<double> n1 = Node<double>(1.2);
    Node<double> n2 = Node<double>(1.3);
    Node<double> n3 = Node<double>(1.4);
    Node<double> n4 = Node<double>(1.5);
    Node<double> n5 = Node<double>(1.6);
    
    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);
    //tree.add_sub_node(root_node, n3); // This should throw an exception.
    cout << tree;
    // tree.add_sub_node(n5, n1);
    // cout << tree;

    Complex c1(1, 2);
    Complex c2(3, 4);
    Tree<Complex> tree2;
    Node<Complex> complexRoot = Node<Complex>(c1);
    tree2.add_root(complexRoot);
    Node<Complex> n12 = Node<Complex>(c2);
    tree2.add_sub_node(complexRoot, n12);
    cout << tree2;

    // Print various traversals
    cout << "Pre-Order Traversal:" << endl;
    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
        cout << (*node)->get_value() << endl;
    }

    cout << "Post-Order Traversal:" << endl;
    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node) {
        cout << (*node)->get_value() << endl;
    }

    cout << "In-Order Traversal:" << endl;
    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node) {
        cout << (*node)->get_value() << endl;
    }

    cout << "BFS Traversal:" << endl;
    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node) {
        cout << (*node)->get_value() << endl;
    }

    cout << "DFS Traversal:" << endl;
    for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node) {
        cout << (*node)->get_value() << endl;
    }

    // 3-ary tree
    Tree<int, 3> three_ary_tree; // 3-ary tree.
    Node<int> int_root_node = Node<int>(1);
    three_ary_tree.add_root(int_root_node);

    Node<int> int_n1 = Node<int>(2);
    Node<int> int_n2 = Node<int>(3);
    Node<int> int_n3 = Node<int>(4);
    Node<int> int_n4 = Node<int>(5);
    Node<int> int_n5 = Node<int>(6);

    three_ary_tree.add_sub_node(int_root_node, int_n1);
    three_ary_tree.add_sub_node(int_root_node, int_n2);
    three_ary_tree.add_sub_node(int_root_node, int_n3);
    three_ary_tree.add_sub_node(int_n1, int_n4);
    three_ary_tree.add_sub_node(int_n2, int_n5);

    // Print 3-ary tree DFS traversal
    cout << "3-ary Tree DFS Traversal:" << endl;
    for (auto node = three_ary_tree.begin_dfs_scan(); node != three_ary_tree.end_dfs_scan(); ++node) {
        cout << (*node)->get_value() << endl;
    }

    return 0;
}

// The binary tree should look like:
    /**
     *       root = 1
     *     /   |   \
     *    2    3    4
     *   /      \
     *  5        6
     */
// The treeary tree should look like:
    /**
     *     root = 1.1
     *     /       \
     *    1.2      1.3
     *   /  \      /
     *  1.4  1.5  1.6
     */