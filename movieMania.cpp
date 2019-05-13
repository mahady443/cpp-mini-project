#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
#include<sstream>
#include<stdlib.h>
#include<windows.h>
using namespace std;
class details
{
public:
	int count;
	string movie;
	string lang;
	string year;
	string hero;
	string heroin;
	string director;
	string desc;
	string duration;
	string buffer;
	string buffer1;
	//string buffer2;
	string movie_list[100];
	string movieu_list[100];
	int add_list[100];
	int up_list[100];
	string ratings;
	string awardswon;
	//int a[20], hyr[20], hpos[20];
	void read();
	void read1();
	void write();
	void write1();
	void pack();
	void pack1();
	void unpack();
	void unpack1();
	void display();
	void display1();
	string extract_moviename();
	string extract_moviename1();
	void createindex();
	void createindex1();
	void sortindex();
	void sortindex1();
	int searchindex(string);
	void search(string);
	int searchindex1(string);
	void search1(string);
	string compress(string);
	string decompress(string);
	//int create_hashkey(int yr);
	//void create_hashtable();
	//void create_hashtable1();
	string extract_yr();
	void display2(int[]);
	void findhash(int);
	void initial_yearlist();
	void yearlist(string, string);
	void searchyear(string);
	void searchhero(string);
	void searchheroin(string);
	string extract_hero();
	void searchdirector(string);
	string extract_director();
	string extract_heroin();
};
void details::searchyear(string yr)
{
	fstream f1;
	int pos;
	f1.open("moviedetails1.txt");
	while (!f1.eof())
	{
		getline(f1, buffer);
		year = extract_yr();
		if (year == yr)
		{
			movie = extract_moviename();
			cout << movie << endl;
		}
	}
	f1.close();
}
void details::searchhero(string he)
{
	fstream f1;
	int pos;
	f1.open("moviedetails1.txt");
	while (!f1.eof())
	{
		getline(f1, buffer);
		hero = extract_hero();
		if (hero == he)
		{
			movie = extract_moviename();
			cout << movie << endl;
		}
	}
	f1.close();
}
string details::extract_hero()
{
	string hero;
	int i = 0;
	hero.erase();
	while (buffer[i] != '|')
		i++;
	i++;
	while (buffer[i] != '|')
		i++;
	i++;
	while (buffer[i] != '|')
		i++;
	i++;
	while (buffer[i] != '|')
		hero += buffer[i++];
	return hero;
}
void details::searchheroin(string he)
{
	fstream f1;
	int pos;
	f1.open("moviedetails1.txt");
	while (!f1.eof())
	{
		getline(f1, buffer);
		heroin = extract_heroin();
		if (heroin == he)
		{
			movie = extract_moviename();
			cout << movie << endl;
		}
	}
	f1.close();
}
string details::extract_heroin()
{
	string heroin;
	int i = 0;
	heroin.erase();
	while (buffer[i] != '|')
		i++;
	i++;
	while (buffer[i] != '|')
		i++;
	i++;
	while (buffer[i] != '|')
		i++;
	i++;
	while (buffer[i] != '|')
		i++;
	i++;
	while (buffer[i] != '|')
		heroin += buffer[i++];
	return heroin;
}
void details::searchdirector(string dir)
{
	fstream f1;
	int pos;
	f1.open("moviedetails1.txt");
	while (!f1.eof())
	{
		getline(f1, buffer);
		director = extract_director();
		if (director == dir)
		{
			movie = extract_moviename();
			cout << movie << endl;
		}
	}
	f1.close();
}
string details::extract_director()
{
	string director;
	int i = 0;
	director.erase();
	while (buffer[i] != '|')
		i++;
	i++;
	while (buffer[i] != '|')
		i++;
	i++;
	while (buffer[i] != '|')
		i++;
	i++;
	while (buffer[i] != '|')
		i++;
	i++;
	while (buffer[i] != '|')
		i++;
	i++;
	while (buffer[i] != '|')
		director += buffer[i++];
	return director;
}
string details::extract_yr()
{
	string year;
	int i = 0;
	year.erase();
	if (!buffer.empty())
	{
		while (buffer[i] != '|')
			i++;
		i++;
		while (buffer[i] != '|')
			i++;
		i++;
		while (buffer[i] != '|')
			year += buffer[i++];
	}
	return year;
}
/*int details::create_hashkey(int yr)
{
	int hkey = yr % 100;
	return hkey;
}
void details::create_hashtable()
{
	for (int i = 0; i<20; i++)
	{
		a[i] = -1;
		hpos[i] = -1;
		hyr[i] = -1;
	}

}
void details::create_hashtable1()
{
	int key, hyr1, i = 0, j, pos, flag = 0;
	string yr;
	fstream f1, f2;
	f1.open("movielist.txt", ios::in);
	f2.open("hashfile.txt", ios::out);
	while (!f1.eof())
	{
		buffer.erase();
		pos = f1.tellg();
		cout << "pos" << pos << endl;
		getline(f1, buffer);
		cout << "buffer:" << buffer << endl;
		i = 0;
		if (!buffer.empty())
		{
			while (buffer[i] != '|')
			{
				yr[i] += buffer[i++];
				if (i >= buffer.size())
					break;
			}
		}
		cout << "yr" << yr << endl;
		hyr1 = atoi(yr.c_str());
		//hyr=2018;
		cout << "hyr" << hyr1 << endl;
		key = create_hashkey(hyr1);
		cout << "key" << key << endl;
		if (a[key] == -1 || a[key] == key)
		{
			a[key] = key;
			hyr[key] = hyr1;
			hpos[key] = pos;
			//cout<<obj[key].a<<"   "<<obj[key].hyr<<"    "<<obj[key].hpos[0];
		}
	}
	for (i = 0; i<20; i++)
	{
		f2 << a[i] << "|" << hyr[i] << "|" << hpos[i] << "$" << "\n";
	}
	f1.close();
	f2.close();

}
void details::findhash(int year)
{
	fstream f1;
	int i, pos;
	int key, flag = 0;
	key = create_hashkey(year);
	if (a[key] == key || hyr[key] == year)
	{
		f1.open("movielist.txt");
		f1.seekp(hpos[key], ios::beg);
		buffer2.erase();
		getline(f1, buffer2);
		//cout << buffer2;
		f1.close();
	}
}
void details::yearlist(string movie, string yr)
{
	int flag = 0, key, i, hyr1, pos;
	string buff, dest;
	fstream f1, f2;
	hyr1 = atoi(yr.c_str());
	key = create_hashkey(hyr1);
	//cout << "key:" << key;
	if (a[key] == key)
	{
		flag = 1;
		pos = hpos[key];
		f1.open("movielist.txt", ios::out | ios::app | ios::in);
		buff.erase();
		f1.seekp(pos, ios::beg);
		getline(f1, buff);
		cout << "buff:" << buff;
		i = 0;
		while (buff[i] != '$')
			dest += buff[i++];
		f1.seekp(pos, ios::beg);
		f1 << dest << "," << movie << "$" << "\n";
		f1.close();
	}
	else if (a[key] == -1)
	{
		flag = 1;
		f1.open("movielist.txt", ios::out | ios::app | ios::in);
		int pos = f1.tellp();
		f1 << yr << "|" << movie << "$" << "\n";
		f1.close();
		a[key] = key;
		hyr[key] = hyr1;
		hpos[key] = pos;
	}
	f2.open("hashfile.txt", ios::out);
	for (i = 0; i<20; i++)
	{
		f2 << a[i] << "|" << hyr[i] << "|" << hpos[i] << "$" << "\n";
	}
	f2.close();
}
void details::initial_yearlist()
{
	fstream f1, f2;
	int key, hyr1;
	string yr, dest, movie, buff;
	f1.open("movielist.txt", ios::out);
	f1.close();
	f2.open("moviedetails1.txt");
	f2.close();
	f1.open("movielist.txt", ios::out | ios::app | ios::in);
	f1.close();

	f2.open("moviedetails1.txt");
	f1.open("movielist.txt", ios::out | ios::app | ios::in);

	while (!f2.eof())
	{
		buffer.erase();
		getline(f2, buffer);
		if (buffer.empty())
			break;
		//cout << buffer << endl;
		yr = extract_yr();
		movie = extract_moviename();
		//cout << "yr" << yr << endl;
		hyr1 = atoi(yr.c_str());
		// cout<<"hyr"<<hyr<<endl;
		key = create_hashkey(hyr1);
		if (a[key] == -1)
		{
			//movie=extract_moviename();
			int pos = f1.tellg();
			f1 << yr << "|" << movie << "$" << "\n";
			//	f1.close();
			a[key] = key;
			hyr[key] = hyr1;
			hpos[key] = pos;
			//cout << key << "    " << a[key] << "   " << hyr[key] << "    " << hpos[key] << endl;
		}
		else if (a[key] == key)
		{
			int pos = hpos[key];
			//cout << "pos:" << pos << endl;
			//	f1.open("movielist.txt",ios::out|ios::app);
			buff.erase();
			f1.seekp(pos, ios::beg);
			getline(f1, buff);
			//cout << "buff:" << buff << endl;
			int i = 0;
			while (buff[i] != '$')
			{
				dest += buff[i++];
			}
			// cout<<"dest:"<<dest;
			f1.seekp(pos, ios::beg);
			f1 << dest << "," << movie << "$" << "\n";
			//f1.close();
		}
		//	for(int j=0;j<20;j++)
		//{
		//	cout<<hpos[j]<<endl;
		//}
	}
	f2.close();
	f1.close();
}
*/

void details::read()
{

	cout << "movie name:";
	cin >> movie;
	cout << "language:";
	cin >> lang;
	cout << "year:";
	cin >> year;
	cout << "hero:";
	cin >> hero;
	cout << "heroin:";
	cin >> heroin;
	cout << "director:";
	cin >> director;
	cout << "duration:";
	cin >> duration;
	cout << "desc:";

	cin >> desc;

}
void details::read1()
{
	cout << "ratings:";
	cin >> ratings;
	cout << "awards won:";
	cin >> awardswon;
}
void details::pack()
{
	string lan = compress(lang);
	buffer.erase();
	buffer = movie + "|" + lan + "|" + year + "|" + hero + "|" + heroin + "|" + director + "|" + duration + "|" + desc + " $ " + "\n";
}
void details::pack1()
{
	buffer1.erase();
	buffer1 = movie + "|" + awardswon + "|" + ratings + " $" + "\n";
}
void details::unpack()
{
	string lan;
	movie.erase();
	int i = 0;
	while (buffer[i] != '|')
	{
		movie += buffer[i];
		i++;
	}
	i++;
	while (buffer[i] != '|')
	{
		lan += buffer[i];
		i++;
	}
	lang = decompress(lan);
	i++;
	year.erase();
	while (buffer[i] != '|')
	{
		year += buffer[i++];
	}
	i++;
	hero.erase();
	while (buffer[i] != '|')
	{
		hero += buffer[i++];
	}
	i++;
	heroin.erase();
	while (buffer[i] != '|')
	{
		heroin += buffer[i++];
	}
	i++;
	director.erase();
	while (buffer[i] != '|')
	{
		director += buffer[i++];
	}
	i++;
	duration.erase();
	while (buffer[i] != '$')
	{
		duration += buffer[i++];
	}
	i++;
	while (buffer[i] != '$')
	{
		desc += buffer[i++];
		if (i >= buffer.size())
			break;
	}
}
void details::unpack1()
{
	int i = 0;
	while (buffer1[i] != '|')
	{
		movie += buffer1[i];
		i++;
	}
	i++;
	awardswon.erase();
	while (buffer1[i] != '|')
	{
		awardswon += buffer1[i++];
	}
	i++;
	ratings.erase();
	while (buffer1[i] != '$')
	{
		ratings += buffer1[i++];
	}
}
string details::compress(string lang)
{
	if ((lang == "kannada") || (lang == "KANNADA"))
		return "kan";
	else if ((lang == "hindi") || (lang == "HINDI"))
		return "hin";
	else if ((lang == "english") || (lang == "ENGLISH"))
		return "eng";
	else
		return "";
}
string details::decompress(string lan)
{
	if (lan == "kan")
		return "kannada";
	else if (lan == "hin")
		return "hindi";
	else if (lan == "eng")
		return "english";
	else
		return "";
}
void details::write()
{
	fstream file;
	fstream file2;
	file.open("moviedetails1.txt", ios::out | ios::app);
	int pos = file.tellp();
	file << buffer;
	file.close();
	movie_list[++count] = movie;
	add_list[count] = pos;
	file2.open("index.txt", ios::out | ios::app);
	file2 << movie << "|" << pos << "$" << "\n";
	file2.close();
	sortindex();
}
void details::write1()
{
	fstream file1;
	fstream file3;
	file1.open("movieupdate1.txt", ios::out | ios::app);
	int pos = file1.tellp();
	file1 << buffer1;
	file1.close();
	movieu_list[++count] = movie;
	up_list[count] = pos;
	file3.open("index1.txt", ios::out | ios::app);
	file3 << movie << "|" << pos << "$" << "\n";
	file3.close();
	sortindex1();
}
void details::display()
{
	unpack();
	//	cout<<"movie name:"<<movie<<endl;
	cout << "language:" << lang << endl;
	cout << "released year:" << year << endl;
	cout << "hero:" << hero << endl;
	cout << "heroin:" << heroin << endl;
	cout << "director:" << director << endl;
	cout << "duration:" << duration << endl;
	cout << "description:" << desc << endl;
}
void details::display1()
{
	unpack1();
	cout << "awards won:" << awardswon << endl;
	cout << "ratings(in stars):" << ratings << endl;
}
string details::extract_moviename()
{
	string movie;
	int i = 0;
	movie.erase();
	if (!buffer.empty())
	{
		while (buffer[i] != '|')
			movie += buffer[i++];
	}
	return movie;
}
string details::extract_moviename1()
{
	string movie;
	int i = 0;
	movie.erase();
	while (buffer1[i] != '|')
		movie += buffer1[i++];
	return movie;
}

void details::createindex()
{
	fstream file;
	fstream file2;
	int pos;
	string movie;
	count = -1;
	file.open("moviedetails1.txt", ios::in);
	while (!file.eof())
	{
		pos = file.tellg();
		buffer.erase();
		getline(file, buffer);
		if (buffer[0] != '*')
		{
			if (buffer.empty())break;
			movie = extract_moviename();
			movie_list[++count] = movie;
			add_list[count] = pos;
		}
	}
	file.close();
	sortindex();
	buffer.erase();
	file2.open("index.txt", ios::out);
	for (int i = 0; i <= count; i++)
	{
		file2 << movie_list[i] << "|" << add_list[i] << "$" << "\n";
		//		cout<<movie_list[i]<<"          "<<add_list[i]<<endl;
	}
	file2.close();
}
void details::createindex1()
{
	fstream file1;
	fstream file3;
	int pos;
	string movie;
	count = -1;
	file1.open("movieupdate1.txt", ios::in);
	while (!file1.eof())
	{
		pos = file1.tellg();
		buffer1.erase();
		getline(file1, buffer1);
		if (buffer1[0] != '*')
		{
			if (buffer1.empty())break;
			movie = extract_moviename1();
			movieu_list[++count] = movie;
			up_list[count] = pos;
		}
	}
	file1.close();
	sortindex1();
	buffer1.erase();
	file3.open("index1.txt", ios::out);
	for (int i = 0; i <= count; i++)
	{
		file3 << movieu_list[i] << "|" << up_list[i] << "$" << "\n";
		//	cout<<movieu_list[i]<<"          "<<up_list[i]<<endl;
	}
	file3.close();
}
void details::sortindex()
{
	int i, j, tempadd;
	string temp;
	for (int i = 0; i <= count; i++)
	{
		for (int j = i + 1; j <= count; j++)
		{
			if (movie_list[i]>movie_list[j])
			{
				temp = movie_list[i];
				movie_list[i] = movie_list[j];
				movie_list[j] = temp;
				tempadd = add_list[i];
				add_list[i] = add_list[j];
				add_list[j] = tempadd;
			}
		}
	}
}
void details::sortindex1()
{
	int i, j, tempadd;
	string temp;
	for (int i = 0; i <= count; i++)
	{
		for (int j = i + 1; j <= count; j++)
		{
			if (movieu_list[i]>movieu_list[j])
			{
				temp = movieu_list[i];
				movieu_list[i] = movieu_list[j];
				movieu_list[j] = temp;
				tempadd = up_list[i];
				up_list[i] = up_list[j];
				up_list[j] = tempadd;
			}
		}
	}
}
int details::searchindex(string key)
{
	int low = 0, high = count, mid = 0, flag = 0, pos;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (movie_list[mid] == key)
		{
			flag = 1;
			break;
		}
		if (movie_list[mid]>key)high = mid - 1;
		if (movie_list[mid]<key)low = mid + 1;
	}
	if (flag)
	{
		//cout<<mid<<endl;
		return mid;
	}

	else
		return -1;
}
void details::search(string key)
{
	int pos = 0, address, address1;
	fstream file;
	fstream file1;
	buffer.erase();
	buffer1.erase();
	pos = searchindex(key);
	if (pos >= 0)
	{
		file.open("moviedetails1.txt", ios::out | ios::in);
		address = add_list[pos];
		file.seekp(address, ios::beg);
		address1 = file.tellg();
		file.seekg(address1, ios::beg);
		getline(file, buffer);
		display();
		file1.open("movieupdate1.txt", ios::out | ios::in);
		address1 = up_list[pos];
		//	cout<<"address:"<<address<<endl;
		file1.seekg(address1, ios::beg);
		getline(file1, buffer1);
		display1();
	}
	else
	{
		cout << "movie not found" << endl;
	}
}
void details::search1(string key)
{
	int pos = 0, address, address1;
	string inp;
	int ch;
	fstream file1;
	buffer1.erase();
	pos = searchindex(key);
	cout << pos;
	if (pos >= 0)
	{

		cout << "what should be modified???" << endl;
		cout << "press '1' to modify awards" << endl;
		cout << "press '2' to modify ratings" << endl;
		cin >> ch;
		switch (ch)
		{
		case 1: {
			cout << "enter new awards won:";
			cin >> inp;
			file1.open("movieupdate1.txt");
			address1 = up_list[pos];
			file1.seekp(address1, ios::beg);
			file1.put('*');
			getline(file1, buffer1);
			unpack1();
			movie = key;
			ratings = ratings;
			awardswon = inp;
			pack1();
			write1();
			file1.close();
			cout << "awards updated successfully!!" << endl;
			break;
		}
		case 2: {
			cout << "enter new ratings:";
			cin >> inp;
			file1.open("movieupdate1.txt");
			address1 = up_list[pos];
			file1.seekp(address1, ios::beg);
			file1.put('*');
			getline(file1, buffer1);
			unpack1();
			movie = key;
			awardswon = awardswon;
			ratings = inp;
			pack1();
			write1();
			file1.close();
			cout << "ratings updated successfully!!" << endl;
			break;
		}
		default:cout << "invalid choice" << endl;
		}
	}
}
int main()
{
	//cout<<"description about project"<<endl;
	system("COLOR 10");
	details d;
	string name, year, hero, heroin, director, desc;
	char choice, ch;
	int num;
	d.createindex();
	d.createindex1();
//	d.create_hashtable();
	//d.initial_yearlist();
//	d.create_hashtable1();
	Sleep(100);
	system("COLOR 20");
	Sleep(100);
	system("COLOR 30");
	Sleep(100);
	system("COLOR 40");
	Sleep(100);
	system("COLOR 50");
	Sleep(100);
	system("COLOR 70");
	Sleep(100);
	system("COLOR 80");
	Sleep(100);
	system("COLOR 90");
	Sleep(100);
	system("COLOR 60");
	char a[] = "----------------------------------------------------------------------------------MoViEs MaNiA-------------------------------------------------------------------";
	int size;
	size = strlen(a);
	for (int i = 0; i<size; i++)
	{
		Sleep(25);
		cout << a[i];
	}
	int c = 1;
	cout << endl << endl;
	Sleep(0);
	cout << "WELCOME TO MOVIEMANIA!!!" << endl;
	cout << "find all the details about your favorite movies here:";
	cin >> name;
	cout << endl;
		if (name == "qwertyui123")
	{
		while (true)
		{
			cout << "M<--Modify existing movies" << endl;
			cout << "A<--Add new movies" << endl;
			cout << "V<--View movie details" << endl;
			cout << "E<--Exit" << endl;
			cout << "->";
			cin >> choice;
			if (choice == 'A' || choice == 'a')
			{
				cout << "ADDING NEW MOVIE RECORDS" << endl;
				cout << "enter number of records:";
				cin >> num;
				for (int i = 0; i<num; i++)
				{
					cout << "enter the details" << endl;
					cout << "movie " << i + 1 << endl;
					d.read();
					d.read1();
					d.pack();
					d.pack1();
					d.write();
					d.write1();
					//	d.yearlist(d.movie,d.year);
				}
				cout << "\nRecords inserted successfully!!" << endl;
			}
			else if (choice == 'M' || choice == 'm')
			{
				cout << "MODIFYING RECORDS" << endl;
				cout << "enter the movie name which is to be modified:";
				cin >> name;
				d.search1(name);
			}
			else if (choice == 'v' || choice == 'V')
			{
				cout << "enter the movie name to be searched:";
				cin >> name;
				d.search(name);
			}
			else if (choice == 'e' || choice == 'E')
			{
				break;
			}
		}
	}
	else
	{
		cout << "movie name:" << name << endl;
		d.search(name);
		cout << endl;
		cout << "You can also search movies based on YEAR,HERO,HEROIN,DIRECTOR,DESC" << endl;
		cout << "press 'Y' if yes \npress other key if no" << endl;
		cout << "->";
		cin >> choice;
		if (choice == 'y' || choice == 'Y')
		{
			while (true)
			{
				cout << "Y<--To search movies based on year\nH<--To search based on hero\nS<--To search based on heroin\nD<--To search based on director\ne<--To exit" << endl;
				cout << "->";
				cin >> ch;
				if (ch == 'y' || ch == 'Y')
				{
					cout << "enter the year:";
					cin >> year;
					d.searchyear(year);
				}
				else if (ch == 'h' || ch == 'H')
				{
					cout << "enter the hero:";
					cin >> hero;
					d.searchhero(hero);
				}
				else if (ch == 's' || ch == 'S')
				{
					cout << "enter the heroin:";
					cin >> heroin;
					d.searchheroin(heroin);
				}
				else if (ch == 'd' || ch == 'D')
				{
					cout << "enter the director:";
					cin >> director;
					d.searchdirector(director);
				}
				else if (ch == 'e' || ch == 'E')
					break;
			}
		}
	}
	return 0;
}
