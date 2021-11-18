#include <sstream>

using namespace std;

template <typename udef>
extern class clist
{
  private:
        unsigned int lenarr = 0;
	udef access_var[8192];
	udef samplearr[1];
	bool repor[8192];
  
        template <typename mytype>
	string as_string(mytype object)
	{
	    stringstream QuickAccessWord;
	    QuickAccessWord << object;
	    string word;
	    QuickAccessWord >> word;
	    return word;  
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
	
	void prive_clear()
	{
		for (int i = 0 ; i < lenarr ; i++)
		{
			repor[i] = samplearr[0];
		}
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
	
	udef access(unsigned int position)
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
	void set(format element ,unsigned int position)
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
		
	udef *slice(int pos[2])
	{
		udef innerr[1024];
		int val = 0;
		for (int i = pos[0]; i < pos[1]; i++)
		{
			innerr[val] = access_var[i];
			val++;
		}
		return innerr;
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
				for (int i = 0; i < lenarr; i++)
				{
					my_array += "\"" + as_string(access_var[i]) + "\"" + " ,";
				}
			}
			else if (typeof == 'i' or typeof == 'b' or typeof == 'f' or typeof == 'd')
			{
				for (int i = 0; i < lenarr; i++)
				{
					my_array += as_string(access_var[i]) + " ,";
				}
			}
			else if (typeof == 'c')
			{
				for (int i = 0; i < lenarr; i++)
				{
					my_array += "\'" + as_string(access_var[i]) + "\'" + " ,";
				}
			}
			int x = my_array.size() - 1;
			my_array[x - 1] = 00;
			my_array[x] = '}';
			cout << my_array << endl;
		}
		else
		{
			my_array = "{-Empty-}";
			cout << my_array << endl;
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

	template <typename subdef>
	int *find_all(subdef subelmnt)
	{
		unsigned int counter = 0;
		unsigned int pos = 0;
		unsigned int val = 0;
		int collect[1024];
		for (int i = 0; i < lenarr; i++)
		{
			if (access_var[i] == subelmnt)
			{
				pos = counter;
				val++;
				collect[val] = pos;
			}
			counter++;
		}
		collect[0] = val;
		return collect;
	}

	template <typename undef>
	void replace(undef subelmntarr[2])
	{
		undef *localarray = access_var;
		for (int i = 0; i < lenarr; i++)
		{
			if (localarray[i] == subelmntarr[0])
			{
				localarray[i] = subelmntarr[1];
			}
		}
		for (int i = 0; i < lenarr; i++)
		{
			access_var[i] = localarray[i];
		}
	}

	void pop(unsigned int fall_point = 0)
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
	void insert(subelement subword, unsigned int fill_point = 0)
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
	
	void swap(unsigned int place)
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
	    	pop(find(min()));
	    }
	    clear();
	    (not flow)?extend(beta,totalen),reverse():extend(beta,totalen);
	}
	
	udef *get()
	{
		return access_var;
	}

}
//responding range : 2^13 & 2^10
