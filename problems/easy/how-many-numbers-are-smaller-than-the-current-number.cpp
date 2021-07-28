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

Problem Source: https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
*/

#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <forward_list>

using namespace std;

vector<int> smallerNumbersThanCurrent(vector<int>& nums);
void print_elements();

void print_elements(vector<int>& nums){
    for (auto number: nums)
        cout << number << ", ";
    cout << endl;
}

vector<int> smallerNumbersThanCurrent(vector<int>& nums){
    //list<int> ans;
    forward_list<int> ans;
    int count;
    auto it = ans.before_begin();

    for (int i=0; i < nums.size(); i++){
        count = 0;
        for( int j=0; j < nums.size(); j++){
            if (nums[i] != nums[j] && nums[i] > nums[j])
                count++;
        }
        //ans.push_back(count);
        ans.insert_after(it, count);
        it++;
    }

    return {ans.begin(), ans.end()};
}

int main () {

    vector<int> ans, nums{8,1,2,2,3};

    print_elements(nums);
    ans = smallerNumbersThanCurrent(nums);
    print_elements(ans);


    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    return 0;
}