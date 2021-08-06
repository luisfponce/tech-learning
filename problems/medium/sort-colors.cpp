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

Problem Source: https://leetcode.com/problems/sort-colors/
*/

#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <forward_list>
#include <unordered_map>

using namespace std;

void print_elements(vector<int>& vec){
    for (auto number: vec)
        cout << number << ", ";
    cout << endl;
}

/* This solution is the general algoritm for sorting numbers 
void sortColors(vector<int>& nums) {
    int current,i,j;
    for(i=1; i < nums.size(); i++){ 
        current = nums[i];
        j = i-1;
        while (j >= 0 && nums[j] > current){
            nums[j+1] = nums[j];
            j--;
        }
        nums[j+1] = current;
   }
}
*/

void swapTwoInt(int &a, int &b){
    if (a == b) return;
    a = a + b;
    b = a - b;
    a = a - b;
}

// This approach is for sorting numbers within three given values
// In the case of this excersise, 0, 1 and 2, going thru each
// sort movement performed using three vars l, m and h correspondingly
void sortColors(vector<int>& nums) {
    int l = 0, m = 0, h = nums.size()-1;
    while (m <= h){
        if (nums[m] == 0){
            swapTwoInt(nums[l], nums[m]);
            l++;
            m++;
        }
        else if (nums[m] == 1)
            m++;
        else if (nums[m] == 2){
            swapTwoInt(nums[m], nums[h]);
            h--;
        }
    }
}

int main (){
    vector<int> nums{2,0,2,1,1,0};
    // vector<int> nums{2,0,1};
    print_elements(nums);
    sortColors(nums);
    print_elements(nums);

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}