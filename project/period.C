
#include <cstdlib>
#include <math.h>

extern "C"
int compute_period_index(int n, int T_0, double* b, double alpha)
{
    int i, j, k, a;
    double *min_array, *sum_array;
    double sum, min;
    int DEFAULT = 9999;
    int i_min;
    
    min_array = (double*) malloc((n - T_0) * sizeof(double));
    for (i = T_0; i < n; ++i)
    {
        sum_array = (double*) malloc(i * sizeof(double));
        for (j = 0; j < i; ++j)
        {
            k = j;
            a = 1;
            sum = 0;
            while (k <= n)
            {
                sum += b[k]/pow(floor(n/i), alpha);
                k = j + a * i;
                ++a;
            }
            sum_array[j] = sum;
        }
        min = sum_array[0];
        for (j = 1; j < i; ++j)
            if (sum_array[j] < min)
                min = sum_array[j];
        if (i == 0)
            min_array[i] = DEFAULT;
        else
            min_array[i - T_0] = min;
        free(sum_array);
    }
    i_min = T_0;
    for (i = T_0 + 1; i < n; ++i)
        if (min_array[i - T_0] < min_array[i_min - T_0])
            i_min = i;
            
    return i_min;
}

