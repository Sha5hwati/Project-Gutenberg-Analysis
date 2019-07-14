#include "bookInfo.h"

int BookInfo::getChapterHelper(vector<string> &words, int curr, int chap){
	if(curr == words.size()) return chap;
	if(book.count(words[curr]) == 0) return -1;
	if(book[words[curr-1]]->adjacent.count(words[curr]) == 0) return -1;
	if(book[words[curr-1]]->adjacent[words[curr]].count(chap) == 0) return -1;
	
	return getChapterHelper(words, curr+1, chap);
}

unordered_set<int> BookInfo::presentInChapters(string word){
	unordered_set<int> chapters;
	unordered_set<string> visited;
	stack<string> stk;
	
	for(auto w : book){
		if(visited.count(w.first) != 0) continue;
		
		stk.push(w.first);
		while(!stk.empty()){
			string top = stk.top();
			stk.pop();
			visited.insert(top);
			for(auto adj : book[top]->adjacent){
				if(visited.count(adj.first) == 0){
					if(adj.first == word){
						for(auto s : adj.second) chapters.insert(s);
					}
					stk.push(adj.first);
				}
			}
		}
	}
	return chapters;
}

int BookInfo::getChapterQuoteAppears(string sentence){
	vector<string> words;
	stringstream ss(sentence);
	while(ss >> sentence){
		words.push_back(Clean(sentence));
	}
	
	if(book.count(words[0]) == 0) return -1;
	
	unordered_set<int> getChapters = presentInChapters(words[0]);
	
	for(auto c : getChapters){
		int val = getChapterHelper(words, 1, c);
		if(val != -1) return val;
	}
	return -1;
}

/*vector<int> BookInfo::getFrequencyOfWord(string word){
	vector<int> frequency(totalChapters, 0);
	
	unordered_set<string> visited;
	stack<string> stk;
	for(auto w : book){
		if(visited.count(w.first) != 0) continue;
		
		stk.push(w.first);
		while(!stk.empty()){
			string top = stk.top();
			stk.pop();
			visited.insert(top);
			for(auto adj : book[top]->adjacent){
				if(adj.first == word){
					for(auto s : adj.second) frequency[s-1]++;
				}
				if(visited.count(adj.first) == 0){
					stk.push(adj.first);
				}
			}
		}
	}
	
	cout<<"actual: "<<book["it"]->count<<endl;
	return frequency;
}*/

string BookInfo::generateSentence(){
	string sentence = "";
	string curr = "the";
	int count = 0;
	
	while(count != 20){
		sentence += curr + " ";
		double total = 0;
		for(auto adj : book[curr]->adjacent){
			total += book[adj.first]->count;
		}
		
		double val =  (double)rand() / ((double)RAND_MAX + 1);

		auto it = book[curr]->adjacent.begin();
		while(val > 0 && it != book[curr]->adjacent.end()){
			val -= (book[it->first]->count)/total;
			curr = it->first;
			it++;
		}
	    
	    count++;
	}
	return sentence;
}



