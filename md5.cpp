#include "md5.h"

string Md5::toHex(){
	string md;
	char lol[16*2];
	for(int i=0 , j=0 ; i<16 ; i++ , j+=2)
		sprintf(&lol[j], "%02x", this->lol[i]);
	for(int i=0; i<16*2; i++)
		md += lol[i];
	return md;
}

void Md5::init(string name){
	MD5_Init(this->md5);
	MD5_Update(this->md5, name.c_str(), name.size());
	MD5_Final(this->lol, this->md5);
}

Md5::Md5(){
	this->md5 = new MD5_CTX();
}

Md5::Md5(string name){
	this->md5 = new MD5_CTX();
	this->word = name;
	this->init(name);
}

Md5::~Md5(){
	delete this->md5;
}

string Md5::getWord() const{
	return this->word;
}

string Md5::toMd5(){
	return this->toHex();
}

void Md5::setWord(string name){
	this->word = name;
	this->init(name);
}
