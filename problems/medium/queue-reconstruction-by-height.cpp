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

Problem Source: https://leetcode.com/problems/queue-reconstruction-by-h/
*/

#include <iostream>
#include <vector>
#include <list>
#include <forward_list>

using namespace std;

enum { h = 0, k = 1 };

void print_vector(vector<vector<int> >& vec);
vector<vector<int> > reconstructQueue(vector<vector<int> > &people);

void print_vector(vector<vector<int> > &vec){
   cout<<"vector elements:"<<endl;
   for (int i=0; i<vec.size(); i++){
   for (int j=0; j< vec[i].size(); j++)
      cout << vec[i][j] << " ";
   cout << endl;
   }
}

/*
vector<vector<int> > reconstructQueue(vector<vector<int> > &people) {
   // sort "people" in decreasing order by his h, if their heights are the same
   // sort them by k in increasing order.
   // after sorting insert the iht person at his k position in a int vector of int vector

   vector<vector <int> > answer;
   sort(people.begin(), people.end(), [](vector<int>& left, vector<int>& right ){
      return (left[h] > right[h] || (left[h] == right[h] && left[k] < right[k]) );
   });

   //print_vector(people);
   for (int i=0; i < people.size() ; i++){
      answer.insert(answer.begin()+people[i][1], people[i]);
      //print_vector(answer);
   }
   return answer;
}
*/

/* This is another solution using list to drop in the ordered elements.
   This proposal consumes less memory due list c++ implementation against vector
   which copies all data everytimes an element is inserted at the beggining
   Reference: https://www.youtube.com/watch?v=4-u9R40G1j8
vector<vector<int> > reconstructQueue(vector<vector<int> >& people) {
   sort(people.begin(), people.end(), [](vector<int>& left, vector<int>& right ){
      return (left[h] > right[h] || (left[h] == right[h] && left[k] < right[k]) );
   });
   list<vector<int> > queue;

   for (auto& person: people) {
      auto position = queue.begin();
      for (int index = 1; index <= person[k]; index++) {
            position++;
      }
      queue.insert(position, person);
   }

   return {queue.begin(), queue.end()};
}
*/

/* Or can be used a forward_list which implement a single linked list
    to drop in the ordered elements.
   This proposal consumes even less memory than list in c++ due it is
   single linked list implementation.
*/
vector<vector<int> > reconstructQueue(vector<vector<int> >& people) {
   sort(people.begin(), people.end(), [](vector<int>& left, vector<int>& right ){
      return (left[h] > right[h] || (left[h] == right[h] && left[k] < right[k]) );
   });
   forward_list<vector<int> > queue;

   for (auto& person: people) {
      forward_list<vector<int> >::iterator position = queue.before_begin();
      for (int index = 1; index <= person[k]; index++) {
            position++;
      }
      queue.insert_after ( position, person );
   }

   return {queue.begin(), queue.end()};
}

int main (){
   vector <vector<int> > people{ {7,0},
                                 {4,4},
                                 {7,1},
                                 {5,0},
                                 {6,1},
                                 {5,2} };
   print_vector(people);
   vector<vector <int> > answer;
   answer =reconstructQueue(people);
   print_vector(answer);

   cin.ignore(numeric_limits<streamsize>::max(), '\n');
   cin.get();
   return 0;
}