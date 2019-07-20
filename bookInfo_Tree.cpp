#include "bookInfo.h"

// getChapterHelper does a dfs on the book to check if the sentence
// considered as path exits in a given chapter
int BookInfo::getChapterHelper(vector<string> &words, int curr, int chap){
	if(curr == words.size()) return chap;
	if(book.count(words[curr]) == 0) return -1;
	if(book[words[curr-1]]->adjacent.count(words[curr]) == 0) return -1;
	if(book[words[curr-1]]->adjacent[words[curr]].count(chap) == 0) return -1;
	
	return getChapterHelper(words, curr+1, chap);
}

// presentInChapter is a helper function that does a dfs on the
// book to find the chapters in which the word is present
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
				if(adj.first == word){
					for(auto s : adj.second) chapters.insert(s.first);
				}
				if(visited.count(adj.first) == 0){
					stk.push(adj.first);
				}
			}
		}
	}
	return chapters;
}

// getChapterQuoteAppears returns the chapter number in
// which the quote appears. If the quote is not found then
// it returns -1
int BookInfo::getChapterQuoteAppears(string sentence){
	vector<string> words;
	stringstream ss(sentence);
	while(ss >> sentence){
		words.push_back(clean(sentence));
	}
	
	if(book.count(words[0]) == 0) return -1;
	
	unordered_set<int> getChapters = presentInChapters(words[0]);
	for(auto c : getChapters){
		int val = getChapterHelper(words, 1, c);
		if(val != -1) return val;
	}
	return -1;
}

vector<int> BookInfo::getFrequencyOfWord(string word){
	word = clean(word);
	vector<int> frequency(totalChapters, 0);
	
	cout<<word<<endl;
	unordered_set<string> visited;
	unordered_set<string> present;
	stack<string> stk;
	for(auto w : book){
		if(visited.count(w.first) != 0) continue;
		
		stk.push(w.first);
		while(!stk.empty()){
			string top = stk.top();
			stk.pop();
			visited.insert(top);
			for(auto adj : book[top]->adjacent){		
				if(adj.first == word && present.count(top) ==0){
						cout<<top<<' ';
						for(auto s : adj.second) frequency[s.first-1]+=s.second;	
						present.insert(top);
				}		
				if(visited.count(adj.first) == 0){
					stk.push(adj.first);
				}
			}
		}
	}
	cout<<endl;
	cout<<"actual: "<<book[word]->count<<endl;
	int total = 0;
	for(auto c:frequency) total+=c;
	cout<<"got: "<<total<<endl;
	return frequency;
}

// generateSentence generates a sentence keeping in
// mind the style of the author. To do so, it takes
// into account the frequency and does a weighted
// random selection (roulette selection) to pick the
// next sentence. The produced sentence is 20 words long
// and does not take into account the punctuations
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



