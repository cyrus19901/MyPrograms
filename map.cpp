#include <iostream>
#include <map>
using namespace std;

int main(){
	map<int,string> name_map;
	name_map[1]="hello";
	name_map[2]="hello-----";
	name_map[3]="hello111111";
	name_map.clear();
	cout << "the size is "<< name_map.size()<<endl;
	name_map.insert(pair<int, string>(4,"blow---------"));
	name_map.insert(pair<int, string>(5,"blow3"));
	for (map<int,string>::iterator itr = name_map.begin(); itr!=name_map.end();itr++){
		cout << itr->first << "\n" << itr->second;
	}
	return 0;
}