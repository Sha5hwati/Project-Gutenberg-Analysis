#include "bookInfo.h"

BookInfo::BookInfo(){
	ifstream inFile("./1342.txt");
	if(!inFile){
		cout<<"Unable to open the file"<<endl;
		exit(1);
	}
	
	string line;
	while(getline(inFile, line) && line.find("Chapter 1") == string::npos){}
	
	int chapter = 1;
	while(getline(inFile, line) && line.find("End of the Project Gutenberg EBook of Pride and Prejudice, by Jane Austen") == string::npos){
		string cleanLine = Clean(line);
	
		if(cleanLine.find("chapter") != string::npos){
			chapter++;
			continue;
		}
		
		stringstream ss(cleanLine);
		string word;
		string prevWord, currWord;
		ss >> prevWord;
		while(ss >> currWord){
		
			if(book[chapter].count(prevWord) == 0){
				book[chapter][prevWord] = new Node(prevWord);
			} 
			
			book[chapter][prevWord]->count++;
			book[chapter][prevWord]->adjacent.push_back(currWord);
			prevWord = currWord;
		}
		
		if(currWord == "") continue;
		
		if(book[chapter].count(currWord) == 0){
			book[chapter][currWord] = new Node(currWord);
		}
		book[chapter][currWord]->count++;
	}
	
	inFile.close();
}

string BookInfo::Clean(string line){
	string clean = "";
	for (unsigned int i=0; i<line.length(); i++){
		if(isalpha(line[i])){
			char c = tolower(line[i]);
			clean.push_back(c);
		}
		if(isspace(line[i])){
			clean.push_back(' ');
		}
	}
	return clean;
}

void BookInfo::PrintBook(){
	ofstream out("./out");
	int chapters = book.size();
	cout<<"Total chapters: "<<chapters<<endl<<endl;
	for(int i=1; i<=61; i++){
		unordered_map<string, Node*> chap = book[i];
		for(auto i=chap.begin(); i!=chap.end(); i++){
			out<<i->first<<' '<<i->second->count<<endl;
		}
		out<<endl;
	}
}
