package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
	"sort"
)

func CF652D(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var n int
	Fscan(in, &n)

	ps := make([]struct {v, i int}, n * 2)
	for i := range ps {
		Fscan(in, &ps[i].v)
		ps[i].i = i
	}

	sort.Slice(ps, func(i, j int) bool {
		return ps[i].v < ps[j].v
	})
	
	// 离散化输入的区间端点
	kth := make([]int, n * 2)
	for i, p := range ps {
		kth[p.i] = i + 1
	}

	type pair struct {
		l, r, i int
	}
	a := make([]pair, n)

	// a[i] 放的就是按照输入顺序的第 i 个区间
	for i := range a {
		a[i] = pair{kth[i * 2], kth[i * 2 + 1], i}
	}
	// 按照区间右端点排序
	sort.Slice(a, func(i, j int) bool {
		return a[i].r < a[j].r
	})
	
	ans := make([]int, n)
	tree := make([]int, n * 2 + 1)
	// 按照右端点排序后 第一个区间右端点最小
	for i, p := range a {
		// c = 在它前面的区间数量
		c := i
		// 去掉那些左端点在范围之外的
		for i := p.l; i > 0; i &= (i - 1) {
			c -= tree[i]
		}
		ans[p.i] = c
		// 更新区间到bit
		for i := p.l; i <= n * 2; i += (i & -i) {
			tree[i]++
		}
	}

	for _, v := range ans {
		Fprintln(out, v)
	}
}

func main() { CF652D(os.Stdin, os.Stdout) }