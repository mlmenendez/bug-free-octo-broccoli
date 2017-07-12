#include "wordtree.h"

WordTree::WordTree() {
	root = nullptr;
}

WordTree::~WordTree() {
	burnTree(root->left);
	burnTree(root->right);
	delete root;
}

void WordTree::burnTree(WordNode* &node) {
	if (node->left != nullptr) {
		burnTree(node->left);
	}
	if (node->right != nullptr) {
		burnTree(node->right);
	}
	delete node;
}

int WordTree::CountNodes() {
	return NodeCount(root);
}

int WordTree::NodeCount(WordNode* &wt) {
	if (wt == nullptr) {
		return 0;
	}
	else {
		return NodeCount(wt->left) + 1 + NodeCount(wt->right);
	}
}

void WordTree::NodeAdd(WordNode* &wt, std::string val) {
	if (wt == nullptr) {
		wt = new WordNode;
		wt->right = nullptr;
		wt->left = nullptr;
		wt->info = val;
		wt->count++;
		return;
	}

	if (val < wt->info) {
			NodeAdd(wt->left, val);
	}

	if (val > wt->info) {
		NodeAdd(wt->right, val);
	}
	if (val == wt->info) {
		wt->count++;
		return;
	}
}

void WordTree::AddNode(std::string input) {
	//std::cout << "Enter a value to add to the tree " << std::endl;
	//std::cin >> input;
	NodeAdd(root, input);
}

std::ostream& operator<< (std::ostream &out, const WordTree &wt)
{
	print(wt.root->right);
	print(wt.root->left);
	//out << "The word is: " << wt.root->info << " " << "it occurs: " << " number of times. " << std::endl;

	return out;
}

void print(WordNode* &node) {
	if (node->left == nullptr&&node->right == nullptr) {
		std::cout << "The word is: " << node->info <<  " the amount of occurance is: " << node->count << std::endl;
		return;
	}
	//if (node == nullptr) {
	//	return;
	//}
	if (node->left != nullptr) {
		print(node->left);
	}
	if (node->right != nullptr) {
		print(node->right);
	}
	//if (node != nullptr) {
	//	std::cout << "The word is: " << node->info << " the amount of occurance is: " << node->count << std::endl;
	//	return;
	//}
}

void WordTree::readIn(std::ifstream &filename) {
	std::string info;
	char temp;
	while (!filename.eof()) {
		temp = filename.get();
		//if (temp != ',' && temp!= '.' && temp != ';' && temp!= '-' &&temp != '?' &&temp!='!' && temp!=' ' && temp!= '\n' && temp!= '"' && temp!= '('
		//	& temp!= ')' && temp != '[' && temp !=']') {
		if (isalpha(temp)){
			temp = toupper(temp);
			info.push_back(temp);
		}
		if (temp == ' ' || temp == '-') {
			if (info.size() >= 1 ) {
				AddNode(info);
				wordcount++;
				info.erase();
			}
		}
	}
}