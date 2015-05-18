#include "std.h"

// for find_if
struct MatchPathSeparator
{
    bool operator()( char ch ) const
    {
        return ch == '/';
    }
};

class GZ 
{

public:
	// constructor
	GZ(string s) 
	{
		setPath(s);
		parseName();
	}

	GZ(){}

	string getPath() 
	{
		return path;
	}

	void setPath(string s) 
	{
		this->path = s;
		parseName();
	}

	string getName() 
	{
		return fileName;
	}

	// init fileName through the path
	void parseName() 
	{
		fileName = basename(path);
	}

private:
	string path;
	string fileName;

	// basename of the file
	std::string
	basename( std::string const& pathname )
	{
		// return last part of the string
		// seprate by '/'
		return std::string( 
		std::find_if( pathname.rbegin(), pathname.rend(),
			      MatchPathSeparator() ).base(),
		pathname.end() );
	}

};

