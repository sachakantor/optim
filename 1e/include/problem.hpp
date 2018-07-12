#ifndef INVOP_1E_PROBLEM_HPP
#define INVOP_1E_PROBLEM_HPP

#include<vector>

#include<ilcplex/cplexx.h>


struct Problem
{
	int N;  							//number of clients (including depot)
	double K;  						//vehicle capacity
	int schedules;				//number of schedules
	int depots;						//number of depots
	int every_day;				//number of clients who must be visited every day
	int every_other_day;	//number of clients who must be visited every day
	std::vector<std::vector<double>> costs;
	std::vector<double> demands;

	Problem();
	explicit Problem(int n);
};

/*struct lazy_constrain_info
{
	CPXLPptr lp;
	Problem* prob;

	lazy_constrain_info(CPXLPptr lp, Problem* prob);
};

static int CPXPUBLIC subtour_constraint_generator(CPXCENVptr env, void* cbdata, int wherefrom, void* cbhandle, int* useraction_p);*/

int initialize_structures(CPXENVptr& env, CPXLPptr& lp);
void free_structures(CPXENVptr env, CPXLPptr lp);
int set_parameters(CPXENVptr env);
int edge_var_number(const Problem* prob, int schedule, int from, int to);
int initialize_mip(Problem* prob, CPXENVptr env, CPXLPptr lp);
double solve(Problem* prob, std::vector<std::vector<int>>& schedules);

#endif //INVOP_PROBLEM_HPP
