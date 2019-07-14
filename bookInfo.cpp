#include "bookInfo.h"

// BookInfo constructor reads the Pride & Prejudice book
// and constructs a graph for each chapter of the book
BookInfo::BookInfo(){
	ifstream inFile("./1342.txt");
	ofstream o("./clean.txt");
	
	if(!inFile || !o){
		cout<<"Unable to open the file"<<endl;
		exit(1);
	}
	
	totalNumberOfWords = 0;
	
	// goes to Chapter 1
	string line;
	while(getline(inFile, line) && line.find("Chapter 1") == string::npos){}
	
	// starts reading from Chapter 1 until the end of last chapter
	int chapterNumber = 1;
	while(getline(inFile, line) && line.find("End of the Project Gutenberg EBook of Pride and Prejudice, by Jane Austen") 
		== string::npos){
			string cleanLine = Clean(line);
		
			// checks if a new chapter has begun
			if(cleanLine.find("chapter") != string::npos){
				chapterNumber++;
				continue;
			}
			
			// constructs the graph for the given chapter
			stringstream ss(cleanLine);
			string word, prevWord = "";
			while(ss >> word){
				o << word << ' ';
				if(book.count(word) == 0){
					book[word] = new Node();
				} 
				
				book[word]->count++;
				book[word]->chapterCount[chapterNumber]++;
				totalNumberOfWords++;
				
				if(prevWord == ""){
					prevWord = word;
					continue;
			 	}
			 	
			 	// sets the adjacenct word
				book[prevWord]->adjacent.push_back(word);
				prevWord = word;
		}
		o << endl;
	}
	
	totalChapters = chapterNumber;
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
	cout<<"Total chapters: "<<totalChapters<<endl<<endl;
	
	for(auto word : book){
		out<<word.first<<' ';
		unordered_map<int, int> currChapterCount = word.second->chapterCount;
		for(auto chapter : currChapterCount)
			out<<chapter.first<< " : "<<chapter.second<<", ";
		out<<endl;
	}
	
	out.close();
}

// getTotalNumberOfWords returns the total number of words in the book
int BookInfo::getTotalNumberOfWords(){

	return totalNumberOfWords;
}

// getTotalUniqueWords returns the number of unique words in the book
int BookInfo::getTotalUniqueWords(){

	return book.size();
}

bool desc_comp(pair<string, int> a, pair<string, int> b){
	if(a.second >= b.second) return true;
	return false;
}

bool asc_comp(pair<string, int> a, pair<string, int> b){
	if(a.second >= b.second) return false;
	return true;
}

// get20MostFrequentWords returns the top 20 most frequent words
vector<pair<string, int>> BookInfo::get20MostFrequentWords(){
	vector<pair<string, int>> heap;
	
	for(auto word : book){
		heap.push_back({word.first, word.second->count});
		pop_heap (heap.begin(), heap.end(), desc_comp);
		if(heap.size() > 21){
			heap.pop_back();
		}
	}
	
	pop_heap (heap.begin(), heap.end(), desc_comp);
	heap.pop_back();
	sort_heap(heap.begin(), heap.end(), desc_comp);
	return heap;
}

// getTop100FrequentWords returns the top 100 most frequent words 
unordered_set<string> BookInfo::getTop100FrequentWords(){
	unordered_set<string> top100FrequentWords;
	
	ifstream inFile("./1-1000.txt");
	if(!inFile){
		cout<<"Unable to open the file"<<endl;
		exit(1);
	}
	
	string word;
	while(inFile >> word && top100FrequentWords.size() != 100){
		top100FrequentWords.insert(Clean(word));
	}
	
	inFile.close();
	return top100FrequentWords;
}

// get20MostInterestingFrequentWords returns the top 20 most interesting frequent words
// these words do not appear in top 100 frequent words according to
// https://gist.github.com/deekayen/4148741. 
vector<pair<string, int>> BookInfo::get20MostInterestingFrequentWords(){
	
	unordered_set<string> notInteresting = getTop100FrequentWords();
	
	vector<pair<string, int>> heap;
	for(auto word : book){
		if(notInteresting.count(word.first)==0)
			heap.push_back({word.first, word.second->count});
		if(heap.size() > 21){
			pop_heap (heap.begin(), heap.end(), desc_comp);
			heap.pop_back();
		}
	}
	
	pop_heap (heap.begin(), heap.end(), desc_comp);
	heap.pop_back();
	sort_heap(heap.begin(), heap.end(), desc_comp);
	return heap;
}

// get20MostFrequentWords returns the top 20 least frequent words
vector<pair<string, int>> BookInfo::get20LeastFrequentWords(){
	vector<pair<string, int>> heap;
	
	for(auto word : book){
		heap.push_back({word.first, word.second->count});
		pop_heap (heap.begin(), heap.end(), asc_comp);
		if(heap.size() > 21){
			heap.pop_back();
		}
	}
	
	pop_heap (heap.begin(), heap.end(), asc_comp);
	heap.pop_back();
	sort_heap(heap.begin(), heap.end(), asc_comp);
	return heap;
}
