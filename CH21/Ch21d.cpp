#include "std_lib_facilities.h"

//g++ Ch21d.cpp -o drill21


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

	struct cName {
		bool operator()(const Item& a, const Item& b) const
		{ return a.name < b.name; }
};

	struct cIid{
		bool operator()(const Item& a, const Item& b) const
		{ return a.iid < b.iid; }
};

	struct cValue{
		bool operator()(const Item& a, const Item& b) const
		{ return a.value < b.value; }

};
	struct fName {
    string name;
public:
    fName(const string& s) :name(s) { }
    bool operator()(const Item& it) const
    {
        return it.name == name;
    }
};

	struct fIid {
		int iid;
public:
	fIid(int i) :iid(i) { }
	bool operator()(const Item& it) const
	{
		return it.iid == iid;
	}

};
void beOlvas(string fileName){

		vector<Item> vi;
	    ifstream ifs(fileName.c_str());
        if (!ifs) error("can't open ",fileName);
        Item i;
        while (ifs>>i) vi.insert(vi.end(),i);

        cout << "Content of lista.txt (vector)" << endl;
        for(int i = 0; i< vi.size(); i++){
			cout <<  vi[i] << endl;
	}

	Item i1{"horse shoe",99,12.34};
	Item i2{"Canon S400",9988,499.95};
	vi.push_back(i1);
	vi.push_back(i2);

	cout << " " << endl;
	cout << "Sorted by name" << endl;
	sort(vi.begin(),vi.end(),cName());
	for(int i = 0;i<vi.size();i++)
		cout << vi[i] << endl;

	cout << " " << endl;
	cout << "Sorted by iid" << endl;
	sort(vi.begin(),vi.end(),cIid());
	for(int i = 0;i<vi.size();i++)
		cout << vi[i] << endl;

	cout << " " << endl;
	cout << "Sorted by value" << endl;
	sort(vi.begin(),vi.end(),cValue());
	for(int i = 0;i<vi.size();i++)
		cout << vi[i] << endl;

	cout << " " << endl;
	cout << "Sorted by value DESC" << endl;
	for(int i = vi.size()-1;i>-1;i--)
		cout << vi[i] << endl;
	cout << " " << endl;

	cout << "Remove 2 items identified by name" << endl;
	vector<Item>::iterator vi_it =
        find_if(vi.begin(),vi.end(),fName("school"));
    vi.erase(vi_it);
    vi_it = find_if(vi.begin(),vi.end(),fName("computer"));
    vi.erase(vi_it);
    for(int i = 0;i<vi.size();i++)
		cout << vi[i] << endl;
	cout << " " << endl;

	cout << "Remove 2 items identified by iid" << endl;
    vi_it = find_if(vi.begin(),vi.end(),fIid(4632));
    vi.erase(vi_it);
    vi_it = find_if(vi.begin(),vi.end(),fIid(345));
    vi.erase(vi_it);
    for(int i = 0;i<vi.size();i++)
		cout << vi[i] << endl;
	cout << " " << endl;
}

void beOlvasLista(string fileName){

	list<Item> li;

	ifstream ifs(fileName.c_str());
    if (!ifs) error("can't open ",fileName);
    Item i;
    while (ifs>>i) li.push_back(i);

    Item i1{"horse shoe",99,12.34};
	Item i2{"Canon S400",9988,499.95};
	li.push_back(i1);
	li.push_back(i2);

    cout << "Content of lista.txt (list)" << endl;
    for(Item &i : li){
    	cout << i << endl;
    }

    cout << " " << endl;
    cout << "Sorted by name" << endl;
    li.sort(cName());
	 for(Item &i : li){
    	cout << i << endl;
    }

        cout << " " << endl;
    cout << "Sorted by iid" << endl;
    li.sort(cIid());
	 for(Item &i : li){
    	cout << i << endl;
    }

        cout << " " << endl;
    cout << "Sorted by value" << endl;
    li.sort(cValue());
	 for(Item &i : li){
    	cout << i << endl;
    }
    cout << " " << endl;

    cout << "Sorted by value DESC" << endl;
   li.reverse();
   	 for(Item &i : li){
    	cout << i << endl;
    }
    cout << " " << endl;

    cout << "Remove 2 items identified by name" << endl;
    list<Item>::iterator li_it =
        find_if(li.begin(),li.end(),fName("computer"));
    li.erase(li_it);
    li_it = find_if(li.begin(),li.end(),fName("school"));
    li.erase(li_it);
    for(Item &i : li){
    	cout << i << endl;
    }
    cout << " " << endl;
/*
    cout << "Remove 2 items identified by iid" << endl;
    li_it = find_if(li.begin(),li.end(),fIid(4632));
    li.erase(li_it);
    li_it = find_if(li.begin(),li.end(),fIid(345));
    li.erase(li_it);
    for(Item &i : li){
    	cout << i << endl;
    }
    cout << " " << endl;
    */
}

void beOlvasMap(){
	map<string,int> msi;
	String name;
	int value;
	cout << "Enter value pairs (string, int)" << endl;
	int db = 0;
	while(cin){
		cin >> name >> value;
		msi.insert({name,value});
		db++;
		if(name == "x" || value == 0)
			break;
		if(db == 10)
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
	cout << " " << endl;
}


void floatBe(string fileName){
	ifstream ifs(fileName.c_str());
	if(!ifs) error ("can't open " , fileName);
	vector<double> vd;
	double d;
	while(ifs >> d) vd.push_back(d);

	cout << "Content of vd" << endl;
	for(int i = 0;i<vd.size();i++)
		cout << vd[i] << endl;
	cout << " " << endl;

	vector<int> vi(vd.size());
	copy(vd.begin(),vd.end(),vi.begin());


	cout << "pairs" << endl;
	for(int i = 0;i<vd.size();i++)
		cout << vd[i] << " , " << vi[i] << endl;
	cout << " " << endl;

	double sumVd = 0;
	int sumVi = 0;
	for(int i = 0;i<vd.size();i++){
		sumVd += vd[i];
		sumVi += vi[i];
	}
		cout << "sum of vd: " << sumVd << endl;
//		cout << "sum of vi: " << sumVi << endl;
	cout << " " << endl;

		cout << "diff of sumVd and sumVi: " << sumVd - sumVi << endl;
		cout << " " << endl;

		reverse(vd.begin(),vd.end());
		for(int i = 0;i<vd.size();i++)
			cout << vd[i] << endl;
		cout << " " << endl;

		double mean = (sumVd / vd.size());
		cout << "mean of vd: " << mean << endl;
		cout << " " << endl;

		vector<double> vd2;
		for(int i = 0;i<vd.size();i++){
		if(vd[i] < mean)
			vd2.push_back(vd[i]);
	}
	cout << "content of vd2 " << endl;
	for(int i = 0;i<vd2.size();i++)
			cout << vd2[i] << endl;
		cout << " " << endl;

		sort(vd.begin(),vd.end());
		for(int i = 0;i<vd.size();i++)
			cout << vd[i] << endl;
		cout << " " << endl;
}


int main(){

	beOlvas("lista.txt");	

	beOlvasLista("lista.txt");

	beOlvasMap();

	floatBe("doubles.txt");

}