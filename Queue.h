//
//  Queue.h
//  Hafman
//
//  Created by Артем Ткачук on 09.07.13.
//  Copyright (c) 2013 Артем Ткачук. All rights reserved.
//

#ifndef __Hafman__Queue__
#define __Hafman__Queue__

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cctype> 

#define HELP_ERROR 99
#define width_unit 5

using namespace std;

template<class T>
class Queue
{
public:
    Queue(int d = 2);
    ~Queue();
    
    void enq(T*);
    T* deq();
    T* front();
    bool isEmpty() const;
    bool isFull() const;
    
private:
    
    int back;
    T* *arr;
    int size;
    static const int SIZE = 10;
    int D;
    
    Queue(const Queue&);
    const Queue & operator = (const Queue&);
    
    void reheapup (int, int);
    void reheapdown (int, int);
    void swap (T* &, T* &);
    
};





































#endif /* defined(__Hafman__Queue__) */
