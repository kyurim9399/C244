/***********************************************************************
// Name   kyurim kim     Date  2020.01.14     Reason NDD   Student # 168819183
***********************************************************************/

#ifndef SDDS_TOOLS_H
#define SDDS_TOOLS_H

const int MAX_WORD_LEN = 21;
const int MAX_NO_OF_WORDS = 500;


struct Word
{
	char letters[MAX_WORD_LEN];
	int count;
};

namespace sdds
{

	void toLowerCaseAndAlphabeticCopy(char des[], const char source[]);
	int searchWords(const Word words[], int num, const char word[]);
	void addWord(Word words[], int* index, const char newWord[]);
	void title();
	void endList();
	void totalWordsStat(int totNoWrds, int totalOverAll, int longestWord);
	void print(const Word* w, bool gotoNextLine);
	void report(const Word words[], int noOfWords, int longestWord);
	void swap(Word* p1, Word* p2);
	void sort(Word words[], int cnt);
}

#endif
