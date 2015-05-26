#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <string>
#include <thread>
#include "std.h"

void addVecPrefix(vector<string>& vs, string s) 
{
	for(auto iter = vs.begin(); iter != vs.end(); iter++) {
		*iter = s + *iter;
	}
}

std::vector<std::string> readLines(std::ifstream& is, int n) 
{
	cout << "is open?: " << is.is_open() << endl;
	std::istream_iterator<std::string> start(is), end;
	std::vector<std::string> vs;
	
	std::string line;

	int i = 0;
	while ( i < n && std::getline(is, line) ) {
		if ( !line.empty() )
			vs.push_back(line);
		i++;
	}

	std::cout << vs.size() << std::endl;
	return vs;
}

void writeToFile(string s, vector<string> vs) 
{
	// overwrite
	std::ofstream output_file(s, std::ofstream::out);

	std::ostream_iterator<std::string> output_iterator(output_file);
	std::copy(vs.begin(), vs.end(), output_iterator);
}

void appendToFile(string s, vector<string> vs) 
{
	// append
	std::ofstream output_file(s, std::ofstream::app);

	std::ostream_iterator<std::string> output_iterator(output_file);
	std::copy(vs.begin(), vs.end(), output_iterator);
}

void loopFread(unsigned char** in, string p) 
{
	//unsigned char* in = new unsigned char[CHUNK];

	FILE *source = fopen(p.c_str(), "rb");
	int i = 0;

	while(fread(in[i], 1, CHUNK, source)) {
		i++;
	}

}

void addVecPrefixAndWrite(vector<string>& vs, string s, string wpath) 
{
	for(auto iter = vs.begin(); iter != vs.end(); iter++) {
		*iter = s + *iter;
	}

	writeToFile(wpath, vs);
}

void parseFileMuTex(std::ifstream& is, vector<string>& v1, vector<string>& v2, int n)
{
	v1 = readLines(is, n);
	v2 = readLines(is, n);

	string p1 = "1:";
	string p2 = "2:";

	//std::thread first  (addVecPrefix, std::ref(v1), p1);
	//std::thread second (addVecPrefix, std::ref(v2), p2);
	string wpath1 = "./out1";
	string wpath2 = "./out2";

	//std::thread first  (addVecPrefixAndWrite, std::ref(v1), p1, wpath1);
	//std::thread second (addVecPrefixAndWrite, std::ref(v2), p2, wpath2);
	//
	//first.join();
	//second.join();
}

void parseFile(std::ifstream& is, vector<string>& v1, int n)
{
	v1 = readLines(is, n);

	string p1 = "1:";

	//std::thread first  (addVecPrefix, std::ref(v1), p1);
	//std::thread second (addVecPrefix, std::ref(v2), p2);
	string wpath1 = "./out1";

	//addVecPrefixAndWrite(v1, p1, wpath1);
}

/*
int main(int argc, char** argv)
{
	std::string path = "../gz/WGC028532D_n1.fq";
	std::ifstream is(path);
}
*/
