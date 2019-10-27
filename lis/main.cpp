#include <iostream>
#include <vector>

using namespace std;

int getIndex(vector<int> tail, int l, int r, int key){
	while(r-l > 1){
		int m = l + (r-l)/2;
		if(tail[m] >= key)
			r=m;
		else
			l=m;
	}

	return r;
}

int lis(vector<int> list){
	if(list.size()==0)
		return 0;

	vector<int> tail(list.size(), 0);
	int length = 1;
	tail[0] = list[0];

	for(int i = 1; i < list.size(); i++){
		if (list[i] < tail[0])
			tail[0] = list[i];

		else if (list[i] > tail[length - 1])
			tail[length++] = list[i];

		else
			tail[getIndex(tail, -1, length -1, list[i])] = list[i];
	}

	return length;
}

int main(){
	vector<int> v{2, 5, 3, 7, 11, 8, 10, 13, 6};
	cout<<"result:"<<lis(v)<<endl;
	return 0;
}
