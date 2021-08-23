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

Problem Source: https://leetcode.com/problems/sqrtx/
*/

#include <iostream>

using namespace std;

int mySqrt(int x) {
    long int mid = x;
    int start = 0, end=x, prevMid = 0;
    int ciclos = 0;
    while (mid*mid != x && abs(mid - prevMid) > 0.5){
        if(mid*mid > x)
            end = mid;
        else
            start = mid;
        prevMid = mid;
        ciclos++;
        mid = (start+end)/2;
    }
    cout << "ciclos: "<< ciclos << " ";
    return mid;
}

/*
int mySqrt(int x) {
    int start=0;
    int end=x;
    int ans=-1;
    int ciclos = 0;
    while(start<=end)
    {
        long long int mid=start+(end-start)/2;
        if(mid*mid<=x)
        {
            ans=mid;
            start=mid+1;
        }
        else
            end=mid-1;
        ciclos++;
    }
    cout << "ciclos: "<< ciclos << " ";
    return ans;
}
*/

int main(){
    //                                   result         cicles
    cout << mySqrt(4) <<endl;           // 2            //1
    cout << mySqrt(8) <<endl;           // 2            //5
    cout << mySqrt(9) <<endl;           // 3            //3
    cout << mySqrt(1025) <<endl;        // 32           //12
    cout << mySqrt(2147395599) <<endl;  // 46,339       //33    
    cout << mySqrt(1) <<endl;           // 1            //0
  
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}