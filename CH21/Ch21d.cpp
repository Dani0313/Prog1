#include "std_lib_facilities.h"

struct Item{
	string name;
	int iid;
	double value;

	Item() :name(), iid(0), value(0) { }
    Item(string n, int i, double v) :name(n), iid(i), value(v) { }
};
istream& operator>>(istream& is, Item& it)
{
    string name;
    int iid;
    double value;
    is >> name >> iid >> value;
    if (!is) return is;
    it = Item(name,iid,value);
    return is;
}

ostream& operator<<(ostream& os, const Item& it)
{
    return os << it.name << '\t' << it.iid << '\t' << it.value;
}

	struct Cmp_by_name {
		bool operator()(const Item& a, const Item& b) const
		{ return a.name < b.name; }
};

	struct Cmp_by_iid{
		bool operator()(const Item& a, const Item& b) const
		{ return a.iid < b.iid; }
};

	struct Cmp_by_value{
		bool operator()(const Item& a, const Item& b) const
		{ return a.value < b.value; }
};
void beOlvas(string fileName, vector<Item> vector){

	    ifstream ifs(fileName.c_str());
        if (!ifs) error("can't open ",fileName);
        Item i;
        while (ifs>>i) vector.insert(vector.end(),i);

        cout << "Content of lista.txt (vector)" << endl;
        for(int i = 0; i< vector.size(); i++){
			cout <<  vector[i] << endl;
	}

	Item i1{"horse shoe",99,12.34};
	Item i2{"Canon S400",9988,499.95};
	vector.push_back(i1);
	vector.push_back(i2);

	cout << " " << endl;
	cout << "Sorted by name" << endl;
	sort(vector.begin(),vector.end(),Cmp_by_name());
	for(int i = 0;i<vector.size();i++)
		cout << vector[i] << endl;

	cout << " " << endl;
	cout << "Sorted by iid" << endl;
	sort(vector.begin(),vector.end(),Cmp_by_iid());
	for(int i = 0;i<vector.size();i++)
		cout << vector[i] << endl;

	cout << " " << endl;
	cout << "Sorted by value" << endl;
	sort(vector.begin(),vector.end(),Cmp_by_value());
	for(int i = 0;i<vector.size();i++)
		cout << vector[i] << endl;


	cout << " " << endl;
	cout << "Sorted by value DESC" << endl;
	for(int i = vector.size()-1;i>-1;i--)
		cout << vector[i] << endl;
	cout << " " << endl;
}

void beOlvasLista(string fileName, list<Item> itemList){

	Item i1{"horse shoe",99,12.34};
	Item i2{"Canon S400",9988,499.95};
	itemList.push_back(i1);
	itemList.push_back(i2);

	ifstream ifs(fileName.c_str());
    if (!ifs) error("can't open ",fileName);
    Item i;
    while (ifs>>i) itemList.push_back(i);

    cout << "Content of lista.txt (list)" << endl;
    for(Item &i : itemList){
    	cout << i << endl;
    }

    cout << " " << endl;
    cout << "Sorted by name" << endl;
    itemList.sort(Cmp_by_name());
	 for(Item &i : itemList){
    	cout << i << endl;
    }

        cout << " " << endl;
    cout << "Sorted by iid" << endl;
    itemList.sort(Cmp_by_iid());
	 for(Item &i : itemList){
    	cout << i << endl;
    }

        cout << " " << endl;
    cout << "Sorted by value" << endl;
    itemList.sort(Cmp_by_value());
	 for(Item &i : itemList){
    	cout << i << endl;
    }


}

void beOlvasMap(){
	map<string,int> msi;
	String name;
	int value;
	cout << "to end the loop name the next item 'x' and set its value to 0" << endl;
	while(cin){
		cin >> name >> value;
		msi.insert({name,value});
		if(name == "x" || value == 0)
			break;

	}
	cout << " " << endl;
	cout << "Content of map msi" << endl;
		for(const auto& p : msi){
		cout << p.first << "\t" << p.second << endl;
	}
			cout << " " << endl;
		int sum = 0;
	for(const auto& p : msi){
		sum += p.second;
	}
	cout << "SUM of entered values: "  << sum << endl;


	map<int,string> mis;

	for(const auto& p : msi){
		mis.insert({p.second, p.first});
	}

	cout << " " << endl;
	cout << "Content of map mis" << endl;
	for(const auto& p : mis){
		cout << p.first << "\t" << p.second << endl;
	}
}


int main(){

	vector<Item> vi;
	beOlvas("lista.txt",vi);	

	list<Item> li;
	beOlvasLista("lista.txt", li);

	beOlvasMap();

}