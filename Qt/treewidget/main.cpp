#include <QApplication>
#include <QTreeWidget>
#include <QTreeWidgetItem>

static void initTreeWidget(QTreeWidget* ptreeWgt);
static void treeItemChange(QTreeWidgetItem* pitem,int column);
static void updateParent(QTreeWidgetItem* pparentItem);

int main(int argc,char* argv[])
{
	QApplication app(argc,argv);
	
	/*main函数中的主窗口一般定义为栈对象，而主窗口中的其他控件一般定义为堆对象，
	 *并将它们的parent父对象直接或间接指定为主窗口，以便实现堆对象的自动内存回收。
	 */
	QTreeWidget treeWgt;
	initTreeWidget(&treeWgt);
	
	QObject::connect(&treeWgt,QTreeWidget::itemChanged,treeItemChange);
	treeWgt.show();

	return app.exec();
}

void initTreeWidget(QTreeWidget* ptreeWgt)
{
	ptreeWgt->setWindowTitle("tree widget test");
	ptreeWgt->resize(400,300);
	ptreeWgt->setHeaderHidden(true);
	
	/********创建地址分组节点*********/
	QTreeWidgetItem* groupAddress = new QTreeWidgetItem(ptreeWgt);
	groupAddress->setText(0,"address");
	groupAddress->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
	groupAddress->setCheckState(0,Qt::Unchecked);
	groupAddress->setExpanded(true);
	
	QTreeWidgetItem* beijingItem = new QTreeWidgetItem(groupAddress);
	beijingItem->setText(0,"beijing");
	beijingItem->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
	beijingItem->setCheckState(0,Qt::Unchecked);
	
	QTreeWidgetItem* shanghaiItem = new QTreeWidgetItem;
	shanghaiItem->setText(0,"shanghai");
	shanghaiItem->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
	shanghaiItem->setCheckState(0,Qt::Unchecked);
	groupAddress->addChild(shanghaiItem);     //将上海添加到地址分组里面
	
	QTreeWidgetItem* hongkongItem = new QTreeWidgetItem();
	hongkongItem->setText(0,"hongkong");
	hongkongItem->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
	hongkongItem->setCheckState(0,Qt::Unchecked);
	groupAddress->addChild(hongkongItem);     //将香港添加到地址分组里面

	/********创建姓名分组节点*********/
	QTreeWidgetItem* groupName = new QTreeWidgetItem;
	groupName->setText(0,"name");
	groupName->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
	groupName->setCheckState(0,Qt::Unchecked);
	ptreeWgt->addTopLevelItem(groupName);
	groupName->setExpanded(true);    //必须要将groupName先添加到ptreeWgt中展开才能生效，不然不会生效
	
	QTreeWidgetItem* amyItem = new QTreeWidgetItem(groupName);
	amyItem->setText(0,"amy");
	amyItem->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
	amyItem->setCheckState(0,Qt::Unchecked);

	QTreeWidgetItem* bobItem = new QTreeWidgetItem;
	bobItem->setText(0,"bob");
	bobItem->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
	bobItem->setCheckState(0,Qt::Unchecked);
	groupName->addChild(bobItem);
	
	QTreeWidgetItem* lisaItem = new QTreeWidgetItem();
	lisaItem->setText(0,"lisa");
	lisaItem->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
	lisaItem->setCheckState(0,Qt::Unchecked);
	groupName->addChild(lisaItem);
}

void treeItemChange(QTreeWidgetItem* pitem,int column)
{
	if(pitem == nullptr)
		return ;
	
	int count = pitem->childCount();
	if(Qt::Checked == pitem->checkState(column))
	{
		//说明父节点被选中，那么只需要将它下面的所有子节点设置为选中状态
		if(count > 0)
		{
			for(int i=0;i<count;++i)
			{
				pitem->child(i)->setCheckState(0,Qt::Checked);
			}
			return ;
		}
	}
	else if(Qt::Unchecked == pitem->checkState(column))
	{
		//说明父节点被取消选中，那么就只需要将它下面的所子节点设置为非选中状态
		if(count > 0)
		{
			for(int i=0;i<count;++i)
			{
				pitem->child(i)->setCheckState(0,Qt::Unchecked);
			}
			return ;
		}
	}
	
	//如果是子节点被选中或取消选中，那么就得继续判断他的其他兄弟节点的状态，来设置父节点的选择状态
	QTreeWidgetItem* parentItem = pitem->parent();
	updateParent(parentItem);
}

void updateParent(QTreeWidgetItem* pparentItem)
{
	if(pparentItem == nullptr)
		return ;
	
	int selectCount = 0;     //统计父节点下被选中子节点的个数
	int childCount = pparentItem->childCount();
	for(int i=0;i<childCount;++i)
	{
		if(Qt::Checked == pparentItem->child(i)->checkState(0))
		{
			selectCount++;
		}
	}
	
	/*这里的if-else if-else语句不能改为switch-case-default语句，
	 *因为case语句后只能接常量表格式，而childCount是一个变量。
	 */
	if(selectCount == 0)
	{
		pparentItem->setCheckState(0,Qt::Unchecked);   //未选中状态
	}
	else if(selectCount == childCount)
	{
		pparentItem->setCheckState(0,Qt::Checked);     //选中状态
	}
	else
	{
		pparentItem->setCheckState(0,Qt::PartiallyChecked);   //部分选中状态
	}
}