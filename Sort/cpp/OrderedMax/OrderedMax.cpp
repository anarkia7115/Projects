#include<iostream>
#include<string>
#include<sstream>
#include<utility>
#include<vector>
#include<cmath>

using namespace std;

// function declare
void orderedMax(string line, vector<pair<int,int> >& maxkv, int& prev, int& max, int& isNew);
void printPairList(vector<pair<int, int> >);
int intLen(int);


// main
int main(int argc, char** argv) {

	string line;

	vector<pair<int,int> > maxkv;
	int prev = -1;
	int max = -1;
	int isNew = 1;

	while(getline(cin, line)) {

		// ignore empty line
		if(line.empty())
			continue;

		orderedMax(line, maxkv, prev, max, isNew);

	}

	// push prev key
	pair<int, int> p = make_pair(prev, max);

	maxkv.push_back(p);

	printPairList(maxkv);
	
	return 0;
}

// Print pair
void printPairList(vector<pair<int, int> > vp) {

	for(auto p : vp) {
		cout 	<< "<"
			<< p.first
			<< ", "
			<< p.second
			<< ">"
			<< endl;
	}

}

// Ordered Max
void orderedMax(string line, vector<pair<int,int> >& maxkv, int& prev, int& max, int& isNew) {

	int k1;
	int k2;
	int key;
	int val;


	// get key and value
	istringstream iss(line);
	iss >> k1 >> k2 >> val;

	key = k1 * pow(10, intLen(k2)) + k2;
	// k1 * 10^n + k2

	pair<int, int> p;

	if(key == prev) {
		
		// update max val
		if(val > max) {
		
			max = val;
		}

	}
	else {
		// new key
		// push prev key
		p = make_pair(prev, max);

		prev = key;
		max = val;

		if (isNew) {
			isNew = 0;
			return;
		}

		maxkv.push_back(p);
	}

}

// Length of Integer
int intLen(int i) {

	unsigned int number_of_digits = 0;
	int base = 10;


	do {

		++number_of_digits; 
		i /= base;

	} while (i);

	return number_of_digits;
}
