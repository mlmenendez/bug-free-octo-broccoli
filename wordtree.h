#ifndef _WORDTREE_H_
#define _WORDTREE_H_
#include <string>
#include <fstream>
#include <iostream>
#include <locale>
#include <vector>

struct WordNode {
	WordNode* left = nullptr;
	WordNode* right = nullptr;
	std::string info="";
	int count = 0;
};

class WordTree {
public:
	WordTree();
	~WordTree();
	int CountNodes();
	void AddNode(std::string);
	void readIn(std::ifstream&);
	friend void print(WordNode*&);
	int wordcount = 0;
	int dnodes = 0;
	friend std::ostream& operator<< (std::ostream &, const WordTree &);
private:
	WordNode* root;
	int NodeCount(WordNode*&);
	void NodeAdd(WordNode*&, std::string);
	void burnTree(WordNode*&);
};

#endif