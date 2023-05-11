#include <bits/stdc++.h>
using namespace std;

class startTime;
class endTime;

class Subtitle
{
private:
	int id;
	class startTime;
	class endTime;
	vector<string> language;
public:
	
}; 

class Video
{
private:
	vector<Subtitle> pst;
public:
	void readSubtitle();
	void adjustSubtitle();
	void writeSubtitle();
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ifstream myfile("视频1.srt");

	string s;
	getline(myfile, s);

	myfile.close();

	ofstream outfile("视频1.srt");



	outfile.close();

	return 0;
}