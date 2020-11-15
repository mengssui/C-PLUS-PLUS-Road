//Copyright
//License
//Autho : Mengbw_
//data : 2020/6/13
//This is the main.cpp to sort
//博客网站：https://blog.csdn.net/qq_42956667/article/details/106738031
#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>
#include <map>
using std::vector;
#define DEBUG
using namespace std;
vector<int> twoSum(vector<int>& nums, int target);
vector<int> num{1,2,3,4,5,6,7,8,9};
unsigned int a,b,c;
int main(){
    vector<int> p;
    p = twoSum(num,3);
    for(int i=0;i!=p.size();i++){
        cout<<p[i]<<"->";
    }

}


vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ret;
    map<int,int> num2i; //数组的值和序号 {nums[i], i}这样的map
    
    for(int j =0; j<=nums.size();j++){
        if(num2i.count(target-nums[j])!=0){ //顺序不能调换，num2i[target-nums[j]]!=j 会创建num2i[target-nums[j]]=0;
            ret.push_back(num2i[target-nums[j]]);
            ret.push_back(j);
            break;
        }
        num2i[nums[j]]=j;
    }


    #ifdef DEBUG //调试
    auto iter = num2i.begin();
    while(iter!=num2i.end()){
        cout<<iter->first<<" "<<iter->second<<endl;
        iter++;
    }
    #endif

    return ret;
}
