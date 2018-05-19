#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <sys/time.h>
#include <vector>

using namespace std;

int count_primes(int n, int thread_num)
{
    vector<bool> nums(n, true);
    int count = 0;

    for(int i = 2; i < n; ++i)
	{
        if(nums[i])
		{
            ++count;

			int j;
			int f = floor((double)n / i);
			#pragma omp parallel for num_threads(thread_num)
            for (j = 2; j <= f; ++j) {
                nums[i * j] = false;
            }
        }
    }
    return count;
}

int main(int argc, char * argv[])
{
	/** Parse Arguments
	 */
	// Check number of arguments
	if (argc != 3)
	{
		cout << "Usage: " << argv[0] << " N thread_num" << endl;
		return -1;
	}
	// Warning: no format check
	int N = atoi(argv[1]);
	int thread_num = atoi(argv[2]);

	//clock_t start, end;	// Deprecated
	struct timespec start, end;

	//start = clock();
	clock_gettime(CLOCK_MONOTONIC, &start);
	int count = count_primes(N, thread_num);
	//end = clock();
	clock_gettime(CLOCK_MONOTONIC, &end);

	cout << "Number: " << N << endl;
	cout << "Number of primes: " << count << endl;
	//cout << "Time cost: " << (double)(end - start)/CLOCKS_PER_SEC << endl;
	cout << "Time cost: " << (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec)/1000000000 << endl;

	return 0;
}
