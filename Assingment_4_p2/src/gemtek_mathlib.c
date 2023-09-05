float cube(float x)
{
    return x * x * x;
}

float square(float x)
{
    return x * x;
}

int is_fibonacci(float n)
{
    int pre_num = 0;
    int cur_num = 1;
    if (n == pre_num || n == cur_num) {
        return 1;
    } 

    int next_num = pre_num + cur_num;
    while(next_num <= n) {
        if(next_num == n) return 1;
        pre_num = cur_num;
        cur_num = next_num;
        next_num = pre_num + cur_num;
    }

    return 0;
}
