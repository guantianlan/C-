//ͷ�ļ�
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

//����ṹ��
struct student
{
    int id = 0;
    string name;
    double score[6] = { 0 };
    double sum = 0;
    double average = 0;
    int paiming = 0;
};

//ȫ�ֱ���
student stu[30];
double stu_num;
int i = 0, j = 0;
double class_num = 0;
double class_sum = 0;
double class_sums[6] = { 0 };
double class_average = 0;
double class_averages[6] = { 0 };
double score_sum = 0;
double score_sums[30] = { 0 };
double score_average = 0;
int stu_paiming[30] = { 0 };

//¼��ÿ��ѧ����ѧ�š������͸��ƿ��Գɼ�
void input()
{
    cout << "����ѧ�š����ֺͷ���" << endl;
    for (i = 0; i < stu_num; i++)
    {
        cin >> stu[i].id >> stu[i].name;
        for (j = 0; j < class_num; j++)
        {
            cin >> stu[i].score[j];
        }
    }
}

//���ÿ�ſγ̵��ֺܷ�ƽ����
void shuchu1()
{
    for (i = 0; i < class_num; i++)
    {
        cout << "��" << i + 1 << "���ܷ֣�" << class_sums[i] << " ƽ����:" << " " << class_averages[i] << endl;
        cout << "-------------------------" << endl;
    }
}

//����ÿ�ſγ̵��ֺܷ�ƽ����
void jisuan1()
{
    for (j = 0; j < class_num; j++)
    {
        class_sum = 0;
        for (i = 0; i < stu_num; i++)
        {
            class_sum = class_sum + stu[i].score[j];
        }
        class_sums[j] = class_sum;
        class_averages[j] = class_sums[j] / stu_num;
    }
}



//���ÿ��ѧ�����ֺܷ�ƽ����
void shuchu2()
{

    for (i = 0; i < stu_num; i++)
    {
        cout << fixed << setprecision(2);
        cout << stu[i].name << " ���ܷ֣�" << stu[i].sum << "," << "ƽ���֣�" << " " << stu[i].average << endl;
        cout << "-------------------------" << endl;
    }
}

//����ÿ��ѧ�����ֺܷ�ƽ����
void jisuan2()
{
    for (i = 0; i < stu_num; i++)
    {
        score_sum = 0;
        for (j = 0; j < class_num; j++)
        {
            score_sum = score_sum + stu[i].score[j];
        }
        stu[i].sum = score_sum;
        //score_sums[i] = score_sum;
        //score_averages[i] = stu[i].sum / class_num;
        stu[i].average = stu[i].sum / class_num;
    }
}

//��ÿ��ѧ�����ܷ��ɸߵ����ų����α�
void jisuan_paiming()
{
    int t, temp, x = 1;
    for (i = 0; i < stu_num; i++)
    {
        score_sums[i] = stu[i].sum;
    }
    for (i = 0; i < stu_num; i++)
    {
        if (score_sums[i] != 0)
        {
            temp = score_sums[i];
            t = i;
            for (j = 0; j < stu_num; j++)
            {
                if (temp < score_sums[j])
                {
                    temp = score_sums[j];
                    t = j;
                }
            }
            score_sums[t] = 0;
            stu[t].paiming = x;
            x++;
            if (i != t)
            {
                i--;
            }
        }
    }

}

//���ÿ��ѧ�����ܷ��ɸߵ����ų����α�
void shuchu_paiming1()
{
    for (i = 0; i < stu_num; i++)
    {
        for (j = 0; j < stu_num; j++)
        {
            if (i + 1 == stu[j].paiming)
            {
                cout << stu[j].name << ":" << stu[j].sum << endl;
                cout << "------------------" << endl;
            }
        }
    }
}

//���ÿ��ѧ�����ܷ��ɵ͵����ų����α�
void shuchu_paiming2()
{
    for (i = stu_num; i > 0; i--)
    {
        for (j = 0; j < stu_num; j++)
        {
            if (i == stu[j].paiming)
            {
                cout << stu[j].name << ":" << stu[j].sum << endl;
                cout << "------------------" << endl;
            }
        }
    }
}

//��ѧ����С�����ų��ɼ���
void xuehao1()
{
    int y = 0; int len = 0;
    cout << "ѧ��" << "\t" << "����" << "\t\t";
    for (i = 0; i < class_num; i++)
    {
        cout << "�γ�" << i + 1 << "\t";
    }
    cout << "�ܷ�" << "\t" << "ƽ����" << "\t" << "����" << endl;

    int z = 0;
    for (y = 0; 1; y++)
    {

        for (i = 0; i < stu_num; i++)
        {
            if (y == stu[i].id)
            {
                len = stu[i].name.size();
                if (len > 8)
                {
                    cout << stu[i].id << "\t" << stu[i].name << "\t";
                }
                else if (len <= 8)
                {
                    cout << stu[i].id << "\t" << stu[i].name << "\t\t";
                }
                for (j = 0; j < class_num; j++)
                {
                    cout << stu[i].score[j] << "\t";
                }
                cout << stu[i].sum << "\t" << stu[i].average << "\t" << stu[i].paiming << endl;
                z++;
            }
        }
        if (z == stu_num) break;
    }
}


//���������ֵ�˳���ų��ɼ���
void xingming1()
{
    int y = 0; int len = 0;
    cout << "ѧ��" << "\t" << "����" << "\t\t";
    for (i = 0; i < class_num; i++)
    {
        cout << "�γ�" << i + 1 << "\t";
    }
    cout << "�ܷ�" << "\t" << "ƽ����" << "\t" << "����" << endl;

    char x; int z = 0; char a;
    for (x = 97; x <= 122; x++)
    {
        for (i = 0; i < stu_num; i++)
        {
            len = stu[i].name.size();
            a = stu[i].name[0];
            if (x == a)
            {
                if (len > 8)
                {
                    cout << stu[i].id << "\t" << stu[i].name << "\t";
                }
                else if (len <= 8)
                {
                    cout << stu[i].id << "\t" << stu[i].name << "\t\t";
                }
                for (j = 0; j < class_num; j++)
                {
                    cout << stu[i].score[j] << "\t";
                }
                cout << stu[i].sum << "\t" << stu[i].average << "\t" << stu[i].paiming << endl;
                z++;
            }

        }
        if (z == stu_num)
        {
            break;
        }
    }
}

//��ѧ�Ų�ѯѧ���������俼�Գɼ�
void xuehao2()
{
    int x;
    cout << "������ѧ�ţ�";
    cin >> x;
    cout << endl;

    cout << "����" << "\t\t";
    for (i = 0; i < class_num; i++)
    {
        cout << "�γ�" << i + 1 << "\t";
    }
    cout << "�ܷ�" << "\t" << "ƽ����" << "\t" << "����" << endl;


    for (i = 0; i < stu_num; i++)
    {
        if (x == stu[i].id)
        {
            cout << stu[i].name << "\t\t";
            for (j = 0; j < class_num; j++)
            {
                cout << stu[i].score[j] << "\t";
            }
            cout << stu[i].sum << "\t" << stu[i].average << "\t" << stu[i].paiming << endl;
        }
    }
}

//��������ѯѧ���������俼�Գɼ�
void xingming2()
{
    string x;
    cout << "������������";
    cin >> x;
    cout << endl;

    cout << "ѧ��" << "\t";
    for (i = 0; i < class_num; i++)
    {
        cout << "�γ�" << i + 1 << "\t";
    }
    cout << "�ܷ�" << "\t" << "ƽ����" << "\t" << "����" << endl;


    for (i = 0; i < stu_num; i++)
    {
        if (x == stu[i].name)
        {
            cout << stu[i].id << "\t";
            for (j = 0; j < class_num; j++)
            {
                cout << stu[i].score[j] << "\t";
            }
            cout << stu[i].sum << "\t" << stu[i].average << "\t" << stu[i].paiming << endl;
        }
    }
}

//��ÿ�ſγ̷ֱ�ͳ��ÿ�����������Լ���ռ�İٷֱ�
//�����㣨90~100�������ã�80~89�����еȣ�70~79��������60~69����������0~59��5�����
void tongji()
{
    double a = 0, b = 0, c = 0, d = 0, e = 0;
    for (j = 0; j < class_num; j++)
    {
        a = 0; b = 0; c = 0; d = 0; e = 0;
        for (i = 0; i < stu_num; i++)
        {
            if (stu[i].score[j] >= 90)
            {
                a++;
            }
            else if (stu[i].score[j] >= 80)
            {
                b++;
            }
            else if (stu[i].score[j] >= 70)
            {
                c++;
            }
            else if (stu[i].score[j] >= 60)
            {
                d++;
            }
            else if (stu[i].score[j] < 60)
            {
                e++;
            }
        }
        cout << fixed << setprecision(2);
        cout << "�γ�" << j + 1 << endl
            << "����" << a << "��" << " �ٷֱ�Ϊ��" << a / stu_num << endl
            << "����" << b << "��" << " �ٷֱ�Ϊ��" << b / stu_num << endl
            << "�е�" << c << "��" << " �ٷֱ�Ϊ��" << c / stu_num << endl
            << "����" << d << "��" << " �ٷֱ�Ϊ��" << d / stu_num << endl
            << "������" << e << "��" << " �ٷֱ�Ϊ��" << e / stu_num << endl;
        cout << "--------------------" << endl;
    }
}


//���ÿ��ѧ����ѧ�š����������ƿ��Գɼ����Լ�ÿ�ſγ̵��ֺܷ�ƽ����
void shuchu3()
{
    int len = 0;
    cout << "ѧ��" << "\t" << "����" << "\t\t";
    for (i = 0; i < class_num; i++)
    {
        cout << "�γ�" << i + 1 << "\t";
    }
    cout << "�ܷ�" << "\t" << "ƽ����" << "\t" << "����" << endl;


    for (i = 0; i < stu_num; i++)
    {
        len = stu[i].name.size();
        if (len > 8)
        {
            cout << stu[i].id << "\t" << stu[i].name << "\t";
        }
        else if (len <= 8)
        {
            cout << stu[i].id << "\t" << stu[i].name << "\t\t";
        }
        for (j = 0; j < class_num; j++)
        {
            cout << stu[i].score[j] << "\t";
        }
        cout << stu[i].sum << "\t" << stu[i].average << "\t" << stu[i].paiming << endl;
    }
}

//�ָ�ѧ���ɼ�����
void huifu()
{
    ifstream cins;
    cins.open("file1", ios::in);
    if (!cins)
    {
        cerr << "��ʧ��" << endl;
        exit(1);
    }

    for (int x = 0; x < stu_num; x++)
    {

        cins >> stu[x].id >> stu[x].name;

        for (j = 0; j < class_num; j++)
        {
            cins >> stu[x].score[j];
        }
    }
    cins.close();
}

//����ѧ���ɼ�����
void beifen()
{
    ofstream couts;
    couts.open("file1", ios::out);
    if (!couts)
    {
        cerr << "��ʧ��" << endl;
        exit(1);
    }
    cout << "������ݵ�ѧ�š����������Ƴɼ�" << endl;
    for (int x = 0; x < stu_num; x++)
    {

        cin >> stu[x].id >> stu[x].name;

        for (j = 0; j < class_num; j++)
        {
            cin >> stu[x].score[j];
        }
    }
    for (int x = 0; x < stu_num; x++)
    {

        couts << stu[x].id << " " << stu[x].name << " ";

        for (j = 0; j < class_num; j++)
        {
            couts << stu[x].score[j] << " ";
        }
    }
    couts.close();
}








int main()
{
    cout << "��������(������30��)" << endl;
    cin >> stu_num;
    if (stu_num > 30 || stu_num <= 0)
    {
        cout << "�������" << endl;
        while (1)
        {
            cin >> stu_num;
            if (stu_num > 30 || stu_num <= 0)
            {
                cout << "�������" << endl;
            }
            else
            {
                break;
            }
        }
    }
    cout << "����γ�����(С�ڵ���6)" << endl;
    cin >> class_num;
    if (class_num > 6 || class_num <= 0)
    {
        cout << "�������" << endl;
        while (1)
        {
            cin >> class_num;
            if (class_num > 6 || class_num <= 0)
            {
                cout << "�������" << endl;
            }
            else
            {
                break;
            }
        }
    }

    int option;
    while (1)
    {
        cout << "�˵�" << endl
            << "1.¼��ÿ��ѧ����ѧ�š������͸��ƿ��Գɼ�" << endl
            << "2.����ÿ�ſγ̵��ֺܷ�ƽ����" << endl
            << "3.����ÿ��ѧ�����ֺܷ�ƽ����" << endl
            << "4.��ÿ��ѧ�����ܷ��ɸߵ����ų����α�" << endl
            << "5.��ÿ��ѧ�����ܷ��ɵ͵����ų����α�" << endl
            << "6.��ѧ����С�����ų��ɼ���" << endl
            << "7.���������ֵ�˳���ų��ɼ���" << endl
            << "8.��ѧ�Ų�ѯѧ���������俼�Գɼ�" << endl
            << "9.��������ѯѧ���������俼�Գɼ�" << endl
            << "10.��ÿ�ſγ̷ֱ�ͳ��ÿ�����������Լ���ռ�İٷֱ�" << endl
            << "11.���ÿ��ѧ����ѧ�š����������ƿ��Գɼ����Լ�ÿ�ſγ̵��ֺܷ�ƽ����" << endl
            << "12.�ָ�ѧ���ɼ�����" << endl
            << "13.����ѧ���ɼ�����" << endl
            << "0.�˳�����" << endl
            << "Please Input your choice:" << endl;


        cin >> option;
        switch (option)
        {
        case 1:input(); jisuan1(); jisuan2(); jisuan_paiming();
            break;
        case 2:shuchu1();
            break;
        case 3:shuchu2();
            break;
        case 4:shuchu_paiming1();
            break;
        case 5:shuchu_paiming2();
            break;
        case 6:xuehao1();
            break;
        case 7:xingming1();
            break;
        case 8:xuehao2();
            break;
        case 9:xingming2();
            break;
        case 10:tongji();
            break;
        case 11:shuchu3();
            break;
        case 12:huifu(); jisuan1(); jisuan2(); jisuan_paiming();
            break;
        case 13:beifen();
            break;
        case 0:
            return 0;
        default:
            cout << "�������" << endl;
        }
    }
}
