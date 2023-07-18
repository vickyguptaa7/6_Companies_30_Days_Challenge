class MyStack
{
    queue<int> que1;

public:
    MyStack()
    {
    }

    void push(int x)
    {
        que1.push(x);
        int size = que1.size() - 1;
        while (size-- > 0)
        {
            que1.push(que1.front());
            que1.pop();
        }
    }

    int pop()
    {
        int val = que1.front();
        que1.pop();
        return val;
    }

    int top()
    {
        return que1.front();
    }

    bool empty()
    {
        return que1.empty();
    }
};