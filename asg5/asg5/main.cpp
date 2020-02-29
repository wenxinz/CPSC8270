#include <iostream>
#include <string>
#include "includes/symbolTable.h"
#include "includes/poolOfNodes.h"

extern int yyparse();
extern void init_scanner(FILE *);

static FILE * 
open_file(const char *filename) {
  FILE *file = fopen(filename, "r");
  if (!file) {
    fprintf(stderr, "Could not open file \"%s\"\n", filename);
    exit(EXIT_FAILURE);
  }
  return file;
}


int main(int argc, char * argv[]) {
  FILE *input_file = stdin;
  if (argc > 1) { /* user-supplied filename */
    input_file = open_file(argv[1]);
  }
  init_scanner(input_file);
//  yydebug = 0;  /* Change to 1 if you want debugging */
  try{
    yyparse(); 
  }
  catch ( const std::string& msg) {
    std::cout << "oops: " << msg << std::endl;
  }
  catch (...){
    std::cout << "uncatched" << std::endl;
  }
  PoolOfNodes::getInstance().drainThePool();
  fclose(input_file);
}

