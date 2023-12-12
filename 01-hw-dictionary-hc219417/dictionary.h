/**
 * @file: dictionary.h
 * @author: Hannah Culver
 * @date: August 31, 2022
 * @brief: header file for the dictionary class
 */

#ifndef DICTIONARY
#define DICTIONARY

#include "node.h"
using namespace std;

class Dictionary{
   public:
    Dictionary(){head = nullptr;} //default constructor

    string get(string key); //returns the value stored at specified key (if not found returns the string "NOT_FOUND")
    void put(string key, string value); //adds a key-value pair to the dictionary (if it already exists, replaces its value)
    
    vector<string> keys(); //returns all the keys in the dictionary in a vector of type string (in the same order as the entries in the dictionary)
    vector<string> values(); //returns all the values in the dictionary in a vector of type string (in the same order as the entries in the dictionary)
    
    bool hasKey(string key); //returns true if a key is in the dictionary
    bool hasValue(string value); //returns true if a value is in the dictionary
    
    int size(); //returns the number of key-value pairs in the dictionary
    
    void removeKey(string key); //removes a node from the list that matches the key
    void removeValues(string value); //removes all the matched values from the dictionary

    string to_lower(string input_string); //converts given string to lowercase

   private:
    node* head;
};

#endif

string Dictionary::get(string key){
    string lowercase_key = to_lower(key);
    if(head == nullptr){ //empty list
        return "NOT_FOUND";
    }
    node* cursor = head;
    while(cursor != nullptr){
        if(to_lower(cursor -> get_key()) == lowercase_key){
            return cursor -> get_value();
        }
        cursor = cursor -> next();
    }
    return "NOT_FOUND";
}

void Dictionary::put(string key, string value){
    node* cursor;
    cursor = head;
    string lowercase_key = to_lower(key);
    if(head == nullptr){ //empty list
        head = new node(key,value);
        return;
    }
    for(node* match_cursor = head; match_cursor != nullptr; match_cursor = match_cursor -> next()){
        if(to_lower(match_cursor -> get_key()) == lowercase_key){
            match_cursor -> set_value(value); //check first for any matching keys
            return;
        }
    }
    if(lowercase_key < to_lower(head -> get_key())){ //entry needs to be put before head
        head = new node(key, value, nullptr, cursor);
        cursor -> set_prev(head); //THE LINE THAT FIXED EVERYTHING.
        return;
    }
    if(cursor -> next() == nullptr){ //only one item in the list
        cursor -> set_next(new node(key, value, cursor));
        return;
    }
    else{ //add entry elsewhere
        while(cursor != nullptr){
            cursor = cursor -> next();
            if(lowercase_key < to_lower(cursor -> get_key())){ //add entry to middle of list
                node* tmp = new node(key, value, cursor -> prev(), cursor);
                cursor -> prev() -> set_next(tmp);
                cursor -> set_prev(tmp);
                return;
            }
            else if(cursor -> next() == nullptr){ //add entry to end of list
                cursor -> set_next(new node(key, value, cursor));
                return;
            }
        }
    }
    return;
}

vector<string> Dictionary::keys(){
    vector<string> keys;
    node* cursor;
    cursor = head;
    if(head == nullptr){ //empty list
        return vector<string>();
    }
    else{
        while(cursor != nullptr){
            keys.push_back(cursor -> get_key());
            cursor = cursor -> next();
        }
    }
    return keys;
}

vector<string> Dictionary::values(){
    vector<string> values;
    node* cursor;
    cursor = head;
    if(head == nullptr){ //empty list
        return vector<string>();
    }
    else{
        while(cursor != nullptr){
            values.push_back(cursor -> get_value());
            cursor = cursor -> next();
        }
    }
    return values;
}

bool Dictionary::hasKey(string key){
    string lowercase_key = to_lower(key);
    if(head == nullptr){ //empty list
        return false;
    }
    if(to_lower(head -> get_key()) == lowercase_key){
        return true;
    }
    else{
        for(node* key_cursor = head; key_cursor != nullptr; key_cursor = key_cursor -> next()){
            if(to_lower(key_cursor -> get_key()) == lowercase_key){
                return true;
            }
        }
    }
    return false;
}

bool Dictionary::hasValue(string value){
    string lowercase_value = to_lower(value);
    if(head == nullptr){ //empty list
        return false;
    }
    if(to_lower(head -> get_value()) == lowercase_value){
        return true;
    }
    else{
        for(node* value_cursor = head; value_cursor != nullptr; value_cursor = value_cursor -> next()){
            if(to_lower(value_cursor -> get_value()) == lowercase_value){
                return true;
            }
        }
    }
    return false;
}

int Dictionary::size(){
    int count = 0;
    for(node* cursor = head; cursor != nullptr; cursor = cursor -> next()){
        count++;
    }
    return count;
}

void Dictionary::removeKey(string key){
    node* cursor;
    cursor = head;
    string lowercase_key = to_lower(key);
    if(head == nullptr){ //empty list
        return;
    }
    if(to_lower(head -> get_key()) == lowercase_key){ //head is already pointing to item that needs removed
        if(cursor -> next() == nullptr){
            delete cursor;
            return; //only one item in the list AND it needs removed
        }
        head = head -> next();
        head -> set_prev(nullptr);
        delete cursor;
    }
    else{
        for(node* key_cursor = head; key_cursor != nullptr; key_cursor = key_cursor -> next()){
            if(to_lower(key_cursor -> get_key()) == lowercase_key && key_cursor -> next() != nullptr){ //item needs removed somewhere from the middle
                key_cursor -> prev() -> set_next(key_cursor -> next());
                key_cursor -> next() -> set_prev(key_cursor -> prev());
                delete key_cursor;
            }
            else if(to_lower(key_cursor -> get_key()) == lowercase_key && key_cursor -> next() == nullptr){ //last item needs removed
                key_cursor -> prev() -> set_next(nullptr);
                delete key_cursor;
            }
        }
    }
    return;
}

void Dictionary::removeValues(string value){
    node* cursor;
    cursor = head;
    string lowercase_value = to_lower(value);
    if(head == nullptr){ //empty list
        return;
    }
    int value_count = 0; //initialize value counter (set to increment in the following for loop)
    for(node* count_cursor = head; count_cursor != nullptr; count_cursor = count_cursor -> next()){
        if(to_lower(count_cursor -> get_value()) == lowercase_value){
            value_count++; //check first for number of same values
        }
    }
    if(value_count == 0){ //error code 404: value_not_found
        return;
    }
    else{
        while(value_count != 0){
            if(to_lower(head -> get_value()) == lowercase_value){ //head is already pointing to item that needs removed
                if(cursor -> next() == nullptr){
                    value_count--;
                    delete cursor;
                    return; //only one item in the list AND it needs removed
                }
                head = head -> next();
                head -> set_prev(nullptr);
                value_count--;
                delete cursor;
            }
            else{
                for(node* value_cursor = head; value_cursor != nullptr; value_cursor = value_cursor -> next()){
                    if(to_lower(value_cursor -> get_value()) == lowercase_value && value_cursor -> next() != nullptr){ //item needs removed somewhere from the middle
                        value_cursor -> prev() -> set_next(value_cursor -> next());
                        value_cursor -> next() -> set_prev(value_cursor -> prev());
                        value_count--;
                        delete value_cursor;
                    }
                    else if(to_lower(value_cursor -> get_value()) == lowercase_value && value_cursor -> next() == nullptr){ //last item needs removed
                        value_cursor -> prev() -> set_next(nullptr);
                        value_count--;
                        delete value_cursor;
                    }
                }
            }
        }
    }
    return;
}

string Dictionary::to_lower(string input_string){
    for(unsigned int i = 0; i < input_string.length(); i++){
        input_string[i] = tolower(input_string[i]);
    }
    return input_string;
}

//eof