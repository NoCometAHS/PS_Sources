#include "bits/stdc++.h"

using namespace std;
using LL = long long;
using iipair = pair<LL,LL>;

template<typename t>
using TwoVector = vector<vector<t>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string str;
    while (cin >> str) {

        
        while(true) {
            stack<int> st;
            bool f = true;

            vector<iipair> t;
            for (int i = 0; i < str.length(); i++) {
                if (str[i] == '(') {
                    st.push(i);
                }
                else if (str[i] == ')') {
                    if (!t.empty() && st.top() + 1 == t.back().first && t.back().second + 1 == i) {
                        str.erase(str.begin() + t.back().second);
                        str.erase(str.begin() + t.back().first);
                        f = false;

                        break;
                    }

                    t.push_back({st.top(), i});
                    st.pop();
                }
            }
            

            if (f) break;
        
        }

        vector<int> toErase;
        vector<iipair> parenthesis;
        stack<int> st;
        
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '(') {
                st.push(i);
            }
            else if (str[i] == ')') {
                parenthesis.push_back({st.top(), i});
                st.pop();
            }
        }

        
        for (auto& [st, en] : parenthesis) {
            bool gob = false;
            
            if (st > 0 && str[st-1] != '+' && str[st-1] != '(') {
                gob = true;
            }
            if (en < str.length()-1 && str[en +1] != '+' && str[en+1] != ')') {
                gob = true;
            }

            bool erase = !gob;

            if (!erase) {
                int plusCnt = 0;
                
                for (int i = st+1, par = 0; i < en; i++) {
                    if (str[i] == '+' && par == 0) plusCnt++;
                    else if (str[i] == '(') par++;
                    else if (str[i] == ')') par--;
                }

                erase = !plusCnt;
            }


            if (erase) {
                toErase.push_back(st);
                toErase.push_back(en);
            }
        }

        sort(toErase.rbegin(), toErase.rend());

        for (int i = 0; i < str.length(); i++) {
            if (!toErase.empty() && i == toErase.back()) {
                toErase.pop_back();
                continue;
            }

            cout << str[i];
        }

        cout << '\n';
    }


    return 0;
}

/*
곱셈을 제거하면 안 되는 경우?

x(y + z ..)
(x + y)x

"뭐 곱하기 (합)" 인 경우

괄호 쌍 인덱스 찾고,
+있는 인덱스 찾고

괄호 인덱스를 살펴봐 하나씩
쌍안에 더하기가 있는데, (의 앞에 혹은 )의 뒤에 바로 문자가 나온다? 그럼 남기기

더하기인데, 해당 괄호 안에만 있는 괄호야 하네.


괄호 안에 있는 식이 곱인지 합인지 구분을 해야하네
괄호를 봤을 때,
    괄호와 곱해져 있는 값이 있다.
        안의 식이 곱만 존재한다. (혹은 괄호식 하나)
            괄호 제거
    곱해져 있는 값이 없다
        괄호 제거

*/