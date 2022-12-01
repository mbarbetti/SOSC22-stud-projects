

extern "C"
int c_count(int len, double* array, double threshold)
{
    int i;
    int counter = 0;
    
    for (i = 0; i < len; ++i)
        if (array[i] > threshold)
            counter ++;
            
    return counter;
}

