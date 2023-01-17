class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int>que;
        for(int i=1;i<=n;i++)que.push(i);
        int temp=k;
        while(que.size()>1)
        {
            int val=que.front();
            que.pop();
            temp--;
            if(temp==0)
            {
                temp=k;
                continue;
            }
            que.push(val);
        }
        return que.front();
    }
};