#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "term.h"
#include "SortingList.h"

using namespace std;

//default constructor
Term::Term()
{
	query = " ";
	weight = 0;
}


// initialize with the given query string and weight 
Term::Term(string query, long weight)
{
	this -> query = query;
	this -> weight = weight;
}

// compare two terms in descending order by weight 
// if t1 and t2 are in descending order by weight, return 1 
// if they are of the same weight, return 0;
 // otherwise, return -1 
int Term::compareByWeight(Term t1, Term t2)
{
	if(t2.weight < t1.weight)
		return 1;
	if(t2.weight == t1.weight)
		return 0;
	else
		return -1;
}


// compares two terms in lexicographic order but using only 
// the first r characters of each query
// if the first r characters of t1 and t2 are in lexicographic order, return 1 
// if they are of the same r characters, return 0; 
// otherwise, return -1

int Term::compareByPrefix(Term T1, Term T2, int r)
{
	// cout << T2.query << endl;
	string tp1 = T1.query.substr(0,r);
	string tp2 = T2.query.substr(0,r);

	if(tp1 < tp2)

	return 1;
	if(tp1 == tp2)
	return 0;
	else
	return -1;
}

// define the operator “<” for Term class (as friend function)
bool operator<(Term T1, Term T2)
{
	if(T1.query < T2.query)
		return true;
	else
		return false;
}

// define the operator “<<” for Term class (as friend function) 
// so that it can send the Term object directly to cout, in the following format:
// the weight followed by a tab key, then followed by the query
ostream& operator<<(ostream &out, const Term& t)
{
	out << t.weight << "\t" << t.query;	
	return out;
}

