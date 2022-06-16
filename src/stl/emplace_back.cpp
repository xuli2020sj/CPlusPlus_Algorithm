//
// Created by x on 2022/6/16.
//
#include <iostream>
#include <vector>

using namespace std;

class A {
    A();
    A(const A&);
    A(const A&&) noexcept ;
    A& operator=(const A&);
    A& operator=(const A&&) noexcept ;
    A* operator&();
    const A* operator&() const;
    ~A();
};

class Student {
    string name;
    int age;
public:
    Student(string& n, int a)
        :name(n), age(a)
    {
        cout << "左值构造：" << endl;
    }

    Student(string&& n, int a)
        :name(std::move(n)), age(a)
    {
        cout << "右值构造：" << endl;
    }

    Student(const Student& s)
        : name(s.name), age(s.age)
    {
        cout << "拷贝构造：" << endl;;
    }

    Student(Student&& s)
        :name(std::move(s.name)), age(s.age)
    {
        cout << "移动构造：" << endl;
    }

    ~Student() {
        cout << name << age << "析构" << endl;
    }

    Student& operator=(const Student& s);
};



/**
 *
 * emplace_back 在容器原地生成对象，省去移动开销
 * push_back 先构造，再移动
 * @return
 */
int main()
{
    // 基于类型萃取查看类信息
    cout << is_move_constructible<Student>::value << endl
         << is_trivially_move_constructible<Student>::value << endl
         << is_nothrow_move_constructible<Student>::value << endl;
    system("chcp 65001"); // 更改系统编码格式

    vector<Student> classes_one;
    vector<Student> classes_two;

    cout << "传入左值" << endl;
    string  ss = "xiaojiang";
    Student jj{ss, 22};

    cout << "传入右值" << endl;
    Student xx{"xl", 18};

    cout << "emplace_back:" << endl;
    classes_one.emplace_back("classes_one_xiaohong", 24);

    // 相比与emplace_back多一次移动构造(拷贝构造）与析构开销，如果类提供移动构造的话优先使用移动构造
    cout << "push_back:" << endl;
    classes_two.push_back(Student("classes_two_xiaoming", 23));

    cout << "palacement new test" << endl;
    char *buf=new char[sizeof(Student)+ sizeof(int)*8 ] ;
    Student* x = new(buf) Student("xx", 8);
    x->~Student();
    delete[] buf;
    cout << "palacement new test finished" << endl;
}

