/*
 * Course: CS216-00x
 * Project: Project 3
 * Purpose: To create a autocomplete program to find out what the user is typing or going to type
 *Author: Ruth Dankwah
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "term.h"
#include "SortingList.h"
#include "autocomplete.h"


using namespace std;

int main(int argc, char** argv) {
    const int ARGUMENTS = 3;
   	
	int k;
    // check the command line argument, an input file name is needed
    if (argc != ARGUMENTS)
    {
        cout << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }    

	k = atoi(argv[2]);
	if(k < 1)
	{
		cout << "The number of matching terms needs to be a positive number";
		return 2;
	}
    
    // check if the input file can be opened successfully
    ifstream infile;
    infile.open(argv[1]);
    if (!infile.good())
    {
        cout << "Cannot open the file named " << argv[1] << endl;
        return 3;
    }  
    
    // read in the terms from the input file
    // line by line and store into SortingList object
//    SortingList<Term> dataList;
    SortingList<Term> a;
    long weight;
    string query;
    
    while (infile >> weight)
    {
		
        infile >> ws;
        getline(infile, query);
        if (query != "")
        {    
            Term newterm(query, weight);
            //dataList.insert(newterm);
            a.insert(newterm);
        }    
    } 

    // close the file stream
    infile.close();

    string prefix;
	// Ask the user to put what they want to search
    cout << "Please input the search query(type \"exit\" to quit): " << endl;
    getline(cin, prefix);
    
	//while what the user entered in is not exit, search through the prefixes
    while (prefix != "exit")
    {	a.sort();
		 Autocomplete b;
		 for(int i = 0; i < a.size(); i ++)
		 {	b.insert(a[i]);
		 }
		SortingList <Term> S = b.allMatches(prefix);
		if(S.size() == 0)
			//if there is not a match let the user know
			cout <<"No matched query!" <<endl;
		else
		{
			if(k < S.size())
			{
				for(int i = 0; i < k; i++)
					cout << S[i] << endl;
			}
			else
			{
				for(int i = 0; i < S.size(); i++)
					cout <<S[i] <<endl;
			}
		}

        //ask the user to type what they are looking for again
        cout << "Please input the search query(type \"exit\" to quit): " << endl;
        getline(cin, prefix);
		

    }    
    return 0;
}

