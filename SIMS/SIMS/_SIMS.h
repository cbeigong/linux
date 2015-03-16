#ifndef __SIMS__
#define __SIMS__
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
#define PWD_LEN 10
#define NAME_LEN 20
#define LINE_LEN 512
#define CONFIRM_CNT 3
#define M1 "1.search	student		information"
#define M2 "2.update	student		information"
#define M3 "3.delete	student		information"
#define M4 "4.add		student		information"
#define M5 "5.search	user		account"
#define M6 "6.update	user		account"
#define M7 "7.delete	user		account"
#define M8 "8.add		user		account"
#define M9 "9.exit"
typedef struct stu_accout_tag
{
	char m_passwd[PWD_LEN];
	char m_name[20];
	int  m_role;
	struct stu_accout_tag* m_next;
}ACCOUNT, *pACCOUNT;
typedef struct stu_info_tag
{
	int m_id;
	char m_name[NAME_LEN];
	char m_gender;
	double m_socres[5];
	struct stu_info_tag* m_next;
}STU, *pSTU;
int show_search_menu(int role);
void system_init(char* config, pACCOUNT* pphead_acc, pSTU* pphead_stu);
int role_confirm(pACCOUNT phead_acc);
int show_system_menu(int role);
void search_usr_info_by_id(pSTU stu_list, int search_id);
void search_usr_info_by_name(pSTU stu_list,char* search_name);
void search_usr_account(account_list, search_name);
void search_usr_info_all(pSTU stu_list);
pSTU update_usr_info(pSTU stu_list, int search_id);
pACCOUNT update_usr_account(pACCOUNT account_list, char* search_name);
pSTU delete_usr_info(pSTU* stu_list,/* &usr_info_num*/int search_id);
pSTU add_usr_info(pSTU* stu_list/*, &usr_infor_num*/);
pACCOUNT delete_usr_account(pACCOUNT* account_list,/* &usr_account_num,*/ char* search_name);
pACCOUNT add_usr_account(pACCOUNT* account_list /*,&usr_account_num*/);
void save_data_to_file(char* config,pACCOUNT account_list,pSTU stu_list);
#endif