#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 20
//ͼ����Ϣ�� 
struct book{ 
	int id;
	char number[MAX];
	char title[MAX];
	char author[MAX]; 
	struct book *next;
};
//ȫ�ֱ������� 
	struct book *head, *p, *t, *tail, temp;	//��������� 
	int order;			//ȫ��������� 
	int ids=1;
	int idd, flag;
	char ch[MAX];	
void dispaly()		//��ʾ����������������ʾ���ڴ�������Ϣ�� over
{
	if(head){
		printf("���  ���        ����     ����\n");
		p = head;
		while(p != NULL){
			printf("%-6d%-12s%-10s%s\n",p->id,p->number,p->title,p->author);
			p=p->next;
		}
		printf("     ����ʾȫ����Ϣ��\n");
		printf("     �û��س���ʾ�˵�\n\n");
		getchar();
		getchar();
	}else{
		printf("\n       !!û�п�����ʾ����Ϣ\n\n");
	}
}
void add()		//��Ӻ������������ڴ�������µ�ְ����Ϣ�� over
{
	char key;
	printf("\n����������Ҫ���ͼ�����Ϣ:\n");
	printf("*���:");
	scanf("%s",&temp.number);
	printf("*����:");
	scanf("%s",&temp.title);
	printf("*����:");
	scanf("%s",&temp.author);
	getchar();
	printf("���:%s ����:%s ����:%s\n",temp.number,temp.title,temp.author);
	printf("��ȷ����Ϣ�����Ƿ񱣴棿(y/n):");
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
			printf("     �ɹ������Ϣ��\n");
			flag = 1;
			break;
		}else if(key=='n'){
			printf("     �Ѿ�ȡ��������\n");
			break;
		}else{
			printf("�Բ����������ָ����������������:");
		}
	}
	if(flag){
		printf("�Ƿ�������ͼ����Ϣ��(y/n)");
		while(scanf("%c",&key)!=EOF){
			if(key=='y'){
				add();
				break;
			}else if(key=='n'){
				break;
			}else{
				printf("�Բ����������ָ����������������:");
			}
		}	
	}
}
void find()		//�����������������ڴ����м���ͼ����Ϣ�� over
{
	if(!head) {
		printf("\n    !!��ǰϵͳ��û����Ϣ���޷�ִ�м���������\n\n"); 
		return;
	}
	printf("       ��ѡ�������ʽ:\n");
	printf("       ___________________\n");
	printf("       |1 ������ż���   |\n"); 
	printf("       |2 ���ձ�ż���   |\n");
	printf("       |3 ������������   |\n");
	printf("       |0 ȡ������       |\n"); 
	printf("       ___________________\n");
	printf("  ������˵�ǰ�������ִ����Ӧ����:");
	scanf("%d",&order);
	getchar();
	switch(order){
		case 1:
			flag=0;
			printf("��������Ҫ��ѯ�����:");
			scanf("%d",&idd);
			p=head;
			printf("���  ���        ����     ���� \n");
			while(p){
				if(p->id == idd){
					printf("%-6d%-12s%-10s%s\n",p->id,p->number,p->title,p->author);
					flag=1;
				}
				p=p->next;
			}
			if(!flag) printf("�Բ���δ�����������Ϣ��\n");
			printf("     �û��س���ʾ�˵�\n\n");
			getchar();
			getchar();
			break;
		case 2:
		    flag=0;
			printf("��������Ҫ��ѯ�ı��:");
			gets(ch);
			p=head;
			printf("���  ���        ����      ����\n");
			while(p){
				if(!strcmp(p->number,ch)){
					printf("%-6d%-12s%-10s%s\n",p->id,p->number,p->title,p->author);
					flag=1;
				}
				p=p->next;
			}
			if(!flag) printf("�Բ���δ�����������Ϣ��\n");
			printf("     �û��س���ʾ�˵�\n\n");
			getchar();
			break;
		case 3:
			flag=0;
	        printf("��������Ҫ��ѯ������:");
			gets(ch);
			p=head;
			printf("���  ���        ����      ����\n");
			while(p){
				if(!strcmp(p->title,ch)){
					printf("%-6d%-12s%-10s%s\n",p->id,p->number,p->title,p->author);
					flag=1;
				}
				p=p->next;
			}
			if(!flag) printf("�Բ���δ�����������Ϣ��\n");
			printf("     �û��س���ʾ�˵�\n\n");
			getchar();
			break;
		case 0:break;
		default:printf("�Բ����������ָ���������������룡\n");
		find(); 
	}
}
void del()		//ɾ������������ɾ���ڴ���������ͼ����Ϣ��
{
	char key;
	if(!head) {
		printf("\n    !!��ǰϵͳ��û����Ϣ���޷�ִ��ɾ��������\n\n"); 
		return;
	}
	
	printf("        ��ѡ��ɾ����ʽ:\n");
	printf("       ___________________\n");
	printf("       |1 �������ɾ��   |\n"); 
	printf("       |2 ���ձ��ɾ��   |\n");
	printf("       |3 ��������ɾ��   |\n");
	printf("       |0 ȡ������       |\n"); 
	printf("       ___________________\n");
	printf("  ������˵�ǰ�������ִ����Ӧ����:");
	scanf("%d",&order);
	getchar();
	
	switch(order){
		case 1:
			flag = 0;
			printf("��������Ҫɾ������Ϣ�����:");
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
			printf("   ��Ϣ�Ѿ��ɹ�ɾ����\n");
			else
			printf("   �Բ���δ�����������Ϣ��\n");
			break;
		case 2:
	        flag=0;
			printf("��������Ҫɾ������Ϣ�ı��:");
			gets(ch);
			printf("���  ���        ����      ����\n");
			p=head;
			while(p){
				if(!strcmp(p->number,ch)){
					printf("%-6d%-12s%-10s%s\n",p->id,p->number,p->title,p->author);
					flag=1;
				}
				p=p->next;
			}
			if(flag){
				printf("�Ƿ�ɾ�����з�����������Ϣ��(y/n):");
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
						printf("�Ѿ��ɹ�ɾ�����з�����������Ϣ��\n");
						return ;
					}
					else if(key == 'n'){
						printf("�Ƿ��������ɾ����Ϣ������ȡ�����β���(y/n):");
						while(scanf("%c",&key)!=EOF){
							getchar();
							if(key == 'y'){
								flag = 0;
								printf("��������Ҫɾ������Ϣ�����:");
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
								printf("   ��Ϣ�Ѿ��ɹ�ɾ����\n");
								else
								printf("   �Բ���δ�����������Ϣ��\n");
								return ;
							}
							else if(key == 'n'){
								printf("���β����Ѿ�ȡ����\n");
								return ; 
							}else{
								printf("�Բ����������ָ���������������룡\n");
							}
						}
					}else{
						printf("�Բ����������ָ���������������룡\n");
					}
				}
			}
			else{
				printf("�Բ���δ�����������Ϣ��\n");break;
			} 
			printf("     �û��س���ʾ�˵�\n\n");
			getchar();
			break;
		case 3:
			flag=0;
			printf("��������Ҫɾ������Ϣ������:");
			gets(ch);
			printf("���  ���        ����      ����\n");
			p=head;
			while(p){
				if(!strcmp(p->title,ch)){
					printf("%-6d%-12s%-10s%s\n",p->id,p->number,p->title,p->author);
					flag=1;
				}
				p=p->next;
			}
			if(flag){
				printf("�Ƿ�ɾ�����з�����������Ϣ��(y/n):");
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
						printf("�Ѿ��ɹ�ɾ�����з�����������Ϣ��\n");
						return ;
					}
					else if(key == 'n'){
						printf("�Ƿ��������ɾ����Ϣ������ȡ�����β���(y/n):");
						while(scanf("%c",&key)!=EOF){
							getchar();
							if(key == 'y'){
								flag = 0;
								printf("��������Ҫɾ������Ϣ�����:");
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
								printf("   ��Ϣ�Ѿ��ɹ�ɾ����\n");
								else
								printf("   �Բ���δ�����������Ϣ��\n");
								return ;
							}
							else if(key == 'n'){
								printf("���β����Ѿ�ȡ����\n");
								return ; 
							}else{
								printf("�Բ����������ָ���������������룡\n");
							}
						}
					}else{
						printf("�Բ����������ָ���������������룡\n");
					}
				}
			}
			else{
				printf("�Բ���δ�����������Ϣ��\n");break;
			} 
			printf("     �û��س���ʾ�˵�\n\n");
			getchar();
			break;
		case 0:break;
		default:printf("�Բ����������ָ���������������룡\n");
		del(); 
	} 
}
void readfp()		//��ȡ�������������ĵ��ļ��ж�ȡ�Ѵ��ͼ����Ϣ��
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
void savefp()		//�洢�������������ڴ�����ͼ����Ϣ���浽�ĵ���
{
	if(!head) {
		printf("\n    !!��ǰϵͳ��û����Ϣ���޷�ִ�д浵������\n\n"); 
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
	printf("        ��Ϣ�Ѿ��ɹ����棡\n");
	getchar();getchar();
} 
int menu()			//�˵�������������ʾ�˵�����ȡ����ָ�
{
	printf("       _____________________\n");
	printf("       |1 �鿴����ͼ����Ϣ |\n");
	printf("       |2 ����µ�ͼ����Ϣ |\n");
	printf("       |3 ɾ�����е���Ϣ   |\n");
	printf("       |4 �������е���Ϣ   |\n");
	printf("       |5 ������Ϣ���ĵ�   |\n");
	printf("       |0 �˳�ϵͳ         |\n");
	printf("       _____________________\n");
	printf("    ע:�˳�ϵͳǰ�뱣���������ݶ�ʧ\n");
	printf("  ������˵�ǰ�������ִ����Ӧ����:");
	scanf("%d",&order);
	switch(order){
			case 1:dispaly();break;
			case 2:add();break;
			case 3:del();break;
			case 4:find();break;
			case 5:savefp();break;
			case 0:break; 
			default:printf("�Բ����������ָ���������������룡\n");
	}
	return order;
}
main()				//ִ�к�����������ӭ���ȡ�ĵ���Ϣ�ȡ� over
{
	printf("        ��ӭʹ��ͼ�����ϵͳ\n");
	printf("             ��ϵͳ������:����\2\2\n");
	printf("            ���û��س����򿪲˵�\n");
	getchar();
	readfp();
	while(menu()) ;
	printf("  ϵͳ�Ѿ���ȫ�˳���"); 
	exit(0);
}
