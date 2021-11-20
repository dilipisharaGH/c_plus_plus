/*
This will present you many useful library function for fast coding and keep your code short and sweet.
many useful functions included with this for help you to complete your projects easierly!
Try with "lib16" library functions!
*/

#include <iostream>
#include <typeinfo>
#include <clist>
#include <sstream>

#define $KEY "/uNZIP/"

using namespace std;

template <typename mytype>
string as_string(mytype object)
{
    stringstream QuickAccessWord;
    QuickAccessWord << object;
    string word;
    QuickAccessWord >> word;
    return word;  
}

int as_int(string object)
{
    string integer = object;
    stringstream store(integer);
    int QuickAccessNumber = 0;
    store >> QuickAccessNumber;
    
    return QuickAccessNumber;
}

template <typename undefined>
string type(undefined my_type) 
{
    string def_type = typeid(my_type).name();
    string word = def_type;
    char spliter = '_';
    string spltr(1, spliter);
    
    if (def_type[0] == 'i')
    {
        return "int";
    }
    else if (def_type[0] == 'd')
    {
        return "double";
    }
    else if (def_type[0] == 'f')
    {
        return "float";
    }
    else if (def_type[0] == 'c')
    {
        return "char";
    }
    else if (def_type[0] == 'N' || def_type[1] == 'K')
    {
        return "string";
    }
    else if (def_type[0] == 'b')
    {
        return "bool";
    }
    
    else if (def_type[0] == 'P')
    {
        if (def_type[1] == 'i')
        {
            return "int";
        }
        else if (def_type[1] == 'd')
        {
            return "double";
        }
        else if (def_type[1] == 'f')
        {
            return "float";
        }
        else if (def_type[1] == 'c')
        {
            return "char";
        }
        else if (def_type[1] == 'N')
        {
            return "string";
        }
        else if (def_type[1] == 'b')
        {
            return "bool";
        }
    }
    else if (def_type[0] == 'A')
    {

        word += spltr;
    
        int Anum = 0;
        string SampleTxt = "";
        clist <string> SampleAr;
    
        while (Anum < word.length())
        {
            string str_wdn(1, word[Anum]);
            if (word[Anum] == spliter)
            {
                SampleAr.insert(SampleTxt,SampleAr.depth());
                SampleTxt = "";
            }
            else
            {
                SampleTxt += str_wdn;
            }
    
            Anum++;
        }
        
        int arr_len = SampleAr.depth();
        string as_str_arr_len = to_string(arr_len);
        
        static string new_arr[1024];
        
        new_arr[0] = as_str_arr_len;
        for (int num = 0 ; num < arr_len ; num++)
        {
            new_arr[num+1] = SampleAr.access(num);
        }
        if (new_arr[2][0] == 'i')
        {
            return "int";
        }
        else if (new_arr[2][0] == 'd')
        {
            return "double";
        }
        else if (new_arr[2][0] == 'f')
        {
            return "float";
        }
        else if (new_arr[2][0] == 'c')
        {
            return "char";
        }
        else if (new_arr[2][0] == 'N')
        {
            return "string";
        }
        else if (new_arr[2][0] == 'b')
        {
            return "bool";
        }
    else 
    {
    	return "undefinedined";
    }
    }
}

int sum(int arr[] ,unsigned int expected_len)
{
    int total = 0;
    for (int i = 0 ; i < expected_len ; i++)
    {
        total += arr[i];
    }
    return total;
}

int *range(int b ,int e ,int f = 1)
{
    int beginning = b;
    int ending = e;
    int flowing = f;
    clist <int> omega;
    
    for (int i = beginning ; i < ending ; i += flowing)
    {
        omega.insert(i,omega.depth());
    }
    int length_of_omega = omega.depth();
    omega.insert(length_of_omega,0);
    int *beta = omega.get();
    
    return beta;
}

template <typename typeorder>
void print(typeorder key , string lining = "\n")
{
    cout << key << lining;
}

using namespace std;

int ord(char character)
{
    int my_char;
    my_char = character * 1;
    return my_char;
}

int min(int arr[],int this_len)
{
    int x;
    x = arr[0];
    for (int i = 0; i < this_len ; i++) { if (arr[i] < x) { x = arr[i]; } }
    return x;
}

int max(int arr[],int this_len)
{
    int x;
    x = arr[0];
    for (int i = 0; i < this_len ; i++) { if (arr[i] > x) { x = arr[i]; } }
    return x;
}

template <typename typeorder>
typeorder input (string temp = "")
{
    typeorder key;
    cout << temp;
    cin >> key;
    return key;
}

string chr(int num)
{
    char character = num;
    string result(1,character);
    return result;
}

template <typename typer>
string array_viwe(typer arr[] , int lengthof)
{
    string typeof = type(arr);
    string my_array = "{";
    
    if (typeof == "string")
    {
        for (int i = 0 ; i < lengthof ; i++)
        {
            my_array += "\"" + as_string(arr[i]) + "\"" + " ,";
        }
    }
    else if (typeof == "int" or typeof == "bool" or typeof == "float" or typeof == "double")
    {
        for (int i = 0 ; i < lengthof ; i++)
        {
            my_array += as_string(arr[i]) + " ,";
        }
    }
    else if (typeof == "char")
    {
        for (int i = 0 ; i < lengthof ; i++)
        {
            my_array += "\'" + as_string(arr[i]) + "\'" + " ,";
        }
    }
    int x = my_array.size() - 1;
    my_array[x-1] = 00;
    my_array[x] = '}';
    return my_array;
}

template <typename definition>
definition min(definition arr[],int this_len)
{
    definition x;
    x = arr[0];
    for (int i = 0; i < this_len ; i++) 
    {
    	 if (arr[i] < x) 
    	 {
    	 	 x = arr[i]; 
    	 } 
    }
    return x;
}
template <typename definition>
definition max(definition arr[],int this_len)
{
    definition x;
    x = arr[0];
    for (int i = 0; i < this_len ; i++) 
    { 
    	if (arr[i] > x) 
    	{
    		 x = arr[i]; 
        } 
    }
    return x;
}

bool all(bool arr[] ,unsigned int this_len)
{
    for (int i = 0 ; i < this_len ; i++) 
    { 
    	if (arr[i] == false) 
    		{
    			 return false; 
    		}
    }
    return true;
}

bool any(bool arr[] ,unsigned int this_len)
{
    for (int i = 0 ; i < this_len ; i++) 
    {
    	 if (arr[i] == true) 
    	 {
    	 	 return true; 
    	 } 
    }
    return false;
}

//created :- 2020.10.12 @09:24
//last update :- 2020.11.19 @22:51
