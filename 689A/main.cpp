#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <map>
using namespace std;
typedef struct distance{
	int x;
	int y;
} Distance;


map<int, vector<int>> numToXY;  //������ݽṹ�����0��9��Ӧ������
vector<Distance> DisVec; // ������ݽṹ�����·���ı仯

vector<Distance> intTodis(vector<int> &d)
{
	Distance dis;
	vector<Distance> path;
	for(int i = 0; i < d.size()-1; i++)
	{
		dis.x = numToXY[d[i]][0] - numToXY[d[i+1]][0];
		dis.y = numToXY[d[i]][1] - numToXY[d[i+1]][1];
		path.push_back(dis);
	}
	d.clear();
	return path;
}

int main()
{
	int a;
	string pathStr;
	int phoneNum[5][5];
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j <5; j++)
			phoneNum[i][j] = 12;
	}
	int content = 1;
	vector<int> tmp;
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(i == 3&&j == 1)
			{
				content = 0;
			}

			phoneNum[i][j] = content;
			tmp.push_back(i);
			tmp.push_back(j);
			numToXY[content] = tmp; 
			content++;
			tmp.clear();
			if(content == 1)
				break;
		}
	}

	//���ֻ�������������map��
	map<int, vector<int>>::const_iterator iter;
	for (iter = numToXY.begin(); iter != numToXY.end(); iter++)
	{
		cout << iter->first << "~";
		cout << (iter->second)[0] << " " << (iter->second)[1] << endl;
	}
	//��Ҫһ��vector<Distance>�����洢�仯�Ĳ���
	vector<int> steps;

	while(cin >> a)
	{
		cin >> pathStr;
		const char *mystr = pathStr.c_str();
		for(int i = 0; i < pathStr.length(); i++)
		{
			steps.push_back(mystr[i] - '0');
		}

		DisVec.assign(intTodis(steps).begin(), intTodis(steps).end());  
		//��һ�����Ǳ���10������ ���Ƿ������������仯��
		int flag = 1;
		map<int, vector<int>>::iterator p_iter;
		for(p_iter = numToXY.begin(); p_iter != numToXY.end(); p_iter++)
		{
			int px = (*p_iter).second[0];
			int py = (*p_iter).second[1];
			int i = 0;
			int length = DisVec.size();
			while(i <= length)
			{
				px -= DisVec[i].x;
				py -= DisVec[i].y;
				if(phoneNum[px][py] > 9)
				{
					flag = 0;
					break;
				}
				i++;
			}
			if(flag == 1)
			{
				cout << "True" << endl;
				break;
		 	}
		}	
		cout << "False";
	}
	return 0;
}


