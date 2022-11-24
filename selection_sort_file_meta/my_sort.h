// Change me instead
// All occurences of XXX need to be replaced with
// something more meaningful


template<typename T, class Comp>
void my_selection_sort( T begin, T end, Comp comp) {
    for (T i = begin; i != end; ++i)
    {
        T min = i;
        for (T j = i; j != end; ++j)
        {
            if (comp(*j, *min))
                min = j;
        }
        auto tmp = *i;
        *i = *min;
        *min = tmp;
    }
}
