// bookInfo.h contains the defination of the functions available
#include <iostream>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// TreeNode defines a word
// in a given chapter, the
// frequency of the word
// and the words adjacent to it
struct TreeNode {
	string word;
	int count;
	vector<TreeNode*> adjacent;
};

class BookInfo{
	private:
		//a hash table key: chapter, value:set of nodes of words
		unordered_map<int, unordered_set<TreeNode*>> book;
		
	public:
		BookInfo()
		
		int getTotalNumberOfWords();
		int getTotalUniqueWords();
		unordered_map<string, int> get20MostFrequentWords();
		unordered_map<string, int> get20MostInterestingFrequentWords();
		unordered_map<string, int> get20LeastFrequentWords();
		unordered_map<int, int> getFrequencyOfWord(string word);
		
		int getChapterQuoteAppears(string sentence);
		string generateSentence();
};
