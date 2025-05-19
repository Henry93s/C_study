#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
	// 1. unordered_map
	unordered_map<string, int> um;
	um.insert({ "A", 100});
	um.insert(make_pair("B", 200));
	um.insert({
		{"C",1000},
		{"D",2000}
		});
	for (auto i = um.begin();i != um.end();++i) {
		cout << "[" << i->first << " " << i->second << "] ";
	}
	cout << endl;

	cout << "B의 값을 찾아보자" << endl;
	auto bc = um.bucket("B");
	for (auto i = um.begin(bc);i != um.end(bc);++i) {
		cout << i->first << ":" << i->second;
	}
	cout << endl;
	cout << endl;
	cout << endl;

	// 2. unordered_multiset
	unordered_multiset<string> cities{
		"Braunschweig", "Hanover", "Frankfurt", "New York",
		"Chicago", "Toronto", "Paris", "Frankfurt"
	};
	for (const auto& elem : cities) {
		cout << elem << " ";
	}
	cout << endl;
	cities.insert({ "London", "Munich", "Hanover", "Braunschweig" });
	for (const auto& elem : cities) {
		cout << elem << " ";
	}
	cout << endl;

	return 0;
}