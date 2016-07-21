#pragma once
#include <string>
#include <unordered_map>
using namespace std;

class word
{
public:
	word(unordered_map<string, int> &given_dictionary, string spelling);
	void update_word(bool productive); //update word plus words in definition 
private:
	unordered_map<string, int> definition; //frequency list from wikipedia
	unordered_map<string, int> &global_dictionary_reference; //list of words trained from past
	float weight;
};