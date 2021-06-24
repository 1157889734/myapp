



int mpi_test()
{
	
	
	
	
}

int main(int argc, char **argv)
{
    int ret = 0;

    (void)argc;
    (void)argv;

    mpp_env_set_u32("mpi_debug", 0x1);

    ret = mpi_test();

    mpp_env_set_u32("mpi_debug", 0x0);
    return ret;
}
