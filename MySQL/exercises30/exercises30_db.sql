-- MySQL dump 10.13  Distrib 8.0.16, for Win64 (x86_64)
--
-- Host: localhost    Database: exercises30
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
-- Table structure for table `month_table`
--

DROP TABLE IF EXISTS `month_table`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `month_table` (
  `id` varchar(16) DEFAULT NULL,
  `name` varchar(16) DEFAULT NULL,
  `month_num` int(11) DEFAULT NULL,
  CONSTRAINT `month_table_chk_1` CHECK (((`month_num` >= 1) and (`month_num` <= 12)))
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `month_table`
--

LOCK TABLES `month_table` WRITE;
/*!40000 ALTER TABLE `month_table` DISABLE KEYS */;
INSERT INTO `month_table` VALUES ('E002','王小凤',1),('E001','张文华',2),('E003','孙皓然',3),('E001','张文华',4),('E002','王小凤',5),('E001','张文华',6),('E004','李智瑞',7),('E002','王小凤',8),('E003','孙皓然',9);
/*!40000 ALTER TABLE `month_table` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `sale_table`
--

DROP TABLE IF EXISTS `sale_table`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `sale_table` (
  `year_num` int(11) DEFAULT NULL,
  `month_num` int(11) DEFAULT NULL,
  `sales` int(11) DEFAULT NULL,
  CONSTRAINT `sale_table_chk_1` CHECK ((`year_num` > 0)),
  CONSTRAINT `sale_table_chk_2` CHECK (((`month_num` >= 1) and (`month_num` <= 12)))
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `sale_table`
--

LOCK TABLES `sale_table` WRITE;
/*!40000 ALTER TABLE `sale_table` DISABLE KEYS */;
INSERT INTO `sale_table` VALUES (2019,1,2854),(2019,2,4772),(2019,3,3542),(2019,4,1336),(2019,5,3544),(2018,1,2293),(2018,2,2559),(2018,3,2597),(2018,4,2363);
/*!40000 ALTER TABLE `sale_table` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `score_info_table`
--

DROP TABLE IF EXISTS `score_info_table`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `score_info_table` (
  `id` int(11) DEFAULT NULL,
  `name` varchar(16) DEFAULT NULL,
  `subject` varchar(16) DEFAULT NULL,
  `score` int(11) DEFAULT NULL,
  CONSTRAINT `score_info_table_chk_1` CHECK (((`score` >= 0) and (`score` <= 100)))
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `score_info_table`
--

LOCK TABLES `score_info_table` WRITE;
/*!40000 ALTER TABLE `score_info_table` DISABLE KEYS */;
INSERT INTO `score_info_table` VALUES (1,'王小凤','语文',88),(2,'张文华','语文',70),(3,'徐雨秋','语文',92),(1,'王小凤','数学',55),(2,'张文华','数学',77),(3,'徐雨秋','数学',77),(1,'王小凤','英语',72),(2,'张文华','英语',91),(3,'徐雨秋','英语',93);
/*!40000 ALTER TABLE `score_info_table` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `score_table`
--

DROP TABLE IF EXISTS `score_table`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `score_table` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(16) DEFAULT NULL,
  `class` varchar(16) DEFAULT NULL,
  `score` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`),
  CONSTRAINT `score_table_chk_1` CHECK (((`score` >= 0) and (`score` <= 100)))
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `score_table`
--

LOCK TABLES `score_table` WRITE;
/*!40000 ALTER TABLE `score_table` DISABLE KEYS */;
INSERT INTO `score_table` VALUES (1,'王小凤','一班',88),(2,'刘诗迪','一班',70),(3,'李思雨','一班',92),(4,'张文华','二班',55),(5,'张青云','二班',77),(6,'徐文杰','二班',77),(7,'李智瑞','三班',56),(8,'徐雨秋','三班',91),(9,'孙皓然','三班',93),(10,'李春山','三班',57);
/*!40000 ALTER TABLE `score_table` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `student_info_table`
--

DROP TABLE IF EXISTS `student_info_table`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `student_info_table` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(16) DEFAULT NULL,
  `class` varchar(16) DEFAULT NULL,
  `grade` varchar(16) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=10 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `student_info_table`
--

LOCK TABLES `student_info_table` WRITE;
/*!40000 ALTER TABLE `student_info_table` DISABLE KEYS */;
INSERT INTO `student_info_table` VALUES (1,'王小凤','一班','一年级'),(2,'刘诗迪','一班','二年级'),(3,'李思雨','一班','一年级'),(4,'张文华','二班','二年级'),(5,'张青云','二班','一年级'),(6,'徐文杰','二班','二年级'),(7,'李智瑞','一班','一年级'),(8,'徐雨秋','二班','二年级'),(9,'孙皓然','一班','一年级');
/*!40000 ALTER TABLE `student_info_table` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `student_table`
--

DROP TABLE IF EXISTS `student_table`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `student_table` (
  `id` int(11) NOT NULL,
  `name` varchar(16) DEFAULT NULL,
  `class` varchar(16) DEFAULT NULL,
  `sex` varchar(8) DEFAULT NULL,
  PRIMARY KEY (`id`),
  CONSTRAINT `student_table_chk_1` CHECK (((`sex` = _utf8mb3'男') or (`sex` = _utf8mb3'女')))
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `student_table`
--

LOCK TABLES `student_table` WRITE;
/*!40000 ALTER TABLE `student_table` DISABLE KEYS */;
INSERT INTO `student_table` VALUES (1,'王小凤','一班','女'),(2,'刘诗迪','一班','女'),(3,'李思雨','一班','女'),(4,'张文华','二班','男'),(5,'张青云','二班','女'),(6,'徐文杰','二班','男'),(7,'李智瑞','三班','男'),(8,'徐雨秋','三班','男'),(9,'孙皓然','三班','男'),(10,'李春山','三班','男');
/*!40000 ALTER TABLE `student_table` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2021-04-25 17:29:04
