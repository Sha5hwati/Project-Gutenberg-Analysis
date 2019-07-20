#include "bookInfo.h"

int main(){
	ofstream ofile("analysis.txt");
	if(!ofile){
		ofile<<"analysis.pdf did not open"<<endl;
		return -1;
	}
	
	BookInfo info;
	
	int chapters = info.getTotalChapters();
	ofile<<"Total number of chapters: "<<chapters<<endl;
	
	ofile<<endl;
	
	int wordsCount = info.getTotalNumberOfWords();
	ofile<<"Total number of words: "<<wordsCount<<endl;
	
	ofile<<endl;
	
	int uniqueWordsCount = info.getTotalUniqueWords();
	ofile<<"Total number of unique words: "<<uniqueWordsCount<<endl;
	
	ofile<<endl;
	
	vector<pair<string, int>> frequentWords = info.get20MostFrequentWords();
	ofile<<"20 Most frequent words: "<<endl;
	for(int i=0; i<frequentWords.size(); i++){
		ofile<<i+1<<": "<<frequentWords[i].first<<' '
			<<frequentWords[i].second<<endl;
	}
	
	ofile<<endl;
	
	vector<pair<string, int>> interestingfrequentWords = info.get20MostInterestingFrequentWords();
	ofile<<"20 Most interesting frequent words: "<<endl;
	for(int i=0; i<interestingfrequentWords.size(); i++){
		ofile<<i+1<<": "<<interestingfrequentWords[i].first<<' '
			<<interestingfrequentWords[i].second<<endl;
	}
	
	ofile<<endl;
	
	vector<pair<string, int>> leastfrequentWords = info.get20LeastFrequentWords();
	ofile<<"20 Least frequent words: "<<endl;
	for(int i=0; i<leastfrequentWords.size(); i++){
		ofile<<i+1<<": "<<leastfrequentWords[i].first<<' '<<leastfrequentWords[i].second<<endl;
	}
	
	ofile<<endl;
	
	ofile<<"Find the quote: \n";
	string quotes[] = {"Angry people are not always wise.", "There is a stubbornness about me that never can bear to be frightened at the will of others. My courage always rises at every attempt to intimidate me", "You are too generous to trifle with me. If your feelings are still what they were last April, tell me so at once. My affections and wishes are unchanged, but one word from you will silence me on this subject for ever.", "Completely and perfectly and incandescently happy", "Find me a sentence that does not exist Jane Austen"};
	for(int i=0; i<5; i++){
		int present = info.getChapterQuoteAppears(quotes[i]);
		ofile<<"\""<<quotes[i]<<"\""<<endl;
		if(present != -1)
			ofile<<"Quote found in Chapter "<< present<<endl;
		else 
			ofile<<"Quote not found"<<endl;
		ofile<<endl;
	}
	
	/*string word[] = {"Darcy", "Elizabeth", "Lizzy", "love", "pride", "prejudice"};
	for(int i=0; i<6; i++){
		vector<int> freq = info.getFrequencyOfWord(word[i]);
		ofile<<"The frequency distribution of the word \""<<word[i]<<"\""<<endl;
		for(auto c : freq) ofile<<c<<' '; 
		ofile<<endl<<endl;
	}*/
	
	ofile<<"Generating sentences in authors style"<<endl;
	for(int i=0; i<3; i++){
		ofile<<info.generateSentence()<<endl<<endl;
	}
	
	string complete[] = {"Laugh as", "I wish, as well as"};
	for(int i=0; i<2; i++){
		vector<string> sentences = info.getAutocompleteSentence(complete[i]);
		ofile<<"auto-complete: \n\""<<complete[i]<<"\"..."<<endl;
		for(auto sentence : sentences){
				ofile<<sentence<<endl;
		}
	}
	
	return 0;
}
