#include <iostream>
#include <queue>
#include <string>

char alphabetLetter[] = {'A', 'B', 'C', 'D', 'E', 'F'};
std::string alphabetArray[] = {"", "", "", "", "", ""};


struct nodeLeaf {

	char code;
	int frequency;
	nodeLeaf *lChild, *rChild;

    nodeLeaf(char code, int frequency){
        lChild = nullptr;
        rChild = nullptr;
        this->code = code;
        this->frequency = frequency;
	}
};

struct nodeComparison {
	bool operator()(nodeLeaf* lChild, nodeLeaf* rChild){

		return (lChild->frequency > rChild->frequency);

	}
};

void printCodes(struct nodeLeaf* root, std::string word){

    if (!root){
        return;

    } if (root->code == alphabetLetter[0]) {
        alphabetArray[0] = alphabetArray[0] + "A:" + word;

    } else if (root->code == alphabetLetter[1]) {
        alphabetArray[1] = alphabetArray[1] + "B:" + word;

    } else if (root->code == alphabetLetter[2]) {
        alphabetArray[2] = alphabetArray[2] + "C:" + word;

    } else if (root->code == alphabetLetter[3]) {
        alphabetArray[3] = alphabetArray[3] + "D:" + word;

    } else if (root->code == alphabetLetter[4]) {
        alphabetArray[4] = alphabetArray[4] + "E:" + word;

    } else if (root->code == alphabetLetter[5]) {
        alphabetArray[5] = alphabetArray[5] + "F:" + word;

    }

   /*
    if (root != NULL){
    for (int i; i < 6; i++){
        root->code = alphabetLetter[i];
        alphabetArray[i] += "A:" + word;
        return;
        }
    }*/

    printCodes(root->lChild, word + "0");
	printCodes(root->rChild, word + "1");
    }



void HuffmanCodes(char code[], int frequency[], int length){

	struct nodeLeaf *lChild, *rChild, *root;

	std::priority_queue<nodeLeaf*, std::vector<nodeLeaf*>, nodeComparison> nodeHeap;

	for (int i = 0; i < length; ++i){
		nodeHeap.push(new nodeLeaf(code[i], frequency[i]));
	}

	while (nodeHeap.size() > 1) {

		lChild = nodeHeap.top();
		nodeHeap.pop();
		rChild = nodeHeap.top();
		nodeHeap.pop();

		root = new nodeLeaf('$', lChild->frequency + rChild->frequency);
		root->lChild = lChild;
        root->rChild = rChild;
		nodeHeap.push(root);
	}

    printCodes(nodeHeap.top(), "");

}

void printHuffmanTree(int length){

    for (int j = 0; j < length; j++) {
    std::cout << alphabetArray[j] << std::endl;
    }
}

int main() {

	int length = 6;
    int frequency[length];

	for (int i = 0; i < length; i++){

		std::cin>>frequency[i];
	}

	HuffmanCodes(alphabetLetter, frequency, length);
    printHuffmanTree(length);
	return 0;
}
