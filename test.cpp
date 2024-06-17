#include "doctest.h"
#include "complex.hpp"
#include "node.hpp"
#include "tree.hpp"
#include <iostream>
#include <sstream>
#include <string>

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




