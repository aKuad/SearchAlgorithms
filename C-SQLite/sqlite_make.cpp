/**
 * sqlite_make.cpp
 *
 * Author: aKuad
 *
 * Published with CC0 license
 */

/* Headers including */
#include <iostream>
#include <fstream>
#include <chrono>
#include <sqlite3.h>

using namespace std;
using namespace std::chrono;


/* Parameters settings */
#define NAME_DB argv[2]
#define NAME_TB "data"
#define NAME_TX argv[1]


/* main function */
int main(int argc, char *argv[]) {
  // Variables declarations
  sqlite3 *db;
  fstream ifs;
  system_clock::time_point t_st, t_ed;
  int res, id;
  char *err;
  char value[8];
  char query[64];

  // Argument checking
  if(argc != 3) {
    cerr << "Invalid arguments." << endl;
    cerr << "  Useage:" << endl;
    cerr << "    " << argv[0] << " <Input data file> <Output data file>" << endl;
    exit(EXIT_FAILURE);
  }

  // Database making
  //// Database connect
  sprintf(query, "echo -n > %s", NAME_DB);
  if(system(query)) { // Exist file removing
    cerr << "Database clear failed." << endl;
    exit(EXIT_FAILURE);
  }
  res = sqlite3_open_v2(NAME_DB, &db, SQLITE_OPEN_CREATE | SQLITE_OPEN_READWRITE, NULL);
  if(res != SQLITE_OK) {
    fprintf(stderr, "Failed to open a database.");
    exit(EXIT_FAILURE);
  }
  //// Timer start
  t_st = system_clock::now();
  //// Table make
  sprintf(query, "create table %s (id int, name char(6));", NAME_TB);
  sqlite3_exec(db, query, NULL, NULL, &err);
  //// Data inserting
  ifs.open(NAME_TX);
  sqlite3_exec(db, "begin", NULL, NULL, &err);
  while(ifs >> id >> value) {
    sprintf(query, "insert into %s values (%d, '%s');", NAME_TB, id, value);
    sqlite3_exec(db, query, NULL, NULL, &err);
  }
  sqlite3_exec(db, "commit", NULL, NULL, &err);
  ifs.close();
  //// Timer stop
  t_ed = system_clock::now();
  //// Database disconnect
  sqlite3_close_v2(db);

  // Process time printing
  cout << duration_cast<microseconds>(t_ed - t_st).count() << endl;

  // Quit
  return 0;
}
