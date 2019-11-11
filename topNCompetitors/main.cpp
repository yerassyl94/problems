#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

vector<string> topCompetitors(int topN, vector<string> competitors, vector<string> reviews){
	unordered_map<string,int> map;
	for(int i = 0; i < reviews.size(); i++){
		for(int j=0; j < competitors.size(); j++){
			if (reviews[i].find(competitors[j]) != string::npos){
				map[competitors[j]]++;
			}
		}
	}

	vector<string> res;
	priority_queue<pair<int,string>> pq;
	for(auto i=map.begin();i != map.end(); i++){
		pq.push(make_pair(i->second,i->first));
		if(pq.size() > map.size() - topN){
			res.push_back(pq.top().second);
			pq.pop();
		}
	}

	return res;
}

int main(){
	int topNCompetitors = 2;
	vector<string> competitors{"newshop", "shopnow", "afashion", "fashionbeats", "mymarket"};
	vector<string> reviews{"newshop is providing good services in the city; everyone should use newshop",
                        "best services by newshop", "fashionbeats has great services in the city",
                        "i am proud to have fashionbeats", "mymarket has awesome services",
                        "Thanks newshop for the quick delivery"};

	vector<string> res = topCompetitors(topNCompetitors, competitors, reviews);

	for(int i= 0; i < res.size(); i++){
		cout << res[i] << endl;
	}
}
