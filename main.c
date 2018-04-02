//
//  main.c
//  程序设计
//
//  Created by 黄兴源 on 2018/4/2.
//  Copyright © 2018年 黄兴源. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
    printf("姓名：%s\n",student[i].name);
    printf("学号：%s\n",student[i].StudentID);
    printf("年龄：%d\n",student[i].age);
    printf("性别：%s\n",student[i].sex);
    printf("电话：%d\n",student[i].tel);
    printf("班级：%d\n",student[i]._class);
}
void check(){
    char id[20];
    int i;
    printf("请输入您要查询的学号");
    scanf("%s",id);
    for(i=0;i<io;i++){
        if(!strcmp(student[i].StudentID,id)){
            _print(i);
            return;
        }
    }
    printf("不存在的");
}

void fun(){
    int i;
    while(1){
        printf("\n选择功能\n1.录入\n2.读取\n3.查询\n4.编辑和删除\n5.统计\n6.退出\n请输入选择：");
        scanf("%d",&i);
        switch(i){
            case 1:
                _scanf(io);
                break;
            case 2:
                check();
                break;
            case 6:
                exit(0);
            default:
                printf("ERROR");
        }
    }
}
int main(){
    fun();
}
