#include <string>
#include <fstream>
#include <iostream>
using namespace std;

const int MAX = 19;		//constant value for array length

void openFile(ifstream& input, const string& message);
int fillQuestionsArray(string questions[], ifstream& in);
int fillAnswerKeyArray(char ans[], ifstream& in);
int fillResponseArray(const string questions[], char response[], int len);
int gradeResponses(const char answers[], const char response[], int len);
void printAnswersAndResponses(const string questions[], const char answers[],
							  const char response[], int len);

int main() {

	int arrLenQ, arrLenA;
	ifstream in;
	string questions[MAX];
	char answers[MAX], response[MAX];
	int score = 0;

	cout << "Welcome to the Driving Test. Good Luck!" << endl;

	openFile(in, "questions");
	arrLenQ = fillQuestionsArray(questions, in);
	in.close();

	openFile(in, "answers");
	arrLenA = fillAnswerKeyArray(answers, in);
	in.close();

	if (arrLenQ != arrLenA) {

		cout << "Length of questions and answers are different.";

	}
	else {
		fillResponseArray(questions, response, arrLenQ);

		score = gradeResponses(answers, response, arrLenA);

		printAnswersAndResponses(questions, answers, response, arrLenA);
	}

}

void openFile(ifstream& input, const string& message) {

	bool done = false; 
	string In_File = "";
	while (!done){
		input.clear();cout << "Please input the name of the data file with " << message << " to be read : ";
		getline(cin, In_File);cout << "The file name entered is : " << In_File << endl;input.open(In_File);

		if (input.fail()){
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

int fillQuestionsArray(string questions[], ifstream& in) {

	int i = 0;

	while (in.peek() && i < MAX) {
		getline(in, questions[i], '$');
		i++;
	}

	return i;

}

int fillAnswerKeyArray(char ans[], ifstream& in) {

	int i = 0;

	while (in.peek() && i < MAX) {
		in >> ans[i];
		i++;
	}

	return i;

}

int fillResponseArray(const string questions[], char response[], int len) {

	int len;

	for (len = 0; len < MAX; len++) {

		cout << questions[len];
		cout << "Please type your answer." << endl;
		cin >> response[len];

	}

	return len;

}

int gradeResponses(const char answers[], const char response[], int len) {

	int numCorrect = 0;
	for (int index = 0; index < len; index++) {
		if (answers[index] == response[index]) {
			numCorrect++;
		}

	}

	return numCorrect;
}

void printAnswersAndResponses(const string questions[], const char answers[], const char response[], int len) {

	for (int index = 0; index < len; index++) {
		cout << questions[index] << endl;
		cout << "The correct answer is: " << answers[index] << endl;
		cout << "You answered: " << response[index] << endl;
	}

}