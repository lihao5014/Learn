/*1.测试数据库表名和字段
 *（1）学生表：Student(s_id,s_name,s_birth,s_sex);  -- 学生编号、学生姓名、出生年月、学生性别
 *（2）课程表：Course(c_id,c_name,t_id);  -- 课程编号、课程名称、教师编号
 *（3）教师表：Teacher(t_id,t_name);  #教师编号、教师姓名
 *（4）成绩表：Score(s_id,c_id,s_score);  #学生编号、课程编号、课程分数
 */

#先删除测试使用的classdb数据库
drop database if exists classdb;

#重新创建classdb数据库
create database if not exists classdb;

#切换到classdb数据库中
use classdb;

-- 创建学生表
create table Student (
	s_id varchar(20),
	s_name varchar(20) not null default '',
	s_birth varchar(20) not null default '',
	s_sex varchar(20) not null default '',
	primary key(s_id)
);

-- 创建课程表
create table Course (
	c_id varchar(20),
	c_name varchar(20) not null default '',
	t_id varchar(20) not null,
	primary key(c_id)
);

-- 创建教师表
create table Teacher (
	t_id varchar(20),
	t_name varchar(20) not null default '',
	primary key(t_id)
);

-- 创建成绩表
create table Score (
	s_id varchar(20),
	c_id varchar(20),
	s_score int(3),
	primary key(s_id,c_id)
);

-- 学生表测试数据
insert into Student values('01','赵雷','1990-01-01','男');
insert into Student values('02','钱电','1990-12-21','男');
insert into Student values('03','孙风','1990-05-20','男');
insert into Student values('04','李云','1990-08-06','男');
insert into Student values('05','周梅','1991-12-01','女');
insert into Student values('06','吴兰','1992-03-01','女');
insert into Student values('07','郑竹','1989-07-01','女');
insert into Student values('08','王菊','1990-01-20','女');

-- 课程表测试数据
insert into Course values('01','语文','02');
insert into Course values('02','数学','01');
insert into Course values('03','英语','03');

-- 教师表测试数据
insert into Teacher values('01','张三');
insert into Teacher values('02','李四');
insert into Teacher values('03','王五');

-- 成绩表测试数据
insert into Score values('01','01',80);
insert into Score values('01','02',90);
insert into Score values('01','03',99);
insert into Score values('02','01',70);
insert into Score values('02','02',60);
insert into Score values('02','03',80);
insert into Score values('03','01',80);
insert into Score values('03','02',80);
insert into Score values('03','03',80);
insert into Score values('04','01',50);
insert into Score values('04','02',30);
insert into Score values('04','03',20);
insert into Score values('05','01',76);
insert into Score values('05','02',87);
insert into Score values('06','01',31);
insert into Score values('06','03',34);
insert into Score values('07','02',89);
insert into Score values('07','03',98);
