//����ʹ�õ���Dev-C++����Щ�±�׼���ܲ�֧�֣�������Щ������ֻ��ע�͵��ˣ���û�г�ȥ 
#include <iostream>//��׼�������ͷ�ļ�
#include <string>//�ַ���ͷ�ļ�
//#include <random>//���ȡ�������õ�ͷ�ļ�//���ɰ��������֧�֣�������C++11�� 
#include <winsock2.h> // include must before window.h //
#include <iphlpapi.h>
#include <windows.h>//����̨�����Ҫͷ�ļ�
#include <conio.h>//_getch()�����Լ�system()����
#include <fstream>//�ļ�д����ͷ�ļ�
#include <cassert>

using namespace std;

#pragma comment(lib, "iphlpapi.lib")
#pragma warning(disable: 4996) // �����ȡ�Ӵ���Ϣ������ 

static const int kMaxInfoBuffer = 256;
#define  GBYTES  1073741824  
#define  MBYTES  1048576  
#define  KBYTES  1024  
#define  DKBYTES 1024.0  

void getOsInfo(){
    // �Ӱ汾���л�ȡ�Ӵ��汾 
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
            cout << "����һ��"<< endl;
            break;
		}
		case ('s'):
       	{
            cout << "����һ��"<< endl;
          	break;
		}
		case ('d'):
        {
			cout << " ����һ�� "<< endl;
            break;
		}
		case ('w'):
        {
            cout << "����һ��"<< endl;	
           	break;
		}
		case ('g'):
        {
        	cout << "����һ��"<< endl;
            break;
		}
		case ('k'):
        {
            cout << "����һ��"<< endl;
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
    Champion(int id, string name, int hp, int dmg, int mn) //����һ��Ӣ�۵�����
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
    int getHP() //��������ֵ
    {
        return HP;
    }
    int getMana() //����ħ��ֵ
    {
        return Mana;
    }
    void getinfo() //������Ϣ
    {
        cout << Name << "" << HP << "" << endl;
    }
private:
    int ID;
    string Name;
    int HP;//Ѫ��
    int Damage;//�˺�
    int Mana;//ħ��ֵ

};

/*int Num() //���ȡ������
{
    bool x;
    constexpr int MIN = 1;//ȡֵ����
    constexpr int MAX = 100;//ȡֵ����
    constexpr int RAND_NUMS_TO_GENERATE = 1;//ȡ������
    random_device rd;
    default_random_engine eng(rd());
    uniform_int_distribution<int> distr(MIN, MAX);//ȡ������
    int A = 1;
    int* PtrA = &A;
    int DistrNum = distr(eng);
    int* PtrDistrNum = &DistrNum;
    char b;
    b = _getch();
    if (b == 'g') {
        if ((*PtrDistrNum % 2) == *PtrA)//�ж��Ƿ����
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
			Champion Maozi(1,"ñ��",2500,200,100);
			Champion WXX(2,"��СС",3000,190,120);
			Champion JJ(3,"����",4000,250,50);
			string WenziTixing;
			char Xuanze1,Xuanze3;
			int Xuanze2;
			typedef string XINXI;
			XINXI xx1;
			XINXI xx2;
			XINXI xx3;
			XINXI xx4;
			string Yidong = "w�����ƶ���a�����ƶ���s�����ƶ���d�����ƶ���";
			string Zaozuo = "g������k���ܣ�space��Ծ��";
			IFBEGIN:
				WenziTixing = "�Ƿ�ʼ����YorN����";
				cout << WenziTixing << endl;
				Xuanze1 = _getch();
				cout << Xuanze1 << endl;
				{
					if ( Xuanze1 == 'Y')
					{
						switchbegin1:
							cout << "��Ϸ��ʼ�� " << endl;
							cout << "����������" ; 
							cout << Yidong << endl;
							cout << Zaozuo << endl;
							cout << "��ȡboss��Ϣ��" << endl;
							WXX.getinfo();
							JJ.getinfo();
							WenziTixing = "ѡ��BOSS��wxx(1)����jj(2)��";
							cout << WenziTixing << endl;
							Xuanze2 = _getch();
							cout << static_cast<char>(Xuanze2) << endl;
							{
								if (Xuanze2 == '1')
								{
									
									//Num();//(��֧��c++11�ı�������Ļ�����
									While1: 
									int i = 0;
									while (i <= WXX.getHP())
									{
										WXX.Attack(Maozi);
										xx1 = "�㱻������";
										cout << xx1 << endl;
										if (static_cast<int>(Maozi.getHP()) < 0)
										{
											xx1 = "�����ˣ���Ϸ������";
											cout << xx1 << endl;
											goto Gameend1;
										}
										xx2 = "�㵱ǰ��Ѫ����";
										cout <<xx2 << Maozi.getHP() << endl;
										forbegin:
										cout << "������в����ˡ�" << endl;
										Forbegin1:
											if (kongzhi9() != true)
											{
												goto forbegin;
											}
											else
											{
												Maozi.Attack(WXX); 
												cout << "�㹥����boss������bossѪ��Ϊ" << WXX.getHP() << endl; 
												goto While1; 	
											}
									}
									Gameend1:
										xx1 = "�Ƿ����¿�ʼ����YorN��";
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
										cout << "��˵,��������Y����N��" << endl;
										goto Gameend1;
										}
								}
								else if (Xuanze2 == '2')
								{
									//Num();//(��֧��c++11�ı�������Ļ�����
									While2: 
									int q = 0;
									{
										JJ.Attack(Maozi);
										xx3 = "�㱻������";
										cout << xx3 << endl;
										if (static_cast<int>(Maozi.getHP()) < 0)
										{
											xx4 = "�����ˣ���Ϸ������";
											cout << xx4 << endl;
											goto Gameend2;
										}
										xx3 = "�㵱ǰ��Ѫ����";
										cout << xx3 << Maozi.getHP() << endl;
										forbegin2:
										cout << "������в����ˡ�" << endl;
											if (kongzhi9() != true)
											{
												goto forbegin2;
											}
											else
											{
												Maozi.Attack(JJ); 
												cout << "�㹥����boss������bossѪ��Ϊ" << JJ.getHP() << endl; 
												goto While2; 	
											}
									}
									Gameend2:
										xx2 = "�Ƿ����¿�ʼ����YorN��";
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
										cout << "��˵,��������Y����N��" << endl;
										goto Gameend2;
										}
								}
								else
								{
									cout << "��˵,��������1����2��" << endl;
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
						cout << "��˵,��������Y����N��" << endl << endl;
						goto IFBEGIN;
					}
				}
				End:
				cout << "��Ϸ������" << endl;
				system("pause");
				return 0;
		}
} 

