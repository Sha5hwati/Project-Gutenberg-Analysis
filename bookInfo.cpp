#include "bookInfo.h"

// BookInfo constructor reads the Pride & Prejudice book
// and constructs a graph for each chapter of the book
BookInfo::BookInfo(){
	ifstream inFile("./1342.txt");
	
	if(!inFile){
		cout<<"Unable to open the file"<<endl;
		exit(1);
	}
	
	totalNumberOfWords = 0;
	totalChapters = 1;
	root = new TrieNode();
    srand((unsigned)time(0));
	
	// goes to Chapter 1
	string line;
	while(getline(inFile, line) && line.find("Chapter 1") == string::npos){}
	
	// starts reading from Chapter 1 until the end of last chapter
	string word, prevWord = "";
	string remaining = "";
	while(getline(inFile, line) && line.find("End of the Project Gutenberg EBook of Pride and Prejudice, by Jane Austen") 
		== string::npos){
			line = clean(line);
		    remaining = getCompleteSentence(remaining, line);
		    
			// checks if a new chapter has begun
			if(line.find("chapter") != string::npos){
				totalChapters++;
				prevWord = "";
				continue;
			}
			
			// constructs the graph for the given chapter
			stringstream ss(line);
			while(ss >> word){
				if(book.count(word) == 0){
					book[word] = new Node();
				} 
				
				book[word]->count++;
				totalNumberOfWords++;
				
				if(prevWord == ""){
					prevWord = word;
					continue;
			 	}
			 	
			 	// sets the adjacenct word
				book[prevWord]->adjacent[word][totalChapters]++;
				prevWord = word;
			}
	}
	
	inFile.close();
}

// getTotalChapters returns the total number of chapters excluding
// introductory and endings sections
int BookInfo::getTotalChapters(){
	return totalChapters;
}

// getTotalNumberOfWords returns the total number of words in the book
int BookInfo::getTotalNumberOfWords(){

	return totalNumberOfWords;
}

// getTotalUniqueWords returns the number of unique words in the book
int BookInfo::getTotalUniqueWords(){

	return book.size();
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
