#include "bookInfo.h"

int main(){
	BookInfo info;
	info.PrintBook();
	int wordsCount = info.getTotalNumberOfWords();
	cout<<"Total number of words: "<<wordsCount<<endl;
	
	cout<<endl;
	
	int uniqueWordsCount = info.getTotalUniqueWords();
	cout<<"Total number of unique words: "<<uniqueWordsCount<<endl;
	
	cout<<endl;
	
	vector<pair<string, int>> frequentWords = info.get20MostFrequentWords();
	cout<<"20 Most frequent words: "<<endl;
	for(int i=0; i<frequentWords.size(); i++){
		cout<<i+1<<": "<<frequentWords[i].first<<' '<<frequentWords[i].second<<endl;
	}
	
	cout<<endl;
	
	vector<pair<string, int>> interestingfrequentWords = info.get20MostInterestingFrequentWords();
	cout<<"20 Most interesting frequent words: "<<endl;
	for(int i=0; i<interestingfrequentWords.size(); i++){
		cout<<i+1<<": "<<interestingfrequentWords[i].first<<' '<<interestingfrequentWords[i].second<<endl;
	}
	
	cout<<endl;
	
	vector<pair<string, int>> leastfrequentWords = info.get20LeastFrequentWords();
	cout<<"20 Least frequent words: "<<endl;
	for(int i=0; i<leastfrequentWords.size(); i++){
		cout<<i+1<<": "<<leastfrequentWords[i].first<<' '<<leastfrequentWords[i].second<<endl;
	}
}
