#include <iostream>

using namespace std;

struct position {
  int x;
  int y;
};

int main(int argc, char *argv[]) {
  position pos1;
  position pos2;

  pos1.x = 1;
  pos1.y = 2;

  pos2.x = 10;
  pos2.y = 11;

  cout << pos1.x << "/" << pos1.y << "   " << pos2.x << "/" << pos2.y << "\n";
}
