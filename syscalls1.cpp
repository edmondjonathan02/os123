#include <iostream>
#include <sys/types.h>
#include <unistd.h>
using namespace std;
int main()
{
    fork();
    cout << "Hello World" << endl;
    return 0;
}