PRAGMA foreign_keys=OFF;
BEGIN TRANSACTION;
CREATE TABLE user_login(user_id int,login_time datetime);
INSERT INTO user_login VALUES(1,'2019/1/1 6:00');
INSERT INTO user_login VALUES(1,'2019/1/2 10:00');
INSERT INTO user_login VALUES(1,'2019/1/4 19:00');
INSERT INTO user_login VALUES(2,'2019/1/2 10:00');
INSERT INTO user_login VALUES(2,'2019/1/3 9:00');
INSERT INTO user_login VALUES(2,'2019/1/9 14:00');
INSERT INTO user_login VALUES(3,'2019/1/3 8:00');
INSERT INTO user_login VALUES(3,'2019/1/4 10:00');
COMMIT;
