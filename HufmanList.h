//
//  HufmanList.h
//  Hafman
//
//  Created by Артем Ткачук on 14.07.13.
//  Copyright (c) 2013 Артем Ткачук. All rights reserved.
//

#ifndef __Hafman__HufmanList__
#define __Hafman__HufmanList__

#include <iostream>
#include "Tree.h"

class HufmanList : protected Tree
{
public:
    HufmanList();
    ~HufmanList();
    
    void huf(Node *, unsigned char, string, string &) const;
    void huf_list(Node *, string) const;
    bool get_huf_char(string, unsigned char &) const;
    void huf_write (string & s, unsigned char &, ifstream ist);
    

};

#endif /* defined(__Hafman__HufmanList__) */
