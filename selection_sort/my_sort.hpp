template <typename T>
void my_selection_sort(T begin, T end) 
{
    for (T i = begin; i != end; ++i)
    {
        T pivot = i;
        for (T j = i; j != end; j++)
            if (*j < *pivot) pivot = j;
        auto tmp = *i;
        *i = *pivot;
        *pivot = tmp;
    }
}