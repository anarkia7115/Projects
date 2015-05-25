#include "GZ.h"

class GZPair 
{

public:
	// constructor
	GZPair(string p1, string p2, string p3) 
	{
		gz1.setPath(p1);
		gz2.setPath(p2);

		setWritePath(p3);

		gzPair = make_pair(gz1, gz2);
		initFH();
	}

	// set path
	void setPath(string p1, string p2) 
	{
		gz1.setPath(p1);
		gz2.setPath(p2);

		gzPair = make_pair(gz1, gz2);

	}

	// get pair
	pair<GZ, GZ> getPair() 
	{
		return this->gzPair;
	}

	// test
	void testFunc(int i, bool isCompress) 
	{
		if(isCompress) {
			splitFiles(i);
		}
		else {
			splitFilesNoCompress(i);
		}
	}

	// split file
	void splitFilesNoCompress(int lineNum) 
	{

		lineNum = lineNum / 8;
		// init first part
		int i = 0;
		string p = wpath + "/"  + gz1.getName() + "_" + to_string(i) + ".out";

		// init line number
		int ln = 0;

		// open write file handle
		ofstream out;

		// loop until eof
		while(readLines()) 
		{

			// open new write file
			if(ln == 0) 
			{
				out.open(p);
			}

			writeLines(out);

			ln++;

			// one file generated
			if (ln >= lineNum) {
				ln = 0;

				// next part of file
				i++;
				out.close();

				// log file
				cout << "file: " << p << " done." << endl;
				p = wpath + "/"  + gz1.getName() + "_" + to_string(i) + ".out";

				// log date
				printDate();
			}
		}

		gzclose(gf1);
		gzclose(gf2);
		out.close();
	}

	// split file
	void splitFiles(int lineNum) 
	{

		lineNum = lineNum / 8;
		// init first part
		int i = 0;
		string p = wpath + "/" + gz1.getName() + "_" + to_string(i) + ".gz";

		// init line number
		int ln = 0;

		// open write file handle
		gzFile gfw;

		// loop until eof
		while(readLines()) 
		{

			// open new write file
			if(ln == 0) 
			{
				gfw = gzopen(p.c_str(), "w");
			}

			writeLines(gfw);

			ln++;

			// one file generated
			if (ln >= lineNum) {
				ln = 0;

				// next part of file
				i++;
				gzclose(gfw);

				// log file
				cout << "file: " << p << " done." << endl;
				p = wpath + "/" + gz1.getName() + "_" + to_string(i) + ".gz";

				// log date
				printDate();
			}
		}

		gzclose(gf1);
		gzclose(gf2);
		gzclose(gfw);
	}

private:
	GZ gz1;
	GZ gz2;

	vector<string> lines1;
	vector<string> lines2;

	gzFile gf1, gf2;

	pair<GZ, GZ> gzPair;

	string wpath;

	// Methods

	// write 4 lines to plain file
	void writeLines(ofstream& out)
	{
		// write
		for (auto l : lines1) 
		{
			out << l;
		}

		for (auto l : lines2) 
		{
			out << l;
		}

		lines1.clear();
		lines2.clear();
	}

	// write 4 lines
	void writeLines(gzFile& gfw) 
	{
		// write
		for (auto l : lines1) 
		{
			gzputs(gfw, l.c_str());
		}

		for (auto l : lines2) 
		{
			gzputs(gfw, l.c_str());
		}

		lines1.clear();
		lines2.clear();
	}

	// read 4 lines
	bool readLines() 
	{

		char buf1[CHUNK];
		char buf2[CHUNK];
		bool is_get;

		for (int i = 0; i < 4; i++) 
		{
			// read
			is_get = gzgets(gf1, buf1, CHUNK);
			gzgets(gf2, buf2, CHUNK);
			lines1.push_back(buf1);
			lines2.push_back(buf2);
		}
		return is_get;
	}

	// set write path
	void setWritePath(string p) 
	{
		this->wpath = p;
	}

	// init file handle
	void initFH() 
	{
		gf1 = gzopen(gzPair.first.getPath().c_str(),  "r");
		gf2 = gzopen(gzPair.second.getPath().c_str(), "r");
	}

	// print date
	void printDate() {

		time_t rawtime;
		struct tm * timeinfo;

		time (&rawtime);
		timeinfo = localtime (&rawtime);
		printf ("Date: %s", asctime(timeinfo));
	}
};
