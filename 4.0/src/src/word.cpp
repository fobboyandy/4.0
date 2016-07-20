#include "word.h"
#include "wikipedia_functions.h"
using namespace wikipedia_functions;

word::word(unordered_map<string, int> &given_dictionary) : global_dictionary_reference(given_dictionary)
{

}

void word::update_word(bool productive) //update word plus words in definition 
{

}