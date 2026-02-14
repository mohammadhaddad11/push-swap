/* int parse_bench(char **argv)
{

	if (argv[1] == "--bench")
		return (1);
	return (0);
}

int	parse_flags(char **argv)
{
	int	mode;

	mode = 1;
	if (argv[1] == "--adaptive" || argv[2] == "--adaptive" )
		mode = 2;
	else if (argv[1] == "--simple" || argv[2] == "--simple" )
		mode = 3;
	else if (argv[1] == "--medium" || argv[2] == "--medium" )
		mode = 4;
	else if (argv[1] == "--complex" || argv[2] == "--complex" )
		mode = 5;

	if (parse_bench(argv))
		mode = -mode;
	return (mode);
}
void parse_numbers()
{

}
void build_stack(){}
void error_exit(){} */