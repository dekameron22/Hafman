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
    
    reheapdown(0, back-1);
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
    reheapup(0, back-1);
}

template<class T>
void Queue<T>::reheapup(int root, int bottom)
{
    int parent;
    
    if (bottom > root)
    {
        parent = (bottom-1)/D;
    }
    
    if (*arr[parent] > *arr[bottom])
    {
        swap(arr[parent], arr[bottom]);
        reheapup(root, parent);
    }
}

template <class T>
void Queue<T>::reheapdown(int root, int bottom)
{
    int minchild, firstchild, child;
    
    firstchild = root*D+1;
    
    if (firstchild <= bottom)
    {
        minchild = firstchild;
        
        for (int i = 2; i <= D; ++i)
        {
            child = root*D+i;
            if (child<=bottom)
            {
                if (*arr[minchild] < *arr[child])
                {
                    minchild = child;
                }
            }
        }
        
        if (*arr[root] > *arr[minchild])
        {
            swap(arr[root], arr[minchild]);
            reheapdown(minchild, bottom);
        }
    }
}

template <class T>
void Queue<T>::swap(T* &a, T* &b)
{
    T* c;
    c=a;
    a=b;
    b=c;
}

template <class T>
Queue<T>::~Queue<T>()
{
    delete [] arr;
}



























