#include "word.h"
#include "wikipedia_functions.h"
using namespace wikipedia_functions;

word::word(unordered_map<string, int> &given_dictionary, string spelling) : global_dictionary_reference(given_dictionary), weight(0)
{
	if (definition.empty())//word not defined yet
		definition = wikipedia_functions::word_sort(scrape(spelling));
}

void word::update_word(bool productive) //update word plus words in definition 
{

}