#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;

const int MAX = 20;

struct Quiz {

	string questions;
	char key;
	char responses;

};

void openInputFile(ifstream& input, const string& message);
int fillQuestions(Quiz qz[], ifstream& in);
int fillAnswerKey(Quiz qz[], ifstream& inA);
void fillResponses(Quiz qz[], int len);
int gradeResponses(const Quiz qz[], int len);
void printAnswersAndResponses(const Quiz qz[], int len);

int main() {

	Quiz qz[20];
	ifstream in;
	int score, arrLenA, arrLenQ, numWrong;
	double scorePerc;

	cout << "Welcome to the driving test. Good Luck!\n";

	openInputFile(in, "questions");
	arrLenQ = fillQuestions(qz, in);
	in.close();

	openInputFile(in, "answers");
	arrLenA = fillAnswerKey(qz, in);
	in.close();

	fillResponses(qz, arrLenQ);
	score = gradeResponses(qz, arrLenA);
	
	cout << "You got " << score << " out of 20.\n";
	scorePerc = score / 20;

	if (scorePerc > 0.80) {

		cout << "You passed. Good job!\n";

	}
	else {

		cout << "You failed. Please try again.\n";

	}
	
	numWrong = 20 - score;
	cout << "Total correct: " << score << "\n";
	cout << "Total wrong: " << numWrong << "\n";
	printAnswersAndResponses(qz, arrLenQ);

}

void openInputFile(ifstream& input, const string& message) {

	bool done = false;
	string In_File = "";		//C:\Users\timbi\Desktop\tmbm\school\Elco\CS1\Questions.txt
								//C:\Users\timbi\Desktop\tmbm\school\Elco\CS1\AnswerKey.txt
	while (!done) {
		input.clear(); cout << "Please input the name of the data file with " << message << " to be read : ";
		getline(cin, In_File); cout << "The file name entered is : " << In_File << endl; input.open(In_File);

		if (input.fail()) {
			cout << "The file " << In_File << " does not exist.\n";
			continue;
		}
		else {
			input.peek();
			if (input.eof()) {
				cout << "The file has no data in it\n";
				input.close();
				continue;
			}
			else {
				done = true;
			}
		}
	}
	cout << "File " << In_File << " opened and has data in it." << endl;

}

int fillQuestions(Quiz qz[], ifstream& in) {

	int arrLength = 0;
	while (in.peek() != EOF && arrLength < MAX) {

		getline(in, qz[arrLength].questions, '$');	
		arrLength++;

	}

	return arrLength;

}

int fillAnswerKey(Quiz qz[], ifstream& inA) {

	int arrLength = 0;
	while (inA.peek() != EOF && arrLength < MAX) {

		inA >> qz[arrLength].key;
		arrLength++;

	}

	return arrLength;

}

void fillResponses(Quiz qz[], int len) {
	cout << "\n---------------------------------------------------------------------------\n";
	cout << "The test is now beginning. It will be multiple choice." 
		 << "Please enter A, B, C, or D for your answers.\n";

	for (int i = 0; i < len; i++) {

		cout << qz[i].questions << "\n";
		cout << "Please type your answer.\n";
		cin >> qz[i].responses;
	
	}

}

int gradeResponses(const Quiz qz[], int len) {

	int numCorrect = 0;
	for (int i = 0; i < len; i++) {
	
		if (qz[i].key == qz[i].responses) {

			numCorrect++;

		}

	}

	return numCorrect;

}

void printAnswersAndResponses(const Quiz qz[], int len) {

	cout << "---------------------------------------------------------------------------\n";
	cout << "We will now give a summary of the questions, answers, and your responses.\n";

	for (int i = 0; i < len; i++) {

		cout << qz[i].questions << "\n";
		cout << "The correct answer is " << qz[i].key << ".\n";
		cout << "You answered " << qz[i].responses << ".\n";

		if (qz[i].key == qz[i].responses) {
			cout << "You got this question right.\n";
		}
		else {
			cout << "You got this question wrong.\n";
		}

		cout << "Press ENTER to continue.\n";
		cin.get();

	}

}