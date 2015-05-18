#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<vector>

#define MAX 5000

using namespace std;

void printVecInt(vector<int>);

int main(int argc, char** argv) {

	/* initialize random seed: */
	srand(time(NULL));

	vector<int> randv;

	int randCiel = 999;

	if(argc > 1) {
		randCiel = atoi(argv[1]);
	}

	for(int i = 0; i < MAX; i++) {

		
		int ir = rand() % randCiel;

		randv.push_back(ir);
	}

	printVecInt(randv);

	return 0;
}

void printVecInt(vector<int> vi) {

	for(auto i : vi) {
		cout << i << endl;
	}
}
