//
//  const.cpp
//  cplusplus
//
//  Created by junhui cao on 20/09/2018.
//  Copyright © 2018 junhui cao. All rights reserved.
//

#include<iostream>
using namespace std;
class Point{
    public :
    Point(int _x):x(_x){}   //const x 只能在初始化列表中赋值；
    void testConstFunction(int _x) const{//const修饰成员函数
        ///错误，在const成员函数中，不能修改任何类成员变量
        //x=_x;
        ///错误，const成员函数不能调用非onst成员函数，因为非const成员函数可以会修改成员变量
        //modify_x(_x);
    }
    void modify_x(int _x){
        x=_x;
    }
    void testModifyConst(const int _x) {
        //_x=5;　　　///传递过来的参数在函数内不可以改变,编译出错
    }
    int x;
};
//如果返回const data,non-const pointer，返回值也必须赋给const data,non-const pointer。
const int * mallocA(){  ///const data,non-const pointer
    int *a=new int(2);
    return a;
}
int main(){
    int a1=3;   ///non-const data
    const int a2=a1;    ///const data
    //主要看const在*的前后，在前则指针指向的内容为常量，在后则指针本身为常量；
    //int * a3 = &a2;  //error
    int * a3 = &a1;   ///non-const data,non-const pointer
    const int * a4 = &a1;   ///const data,non-const pointer
    const int * a8 = &a2;   ///const data,non-const pointer
    
    int * const a5 = &a1;   ///non-const data,const pointer
    int const * const a6 = &a1;   ///const data,const pointer
    const int * const a7 = &a1;   ///const data,const pointer
    const int * const a9 = &a2;   ///const data,const pointer
    
    int x=10;
    int y=50;
    //指向常量的指针
    const int *p=&x;
    cout<<"p="<<p<<" *p="<<*p<<endl;
    //    *p=20;//改变指针指向的变量，出错：error C2166: l-value specifies const object
    p=&y;//指针里面的值是可以变的。
    cout<<"p="<<p<<" *p="<<*p<<endl;
    //常指针
    int * const p2=&x;//const靠近指针p2修饰指针p2里面的地址值不可变，
    cout<<"p2="<<p2<<" *p2="<<*p2<<endl;
    //    p2=&y;//不能修改，常指针的指向 error C2166: l-value specifies const object
    *p2=30;//可以修改常指针指向的变量的值
    cout<<"p2="<<p2<<" *p2="<<*p2<<endl;
    
    //定义指向常量的常指针
    const int * const p3=&x;
    //p3=&y;//不可以改变常指针的指向。
    //*p3=100;//不可改变常指针指向的常量的值。
    //const靠近数据类型就是修把该类型的变量变成常量，
    //const靠近指针就是修饰把这个指针变成常指针
    
    const int *a = mallocA();
    ///int *b = mallocA();  ///编译错误
    
    const int temp1 =1; //temp1为常量，不可变
    int const temp2 =1; //temp2为常量，不可变
    return 0;
}
