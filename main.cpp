#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include "md5.h"

using namespace std;

void usage(string name){
	cout << endl <<endl<<"Md5 Hash Bruteforce"<<endl<< "by Gdm1 ---> http://www.ideneal.hellospace.net/" << endl;
	cout << endl <<endl<<"USAGE :"<<endl<< name << " : <options> <mincount> <maxcount> <MD5>"<<endl;
	cout << endl<< endl << "OPTIONS :"<<endl;
	cout << "a = [ abcdefghijklmnopqrstuvwxyz ]"<<endl;
	cout << "A = [ ABCDEFGHIJKLMNOPQRSTUVWXYZ ]"<<endl;
	cout << "d = [ 1234567890 ]"<<endl;
	cout << "x = [ !\"[$%&/()]=?-.:\\*'-_:.;, ]"<<endl;
	cout << endl << endl ;
	cout << "EXAMPLE :"<<endl;
	cout <<name<< " ad 3 3 9cdfb439c7876e703e307864c9167a15"<<endl;
	cout <<name<< " aAx 1 3 9cdfb439c7876e703e307864c9167a15"<<endl;
}


//Un ringraziamento a Midnightmare per questa funzione semplicemente fantastica :D

vector<int> DisposizioniR(int n, int k, bool init = false){
	static vector<int> v;
	static vector<int> c;
	
	if(init){
		v.clear();
		c.clear();
		
		for (int i=0; i<n; i++)
			v.push_back(i);
		
		for (int i=0; i<k; i++)
			c.push_back(0);
		
		c[c.size() - 1]--;
	}
	
	int con = 0;
	
	for(int i=0; i<k; i++)
		if(c[i] == v[v.size() - 1])
			con++;
	
	if(con == k){
		c.resize(0);
		return c;
	}
	
	int i = k - 1;
	
	while(c[i] == v[v.size() - 1])
		i--;
	
	c[i]++;
	
	for (int j = i + 1; j < k; j++)
		c[j] = v[0];
	
	return c;
}

int main(int argc, char * argv[]){
	bool found = false, init;
	vector<int> v;
	Md5 * md5 = new Md5();
	string crypto = argv[4];
	string search;
	string compare;
	if(argc != 5){
		usage(argv[0]);
		exit(1);
	}
	// opzioni
	for(int i=0; i<=strlen(argv[1]); i++){
		switch(argv[1][i]){
			case 'a':
				search += "abcdefghijklmnopqrstuvwxyz";
				break;
			case 'A':
				search += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
				break;
			case 'd':
				search += "1234567890";
				break;
			case 'x':
				search += "!\"[$%&/()]=?-.:\\*'-_:.;,";
				break;
		}
	}
	
	for(int j=atoi(argv[2]); j<=atoi(argv[3]) && !found; j++){
		init = true;
		do{
			v = DisposizioniR(search.size(), j, init);
			init = false;
			for (int i = 0; i < v.size(); i++)
				compare += search[v[i]];
			md5->setWord(compare);
			cout << crypto << "  !=  "<<md5->toMd5()<<"  ("<<md5->getWord()<<")"<<endl;
			if(crypto == md5->toMd5())
				found = true;
			compare = "";
		}while(v.size() > 0 && !found);
	}
	
	if(found)
		cout << endl << endl << "Md5 cracked"<<endl<<crypto<< "  :  "<<md5->getWord()<<endl;
	else
		cout << endl << endl << "Md5 not cracked!!!"<<endl;
	
	
	delete md5;
	return 0;
}
