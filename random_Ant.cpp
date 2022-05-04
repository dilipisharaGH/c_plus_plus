//Ant(8) will have found the Sugar_cube(2); :)
/*The Random access maze sloving progrmme*/
#pragma ones

#include <iostream>
#include <vector>
#include <string>
#include <random>

#pragma GCC diagnostic ignored "-Wreturn-stack-address"

//memory album
struct memo
{
	int id = 0;
	char dir[4] = {'-' ,'-' ,'-' ,'-'};
};

//unused developper tool
template <size_t YY, size_t XX>
struct MAZE_BD
{
	int maze_bd[YY][XX];
	int rown = 0;
	int coln = 0;
	MAZE_BD(int (&grid)[YY][XX])
	{
		rown = YY;
		coln = XX;
		for (int y = 0; y < rown; y++)
		{
			for (int x = 0; x < coln; x++)
			{
				maze_bd[y][x] = grid[y][x];
			}
		}
	}
};

//unused developper tool
template <typename T>
class pack
{
	private:
		T *packet;
		int dep;
	public:
		void add(T elt)
		{
			for (int i = dep-1 ; i > 0 ; i--)
			{
				packet[i] = packet[i-1];
			}
			packet[0] = elt;
		}
		
		T &operator[](int ID) 
		{
			T val;
			if (ID < dep)
				return packet[ID];
			else
				return val;
		}
	
		pack(size_t len)
		{
			packet = new T[len];
			dep = len;
			for (int i = 0 ; i < len ; i++)
			{
				packet[i] = 0;
			}
		}
		
		~pack()
		{
			delete[] packet;
		}
};

//basic Ant
template <size_t YY, size_t XX>
class stepBase
{
	/*VISIBLE ELEMENTS*/
	// 8  = Player(ant)
	// 0  = Wall
	// 1  = Routes
	// 2  = SugerCube
  protected:
    int std_player = 8;
	int std_object = 2;
	int std_wall = 0;
	int std_route = 1;

	int mazeb[YY][XX];
	int rown = 0;
	int coln = 0;
	std::vector<char> dir_rec;
	std::vector<char> dir_analyzer;
	const char way[4] = {'n', 'e', 's', 'w'};
	const char reway[4] = {'s' ,'w' ,'n' ,'e'};
	char from = '-';
	int native_loc[2] = {0, 0};
	int xcd = 0;
	int ycd = 0;
	int state = 1;

	//roundouts...
	int *pin()
	{
		int elts[9] = {
			mazeb[ycd - 1][xcd],
			mazeb[ycd][xcd + 1],
			mazeb[ycd + 1][xcd],
			mazeb[ycd][xcd - 1]};
		return elts;
	}
	
	char antidirect(char parm)
	{
	 	for (int i = 0 ; i < 4 ; i++)  if (parm == this->way[i])  return this->reway[i]; return -1;
	}
	
	//To monitoring the progress...
	void show()
	{
		for (int y = 0; y < rown; y++)
		{
			for (int x = 0; x < coln - 1; x++)
			{
				std::cout << mazeb[y][x] << ' ';
			}
			std::cout << mazeb[y][coln - 1] << std::endl;
		}
		printf("(y[%i], x[%i]) <n[%i].e[%i].s[%i].w[%i]>\n", ycd, xcd, pin()[0], pin()[1], pin()[2], pin()[3]);
	}
	//To get road map
	void recordl()
	{
		for (char sign : dir_rec)
		{
			std::cout << sign;
		}
		std::cout << std::endl;
	}


  public:
	//Movements drivings...
	void move(char direction)
	{
		mazeb[ycd][xcd] = state;
		switch (direction)
		{
		case 's':
			state = mazeb[ycd + 1][xcd];
			mazeb[ycd + 1][xcd] = std_player;
			dir_rec.push_back('s');
			from = 'n';
			ycd++;
			break;
		case 'n':
			state = mazeb[ycd - 1][xcd];
			mazeb[ycd - 1][xcd] = std_player;
			dir_rec.push_back('n');
			from = 's';
			ycd--;
			break;
		case 'e':
			state = mazeb[ycd][xcd + 1];
			mazeb[ycd][xcd + 1] = std_player;
			dir_rec.push_back('e');
			from = 'w';
			xcd++;
			break;
		case 'w':
			state = mazeb[ycd][xcd - 1];
			mazeb[ycd][xcd - 1] = std_player;
			dir_rec.push_back('w');
			from = 'e';
			xcd--;
			break;
		}
	}
	
	//initializing...
	stepBase(int (&grid)[YY][XX])
	{
		rown = YY;
		coln = XX;
		for (int y = 0; y < rown; y++)
		{
			for (int x = 0; x < coln; x++)
			{
				if (grid[y][x] == std_player)
				{
					native_loc[0] = y;
					native_loc[1] = x;
					xcd = x;
					ycd = y;
				}
				mazeb[y][x] = grid[y][x];
			}
		}
	}
};

//Actions data regulation
template <size_t YY, size_t XX>
class Ract : public stepBase <YY ,XX>
{
	/*REPORTS*/
	// @  = won report
	// *  = successful movement
	// ?  = completely blocked
	// #  = native location

	// W  = simple move
	// U  = turn back
	// J  = juction warning
	
  using stepBase <YY  ,XX>::stepBase;
  
  protected:
	std::vector <memo> j_loc;
  
	int routes = 0;
	int term = 0;
	char to = '-';
	bool lgc = false;
	
	char update()
	{
		char status = '*';
		int rou = 0;
		int dir[4] = {this->pin()[0], this->pin()[1], this->pin()[2], this->pin()[3]};
		for (int i = 0; i < 4; i++)
		{
			if (dir[i] == this->std_route)
			{
				if (this->way[i] != this->from)
				{
					to = this->way[i];
				}
				rou++;
			}
			if (dir[i] == this->std_object)
			{
				status = '@';
			}
		}
		routes = rou;
		if (rou == 0)
		{
			status = '?';
		}
		else if ((this->ycd == this->native_loc[0]) && (this->xcd == this->native_loc[1]))
		{
			status = '#';
		}
		else if (lgc)
		{
			status = 'E';
		}
		return status;
	}

	char repor()
	{
		term++;
		if (term > 1)
		{
			if (routes == 1)
			{
				return 'U';
			}
			else if (routes == 2)
			{
				return 'W';
			}
			else if (routes > 2)
			{
				return 'J';
			}
			return '-';
		}
		else
		{
			if (routes == 1)
			{
				return 'W';
			}
			else if (routes > 1)
			{
				return 'J';
			}
		}
		return '-';
	}

	void i_walk()
	{
		this->move(to);
	}

	void u_turn()
	{
		this->move(this->from);
	}

	void junc()
	{
		struct memo mem;
		mem.id = (this->rown*this->ycd) + this->xcd;
		bool argue = true; //hadn't met before?
		int vec_loc = 0;
		
		for (int i = 0 ; i < j_loc.size() ; i++)
		{
			if (j_loc[i].id == mem.id)
			{
				argue = false;
				for (int ii = 0 ; ii < 4 ; ii++)
				{
					mem.dir[ii] = j_loc[i].dir[ii];
				}
				vec_loc = i;
				break;
			}
		}
		if (argue)
		{
			int dir[4] = {this->pin()[0], this->pin()[1], this->pin()[2], this->pin()[3]};
			for (int i = 0; i < 4; i++)
			{
				if (dir[i] == this->std_route)
				{
					if (this->way[i] != this->from)
					{
						mem.dir[i] = this->way[i];
					}
					else
					{
						mem.dir[i] = '+';
					}
				}
			}
			j_loc.push_back(mem);
			vec_loc = j_loc.size()-1;
		}
		
		int post[3] = {0 ,0, 0};
	    int r_count = 0;
	    int hyphens = 0;
	    int entrance = 0;
	    
	    for (int i = 0 ; i < 4 ; i++)
	    {
	    	char rt = mem.dir[i];
	    	if (rt != '-')
	    	{
	    		if (rt == '+') entrance = i;
	    		else
	    		{
	    			post[r_count] = i;
	    			r_count++;
	    		}
	    	}
	    	else hyphens++;
	    }
	    
	    int num = 0;
		if (hyphens != 4)
		{
			if (r_count > 1)
			{
				std::random_device rd;
				std::default_random_engine eng(rd());
				std::uniform_int_distribution<int> distr(0, r_count-1);
				num = post[distr(eng)];
			}
			else if (r_count == 1)
			{
				num = post[0];
			}
			else if (r_count < 1)
			{
				num = entrance;
			}
			
			j_loc[vec_loc].dir[num] = '-';
			this->move(this->way[num]);
		}
		else
		{
			lgc = true;
		}
	}
		
};

//co-ordination between thinking and running
template <size_t YY, size_t XX>
class Ant : public Ract <YY ,XX>
{
  using Ract<YY ,XX>::Ract;
  public:
	void autoRun()
	{
		char rps = '-';
		char ups = '-';
		while (true)
		{
			ups = this->update();
			rps = this->repor();
			this->show();
			printf("Term(%i) | Paths(%i) | To(%c) | From(%c) | Act. Report(%c) | Update(%c)\n\n", this->term, this->routes, this->to, this->from, rps, ups);

			switch (rps)
			{
			case 'W':
				this->i_walk();break;
			case 'U':
				this->u_turn();break;
			case 'J':
				this->junc();break;
			}
			
				 if (ups == '@') {std::cout << "[🏆️].Congratulations; You won!" << std::endl;break;}
			else if (ups == '?') {std::cout << "[⚠️️].Blocked; You blocked!" << std::endl;break;}
			else if (ups == 'E') {std::cout << "[🚫].NodeCrack; You have gone everywhere!" << std::endl;break;}
			system("pause >0");
		}
		this->recordl();
	}
};

// (2021 Apr 6) @7.08pm


int main()
{
	int maze[27][27] = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0},
		{0, 8, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0},
		{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0},
		{0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,0 ,0 ,0 ,1 ,1 ,1 ,1 ,0},
		{0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1 ,1 ,1 ,1 ,1 ,0 ,0 ,1 ,0},
		{0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0},
		{0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1 ,0 ,1 ,1 ,1 ,1 ,1 ,1 ,0},
		{0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1 ,0 ,1 ,0 ,1 ,0 ,1 ,0 ,0},
		{0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0 ,0 ,1 ,0 ,0 ,0 ,1 ,0 ,0},
		{0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,0},
		{0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0},
		{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0 ,0 ,1 ,0 ,1 ,1 ,1 ,1 ,0},
		{0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1 ,0 ,1 ,0 ,0 ,1 ,0 ,1 ,0},
		{0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0},
		{0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 ,0 ,0 ,0 ,0 ,1 ,0 ,1 ,0},
		{0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1 ,1 ,1 ,0 ,0 ,1 ,0 ,1 ,0},
		{0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 0 ,0 ,1 ,1 ,1 ,1 ,0 ,2 ,0},
		{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0},
		{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0},
		{0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1 ,0 ,1 ,0 ,1 ,0 ,1 ,0 ,0},
		{0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0 ,0 ,1 ,1 ,1 ,0 ,1 ,0 ,0},
		{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1 ,1 ,1 ,0 ,1 ,0 ,1 ,0 ,0},
		{0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0 ,1 ,0 ,0 ,1 ,1 ,1 ,0 ,0},
		{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1 ,1 ,1 ,1 ,1 ,0 ,1 ,0 ,0},
		{0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0 ,0 ,0 ,1 ,0 ,0 ,1 ,0 ,0},
		{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0},
	};
	Ant <27 ,27> A(maze);
	A.autoRun();
	
	//std::cout << sizeof(A) << std::endl;
	return 0;
}

//UpNext: selective function!
//UpNext: loop breaker
//UpNext: route predictor and analyzer

