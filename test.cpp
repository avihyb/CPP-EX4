#include "doctest.h"
#include "complex.hpp"
#include "node.hpp"
#include "tree.hpp"
#include <iostream>
#include <sstream>

/*
    Test Cases:
    
    - Invalid tree operation: Adding a 3rd node to a binary tree
    - Invalid tree operation: Adding a sub-node to a non-existent parent node
    - Parent node not found
    - Root already exists
    
    - Pre order traversal
    - Post order traversal
    - In order traversal
    - BFS traversal
    - DFS traversal
    - 3-ary tree DFS traversal
    - 3-ary DFS traversal
    - Heap Traversal
*/
using namespace std;

TEST_CASE("Invalid tree operation: Adding a 3rd node to a binary tree")
{
    Node<double> root_node = Node<double>(1.1);
    Tree<double> tree;
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

    CHECK_THROWS(tree.add_sub_node(root_node, n1));
}

TEST_CASE("Invalid tree operation: Adding a sub-node to a non-existent parent node")
{
    Tree<double> tree;
    Node<double> parent_node = Node<double>(1.1);
    Node<double> sub_node = Node<double>(1.2);

    CHECK_THROWS(tree.add_sub_node(parent_node, sub_node));
}

TEST_CASE("Parent node not found"){
    Tree<double> tree;
    Node<double> parent_node = Node<double>(1.1);
    Node<double> sub_node = Node<double>(1.2);

    CHECK_THROWS(tree.add_sub_node(parent_node, sub_node));
}

TEST_CASE("Root already exists"){
    Node<double> root_node = Node<double>(1.1);
    Tree<double> tree;
    tree.add_root(root_node);

    CHECK_THROWS(tree.add_root(root_node));
}

TEST_CASE("Pre order traversal"){
    Node<double> root_node = Node<double>(1.1);
    Tree<double> tree;
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

    stringstream ss;
    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
        ss << (*node)->get_value() << " ";
    }

    CHECK(ss.str() == "1.1 1.2 1.4 1.5 1.3 1.6 ");
}

TEST_CASE("Post order traversal"){
    Node<double> root_node = Node<double>(1.1);
    Tree<double> tree;
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

    stringstream ss;
    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node) {
        ss << (*node)->get_value() << " ";
    }

    CHECK(ss.str() == "1.4 1.5 1.2 1.6 1.3 1.1 ");
}

TEST_CASE("In order traversal"){
    Node<double> root_node = Node<double>(1.1);
    Tree<double> tree;
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

    stringstream ss;
    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node) {
        ss << (*node)->get_value() << " ";
    }

    CHECK(ss.str() == "1.4 1.2 1.5 1.1 1.6 1.3 ");
}

TEST_CASE("BFS traversal"){
    Node<double> root_node = Node<double>(1.1);
    Tree<double> tree;
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

    stringstream ss;
    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node) {
        ss << (*node)->get_value() << " ";
    }

    CHECK(ss.str() == "1.1 1.2 1.3 1.4 1.5 1.6 ");
}

TEST_CASE("DFS traversal"){
    Node<double> root_node = Node<double>(1.1);
    Tree<double> tree;
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

    stringstream ss;
    for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node) {
        ss << (*node)->get_value() << " ";
    }

    CHECK(ss.str() == "1.1 1.2 1.4 1.5 1.3 1.6 ");
}

TEST_CASE("3-ary tree DFS traversal"){
    Tree<int, 3> three_ary_tree;
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

    stringstream ss;
    for (auto node = three_ary_tree.begin_dfs_scan(); node != three_ary_tree.end_dfs_scan(); ++node) {
        ss << (*node)->get_value() << " ";
    }

    CHECK(ss.str() == "1 2 5 3 6 4 ");
}

TEST_CASE("3-ary DFS traversal"){
    Tree<int, 3> three_ary_tree;
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

    stringstream ss;
    for (auto node = three_ary_tree.begin_dfs_scan(); node != three_ary_tree.end_dfs_scan(); ++node) {
        ss << (*node)->get_value() << " ";
    }

    CHECK(ss.str() == "1 2 5 3 6 4 ");
}

TEST_CASE("Test myHeap Traversal"){
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

    stringstream ss;
    for (auto node = tree.begin_heap(); node != tree.end_heap(); ++node) {
        ss << (*node)->get_value() << " ";
    }

    CHECK(ss.str() == "1.1 1.2 1.4 1.5 1.3 1.6 ");
}

TEST_CASE("Complex Tree: DFS Traversal"){
    Tree<Complex> complex_tree;
    Node<Complex> complex_root_node = Node<Complex>(Complex(1, 2));
    complex_tree.add_root(complex_root_node);
    Node<Complex> complex_n1 = Node<Complex>(Complex(3, 4));
    complex_tree.add_sub_node(complex_root_node, complex_n1);
    Node<Complex> complex_n2 = Node<Complex>(Complex(5, 6));
    complex_tree.add_sub_node(complex_root_node, complex_n2);

    stringstream ss;
    for (auto node = complex_tree.begin_dfs_scan(); node != complex_tree.end_dfs_scan(); ++node) {
        ss << (*node)->get_value() << " ";
    }

    CHECK(ss.str() == "1+2i 3+4i 5+6i ");
}

TEST_CASE("Complex Tree: BFS Traversal"){
    Tree<Complex> complex_tree;
    Node<Complex> complex_root_node = Node<Complex>(Complex(1, 2));
    complex_tree.add_root(complex_root_node);
    Node<Complex> complex_n1 = Node<Complex>(Complex(3, 4));
    complex_tree.add_sub_node(complex_root_node, complex_n1);
    Node<Complex> complex_n2 = Node<Complex>(Complex(5, 6));
    complex_tree.add_sub_node(complex_root_node, complex_n2);

    stringstream ss;
    for (auto node = complex_tree.begin_bfs_scan(); node != complex_tree.end_bfs_scan(); ++node) {
        ss << (*node)->get_value() << " ";
    }

    CHECK(ss.str() == "1+2i 3+4i 5+6i ");
}

TEST_CASE("Complex Tree: Pre Order Traversal"){
    Tree<Complex> complex_tree;
    Node<Complex> complex_root_node = Node<Complex>(Complex(1, 2));
    complex_tree.add_root(complex_root_node);
    Node<Complex> complex_n1 = Node<Complex>(Complex(3, 4));
    complex_tree.add_sub_node(complex_root_node, complex_n1);
    Node<Complex> complex_n2 = Node<Complex>(Complex(5, 6));
    complex_tree.add_sub_node(complex_root_node, complex_n2);

    stringstream ss;
    for (auto node = complex_tree.begin_pre_order(); node != complex_tree.end_pre_order(); ++node) {
        ss << (*node)->get_value() << " ";
    }

    CHECK(ss.str() == "1+2i 3+4i 5+6i ");
}

TEST_CASE("Complex Tree: Post Order Traversal"){
    Tree<Complex> complex_tree;
    Node<Complex> complex_root_node = Node<Complex>(Complex(1, 2));
    complex_tree.add_root(complex_root_node);
    Node<Complex> complex_n1 = Node<Complex>(Complex(3, 4));
    complex_tree.add_sub_node(complex_root_node, complex_n1);
    Node<Complex> complex_n2 = Node<Complex>(Complex(5, 6));
    complex_tree.add_sub_node(complex_root_node, complex_n2);

    stringstream ss;
    for (auto node = complex_tree.begin_post_order(); node != complex_tree.end_post_order(); ++node) {
        ss << (*node)->get_value() << " ";
    }

    CHECK(ss.str() == "3+4i 5+6i 1+2i ");
}

TEST_CASE("Complex Tree: In Order Traversal"){
    Tree<Complex> complex_tree;
    Node<Complex> complex_root_node = Node<Complex>(Complex(1, 2));
    complex_tree.add_root(complex_root_node);
    Node<Complex> complex_n1 = Node<Complex>(Complex(3, 4));
    complex_tree.add_sub_node(complex_root_node, complex_n1);
    Node<Complex> complex_n2 = Node<Complex>(Complex(5, 6));
    complex_tree.add_sub_node(complex_root_node, complex_n2);

    stringstream ss;
    for (auto node = complex_tree.begin_in_order(); node != complex_tree.end_in_order(); ++node) {
        ss << (*node)->get_value() << " ";
    }

    CHECK(ss.str() == "3+4i 1+2i 5+6i ");
}

TEST_CASE("Complex Tree: Heap Traversal"){
    Tree<Complex> complex_tree;
    Node<Complex> complex_root_node = Node<Complex>(Complex(1, 2));
    complex_tree.add_root(complex_root_node);
    Node<Complex> complex_n1 = Node<Complex>(Complex(3, 4));
    complex_tree.add_sub_node(complex_root_node, complex_n1);
    Node<Complex> complex_n2 = Node<Complex>(Complex(5, 6));
    complex_tree.add_sub_node(complex_root_node, complex_n2);

    stringstream ss;
    for (auto node = complex_tree.begin_heap(); node != complex_tree.end_heap(); ++node) {
        ss << (*node)->get_value() << " ";
    }

    CHECK(ss.str() == "1+2i 3+4i 5+6i ");
}



TEST_CASE("Test Complex Operators"){
    Complex c1(1, 2);
    Complex c2(3, 4);
    Complex c3 = c1 + c2;
    CHECK(c3.get_real() == 4);
    CHECK(c3.get_imag() == 6);
    Complex c4 = c1 - c2;
    CHECK(c4.get_real() == -2);
    CHECK(c4.get_imag() == -2);
    Complex c5 = c1 * c2;
    CHECK(c5.get_real() == -5);
    CHECK(c5.get_imag() == 10);
    Complex c6 = c1 / c2;
    CHECK(c6.get_real() == 0.44);
    CHECK(c6.get_imag() == 0.08);
    Complex c7 = -c1;
    CHECK(c7.get_real() == -1);
    CHECK(c7.get_imag() == -2);
    c1 += c2;
    CHECK(c1.get_real() == 4);
    CHECK(c1.get_imag() == 6);
    c1 -= c2;
    CHECK(c1.get_real() == 1);
    CHECK(c1.get_imag() == 2);
    c1 *= c2;
    CHECK(c1.get_real() == -5);
    CHECK(c1.get_imag() == 10);
    c1 /= c2;
    CHECK(c1.get_real() == 1);
    CHECK(c1.get_imag() == 2);
    CHECK(c1 == Complex(1, 2));
    CHECK(c1 != Complex(2, 1));
}

TEST_CASE("Test <= operator"){
    Complex c1(1, 2);
    Complex c2(3, 4);
    Complex c3(1, 2);
    Complex c4(0, 0);

    CHECK(c1 <= c2);
    CHECK(c1 <= c3);
    CHECK(c1 <= c1);
    CHECK(!(c1 <= c4));
}

TEST_CASE("Test >= operator"){
    Complex c1(1, 2);
    Complex c2(3, 4);
    Complex c3(1, 2);
    Complex c4(0, 0);

    CHECK(!(c1 >= c2));
    CHECK(c1 >= c3);
    CHECK(c1 >= c1);
    CHECK(c1 >= c4);
}

TEST_CASE("Test < operator"){
    Complex c1(1, 2);
    Complex c2(3, 4);
    Complex c3(1, 2);
    Complex c4(0, 0);

    CHECK(c1 < c2);
    CHECK(!(c1 < c3));
    CHECK(!(c1 < c1));
    CHECK(!(c1 < c4));
}

TEST_CASE("Test > operator"){
    Complex c1(1, 2);
    Complex c2(3, 4);
    Complex c3(1, 2);
    Complex c4(0, 0);

    CHECK(!(c1 > c2));
    CHECK(!(c1 > c3));
    CHECK(!(c1 > c1));
    CHECK(c1 > c4);
}
