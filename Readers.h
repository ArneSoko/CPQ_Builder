#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <fstream>
#include "CPQ_base.h"

using namespace std;

int detectFileContent(string filename);

Cart readCart(string filename);
Item readItem(string filename);