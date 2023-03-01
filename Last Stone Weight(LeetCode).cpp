#include <bits/stdc++.h>
using namespace std;
//Last Stone Weight(LeetCode)
int lastStoneWeight(vector<int> &stones)
{
    multiset<int> st;
    for(auto val: stones){
        st.insert(val);
    }
    // auto itr=--st.end();
    while (st.size()>1)
    {
        auto itr=--st.end();
        auto itr2=--st.end();
        itr--;
        if((*itr)==(*itr2)){
            st.erase(itr);
            st.erase(itr2);
        }
        else{
            st.insert((*itr2)-(*itr));
            st.erase(itr);
            st.erase(itr2);
        }
        // itr2--;
    }
    if(st.size()>0) return (*st.begin());
    return 0;
}
