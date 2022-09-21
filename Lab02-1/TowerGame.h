#include <string>
#include "StackQueue.h"

using namespace std;

class Tower
{
public:
    //creating tower
    Tower();
    ~Tower();

    //Game Functions
    bool Move();
    bool Win();
    bool CollectInput(string disk,string from,string to);
    bool RunTurn();
    
    ArrayBasedQueue MoveHistory;
    ArrayBasedStack Tower1;
    ArrayBasedStack Tower2;
    ArrayBasedStack Tower3;
    string *disk;
    string *from;
    string *to;

private:
};