#include "bookInfo.h"

// BookInfo constructor reads the Pride & Prejudice book
// and constructs a graph for each chapter of the book
BookInfo::BookInfo(){
	ifstream inFile("./1342.txt");
	if(!inFile){
		cout<<"Unable to open the file"<<endl;
		exit(1);
	}
	
	// goes to Chapter 1
	string line;
	while(getline(inFile, line) && line.find("Chapter 1") == string::npos){}
	
	// starts reading from Chapter 1 until the end of last chapter
	int chapter = 1;
	while(getline(inFile, line) && line.find("End of the Project Gutenberg EBook of Pride and Prejudice, by Jane Austen") 
		== string::npos){
			string cleanLine = Clean(line);
		
			// checks if a new chapter has begun
			if(cleanLine.find("chapter") != string::npos){
				chapter++;
				continue;
			}
			
			// constructs the graph for the given chapter
			stringstream ss(cleanLine);
			string word, prevWord = "";
			while(ss >> word){
				if(book[chapter].count(word) == 0){
					book[chapter][word] = new Node(word);
				} 
				
				book[chapter][word]->count++;
				
				if(prevWord == ""){
					prevWord = word;
					continue;
			 	}
			 	
			 	// sets the adjacenct word
				book[chapter][prevWord]->adjacent.push_back(word);
				prevWord = word;
		}
	}
	
	inFile.close();
}

// Clean cleans the given line
// it converts uppercase characters to lower case
// sets any kind of space to a single space
// removes special characters and digits
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

// PrintBook is a debugging function
// it returns the frequency of words in each chapter  
void BookInfo::PrintBook(){
	ofstream out("./out");
	int chapters = book.size();
	cout<<"Total chapters: "<<chapters<<endl<<endl;
	
	for(int i=1; i<=61; i++){
		out<<"Chapter "<<i<<endl;
		out<<"-------------"<<endl;
		unordered_map<string, Node*> chap = book[i];
		
		for(auto i=chap.begin(); i!=chap.end(); i++){
			out<<i->first<<' '<<i->second->count<<endl;
		}
		out<<endl;
	}
	
	out.close();
}
