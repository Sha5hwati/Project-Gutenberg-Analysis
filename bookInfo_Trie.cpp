#include "bookInfo.h"

// inserting a sentence into a trie
void BookInfo::insert(string line){
	TrieNode* curr = root;
	for(int i=0; i<line.length(); i++){
		if(curr->children.count(line[i]) == 0)
			curr->children[line[i]] = new TrieNode();
		curr = curr->children[line[i]];
	}
	curr->endSentence = true;
}

// autoCompleteHelper looks for all possible solutions for a prefix
void autoCompleteHelper(TrieNode* node, string startOfSentence, vector<string> &ans, string &curr){
	if(node->endSentence) {
		ans.push_back(startOfSentence + curr);
	}
	
	if(node->children.size() == 0) return;
	
	for(auto child : node->children){
		curr.push_back(child.first);
		autoCompleteHelper(child.second, startOfSentence, ans, curr);
		curr.pop_back();
	}
}

// autoCompleteSentence checks if the prefix of the word exists
// if it does it looks for all possible options
vector<string> BookInfo::getAutocompleteSentence(string startOfSentence){
	vector<string> ans;
	string prefix = "";
	TrieNode* curr = root;
	
	startOfSentence = clean(startOfSentence);
	for(int i=0; i<startOfSentence.length(); i++){
		if(curr->children.count(startOfSentence[i]) == 0){
			cout<<startOfSentence[i]<<endl;
			return ans;
		}
		curr = curr->children[startOfSentence[i]];
	}
	autoCompleteHelper(curr, startOfSentence, ans, prefix);
	return ans;
}
