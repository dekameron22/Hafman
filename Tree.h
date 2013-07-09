//
//  Tree.h
//  Hafman
//
//  Created by Артем Ткачук on 09.07.13.
//  Copyright (c) 2013 Артем Ткачук. All rights reserved.
//

#ifndef __Hafman__Tree__
#define __Hafman__Tree__

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cctype>

#define HELP_ERROR 99
#define width_unit 5

using namespace std;

class Tree
{
private:
    class Node
    {
        unsigned int freq;
        unsigned char ch;
        Node *left, *right;
        
        Node():freq(0), ch('\0'),left(nullptr), right(nullptr){};
    };
    
    Node *root;
    Tree (const Tree &);
    const Tree & operator=(const Tree &);
    void chop (Node *N);
    void print (ostream &, Node *, int) const;
    void print (Node *, int) const;
    
public:
    Tree();
    ~Tree();
    
    friend ostream operator<<(ostream &, const Tree &);
    
    unsigned int get_freq(void) const;
    unsigned char get_char(void) const;
    void set_freq(unsigned int);
    void set_char(unsigned char);
    Node get_left(void) const;
    Node get_right(void) const;
    void set_left(Node *) const;
    void set_right(Node *) const;
    Node *get_root(void) const;

    //перегрузити оператори!!!!
    //
    
    void huf(Node *, unsigned char, string, string &) const;
    void huf_list(Node *, string) const;
    bool get_juf_char(string, unsigned char &) const;
    string print_char(Node *) const;

};

#endif /* defined(__Hafman__Tree__) */



































