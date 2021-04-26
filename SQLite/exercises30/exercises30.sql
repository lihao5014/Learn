/***************30道经典SQL面试题***************/

/*1.查询每个班学生数：
 *  现在有一张全校学生信息表student_table，这张表存储了每位学生的id、name(姓名)、class(班级)、sex(性别)
 *  以及一些其他信息，现在我们想知道每个班有多少学生，该怎么实现呢？
 *
 *（1）学生信息表：
 *  +----+-----------+--------+------+
 *  | id | name      | class  | sex  |
 *  +----+-----------+--------+------+
 *  |  1 | 王小凤    | 一班   | 女   |
 *  |  2 | 刘诗迪    | 一班   | 女   |
 *  |  3 | 李思雨    | 一班   | 女   |
 *  |  4 | 张文华    | 二班   | 男   |
 *  |  5 | 张青云    | 二班   | 女   |
 *  |  6 | 徐文杰    | 二班   | 男   |
 *  |  7 | 李智瑞    | 三班   | 男   |
 *  |  8 | 徐雨秋    | 三班   | 男   |
 *  |  9 | 孙皓然    | 三班   | 男   |
 *  | 10 | 李春山    | 三班   | 男   |
 *  +----+-----------+--------+------+
 */

-- （2）SQL语句：
select
	class,
	count(id) as student_number
from student_table
group by class;

/*（3）查询结果：
 *  +--------+----------------+
 *  | class  | student_number |
 *  +--------+----------------+
 *  | 一班   |              3 |
 *  | 二班   |              3 |
 *  | 三班   |              4 |
 *  +--------+----------------+
 */

/*2.查询每个班男女学生数：
 *  还是前面的全校学生信息表student_table，现在我们想知道每个班男生、女生分别有多少个？
 */

-- （1）SQL语句：
select
	class,
	sex,
	count(id) as student_number
from student_table
group by
	class,
	sex;

/*（2）查询结果：
 *  +--------+------+----------------+
 *  | class  | sex  | student_number |
 *  +--------+------+----------------+
 *  | 一班   | 女   |              3 |
 *  | 二班   | 男   |              2 |
 *  | 二班   | 女   |              1 |
 *  | 三班   | 男   |              4 |
 *  +--------+------+----------------+
 */
 
/*3.姓张的同学有多少个：
 *  还是前面的全校学生信息表student_table，现在我们想知道这张表中姓张的同学有多少个？
 */

-- （1）SQL语句：
select
	group_concat(name) as all_name,
	count(id) as student_number
from student_table
where name like "张%";

/*（2）查询结果：
 *  +---------------------+----------------+
 *  | all_name            | student_number |
 *  +---------------------+----------------+
 *  | 张文华,张青云       |              2 |
 *  +---------------------+----------------+
 */

/*4.筛选出id第3-5的同学：
 *还是前面的全校学生信息表student_table，现在我们要获取id从小到大排序以后第3-5位的同学的信息。
 */

-- （1）SQL语句：
select * from student_table order by id asc limit 2,3;

/*（2）查询结果：
 *  +----+-----------+--------+------+
 *  | id | name      | class  | sex  |
 *  +----+-----------+--------+------+
 *  |  3 | 李思雨    | 一班   | 女   |
 *  |  4 | 张文华    | 二班   | 男   |
 *  |  5 | 张青云    | 二班   | 女   |
 *  +----+-----------+--------+------+
 */
 
/*5.筛选出挂科的同学：
 *  现在有一张学生成绩表score_table，这张表存储了每位学生的id、name(姓名)、class(班级)、score(成绩)，
 *  现在我们想要把挂科(成绩小于60)的同学信息筛选出来。
 *
 *（1）学生成绩表：
 *  +----+-----------+--------+-------+
 *  | id | name      | class  | score |
 *  +----+-----------+--------+-------+
 *  |  1 | 王小凤    | 一班   |    88 |
 *  |  2 | 刘诗迪    | 一班   |    70 |
 *  |  3 | 李思雨    | 一班   |    92 |
 *  |  4 | 张文华    | 二班   |    55 |
 *  |  5 | 张青云    | 二班   |    77 |
 *  |  6 | 徐文杰    | 二班   |    77 |
 *  |  7 | 李智瑞    | 三班   |    56 |
 *  |  8 | 徐雨秋    | 三班   |    91 |
 *  |  9 | 孙皓然    | 三班   |    93 |
 *  | 10 | 李春山    | 三班   |    57 |
 *  +----+-----------+--------+-------+
 */

-- （2）SQL语句：
select * from score_table where score < 60;

/*（3）查询结果：
 *  +----+-----------+--------+-------+
 *  | id | name      | class  | score |
 *  +----+-----------+--------+-------+
 *  |  4 | 张文华    | 二班   |    55 |
 *  |  7 | 李智瑞    | 三班   |    56 |
 *  | 10 | 李春山    | 三班   |    57 |
 *  +----+-----------+--------+-------+
 */

/*6.筛选姓张的且挂科的同学：
 *  我们现在需要根据学生成绩表score_table查找出姓张的且挂科的同学的信息。
 */

-- （1）SQL语句：
select * from score_table where name like '张%' and score < 60;

/*（2）查询结果：
 *  +----+-----------+--------+-------+
 *  | id | name      | class  | score |
 *  +----+-----------+--------+-------+
 *  |  4 | 张文华    | 二班   |    55 |
 *  +----+-----------+--------+-------+
 */

/*7.查询销售冠获得次数：
 *  我们有一张表month_table记录了每月的销售冠军信息，这张表存储了每月销冠的id、name(姓名)、month_num(月份)，
 *  现在需要获取销冠次数超过2次的人以及其对应的做销冠次数。
 *
 *（1）月度销售冠军信息表：
 *  +------+-----------+-----------+
 *  | id   | name      | month_num |
 *  +------+-----------+-----------+
 *  | E002 | 王小凤    |         1 |
 *  | E001 | 张文华    |         2 |
 *  | E003 | 孙皓然    |         3 |
 *  | E001 | 张文华    |         4 |
 *  | E002 | 王小凤    |         5 |
 *  | E001 | 张文华    |         6 |
 *  | E004 | 李智瑞    |         7 |
 *  | E002 | 王小凤    |         8 |
 *  | E003 | 孙皓然    |         9 |
 *  +------+-----------+-----------+
 */

-- （2）SQL语句：
select
	name,
	count(id) as championship_num
from month_table
group by name
having count(id) > 2;      -- having中可以使用聚合函数，而where中不能使用聚合函数

/*（3）查询结果：
 *  +-----------+------------------+
 *  | name      | championship_num |
 *  +-----------+------------------+
 *  | 王小凤    |                3 |
 *  | 张文华    |                3 |
 *  +-----------+------------------+
 */

/*8.获取每个部门一整年业绩提升幅度：
 *  现在有一个月份销售额记录表sale_table，这个表记录了每年每月的销售额，现在我们想看下今年(2019年)，
 *  月销售额最高涨幅是多少？
 *
 *（1）销售额记录表：
 *  +----------+-----------+-------+
 *  | year_num | month_num | sales |
 *  +----------+-----------+-------+
 *  |     2019 |         1 |  2854 |
 *  |     2019 |         2 |  4772 |
 *  |     2019 |         3 |  3542 |
 *  |     2019 |         4 |  1336 |
 *  |     2019 |         5 |  3544 |
 *  |     2018 |         1 |  2293 |
 *  |     2018 |         2 |  2559 |
 *  |     2018 |         3 |  2597 |
 *  |     2018 |         4 |  2363 |
 *  +----------+-----------+-------+
 */

-- （2）SQL语句：
select 
	min(sales) as min_sales,
	max(sales) as max_sales,
	max(sales) - min(sales) as max_increment,
	(max(sales) - min(sales)) / min(sales) as growth
from sale_table
where year_num = 2019;

/*（3）查询结果：
 *  +-----------+-----------+---------------+--------+
 *  | min_sales | max_sales | max_increment | growth |
 *  +-----------+-----------+---------------+--------+
 *  |      1336 |      4772 |          3436 | 2.5719 |
 *  +-----------+-----------+---------------+--------+
 */

/*9.查找每科成绩大于70的学生：
 *  我们有一张学生科目成绩表score_info_table，这张表记录了每一位同学每一科目的成绩，
 *  每一位同学的每科成绩是一行，现在我们想要通过这张表获取到每科成绩都大于70分的学生。
 *
 *（1）学生科目成绩表：
 *  +------+-----------+---------+-------+
 *  | id   | name      | subject | score |
 *  +------+-----------+---------+-------+
 *  |    1 | 王小凤    | 语文    |    88 |
 *  |    2 | 张文华    | 语文    |    70 |
 *  |    3 | 徐雨秋    | 语文    |    92 |
 *  |    1 | 王小凤    | 数学    |    55 |
 *  |    2 | 张文华    | 数学    |    77 |
 *  |    3 | 徐雨秋    | 数学    |    77 |
 *  |    1 | 王小凤    | 英语    |    72 |
 *  |    2 | 张文华    | 英语    |    91 |
 *  |    3 | 徐雨秋    | 英语    |    93 |
 *  +------+-----------+---------+-------+
 */
 
-- （1）使用自连接查询实现：
select
	sc1.id,
	sc1.name,
	sc1.score as '语文',
	sc2.score as '数学',
	sc3.score as '英语'
from 
	score_info_table as sc1,
	score_info_table as sc2,
	score_info_table as sc3
where
	sc1.id = sc2.id
and sc1.subject = '语文'
and sc2.subject = '数学'
and sc1.id = sc3.id
and sc3.subject = '英语'
and sc1.score > 70
and sc2.score > 70
and sc3.score > 70;

/*（2）自连接查询查询结果：
 *  +------+-----------+--------+--------+--------+
 *  | id   | name      | 语文   | 数学   | 英语   |
 *  +------+-----------+--------+--------+--------+
 *  |    3 | 徐雨秋    |     92 |     77 |     93 |
 *  +------+-----------+--------+--------+--------+
 */

-- （3）使用聚合函数实现：
select 
	id,
	name,
	group_concat(subject) as '科目',
	group_concat(score) as '分数' 
from score_info_table 
group by name 
having min(score) > 70;


/*（4）使用聚合函数查询结果：
 *  +------+-----------+----------------------+----------+
 *  | id   | name      | 科目                 | 分数     |
 *  +------+-----------+----------------------+----------+
 *  |    3 | 徐雨秋    | 语文,数学,英语       | 92,77,93 |
 *  +------+-----------+----------------------+----------+
 */

/*10.删除重复值：
 *现在有一个学生信息表student_info_table，这张表存储了每位学生id、name(姓名)、class(班级)、grade(年级)，
 *现在我们想获取这个学校所有年级以及所有班级的信息，即哪些年级有哪些班级，该怎么获取？
 *
 *（1）学生信息表：
 *  +----+-----------+--------+-----------+
 *  | id | name      | class  | grade     |
 *  +----+-----------+--------+-----------+
 *  |  1 | 王小凤    | 一班   | 一年级    |
 *  |  2 | 刘诗迪    | 一班   | 二年级    |
 *  |  3 | 李思雨    | 一班   | 一年级    |
 *  |  4 | 张文华    | 二班   | 二年级    |
 *  |  5 | 张青云    | 二班   | 一年级    |
 *  |  6 | 徐文杰    | 二班   | 二年级    |
 *  |  7 | 李智瑞    | 一班   | 一年级    |
 *  |  8 | 徐雨秋    | 二班   | 二年级    |
 *  |  9 | 孙皓然    | 一班   | 一年级    |
 *  +----+-----------+--------+-----------+
 */
 
-- （2）SQL语句：
select 
	grade "年级",
	class as '班级' 
from student_info_table 
group by 
	grade,
	class
order by grade;

/*（3）查询结果：
 *  +-----------+--------+
 *  | 年级      | 班级   |
 *  +-----------+--------+
 *  | 一年级    | 一班   |
 *  | 一年级    | 二班   |
 *  | 二年级    | 一班   |
 *  | 二年级    | 二班   |
 *  +-----------+--------+
 */
 
/*11.行列互换（长型数据变为宽型数据）:
 *  将销售额记录表sale_table中的数据，由每个月份销售额纵向存储数据的方式，改成按每个月份销售额横向存储的方式。
 */
 
-- （1）SQL语句：
select 
	year_num,
	sum(case when month_num =1 then sales end) as '1月',
	sum(case when month_num =2 then sales end) as '2月',
	sum(case when month_num =3 then sales end) as '3月',
	sum(case when month_num =4 then sales end) as '4月',
	sum(case when month_num =5 then sales end) as '5月'
from sale_table
group by year_num;

/*（2）行列互换结果：
 *  +----------+------+------+------+------+------+
 *  | year_num | 1月  | 2月  | 3月  | 4月  | 5月  |
 *  +----------+------+------+------+------+------+
 *  |     2019 | 2854 | 4772 | 3542 | 1336 | 3544 |
 *  |     2018 | 2293 | 2559 | 2597 | 2363 | NULL |
 *  +----------+------+------+------+------+------+
 */

/*12.多列比较：
 *  现在表column_table中有column1、column2、column3三列数据，我们需要根据这三列数据生成最后一列结果列，结果列
 *  的生成规则为：如果column1大于column2时选column1列，如果column2大于column3列时选column3列，否则选column3列。
 *
 *（1）数据列表；
 *  +---------+---------+---------+
 *  | column1 | column2 | column3 |
 *  +---------+---------+---------+
 *  |       5 |      10 |       7 |
 *  |       1 |      10 |       6 |
 *  |       9 |       3 |       5 |
 *  |       5 |       2 |       9 |
 *  |      10 |       4 |       3 |
 *  |       5 |       2 |       9 |
 *  |       5 |       8 |       6 |
 *  |       8 |       8 |       6 |
 *  +---------+---------+---------+
 */

-- （2）SQL语句：
select 
	*,
	(case when column1 > column2 then column1
	      when column2 > column3 then column3
	 else column2 
	 end) as result
from column_table;

/*（3）查询结果：
 *  +---------+---------+---------+--------+
 *  | column1 | column2 | column3 | result |
 *  +---------+---------+---------+--------+
 *  |       5 |      10 |       7 |      7 |
 *  |       1 |      10 |       6 |      6 |
 *  |       9 |       3 |       5 |      9 |
 *  |       5 |       2 |       9 |      5 |
 *  |      10 |       4 |       3 |     10 |
 *  |       5 |       2 |       9 |      5 |
 *  |       5 |       8 |       6 |      6 |
 *  |       8 |       8 |       6 |      6 |
 *  +---------+---------+---------+--------+
 */

/*13.对成绩进行分组
 *  我们想知道学生成绩表score_table中60分以下、60-80分、80-100分这三个成绩段内分别有多少学生，该怎实现呢？
 */

-- （1）横向输出：
select
	count(case when score < 60 then id end) as '0-60分',
	count(case when score >= 60 and score < 80 then id end) as '0-80分',
	count(case when score >= 80 and score <= 100 then id end) as '80-100分'
from score_table;

/*（2）横向输出查询结果表：
 *  +---------+---------+-----------+
 *  | 0-60分  | 0-80分  | 80-100分  |
 *  +---------+---------+-----------+
 *  |       3 |       3 |         4 |
 *  +---------+---------+-----------+
 */
 
-- （3）纵向输出：
select 
	(case when score < 60 then '60分以下'
		  when score <= 80 then "60-80分"
		  when score <= 100 then "80-100分"
	 else "其他"
	 end) as '分数段',
	 count(id) "学生数目"
from score_table
group by
	(case when score < 60 then '60分以下'
		  when score <= 80 then "60-80分"
		  when score <= 100 then "80-100分"
	 else "其他"
	 end);

/*（4）纵向输出查询结果表：
 *  +-------------+--------------+
 *  | 分数段      | 学生数目     |
 *  +-------------+--------------+
 *  | 80-100分    |            4 |
 *  | 60-80分     |            3 |
 *  | 60分以下    |            3 |
 *  +-------------+--------------+
 */

/*14.周累计数据获取：
 *  现在我们有一个订单明细表order_table，这张表中存储了order_id(订单id)、order_date(订单日期)以及其他订单相关信息，
 *  我们需要每天获取本周累计的订单数，本周累计是指本周一到获取数据当天，比如今天是周三，那么本周累计就是周一到周三。
 *  这个该怎么实现呢？
 *
 *（1）订单明细表：
 *  +----------+------------+
 *  | order_id | order_date |
 *  +----------+------------+
 *  |        1 | 2019-01-08 |
 *  |        2 | 2019-01-09 |
 *  |        3 | 2019-01-10 |
 *  |        4 | 2019-01-11 |
 *  |        5 | 2020-01-08 |
 *  |        6 | 2020-01-09 |
 *  |        7 | 2020-01-10 |
 *  |        8 | 2020-01-11 |
 *  |        9 | 2020-01-12 |
 *  +----------+------------+
 */
 
-- （2）SQL语句：
select
	curdate(),
	count(order_id) as order_cnt
from order_table
where
	weekofyear(order_date) = weekofyear(curdate())
and year(order_date) = year(curdate());

/*（3）查询结果：
 *  +------------+-----------+
 *  | curdate()  | order_cnt |
 *  +------------+-----------+
 *  | 2021-04-26 |         0 |
 *  +------------+-----------+
 */
 
/*15.周环比数据获取：
 *  我们现在需要根据订单明细表order_table，获取当日的订单数；当日的环比订单数，即昨天的数据。
 */

-- （1）SQL语句：
select
	count(order_id) as order_cnt,
	count(if(date_sub(curdate(),interval 1 day) = order_date,order_id,null)) as last_order_cnt
from order_table;

/*（3）查询结果：
 *  +-----------+----------------+
 *  | order_cnt | last_order_cnt |
 *  +-----------+----------------+
 *  |         9 |              0 |
 *  +-----------+----------------+
 */
 
/*16.查找获奖同学信息：
 *  现在有一张学生信息表student_table，这张表记录了id、name等一些其他信息；还有另外一张获奖名单表winner_table，
 *  这张表记录了获奖学生的id和name。现在我们想要通过student_table获取获奖学生的更多信息。
 *
 *（1）获奖名单表:
 *  +----+-----------+
 *  | id | name      |
 *  +----+-----------+
 *  |  1 | 王小凤    |
 *  |  2 | 刘诗迪    |
 *  |  3 | 李思雨    |
 *  |  7 | 李智瑞    |
 *  |  8 | 徐雨秋    |
 *  |  9 | 孙皓然    |
 *  +----+-----------+
 */
 
-- （2）连接查询：
select
	student_table.*
from
	student_table left join winner_table on student_table.id = winner_table.id
where winner_table.id is not null;

-- （3）子查询：
select *
from student_table
where
	id in(select id from winner_table);

/*（4）查询结果：
 *  +----+-----------+--------+------+
 *  | id | name      | class  | sex  |
 *  +----+-----------+--------+------+
 *  |  1 | 王小凤    | 一班   | 女   |
 *  |  2 | 刘诗迪    | 一班   | 女   |
 *  |  3 | 李思雨    | 一班   | 女   |
 *  |  7 | 李智瑞    | 三班   | 男   |
 *  |  8 | 徐雨秋    | 三班   | 男   |
 *  |  9 | 孙皓然    | 三班   | 男   |
 *  +----+-----------+--------+------+
 */

/*17.计算用户留存情况：
 *  现在有一张用户登陆表user_login，这张表记录了uid(用户id)和login_time(登陆时间)。我们想看用户的
 *  次日留存数、三日留存数、七日留存数，只要用户从首次登陆以后再有登陆就算留存下来了，比如三日登陆
 *  表示用户自首次登陆以后第三天也会进行登陆，该怎么实现呢？
 *
 *（1）用户登录表：
 *  +---------+---------------------+
 *  | user_id | login_time          |
 *  +---------+---------------------+
 *  |       1 | 2019-01-01 06:00:00 |
 *  |       1 | 2019-01-02 10:00:00 |
 *  |       1 | 2019-01-04 19:00:00 |
 *  |       2 | 2019-01-02 10:00:00 |
 *  |       2 | 2019-01-03 09:00:00 |
 *  |       2 | 2019-01-09 14:00:00 |
 *  |       3 | 2019-01-03 08:00:00 |
 *  |       3 | 2019-01-04 10:00:00 |
 *  +---------+---------------------+
 */
 
-- （2）SQL语句：
select
	(case when t3.day_value = 1 then "次日留存"
  	      when t3.day_value = 3 then "三日留存"
	      when t3.day_value = 7 then "七日留存"
    else "其他"
    end) as type,
    count(t3.user_id) userid_cnt
from
   (select
        t1.user_id,
		t1.first_time,
		t2.last_time,
		datediff(t2.last_time,t1.first_time) day_value
	from
		(select
			user_id,
			date(min(login_time)) as first_time
        from user_login
        group by user_id) t1
    left join
        (select
            user_id,
            date(max(login_time)) as last_time
        from user_login
        group by user_id) t2
    on t1.user_id = t2.user_id) t3
group by
        (case when t3.day_value = 1 then "次日留存"
              when t3.day_value = 3 then "三日留存"
              when t3.day_value = 7 then "七日留存"
        else "其他"
        end);

/*（3）查询结果：
 *  +--------------+------------+
 *  | type         | userid_cnt |
 *  +--------------+------------+
 *  | 三日留存     |          1 |
 *  | 七日留存     |          1 |
 *  | 次日留存     |          1 |
 *  +--------------+------------+
 */

/*18.筛选最受欢迎的课程：
 *  现在有一张学生科目表course_table，这张表存储了每一位学生的id、name(姓名)、grade(年级)、course(选修课程)
 *  以及一些其他信息，现在我们想知道哪门课被学生选的人数最多？
 *
 *（1）学生科目表:
 *  +----+-----------+-----------+-----------+
 *  | id | name      | grade     | courses   |
 *  +----+-----------+-----------+-----------+
 *  |  1 | 王小凤    | 一年级    | 心理学    |
 *  |  2 | 刘诗迪    | 二年级    | 心理学    |
 *  |  3 | 李思雨    | 三年级    | 社会学    |
 *  |  4 | 张文华    | 一年级    | 心理学    |
 *  |  5 | 张青云    | 二年级    | 心理学    |
 *  |  6 | 徐文杰    | 三年级    | 计算机    |
 *  |  7 | 李智瑞    | 一年级    | 心理学    |
 *  |  8 | 徐雨秋    | 二年级    | 计算机    |
 *  |  9 | 孙皓然    | 三年级    | 社会学    |
 *  | 10 | 李春山    | 一年级    | 社会学    |
 *  +----+-----------+-----------+-----------+
 */

-- （2）不能解决多门课程选择人数一样的情况：
select 
	courses,
	count(id) as student_num
from course_table
group by courses
order by count(id) desc
limit 1;

-- （3）可以解决多门课程选择人数一样的情况：
select 
	courses,
	count(id) as student_num
from course_table
group by courses
having
	count(id) = (select
					max(temp.student_num) as max_num
                 from
					(select 
						courses,
						count(id) as student_num
					 from course_table
					 group by courses
					) temp
	            );

/*（4）查询结果：
 *  +-----------+-------------+
 *  | courses   | student_num |
 *  +-----------+-------------+
 *  | 心理学    |           5 |
 *  +-----------+-------------+
 */

/*19.筛选出每个年级最受欢迎的三门课程：
 *  还是前面的course_table，现在我们想知道每个年级被选择最多的三门课程,该怎么实现呢？
 */

-- （1）SQL语句：
select 
    *
from
    (select
         tb1.grade,
	     tb1.courses,
		 tb1.stu_num,
	     row_number() over(partition by tb1.grade order by tb1.stu_num desc) as course_rank
    from
        (select
            grade,
            courses,
            count(id) as stu_num
        from
            course_table
        group by
            grade,
            courses
        ) tb1
    ) tb2
where 
    tb2.course_rank < 4;


/*（2）查询结果：
 *  +-----------+-----------+---------+-------------+
 *  | grade     | courses   | stu_num | course_rank |
 *  +-----------+-----------+---------+-------------+
 *  | 一年级    | 心理学    |       3 |           1 |
 *  | 一年级    | 社会学    |       1 |           2 |
 *  | 三年级    | 社会学    |       2 |           1 |
 *  | 三年级    | 计算机    |       1 |           2 |
 *  | 二年级    | 心理学    |       2 |           1 |
 *  | 二年级    | 计算机    |       1 |           2 |
 *  +-----------+-----------+---------+-------------+
 */

/*20.求累积和：
 *  现在有一张2019年一整年的订单表consum_order_table，consum_order_table包含order_id(订单id)、user_id(用户id)、
 *  amount(订单金额)，现在我们想看下80%的订单金额最少是由多少用户贡献的，该怎么实现呢？
 *
 *（1）订单表:
 *  +----------+---------+--------+
 *  | order_id | user_id | amount |
 *  +----------+---------+--------+
 *  |   201901 |       1 |     10 |
 *  |   201902 |       2 |     20 |
 *  |   201903 |       3 |     15 |
 *  |   201904 |       3 |     15 |
 *  |   201905 |       4 |     20 |
 *  |   201906 |       4 |     20 |
 *  |   201907 |       5 |     25 |
 *  |   201908 |       5 |     25 |
 *  |   201909 |       6 |     30 |
 *  |   201910 |       6 |     30 |
 *  |   201911 |       7 |     35 |
 *  |   201912 |       7 |     35 |
 *  +----------+---------+--------+
 */

-- （2）SQL语句：
select
    count(temp.user_id) as consum_count
from
    (select
        user_id,
        amount,
        sum(amount) over(order by amount desc) as consum_amount,
        (sum(amount) over(order by amount desc))/(select sum(amount) from consum_order_table) as consum_amount_rate
    from
        (select
            user_id,
            sum(amount) amount
        from consum_order_table
        group by user_id
        ) user_id_table
	) temp
where 
    temp.consum_amount_rate < 0.8

/*（3）查询结果：
 *  +--------------+
 *  | consum_count |
 *  +--------------+
 *  |            4 |
 *  +--------------+
 */

