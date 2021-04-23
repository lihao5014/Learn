-- MySQL dump 10.13  Distrib 8.0.16, for Win64 (x86_64)
--
-- Host: localhost    Database: paradigmdb
-- ------------------------------------------------------
-- Server version	8.0.16

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
 SET NAMES utf8 ;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `customer`
--

DROP TABLE IF EXISTS `customer`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `customer` (
  `客户编号` int(11) NOT NULL AUTO_INCREMENT,
  `客户姓名` varchar(32) DEFAULT NULL,
  `所属公司` varchar(32) DEFAULT NULL,
  `联系方式` varchar(16) DEFAULT NULL,
  PRIMARY KEY (`客户编号`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `customer`
--

LOCK TABLES `customer` WRITE;
/*!40000 ALTER TABLE `customer` DISABLE KEYS */;
INSERT INTO `customer` VALUES (1,'李聪','五一建筑','13253661015'),(2,'刘新明','中铁十五局','13814535875');
/*!40000 ALTER TABLE `customer` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `order`
--

DROP TABLE IF EXISTS `order`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `order` (
  `订单编号` varchar(16) NOT NULL,
  `商品编号` int(11) NOT NULL,
  `商品名称` varchar(32) DEFAULT NULL,
  `数量` int(11) DEFAULT NULL,
  `单位` varchar(8) DEFAULT NULL,
  `价格` int(11) DEFAULT NULL,
  `客户` varchar(32) DEFAULT NULL,
  `所属单位` varchar(32) DEFAULT NULL,
  `联系方式` varchar(32) DEFAULT NULL,
  PRIMARY KEY (`订单编号`,`商品编号`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `order`
--

LOCK TABLES `order` WRITE;
/*!40000 ALTER TABLE `order` DISABLE KEYS */;
INSERT INTO `order` VALUES ('001',1,'挖掘机',1,'台',1200000,'张三','中国五冶集团','020-1234567'),('001',2,'冲击钻',8,'把',230,'张三','中国五冶集团','020-1234567'),('003',3,'铲车',2,'辆',980000,'李四','四川华西集团','010-7654321');
/*!40000 ALTER TABLE `order` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `order_2nf`
--

DROP TABLE IF EXISTS `order_2nf`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `order_2nf` (
  `订单编号` varchar(16) NOT NULL,
  `商品编号` int(11) NOT NULL,
  `数量` int(11) DEFAULT NULL,
  PRIMARY KEY (`订单编号`,`商品编号`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `order_2nf`
--

LOCK TABLES `order_2nf` WRITE;
/*!40000 ALTER TABLE `order_2nf` DISABLE KEYS */;
INSERT INTO `order_2nf` VALUES ('001',1,1),('001',2,8),('003',3,2);
/*!40000 ALTER TABLE `order_2nf` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `orderinfo`
--

DROP TABLE IF EXISTS `orderinfo`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `orderinfo` (
  `订单编号` varchar(16) NOT NULL,
  `客户` varchar(32) DEFAULT NULL,
  `所属单位` varchar(32) DEFAULT NULL,
  `联系方式` varchar(32) DEFAULT NULL,
  PRIMARY KEY (`订单编号`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `orderinfo`
--

LOCK TABLES `orderinfo` WRITE;
/*!40000 ALTER TABLE `orderinfo` DISABLE KEYS */;
INSERT INTO `orderinfo` VALUES ('001','张三','中国五冶集团','020-1234567'),('002','张三','中国五冶集团','020-1234567'),('003','李四','四川华西集团','010-7654321');
/*!40000 ALTER TABLE `orderinfo` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `productinfo`
--

DROP TABLE IF EXISTS `productinfo`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `productinfo` (
  `商品编号` int(11) NOT NULL,
  `商品名称` varchar(32) DEFAULT NULL,
  `单位` varchar(8) DEFAULT NULL,
  `价格` int(11) DEFAULT NULL,
  PRIMARY KEY (`商品编号`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `productinfo`
--

LOCK TABLES `productinfo` WRITE;
/*!40000 ALTER TABLE `productinfo` DISABLE KEYS */;
INSERT INTO `productinfo` VALUES (1,'挖掘机','台',1200000),(2,'冲击钻','把',230),(3,'铲车','辆',980000);
/*!40000 ALTER TABLE `productinfo` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `sale`
--

DROP TABLE IF EXISTS `sale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `sale` (
  `订单编号` varchar(16) NOT NULL,
  `商品名称` varchar(32) DEFAULT NULL,
  `业务员` varchar(32) DEFAULT NULL,
  `数量` int(11) DEFAULT NULL,
  `单位` varchar(8) DEFAULT NULL,
  `客户姓名` varchar(32) DEFAULT NULL,
  `所属公司` varchar(32) DEFAULT NULL,
  `联系方式` varchar(16) DEFAULT NULL,
  PRIMARY KEY (`订单编号`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `sale`
--

LOCK TABLES `sale` WRITE;
/*!40000 ALTER TABLE `sale` DISABLE KEYS */;
INSERT INTO `sale` VALUES ('001','挖掘机','李季东',1,'台','李聪','五一建筑','13253661015'),('002','冲击钻','霍新峰',8,'个','刘新明','中铁十五局','13814535875'),('003','铲车','郭新明',2,'辆','李聪','五一建筑','13253661015');
/*!40000 ALTER TABLE `sale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `sale_3nf`
--

DROP TABLE IF EXISTS `sale_3nf`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `sale_3nf` (
  `订单编号` varchar(16) NOT NULL,
  `商品名称` varchar(32) DEFAULT NULL,
  `业务员` varchar(32) DEFAULT NULL,
  `数量` int(11) DEFAULT NULL,
  `单位` varchar(8) DEFAULT NULL,
  `客户编号` int(11) DEFAULT NULL,
  PRIMARY KEY (`订单编号`),
  KEY `客户编号` (`客户编号`),
  CONSTRAINT `sale_3nf_ibfk_1` FOREIGN KEY (`客户编号`) REFERENCES `customer` (`客户编号`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `sale_3nf`
--

LOCK TABLES `sale_3nf` WRITE;
/*!40000 ALTER TABLE `sale_3nf` DISABLE KEYS */;
INSERT INTO `sale_3nf` VALUES ('001','挖掘机','李季东',1,'台',1),('002','冲击钻','霍新峰',8,'个',2),('003','铲车','郭新明',2,'辆',1);
/*!40000 ALTER TABLE `sale_3nf` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `userinfo`
--

DROP TABLE IF EXISTS `userinfo`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `userinfo` (
  `编号` int(11) NOT NULL,
  `姓名` varchar(20) DEFAULT NULL,
  `性别` varchar(8) DEFAULT NULL,
  `年龄` int(11) DEFAULT NULL,
  `电话` varchar(20) DEFAULT NULL,
  `地址` varchar(64) DEFAULT NULL,
  PRIMARY KEY (`编号`),
  CONSTRAINT `check_age` CHECK (((`年龄` > 0) and (`年龄` < 100))),
  CONSTRAINT `check_sex` CHECK (((`性别` = _utf8mb3'男') or (`性别` = _utf8mb3'女')))
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `userinfo`
--

LOCK TABLES `userinfo` WRITE;
/*!40000 ALTER TABLE `userinfo` DISABLE KEYS */;
INSERT INTO `userinfo` VALUES (1,'张红欣','男',26,'0378-23459876','河南省，开封市，朝阳区新华路23号'),(2,'李四平','女',32,'0751-65432584','广东省，广州市，白云区天明路148号'),(3,'刘志国','男',21,'0371-87659852','河南省，郑州市，二七区大学路198号'),(4,'郭小明','女',27,'0371-62556789','河南省，郑州市，新郑区薛店北街218号');
/*!40000 ALTER TABLE `userinfo` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `userinfo_1nf`
--

DROP TABLE IF EXISTS `userinfo_1nf`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `userinfo_1nf` (
  `编号` int(11) NOT NULL AUTO_INCREMENT,
  `姓名` varchar(20) DEFAULT NULL,
  `性别` varchar(8) DEFAULT NULL,
  `年龄` int(11) DEFAULT NULL,
  `电话` varchar(20) DEFAULT NULL,
  `省` varchar(20) DEFAULT NULL,
  `市` varchar(20) DEFAULT NULL,
  `详细地址` varchar(64) DEFAULT NULL,
  PRIMARY KEY (`编号`)
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `userinfo_1nf`
--

LOCK TABLES `userinfo_1nf` WRITE;
/*!40000 ALTER TABLE `userinfo_1nf` DISABLE KEYS */;
INSERT INTO `userinfo_1nf` VALUES (1,'张红欣','男',26,'0378-23459876','河南','开封','朝阳区新华路23号'),(2,'李四平','女',32,'0751-65432584','广东','广州','白云区天明路148号'),(3,'刘志国','男',21,'0371-87659852','河南','郑州','二七区大学路198号'),(4,'郭小明','女',27,'0371-62556789','河南','郑州','新郑区薛店北街218号');
/*!40000 ALTER TABLE `userinfo_1nf` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2021-04-24  3:35:30
