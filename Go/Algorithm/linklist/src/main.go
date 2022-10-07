//直接在Windows cmd命令行中运行build.bat脚本，即可运行main.go测试程序。
package main

import "os"
import "fmt"
import "linklist"

func main(){
	var ls  = linklist.CreateLinkList()
	fmt.Printf("ls.IsNull() =%t ,ls.IsEmpty() =%t ,ls.Length() =%d\n",ls.IsNull(),ls.IsEmpty(),ls.Length())
	
	ls.Append(1.5)
	ls.Append(2.5)
	ls.Append(3.5)
	
	ls.Prepend(5.1)
	ls.Prepend(5.2)
	ls.Prepend(5.2)
	
	ls.Append(4.5)
	ls.Prepend(5.3)
	ls.Display()
	fmt.Printf("ls.IsNull() =%t ,ls.IsEmpty() =%t ,ls.Length() =%d\n",ls.IsNull(),ls.IsEmpty(),ls.Length())
	
	ls.PopFront()
	ls.PopFront()
	ls.Display()
	
	ls.PopBack()
	ls.PopBack()
	ls.Display()
	fmt.Printf("ls.IsNull() =%t ,ls.IsEmpty() =%t ,ls.Length() =%d\n",ls.IsNull(),ls.IsEmpty(),ls.Length())
	
	ls.Insert(2,3.1415)
	ls.Insert(3,2.71828)
	ls.Insert(3,2.71828)
	ls.Insert(3,2.71828)
	ls.Insert(0,1.414)
	ls.Insert(9,0.618)
	ls.Display()
	fmt.Printf("ls.Length() =%d\n",ls.Length())
	
	ls.Remove(2.71828)
	ls.Display()
	fmt.Printf("ls.Length() =%d\n",ls.Length())
	
	num := ls.At(2)
	fmt.Fprintf(os.Stdout,"ls.At(2) =%f ,ls.At(5) =%f\n",num,ls.At(5))
	
	var flag = ls.Contains(2.71828)
	fmt.Fprintf(os.Stdout,"ls.Contains(2.71828) =%t ,ls.Contains(1.414) =%t\n",flag,ls.Contains(1.414))
	
	var index int = ls.Find(1.414)
	fmt.Printf("ls.Find(1.414) =%d ,ls.Find(3.1415) =%d\n",index,ls.Find(3.1415))
	
	ls.Change(1,10.55)
	ls.Change(6,20.55)
	ls.Display()
}
