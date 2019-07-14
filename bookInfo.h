// bookInfo.h contains the defination of the functions available
#include <iostream>
#include <fstream>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <vector>
#include <utility> 
#include <queue>
#include <sstream>
using namespace std;

// TreeNode defines a word
// in a given chapter, the
// frequency of the word
// and the words adjacent to it
struct Node {
	int count;
	unordered_map<int, int> chapterCount;
	vector<string> adjacent;
	
	Node(): count(0) {}
};

class BookInfo{
	private:		
		//a hash table key: chapter, value:set of nodes of words
		unordered_map<string, Node*> book;
				
		int totalChapters;
		int totalNumberOfWords;
		
		string Clean(string line);
		unordered_set<string> getTop100FrequentWords();

		
	public:
		BookInfo();
		void PrintBook();
		
		int getTotalNumberOfWords();
		int getTotalUniqueWords();
		vector<pair<string, int>> get20MostFrequentWords();
		vector<pair<string, int>> get20MostInterestingFrequentWords();
		vector<pair<string, int>> get20LeastFrequentWords();
		unordered_map<int, int> getFrequencyOfWord(string word);
		
		int getChapterQuoteAppears(string sentence);
		string generateSentence();
};
