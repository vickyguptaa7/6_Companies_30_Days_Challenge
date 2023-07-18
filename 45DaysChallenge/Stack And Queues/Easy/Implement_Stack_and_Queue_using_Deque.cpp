#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

typedef long long ll;

class Stack
{
    deque<int> st;

public:
    void push(int val)
    {
        st.push_back(val);
    }
    int pop()
    {
        if (st.size() == 0)
            return -1;
        int val = st.back();
        st.pop_back();
        return val;
    }
    bool isEmpty()
    {
        return st.size() == 0;
    }
};

class Queue
{
    deque<int> st;

public:
    void push(int val)
    {
        st.push_back(val);
    }
    int pop()
    {
        if (st.size() == 0)
            return -1;
        int val = st.front();
        st.pop_front();
        return val;
    }
    bool isEmpty()
    {
        return st.size() == 0;
    }
};

int main()
{
    return 0;
}