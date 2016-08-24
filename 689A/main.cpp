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
		vector<Distance> Vtmp = intTodis(steps);
		DisVec.assign(Vtmp.begin(), Vtmp.end());  
		//��һ�����Ǳ���10������ ���Ƿ������������仯��
		
		map<int, vector<int>>::iterator p_iter;
		int flag = 1;
		for(p_iter = numToXY.begin(); p_iter != numToXY.end(); p_iter++)
		{
			if((*p_iter).first == steps[0])
				continue;
			int px = (*p_iter).second[0];
			int py = (*p_iter).second[1];
			int i = 0;
			int length = DisVec.size();
			while(i < length)
			{
				px -= DisVec[i].x;
				py -= DisVec[i].y;
				if(phoneNum[px][py] > 9||px < 0||py < 0)
				{
					break;
				}
				i++;
			}
			if(i == length)
			{
				flag = 0;
				cout <<"NO" << endl;
				break;
			}
		}
		if(flag == 1)
			cout << "YES" << endl;
		DisVec.clear();
		steps.clear();
	}
	return 0;
}


