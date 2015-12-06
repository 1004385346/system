#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 20
//图书信息类 
struct book{ 
	int id;
	char number[MAX];
	char title[MAX];
	char author[MAX]; 
	struct book *next;
};
//全局变量定义 
	struct book *head, *p, *t, *tail, temp;	//链表联结点 
	int order;			//全局命令变量 
	int ids=1;
	int idd, flag;
	char ch[MAX];	
void dispaly()		//显示函数，用来依次显示出内存区的信息。 over
{
	if(head){
		printf("序号  编号        书名     作者\n");
		p = head;
		while(p != NULL){
			printf("%-6d%-12s%-10s%s\n",p->id,p->number,p->title,p->author);
			p=p->next;
		}
		printf("     已显示全部信息。\n");
		printf("     敲击回车显示菜单\n\n");
		getchar();
		getchar();
	}else{
		printf("\n       !!没有可以显示的信息\n\n");
	}
}
void add()		//添加函数，用来向内存区添加新的职工信息。 over
{
	char key;
	printf("\n请依次输入要添加图书的信息:\n");
	printf("*编号:");
	scanf("%s",&temp.number);
	printf("*书名:");
	scanf("%s",&temp.title);
	printf("*作者:");
	scanf("%s",&temp.author);
	getchar();
	printf("编号:%s 书名:%s 作者:%s\n",temp.number,temp.title,temp.author);
	printf("请确认信息无误，是否保存？(y/n):");
	while(scanf("%c",&key)!=EOF){
		flag = 0; 
		getchar();
		if(key=='y'){
			if(!head){
				temp.id=ids++;
				p=(struct book*)malloc(sizeof(struct book));
				head=p;
				tail=p;
				*p=temp;
				p->next=0;
			}else{
				temp.id=ids++;
				p=(struct book*)malloc(sizeof(struct book));
				*p=temp;
				p->next=0;
				tail->next=p;
				tail=p;
			}
			printf("     成功添加信息。\n");
			flag = 1;
			break;
		}else if(key=='n'){
			printf("     已经取消操作！\n");
			break;
		}else{
			printf("对不起，您输入的指令有误，请重新输入:");
		}
	}
	if(flag){
		printf("是否继续添加图书信息？(y/n)");
		while(scanf("%c",&key)!=EOF){
			if(key=='y'){
				add();
				break;
			}else if(key=='n'){
				break;
			}else{
				printf("对不起，您输入的指令有误，请重新输入:");
			}
		}	
	}
}
void find()		//检索函数，用来在内存区中检索图书信息。 over
{
	if(!head) {
		printf("\n    !!当前系统中没有信息，无法执行检索操作。\n\n"); 
		return;
	}
	printf("       请选择检索方式:\n");
	printf("       ___________________\n");
	printf("       |1 按照序号检索   |\n"); 
	printf("       |2 按照编号检索   |\n");
	printf("       |3 按照书名检索   |\n");
	printf("       |0 取消操作       |\n"); 
	printf("       ___________________\n");
	printf("  请输入菜单前的序号以执行相应操作:");
	scanf("%d",&order);
	getchar();
	switch(order){
		case 1:
			flag=0;
			printf("请输入需要查询的序号:");
			scanf("%d",&idd);
			p=head;
			printf("序号  编号        书名     作者 \n");
			while(p){
				if(p->id == idd){
					printf("%-6d%-12s%-10s%s\n",p->id,p->number,p->title,p->author);
					flag=1;
				}
				p=p->next;
			}
			if(!flag) printf("对不起，未检索到相关信息！\n");
			printf("     敲击回车显示菜单\n\n");
			getchar();
			getchar();
			break;
		case 2:
		    flag=0;
			printf("请输入需要查询的编号:");
			gets(ch);
			p=head;
			printf("序号  编号        书名      作者\n");
			while(p){
				if(!strcmp(p->number,ch)){
					printf("%-6d%-12s%-10s%s\n",p->id,p->number,p->title,p->author);
					flag=1;
				}
				p=p->next;
			}
			if(!flag) printf("对不起，未检索到相关信息！\n");
			printf("     敲击回车显示菜单\n\n");
			getchar();
			break;
		case 3:
			flag=0;
	        printf("请输入需要查询的书名:");
			gets(ch);
			p=head;
			printf("序号  编号        书名      作者\n");
			while(p){
				if(!strcmp(p->title,ch)){
					printf("%-6d%-12s%-10s%s\n",p->id,p->number,p->title,p->author);
					flag=1;
				}
				p=p->next;
			}
			if(!flag) printf("对不起，未检索到相关信息！\n");
			printf("     敲击回车显示菜单\n\n");
			getchar();
			break;
		case 0:break;
		default:printf("对不起，您输入的指令有误，请重新输入！\n");
		find(); 
	}
}
void del()		//删除函数，用来删除内存区的已有图书信息。
{
	char key;
	if(!head) {
		printf("\n    !!当前系统中没有信息，无法执行删除操作。\n\n"); 
		return;
	}
	
	printf("        请选择删除方式:\n");
	printf("       ___________________\n");
	printf("       |1 按照序号删除   |\n"); 
	printf("       |2 按照编号删除   |\n");
	printf("       |3 按照书名删除   |\n");
	printf("       |0 取消操作       |\n"); 
	printf("       ___________________\n");
	printf("  请输入菜单前的序号以执行相应操作:");
	scanf("%d",&order);
	getchar();
	
	switch(order){
		case 1:
			flag = 0;
			printf("请输入需要删除的信息的序号:");
			scanf("%d",&idd);
			if(head->id == idd){
				head=head->next;
				flag=1;
			}else{
				p=head;
			while(p->next){
				t=p->next;
				if(t->id == idd){
					if(t->next){
						p->next = t->next;
						free(t);	
					}else{
						p->next = 0;
						free(t);
						tail = p;
					}
					flag=1;
					break;
				}
				p=p->next;
			}
			} 
			if(flag)
			printf("   信息已经成功删除！\n");
			else
			printf("   对不起，未检索到相关信息！\n");
			break;
		case 2:
	        flag=0;
			printf("请输入需要删除的信息的编号:");
			gets(ch);
			printf("序号  编号        书名      作者\n");
			p=head;
			while(p){
				if(!strcmp(p->number,ch)){
					printf("%-6d%-12s%-10s%s\n",p->id,p->number,p->title,p->author);
					flag=1;
				}
				p=p->next;
			}
			if(flag){
				printf("是否删除所有符合条件的信息？(y/n):");
				while(scanf("%c",&key)!=EOF){
					getchar();
					if(key == 'y'){
						p = head;
						while(p->next){
							t = p->next;
							if(!strcmp(t->number,ch)){
								if(t->next){
									p->next = t->next;
									free(t);
								}else{
									p->next = 0;
									free(t);
									tail = p;
								}
							}else{
								p=p->next;
							}
						}
						p = head;
						if(!strcmp(p->number,ch)){
							if(head->next){
								head=head->next;
								free(p);
							}else{
								free(p);
								head = NULL;
								tail = NULL;
							}
						} 
						printf("已经成功删除所有符合条件的信息！\n");
						return ;
					}
					else if(key == 'n'){
						printf("是否依照序号删除信息，否则取消本次操作(y/n):");
						while(scanf("%c",&key)!=EOF){
							getchar();
							if(key == 'y'){
								flag = 0;
								printf("请输入需要删除的信息的序号:");
								scanf("%d",&idd);
								
								p = head;
								if(p->id == idd){
									head = p->next;
									free(p);
									flag = 1;
								}else{
									while(p->next){
										t = p->next;
										if(t->id == idd){
											if(t->next){
												p->next = t->next;
												free(t);
											}else{
												p->next = 0;
												free(t);
												tail = p;
											}
											flag = 1;
											break;
										}
										p=p->next;
									}
								} 
								if(flag)
								printf("   信息已经成功删除！\n");
								else
								printf("   对不起，未检索到相关信息！\n");
								return ;
							}
							else if(key == 'n'){
								printf("本次操作已经取消。\n");
								return ; 
							}else{
								printf("对不起，您输入的指令有误，请重新输入！\n");
							}
						}
					}else{
						printf("对不起，您输入的指令有误，请重新输入！\n");
					}
				}
			}
			else{
				printf("对不起，未检索到相关信息！\n");break;
			} 
			printf("     敲击回车显示菜单\n\n");
			getchar();
			break;
		case 3:
			flag=0;
			printf("请输入需要删除的信息的书名:");
			gets(ch);
			printf("序号  编号        书名      作者\n");
			p=head;
			while(p){
				if(!strcmp(p->title,ch)){
					printf("%-6d%-12s%-10s%s\n",p->id,p->number,p->title,p->author);
					flag=1;
				}
				p=p->next;
			}
			if(flag){
				printf("是否删除所有符合条件的信息？(y/n):");
				while(scanf("%c",&key)!=EOF){
					getchar();
					if(key == 'y'){
						p = head;
						while(p->next){
							t = p->next;
							if(!strcmp(t->title,ch)){
								if(t->next){
									p->next = t->next;
									free(t);
								}else{
									p->next = 0;
									free(t);
									tail = p;
								}
							}else{
								p=p->next;
							}
						}
						p = head;
						if(!strcmp(p->title,ch)){
							if(head->next){
								head=head->next;
								free(p);
							}else{
								free(p);
								head = NULL;
								tail = NULL;
							}
						} 
						printf("已经成功删除所有符合条件的信息！\n");
						return ;
					}
					else if(key == 'n'){
						printf("是否依照序号删除信息，否则取消本次操作(y/n):");
						while(scanf("%c",&key)!=EOF){
							getchar();
							if(key == 'y'){
								flag = 0;
								printf("请输入需要删除的信息的序号:");
								scanf("%d",&idd);
								
								p = head;
								if(p->id == idd){
									head = p->next;
									free(p);
									flag = 1;
								}else{
									while(p->next){
										t = p->next;
										if(t->id == idd){
											if(t->next){
												p->next = t->next;
												free(t);
											}else{
												p->next = 0;
												free(t);
												tail = p;
											}
											flag = 1;
											break;
										}
										p=p->next;
									}
								} 
								if(flag)
								printf("   信息已经成功删除！\n");
								else
								printf("   对不起，未检索到相关信息！\n");
								return ;
							}
							else if(key == 'n'){
								printf("本次操作已经取消。\n");
								return ; 
							}else{
								printf("对不起，您输入的指令有误，请重新输入！\n");
							}
						}
					}else{
						printf("对不起，您输入的指令有误，请重新输入！\n");
					}
				}
			}
			else{
				printf("对不起，未检索到相关信息！\n");break;
			} 
			printf("     敲击回车显示菜单\n\n");
			getchar();
			break;
		case 0:break;
		default:printf("对不起，您输入的指令有误，请重新输入！\n");
		del(); 
	} 
}
void readfp()		//读取函数，用来从文档文件中读取已存的图书信息。
{
	FILE *save;
	save = fopen("save.txt","r");
	if(save != NULL){
		fscanf(save,"%d\n",&ids);
		fscanf(save,"%d %s %s %s\n",&temp.id,&temp.number,&temp.title,&temp.author);
		p=(struct book*)malloc(sizeof(struct book));
		head=p;
		tail=p;
		*p=temp;
		p->next=0;
		p = head;
		while(fscanf(save,"%d %s %s %s\n",&temp.id,&temp.number,&temp.title,&temp.author)!=EOF){
			p=(struct book*)malloc(sizeof(struct book));
			*p=temp;
			p->next=0;
			tail->next=p;
			tail=p;
		}	
	}
	fclose(save);
}
void savefp()		//存储函数，用来将内存区的图书信息保存到文档。
{
	if(!head) {
		printf("\n    !!当前系统中没有信息，无法执行存档操作。\n\n"); 
		return;
	}
	FILE *save;
	save = fopen("save.txt","w");
	fprintf(save,"%d\n",ids);
	p = head;
	while(p){
		fprintf(save,"%d %s %s %s\n",p->id,p->number,p->title,p->author);
		p = p->next;
	}
	fclose(save);
	printf("        信息已经成功保存！\n");
	getchar();getchar();
} 
int menu()			//菜单函数，用来显示菜单并获取操作指令。
{
	printf("       _____________________\n");
	printf("       |1 查看所有图书信息 |\n");
	printf("       |2 添加新的图书信息 |\n");
	printf("       |3 删除已有的信息   |\n");
	printf("       |4 搜索已有的信息   |\n");
	printf("       |5 保存信息至文档   |\n");
	printf("       |0 退出系统         |\n");
	printf("       _____________________\n");
	printf("    注:退出系统前请保存以免数据丢失\n");
	printf("  请输入菜单前的序号以执行相应操作:");
	scanf("%d",&order);
	switch(order){
			case 1:dispaly();break;
			case 2:add();break;
			case 3:del();break;
			case 4:find();break;
			case 5:savefp();break;
			case 0:break; 
			default:printf("对不起，您输入的指令有误，请重新输入！\n");
	}
	return order;
}
main()				//执行函数，包含欢迎语，读取文档信息等。 over
{
	printf("        欢迎使用图书管理系统\n");
	printf("             本系统制作人:孙宇\2\2\n");
	printf("            请敲击回车键打开菜单\n");
	getchar();
	readfp();
	while(menu()) ;
	printf("  系统已经安全退出！"); 
	exit(0);
}
