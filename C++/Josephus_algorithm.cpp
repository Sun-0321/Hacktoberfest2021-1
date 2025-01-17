// Author : Sundar

/*Problem Statement : N people are standing in a circle. We eliminate the M th person continuously.
Find the person who is not eliminated and is still there in the circle 

    Sample input:
        N = 5  M = 2

        Ans : 3
        The 3rd person is the person to stay till the last without elimination 

*/

#include <iostream>
using namespace std;

int josephus_iterative(int N, int M)
{
    int res = 0;
    for (int i = 1; i <= N; i++)
    {
        res = (res + M) % i;
    }
    return res + 1;
}

int josephus_recursive(int N, int M)
{
    if (N == 1)
        return 1;
    int a = josephus_recursive(N - 1, M);
    return (a + M - 1) % N + 1;
}



int main()
{
    int N, M;
    //N - number of people in the circle
    //M - people from the current location to be eliminated
    cin >> N >> M;
    
    cout << "Last Standing person derived using ITERATION : " << josephus_iterative(N, M) << '\n';
    cout << "Last Standing person derived using RECURSION : " << josephus_recursive(N, M) << '\n';
    return 0;
}