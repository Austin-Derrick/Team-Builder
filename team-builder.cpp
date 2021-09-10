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

class worker : public IWork {
	string name;
	string position;
public:
	worker() = delete;
	worker(const char* n, const char* p) : name(n), position(p) {}
	virtual ~worker() {}
	virtual const char* get_name() override
	{ return this->name.c_str(); }
	virtual const char* get_position() override
	{ return this->position.c_str(); }
	virtual void do_work() override { cout << "Works" << endl; }
};

class manager : public worker, public IManage {
	vector<unique_ptr<IWork>> team;
public:
	manager() = delete;
	manager(const char* n, const char* p) : worker(n, p) {}
	const vector<unique_ptr<IWork>>& get_team() { return team; }
	virtual void manage_team() override { cout << "manages a team" << endl; }
	virtual void do_work() override { this->manage_team(); }
};

int main(int argc, const char* argv[]) 
{
	return 0;
}