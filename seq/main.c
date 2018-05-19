#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sys/time.h>
#include <vector>

using namespace std;

int count_primes(int n)
{
    vector<bool> nums(n, true);
    int count = 0;
    for(int i = 2; i < n; ++i) {
        if(nums[i]) {
            ++count;
            for(int j = 2; i * j <= n; ++j) {
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
	if (argc != 2)
	{
		cout << "Usage: " << argv[0] << " N" << endl;
		return -1;
	}
	// Warning: no format check
	int N = atoi(argv[1]);

	struct timespec start, end;
	//clock_t start, end;

	clock_gettime(CLOCK_MONOTONIC, &start);
	//start = clock();
	int count = count_primes(N);
	//end = clock();
	clock_gettime(CLOCK_MONOTONIC, &end);

	cout << "Number: " << N << endl;
	cout << "Number of primes: " << count << endl;
	//cout << "Time cost: " << (double)(end - start)/CLOCKS_PER_SEC << endl;
	cout << "Time cost: " << (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec)/1000000000 << endl;

	return 0;
}
