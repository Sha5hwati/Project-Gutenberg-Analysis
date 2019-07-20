#include "bookInfo.h"

// for results in decreasing order
bool desc_comp(pair<string, int> a, pair<string, int> b){
	if(a.second >= b.second) return true;
	return false;
}

// for results in ascending order
bool asc_comp(pair<string, int> a, pair<string, int> b){
	if(a.second >= b.second) return false;
	return true;
}

// cleans the given line
// it converts uppercase characters to lower case
// sets any kind of space to a single space
// removes special characters and digits
string clean(string line){
	string cleanSentence = "";
	for (unsigned int i=0; i<line.length(); i++){
		if(isalpha(line[i])){
			char c = tolower(line[i]);
			cleanSentence.push_back(c);
		}
		if(isspace(line[i])){
			cleanSentence.push_back(' ');
		}
	}
	return cleanSentence;
}

// getCompleteSentence finds complete sentences in the text.
// a complete sentence starts after a . (start of a sentence)
// and before a . (end of a sentence)
string BookInfo::getCompleteSentence(string remaining, string line){
	line.pop_back();
	remaining += line + " ";
	
	if(line.find(".") == string::npos) return remaining;
	
	int pos = remaining.find_first_of(".");
	int curr = -1;
	
	while(pos != string::npos){
		string completeSentence = remaining.substr(curr+1, pos-curr);
		curr = pos;
		pos = remaining.find_first_of(".", pos+1);
		insert(completeSentence);
	}
	remaining = remaining.substr(curr+1);
	return remaining;
}

// getTop100FrequentWords returns the top 100 most frequent words 
unordered_set<string> getTop100FrequentWords(){
	unordered_set<string> top100FrequentWords;
	
	ifstream inFile("./1-1000.txt");
	if(!inFile){
		cout<<"Unable to open the file"<<endl;
		exit(1);
	}
	
	string word;
	while(inFile >> word && top100FrequentWords.size() != 100){
		top100FrequentWords.insert(clean(word));
	}
	
	inFile.close();
	return top100FrequentWords;
}

