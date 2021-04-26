-- 使用.read importtable.sql语句来执行importtable.sql文件中的SQL命令。

/*将student_table.txt文件中的数据导入到student_table表格中。但需要注意在数据导入之前，
 *先要根据文件中数据具体的分隔格式，设置数据导入的间隔符。在student_table.txt文本数据
 *中采用的是tab制表符'\t‘来间隔数据，因此应先调用.seperator '	'设置tab制表符为间隔符。
 */
.import student_table.txt student_table

-- 将score_table.txt文件中的数据导入到score_table表格中。
.import score_table.txt score_table

-- 将month_table.txt文件中的数据导入到month_table表格中。
.import month_table.txt month_table

/*将sale_table.txt文件中的数据导入到sale_table表格中。在sale_table.txt文本数据中采用
 *逗号','来间隔数据，因此应先调用.seperator ','或者.mode csv设置逗号','为间隔符。
 */
.import sale_table.txt sale_table

-- 将score_info_table.txt文件中的数据导入到score_info_table表格中。
.import score_info_table.txt score_info_table

-- 将student_info_table.txt文件中的数据导入到student_info_table表格中。
.import student_info_table.txt student_info_table

-- 将column_table.txt文件中的数据导入到column_table表格中。
.import column_table.txt column_table

-- 将order_table.txt文件中的数据导入到order_table表格中。
.import order_table.txt order_table

-- 将winner_table.txt文件中的数据导入到winner_table表格中。
.import winner_table.txt winner_table

-- 将user_login.txt文件中的数据导入到user_login表格中。
.import user_login.txt user_login

-- 将course_table.txt文件中的数据导入到course_table表格中。
.import course_table.txt course_table

-- 将consum_order_table.txt文件中的数据导入到consum_order_table表格中。
.import consum_order_table.txt consum_order_table
