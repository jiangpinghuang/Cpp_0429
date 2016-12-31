/*
 * minEditDist.cpp
 *
 *  Created on: Dec 31, 2016
 *      Author: hjp
 * Description: calculate the minimal edit distance between 2 strings.
 */

#include"iostream"
#include"stdio.h"
#include"string.h"
using namespace std;

#define N 100
#define INF 100000000

#ifndef min
#define min(a,b) (((a) < (b)) ? (a) : (b))
#endif

int dis[N][N];
char s1[N],s2[N];
int n,m;//length of the two string

int main()
{
	int i,j,k;
	while(scanf("%s%s",&s1,&s2)!=EOF)
	{
		n=strlen(s1);m=strlen(s2);
		for(i=0;i<=n+1;i++)
			for(j=0;j<=m+1;j++)
				dis[i][j]=INF;
		dis[0][0]=0;

		for(i=0;i<=n;i++)
			for(j=0;j<=m;j++)
			{
				if(i>0) dis[i][j] = min(dis[i][j],dis[i-1][j]+1); //delete
				if(j>0) dis[i][j] = min(dis[i][j],dis[i][j-1]+1);//insert

				//substitute
				if(i>0&&j>0)
				{
					if(s1[i-1]!=s2[j-1])
						dis[i][j] = min(dis[i][j],dis[i-1][j-1]+2);
					else
						dis[i][j] = min(dis[i][j],dis[i-1][j-1]);
				}
			}

		printf("min edit distance is: %d\n",dis[n][m]);
	}
	return 0;
}
