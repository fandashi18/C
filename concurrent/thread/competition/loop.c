int main(int argc, char const *argv[])
{
    volatile int count = 0;
    for (int i = 0; i < 10000; i++)
    {
        count++;
    }

    return 0;
}
