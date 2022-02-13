#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
#define MAX_KIND_SIZE 2//자동화구현에서 추가해야하는 부분1(추가가 아닌 값 수정)
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
		memcpy(m_year, a_year, len);//두개가 선언시에 길이가 달랐어도 사용가능한 문자열복사함수
		printf("%d %d %s:초기화완료\n", strlen(a_year), strlen(m_year), m_year);
		len = strlen(a_name) + 1;
		m_name = new char[len];
		memcpy(m_name, a_name, len);
		printf("%d %d %s:초기화완료\n", strlen(a_name), strlen(m_name), m_name);
	}
}bookInfo;
class Book {
public:
	virtual char* GetName() { return NULL; }
	HANDLE SetString(unsigned int ap_book_count);
};
class Inmune :public Book {
public:
	char* GetName() { return (char*)"인문"; }
};
class NatureSci :public Book {
public:
	char* GetName() { return (char*)"자연과학"; }
};
Book* gp_book_table[MAX_KIND_SIZE] = { new Inmune, new NatureSci };//자동화구현에서 추가해야하는 부분2
vector<vector<bookInfo>> total_book_list;
vector<bookInfo> Inmune_book_list;//자동화구현에서 추가해야하는 부분3
vector<bookInfo> NatureSci_book_list;//자동화구현에서 추가해야하는 부분4

//자동화구현에서 추가해야하는 부분5(push_back코드)
void Initialize_2dim_vector()
{
	total_book_list.push_back(Inmune_book_list);
	total_book_list.push_back(NatureSci_book_list);
}


void Print_2dim_vector()
{
	int row_count = total_book_list.size();
	int col_count = total_book_list[0].size();
	printf("데이터를 출력합니다:\n");
	printf("%8s%8s%8s%8s\n", "이름", "출판일", "작가", "출판사");
	for (int i = 0; i < row_count; i++) {
		col_count = total_book_list[i].size();
		for (int j = 0; j < col_count; j++) {
			printf("%8s%8s%8s%8s\n", total_book_list[i].at(j).m_name, total_book_list[i].at(j).m_year, total_book_list[i].at(j).m_owner.author, total_book_list[i].at(j).m_owner.company);
		}
	}
}

void Print_1dim_vector(unsigned int select)
{
	printf("%s 분야의 데이터를 출력합니다:\n", gp_book_table[select]->GetName());
	printf("%10s%8s%8s%8s%8s\n", "책 지정번호", "이름", "출판일", "작가", "출판사");
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
				printf("%8s%8s%8s%8s:\n", "이름", "제작년도", "작가", "출판사");
				printf("%8s%8s%8s%8s\n", temp.m_name, temp.m_year, temp.m_owner.author, temp.m_owner.company);
				return;
			}
			else
			{
				continue;
			}
		}
	}
	printf("찾으려는 데이터와 일치하는 메모리주소가 없습니다\n");
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
				printf("%8s%8s%8s%8s:\n", "이름", "제작년도", "작가", "출판사");
				printf("%8s%8s%8s%8s\n", temp.m_name, temp.m_year, temp.m_owner.author, temp.m_owner.company);
				return;
			}
			else
			{
				continue;
			}
		}
	}
	printf("찾으려는 데이터와 일치하는 메모리주소가 없습니다\n");
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
			printf("%d %d:문자열길이비교\n", strlen(total_book_list[i][j].m_name), strlen(ap_book_name));
			printf("%d:strcmp결과\n", strcmp(total_book_list[i][j].m_name, ap_book_name));
			if (strcmp(total_book_list[i][j].m_name, ap_book_name) == 0) {
				printf("삭제합니다: %8s%8s%8s%8s:\n", "이름", "제작년도", "작가", "출판사");
				printf("\t\t%8s%8s%8s%8s\n", total_book_list[i][j].m_name, total_book_list[i][j].m_year, total_book_list[i][j].m_owner.author, total_book_list[i][j].m_owner.company);
				total_book_list[i].erase(total_book_list[i].begin() + j);
				printf("삭제한 뒤 %s 분야 책 목록:\n", gp_book_table[i]->GetName());
				Print_1dim_vector(i);
				return;
			}
			else
			{
				continue;
			}
		}
	}
	printf("찾으려는 데이터와 일치하는 메모리주소가 없습니다\n");
}


HANDLE Book::SetString(unsigned int ap_book_count)
{
	int select;
	printf("어떤 분야를 추가하나요?: ");
	int i;
	for (i = 0; i < MAX_KIND_SIZE; i++) {
		printf("%d. %s  ", i, gp_book_table[i]->GetName());
	}
	scanf("%d", &select);
	char ap_name[40] = { 0, };
	char ap_year[20] = { 0, };
	reg a_owner;
	//bookInfo구조체 변수 초기화
	//linked List기반 데이터 구현 : 데이터 저장
	printf("책 이름: ");
	rewind(stdin);
	scanf("%s", ap_name);
	printf("출판년도: ");
	rewind(stdin);
	scanf("%s", ap_year);
	printf("저자 : ");
	rewind(stdin);
	scanf("%s", a_owner.author);
	printf("출판사: ");
	rewind(stdin);
	scanf("%s", a_owner.company);

	//select_num을 통해서 몇 번째 클래스인지(무슨 분야인지 정해줌)
	char buf[3] = { 0, };//앞,뒤 중 어디에 넣을지 받는 변수(한글 한 글자가 2바이트+널문자용1바이트)
	HANDLE ins_loc;
	int ins_idx;
	
	Print_1dim_vector(select);
	if (total_book_list[select].size()) {
		printf("어느위치에 추가하시겠어요?: (핸들값 입력)");
		scanf("%d", &ins_loc);
		for (ins_idx = 0; i < total_book_list[select].size(); ins_idx++) {
			if (total_book_list[select].at(ins_idx).m_h == ins_loc)
				break;
			else
				continue;
		}
		printf("앞, 뒤 중에 어디에 추가할까요?: (앞,뒤 입력)");
		scanf("%s", buf);
		if (strcmp(buf, "앞") == 0)	total_book_list[select].insert(total_book_list[select].begin() + ins_idx, bookInfo(ap_year, ap_name, a_owner, ap_book_count + 1));
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
		printf("도서관리시스템입니다. 어떤 작업을 하시겠습니까?\n");
		printf(" [ Menu ] ");
		printf(" 1. AddBook  2. FindBook  3. DeleteBook  4. PrintAllList  5. Exit :");
		rewind(stdin);
		scanf_s("%d", &select);
		if (select == 5)	break;
		if (select == 1) {
			//AddBook에서 입력받은 최대 배열크기를 초과하지 않을때만 book_count증가
			int handle = book->SetString(book_count);//핸들값을 SetString에서 반환
			if (handle) {//handle!=0
				printf("책이 정상적으로 추가되었습니다!\n");
				book_count++;
			}
		}
		else if (select == 2) {
			printf("찾으려는 책 이름 :");
			rewind(stdin);
			scanf("%s", find_book_name);
			rewind(stdin);//표준입력함수 쓴뒤에는 반드시 rewind사용
			FindBook(find_book_name);
		}
		else if (select == 3) {
			printf("삭제하려는 책 이름 :");
			rewind(stdin);
			scanf("%s", delete_book_name);
			DeleteBook(delete_book_name);
		}
		else {
			Print_2dim_vector();
		}
	}
	//객체소멸자 호출
	delete book;
	for (int i = 0; i < MAX_KIND_SIZE; i++)
		delete[] gp_book_table[i];

}