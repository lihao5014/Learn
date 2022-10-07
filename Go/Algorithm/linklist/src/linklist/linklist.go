package linklist

import "os"
import "fmt"
import "math"

const Accuracy float64 = 0.000001

type node struct{
	data float64
	next *node
}

type LinkList struct{
	length int
	head node
}

func CreateLinkList() *LinkList{
	return new(LinkList)            //Go语言中数值类型的默认值为0，指针类型的默认值为nil
}

func (ls *LinkList)IsNull() bool{
	if ls == nil {
		return true
	}
	return false
}

func (ls *LinkList)IsEmpty() bool{
	if ls == nil || ls.head.next == nil {
		return true
	}
	
	return false
}

func (ls *LinkList)Length() int{
	if ls == nil {
		return -1
	}
	
	return ls.length
}

func (ls *LinkList)Append(value float64){
	if ls == nil {
		fmt.Println("Append() error: ls is nil")
		return
	}
	
	p := &ls.head
	for p.next != nil {
		p = p.next
	}
	
	var newNode *node = new(node)
	newNode.data = value
	newNode.next = nil                 //可以不用手动赋值，Go语言中指针类型的默认值为nil
	
	ls.length += 1
	p.next = newNode
}

func (ls *LinkList)Prepend(value float64){
	if ls == nil {
		fmt.Println("Prepend() error: ls is nil")
		return
	}
	
	var newNode *node = new(node)
	newNode.data = value
	newNode.next = ls.head.next
	
	ls.length += 1
	ls.head.next = newNode
}

func (ls *LinkList)PopFront(){
	if ls.IsEmpty() {
		return
	}
	
	var p = ls.head.next
	if p != nil {
		ls.head.next = p.next
	}
	
	ls.length--
}

func (ls *LinkList)PopBack(){
	if ls.IsEmpty() {
		return
	}
	
	p := &(ls.head)
	for p.next.next != nil {
		p = p.next
	}
	
	p.next = nil
	ls.length--
}

func (ls *LinkList)Insert(pos int,value float64){
	if ls == nil || pos < 0 || pos > ls.length {
		fmt.Println("Insert() error: ls is nil or pos is illegal")
		return
	}
	
	var p *node = &ls.head
	for ;pos > 0;pos--{
		p = p.next
	}
	
	newNode := new(node)
	newNode.data = value
	newNode.next = p.next
	
	p.next = newNode
	ls.length++
}

func (ls *LinkList)Remove(value float64){
	if ls.IsEmpty() {
		return
	}
	
	var p = &ls.head
	for p.next != nil {
		if math.Abs(p.next.data - value) < Accuracy {
			p.next = p.next.next
			ls.length--
		} else {
			p = p.next
		}
	}
}

func (ls *LinkList)At(index int) float64{
	if ls.IsEmpty() || index < 0 || index >= ls.length {
		fmt.Println("At() error: ls is empty or index is illegal")
		os.Exit(-1)
	}
	
	var p *node = ls.head.next
	for ;index > 0;index-- {
		p = p.next
	}
	
	return p.data
}

func (ls *LinkList)Contains(value float64) bool{
	if ls.IsEmpty() {
		return false
	}
	
	p := ls.head.next
	for p != nil {
		if math.Abs(p.data - value) < Accuracy {
			return true
		}
		p = p.next
	}
	
	return false
}

func (ls *LinkList)Find(value float64) int{
	if ls.IsEmpty() {
		return -1
	}
	
	p := ls.head.next
	for index := 0 ; p != nil ; index++ {
		if math.Abs(p.data - value) < Accuracy {
			return index
		}
		p = p.next
	}
	
	return -1
}

func (ls *LinkList)Change(index int,value float64){
	if ls.IsEmpty() || index < 0 || index >= ls.length {
		fmt.Println("Change() error: ls is empty or index is illegal")
		return
	}
	
	p := ls.head.next
	for ;index > 0;index-- {
		p = p.next
	}
	
	p.data = value
}

func (ls *LinkList)Display(){
	var p *node = ls.head.next
	for p != nil {
		fmt.Printf("%f ",p.data)
		p = p.next
	}
	fmt.Println("")
}