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
#include <stdlib.h>
#include <stack>
#include <time.h>
#include <sstream>
using namespace std;

// TreeNode defines a word
// in a given chapter, the
// frequency of the word
// and the words adjacent to it
struct Node {
	int count;
	unordered_map<string, unordered_map<int, int>> adjacent;
	
	Node(): count(0) {}
};

// TreeNode defines a node in a trie that
// stores complete sentences.
struct TrieNode {
	unordered_map<char, TrieNode*> children;
	bool endSentence;
	
	TrieNode(): endSentence(false){}
};	

class BookInfo{
	private:		
		//a hash table key: chapter, value:set of nodes of words
		unordered_map<string, Node*> book;
		TrieNode* root;
				
		int totalChapters;
		int totalNumberOfWords;
		
		// getCompleteSentence finds complete sentences in the text.
		string getCompleteSentence(string remaining, string line);

		// inserting a sentence into a trie
		void insert(string line);
	
		int getChapterHelper(vector<string> &words, int curr, int chap);
		
		// a helper function that returns all the chapters the word is
		// present in
		unordered_set<int> presentInChapters(string word);
	
		
	public:
		BookInfo();
		
		// Total number of chapters
		int getTotalChapters();
		
		// Total number of words in the book
		int getTotalNumberOfWords();
		
		// Total number of unique words in the book
		int getTotalUniqueWords();
		
		// a list of top 20 most frequent words along with
		// its frequency
		vector<pair<string, int>> get20MostFrequentWords();
		
		// a list of top 20 most interesting frequent words along
		// with its frequency
		vector<pair<string, int>> get20MostInterestingFrequentWords();
		
		// a list of top 20 least frequent words and its frequency
		vector<pair<string, int>> get20LeastFrequentWords();
		
		// a list of frequency of the word in each chapter
		vector<int> getFrequencyOfWord(string word);
		
		// gets the chapter in which the given quote is present
		int getChapterQuoteAppears(string sentence);
		
		// generates sentences in author's style
		string generateSentence();
		
		// a list of possible sentences with the given prefix
		vector<string> getAutocompleteSentence(string startOfSentence);
};

// for results in decreasing order
bool desc_comp(pair<string, int> a, pair<string, int> b);

// for results in ascending order
bool asc_comp(pair<string, int> a, pair<string, int> b);

// cleans the given line
string clean(string line);

// getTop100FrequentWords returns the top 100 most frequent words 
unordered_set<string> getTop100FrequentWords();
	
