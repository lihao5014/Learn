TEMPLATE = subdirs

#编译库文件的项目必须放置到前面，以便先编译库，再编译应用程序
SUBDIRS += school app

CONFIG += ordered