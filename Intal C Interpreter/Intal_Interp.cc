//*************************************************************
// File: Intal_Interp.cc
//
// Author: Doug Morgan
// Email: dm303102@ohiou.edu
//
// Description: The Intal_Interp.cc program reads and interprets
// commands from the low-level language Intal. Commands include
// ADDR var addr, SET var val, INCR var, DECR var, ADD || SUB
// || MULT || DIV on var var and PRINT var. The program takes
// one command line parameter that is a flag to determine the
// STL algorithm to use in implementing the sybmol_table for the
// Intal interpreter. These inlude -h(hash_map), -m(map) and
// -l(list). The interpreter accepts multiple bindings by using
// another multimap structure to map an address
// (range: 0-50,000) to a set of variable strings. These strings
// are referenced and updated every time a variable with the same
// address is updated. The STL data structures implementing the
// table are composed of string key to represent variables and
// a struct defined below called binding as the data which holds
// an integer address and an integer value.
// Date: 11-15-05
//*************************************************************
#include<iostream>
#include<string>
#include<cctype>
#include<ext/hash_map>
#include<map>
#include<list>
#include<utility>

using namespace std;

#define sgi __gnu_cxx
#define MEM 50,000

struct binding
{
    size_t address;  //memory adress within range of MEM
    int value;  
};

//*************************************************************
// Function: Error(const string& msg)
//
// Purpose: prints msg to the standard error stream and exits
// the program
//
// Parameters: const string& msg
//
// Member/Global variables: none
//
// Preconditions: none
//
// Postconditions: msg is sent to cerr and exit(1) is called
//
//*************************************************************
void Error(const string& msg);

//*************************************************************
// Function: int eat_space(string s1, size_t i)
//
// Purpose: Returns an index in s1 to the first character
// starting at s1[i] that is not a space character; returns
// -1 if not found
//
// Parameters: string s1, size_t i
//
// Member/Global variables: 
//
// Preconditions: none
//
// Postconditions: If a character was found starting  s[i] that
// was not a space character, then its index is returned.
// Otherwise, -1 is returnd
//
//*************************************************************
int eat_space(string s1, size_t i);


//*************************************************************
// Function: bool get_args(string& arg1, string& arg2,
//                         const string input, int start_char)
//
// Purpose: Returns arguments for an Intal Command of the form:
// Command(string) arg1 agr2
//
// Parameters: string& arg1, string& arg2, const string input
//             int start_char
//
// Member/Global variables: none
//
// Preconditions: Assume start_char is an index to a char value
// in input
//
// Postconditions: If arg1 and arg2 are read as substrings from
// input, then true is returned. othewise, false is returned
//*************************************************************
bool get_args(string& arg1, string& arg2, const string input, int start_char);


//*************************************************************
// Function: get_arg(string& arg1, const string input, int start_char)
//
// Purpose: Returns arguments for an Intal Command of the form:
// Command(string) arg1
//
// Parameters: string& arg1, const string input, int start_char
//
// Member/Global variables: none
//
// Preconditions: 
//
// Postconditions: If start_char is not the size of input, then
// arg1 is set to all characers after and including input[start_char]
// and true is returned. Otherwiaw false is returned
//
//*************************************************************
bool get_arg(string& arg1, const string input, int start_char);


//*************************************************************
// Function: string_to_int(const string& s1)
//
// Purpose: converts a string to an integer
//
// Parameters: const string& s1
//
// Member/Global variables: none
//
// Preconditions: s1 is a string of digits
//
// Postconditions: the integer value of the number string s1
// is returned
//*************************************************************
int string_to_int(const string& s1);


//*************************************************************
// Function: find(list<pair<string, binding> > l, const string& target)
//
// Purpose: finds a spot in a linked list of pairs of strings
// and bindings whose string is equal to target
//
// Parameters: list<pair<string, binding> > l, const string& target
//
// Member/Global variables: none
//
// Preconditions: none
//
// Postconditions: If a list object was found with it string equal
// to target, then an itrerator to that object is returned;
// Otherwise NULL is returned
//*************************************************************
list<pair<string, binding> >::iterator find(list<pair<string, binding> > l, const string& target);

struct hash_func
{
    size_t operator ()(const string &x) const
	{
	    size_t sum = 0;
	    for(int i = 0; i < x.length(); i++)
		sum += x[i];
	    return sum;
	}
};
	    
int
main(int argc, char* argv[])
{
    multimap<int, string> address_table;  //maps an address to multiple strings
    multimap<int, string>::iterator addr_itr;  
    sgi::hash_map<string, binding, hash_func> t_hmap;
    sgi::hash_map<string, binding, hash_func>::iterator h_itr1;
    sgi::hash_map<string, binding, hash_func>::iterator h_itr2;
    map<string, binding> t_map;
    map<string, binding>::iterator m_itr1;
    map<string, binding>::iterator m_itr2;
    list<pair<string, binding> > t_list;
    list<pair<string, binding> >::iterator l_itr1;
    list<pair<string, binding> >::iterator l_itr2;
    string input_s;  //current intal input
    string com_str;  //current intal input command
    string arg1, arg2;  //possible current intal command arguments
    char method;  //flag used to determine the STL data structure
    //to use to impLement a hash table
    
    int start = -1;  //index in input of the start of a substring
    int space_ind = -1;  //index of the first space after a substring
        
    //Strip out hash table method flag
    if(argc != 2 || argv[1][0] != '-' || argv[1][1] == '\0')
    {
	cerr<<"Invalid command line arguments\n";
	exit(1);
    }
    else
	method = argv[1][1];

    
    //SYNTAX INTERPRETER
    while(!cin.eof())
    {
	cout<<">";
	getline(cin, input_s);

	//GET COMMAND FROM INPUT LINE
	start = eat_space(input_s, 0);

	if(start == -1)  //empty input
	    break;
	    
	//finds position of space after intal command
	for(int i = start; i < input_s.length() && space_ind == -1; i++)
	{
	    if(isspace(input_s[i]))
		space_ind = i;
	}

	//Error check arguments
	if(space_ind != -1)  //no args
	{
	  com_str = input_s.substr(start, space_ind-start);    
	   
	  //finds position of first character of arguments
	  start = eat_space(input_s, space_ind);
	}
	
	//Error check args
	if(start == -1)
	    Error("Intal syntax error: invalid number of args\n");
	

        //INTERPRETER CASES	
	if(com_str == "ADDR")
	{
	    int address;  
	    binding b;  //binding to arg1 consisting of <address, arg2>
	    
	    get_args(arg1, arg2, input_s, start);       
	    address = string_to_int(arg2);
	    b.address = address;
	    
	    if(address < 0 || address > MEM)
		Error("Invalid address range " + arg2);

	    address_table.insert(multimap<int, string>::value_type(address, arg1));	

	    if(method == 'h')
		t_hmap[arg1] = b;
	    else if(method == 'm')
		t_map[arg1] = b;
	    else if(method == 'l')
		t_list.push_front(make_pair(arg1, b));
	    else
		Error("Invalid command line flag " + method);
	}
	else if(com_str == "SET")
	{
	    int val;  //integer value of arg2
	    int i;  //iterator
	    int count;  //count of strings in address table associated with a given address
	    
	    get_args(arg1, arg2, input_s, start);
	    val = string_to_int(arg2);
	    
	    if(method == 'h')
	    {
		h_itr1 = t_hmap.find(arg1);  //find data for arg1 key

		if(h_itr1 != t_hmap.end())
		{
                    h_itr1->second.value = val;  //set new value
                    addr_itr = address_table.find(h_itr1->second.address);    

		    for(i=0;i<address_table.count(h_itr1->second.address);i++)
		    {		     
			h_itr2 = t_hmap.find(addr_itr->second);
			h_itr2->second.value = val;
			++addr_itr;
		    }
		}
		else
		    Error("Intal Error: SET referenced a non-existant binding\n");
	    }
	    else if(method == 'm')
	    {
		m_itr1 = t_map.find(arg1);

		if(m_itr1 != t_map.end())
		{
		    m_itr1->second.value = val;
		    addr_itr = address_table.find(m_itr1->second.address);    

		    for(i=0;i<address_table.count(m_itr1->second.address);i++)
		    {		     
			m_itr2 = t_map.find(addr_itr->second);
			m_itr2->second.value = val;
			++addr_itr;
		    }
		}
		else
		    Error("Intal Error: SET referenced a non-existant binding\n");
	    }
	    else if(method == 'l')
	    {
		l_itr1 = find(t_list, arg1);

		if(l_itr1 != NULL)
		{
		    count = address_table.count(l_itr1->second.address);
		    l_itr1->second.value = val;
		    addr_itr = address_table.find(l_itr1->second.address);    

	   
		    for(i=0;i<count;++i,++addr_itr)
		    {
			l_itr2 = find(t_list, addr_itr->second);
			(l_itr2->second).value = val;
		    }
		}
		else
		    Error("Intal Error: SET referenced a non-existant binding\n");
	    }
	    else	       
		Error("Invalid command line flag " + method);	    
	}
	else if(com_str == "INCR")
	{
	    get_arg(arg1, input_s, start);

	    if(method == 'h')
	    {
		h_itr1 = t_hmap.find(arg1);

		if(h_itr1 != t_hmap.end())    
		    h_itr1->second.value += 1;
		  
		else
		    Error("Intal Error: INCR referenced a non-existant binding\n");
	    }
	    else if(method == 'm')
	     {
		m_itr1 = t_map.find(arg1);

		if(m_itr1 != t_map.end())    
		    m_itr1->second.value += 1;		  
		else
		    Error("Intal Error: INCR referenced a non-existant binding\n");
	     }
	    else if(method == 'l')
	    {
		l_itr1 = find(t_list, arg1);

		if(l_itr1 != t_list.end())
		    l_itr1->second.value += 1;
		else
		    Error("Intal Error: INCR referenced a non-existant binding\n");
	    }
	    else		
		Error("Invalid command line flag " + method);	    
	}
	else if(com_str == "DECR")
	{
	    get_arg(arg1, input_s, start);

	    if(method == 'h')
	    {
		h_itr1 = t_hmap.find(arg1);

		if(h_itr1 != t_hmap.end())    
		    h_itr1->second.value -= 1;	         
		else
		    Error("Intal Error: DECR referenced a non-existant binding\n");
	    }
	    else if(method == 'm')
	    {
		m_itr1 = t_map.find(arg1);

		if(m_itr1 != t_map.end())    
		    m_itr1->second.value -= 1;	         
		else
		    Error("Intal Error: DECR referenced a non-existant binding\n");
	    }
	    else if(method == 'l')
	    {
		l_itr1 = find(t_list, arg1);

		if(l_itr1 != t_list.end())
		    l_itr1->second.value -= 1;
		else
		    Error("Intal Error: DECR referenced a non-existant binding\n");
	    }
	    else
		Error("Invalid command line flag " + method);	
	}
	else if(com_str == "MULT")
	{	  	  
	    get_args(arg1, arg2, input_s, start);

	    if(method == 'h')
	    {		
		h_itr1 = t_hmap.find(arg1);
		h_itr2 = t_hmap.find(arg2);
		
		if(h_itr1 != t_hmap.end() && h_itr2 != t_hmap.end())
		    h_itr1->second.value *= h_itr2->second.value;
		else
		    Error("Intal Error: MULT referenced a non-existant binding\n");
	    }
	    else if(method == 'm')
	    {		
		m_itr1 = t_map.find(arg1);
		m_itr2 = t_map.find(arg2);
		
		if(m_itr1 != t_map.end() && m_itr2 != t_map.end())
		    m_itr1->second.value *= m_itr2->second.value;
		else
		    Error("Intal Error: MULT referenced a non-existant binding\n");
	    }
	    else if(method == 'l')
	    {
		l_itr1 = find(t_list, arg1);
		l_itr2 = find(t_list, arg2);

		if(l_itr1 != t_list.end() && l_itr2 != t_list.end())
		    l_itr1->second.value *= l_itr2->second.value;
		else
		    Error("Intal Error: MULT referenced a non-existant binding\n");
	    }
	    else
		Error("Invalid command line flag " + method);	
	}
	else if(com_str == "ADD")
	{	  	  
	    get_args(arg1, arg2, input_s, start);

	    if(method == 'h')
	    {		
		h_itr1 = t_hmap.find(arg1);
		h_itr2 = t_hmap.find(arg2);
		
		if(h_itr1 != t_hmap.end() && h_itr2 != t_hmap.end())
		    h_itr1->second.value += h_itr2->second.value;
		else
		    Error("Intal Error: ADD referenced a non-existant binding\n");
	    }
	    else if(method == 'm')
	     {		
		m_itr1 = t_map.find(arg1);
		m_itr2 = t_map.find(arg2);
		
		if(m_itr1 != t_map.end() && m_itr2 != t_map.end())
		    m_itr1->second.value += m_itr2->second.value;
		else
		    Error("Intal Error: ADD referenced a non-existant binding\n");
	     }
	    else if(method == 'l')
	    {
		l_itr1 = find(t_list, arg1);
		l_itr2 = find(t_list, arg2);

		if(l_itr1 != t_list.end() && l_itr2 != t_list.end())
		    l_itr1->second.value += l_itr2->second.value;
		else
		    Error("Intal Error: ADD referenced a non-existant binding\n");
	    }
	    else
		Error("Invalid command line flag " + method);
	}
	else if(com_str == "SUB")
	{	  	  
	    get_args(arg1, arg2, input_s, start);

	    if(method == 'h')
	    {		
		h_itr1 = t_hmap.find(arg1);
		h_itr2 = t_hmap.find(arg2);
		
		if(h_itr1 != t_hmap.end() && h_itr2 != t_hmap.end())
		    h_itr1->second.value -= h_itr2->second.value;
		else
		    Error("Intal Error: SUB referenced a non-existant binding\n");
	    }
	    else if(method == 'm')
	     {		
		m_itr1 = t_map.find(arg1);
		m_itr2 = t_map.find(arg2);
		
		if(m_itr1 != t_map.end() && m_itr2 != t_map.end())
		    m_itr1->second.value -= m_itr2->second.value;
		else
		    Error("Intal Error: SUB referenced a non-existant binding\n");
	     }
	    else if(method == 'l')
	    {
		l_itr1 = find(t_list, arg1);
		l_itr2 = find(t_list, arg2);

		if(l_itr1 != t_list.end() && l_itr2 != t_list.end())
		    l_itr1->second.value -= l_itr2->second.value;
		else
		    Error("Intal Error: SUB referenced a non-existant binding\n");
	    }
	    else
		Error("Invalid command line flag " + method);
	}
	else if(com_str == "DIV")
	{	  	  
	    get_args(arg1, arg2, input_s, start);

	    if(method == 'h')
	    {		
		h_itr1 = t_hmap.find(arg1);
		h_itr2 = t_hmap.find(arg2);
		
		if(h_itr1 != t_hmap.end() && h_itr2 != t_hmap.end())
		{
		    if(h_itr2->second.value == 0)
			Error("Intal Sytax Error: division by zero in DIV\n");
		    h_itr1->second.value /= h_itr2->second.value;
		}
		else
		    Error("Intal Error: DIV referenced a non-existant binding\n");
	    }
	    else if(method == 'm')
	    {
		m_itr1 = t_map.find(arg1);
		m_itr2 = t_map.find(arg2);
		
		if(m_itr1 != t_map.end() && m_itr2 != t_map.end())
		{
		    if(m_itr2->second.value == 0)
			Error("Intal Sytax Error: division by zero in DIV\n");
		    m_itr1->second.value /= m_itr2->second.value;
		}
		else
		    Error("Intal Error: DIV referenced a non-existant binding\n");
	    }
	    else if(method == 'l')
	    {
		l_itr1 = find(t_list, arg1);
		l_itr2 = find(t_list, arg2);
		
		if(l_itr1 != t_list.end() && l_itr2 != t_list.end())
		{
		    if(l_itr2->second.value == 0)
			Error("Intal Sytax Error: division by zero in DIV\n");
		    l_itr1->second.value /= l_itr2->second.value;
		}
		else
		    Error("Intal Error: DIV referenced a non-existant binding\n");
	    }
	    else
		Error("Invalid command line flag " + method);	    	    	    
	}
	else if(com_str == "MOD")
	{	  	  
	    get_args(arg1, arg2, input_s, start);

	    if(method == 'h')
	    {		
		h_itr1 = t_hmap.find(arg1);
		h_itr2 = t_hmap.find(arg2);
		
		if(h_itr1 != t_hmap.end() && h_itr2 != t_hmap.end())
		{
		    if(h_itr2->second.value == 0)
			Error("Intal Sytax Error: division by zero in DIV\n");
		    h_itr1->second.value %= h_itr2->second.value;
		}
		else
		    Error("Intal Error: MOD referenced a non-existant binding\n");
	    }
	    else if(method == 'm')
	    {
		m_itr1 = t_map.find(arg1);
		m_itr2 = t_map.find(arg2);
		
		if(m_itr1 != t_map.end() && m_itr2 != t_map.end())
		{
		    if(m_itr2->second.value == 0)
			Error("Intal Sytax Error: division by zero in DIV\n");
		    m_itr1->second.value %= m_itr2->second.value;
		}
		else
		    Error("Intal Error: MOD referenced a non-existant binding\n");
	    }
	    else if(method == 'l')
	    {
		l_itr1 = find(t_list, arg1);
		l_itr2 = find(t_list, arg2);
		
		if(l_itr1 != t_list.end() && l_itr2 != t_list.end())
		{
		    if(l_itr2->second.value == 0)
			Error("Intal Sytax Error: division by zero in DIV\n");
		    l_itr1->second.value %= l_itr2->second.value;
		}
		else
		    Error("Intal Error: MOD referenced a non-existant binding\n");
	    }
	    else
		Error("Invalid command line flag " + method);
	}
	else if(com_str == "PRINT")
	{
	    get_arg(arg1, input_s, start);

	    if(method == 'h')
	    {
		h_itr1 = t_hmap.find(arg1);

		if(h_itr1 != t_hmap.end())       
		    cout<<h_itr1->second.value <<endl;
		else
		    Error("Intal Error: PRINT referenced a non-existant binding\n");
	    }
	    else if(method == 'm')
	    {
		m_itr1 = t_map.find(arg1);

		if(m_itr1 != t_map.end())       
		    cout<<m_itr1->second.value <<endl;
		else
		    Error("Intal Error: PRINT referenced a non-existant binding\n");
	    }
	    else if(method == 'l')
	    {
		l_itr1 = find(t_list, arg1);

		if(l_itr1 != t_list.end())
		    cout<<(l_itr1->second).value <<endl;
		else
		     Error("Intal Error: PRINT referenced a non-existant binding\n");
	    }
	    else
		Error("Invalid command line flag " + method);
	}
	else
	    Error("Unknown command: " + com_str);

	start = -1;  //reset character start flag
	space_ind = -1;  //reset space index flag
    }
    return 0;
}	   	
   
//*************************************************************
// Function: Error(const string& msg)
//
// Purpose: prints msg to the standard error stream and exits
// the program
//
// Parameters: const string& msg
//
// Member/Global variables: none
//
// Preconditions: none
//
// Postconditions: msg is sent to cerr and exit(1) is called
//
//*************************************************************
void Error(const string& msg)
{
    cerr<<msg;
    exit(1);
}

//Iterates through all the whitespace in a string
//Returns the an index in s1 to the first character that is
//not whitespace, or -1 if not found
//*************************************************************
// Function: int eat_space(string s1, size_t i)
//
// Purpose: Returns an index in s1 to the first character
// starting at s1[i] that is not a space character; returns
// -1 if not found
//
// Parameters: string s1, size_t i
//
// Member/Global variables: 
//
// Preconditions: none
//
// Postconditions: If a character was found starting  s[i] that
// was not a space character, then its index is returned.
// Otherwise, -1 is returnd
//
//*************************************************************
int eat_space(string s1, size_t i)
{
    int first_char = -1;

    for(size_t j = i; j < s1.length() && first_char == -1; i++)
    {
	if(!isspace(s1[i]))	    
	    first_char = i;	
    }

    return first_char;
}

//*************************************************************
// Function: bool get_args(string& arg1, string& arg2,
//                         const string input, int start_char)
//
// Purpose: Returns arguments for an Intal Command of the form:
// Command(string) arg1 agr2
//
// Parameters: string& arg1, string& arg2, const string input
//             int start_char
//
// Member/Global variables: none
//
// Preconditions: Assume start_char is an index to a char value
// in input
//
// Postconditions: If arg1 and arg2 are read as substrings from
// input, then true is returned. othewise, false is returned
//*************************************************************
bool get_args(string& arg1, string& arg2, const string input, int start_char)
{
    int last_char = -1;
    
    //strip out arg1
    for(size_t i = start_char; i < input.length() && last_char == -1; i++)
    {
	if(isspace(input[i]))
	   last_char = i-1;
    }

    //Error check arg1
    if(last_char == -1)
	return false;

    arg1 = input.substr(start_char, last_char - start_char + 1);

    
    //strip out arg2    
    start_char = eat_space(input, last_char+1);
    
    if(start_char == -1)	
	return false;
    	
    last_char = start_char;
    
    while(last_char < input.length())
	last_char++;
    
    if(last_char == start_char)	
	return false;
    
    arg2 = input.substr(start_char, last_char - start_char + 1);    

    return true;
}

//*************************************************************
// Function: get_arg(string& arg1, const string input, int start_char)
//
// Purpose: Returns arguments for an Intal Command of the form:
// Command(string) arg1
//
// Parameters: string& arg1, const string input, int start_char
//
// Member/Global variables: none
//
// Preconditions: 
//
// Postconditions: If start_char is not the size of input, then
// arg1 is set to all characers after and including input[start_char]
// and true is returned. Otherwiaw false is returned
//
//*************************************************************
bool get_arg(string& arg1, const string input, int start_char)
{
    //strip out arg1    
    int last_char = start_char;
    
    while(last_char < input.length())
	last_char++;
    
    if(last_char == start_char)	
	return false;
    
    arg1 = input.substr(start_char, last_char - start_char + 1);    

    return true;
}

//*************************************************************
// Function: string_to_int(const string& s1)
//
// Purpose: converts a string to an integer
//
// Parameters: const string& s1
//
// Member/Global variables: none
//
// Preconditions: s1 is a string of digits
//
// Postconditions: the integer value of the number string s1
// is returned
//*************************************************************
int string_to_int(const string& s1)
{
    const char* str = s1.c_str();
    int num = 0 ;

    for(int i = 0; str[i] != '\0'; i++)    {
	num = num * 10 ;	
	num = num + int( str [i] - '0' ) ;
    }
    return num;
}

//*************************************************************
// Function: find(list<pair<string, binding> > l, const string& target)
//
// Purpose: finds a spot in a linked list of pairs of strings
// and bindings whose string is equal to target
//
// Parameters: list<pair<string, binding> > l, const string& target
//
// Member/Global variables: none
//
// Preconditions: none
//
// Postconditions: If a list object was found with it string equal
// to target, then an itrerator to that object is returned;
// Otherwise NULL is returned
//*************************************************************
list<pair<string, binding> >::iterator find(list<pair<string, binding> > l, const string& target)
{
    list<pair<string, binding> >::iterator itr;

    for(itr = l.begin(); itr != l.end(); ++itr)
    {
	if(itr->first == target)
	    return itr;
    }

    return NULL;
}
