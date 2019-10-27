#include <iostream>
#include <vector>

using namespace std;

bool canMakeItIncreasing(vector<int> list, int max_remove){
	int count=0;
	for(int i=1; i< list.size(); i++){
		if(list[i] < list[i-1]){
			count++;
			list.erase(list.begin() + i - 1);
			i = i-2;
		}
		if (count > max_remove){
                                return false;
                                break;
                }

	}
	return true;
}

int main(){
	vector<int> list1={1, 2, 3, 7, 5, 6};
	vector<int> list2={1, 2, 3, 7, 8, 4, 5};
	bool result_1=canMakeItIncreasing(list1,1);
	bool result_2=canMakeItIncreasing(list2,1);

	cout<<"list 1:"<<result_1<<endl;
	cout<<"list 2:"<<result_2<<endl;
}
