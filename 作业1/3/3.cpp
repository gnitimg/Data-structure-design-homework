#include<bits/stdc++.h>
using namespace std;

class queues
{
    private:
        queue<int>qa, qb;
    public:
        void print(int n)
        {
            qa.push(1);
            for (int i = 0; i <n; i++)
            {
                int pre = 0;
                while (!qa.empty())
                {
                    int curr = qa.front();
                    qa.pop();
                    cout << curr << " ";
                    qb.push(pre + curr);//输出qa的同时预处理qb
                    pre = curr;
                }
                qb.push(1);
                cout << endl;
                swap(qa, qb);
        }
    }

    void returns(int n)
    {
        if (n <= 0) cout << "invalid input!!!" << endl;
        else print(n);
    }
};

int main()
{
    int c;
    cin >> c;
    queues q;
    q.returns(c);
    return 0;
}