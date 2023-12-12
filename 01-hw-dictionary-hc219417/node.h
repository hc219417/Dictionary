/**
 * @file: node.h
 * @author: Hannah Culver
 * @date: August 31, 2022
 * @brief: header file for the node class
 */

#ifndef NODE
#define NODE

#include <string>
#include <vector>
#include <cctype>
#include <iostream>

using namespace std;

class node{
    public:
        node(string k = string(), string v = string(), node* p = nullptr, node* n = nullptr);

        void set_key(string new_key) {key = new_key;}
        void set_value(string new_value) {value = new_value;}
        void set_next(node* n) {next_field = n;}
        void set_prev(node* p) {prev_field = p;}

        string get_key()const {return key;}
        string get_value()const {return value;}
        node* next()const {return next_field;}
        node* prev()const {return prev_field;}

    private:
        string key;
        string value;
        node* prev_field;
        node* next_field;
};

node::node(string k, string v, node* p, node* n){
    key = k;
    value = v;
    prev_field = p;
    next_field = n;
}

#endif