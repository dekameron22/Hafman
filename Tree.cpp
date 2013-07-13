//
//  Tree.cpp
//  Hafman
//
//  Created by Артем Ткачук on 09.07.13.
//  Copyright (c) 2013 Артем Ткачук. All rights reserved.
//

#include "Tree.h"

Tree::Tree()
{
    Node* N = new Node;
    root = N;
}

void Tree::chop(Node *N)
{
    if (N)
    {
        chop(N->left);
        chop(N->right);
        delete N;
    }
}

Tree::~Tree()
{
    chop(root);
}

unsigned int Tree::get_freq() const
{
    return root->freq;
}

unsigned char Tree::get_char() const
{
    return root->ch;
}

void Tree::set_freq(unsigned int frequency)
{
    root->freq = frequency;
}

void Tree::set_char(unsigned char symbol)
{
    root->ch = symbol;
}

Tree::Node* Tree::get_left(void) const
{
    return root->left;
}

Tree::Node* Tree::get_right(void) const
{
    return root->right;
}

void Tree::set_left(Node *N) const
{
    root->left = N;
}

void Tree::set_right(Node *N) const
{
    root->right = N;
}

Tree::Node * Tree::get_root() const
{
    return root;
}

void Tree::print(ostream &ost, Node *curr, int level) const
{
    if (curr)
    {
        print(ost, curr->right, level+1);//right
        ost<<setw(level*width_unit)<<print_char(curr)<<":"<<curr->freq<<endl;
        print(ost, curr->left, level+1);//left
    }
}

void Tree::print(Node* curr, int level) const
{
    if (curr)
    {
        print(curr->right, level+1);
        cout << setw(level*width_unit)<<print_char(curr)<<":"<<curr->freq<<endl;
        print(curr->left, level+1);
    }
}

ostream & operator<<(ostream &ost, const Tree &t)
{
    t.print(ost, t.root, 1);
    return ost;
}

bool Tree::operator==(const Tree &t) const
{
    return (root->freq == t.root->freq);
}

bool Tree::operator!=(const Tree &t) const
{
    return (root->freq != t.root->freq);
}

bool Tree::operator<(const Tree &t) const
{
    return (root->freq < t.root->freq);
}

bool Tree::operator>(const Tree &t) const
{
    return (root->freq > t.root->freq);
}

bool Tree::operator<=(const Tree &t) const
{
    return (root->freq <= t.root->freq);
}

bool Tree::operator>=(const Tree &t) const
{
    return (root->freq >= t.root->freq);
}


































