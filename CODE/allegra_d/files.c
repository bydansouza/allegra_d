#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <unistd.h>

#include"files.h"

static const struct option long_options[] =
{
    { "list", required_argument, NULL, 'l'},
    { "help", no_argument, NULL, 'h'},
    { NULL, no_argument, NULL, 0}
};

static char* input_file = NULL;

static void usage(void)
{
    puts("Exemplo de aplicacao BSort");
    puts("Usage:");
    puts("\t\t-l (--list) <text file>");
    puts("--------------------------------");

    exit(EXIT_FAILURE);
}

static int command(int argc, char** argv)
{
    int c;

    while (1) {
        int option_index = 0;

        c = getopt_long(argc, argv, "m:x:h", long_options, &option_index);

        /* Detect the end of the options. */
        if (c == -1) {
            break;
        }

        switch (c) {
        case 0:
            usage();
            break;
            //input_file = (char*) strdup(optarg);
        case 'l':
            if (input_file == NULL){
                input_file = (char*)strdup(optarg);
            }
	    else{
	      puts("ABORT: Input file defined twice");
	      exit(EXIT_FAILURE);
	    }

            break;
        case 'h':
            usage();
            exit(0);
        }
    }

    if (!input_file) {
        printf("ABORT: Undefined input file\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}
