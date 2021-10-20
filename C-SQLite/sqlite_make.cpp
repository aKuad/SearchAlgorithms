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
#define NAME_DB "data.db"
#define NAME_TB "data"
#define NAME_TX "../data.txt"


/* main function */
int main() {
  // Variables declarations
  sqlite3 *db;
  fstream ifs;
  system_clock::time_point t_st, t_ed;
  int res, id;
  char *err;
  char value[8];
  char query[64];

  // Database making
  //// Database connect
  system(((string)"echo -n > " + NAME_DB).c_str()); // Exist file removing
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
  while(ifs >> id >> value) {
    sprintf(query, "insert into %s values (%d, '%s');", NAME_TB, id, value);
    sqlite3_exec(db, query, NULL, NULL, &err);
  }
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
