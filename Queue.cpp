//
//  Queue.cpp
//  Hafman
//
//  Created by Артем Ткачук on 09.07.13.
//  Copyright (c) 2013 Артем Ткачук. All rights reserved.
//

#include "Queue.h"


template <class T>
Queue<T>::Queue(int d)
{
    if (d<2)
    {
        d = 2;
    }
    
    D = d;
    back = 0;
    size = SIZE;
    arr = new T*[size];
}

template <class T>
bool Queue<T>::isEmpty() const
{
    return back<=0;
}

template <class T>
bool Queue<T>::isFull() const
{
    return back>=size;
}

template <class T>
T* Queue<T>::deq()
{
    if (isEmpty())
    {
        cerr <<"deq error! exit"<<endl;
        exit(1);
    }
    
    T* rval = arr[0];
    arr[0] = arr[back-1];
    --back;
    
    //method
    return rval;
    
}

template<class T>
T* Queue<T>::front(void)
{
    if (isEmpty())
    {
        cerr<<"deq error! exiting"<<endl;
        exit(1);
    }
    
    return arr[0];
}

template<class T>
void Queue<T>::enq(T* foo)
{
    if (isFull())
    {
        int nsize = size+SIZE;
        T* *narr = new T*[nsize];
        for (int i = 0; i<size; ++i)
        {
            narr[i] = arr[i];
        }
        
        delete [] arr;
        arr = narr;
        size = nsize;
    }
    
    arr[back++]=foo;
    //method
}


































