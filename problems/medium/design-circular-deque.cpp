/* BSD 3-Clause License

Copyright (c) 2021, Luis Ponce
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its
   contributors may be used to endorse or promote products derived from
   this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 

Owner: Luis Felipe Ponce Navarro
Email: poncenavarroluisfelipe@gmail.com

Problem Source: https://leetcode.com/problems/design-circular-deque/
*/

#include <iostream>

using namespace std;

class MyCircularDeque {
    private:
        int sizeofK=0;
        int *deque = NULL;
        int f,r;
    public:
        
        MyCircularDeque(int k) {
            sizeofK=k;
            deque = (int*) malloc (k * sizeof(int));
            f=-1;
            r=-1;
        }
        
        bool insertFront(int value) {
            if( isFull() ){
                return false;
            }
            else if ( f == -1 && r == -1)
                f = r = 0;
            else if ( f == 0 )
                f = sizeofK-1;
            else
                f--;
            deque[f]=value;
            return true;
        }
        
        bool insertLast(int value) {
            if( isFull() ){
                return false;
            }
            else if ( f == -1 && r == -1 )
                f = r = 0;
            else if ( r == sizeofK-1 )
                r = 0;
            else
                r++;
            deque[r]=value;
            return true;
        }
        
        bool deleteFront() {
            if( isEmpty() ){
                return false;
            }
            deque[f]=-1;
            if ( r == f)
                r = f = -1;
            else if ( f == sizeofK-1 )
                f = 0;
            else
                f++;
            return true;
        }
        
        bool deleteLast() {
            if( isEmpty() ){
                return false;
            }
            deque[r]=-1;
            if ( r == f)
                r = f = -1;
            else if ( r == 0)
                r = sizeofK-1;
            else
                r--;
            return true;
            
        }
        
        int getFront() {
            if ( ! isEmpty() )
                return deque[f];
            return -1;
        }

        int getRear() {
            if ( ! isEmpty() )
                return deque[r];
            return -1;
        }

        bool isEmpty() {
            if( f == -1 && r == -1 )
                return true;
            return false;
        }

        bool isFull() {
            if( (f == 0  && r == sizeofK-1) || (f == r+1) )
                return true;
            return false;
        }

        void printDeque(){
            cout << endl;
            cout << "Elements in list :" <<endl;
            for (int i=0; i<sizeofK; i++) {
                cout << "[ " << deque[i] << " ] -> ";
            }
            cout << " NULL " <<endl;
        }

        void deleteDeque (){
            delete deque;
        }
};

/*  A n o t h e r   a p r o a c h
class MyCircularDeque {
    private:
        int sizeofK=0;
        int *deque = NULL;
        int f,r;
    public:
        
        MyCircularDeque(int k) {
            sizeofK=k;
            deque = (int*) malloc (k * sizeof(int));
            f=-1;
            r=-1;
        }
        
        bool insertFront(int value) {
            if( isFull() ){
                return false;
            }
            if ( f == -1 && r == -1)
                f = r = 0;
            else
                f = (f - 1 + sizeofK ) % sizeofK;
            deque[f]=value;
            return true;
        }
        
        bool insertLast(int value) {
            if( isFull() ){
                return false;
            }
            if ( f == -1 && r == -1 )
                f = r = 0;
            else
                r = (r + 1) % sizeofK;
            deque[r]=value;
            return true;
        }
        
        bool deleteFront() {
            if( isEmpty() ){
                return false;
            }
            deque[f]=-1;
            if ( r == f)
                r = f = -1;
            else
                f = (f + 1) % sizeofK;
            return true;
        }
        
        bool deleteLast() {
            if( isEmpty() ){
                return false;
            }
            deque[r]=-1;
            if ( r == f)
                r = f = -1;
            else
                r = (r-1 + sizeofK) % sizeofK;
            return true;
            
        }
        
        int getFront() {
            if ( ! isEmpty() )
                return deque[f];
            return -1;
        }

        int getRear() {
            if ( ! isEmpty() )
                return deque[r];
            return -1;
        }

        bool isEmpty() {
            if( f == -1 && r == -1 )
                return true;
            return false;
        }

        bool isFull() {
            if( (f == 0  && r == sizeofK-1) || (f == r+1) )
                return true;
            return false;
        }

        void printDeque(){
            cout << endl;
            cout << "Elements in list :" <<endl;
            for (int i=0; i<sizeofK; i++) {
                cout << "[ " << deque[i] << " ] -> ";
            }
            cout << " NULL " <<endl;
        }

        void deleteDeque (){
            delete deque;
        }
};
*/

/* A n o t h e r    s o l u t i o n 
class MyCircularDeque {
    int maxSize;
    int left;
    int right;
    int curSize;
    int *data = NULL;
    
public:
    MyCircularDeque(int k) {
        maxSize = k;
        left = 0;
        right = 0;
        curSize = 0;
        data = (int*) malloc (k * sizeof(int));
    }
    
    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        if (curSize++) {
            left = (left - 1 + maxSize) % maxSize;
        }
        data[left] = value;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        if (curSize++) {
            right = (right + 1) % maxSize;
        }
        data[right] = value;
        return true;
    }
    
    bool deleteFront() {
        if (! curSize) {
            return false;
        }
        data[left] = -1;
        if (--curSize) {
            left = (left + 1) % maxSize;
        }
        return true;
    }

    bool deleteLast() {
        if (! curSize) {
            return false;
        }
        data[right] = -1;
        if (--curSize) {
            right = (right - 1 + maxSize) % maxSize;
        }
        return true;
    }
    
    int getFront() {
        return (curSize ? data[left] : -1);
    }
    
    int getRear() {
        return (curSize ? data[right] : -1);
    }
    
    bool isEmpty() {
        return ! curSize;
    }
    
    bool isFull() {
        return curSize == maxSize;
    }

    void printDeque(){
        cout << endl;
        cout << "Elements in list :" <<endl;
        for (int i=0; i<maxSize; i++) {
            cout << "[ " << data[i] << " ] -> ";
        }
        cout << " NULL " <<endl;
    }

    void deleteDeque (){
        delete data;
    }
};
*/

int main (){

    /**
     * Your MyCircularDeque object will be instantiated and called as such:
     * MyCircularDeque* obj = new MyCircularDeque(k);
     * bool param_1 = obj->insertFront(value);
     * bool param_2 = obj->insertLast(value);
     * bool param_3 = obj->deleteFront();
     * bool param_4 = obj->deleteLast();
     * int param_5 = obj->getFront();
     * int param_6 = obj->getRear();
     * bool param_7 = obj->isEmpty();
     * bool param_8 = obj->isFull();
     */

    int size = 0;
    cout << "Insert size of Deque:" << endl;
    cin >> size;

    MyCircularDeque* obj = new MyCircularDeque(size);

    cout << boolalpha << obj->insertFront(4) << ",";
    cout << boolalpha << obj->deleteLast() << ",";
    cout << obj->getRear() << ",";
    cout << obj->getFront() << ",";
    cout << obj->getFront() << ",";
    cout << boolalpha << obj->deleteFront() << ",";
    cout << boolalpha << obj->insertFront(6) << ",";
    cout << boolalpha << obj->insertLast(5) << ",";
    cout << boolalpha << obj->insertFront(9) << ",";
    cout << obj->getFront() << ",";
    cout << boolalpha << obj->insertFront(6) << ",";
    cout << endl;
    
    obj->printDeque();
    obj->deleteDeque();

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
        
    return 0;
}