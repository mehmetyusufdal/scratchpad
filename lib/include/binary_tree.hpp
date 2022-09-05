/**
 * @file binary_tree.hpp
 * @author Mehmet Yusuf Dal (mehmetyusufdal@gmail.com)
 * @brief Binary Tree Implementation
 * @date 2022-09-05
 */
#pragma once

#include <concepts>
#include <iostream> // temp

template <class T>
concept aritmetic = std::integral<T> || std::floating_point<T>;

template <aritmetic T = int>
class BinaryTree{
private:
    struct Node;
    typedef std::unique_ptr<Node> node_ptr;

    struct Node{
        T value{ NULL };
        node_ptr left{ nullptr };
        node_ptr right{ nullptr };
    };

    node_ptr root{ nullptr };

    void append(node_ptr& node, T const& val) {
        if(!node) {
            node = std::make_unique<Node>();
            node->value = val;
        }
        else if (val >= node->value) append(node->right, val);
        else append(node->left, val);
    }

    node_ptr& find(node_ptr& node, T const& val) {
        if(!node) {
            // not found
            // TODO: Handle this situation.
            return node; // temp;
        }
        else if(val == node->value) {
            return node;
        }
        else if(val > node->value) find(node->right, val);
        else find(node->left, val);
    }

    void print(node_ptr& node) { // temp
        if(node->left) print(node->left);
        
        std::cout << std::to_string(node->value) << " ";
        
        if(node->right) print(node->right);
    } // temp

public:
    BinaryTree() {}

    BinaryTree(T const& root_val) {
        root = std::make_unique<Node>();
        root->value = root_val;
    }

    void append(T const& val) {
        if(!root) {
            root = std::make_unique<Node>();
            root->value = val;
        }
        else if(val >= root->value) append(root->right, val);
        else append(root->left, val);
    }

    node_ptr& find(T const& val) {
        return find(root, val);
    }

    void print() { // temp
        print(root);
    } // temp
};
