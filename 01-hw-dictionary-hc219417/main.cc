/**
 * @file: main.cc
 * @author: Hannah Culver
 * @date: August 31, 2022
 * @brief: main program to test dictionary class
 */

#include <iostream>
#include "dictionary.h"

using namespace std;

int main(){

    cout << "************************" << endl;
    cout << "TESTING DICTIONARY CLASS" << endl;
    cout << "************************" << endl;
       
    cout << "========================" << endl;
    cout << "Default Constructor:" << endl;
    cout << "------------------------" << endl;

    Dictionary a;
    cout << a.size() << endl; //should be 0

    cout << "========================" << endl;  
    cout << "put and get:" << endl;
    cout << "------------------------" << endl;
            
    Dictionary b;

    b.put("Name", "Bob");
    b.put("email", "bob@gmail.com");
    b.put("address", "12 Main St.");
    b.put("raNk", "Captain");
    b.put("Name", "Robert");

    cout << b.get("Name") << endl; //Robert
    cout << b.get("EMAIL") << endl; //bob@gmail.com
    cout << b.get("RANK") << endl; //Captain
    cout << b.get("Address") << endl; //12 Main St.
    cout << b.get("SSN") << endl; //NOT_FOUND
    
    b.put("rank", "General");

    cout << b.get("RANK") << endl; //General

    cout << "========================" << endl;
    cout << "size:" << endl;
    cout << "------------------------" << endl;

    Dictionary c;

    c.put("Name", "Bob");
    c.put("email", "bob@gmail.com");
    c.put("email", "bob@gmail.com");
    c.put("email", "bob@gmail.com");
    c.put("address", "12 Main St.");
    c.put("raNk", "Captain");
    c.put("raNk", "Captain");
    c.put("raNk", "Captain");

    cout << c.size() << endl; //should be 4

    cout << "========================" << endl;
    cout << "keys:" << endl;
    cout << "------------------------" << endl;
    
    Dictionary d;
    vector<string> k = d.keys();

    cout << k.size() << endl; //should be 0

    d.put("Name", "Bob");
    d.put("Name", "Bob");
    d.put("email", "bob@gmail.com");
    d.put("address", "12 Main St.");
    d.put("raNk", "Captain");
    d.put("raNk", "Captain");
    d.put("raNk", "Captain");

    vector<string> k1 = d.keys();

    cout << k1[0] << endl; //address
    cout << k1[1] << endl; //email
    cout << k1[2] << endl; //Name
    cout << k1[3] << endl; //raNk

    cout << k1.size() << endl; //should be 4

    cout << "========================" << endl;
    cout << "values:" << endl;
    cout << "------------------------" << endl;
    
    Dictionary e;
    vector<string> v = e.keys();

    cout << v.size() << endl; //should be 0

    e.put("Name", "Bob");
    e.put("email", "bob@gmail.com");
    e.put("address", "12 Main St.");
    e.put("raNk", "Captain");

    vector<string> v1 = e.values();

    cout << v1[0] << endl; //12 Main St.
    cout << v1[1] << endl; //bob@gmail.com
    cout << v1[2] << endl; //Bob
    cout << v1[3] << endl; //Captain

    cout << v1.size() << endl; //should be 4

    cout << "========================" << endl;
    cout << "hasKey:" << endl;
    cout << "------------------------" << endl;
    
    Dictionary f;

    f.put("Name", "Bob");
    f.put("email", "bob@gmail.com");
    f.put("address", "12 Main St.");
    f.put("raNk", "Captain");

    if(f.hasKey("EMAIL")){
        cout << "true" << endl;
    } //true
    else cout << "false" << endl;

    if(f.hasKey("emails")){
        cout << "true" << endl;
    } //false
    else cout << "false" << endl;

    if(f.hasKey("")){
        cout << "true" << endl;
    } //false
    else cout << "false" << endl;

    if(f.hasKey("rank")){
        cout << "true" << endl;
    } //true
    else cout << "false" << endl;

    cout << "========================" << endl;
    cout << "hasValue:" << endl;
    cout << "------------------------" << endl;
     
    Dictionary g;

    g.put("Name", "Bob");
    g.put("email", "bob@gmail.com");
    g.put("address", "12 Main St.");
    g.put("raNk", "Captain");

    if(g.hasValue("12 Main St.")){
        cout << "true" << endl;
    } //true
    else cout << "false" << endl;

    if(g.hasValue("none")){
        cout << "true" << endl;
    } //false
    else cout << "false" << endl;

    if(g.hasValue("")){
        cout << "true" << endl;
    } //false
    else cout << "false" << endl;

    if(g.hasValue("bob@gmail.com")){
        cout << "true" << endl;
    } //true
    else cout << "false" << endl;

    cout << "========================" << endl;
    cout << "removeKey:" << endl;
    cout << "------------------------" << endl;

    Dictionary h;

    h.put("Name", "Bob");
    h.put("email", "bob@gmail.com");
    h.put("address", "12 Main St.");
    h.put("raNk", "Captain");

    h.removeKey("email");

    vector<string> k2 = h.keys();

    cout << k2[0] << endl; //address
    cout << k2[1] << endl; //Name
    cout << k2[2] << endl; //raNk

    cout << k2.size() << endl; //should be 3

    h.removeKey("rank");

    vector<string> k3 = h.keys();
    cout << k3.size() << endl; //should be 2

    cout << "========================" << endl;
    cout << "removeValues:" << endl;
    cout << "------------------------" << endl;

    Dictionary i;

    i.put("Name", "Bob");
    i.put("email", "bob@gmail.com");
    i.put("address", "12 Main St.");
    i.put("raNk", "Captain");
    i.put("rank2", "Captain");
    i.put("email2", "Captain");

    i.removeValues("Captain");
    
    vector<string> k4 = i.keys();

    cout << k4[0] << endl; //address
    cout << k4[1] << endl; //email
    cout << k4[2] << endl; //Name

    cout << k4.size() << endl; //should be 3

    vector<string> v2 = i.values();

    cout << v2[0] << endl; //12 Main St.
    cout << v2[1] << endl; //bob@gmail.com
    cout << v2[2] << endl; //Bob

    cout << v2.size() << endl; //should be 3

    cout << "========================" << endl;

    return 0;
}