# Trees in C++

![Build Status](https://img.shields.io/badge/build-passing-brightgreen)
![License](https://img.shields.io/badge/license-MIT-blue.svg)

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Usage](#usage)
- [Tests](#tests)

## Overview

This repository contains a C++ implementation of binary and n-ary (n >= 2) tree data structures, along with functionalities for adding nodes, performing traversals (pre-order, post-order, in-order, BFS, DFS), and printing the tree structure.

The printing operator for trees launches a window with a GUI that displays the tree in its original form. (Uses SFML)

**GUI Example:**

![image](https://github.com/avihyb/CPP-EX4/assets/69721418/6a55ea22-970a-4054-bc55-fc66b880acd2)

The project is fully backed with testing cases to cover various scenarios. 
The makefile includes options for memory leak checking using tools like valgrind.

## Features

- Supports storing different data types in the tree nodes (e.g., integers, strings).
- Handles binary and n-ary tree structures (n >= 2).
- Provides a clear visual representation of the tree structure when printed.
- Implements different tree traversal methods for various use cases.

## Usage

```c++
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
```

This code displays the following GUI window:
![image](https://github.com/avihyb/CPP-EX4/assets/69721418/6a55ea22-970a-4054-bc55-fc66b880acd2)

The second argument of tree initialization sets the tree's maximum degree (K):
```c++
Tree<T, K> tree;
```
By default, it is set to be binary (K=2).
