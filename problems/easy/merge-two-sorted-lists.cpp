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

Problem Source: https://leetcode.com/problems/merge-two-sorted-lists/
*/

#include <iostream>
#include <string>

using namespace std;

// Definition for singly-linked list.
struct ListNode{
    int val;
    ListNode *next;
    ListNode(): val(0), next(NULL) {}
    ListNode(int x): val(x), next(NULL) {}
    ListNode(int x, ListNode *next): val (x), next(next){}
};

ListNode *l1, *tail1;
ListNode *l2, *tail2;
ListNode *aux, *_tmp;
ListNode *tailans;
ListNode *answer;

void print_elemets(ListNode *&l);
void remove_element(ListNode *&l, ListNode *&tail, int val);
void insert_element(ListNode *&l, ListNode *&tail ,int val);
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);

int main (){
    // l1 = [1,2,4]
    // l2 = [1,3,4]
    int no = 0;
    int val = 0;

    cout << "Insert only a single number of elements in L1 " << endl;
    cin >> no;
    while ( no > 0 ){
        cout << "Elements left "<< no << " to fill L1" << endl;
        cin >> val;
        insert_element(l1, tail1, val);
        no--;
    }

    cout << "Insert only a single number of elements in L2 " << endl;
    cin >> no;
    while ( no > 0 ){
        cout << "Elements left "<< no << " to fill L2" << endl;
        cin >> val;
        insert_element(l2, tail2, val);
        no--;
    }
    _tmp = mergeTwoLists(l1, l2);
    print_elemets(_tmp);

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
        
    return 0;
}

void print_elemets(ListNode *&l){
    aux = l;
    cout << "Elements in list :" <<endl;
    while (aux != NULL){
        cout << "[ " << aux->val << " ] -> ";
        aux = aux->next;
    }
    cout << " NULL " <<endl;
}

void remove_element(ListNode *&l, ListNode *&tail, int val){
    aux = l;
    while (aux != NULL){
        if (aux->val == val){
            if (aux == tail)
                l = l->next;
            else
                tail->next = aux->next;
            delete(aux);
        }
    }
}

void insert_element(ListNode *&l, ListNode *&tail ,int val){
    if (l == NULL){
        l = new ListNode();
        l->val = val;
        tail = l;
    }
    else {
        aux = new ListNode();
        tail->next = aux;
        aux-> val = val;
        tail = aux;
    }
    tail->next = NULL;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    
    while (l1 != NULL || l2 != NULL){
        if (l1 == NULL && l2 != NULL){
            while (l2 !=  NULL){
                insert_element(answer, tailans, l2->val);
                l2 = l2->next;
            }
            break;
        }
        if (l2 == NULL && l1 != NULL){
            while (l1 != NULL){
                insert_element(answer, tailans,l1->val);
                l1 = l1->next;
            }
            break;
        }
        if(l1->val > l2->val){
            insert_element(answer, tailans, l2->val);
            l2=l2->next;
        }
        else if(l2->val > l1->val){
            insert_element(answer, tailans,l1->val);
            l1 = l1->next;
        }
        else {
            insert_element(answer, tailans, l1->val);
            insert_element(answer, tailans, l2->val);
            l1 = l1->next;
            l2 = l2->next;
        }
    }
    return answer;
}
