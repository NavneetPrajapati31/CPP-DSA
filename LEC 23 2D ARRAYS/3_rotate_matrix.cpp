#include<iostream>
#include<vector>
using namespace std;

void reverse(vector<vector<int>> &v, int row)
{
	int s=0;
	int e=v.size()-1;

	while(s<=e)
	{
		swap(v[row][s++],v[row][e--]);
	}

}

void rotateMatrix(vector<vector<int>> &mat){
	// Write your code here.
	vector<vector<int>> v(3,vector<int>(3));

	for(int i=0;i<mat.size();i++)
	{
		for(int j=0;j<mat.size();j++)
	{
		v[i][j] = mat[j][i];
	}
	}

	for(int i=0;i<v.size();i++)
	{
		reverse(v,i);
	}

	for(int i=0;i<mat.size();i++)
	{
		for(int j=0;j<mat.size();j++)
	{
		mat[i][j] = v[i][j];
	}
	}
	
}


int main()
{
    vector<vector<int>> matrix(3,vector<int>(3));
    for(int i=0;i<matrix.size();i++)
	{
		for(int j=0;j<matrix.size();j++)
	{
		cin>>matrix[i][j];
	}

    }

    rotateMatrix(matrix);

    for(int i=0;i<matrix.size();i++)
	{
		for(int j=0;j<matrix.size();j++)
	{
		cout<<matrix[i][j]<<" ";
	}

    cout<<endl;

    }



}