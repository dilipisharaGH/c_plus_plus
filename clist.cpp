/*
clist [THE ARRAY HANDLER!]
this is one of more easier way to handle arrays in C++
refer the original resource from: https://raw.githubusercontent.com/dilipisharaGH/c_plus_plus/main/clist.cpp
*/

#pragma ones

#include <iostream>
#include <sstream>
#include <typeinfo>

using namespace std;

#define cprint(W) (cout << W << endl)

template <typename T>
class clist
{
	private:
	
		int dp;
		T *local;
		T null;
		
		template <typename mytype>
		string as_string(mytype object)
		{
		    stringstream QuickAccessWord;
		    QuickAccessWord << object;
		    string word;
		    QuickAccessWord >> word;
		    return word;  
		}
	public:
	
		//Read Only Section
		int depth(){return dp;}
		
		void viwe()
		{
			string my_array;
			if (dp > 0)
			{
				my_array = "{";
				string typer = typeid(local).name();
				char typeof = typer[1];
	
				if (typeof == 'N') {for (int i = 0; i < dp - 1; i++){my_array += "\"" + as_string(local[i]) + "\"" + " ,";}my_array += "\"" + as_string(local[dp - 1]) + "\"";}
				else if (typeof == 'i' or typeof == 'b' or typeof == 'f' or typeof == 'd'){for (int i = 0; i < dp - 1; i++){my_array += as_string(local[i]) + " ,";}my_array += as_string(local[dp - 1]);}
				else if (typeof == 'c'){for (int i = 0; i < dp - 1; i++){my_array += "\'" + as_string(local[i]) + "\'" + " ,";}my_array += "\'" + as_string(local[dp - 1]) + "\'";}
				else {my_array += "error";}
				my_array += "}";
			}
			else
			{
				my_array = "{}";
			}
			cprint(my_array);
		}
		
		T min()
		{
		    T xyz;
		    xyz = local[0];
		    for (int i = 0; i < dp ; i++) 
		    {
		    	 if (local[i] < xyz) 
		    	 {
		    	 	 xyz = local[i]; 
		    	 } 
		    }
		    return xyz;
		}
		T max()
		{
		    T xyz;
		    xyz = local[0];
		    for (int i = 0; i < dp ; i++) 
		    { 
		    	if (local[i] > xyz) 
		    	{
		    		 xyz = local[i]; 
		        } 
		    }
		    return xyz;
		}
		
		int find(T E)
		{
			int counter = 0;
			for (int i = 0; i < dp; i++)
			{
				if (local[i] == E)
				{
					return counter;
				}
				counter++;
			}
			return -1;
		}
	
		int rfind(T E)
		{
			int counter = 0;
			int pos = 0;
			for (int i = 0; i < dp; i++)
			{
				if (local[i] == E)
				{
					pos = counter;
				}
				counter++;
			}
			return pos;
		}
		
		int check(T E)
		{
			for (int i = 0; i < dp; i++)
			{
				if (local[i] == E)
				{
					return true;
				}
			}
			return false;
		}
	
		int count(T E)
		{
			int counter = 0;
			for (int i = 0; i < dp; i++)
			{
				if (local[i] == E)
				{
					counter++;
				}
			}
			return counter;
		}
		
		
		//Writing Section
		T &operator[](int index) 
		{
			return local[index];
		}
		
		void clear()
		{
			for (int i = 0 ; i < dp ; i++)
			{
				local[i] = null;
			}
		}
		
		void replace(T W , T E)
		{
			for (int i = 0; i < dp; i++)
			{
				if (local[i] == W)
				{
					local[i] = E;
				}
			}
		}
		
		void reverse() //warning
		{
			for (int i = 0 ; i < dp/2 ; i++)
			{
				int stnd = (dp-1)-i;
				T var_0 = local[stnd];
				local[stnd] = local[i];
				local[i] = var_0; 
			}
		}
		
		template <size_t ln>
		void copyto(T (&copi)[ln])
		{
			for (int i = 0 ; i < ln ; i++)
			{
				copi[i] = local[i];
			}
		}
		
		void swap(int place)
		{
			T swaparr[2];
			if (place == 0)
			{
				//store
				swaparr[0] = local[0];
				swaparr[1] = local[dp-1];
				//swap
				local[dp-1] = swaparr[0];
				local[0] = swaparr[1];
			}
			else
			{
				//store
				swaparr[0] = local[place];
				swaparr[1] = local[place-1];
				//swap
				local[place-1] = swaparr[0];
				local[place] = swaparr[1];
			}
		}
		
		void spin(bool isforward = true)
		{
			if (isforward == true)
			{
				for (int i = dp-2; i > -1; i--)
				{
					T var_0 = local[i+1];
					local[i+1] = local[i];
					local[i] = var_0;
					//cprint(var_0);
				}
			}
			else
			{
				for (int i = 1; i < dp; i++)
				{
					T var_0 = local[i-1];
					local[i-1] = local[i];
					local[i] = var_0;
				}
			}
			
		}
		
		//bubble sort algorithm
		void sort(bool isAscending = true)
		{
			for (int j = 1 ; j < dp ; j++)
	    	{
	   	 	int n = 0;
			    for (int i = 1 ; i < dp ; i++)
			    {
			        if (local[i-1] > local[i]) { swap(i); n++; }
			    }
			    if (n == 0) {break;}
			    n = 0;
			}
			if (isAscending == false) {reverse();}
		}
			
		//Initializer
		template <size_t N>
		clist(T (&drive)[N])
		{
			local = drive;
			dp = N;
		}
};

//still developping...and debugging...
//responding element range : user define
//total methods			: 15

//created :- 2021.11.18 @15:10
//last updated :- 2022.01.22 @11:09 as 6th update
