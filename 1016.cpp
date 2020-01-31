#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
double cost[24] = { 0 };
int month;
double dayprice = 0;
struct node {
	int day;
	int hour;
	int mins;
	int time;
	bool flag;
	double price;
	void init(int day, int hour, int mins, bool flag) {
		double price = dayprice * (day - 1);
		int time = 1440 * (day - 1);
		for (int i = 0; i < hour; i++) {
			price += cost[i];
		}
		time += hour * 60;
		price += (cost[hour] / 60) * mins;
		time += mins;
		this->price = price;
		this->day = day;
		this->hour = hour;
		this->mins = mins;
		this->time = time;
		this->flag = flag;
	}
};
typedef struct node Node;

map<string, vector<Node>>mp;

bool cmp(Node a, Node b) {
	return a.time < b.time;
}

void input() {
	mp.clear();
	for (int i = 0; i < 24; i++) {
		scanf("%lf", &cost[i]);
		cost[i] *= 0.6;
		dayprice += cost[i];
	}
	int n;
	scanf("%d", &n);
	string name, status;
	int mon, day, h, mins;
	bool flag;
	Node temp;
	for (int i = 0; i < n; i++) {
		cin >> name;
		scanf("%d:%d:%d:%d", &mon, &day, &h, &mins);
		cin >> status;
		if (status[1] == 'n') {
			flag = true;
		}
		else {
			flag = false;
		}
		temp.init(day, h, mins, flag);
		if (mp.find(name) == mp.end()) {
			mp[name] = vector<Node>();
		}
		mp[name].push_back(temp);
	}
	month = mon;
}

void work() {
	for (map<string, vector<Node>>::iterator iter = mp.begin(); iter != mp.end(); iter++) {
		sort(iter->second.begin(), iter->second.end(), cmp);
		bool flag = false;
		int lastindex = 0;
		double sum = 0;
		for (int i = 0; i < iter->second.size(); i++) {
			if (iter->second[i].flag) {
				flag = true;
				lastindex = i;
			}else if (flag && !iter->second[i].flag) {
				double temp = iter->second[i].price - iter->second[lastindex].price;
				int temptime = (iter->second[i].time - iter->second[lastindex].time);
				if (sum < 1e-11) {
					printf("%s %02d\n", iter->first.c_str(), month);
				}
				printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n", iter->second[lastindex].day,
					iter->second[lastindex].hour, iter->second[lastindex].mins,
					iter->second[i].day, iter->second[i].hour, iter->second[i].mins, temptime, temp);
				sum += temp;
				lastindex = i;
				flag = false;
			}else if (!flag) {
				lastindex = i;
			}
		}
		if (sum > 1e-11) {
			printf("Total amount: $%.2lf\n", sum);
		}
	}
}

int main() {
	input();
	work();
	return 0;
}
