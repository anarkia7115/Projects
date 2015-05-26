#include "std.h"
#include "thread_read.h"

#define MAX 50000

/* Decompress from file source to file dest until stream ends or EOF.
   inf() returns Z_OK on success, Z_MEM_ERROR if memory could not be
   allocated for processing, Z_DATA_ERROR if the deflate data is
   invalid or incomplete, Z_VERSION_ERROR if the version of zlib.h and
   the version of the library linked do not match, or Z_ERRNO if there
   is an error reading or writing the files. */
int inf(string pr, string pw)
{
	int ret;
	unsigned have;
	z_stream strm;
	//unsigned char in[CHUNK];
	//unsigned char out[CHUNK];
	unsigned char* in = new unsigned char[CHUNK];
	unsigned char* out = new unsigned char[CHUNK];

	FILE *source = fopen(pr.c_str(), "rb");
	FILE *dest = fopen(pw.c_str(), "w");

	/* allocate inflate state */
	strm.zalloc = Z_NULL;
	strm.zfree = Z_NULL;
	strm.opaque = Z_NULL;
	strm.avail_in = 0;
	strm.next_in = Z_NULL;
	// ret = inflateInit(&strm);
	ret = inflateInit2(&strm, 16+MAX_WBITS);
	if (ret != Z_OK)
		return ret;

	/* decompress until deflate stream ends or end of file */
	do {
		strm.avail_in = fread(in, 1, CHUNK, source);
		if (ferror(source)) {
			(void)inflateEnd(&strm);
			return Z_ERRNO;
		}
		if (strm.avail_in == 0)
			break;
		strm.next_in = in;

		/* run inflate() on input until output buffer not full */
		do {
			strm.avail_out = CHUNK;
			strm.next_out = out;
			ret = inflate(&strm, Z_NO_FLUSH);
			assert(ret != Z_STREAM_ERROR);  /* state not clobbered */
			switch (ret) {
			case Z_NEED_DICT:
				ret = Z_DATA_ERROR;	 /* and fall through */
			case Z_DATA_ERROR:
			case Z_MEM_ERROR:
				(void)inflateEnd(&strm);
				return ret;
			}
			have = CHUNK - strm.avail_out;

			if (fwrite(out, 1, have, dest) != have || ferror(dest)) {
				(void)inflateEnd(&strm);
				return Z_ERRNO;
			}
		} while (strm.avail_out == 0);

		/* done when inflate() says it's done */
	} while (ret != Z_STREAM_END);

	/* clean up and return */
	(void)inflateEnd(&strm);
	return ret == Z_STREAM_END ? Z_OK : Z_DATA_ERROR;
}

int inf2thread(string pr, string pw)
{
	int ret;
	unsigned have;
	z_stream strm;
	//unsigned char in[CHUNK];
	//unsigned char out[CHUNK];
	unsigned char* in = new unsigned char[CHUNK];
	unsigned char* out = new unsigned char[CHUNK];

	FILE *source = fopen(pr.c_str(), "rb");
	FILE *dest = fopen(pw.c_str(), "w");

	/* allocate inflate state */
	strm.zalloc = Z_NULL;
	strm.zfree = Z_NULL;
	strm.opaque = Z_NULL;
	strm.avail_in = 0;
	strm.next_in = Z_NULL;
	// ret = inflateInit(&strm);
	ret = inflateInit2(&strm, 16+MAX_WBITS);
	if (ret != Z_OK)
		return ret;

	/* decompress until deflate stream ends or end of file */
	do {
		strm.avail_in = fread(in, 1, CHUNK, source);
		if (ferror(source)) {
			(void)inflateEnd(&strm);
			return Z_ERRNO;
		}
		if (strm.avail_in == 0)
			break;
		strm.next_in = in;

		/* run inflate() on input until output buffer not full */
		do {
			strm.avail_out = CHUNK;
			strm.next_out = out;
			ret = inflate(&strm, Z_NO_FLUSH);
			assert(ret != Z_STREAM_ERROR);  /* state not clobbered */
			switch (ret) {
			case Z_NEED_DICT:
				ret = Z_DATA_ERROR;	 /* and fall through */
			case Z_DATA_ERROR:
			case Z_MEM_ERROR:
				(void)inflateEnd(&strm);
				return ret;
			}
			have = CHUNK - strm.avail_out;

			if (fwrite(out, 1, have, dest) != have || ferror(dest)) {
				(void)inflateEnd(&strm);
				return Z_ERRNO;
			}
		} while (strm.avail_out == 0);

		/* done when inflate() says it's done */
	} while (ret != Z_STREAM_END);

	/* clean up and return */
	(void)inflateEnd(&strm);
	return ret == Z_STREAM_END ? Z_OK : Z_DATA_ERROR;
}

void test(string path) 
{
	string wpath = "../small_plate/test_out.out";
	//inf(path, wpath);

	unsigned char** in = new unsigned char*[MAX];
	for(int i = 0; i <MAX; i++) {
		in[i] = new unsigned char[CHUNK];
	}

	//loopFread(in, path);
	//getchar();

}

int main(int argc, char** argv) 
{


	string path = "../gz/WGC_10m_n1.fq";
	string wpath = "./out";
	//string path = "../gz/WGC028532D_n2.fq.gz";
	std::ifstream is(path);

	//20,000,000
	int n = 20000000;
	//int n = 20000000 / 2;

	vector<string> v1;
	vector<string> v2;

	//parseFileMuTex(is, v1, v2, n);
	parseFile(is, v1, n);
	

	//auto vs = readLines(is, n);
	
	//writeToFile(wpath, v1);
	//appendToFile(wpath, v2);
	

	return 0;
}
