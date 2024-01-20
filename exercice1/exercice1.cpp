#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> splitSentence(string);
string longestWord(vector<string>);
string shortestWord(vector<string>);
double averageLength(vector<string>);

int main() {
    string sentence; 
    cout << "Saisissez une phrase: ";
    getline(cin, sentence);
    vector<string> sentenceWords=  splitSentence(sentence);  
    string shortest = shortestWord(sentenceWords);
    string longest = longestWord(sentenceWords);
    double average =  averageLength(sentenceWords);
    cout << "Le mot le plus court est : " << shortest << endl;
    cout << "Le mot le plus long est : " << longest << endl;
    cout << "La longueur moyenne est : " << average << " lettres";
}

vector<string> splitSentence(string phrase) {
    string word;
    vector <string> sentenceWords;
    for (char letter : phrase) {
        if (letter != ' ') {
            word += letter;
        }
        else {
            sentenceWords.push_back(word);
            word.clear();
        }
    }
    sentenceWords.push_back(word);
    return sentenceWords;
}

string shortestWord(vector<string>listWords) {
    int length = listWords[1].length();
    string shortest = " ";
    for (auto word : listWords) {
        if (word.length() < length) {
            length = word.length();
            shortest = word;
        }
    }
    return shortest;
}

string longestWord(vector<string> listWords) {
    int length = 0;
    string longest = " ";
    for (auto word : listWords) {
        if (word.length() > length) {
            length = word.length();
            longest = word;
        }
    }
    return longest;
}

double averageLength(vector<string> listWords) {
    double average = 0.0;
    for (auto word : listWords) {
        average += word.length();
    }
    average = average / size(listWords);
    return average;
}

