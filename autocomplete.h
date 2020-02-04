/* file: autocomplete.h
* Course: CS216-008
* Project: Project 3
* Purpose: the declaration for the Autocomplete class
*
*/

#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include <string>
#include "term.h"
#include "SortingList.h"
using namespace std;

class Autocomplete
{
	 public:
	  // insert the newterm to the sequence
	  void insert(Term newterm);

	   // return all terms whose queries match the given prefix,
	   // in descending order by weight

	  SortingList<Term> allMatches(string prefix);

	   // first: the index of the first query whose prefix matches 
	   //        the search key, or -1 if no such key
	   // last: the index of the last query whose prefix matches 
	   //       the search key, or -1 if no such key
	   // key: the given prefix to match 
	   void search(string key, int& first, int& last);

	   // return the index number of the term whose query 
	   // prefix-matches the given prefix, using binary search algorithm 
	   // Note that binary search can only be applied to sorted sequence
	   // Note that you may want a binary search helper function
	   int binary_search(string prefix);
	   // display all the terms
	   void print();
		
	   void sort_a();
	   // other member functions you need…
		
	 private:
	 	// choose your own data structure to represent the sequence of Term objects
		SortingList<Term> terms;
};

#endif
