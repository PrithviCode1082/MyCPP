#include <stdio.h>
#include <set>

using namespace std;
// Taking Inputs and storing unique values in a set
int main() {
    set<int> nums;
    int num, temp;

    printf("Enter number of elements to sort: ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        printf("Enter Element no: %d - ", (i+1));
        scanf("%d", &temp);
        nums.insert(nums.begin(), temp);
    }

    for (int n : nums) {
        printf("%d\n", n);
    }
    return 0;
}
