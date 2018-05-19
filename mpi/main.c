#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <mpi.h>

using namespace std;

bool is_prime(int n)
{
	assert(n % 2);
	bool ret = true;
	int f = floor(sqrt(n));
	for (int i = 3; i <= f; i += 2)
	{
		if (!(n % i))
		{
			ret = false;
			break;
		}
	}
	//cout << n << ": " << ret << endl;
	return ret;
}

int count_primes(int N, int rank, int proc_num)
{
	int count = 0;
	for (int i = 2 * rank + 3; i <= N; i += 2 * proc_num)
	{
		//cout << i << endl;
		if (is_prime(i))
		{
			count++;
		}
	}
	return count;
}

void MPI_prepare(int argc, char * argv[], int * prank, int * pproc_num)
{
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, pproc_num);
	MPI_Comm_rank(MPI_COMM_WORLD, prank);
}

int main(int argc, char * argv[])
{
	/** Parse Arguments
	 */
	// Check number of arguments
	if (argc != 2)
	{
		cout << "Usage: " << argv[0] << " N" << endl;
		return -1;
	}
	// Warning: no format check
	int N = atoi(argv[1]);

	// MPI Initialization
	int rank, proc_num;
	MPI_prepare(argc, argv, &rank, &proc_num);

	//cout << "Proc: " << rank << '/' << proc_num << endl;

	double start;
	int count;
	if (!rank)
	{
		start = MPI_Wtime();
	}

	int stepcount = count_primes(N, rank, proc_num);
	MPI_Reduce(&stepcount, &count, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	count++;	// Prime: 2

	if (!rank)
	{
		double end = MPI_Wtime();
		cout << "Number: " << N << endl;
		cout << "Number of primes: " << count << endl;
		cout << "Time cost: " << end-start << endl;
	}

	MPI_Finalize();

	return 0;
}
