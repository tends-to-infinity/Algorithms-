#include <iostream>
#include <stdlib.h>
#include<time.h>
using namespace std;
void tower_hanoi(int n, char from, char to, char tem)
{
    if (n == 1)
    {
        cout << "Move disk 1 from rod " << from << " to rod " << to << "\n";
        return;
    }
    tower_hanoi(n - 1, from, tem, to);
    cout << "Move disk " << n << " from rod " << from << " to rod " << to << "\n";
    tower_hanoi(n - 1, tem, to, from);
}
int main()
{
    int n;
    cin >> n;
     double time_spent=0.0;
     clock_t begin = clock();
    tower_hanoi(n, 'A', 'B', 'C');
    clock_t end = clock();
    time_spent += (double)(end - begin)/CLOCKS_PER_SEC;
    printf("Time of execution of program is:%lf",time_spent);
}
