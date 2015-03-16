#include "_SIMS.h"
int main(int argc, char* argv[])
{
	char search_name[NAME_LEN];
	int search_id;
	pACCOUNT account_list = NULL;
	pSTU stu_list = NULL;
	int role;
	int select;
	system_init(argv[1], &account_list, &stu_list);

	if ((role = role_confirm(account_list)) == -1)
	{
		system("cls");
		printf("\n user account not exist or user password wrong!\n");
		fflush(stdout);
		//system("pause");
		return 0;
	}
	while (system("cls"), (select = show_system_menu(role)) != 9)
	{
		if (role == 1)
		{
			switch (select)
			{
			case 1:
			{
					  while (fflush(stdin), (select = show_search_menu(role)) != 3)
					  {
						  if (select == 2)
						  {
							  system("cls");
							  printf("Enter search id: ");
							  fflush(stdout);
							  fflush(stdin);
							  scanf("%d", &search_id);
							  search_usr_info_by_id(stu_list, search_id);
							  getchar();
							  getchar();
						  }
						  else if (select == 1)
						  {
							  system("cls");
							  printf("Enter search name : ");
							  fflush(stdout);
							  fflush(stdin);
							  //??????
							  scanf("%s", search_name);
							  search_usr_info_by_name(stu_list, search_name);
							  getchar();
							  getchar();
						  }
						  else
						  {
							  search_usr_info_all(stu_list);
							  getchar();
							  getchar();
						  }
					  }
			}
				break;
			case 2:
			{
					  system("cls");
					  printf("Enter update id: ");
					  fflush(stdout);
					  fflush(stdin);
					  scanf("%d", &search_id);
					  update_usr_info(stu_list, search_id);
					  getchar();
					  getchar();
			}
				break;
			case 3:
			{
					  system("cls");
					  printf("Enter delete id: ");
					  fflush(stdin);
					  fflush(stdout);
					  //id 的输入 输出错误在delete 函数里面进行判断。
					  if ((scanf("%d", &search_id)) == 1)
					  {
						  delete_usr_info(&stu_list,/* &usr_info_num*/ search_id);
						  getchar();
						  getchar();
					  }
					  else
					  {
						  fflush(stdin);
						  printf("\nillegal input !\n");
						  fflush(stdout);
						  getchar();
						  getchar();
					  }
			}
				break;
			case 4:
			{
					  system("cls");
					  add_usr_info(&stu_list/*, &usr_infor_num*/);
					  getchar();
					  getchar();
			}
				break;
			case 5:
			{
					  system("cls");
					  printf("Enter search account Name: ");
					  //什么时候请stdout 社么时候清stdin
					  fflush(stdout);
					  memset(search_name, 0, sizeof(search_name));
					  fflush(stdin);
					  if (scanf("%s", search_name) == 1)
					  {
						  fflush(stdin);
						  // fflush(stdout);
						  search_usr_account(account_list, search_name);
					  }
					  else
					  {
						  //  search_usr_account(pUsr_Account, NULL);
					  }
					  getchar();
					  getchar();
			}
				break;
			case 6:
			{
					  system("cls");
					  printf("Enter update usr account: ");
					  fflush(stdout);
					  fflush(stdin);
					  memset(search_name, 0, sizeof(search_name));
					  scanf(" %s", &search_name);
					  update_usr_account(account_list, search_name);
					  getchar();
					  getchar();
			}
				break;

			case 7:
			{
					  //每次输出到屏幕的时候就清一次屏幕：fflush(stdout)
					  system("cls");
					  printf("Enter delete account Name: ");
					  fflush(stdout);
					  fflush(stdin);
					  if (scanf("%s", search_name) == 1)
					  {
						  delete_usr_account(&account_list,/* &usr_account_num,*/ search_name);
						  getchar();
						  getchar();
					  }
					  else
					  {
						  fflush(stdin);
						  printf("\nillegal !\n");
						  fflush(stdout);
						  getchar();
						  getchar();
					  }
			}
				break;
			case 8:
			{
					  system("cls");
					  add_usr_account(&account_list /*,&usr_account_num*/);
					  getchar();
					  getchar();
			}
				break;
				/*case 9:
				printf("9\n");
				break;*/
			}
		}
		else
		{
			while (fflush(stdin), (select = show_search_menu(role)) != 3)
			{
				if (select == 2)
				{
					system("cls");
					printf("Enter search id: ");
					fflush(stdout);
					fflush(stdin);
					scanf("%d", &search_id);
					search_usr_info_by_id(stu_list, search_id);
					getchar();
					getchar();
				}
				else if (select == 1)
				{
					system("cls");
					printf("Enter search name : ");
					fflush(stdout);
					fflush(stdin);
					//??????
					scanf("%s", search_name);
					search_usr_info_by_name(stu_list, search_name);
					getchar();
					getchar();
				}


			}
			system("cls");
		}
	}
	//save_data_to_file(argv[1], pUsr_Account, pUsr_Infor);
	system("pause");
	return 0;
}