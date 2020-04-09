eSystemState initialZerohandler(void)
{
    printf("%50s","\n initialZerohandler:\t A#   B    Final");
    return INITIAL_STATE;
}
eSystemState initialOnehandler(void)
{
    printf("\n initialOnehandler:\t  A--->---B    Final");
    return INTERMEDIATE_STATE;
}

eSystemState intermediateZerohandler(void)
{
  printf("%50s","\n intermediateZerohandler:\t  A---<---B   Final");
    return INITIAL_STATE;
}
eSystemState intermediateOnehandler(void)
{
    printf("\n intermediateOnehandler:\t  A    B--->---Final");
    return FINAL_STATE;
}

eSystemState finalZerohandler(void)
{
  printf("\n  finalZerohandler:\t  Final--->---A     B");
    return INITIAL_STATE;
}
eSystemState finalOnehandler(void)
{
  printf("\n  finalOnehandler :\t  A     B     Final#");
    return FINAL_STATE;
}
