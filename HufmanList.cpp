//
//  HufmanList.cpp
//  Hafman
//
//  Created by Артем Ткачук on 14.07.13.
//  Copyright (c) 2013 Артем Ткачук. All rights reserved.
//

#include "HufmanList.h"

void HufmanList::huf(Node *N, unsigned char c, string str, string & s) const
{
    if (N)
    {
        if (!N->left && !N->right && N->ch == c)
        {
            s = str;
        }
        else
        {
            huf(N->left, c, str+"0", s);
            huf(N->right, c, str+"1", s);
        }
    }
}

bool HufmanList::get_huf_char(string s, unsigned char & c) const
{
    Node *current = root;
    for (unsigned int i = 0; i<s.size(); ++i)
    {
        if (s[i] == '0')
        {
            current = current->left;
        }
        else
            if (s[i] == '1')
            {
                current = current->right;
            }
    }
    
    bool found = false;
    
    if (!current->right && !current->left)
    {
        found = true;
        c = current->ch;
    }
    
    return found;
}































