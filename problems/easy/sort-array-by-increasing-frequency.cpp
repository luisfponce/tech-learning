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

Problem Source: https://leetcode.com/problems/sort-array-by-increasing-frequency/
*/

#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <forward_list>
#include <unordered_map>

using namespace std;

void print_elements();
vector<int> frequencySort(vector<int>& nums);
void print_elements_map(unordered_map<int, int> map);
void print_elements(vector<pair<int, int> > vec);

void print_elements(vector<int>& vec){
    for (auto number: vec)
        cout << number << ", ";
    cout << endl;
}

void print_elements(vector<pair<int, int> > vec){
    for (auto const &pair: vec)
        cout << "{" << pair.first << " -> "<< pair.second << "}";
    cout << endl;
}

void print_elements(unordered_map<int, int> map){
    for (auto const &pair: map)
        cout << "{" << pair.first << ": "<< pair.second << "}";
    cout << endl;
}

bool comp_func(pair<int,int> &a, pair<int,int> &b) {
    if (a.second < b.second)
        return true;
    if (a.second == b.second)
        return a.first > b.first;
    return false;
}

/*
vector<int> frequencySort(vector<int>& nums) {
    forward_list<int> ans;
    auto it = ans.before_begin();
    unordered_map<int, int> _tmpMap;
    int i;
    for (i=0; i < nums.size(); i++){
        if ( _tmpMap[nums[i]] == 0 ){
            _tmpMap[nums[i]] = 1;
        }
        else
            _tmpMap[nums[i]] = _tmpMap[nums[i]]+1;
    }

    //print_elements(_tmpMap);

    vector<pair<int, int> > elems(_tmpMap.begin(), _tmpMap.end());
    sort(elems.begin(), elems.end(), comp_func);

    //print_elements(elems);

    for (auto num: elems){
        it = ans.insert_after(it, num.second, num.first);
    }
    
    return {ans.begin(), ans.end()};
}
*/

vector<int> frequencySort(vector<int>& nums){
    unordered_map<int, int> _tmpMap;

    for (auto x: nums)
        _tmpMap[x]++;

    print_elements(_tmpMap);
    cout<<"sort start : ";
    sort(nums.begin(), nums.end(), [&](int &right, int &left){
        
        print_elements(nums);
        cout << "    map[R],  map[L]" << endl;
        cout << "    map[" << right <<"],  map[" << left << "]" << endl;
        cout << "   IF   "<< _tmpMap[right] << " != " << _tmpMap[left] << endl;
        cout << "true -> " <<_tmpMap[right] << " < " << _tmpMap[left] << endl;
        cout << "        R , L " << endl;
        cout << "false-> " <<right << " > " << left << endl << endl;
        cout << endl ;
        cout << "sort result: ";
        
        return _tmpMap[right] != _tmpMap[left] ? _tmpMap[right] < _tmpMap[left] : right > left;
    });

    return nums;
}

int main (){
    vector<int> ans, nums{-1,1,-6,4,5,-6,1,4,1};
    //print_elements(nums);
    ans = frequencySort(nums);
    print_elements(ans);

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}