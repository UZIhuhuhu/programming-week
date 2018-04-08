/*
 * @Author: MozhuCY
 * @Date: 2018-04-03 09:56:00
 * @Last Modified by: wynnxin
 * @Last Modified time: 2018-04-04 10:11:32
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int io=0;
//全局记录录入学生数

int cid=0;
//全局记录课程数

char base64[65]="ABCDEFGHIJKLMN0PQRSTUVWXYZabcdefghijklmnopqrstuvwxyzO123456789+/";

struct student{
    int age;
    char name[20];
    char StudentID[20];
    char sex[5];
    int _class;
    int tel;
    int cours;
}student[100];
//学生结构体

struct course{
    int ID;
    char _name[20];
    char _xingzhi[10];
    int time;
    int p_num;
    int p_all;
    int term;
}course[100];
//课程结构体


char * abase64(char * str){  
    long len;  
    long str_len;  
    char *res;  
    int i,j;
    str_len=strlen(str);  
    if(str_len % 3 == 0)  
        len=str_len/3*4;  
    else  
        len=(str_len/3+1)*4;  
  
    res=malloc(sizeof(char)*len+1);  
    res[len]='\0';  
    for(i=0,j=0;i<len-2;j+=3,i+=4)  
    {  
        res[i]=base64[str[j]>>2];
        res[i+1]=base64[(str[j]&0x3)<<4 | (str[j+1]>>4)];  
        res[i+2]=base64[(str[j+1]&0xf)<<2 | (str[j+2]>>6)];
        res[i+3]=base64[str[j+2]&0x3f];
    }  
  
    switch(str_len % 3)  
    {  
        case 1:  
            res[i-2]='=';  
            res[i-1]='=';  
            break;  
        case 2:  
            res[i-1]='=';  
            break;  
    }  
  	return res;
}

void replace(char * a){
	int len = strlen(a);
	a[len]='\x00';
}
//去除读入字符串最后的回车

void _scanf(int i){
	char a[20];
	printf("您的学号：");
	scanf("%s",a);
    if(if_in(a)){
    	return ;
	};
    printf("您的姓名：");
    scanf("%s",student[i].name);
    printf("您的年龄：");
    scanf("%d",&student[i].age);
    printf("您的性别：");
    scanf("%s",student[i].sex);
    printf("您的电话：");
    scanf("%d",&student[i].tel);
    printf("您的班级：");
    scanf("%d",&student[i]._class);
    student[i].cours=-1;
    io++;
}
//录入学生信息

void c_scanf(){
    printf("课程名字：");
    scanf("%s",course[cid]._name);
    printf("课程性质：");
    scanf("%s",course[cid]._xingzhi);
    printf("学时：");
    scanf("%d",&course[cid].time);
    printf("课程总量：");
    scanf("%d",&course[cid].p_num);
    course[cid].p_all=course[cid].p_num;
    printf("开课学期：");
    scanf("%d",&course[cid].term);
    cid++;
}
//录入课程信息

void _print(int i){
    printf("===================\n");
    printf("姓名：%s\n",student[i].name);
    printf("学号：%s\n",student[i].StudentID);
    printf("年龄：%d\n",student[i].age);
    printf("性别：%s\n",student[i].sex);
    printf("电话：%d\n",student[i].tel);
    printf("班级：%d\n",student[i]._class);
    printf("===================\n");
}
//打印学生信息

void c_print(int i){
    printf("===================\n");
    printf("课程名称：%s\n",course[i]._name);
    printf("课程性质：%s\n",course[i]._xingzhi);
    printf("开课学期：%d\n",course[i].term);
    printf("课程总/余量：%d  %d\n",course[i].p_all,course[i].p_num);
    printf("课时：%d\n",course[i].time);
    printf("===================\n");
}
//打印课程信息

int if_in(char * a){
	int checkid=-1;
	int i;
	if(strlen(a)!=9){
        printf("非法学号!\n");
        return 2;
	}
    for(i=0;i<io;i++){
        if(!strcmp(student[i].StudentID,a)){
            printf("该学号已经存在!\n");
            return 1;
        }
	}
	if(!(checkid+1)){
        strcpy(student[io].StudentID,a);
        return 0;
    }
}
//输入时,根据学号字符串查询是否学生信息已存在

int check(){
    char id[20];
    int i;
    int checkid=-1;
    printf("请输入您要修改的学号:　");
    scanf("%s",id);
    for(i=0;i<io;i++){
        if(!strcmp(student[i].StudentID,id)){
            checkid=i;
        }
    }
    if(!(checkid+1)){
        printf("未查询到学生信息\n");
        return -1;
    }
    return checkid;
}
//录入后查取学生信息

void edit(){
    int checkid=check();
    printf("===================\n");
    printf("[1] 修改姓名\n[2] 修改年龄\n[3] 修改学号\n[4] 修改电话\n[5] 修改班级\n");
    printf("===================\n");
    int choose;
    scanf("%d",&choose);
    switch(choose){
        case 1:
        	printf("您的姓名:");
            scanf("%s",student[checkid].name);
            break;
        case 2:
        	printf("您的年龄:");
            scanf("%d",&student[checkid].age);
            break;
        case 3:
        	printf("您的学号:");
            scanf("%s",student[checkid].StudentID);
            break;
        case 4:
        	printf("您的电话:");
            scanf("%d",&student[checkid].tel);
            break;
        case 5:
        	printf("您的班级:");
            scanf("%d",&student[checkid]._class);
            break;
        default:
            return;
    }
}
//编辑修改指定的学生信息字段

void count(){
	printf("=====================\n");
	printf("已录入学生人数: %d\n",io);
	printf("=====================\n");

}
//分割线

void pcheck(){
	int i=check();
	if(i!=-1) _print(i);
	else return;
}
//查询学生信息

int ccheck(){
	int i,checkid=-1;
	char name[20];
	printf("请输入课程名称:");
	scanf("%s",name);
    for(i=0;i<cid;i++){
        if(!strcmp(course[i]._name,name)){
            checkid=i;
        }
    }
    if(!(checkid+1)){
        printf("未查询到课程信息\n");
        return -1;
    }
    return checkid;
}
//查询课程信息

void c_check(){
	int i=ccheck();
	if(i!=-1) c_print(i);
	else return;
}
//查询到后打印

void _del(int id){
	int i;
	for(i=id;i<io;i++){
		strcpy(student[i].name,student[i+1].name);
		student[i].age = student[i+1].age;
		strcpy(student[i].StudentID,student[i+1].StudentID);
		strcpy(student[i].sex,student[i+1].sex);
		student[i].tel=student[i+1].tel;
		student[i]._class=student[i+1]._class;
		io--;
	}
}
//删除学生

void del(){
	int id = check();
	char ch[1];
	while(1){
		printf("确定删除此数据吗(Y/N)\n");
		scanf("%s",ch);
		if(!strcmp(ch,"Y")){
			_del(id);
			printf("删除成功\n");
			return;
		}
		else if(!strcmp(ch,"N")){
			return;
		}
	}
}
//删除确定

void save(){
	FILE * fp ;
	fp = fopen("message.txt","w");
	int i;
	for(i=0;i<io;i++){
		fprintf(fp,"0\n");
    	fprintf(fp,"%s\n",student[i].StudentID);
    	fprintf(fp,"%s\n",student[i].name);
    	fprintf(fp,"%d\n",student[i].age);
    	fprintf(fp,"%s\n",student[i].sex);
    	fprintf(fp,"%d\n",student[i].tel);
    	fprintf(fp,"%d\n",student[i]._class);
    	fprintf(fp,"%d\n",student[i].cours);
	}
	fprintf(fp,"1");
	fclose(fp);
	printf("===============\n");
	printf("[*]文件保存成功\n");
	printf("===============\n");
}
//保存学生信息到本地

void csave(){
	FILE * fp ;
	fp = fopen("course.txt","w");
	int i;
	for(i=0;i<cid;i++){
		fprintf(fp,"0\n");
    	fprintf(fp,"%s\n",course[i]._name);
    	fprintf(fp,"%s\n",course[i]._xingzhi);
    	fprintf(fp,"%d\n",course[i].time);
    	fprintf(fp,"%d\n",course[i].p_num);
    	fprintf(fp,"%d\n",course[i].term);
	}
	fprintf(fp,"1");
	fclose(fp);
	printf("===============\n");
	printf("[*]文件保存成功\n");
	printf("===============\n");
}
//保存课程信息到本地

void read(){
	FILE * fp;
	fp = fopen("message.txt","r");
	while(1){
		int flag=0;
		fscanf(fp,"%d",&flag);
		if(flag){
			printf("===============\n");
			printf("[*]文件读取成功\n");
			printf("===============\n");
			return;
		}
		fscanf(fp,"%s",student[io].StudentID);
		replace(student[io].StudentID);
    	fscanf(fp,"%s",student[io].name);
    	fscanf(fp,"%d",&student[io].age);
    	fscanf(fp,"%s",student[io].sex);
    	fscanf(fp,"%d",&student[io].tel);
    	fscanf(fp,"%d",&student[io]._class);
    	fscanf(fp,"%d",&student[io].cours);
    	io+=1;
	}

}
//读取学生信息

void cread(){
	FILE * fp;
	fp = fopen("course.txt","r");
	while(1){
		int flag=0;
		fscanf(fp,"%d",&flag);
		if(flag){
			printf("===============\n");
			printf("[*]文件读取成功\n");
			printf("===============\n");
			return;
		}
		fscanf(fp,"%s",course[cid]._name);
		replace(student[cid].StudentID);
    	fscanf(fp,"%s",course[cid]._xingzhi);
    	fscanf(fp,"%d",&course[cid].time);
    	fscanf(fp,"%d",&course[cid].p_num);
    	fscanf(fp,"%d",&course[cid].term);
    	cid+=1;
	}
}
//读取课程信息

void stdu(){
    int i;
    while(1){
        printf("\n选择功能\n[1] 录入\n[2] 查询学生信息\n[3] 编辑\n[4] 统计\n[5] 删除信息\n[6] 存储信息到文件\n[7] 读取文件信息\n[9] 离开子程序\n请输入选择：");
        scanf("%d",&i);
        switch(i){
            case 1:
                _scanf(io);
                break;
            case 2:
                pcheck();
                break;
            case 3:
                edit();
                break;
            case 4:
            	count();
            	break;
            case 5:
            	del();
            	break;
            case 6:
            	save();
            	break;
            case 7:
            	read();
            	break;
            case 9:
				return;
            default:
                printf("ERROR");
        }
    }
}
//学生子系统

void cour(){
	int i;
    while(1){
        printf("\n选择功能\n[1] 录入\n[2] 查询课程信息\n[3]存储信息到文件\n[4] 读取文件信息\n[9] 离开子程序\n请输入选择：");
        scanf("%d",&i);
        switch(i){
            case 1:
                c_scanf();
                break;
            case 2:
				c_check();
				break;
			case 3:
				csave();
				break;
			case 4:
				cread();
				break;
			case 5:
				c_print(0);
            case 9:
				return;
            default:
                printf("ERROR");
        }
    }
}
//课程子系统

void chose_cour(){
	int i=0;
	int id;
	printf("请输入你的学号\n");
	id = check();
	if(id==-1){
		return;
	}
	for(i=0;i<cid;i++){
		printf("可选课程 [%d]\n",i+1);
		c_print(i);
	}
	printf("请输入你要选择课程的编号: ");
	int chose;
	scanf("%d",&chose);
    if(course[chose-1].p_num<=0){
        printf("课程已满");
        return;
    }
    if(chose-1==student[id].cours){
        printf("同学，你已经选过这门课啦！");
        return;
    }
	student[id].cours = chose-1;
	course[id].p_num-=1;
	printf("选课成功!不要翘课哦!\n");
}
//选课系统

void scprint(int i){
	printf("===================\n");
    printf("姓名：%s\n",student[i].name);
    printf("学号：%s\n",student[i].StudentID);
    printf("年龄：%d\n",student[i].age);
    printf("性别：%s\n",student[i].sex);
    printf("电话：%d\n",student[i].tel);
    printf("班级：%d\n",student[i]._class);
    printf("已选课程: %s\n",course[student[i].cours]._name);
    printf("===================\n");
}
//打印学生和选课信息

void look(){
		int id;
	printf("请输入你的学号\n");
	id = check();
	if(id==-1){
		return;
	}
	scprint(id);
}
//确认学号

void t_cour(){
	int id;
	printf("请输入你的学号\n");
	id = check();
	if(id==-1){
		return;
	}
	int c_id;
	printf("确定退选已选课程(1.确定  2.取消)");
	scanf("%d",&c_id);
	if(c_id==1){
		course[student[id].cours].p_num+=1;
		student[id].cours =-1;
		printf("退选成功!\n");
	}
	return;
}
//退选课程功能

void chos(){
	while(1){
		int i;
		printf("\n=============\n[1] 选课\n[2] 退课\n[3] 查看当前信息\n=============\n请输入选择：");
		scanf("%d",&i);
		switch(i){
			case 1:
				chose_cour();
				break;
			case 2:
				t_cour();
				break;
			case 3:
				look();
				break;
			default:
				return ;
		}
	}
}
//选课子系统

void pwd_cour(){
	char pwd[20];
	printf("请输入管理员密码:");
	scanf("%s",pwd);
	if(!strcmp(abase64(pwd),"YWRtaW4=")){
		printf("登入成功!\n");
		cour(); 
	}
	else
		printf("非法用户!!!你没有此子程序的使用权限!!!\n");
	return; 
}


int main(){
    printf("===============\n");
    printf("学生选修课系统:\n");
    printf("===============\n");
	//美化界面
    int i;
    while(1){
    	    printf("\n===================\n[1] 学生信息管理\n[2] 课程信息管理\n[3] 学生选课\n[4] 离开程序\n===================\n请输入选择：");
    	scanf("%d",&i);
    	switch(i){
			case 1:
    			stdu();
    			break;
			case 2:
				pwd_cour();
				break;
			case 3:
				chos();
				break;
			case 4:
				return 0;
			default:
				printf("ERROR\n");
				break;
    	}
    }
}
//主函数