#include "GZPair.h"


int main(int argc, char** argv) {

	string rpath1 = "sample_n1.gz";
	string rpath2 = "sample_n1.gz";

	GZPair p(rpath1, rpath2);

	auto gzPair = p.getPair();

	string wpath = "./part1.gz";

	// input file
	gzFile gf1 = gzopen(gzPair.first.getPath().c_str(),  "r");
	gzFile gf2 = gzopen(gzPair.second.getPath().c_str(), "r");

	vector<char> buf1;
	vector<char> buf2;
	buf1.resize(CHUNK);
	buf2.resize(CHUNK);

	gzgets(gf1, &buf1[0], CHUNK);
	gzgets(gf2, &buf2[0], CHUNK);
	//gzread(gf1, &buf1[0], CHUNK);
	//gzread(gf2, &buf2[0], CHUNK);
	gzclose(gf1);
	gzclose(gf2);

	// read end
	cout << "read end" << endl;

	// write open
	gzFile wgf = gzopen(wpath.c_str(), "w");

	// write
	gzwrite(wgf, &buf1[0], CHUNK);
	gzwrite(wgf, &buf2[0], CHUNK);

	gzclose(wgf);



	return 0;
}
