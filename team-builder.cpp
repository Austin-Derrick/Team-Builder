#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <memory>

using namespace std;

#define interface struct
interface IWork {
	virtual const char* get_name() = 0;
	virtual const char* get_position() = 0;
	virtual void do_work() = 0;
};

interface IManage {
	virtual const vector<unique_ptr<IWork>>& get_team() = 0;
	virtual void manage_team() = 0;
};

interface IDevelop {
	virtual void write_code() = 0;
};

int main(int argc, const char* argv[]) 
{
	return 0;
}