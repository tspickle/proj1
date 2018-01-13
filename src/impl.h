
enum {FALSE=0, TRUE};

int array_len(char **a);
int array_cmp(char **a, char **b);
int array_copy(char **dst, char **src, int max_size, int check_after);
void array_element_swap(char **a, char **b);
void array_sort(char **a, int nel);
void array_sort2(char **a, int nel);
