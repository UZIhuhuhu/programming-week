/*
 * @Author: wynnxin 
 * @Date: 2018-04-02 12:53:15 
 * @Last Modified by: wynnxin
 * @Last Modified time: 2018-04-02 14:55:20
 */

const studentsList = document.querySelector("table tbody");

let Student = function(Name,Age,Sex,Tel,Class,StudentID){
    this.Name = Name;
    this.Age = Age;
    this.Sex = Sex;
    this.Tel = Tel;
    this.Class = Class;
    this.StudentID = StudentID;
};

//添加学生信息
Student.prototype.addStudentInfor = function(){
    const studentsTr = document.createElement("tr");
    studentsList.appendChild(studentsTr);
    studentsTr.innerHTML = 
    `
    <tr class="active  student-list">
        <td>${this.Name}</td>
        <td>${this.Age}</td>
        <td>${this.Sex}</td>
        <td>${this.Tel}</td>
        <td>${this.Class}</td>
        <td>${this.StudentID}</td>
        <td><button class="btn btn-primary delete-student-infor">删除学生信息</button></td>
        <td><button class="btn btn-primary edit-student-infor">编辑学生信息</button></td>
    </tr>
    `
};

//编辑具体信息
Student.prototype.editStudentInfor = function(){

};

//删除具体信息
Student.prototype.deleteStudentInfor = function(){
    
};

//创建实例
let student1 = new Student(`wcy`,19,`woman`,191,5,`B17040509`);
let student2 = new Student(`hxy`,19,`man`,110,5,`B17040528`);

//事件绑定
const addButton = document.querySelector(".add-student");

//执行原型链函数
student1.addStudentInfor();
student2.addStudentInfor();







