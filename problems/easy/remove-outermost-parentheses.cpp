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
*/

#include <iostream>
#include <string>
#include <stack>
#include <list>
#include <vector>

using namespace std;

string removeOuterParentheses_using_stack(string s){
    stack<char> stk;
    vector<int> l;
    string out = "";

    for(int i=0; i< s.size(); i++){
        if (stk.size()==0){
            l.push_back(i);
            stk.push(s[i]);
            continue;
        }
        if(s[i]=='(' && stk.top() == ')'){
            stk.pop();
            if(stk.size()==0)
                l.push_back(i);
        }
        else if(s[i]==')' && stk.top()=='('){
            stk.pop();
            if(stk.size()==0)
                l.push_back(i);
        }
        else
            stk.push(s[i]);
    }

    for(int i=0; i < l.size(); i+=2){
        out+= s.substr(l[i]+1,(l[i+1])-(l[i]+1));
    }
    return out;
}

string removeOuterParentheses(string &s) {
    string out = "";

    int keepTrack = 0;

    for(int i=0; i < s.size(); i++){

        if (s[i] == ')')
            keepTrack--;

        if (keepTrack != 0)
            out+=s[i];

        if (s[i] == '(')
            keepTrack++;       
    }

    return out;
        
}

int main () {

    //string s = "((()())(()()))";
    string s = "(()())(())";
    //cout << "result: " << removeOuterParentheses(s) << endl;
    cout << "result: " << removeOuterParentheses_using_stack(s);
    return 0;
}