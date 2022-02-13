#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
#define MAX_KIND_SIZE 2//�ڵ�ȭ�������� �߰��ؾ��ϴ� �κ�1(�߰��� �ƴ� �� ����)
#define MAX_ONE_CATEGORY 260
#define MAX_LEN 32
typedef unsigned int HANDLE;
typedef struct reg {
	char author[20];
	char company[20];
}reg;
typedef struct bookInfo {
	char* m_year;
	char* m_name;
	reg m_owner;
	HANDLE m_h;
	//bookInfo() {}
	bookInfo(char a_year[], char a_name[], reg a_owner, HANDLE a_h)
		:m_owner(a_owner), m_h(a_h)
	{
		int len = strlen(a_year) + 1;
		m_year = new char[len];
		memcpy(m_year, a_year, len);//�ΰ��� ����ÿ� ���̰� �޶�� ��밡���� ���ڿ������Լ�
		printf("%d %d %s:�ʱ�ȭ�Ϸ�\n", strlen(a_year), strlen(m_year), m_year);
		len = strlen(a_name) + 1;
		m_name = new char[len];
		memcpy(m_name, a_name, len);
		printf("%d %d %s:�ʱ�ȭ�Ϸ�\n", strlen(a_name), strlen(m_name), m_name);
	}
}bookInfo;
class Book {
public:
	virtual char* GetName() { return NULL; }
	HANDLE SetString(unsigned int ap_book_count);
};
class Inmune :public Book {
public:
	char* GetName() { return (char*)"�ι�"; }
};
class NatureSci :public Book {
public:
	char* GetName() { return (char*)"�ڿ�����"; }
};
Book* gp_book_table[MAX_KIND_SIZE] = { new Inmune, new NatureSci };//�ڵ�ȭ�������� �߰��ؾ��ϴ� �κ�2
vector<vector<bookInfo>> total_book_list;
vector<bookInfo> Inmune_book_list;//�ڵ�ȭ�������� �߰��ؾ��ϴ� �κ�3
vector<bookInfo> NatureSci_book_list;//�ڵ�ȭ�������� �߰��ؾ��ϴ� �κ�4

//�ڵ�ȭ�������� �߰��ؾ��ϴ� �κ�5(push_back�ڵ�)
void Initialize_2dim_vector()
{
	total_book_list.push_back(Inmune_book_list);
	total_book_list.push_back(NatureSci_book_list);
}


void Print_2dim_vector()
{
	int row_count = total_book_list.size();
	int col_count = total_book_list[0].size();
	printf("�����͸� ����մϴ�:\n");
	printf("%8s%8s%8s%8s\n", "�̸�", "������", "�۰�", "���ǻ�");
	for (int i = 0; i < row_count; i++) {
		col_count = total_book_list[i].size();
		for (int j = 0; j < col_count; j++) {
			printf("%8s%8s%8s%8s\n", total_book_list[i].at(j).m_name, total_book_list[i].at(j).m_year, total_book_list[i].at(j).m_owner.author, total_book_list[i].at(j).m_owner.company);
		}
	}
}

void Print_1dim_vector(unsigned int select)
{
	printf("%s �о��� �����͸� ����մϴ�:\n", gp_book_table[select]->GetName());
	printf("%10s%8s%8s%8s%8s\n", "å ������ȣ", "�̸�", "������", "�۰�", "���ǻ�");
	int col_count = total_book_list[select].size();
	for (int j = 0; j < col_count; j++) {
		printf("%-4d.%8s%8s%8s%8s\n", total_book_list[select].at(j).m_h, total_book_list[select].at(j).m_name, total_book_list[select].at(j).m_year, total_book_list[select].at(j).m_owner.author, total_book_list[select].at(j).m_owner.company);
	}
}

/*
void FindBook(HANDLE a_h)
{
	int row_count = total_book_list.size();
	int col_count = total_book_list[0].size();
	for (int i = 0; i < row_count; i++) {
		int j;
		col_count = total_book_list[i].size();
		for (j = 0; j < col_count; j++) {
			if (total_book_list[i][j].m_h == a_h) {
				bookInfo temp = { total_book_list[i][j].m_year, total_book_list[i][j].m_name, total_book_list[i][j].m_owner, total_book_list[i][j].m_h };
				printf("%8s%8s%8s%8s:\n", "�̸�", "���۳⵵", "�۰�", "���ǻ�");
				printf("%8s%8s%8s%8s\n", temp.m_name, temp.m_year, temp.m_owner.author, temp.m_owner.company);
				return;
			}
			else
			{
				continue;
			}
		}
	}
	printf("ã������ �����Ϳ� ��ġ�ϴ� �޸��ּҰ� �����ϴ�\n");
}
*/

void FindBook(const char* ap_book_name)
{
	int row_count = total_book_list.size();
	int col_count = total_book_list[0].size();
	for (int i = 0; i < row_count; i++) {
		int j;
		col_count = total_book_list[i].size();
		for (j = 0; j < col_count; j++) {
			printf("%s %s\n", total_book_list[i][j].m_name, ap_book_name);
			if (strcmp(total_book_list[i][j].m_name, ap_book_name) == 0) {
				bookInfo temp = { total_book_list[i][j].m_year, total_book_list[i][j].m_name, total_book_list[i][j].m_owner, total_book_list[i][j].m_h };
				printf("%8s%8s%8s%8s:\n", "�̸�", "���۳⵵", "�۰�", "���ǻ�");
				printf("%8s%8s%8s%8s\n", temp.m_name, temp.m_year, temp.m_owner.author, temp.m_owner.company);
				return;
			}
			else
			{
				continue;
			}
		}
	}
	printf("ã������ �����Ϳ� ��ġ�ϴ� �޸��ּҰ� �����ϴ�\n");
}


void DeleteBook(const char* ap_book_name)
{
	int row_count = total_book_list.size();
	int col_count = total_book_list[0].size();
	for (int i = 0; i < row_count; i++) {
		int j;
		col_count = total_book_list[i].size();
		for (j = 0; j < col_count; j++) {
			printf("%s %s\n", total_book_list[i][j].m_name, ap_book_name);
			printf("%d %d:���ڿ����̺�\n", strlen(total_book_list[i][j].m_name), strlen(ap_book_name));
			printf("%d:strcmp���\n", strcmp(total_book_list[i][j].m_name, ap_book_name));
			if (strcmp(total_book_list[i][j].m_name, ap_book_name) == 0) {
				printf("�����մϴ�: %8s%8s%8s%8s:\n", "�̸�", "���۳⵵", "�۰�", "���ǻ�");
				printf("\t\t%8s%8s%8s%8s\n", total_book_list[i][j].m_name, total_book_list[i][j].m_year, total_book_list[i][j].m_owner.author, total_book_list[i][j].m_owner.company);
				total_book_list[i].erase(total_book_list[i].begin() + j);
				printf("������ �� %s �о� å ���:\n", gp_book_table[i]->GetName());
				Print_1dim_vector(i);
				return;
			}
			else
			{
				continue;
			}
		}
	}
	printf("ã������ �����Ϳ� ��ġ�ϴ� �޸��ּҰ� �����ϴ�\n");
}


HANDLE Book::SetString(unsigned int ap_book_count)
{
	int select;
	printf("� �о߸� �߰��ϳ���?: ");
	int i;
	for (i = 0; i < MAX_KIND_SIZE; i++) {
		printf("%d. %s  ", i, gp_book_table[i]->GetName());
	}
	scanf("%d", &select);
	char ap_name[40] = { 0, };
	char ap_year[20] = { 0, };
	reg a_owner;
	//bookInfo����ü ���� �ʱ�ȭ
	//linked List��� ������ ���� : ������ ����
	printf("å �̸�: ");
	rewind(stdin);
	scanf("%s", ap_name);
	printf("���ǳ⵵: ");
	rewind(stdin);
	scanf("%s", ap_year);
	printf("���� : ");
	rewind(stdin);
	scanf("%s", a_owner.author);
	printf("���ǻ�: ");
	rewind(stdin);
	scanf("%s", a_owner.company);

	//select_num�� ���ؼ� �� ��° Ŭ��������(���� �о����� ������)
	char buf[3] = { 0, };//��,�� �� ��� ������ �޴� ����(�ѱ� �� ���ڰ� 2����Ʈ+�ι��ڿ�1����Ʈ)
	HANDLE ins_loc;
	int ins_idx;
	
	Print_1dim_vector(select);
	if (total_book_list[select].size()) {
		printf("�����ġ�� �߰��Ͻðھ��?: (�ڵ鰪 �Է�)");
		scanf("%d", &ins_loc);
		for (ins_idx = 0; i < total_book_list[select].size(); ins_idx++) {
			if (total_book_list[select].at(ins_idx).m_h == ins_loc)
				break;
			else
				continue;
		}
		printf("��, �� �߿� ��� �߰��ұ��?: (��,�� �Է�)");
		scanf("%s", buf);
		if (strcmp(buf, "��") == 0)	total_book_list[select].insert(total_book_list[select].begin() + ins_idx, bookInfo(ap_year, ap_name, a_owner, ap_book_count + 1));
		else
		{
			total_book_list[select].insert(total_book_list[select].begin() + ins_idx + 1, bookInfo(ap_year, ap_name, a_owner, ap_book_count + 1));
		}
	}
	else {
		total_book_list[select].push_back(bookInfo(ap_year, ap_name, a_owner, ap_book_count + 1));
	}

	return ap_book_count + 1;
}
void main()
{
	int select = 0;;
	unsigned int book_count = 0;
	Book* book = new Book;
	Initialize_2dim_vector();
	char find_book_name[MAX_LEN] = { 0, };
	char delete_book_name[MAX_LEN] = { 0, };
	while (1) {
		printf("���������ý����Դϴ�. � �۾��� �Ͻðڽ��ϱ�?\n");
		printf(" [ Menu ] ");
		printf(" 1. AddBook  2. FindBook  3. DeleteBook  4. PrintAllList  5. Exit :");
		rewind(stdin);
		scanf_s("%d", &select);
		if (select == 5)	break;
		if (select == 1) {
			//AddBook���� �Է¹��� �ִ� �迭ũ�⸦ �ʰ����� �������� book_count����
			int handle = book->SetString(book_count);//�ڵ鰪�� SetString���� ��ȯ
			if (handle) {//handle!=0
				printf("å�� ���������� �߰��Ǿ����ϴ�!\n");
				book_count++;
			}
		}
		else if (select == 2) {
			printf("ã������ å �̸� :");
			rewind(stdin);
			scanf("%s", find_book_name);
			rewind(stdin);//ǥ���Է��Լ� ���ڿ��� �ݵ�� rewind���
			FindBook(find_book_name);
		}
		else if (select == 3) {
			printf("�����Ϸ��� å �̸� :");
			rewind(stdin);
			scanf("%s", delete_book_name);
			DeleteBook(delete_book_name);
		}
		else {
			Print_2dim_vector();
		}
	}
	//��ü�Ҹ��� ȣ��
	delete book;
	for (int i = 0; i < MAX_KIND_SIZE; i++)
		delete[] gp_book_table[i];

}