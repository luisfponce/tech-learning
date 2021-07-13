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

Problem Source: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
*/

#include <iostream>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(NULL) {}
     ListNode(int x) : val(x), next(NULL) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode *tail;

ListNode* swapNodes(ListNode* &head, int k);
void insertElement(ListNode* &l, int val);
void printElements(ListNode *&list);

int main (){
    ListNode *head = NULL;
    int n = 0, k = 0, val = 0;
    cout << "Inster the number of elements in the list:"<< endl;
    cin >> n;

    for (k=0; k<n; k++ ){
        cout<< "Insert "<< k << "º of "<< n << endl;
        cin >> val;
        insertElement(head,val);
    }
    cout << "tail is " << tail->val <<endl;

    cout << "Insert K:" <<endl;
    cin >> k;
    printElements(head);
    swapNodes(head,k);
    printElements(head);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    return 0;
}

ListNode* swapNodes(ListNode* &head, int k){
    ListNode *aux = head;
    int size = 0, i;
    while (aux != NULL){
        size++;
        aux = aux->next;
    }
    aux = head;
    if ( size/k < k ){  
    // In case the K number does not allow to switch 
    // the beggining and end node on the fly use another for
        int _tmp[size];
        for (i=0; i<size;i++){
            _tmp[i]=aux->val;
            aux = aux->next;
        }
        aux = head;
        for (i=0;i<size; i++){
            if (i+1 == k){
                aux->val = _tmp[size-k];
            }
            else if (i == size-k){
                aux->val = _tmp[k-1];
            }
            else
                aux->val = _tmp[i];
            aux =  aux->next;
        }
        return head;
    }
    ListNode *b;
    int a;
    for (i=1; i<=size;i++){
        if (i == k){
            b = aux;
            a = aux->val;
        }
        if (i-1 == size-k) {
            b->val = aux->val;
            aux->val = a;
        }
        aux = aux->next;
    }
    return head;
}

void insertElement(ListNode* &l, int val){
    ListNode *aux;
    if ( l == NULL){
        l = new ListNode();
        l->val=val;
        tail=l;
    }
    else {
        aux = new ListNode();
        tail->next = aux;
        aux->val = val;
        tail = aux;
    }
    tail->next =  NULL;
}

void printElements(ListNode *&list){
    ListNode *aux;
    aux = list;
    cout<< "List elements: ";
    while (aux != NULL){
        cout<<"[ " << aux->val << " ] -> ";
        aux = aux->next;
    }
    cout<<"NULL"<<endl;

}