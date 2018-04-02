// import { resolve } from "dns";

// import { resolve } from "url";

/*
 * @Author: wynnxin 
 * @Date: 2018-04-02 12:53:15 
 * @Last Modified by: wynnxin
 * @Last Modified time: 2018-04-02 19:01:37
 */

const studentsList = document.querySelector(`table tbody`);

let Student = function (Name, Age, Sex, StudentID) {
    this.Name = Name;
    this.Age = Age;
    this.Sex = Sex;
    // this.Tel = Tel;
    // this.Class = Class;
    this.StudentID = StudentID;
};

//添加学生信息
Student.prototype.enteringStudentInfor = function () {

    alert(`添加学生信息成功`);
};

//显示学生信息
Student.prototype.addStudentInfor = function () {
    const studentsTr = document.createElement(`tr`);
    studentsList.appendChild(studentsTr);
    studentsTr.innerHTML =
        `
    <tr class="active  student-list">
        <td>${this.Name}</td>
        <td>${this.Age}</td>
        <td>${this.Sex}</td>
        <td>${this.StudentID}</td>
        <td><button class="btn btn-primary delete-student-infor">删除学生信息</button></td>
        <td><button class="btn btn-primary edit-student-infor">编辑学生信息</button></td>
        <th><button class="btn btn-primary checkout-course">选课情况</button></th>
    </tr>
    `
};

//编辑具体信息
//表格里变成input,默认值是原来的
Student.prototype.editStudentInfor = function () {

};

//删除具体信息
//删除整个<tr>
Student.prototype.deleteStudentInfor = function () {

};

//创建实例
//录入
let student1 = new Student(`wcy`, 19, `woman`, `B17040509`);
let student2 = new Student(`hxy`, 19, `man`, `B17040528`);


student1.addStudentInfor();
student2.addStudentInfor();

//显示隐藏的录入学生信息
const addButton = document.querySelector(`.add-student`);
addButton.addEventListener(`click`, () => document.querySelector(`.student-infor`).setAttribute("style", "margin-top:40px"));

//异步 debug
let getStudentValue = function () {
    return new Promise(function (resolve) {
        let Name = $(`.student-infor .student-infor-name`).val();
        let Age = $(`.student-infor .student-infor-age`).val();
        let Sex = $(`.student-infor select`).find(`option:selected`).val();
        let StudentID = $(`.student-infor-studentid`).val();
        const getName = function () {
            return this.Name;
        };
        const getAge = function () {
            return this.Age;
        };
        const getSex = function () {
            return this.Sex;
        }
        resolve();
        return {
            getName: getName(),
            getAge: getAge(),
        }
    }
    )
}
getStudentValue().then(() => {
    $(`.confirm-add-infor`).click(getStudentValue)
});
console.log(getStudentValue().getName);
//undefined

