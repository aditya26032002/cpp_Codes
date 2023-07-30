#include <bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

class Solution
{
public:
    int tour(petrolPump p[], int n)
    {
        int front = 0, rear = 0;
        while (front < n)
        {
            rear = front;
            int tankCapacity = 0;
            while (true)
            {
                tankCapacity = tankCapacity + (p[rear].petrol) - (p[rear].distance);
                if (tankCapacity >= 0)
                    rear++;
                else
                    break;
                if (rear == n)
                    rear = 0;
                if (front == rear)
                    return front;
            }
            if (rear < front)
                return -1;
            else
                front = rear + 1;
        }
        return -1;
    }
};

int main()
{

    return 0;
}