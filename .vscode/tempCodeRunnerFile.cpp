 #include<iostream>
 #include<deque>

 using namespace std;
 int main()
 {

deque<int> d;

d.push_back(4);
d.push_front(9);

cout<<"first index element"<<d.at(0)<<endl; 



for(int i: d)
{
    cout<<i<<" ";
}




 }