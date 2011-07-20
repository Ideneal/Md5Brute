#ifndef MD5_H
#define MD5_H

#include <iostream>
#include <cstdio>
#include <string>
#include <openssl/md5.h>

using namespace std;

class Md5{
	private:
		string word;
		MD5_CTX * md5;
		unsigned char lol[ 16 ];
		
		string toHex();
		void init(string);
	public:
		Md5();
		Md5(string);
		~Md5();
		
		string getWord() const;
		string toMd5();
		
		void setWord(string);
};
#endif
