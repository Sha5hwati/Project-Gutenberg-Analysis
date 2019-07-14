#include "bookInfo.h"

int main(){
	BookInfo info;
	//info.PrintBook();
	/*int wordsCount = info.getTotalNumberOfWords();
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
	
	int present = info.getChapterQuoteAppears("In this house they were received by Miss Darcy, who was sitting there with Mrs. Hurst and Miss Bingley, and the lady with whom she lived in London. Georgiana's reception of them was very civil, but attended with all the embarrassment which, though proceeding from shyness and the fear of doing wrong, would easily give to those who felt themselves inferior the belief of her being proud and reserved. Mrs. Gardiner and her niece, however, did her justice, and pitied her.");
	cout<<"long sentence: "<< present<<endl;
	
	present = info.getChapterQuoteAppears("young man of large fortune");
	cout<<"young man of large fortune: "<<present<<endl;
	
	vector<int> freq = info.getFrequencyOfWord("it");
	cout<<"it: ";
	int t = 0;
	for(auto c : freq) { cout<<c<<' '; t+=c; }
	cout<<endl;
	cout<<t<<' '<<endl;
	cout<<endl;
	cout<<info.generateSentence()<<endl;
	cout<<info.generateSentence()<<endl;
	cout<<info.generateSentence()<<endl;
	cout<<info.generateSentence()<<endl;*/
	
	vector<string> autoComp = info.getAutocompleteSentence(" Mary was obliged to mix more with the world, but she could still moralize over every morning visit;");
	cout<<"auto-complete: "<<endl;
	for(auto c : autoComp){
		cout<<c<<endl;
	}
}
