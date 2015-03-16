#include"_SIMS.h"

void trim_space(char*src)
{
	int fast_index, last_index;
	for (fast_index = 0, last_index = -1; src[fast_index] != 0; fast_index++)
	{
		if (!isspace(src[fast_index]))
		{
			src[++last_index] = src[fast_index];
		}
		else
		{
			if (last_index != -1 && !isspace(src[last_index]))
			{
				src[++last_index] = ' ';
			}
		}
	}
	src[++last_index] = 0;
}
void system_init(char* config, pACCOUNT* pphead_acc, pSTU* pphead_stu)
{
	FILE* fp_config, *fp_account, *fp_stu;
	char line[LINE_LEN];
	pACCOUNT pnew, pcur, ppre;
	pSTU pnew_stu, pcur_stu, ppre_stu;

	fp_config = fopen(config, "r");
	if (fp_config == NULL)
	{
		printf("open config fail!\n");
		system("pause");
		exit(1);
	}
	memset(line, 0, sizeof(line));
	fflush(stdin);
	fgets(line, LINE_LEN, fp_config);
	line[strlen(line) - 1] = 0;

	fp_account = fopen(line, "r");
	if (fp_account == NULL)
	{
		printf("open account fail!\n");
		system("pause");
		exit(1);
	}
	 while (memset(line, 0, sizeof(line)), fgets(line, LINE_LEN, fp_account) != NULL)
	{
		pnew = (pACCOUNT)calloc(1, sizeof(ACCOUNT));
		sscanf(line, "%s%s%d", pnew->m_name, pnew->m_passwd, &pnew->m_role);

		pcur = *pphead_acc;
		ppre = NULL;
		while (pcur && strcmp(pcur->m_name, pnew->m_name) < 0)
		{
			ppre = pcur;
			pcur = pcur->m_next;
		}
		if (ppre == NULL)
		{
			pnew->m_next = *pphead_acc;
			*pphead_acc = pnew;
		}
		else
		{
			pnew->m_next = pcur;
			ppre->m_next = pnew;
		}
	}
	fclose(fp_account);


	memset(line, 0, sizeof(line));
	fgets(line, LINE_LEN, fp_config);
	line[strlen(line) - 1] = 0;
	fclose(fp_config);

	fp_stu = fopen(line, "r");
	if (fp_stu == NULL)
	{
		printf("open stu fail!\n");
		system("pause");
		exit(1);
	}

	while (memset(line, 0, sizeof(line)), fgets(line, LINE_LEN, fp_stu) != NULL)
	{
		pnew_stu = (pSTU)calloc(1, sizeof(STU));
		//sscanf(line,"%s%s%d", pnew ->m_name, pnew ->m_passwd, &pnew ->m_role);
		trim_space(line);

		sscanf(line, "%d%s %c%lf%lf%lf%lf%lf", &pnew_stu->m_id, pnew_stu->m_name, &pnew_stu->m_gender, &pnew_stu->m_socres[0], &pnew_stu->m_socres[1], &pnew_stu->m_socres[2], &pnew_stu->m_socres[3], &pnew_stu->m_socres[4]);

		pcur_stu = *pphead_stu;
		ppre_stu = NULL;
		while (pcur_stu && pcur_stu->m_id < pnew_stu->m_id)
		{
			ppre_stu = pcur_stu;
			pcur_stu = pcur_stu->m_next;
		}
		if (ppre_stu == NULL)
		{
			pnew_stu->m_next = *pphead_stu;
			*pphead_stu = pnew_stu;
		}
		else
		{
			pnew_stu->m_next = pcur_stu;
			ppre_stu->m_next = pnew_stu;
		}
	}
	fclose(fp_stu);





}
int role_confirm(pACCOUNT phead_acc)
{
	char ch;
	int cnt = 0;
	pACCOUNT pcur;
	char usr_name[NAME_LEN];
	char usr_passwd[PWD_LEN];
	while (cnt < CONFIRM_CNT)
	{
		int cnt_Get_Pwd = 0;
		system("cls");
		printf("enter user name:");
		fflush(stdin);
		fgets(usr_name, NAME_LEN, stdin);
		usr_name[strlen(usr_name) - 1] = 0;
		printf("enter user password:");
		fflush(stdin);
		//输入字符回显示密码
		//暂时没有实现修改密码的时候星号也回退。
		memset(usr_passwd, 0, sizeof(usr_passwd));
		while((ch = getch()) != '\r')
		{
			if (isprint(ch))
			{
				usr_passwd[cnt_Get_Pwd] = ch;
				putchar('*');
				++cnt_Get_Pwd;
				if (cnt_Get_Pwd >= PWD_LEN)
				{
					break;
				}
			}
			
		}
		
		//fgets(usr_passwd, PWD_LEN, stdin);
		//usr_passwd[strlen(usr_passwd)] = 0;
		pcur = phead_acc;
		while (pcur)
		{
			if (strcmp(usr_name, pcur->m_name) == 0 && strcmp(usr_passwd, pcur->m_passwd) == 0)
			{
				break;
			}
			pcur = pcur->m_next;
		}
		if (pcur)
		{
			return pcur->m_role;
		}
		else
		{
			cnt++;
		}



	}
	return -1;
}
int show_system_menu(int role)
{
	int select;
	int flag = 0;
	while (!flag)
	{
		system("cls");
		if (role == 1)
		{
			printf("********************************************************************************");
			printf("*****************Student    Information    Management    System*****************");
			printf("********************************************************************************");
			//printf("1.");
			printf("		%s\n", M1);
			printf("		%s\n", M2);
			printf("		%s\n", M3);
			printf("		%s\n", M4);
			printf("		%s\n", M5);
			printf("		%s\n", M6);
			printf("		%s\n", M7);
			printf("		%s\n", M8);
			printf("		%s\n", M9);
		}
		else
		{
			printf("********************************************************************************");
			printf("*****************Student    Information    Management    System*****************");
			printf("********************************************************************************");
			printf("		%s\n", M1);
			printf("		%s\n", M9);
		}
		printf("select a number:");
		fflush(stdin);
		select = getchar();
		if (role == 1)
		{
			if ('1' <= select && select <= '9')
			{
				flag = 1;
			}
		}
		else
		{
			if (select == '1' || select == '9')
			{
				flag = 1;
			}
		}

	}
	return select - '0';
}
int show_search_menu(int role)
{
	int select;
	int flag = 0;
	if (!flag)
	{
		system("cls");
		if (role == 1)
		{
			printf("********************************************************************************");
			printf("*****************Student    Information    Management    System*****************");
			printf("********************************************************************************");
			printf("		%s\n", "0.search all");
			printf("		%s\n", "1.search by name");
			printf("		%s\n", "2.search by id");
			printf("		%s\n", "3.return");
		}
		else
		{
			printf("********************************************************************************");
			printf("*****************Student    Information    Management    System*****************");
			printf("********************************************************************************");
			printf("		%s\n", "1.search by name");
			printf("		%s\n", "2.search by id");
			printf("		%s\n", "3.return");
		}
	}
	printf("select a number: ");
	fflush(stdin);
	select = getchar();
	if (role == 1)
	{
		if (select >= '0' && select <= '3')
			flag = 1;
	}
	else
	{
		if (select >= '1' && select <= '3')
		{
			flag = 1;
		}
	}
	return select - '0';
}
void search_usr_info_by_id(pSTU stu_list, int search_id)
{
	pSTU pcur = stu_list;
	while (pcur)
	{
		if (pcur->m_id == search_id)
		{
			printf("\nID: %d name: %s Gender: %c Grade: %.2f %.2f %.2f %.2f %.2f \n", pcur->m_id, pcur->m_name, pcur->m_gender, pcur->m_socres[0], pcur->m_socres[1], pcur->m_socres[2], pcur->m_socres[3], pcur->m_socres[4]);
			break;
		}
		pcur = pcur->m_next;
	}
	if (pcur == NULL)
	{
		printf("\n The ID you Enter Didn't exist \n");
	}
}

void search_usr_info_by_name(pSTU stu_list, char* search_name)
{
	pSTU pcur = stu_list;
	while (pcur)
	{
		if (strcmp(pcur->m_name, search_name) == 0)
		{
			printf("\nID: %d name: %s Gender: %c Grade: %.2f %.2f %.2f %.2f %.2f \n", pcur->m_id, pcur->m_name, pcur->m_gender, pcur->m_socres[0], pcur->m_socres[1], pcur->m_socres[2], pcur->m_socres[3], pcur->m_socres[4]);
			break;
		}
		pcur = pcur->m_next;
	}
	if (pcur == NULL)
	{
		printf("\n The Name You Enter Didn't Exist! \n");
	}
}
void search_usr_info_all(pSTU stu_list)
{
	pSTU pcur = stu_list;
	while (pcur)
	{
		printf("\nID: %d name: %s Gender: %c Grade: %.2f %.2f %.2f %.2f %.2f \n", pcur->m_id, pcur->m_name, pcur->m_gender, pcur->m_socres[0], pcur->m_socres[1], pcur->m_socres[2], pcur->m_socres[3], pcur->m_socres[4]);
		pcur = pcur->m_next;
	}
}
void search_usr_account(pACCOUNT account_list, char* search_name)
{
	pACCOUNT pcur = account_list;
	while(pcur)
	{
		if (strcmp(pcur->m_name, search_name) == 0)
		{
			printf("\nName: %s password: %s role: %d\n", pcur->m_name, pcur->m_passwd, pcur->m_role);
			break;
		}
		pcur = pcur->m_next;
	}
	if (pcur == NULL)
	{
		printf("\nAccount You Enter Didn't Exist!!\n");
	}
}
pSTU update_usr_info(pSTU stu_list, int search_id)
{
	
	pSTU pcur = stu_list;
	while (pcur)
	{
		if (pcur->m_id == search_id)
		{
			printf("\n enter ID , Name, Gender, Five Scores\n");
			scanf(" %d %s %c %lf %lf %lf %lf %lf", &pcur->m_id, pcur->m_name, &pcur->m_gender, &pcur->m_socres[0], &pcur->m_socres[1], &pcur->m_socres[2], &pcur->m_socres[3], &pcur->m_socres[4]);
			break;
		}
		pcur = pcur->m_next;
	}
	if (pcur == NULL)
	{
		printf("\nThe Id You Enter is illegal: \n");
	}
	return pcur;
}
pACCOUNT update_usr_account(pACCOUNT account_list, char* search_name)
{
	pACCOUNT pcur = account_list;
	while (pcur)
	{
		if (strcmp(pcur->m_name, search_name) == 0)
		{
			printf("\nEnter Name: password: role:\n");
			scanf(" %s %s %d", pcur->m_name, pcur->m_passwd, &pcur->m_role);
			break;
		}
		pcur = pcur->m_next;
	}
	if (pcur == NULL)
	{
		printf("The Name You Search Didn't Exist");
	}
	return pcur;
	
}
pSTU delete_usr_info(pSTU* stu_list,/* &usr_info_num*/int search_id)
{
	pSTU ppre = NULL, pcur = *stu_list;
	while (pcur && pcur->m_id != search_id)
	{
		ppre = pcur;
		pcur = pcur->m_next;
	}
	if (pcur == NULL)
	{
		printf("\nThe Stu's Information's  Empty\n");
	}
	else
	{
		if (ppre == NULL)
		{
			*stu_list = pcur->m_next;
			free(pcur);
		}
		else
		{
			ppre->m_next = pcur->m_next;
			free(pcur);
		}
		/*tmp = pcur;	
		ppre->m_next = pcur->m_next;
		pcur = pcur->m_next;
		free(tmp);*/// 所以可以写的简单些。
	}
	return pcur->m_next;
}
pACCOUNT delete_usr_account(pACCOUNT* account_list,/* &usr_account_num,*/ char* search_name)
{
	pACCOUNT ppre = NULL, pcur = *account_list;
	while (pcur && strcmp(pcur->m_name, search_name))
	{
		ppre = pcur;
		pcur = pcur->m_next;
	}
	if (pcur == NULL)
	{
		printf("\n the ID You Enter is Didn't Exist! ");
	}
	else
	{
		if (ppre == NULL)
		{
			*account_list = pcur->m_next;
			free(pcur);
		}
		else
		{
			ppre->m_next = pcur->m_next;
			free(pcur);
		}
	}
	return ppre->m_next;
}
pSTU add_usr_info(pSTU* stu_list/*, &usr_infor_num*/)
{

	pSTU ppre = NULL, pcur = *stu_list, pnew;
	printf("\n Add Account Enter ID, Name, Gender, Grade:\n ");
	pnew = (pSTU)calloc(1, sizeof(STU));
	//scanf 中的%d间隔要有
	scanf(" %d %s %c %lf %lf %lf %lf %lf", &pnew->m_id, pnew->m_name, &pnew->m_gender, &pnew->m_socres[0], &pnew->m_socres[1], &pnew->m_socres[2], &pnew->m_socres[3], &pnew->m_socres[4], &pnew->m_socres[5]);
	while (pcur && pcur->m_id < pnew->m_id)
	{
		ppre = pcur;
		pcur = pcur->m_next;
	}
	//如果只有一个节点的话第一句一样，第一行稍有变化。
	if (ppre == NULL)
	{
		pnew->m_next = *stu_list;
		*stu_list = pnew;
	}
	else
	{
		pnew->m_next = pcur;
		ppre->m_next = pnew;
	}
	return pcur;
	
}
pACCOUNT add_usr_account(pACCOUNT* account_list /*,&usr_account_num*/)
{
	
	pACCOUNT ppre = NULL, pnew, pcur = *account_list;
	pnew = (pACCOUNT)calloc(1, sizeof(pACCOUNT));
	printf("\n Enter Account:Name, password , role(1/2): \n ");
	scanf("%s %s %d", pnew->m_name, pnew->m_passwd, &pnew->m_role);
	while (pcur && strcmp(pcur->m_name, pnew->m_name) < 0)
	{
		ppre = pcur;
		pcur = pcur->m_next;
	}
	if (ppre == NULL)
	{
		pnew->m_next = *account_list;
		*account_list = pnew;
	}
	else
	{
		pnew->m_next = pcur;
		ppre->m_next = pnew;
	}
	return pcur;

}
//void save_data_to_file(char* config, pACCOUNT account_list, pSTU stu_list)
//{
//	//记得要释放内存
//	//此处定义指针的时候要小心，应写成下面的那种方式
//	pACCOUNT pcur_acc = account_list,tmp;
//	pSTU pcur_stu = stu_list, pstu_tmp;
//	FILE* fp_config, *fp_account, *fp_stu;
//	char buf[LINE_LEN];
//	fp_config = fopen(config, "r");
//	if (fp_config == NULL)
//	{
//		printf("\n fail to opne config file. \n");
//		system("pause");
//		exit(1);
//	}
//	memset(buf, 0, sizeof(buf));
//	fflush(stdin);
//	fgets(buf, LINE_LEN, fp_config);
//	buf[strlen(buf) - 1] = 0;//读地址的时候后面的换行符号没必要读进去；
//	fp_account = fopen(buf, "w");
//	if (fp_account == NULL)
//	{
//		printf("\n Fail Open Account File ");
//		system("pause");
//		exit(1);
//	}
//	while (pcur_acc)
//	{
//		memset(buf, 0, sizeof(buf));
//		fflush(stdin);
//		fgets(buf, LINE_LEN, fp_account);
//		sprintf(buf, "-5%s 5%s 5%d", pcur_acc->m_name, pcur_acc->m_passwd, pcur_acc->m_role);
//		//fprintf(fp_account, "-5%s 5%s 5%d", pcur_acc->m_name, pcur_acc->m_passwd, pcur_acc->m_role)
//		fputs(buf, fp_account);
//		tmp = pcur_acc;
//		pcur_acc = pcur_acc->m_next;
//		free(tmp);	
//	}
//	memset(buf, LINE_LEN, sizeof(buf));
//	fflush(stdin);
//	fgets(buf, LINE_LEN, fp_config);
//	buf[strlen(buf) - 1] = 0;// 去掉最后的换行符号。
//	fp_stu = fopen(buf, "w");
//	if (fp_stu == NULL)
//	{
//		printf("\n Fail To Open STU_Info.txt \n");
//		system("pause");
//		exit(1);
//	}
//	while (pcur_stu)
//	{
//		memset(buf, 0, sizeof(buf));
//		fflush(stdin);
//		//fgets(buf, LINE_LEN,fp_stu)
//		sprintf(buf, "%d, %s, %c %d %d %d %d %d", pcur_stu->m_id, pcur_stu->m_name, pcur_stu->m_gender, pcur_stu->m_socres[0], pcur_stu->m_socres[1], pcur_stu->m_socres[2], pcur_stu->m_socres[3], pcur_stu->m_socres[4]);
//		fputs(buf, pcur_s);
//		pstu_tmp = pcur_stu;
//		pcur_stu = pcur_stu->m_next;
//		free(tmp);
//	}

	
	
	

	

