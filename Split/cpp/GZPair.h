#include "GZ.h"

class GZPair 
{

public:
	// constructor
	GZPair(string p1, string p2) 
	{
		gz1.setPath(p1);
		gz2.setPath(p2);

		gzPair = make_pair(gz1, gz2);
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
	void testFunc() 
	{
		string path1 = "/home/gaojiaxiang/Projects/Split/cpp/GZ.h";
		string path2 = "/home/gaojiaxiang/Projects/Split/cpp/GZPair.h";

		GZPair gzp(path1, path2);

		pair<GZ, GZ> p = gzp.getPair();


		cout << "path: " << p.first.getPath() << endl;
		cout << "name: " << p.first.getName() << endl;
		cout << "path: " << p.second.getPath() << endl;
		cout << "name: " << p.second.getName() << endl;
	}

private:
	GZ gz1;
	GZ gz2;

	pair<GZ, GZ> gzPair;
};
