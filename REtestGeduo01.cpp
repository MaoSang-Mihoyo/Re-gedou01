//笔者使用的是Dev-C++，有些新标准可能不支持，所以有些代码我只是注释掉了，并没有除去 
#include <iostream>//标准输入输出头文件
#include <string>//字符串头文件
//#include <random>//随机取数函数用的头文件//（旧版编译器不支持）（所需C++11） 
#include <winsock2.h> // include must before window.h //
#include <iphlpapi.h>
#include <windows.h>//控制台编程主要头文件
#include <conio.h>//_getch()函数以及system()函数
#include <fstream>//文件写操作头文件
#include <cassert>

using namespace std;

#pragma comment(lib, "iphlpapi.lib")
#pragma warning(disable: 4996) // 避免获取视窗信息被警告 

static const int kMaxInfoBuffer = 256;
#define  GBYTES  1073741824  
#define  MBYTES  1048576  
#define  KBYTES  1024  
#define  DKBYTES 1024.0  

void getOsInfo(){
    // 从版本号中获取视窗版本 
    OSVERSIONINFO osver = { sizeof(OSVERSIONINFO) };
    GetVersionEx(&osver);
    string os_name;
    if (osver.dwMajorVersion == 5 && osver.dwMinorVersion == 0)
        os_name = "Windows 2000";
    else if (osver.dwMajorVersion == 5 && osver.dwMinorVersion == 1)
        os_name = "Windows XP";
    else if (osver.dwMajorVersion == 6 && osver.dwMinorVersion == 0)
        os_name = "Windows 2003";
    else if (osver.dwMajorVersion == 5 && osver.dwMinorVersion == 2)
        os_name = "windows vista";
    else if (osver.dwMajorVersion == 6 && osver.dwMinorVersion == 1)
        os_name = "windows 7";
    else if (osver.dwMajorVersion == 6 && osver.dwMinorVersion == 2)
        os_name = "windows 10";
    cout << "OS Name: " << os_name << endl;
    cout << "OS Version: " << osver.dwMajorVersion << '.' << osver.dwMinorVersion << endl;

}

bool kongzhi9(){ 
	bool x;
	char kongzhi = _getch();
    switch (kongzhi)
	{
    	case ('a'):
        {
            cout << "左移一步"<< endl;
            break;
		}
		case ('s'):
       	{
            cout << "下移一步"<< endl;
          	break;
		}
		case ('d'):
        {
			cout << " 右移一步 "<< endl;
            break;
		}
		case ('w'):
        {
            cout << "上移一步"<< endl;	
           	break;
		}
		case ('g'):
        {
        	cout << "攻击一次"<< endl;
            break;
		}
		case ('k'):
        {
            cout << "闪避一次"<< endl;
           	break;
		}
	}
		
		if (kongzhi != 'g')
		{	
			x = false;
			return x;
		}
		else 
		{
			x = true;
			return x;
		} 
}

class Champion {
public:
    Champion(int id, string name, int hp, int dmg, int mn) //定义一个英雄的属性
    {
        ID = id;
        Name = name;
        HP = hp;
        Damage = dmg;
        Mana = mn;
    }
    void Attack(Champion& chmp) 
    {
        chmp.takeDamage(this->Damage);
    }
    void takeDamage(int incomingDamage) 
    {
        HP -= incomingDamage;
    }
    int getHP() //返回生命值
    {
        return HP;
    }
    int getMana() //返回魔法值
    {
        return Mana;
    }
    void getinfo() //返回信息
    {
        cout << Name << "" << HP << "" << endl;
    }
private:
    int ID;
    string Name;
    int HP;//血量
    int Damage;//伤害
    int Mana;//魔法值

};

/*int Num() //随机取数函数
{
    bool x;
    constexpr int MIN = 1;//取值下限
    constexpr int MAX = 100;//取值上限
    constexpr int RAND_NUMS_TO_GENERATE = 1;//取数个数
    random_device rd;
    default_random_engine eng(rd());
    uniform_int_distribution<int> distr(MIN, MAX);//取数操作
    int A = 1;
    int* PtrA = &A;
    int DistrNum = distr(eng);
    int* PtrDistrNum = &DistrNum;
    char b;
    b = _getch();
    if (b == 'g') {
        if ((*PtrDistrNum % 2) == *PtrA)//判断是否相等
        {
            x = false;
            return x;
        }
        else
        {
            x = true;
            return x;
        }
    }
}*/

int main (){
		cout << "=== OS Information ===" << endl;
		getOsInfo();
	ALLBEGIN:
		{
			system("color 3e");
			Champion Maozi(1,"帽子",2500,200,100);
			Champion WXX(2,"王小小",3000,190,120);
			Champion JJ(3,"景靖",4000,250,50);
			string WenziTixing;
			char Xuanze1,Xuanze3;
			int Xuanze2;
			typedef string XINXI;
			XINXI xx1;
			XINXI xx2;
			XINXI xx3;
			XINXI xx4;
			string Yidong = "w向上移动，a向左移动，s向下移动，d向右移动。";
			string Zaozuo = "g攻击，k闪避，space跳跃。";
			IFBEGIN:
				WenziTixing = "是否开始？（YorN）：";
				cout << WenziTixing << endl;
				Xuanze1 = _getch();
				cout << Xuanze1 << endl;
				{
					if ( Xuanze1 == 'Y')
					{
						switchbegin1:
							cout << "游戏开始。 " << endl;
							cout << "基本操作：" ; 
							cout << Yidong << endl;
							cout << Zaozuo << endl;
							cout << "获取boss信息：" << endl;
							WXX.getinfo();
							JJ.getinfo();
							WenziTixing = "选择BOSS：wxx(1)或者jj(2)：";
							cout << WenziTixing << endl;
							Xuanze2 = _getch();
							cout << static_cast<char>(Xuanze2) << endl;
							{
								if (Xuanze2 == '1')
								{
									
									//Num();//(在支持c++11的编译器里改回来）
									While1: 
									int i = 0;
									while (i <= WXX.getHP())
									{
										WXX.Attack(Maozi);
										xx1 = "你被攻击了";
										cout << xx1 << endl;
										if (static_cast<int>(Maozi.getHP()) < 0)
										{
											xx1 = "你死了，游戏结束。";
											cout << xx1 << endl;
											goto Gameend1;
										}
										xx2 = "你当前的血量：";
										cout <<xx2 << Maozi.getHP() << endl;
										forbegin:
										cout << "该你进行操作了。" << endl;
										Forbegin1:
											if (kongzhi9() != true)
											{
												goto forbegin;
											}
											else
											{
												Maozi.Attack(WXX); 
												cout << "你攻击了boss，现在boss血量为" << WXX.getHP() << endl; 
												goto While1; 	
											}
									}
									Gameend1:
										xx1 = "是否重新开始？（YorN）";
										cout << xx1 << endl;
										Xuanze3 = _getch();
										if (Xuanze3 == 'N')
										{
											goto End;
										}
										else if (Xuanze3 == 'Y')
										{
											goto  ALLBEGIN;
										}
										else
										{
										cout << "我说,喊你输入Y或者N！" << endl;
										goto Gameend1;
										}
								}
								else if (Xuanze2 == '2')
								{
									//Num();//(在支持c++11的编译器里改回来）
									While2: 
									int q = 0;
									{
										JJ.Attack(Maozi);
										xx3 = "你被攻击了";
										cout << xx3 << endl;
										if (static_cast<int>(Maozi.getHP()) < 0)
										{
											xx4 = "你死了，游戏结束。";
											cout << xx4 << endl;
											goto Gameend2;
										}
										xx3 = "你当前的血量：";
										cout << xx3 << Maozi.getHP() << endl;
										forbegin2:
										cout << "该你进行操作了。" << endl;
											if (kongzhi9() != true)
											{
												goto forbegin2;
											}
											else
											{
												Maozi.Attack(JJ); 
												cout << "你攻击了boss，现在boss血量为" << JJ.getHP() << endl; 
												goto While2; 	
											}
									}
									Gameend2:
										xx2 = "是否重新开始？（YorN）";
										cout << xx2 << endl;
										Xuanze3 = _getch();
										if (Xuanze3 == 'N')
										{
											goto End;
										}
										else if (Xuanze3 == 'Y')
										{
											goto  ALLBEGIN;
										}
										else
										{
										cout << "我说,喊你输入Y或者N！" << endl;
										goto Gameend2;
										}
								}
								else
								{
									cout << "我说,喊你输入1或者2！" << endl;
									goto switchbegin1;
								}
							}
					}
					else if ( Xuanze1 == 'N')
					{
						goto End;
					}
					else
					{
						cout << "我说,喊你输入Y或者N！" << endl << endl;
						goto IFBEGIN;
					}
				}
				End:
				cout << "游戏结束。" << endl;
				system("pause");
				return 0;
		}
} 

