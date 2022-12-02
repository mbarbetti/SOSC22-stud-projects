
            #include <math.h>

            extern "C"
            void best_matching_period (int n, double alpha, double* lumi, int* best_period, double* min_score) {
                int i, j, k;
                double score;
                
                for (i = 100; i < n/2; ++i)
                    for (j = 1; j < i; ++j) {
                        score = 0;
                        for (k = j; k < n; k+= i) score += lumi[k];
                        score /= pow(n/i, alpha);
                        
                        if (score < *min_score) {
                            *min_score = score;
                            *best_period = i;
                        }
                    }
            }
            
