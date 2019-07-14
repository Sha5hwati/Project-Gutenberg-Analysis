#include "bookInfo.h"

void BookInfo::insert(string line){
	cout<<line<<endl;
	Trie* curr = root;
	for(int i=0; i<line.length(); i++){
		if(curr->children.count(line[i]) == 0)
			curr->children[line[i]] = new Trie();
		curr = curr->children[line[i]];
	}
	curr->endSentence = true;
}

void autoCompleteHelper(Trie* node, string startOfSentence, vector<string> &ans, string &curr){
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

vector<string> BookInfo::getAutocompleteSentence(string startOfSentence){
	vector<string> ans;
	string prefix = "";
	Trie* curr = root;
	
	for(int i=0; i<startOfSentence.length(); i++){
		cout<<"size: "<<curr->children.size()<<endl;
		for(auto x : curr->children)
			cout<<x.first<<' ';
		cout<<endl;
		if(curr->children.count(startOfSentence[i]) == 0){
			cout<<startOfSentence[i]<<endl;
			return ans;
		}
		curr = curr->children[startOfSentence[i]];
	}
	cout<<"ok"<<endl;
	autoCompleteHelper(curr, startOfSentence, ans, prefix);
	return ans;
}
