#include<iostream>
#include<string>

#define endl '\n'

using namespace std;

//最大人数，便于后续修改电话簿人数上限
const int N=1e4;

//定义包含类Basic_Information，里面是成员的基本信息
class Basic_Information
{
public:
	int sex;
	int age;
	
	//构造函数
	Basic_Information(int _sex,int _age):sex(_sex),age(_age){}
	
	//析构函数
	~Basic_Information(){}
};

// 定义基类Contact，里面含有每个成员的姓名
class Contact
{
protected:
	string name;
public:
	Contact(string _name=""):name(_name){}
	
	// 纯虚函数
	virtual void display() const = 0;
	virtual string getName() const = 0;
	
	// 析构函数
	virtual ~Contact(){}
	
};

class Person : public Contact
{
protected:
	Basic_Information Basic_information;
	string phone;
	string address;
	int index;
	
public:
	// 构造函数
	Person(string _name="",int _sex=0,int _age=0,string _phone="",string _address="",int _index=0):Contact(_name),Basic_information(_sex,_age),phone(_phone),address(_address),index(_index){}
	
	// 获取姓名
	string getName() const
	{
		return name;
	}
	
	// 获取联系人索引
	int getIndex() const
	{
		return index;
	}
	
	// 修改联系人索引
	void modifyIndex(const int number)
	{
		index=number;
	}
	
	// 重置姓名
	void resetName()
	{
		name="";
	}
	
	// 重置性别
	void resetSex()
	{
		Basic_information.sex=0;
	}
	
	// 重置年龄
	void resetAge()
	{
		Basic_information.age=0;
	}
	
	// 重置电话号码
	void resetPhone()
	{
		phone="";
	}
	
	// 重置住址
	void resetAddress()
	{
		address="";
	}
	
	// 重置该联系人下标
	void resetIndex()
	{
		index=0;
	}
	
	// 显示该联系人信息
	void display() const
	{
		cout<<"第"<<index+1<<"位联系人"<<'\t';
		cout<<"姓名："<<name<<'\t';
		cout<<"性别："<<(Basic_information.sex?"男":"女")<<'\t';
		cout<<"年龄："<<Basic_information.age<<'\t';
		cout<<"电话："<<phone<<'\t';
		cout<<"住址："<<address<<endl;
	}
	
	// 友元函数，判断联系人是否存在
	friend int isfindPerson(const Person& person, const string& name);
	
	// 调用析构函数
	~Person(){}
	
};

// 查找联系人是否存在
// 参数1：联系人    参数2：姓名
int isfindPerson(const Person& person, const string& name)
{
	if(person.getName() == name)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

class Phonebook
{
protected:
	// 电话簿中保存联系人数组
	Person person_member[N];
	
	// 电话簿中人员个数
	int number;
	
public:
	// 构造函数
	Phonebook():number(0){}
	
	// 1、添加联系人
	void addPerson(Person &person)
	{
		// 判断是否达到通讯录上限，达到就不再添加
		if(number == N)
		{
			cout<<"电话簿人数已达上限，无法添加！"<<endl;
			return;
		}
		else
		{
			// 更新联系人信息
			person_member[number] = person;
			
			// 更新联系人在数组中的下标
			person_member[number].modifyIndex(number);
			
			// 更新电话簿人数
			++number;
			
			// 提示添加成功
			cout<<"添加成功"<<endl;
			
		}
		
	}
	
	// 2、显示联系人
	void showPerson() const
	{
		// 判断通讯录中人数是否为零
		if(number == 0)
		{
			cout<<"电话簿为空"<<endl;
			return;
		}
		else
		{
			for(int i=0;i<number;++i)
			{
				// 调用display函数显示信息
				person_member[i].display();
			}
		}
		
	}
	
	// 3、删除联系人
	void deletePerson(const string& name)
	{
		// 该联系人的位置初始化为-1
		int position=-1;
		
		for(int i=0;i<number;++i)
		{
			if(isfindPerson(person_member[i],name))
			{
				//// 找到此人，记录此人的位置
				position=i;
				break;
			}
		}
		
		// position == -1 表示未找到此人
		// position != -1 表示找到此人
		
		if(position == -1)
		{
			cout<<"未找到该联系人"<<endl;
		}
		else
		{
			for(int i=position;i<number-1;++i)
			{
				// 数据前移，覆盖当前数据
				person_member[i]=person_member[i+1];
				person_member[i].modifyIndex(i);
			}
			
			// 更新电话簿中的人数
			--number;
			
			// 提示删除成功
			cout<<"删除成功"<<endl;
		}
		
	}
	
	// 4、查找联系人
	void findPerson(const string& name) const
	{
		// 该联系人的位置初始化为-1
		int position=-1;
		
		for(int i=0;i<number;++i)
		{
			if(isfindPerson(person_member[i],name))
			{
				//// 找到此人，记录此人的位置
				position=i;
				break;
			}
		}
		
		// position == -1 表示未找到此人
		// position != -1 表示找到此人
		
		if(position == -1)
		{
			cout<<"未找到该联系人"<<endl;
		}
		else
		{
			// 显示该联系人的信息
			person_member[position].display();
			
			// 提示查找成功
			cout<<"查找成功"<<endl;
		}
		
	}
	
	// 5、修改联系人
	void modifyPerson(const string& name)
	{
		// 该联系人的位置初始化为-1
		int position=-1;
		
		for(int i=0;i<number;++i)
		{
			if(isfindPerson(person_member[i],name))
			{
				//// 找到此人，记录此人的位置
				position=i;
				break;
			}
		}
		
		// position == -1 表示未找到此人
		// position != -1 表示找到此人
		
		if(position == -1)
		{
			cout<<"未找到该联系人"<<endl;
		}
		else
		{
			
			// 记录该联系人索引
			int _index=person_member[position].getIndex();
			// 性别
			int sex=0;
			cout<<"请输入性别："<<endl;
			cout<<"0 ----- 女"<<endl;
			cout<<"1 ----- 男"<<endl;
			// 用while循环保证性别输入无误
			while(true)
			{
				// 如果输入错误，重新输入
				cin>>sex;
				if(sex==0||sex==1)
				{
					break;
				}
				cout<<"输入错误，请重新输入"<<endl;
			}
			
			// 年龄
			int age=0;
			cout<<"请输入年龄："<<endl;
			// 用while循环保证年龄大于等于0
			while(true)
			{
				// 如果输入有误，重新输入
				cin>>age;
				if(age>=0)
				{
					break;
				}
				cout<<"输入错误，请重新输入"<<endl;
			}
			
			// 电话
			string phone;
			cout<<"请输入联系人电话："<<endl;
			cin>>phone;
			
			// 住址
			string address;
			cout<<"请输入联系人住址："<<endl;
			cin>>address;
			
			// 将上述信息存入数组
			Person person(name,sex,age,phone,address,_index);
			person_member[position]=person;
			
			// 提示修改成功
			cout<<"修改成功"<<endl;
			
		}
		
	}
	
	// 6、清空联系人
	void clearbooks()
	{
		// 将电话簿所有信息都重置
		for(int i=0;i<number;++i)
		{
			person_member[i].resetAge();
			person_member[i].resetSex();
			person_member[i].resetAge();
			person_member[i].resetPhone();
			person_member[i].resetAddress();
			person_member[i].resetIndex();
		}
		
		// 将联系人数量重置为0
		number = 0;
		
		// 提示电话簿已清空
		cout<<"电话簿已清空"<<endl;
		
	}
	
	// 调用析构函数
	~Phonebook(){}
	
};

// 菜单界面
void showMenu()
{
	cout<<"-------------------"<<endl;
	cout<<"|| 1、添加联系人 ||"<<endl;
	cout<<"|| 2、显示联系人 ||"<<endl;
	cout<<"|| 3、删除联系人 ||"<<endl;
	cout<<"|| 4、查找联系人 ||"<<endl;
	cout<<"|| 5、修改联系人 ||"<<endl;
	cout<<"|| 6、清空联系人 ||"<<endl;
	cout<<"|| 0、退出通讯录 ||"<<endl;
	cout<<"-------------------"<<endl;
}

// 1、添加联系人
void add_Person(Phonebook *books)
{
	// 姓名
	string name;
	cout<<"请输入姓名："<<endl;
	cin>>name;
	
	// 性别
	int sex=0;
	cout<<"请输入性别："<<endl;
	cout<<"0 ----- 女"<<endl;
	cout<<"1 ----- 男"<<endl;
	// 用while循环保证性别输入无误
	while(true)
	{
		// 如果输入错误，重新输入
		cin>>sex;
		if(sex==0||sex==1)
		{
			break;
		}
		cout<<"输入错误，请重新输入"<<endl;
	}
	
	// 年龄
	int age=0;
	cout<<"请输入年龄："<<endl;
	// 用while循环保证年龄大于等于0
	while(true)
	{
		// 如果输入有误，重新输入
		cin>>age;
		if(age>=0)
		{
			break;
		}
		cout<<"输入错误，请重新输入"<<endl;
	}
	
	// 电话
	string phone;
	cout<<"请输入联系人电话："<<endl;
	cin>>phone;
	
	// 住址
	string address;
	cout<<"请输入联系人住址："<<endl;
	cin>>address;
	
	// 添加操作
	Person person(name,sex,age,phone,address);
	books->addPerson(person);
	
	system("pause"); // 按任意键继续
	system("cls"); // 清屏
	
}

// 2、显示联系人
void show_Person(Phonebook *books)
{
	books->showPerson();
	
	system("pause"); // 按任意键继续
	system("cls"); // 清屏
	
}

// 3、删除联系人
void delete_Person(Phonebook *books)
{
	string name;
	cout<<"请输入要删除的联系人的姓名："<<endl;
	cin>>name;
	books->deletePerson(name);
	
	system("pause"); // 按任意键继续
	system("cls"); // 清屏
	
}

// 4、查找联系人
void find_Person(Phonebook *books)
{
	string name;
	cout<<"请输入要查找的联系人的姓名："<<endl;
	cin>>name;
	books->findPerson(name);
	
	system("pause"); // 按任意键继续
	system("cls"); // 清屏
	
}

// 5、修改联系人
void modify_Person(Phonebook *books)
{
	string name;
	cout<<"请输入要修改的联系人的姓名："<<endl;
	cin>>name;
	books->modifyPerson(name);
	
	system("pause"); // 按任意键继续
	system("cls"); // 清屏
	
}

// 6、清空联系人
void clear_books(Phonebook *books)
{
	books->clearbooks();
	
	system("pause"); // 按任意键继续
	system("cls"); // 清屏
	
}

int main()
{
	// 用户的选择
	int option=0;
	
	// 创建一个电话簿对象
	Phonebook books;
	
	while(true)
	{
		// 显示菜单
		showMenu();
		
		// 读入用户的选择
		cin>>option; 
		
		switch (option)
		{
		// 1、添加联系人
		case 1:
			{
				add_Person(&books);
				break;
			}
		// 2、显示联系人
		case 2:
			{
				show_Person(&books);
				break;
			}
		// 3、删除联系人
		case 3:
			{
				delete_Person(&books);
				break;
			}
		// 4、查找联系人
		case 4:
			{
				find_Person(&books);
				break;
			}
		// 5、修改联系人
		case 5:
			{
				modify_Person(&books);
				break;
			}
		// 6、清空联系人
		case 6:
			{
				clear_books(&books);
				break;
			}
		// 0、退出通讯录
		case 0:
			{
				cout<<"欢迎下次使用"<<endl;
				system("pause");
				return 0;
				break;
			}
		default:
			{
				cout<<"输入错误，请重新输入"<<endl;
				break;
			}
		}
		
	}
	
	system("pause");
	return 0;
}