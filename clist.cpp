/*
clist [THE ARRAY HANDLER!]

I create this data structure to enhance the performance of the C Plus Plus array and make it more efficient.
this array handler has clear syntax rules, and it easy to use than vectors.
also you can use my data structure as libray whether you want with save it under the .hpp or .h file extension!
i invite you to change this data structure and improve its skills than now!

i hope to improve skills of this data structure, and upgrade its perfomance monthly.
contact dilipishara52@gmail.com or +94704532646 for send suggestion and further information
thanks for using my "clist ARRAY HADLER"
*/

#include <sstream>

#ifndef __COMMON_H__
#define __COMMON_H__
using namespace std;

template <typename udef>
class clist
{
  private:
    int lenarr = 0;
	udef access_var[8192];
	udef innerr[8192];
	udef samplearr[1];
  
    template <typename mytype>
	string as_string(mytype object)
	{
	    stringstream QuickAccessWord;
	    QuickAccessWord << object;
	    string word;
	    QuickAccessWord >> word;
	    return word;  
	}
	
	bool all(bool arr[] ,int this_len)
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

  public:
    
	int depth()
	{
		return lenarr;
	}
	
	void clear()
	{
		for (int i = 0 ; i < lenarr ; i++)
		{
			access_var[i] = samplearr[0];
		}
		lenarr = 0;
	}
	
	udef access(int position)
	{
		if (position <= lenarr)
		{
			return access_var[position];
		}
		else
		{
			return samplearr[0];
		}
	}
	
	template <typename format>
	void set(format element ,int position)
	{
		if (position <= lenarr)
		{
			access_var[position] = element;
		}
	}
	
	udef min()
	{
	    udef xyz;
	    xyz = access_var[0];
	    for (int i = 0; i < lenarr ; i++) 
	    {
	    	 if (access_var[i] < xyz) 
	    	 {
	    	 	 xyz = access_var[i]; 
	    	 } 
	    }
	    return xyz;
	}
	udef max()
	{
	    udef xyz;
	    xyz = access_var[0];
	    for (int i = 0; i < lenarr ; i++) 
	    { 
	    	if (access_var[i] > xyz) 
	    	{
	    		 xyz = access_var[i]; 
	        } 
	    }
	    return xyz;
	}
		
	udef *slice(int pointin , int pointout)
	{
		if (pointin >= 0 and pointout <= lenarr)
		{
			//int rangeof = pointout - pointin;
			for (int i = 0 ; i < 8192 ; i++)
			{
				innerr[i] = samplearr[0];
			}
			
			int val = 0;
			for (int i = pointin; i < pointout; i++)
			{
				innerr[val] = access_var[i];
				val++;
			}
			
			return innerr;
		}
                else
                {
                        return samplearr;
                }
	}

	string viwe()
	{
		string my_array = "{";
		if (lenarr > 0)
		{
			string typer = typeid(access_var).name();
			char typeof = typer[6];

			if (typeof == 'N')
			{
				for (int i = 0; i < lenarr - 1; i++)
				{
					my_array += "\"" + as_string(access_var[i]) + "\"" + " ,";
				}
				my_array += "\"" + as_string(access_var[lenarr - 1]) + "\"";
			}
			else if (typeof == 'i' or typeof == 'b' or typeof == 'f' or typeof == 'd')
			{
				for (int i = 0; i < lenarr - 1; i++)
				{
					my_array += as_string(access_var[i]) + " ,";
				}
				my_array += as_string(access_var[lenarr - 1]);
			}
			else if (typeof == 'c')
			{
				for (int i = 0; i < lenarr - 1; i++)
				{
					my_array += "\'" + as_string(access_var[i]) + "\'" + " ,";
				}
				my_array += "\'" + as_string(access_var[lenarr - 1]) + "\'";
			}
			my_array += "}";
		}
		else
		{
			my_array = "{}";
		}
		return my_array;
	}
	
	string join(string joiner)
	{
	    string word = "NULL";
	    if (lenarr > 0)
	    {
		    word = "";
		    for (int i = 0 ; i < lenarr - 1 ; i++)
		    {
		        word += as_string(access_var[i]) + joiner;
		    }
		    word += as_string(access_var[lenarr - 1]);
	    }
	    return word;
	}

	template <typename subdef>
	int find(subdef subelmnt)
	{
		int counter = 0;
		for (int i = 0; i < lenarr; i++)
		{
			if (access_var[i] == subelmnt)
			{
				return counter;
			}
			counter++;
		}
		return -1;
	}

	template <typename subdef>
	int rfind(subdef subelmnt)
	{
		int counter = 0;
		int pos = 0;
		for (int i = 0; i < lenarr; i++)
		{
			if (access_var[i] == subelmnt)
			{
				pos = counter;
			}
			counter++;
		}
		return pos;
	}

	template <typename subdef>
	int check(subdef subelmnt)
	{
		for (int i = 0; i < lenarr; i++)
		{
			if (access_var[i] == subelmnt)
			{
				return true;
			}
		}
		return false;
	}

	template <typename subdef>
	int count(subdef subelmnt)
	{
		int counter = 0;
		for (int i = 0; i < lenarr; i++)
		{
			if (access_var[i] == subelmnt)
			{
				counter++;
			}
		}
		return counter;
	}

	int *find_all(udef subelement)
	{
		int var = 0;
		int collector[lenarr];
		for (int i = 0 ; i < lenarr ; i++)
		{
			if (access_var[i] == subelement)
			{
				var++;
				collector[var] = i;
			}
		}
		collector[0] = var;
		return collector;
	}

	template <typename undef>
	void replace(undef word , undef subword)
	{
		for (int i = 0; i < lenarr; i++)
		{
			if (access_var[i] == word)
			{
				access_var[i] = subword;
			}
		}
	}

	void pop(int fall_point = 0)
	{
		if (fall_point < lenarr and fall_point >= 0 and lenarr > 0)
		{
			udef innerr[8192];
			for (int i = 0; i < lenarr; i++)
			{
				if (fall_point <= i)
				{
					innerr[i] = access_var[i + 1];
				}
				else
				{
					innerr[i] = access_var[i];
				}
			}
			for (int i = 0; i < lenarr - 1; i++)
			{
				access_var[i] = innerr[i];
			}
			lenarr--;
		}
	}
	
	template <typename subelement>
	udef remove(subelement subword)
	{
		udef innerr[8192];
		int total = 0;
		int suber = 0;
		for (int i = 0 ; i < lenarr ; i++)
		{
			if (access_var[i] != subword)
			{
				innerr[suber] = access_var[i];
				suber++;
			}
			else {total++;}
		}
		for (int i = 0 ; i < suber ; i++)
		{
			access_var[i] = innerr[i];
		}
		for (int i = suber ; i < lenarr ; i++)
		{
			access_var[i] = samplearr[0];
		}
		lenarr = suber;
	}
	template <typename subelement>
	void insert(subelement subword, int fill_point = 0)
	{
		if (lenarr > 0)
		{
			if (fill_point <= lenarr and fill_point >= 0)
			{
				udef innerr[8192];
				innerr[0] = subword;
				if (fill_point == 0)
				{
					for (int i = 0; i < lenarr; i++)
					{
						innerr[i + 1] = access_var[i];
					}
				}
				else if (fill_point < lenarr)
				{
					for (int i = 0; i < lenarr; i++)
					{
						if (i < fill_point)
						{
							innerr[i] = access_var[i];
						}
						else if (i == fill_point)
						{
							innerr[i] = subword;
							innerr[i + 1] = access_var[i];
						}
						else if (i > fill_point)
						{
							innerr[i + 1] = access_var[i];
						}
					}
				}
				else if (fill_point == lenarr)
				{
					for (int i = 0 ; i < lenarr ; i++)
					{
						innerr[i] = access_var[i];
					}
					innerr[lenarr] = subword;
				}
				
				for (int i = 0; i <= lenarr; i++)
				{
					access_var[i] = innerr[i];
				}
				lenarr++;
			}
		}
		else if (lenarr == 0)
		{
			access_var[0] = subword;
			lenarr++;
		}
	}
	
	void reverse()
	{
		udef innerr[8192];
		int var = 0;
		for (int i = lenarr-1 ; i >= 0 ; i--)
		{
			innerr[var] = access_var[i];
			var++;
		}
		for (int i = 0 ; i < lenarr ; i++)
		{
			access_var[i] = innerr[i];
		}
		
	}
	
	void swap(int place)
	{
		udef swaparr[2];
		if (place == 0)
		{
			//store section
			swaparr[0] = access_var[0];
			swaparr[1] = access_var[lenarr-1];
			//swap section
			access_var[lenarr-1] = swaparr[0];
			access_var[0] = swaparr[1];
		}
		else
		{
			//store section
			swaparr[0] = access_var[place];
			swaparr[1] = access_var[place-1];
			//swap section
			access_var[place-1] = swaparr[0];
			access_var[place] = swaparr[1];
		}
	}
	
	void spin(bool isforward = true)
	{
		udef innerr[8192];
		if (isforward)
		{
			innerr[0] = access_var[lenarr-1];
			for (int i = 0 ; i < lenarr-1 ; i++)
			{
				innerr[i+1] = access_var[i];
			}
			
			for (int i = 0 ; i < lenarr ; i++)
			{
				access_var[i] = innerr[i];
			}
		}
		else
		{
			for (int i = 0 ; i < lenarr-1 ; i++)
			{
				innerr[i] = access_var[i+1];
			}
			innerr[lenarr-1] = access_var[0];
			
			for (int i = 0 ; i < lenarr ; i++)
			{
				access_var[i] = innerr[i];
			}
		}
	}
	
	void extend(udef new_array[] ,int lenn)
	{
		for (int i = 0 ; i < lenn ; i++)
		{
			int ava = lenarr + i;
			access_var[ava] = new_array[i];
		}
		lenarr += lenn;
	}
	
	void sort(bool flow = true)
	{
	    udef beta[8192];
	    int totalen = lenarr;
	    for (int i = 0 ; i < totalen ; i++)
	    {
	    	beta[i] = min();
	    	pop(find(beta[i]));
	    }
	    clear();
	    (not flow)?extend(beta,totalen),reverse():extend(beta,totalen);
	}
	
	udef *get()
	{
		return access_var;
	}

};
#endif

//still developping...and debugging...
//responding element range : between 2^10 and 2^13

//created :- 2020.11.18 @15:10
//last updated :- 2020.12.04 @12:22 as 4.5th update


