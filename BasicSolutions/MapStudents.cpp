// Taking Student's name and age and storing it in a map
#include <iostream>
#include <map>

using namespace std;

void getInput(int *tempAge, int i, string *tempName){
    cout << "Enter " << i + 1 << "st student's name: \n";
	cin >> *tempName;

	cout << "Enter age: ";
	cin >> *tempAge;
}

int main() {
	int num, tempAge;
	string tempName;

	map<string, int> students;

	printf("Enter number of students: ");
	scanf("%d", &num);

	for (int i = 0; i < num; i++)
	{
        getInput(&tempAge, i, &tempName);
		students[tempName] = tempAge;
	}

	map<string, int> ::iterator studentList;

	for (studentList = students.begin(); studentList != students.end(); ++studentList)
	{
		cout << studentList->first << " - " << studentList->second << "\n";
	}
	return 0;
}
