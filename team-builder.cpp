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
	virtual void add_team_member(IWork* worker) 
		{ team.push_back(unique_ptr<IWork>(worker)); }
	virtual void do_work() override { this->manage_team(); }
};

class project_manger : public manager
{
public:
	project_manageR() = delete;
	project_manager(const char* n) : manager(n, "Project Manager") {}
	virtual void manage_team() override { cout << "manages a team of developers" << endl; }
};

void print_team(IWork* mgr)
{
	cout << mgr->get_name() << " is "
		<< mgr->get_position() << " and ";
	IManage* manager = dynamic_cast<IManage*>(mgr);
	if (manager != nullptr)
	{
		cout << "manages a team of: " << endl;
		for (auto team_member : manager->get_team())
		{
			cout << team_member->get_name() << " "
				<< team_member->get_position() << endl;
		}
	}
	else { cout << "is not a manager" << endl; }
}

int main(int argc, const char* argv[]) 
{
	return 0;
}