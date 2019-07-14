// bookInfo.h contains the defination of the functions available
#include <iostream>
#include <fstream>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;

// TreeNode defines a word
// in a given chapter, the
// frequency of the word
// and the words adjacent to it
struct Node {
	string word;
	int count;
	vector<string> adjacent;
	
	Node(string w): word(w), count(0) {}
};

class BookInfo{
	private:
		//a hash table key: chapter, value:set of nodes of words
		unordered_map<int, unordered_map<string, Node*>> book;
		string Clean(string line);
		
	public:
		BookInfo();
		void PrintBook();
		
		int getTotalNumberOfWords();
		int getTotalUniqueWords();
		unordered_map<string, int> get20MostFrequentWords();
		unordered_map<string, int> get20MostInterestingFrequentWords();
		unordered_map<string, int> get20LeastFrequentWords();
		unordered_map<int, int> getFrequencyOfWord(string word);
		
		int getChapterQuoteAppears(string sentence);
		string generateSentence();
};
