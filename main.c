#include <stdio.h>
#include <stdlib.h>
int io=0;
struct student{
    int age;
    char name[20];
    char StudentID[20];
    char sex[5];
    int _class;
    int tel;
}student[];
struct course{
    int ID;
    char _name[20];
    char _xingzhi[10];
    int time;
    int p_num;
    int term;
}course[];
void _scanf(int i){
    printf("您的姓名：");
    scanf("%s",student[i].name);
    printf("您的学号：");
    scanf("%s",student[i].StudentID);
    printf("您的年龄：");
    scanf("%d",&student[i].age);
    printf("您的性别：");
    scanf("%s",student[i].sex);
    printf("您的电话：");
    scanf("%d",&student[i].tel);
    printf("您的班级：");
    scanf("%d",&student[i]._class);
    io++;
}
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
void check(){
    char id[20];
    int i;
    printf("请输入您要查询的学号:　");
    scanf("%s",id);
    for(i=0;i<io;i++){
        if(!strcmp(student[i].StudentID,id)){
            _print(i);
            return;
        }
    }
    printf("不存在的\n");
}
void edit(){
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
        printf("未查询到学生信息");
        return;
    }
    printf("===================");
    printf("1.修改姓名\n2.修改年龄\n3.修改学号\n4.修改电话\n5.修改班级\n");
    printf("===================");
    int choose;
    scanf("%d",&choose);
    switch(choose){
        case 1:
            scanf("%s",student[checkid].name);
            break;
        case 2:
            scanf("%d",&student[checkid].age);
            break;
        case 3:
            scanf("%s",student[checkid].StudentID);
            break;
        case 4:
            scanf("%d",&student[checkid].tel);
            break;
        case 5:
            scanf("%d",&student[checkid]._class);
            break;
        default:
            return;
    }
}
void fun(){
    int i;
    while(1){
        printf("\n选择功能\n1.录入\n2.读取信息或查询\n3.编辑和删除\n4.统计\n5.退出\n请输入选择：");
        scanf("%d",&i);
        switch(i){
            case 1:
                _scanf(io);
                break;
            case 2:
                check();
                break;
            case 3:
                edit();
                break;
            case 5:
                exit(0);
            default:
                printf("ERROR");
        }
    }
}
int main(){
    printf("=================================\n");
    printf("学生选修课系统：powered by W8Cloud\n");
    printf("=================================\n");
    fun();
}
