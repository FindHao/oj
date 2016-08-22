## 星期四, 11. 八月 2016 04:02下午 
problem：
1 棋盘问题 http://noi.openjudge.cn/ch0205/323/ 
同poj http://poj.org/problem?id=1321

tag： dfs 深度搜索
note：
同一行列只能放一个，那么探索每行放不放即可。针对dfs模板
目标状态是放的棋子数==k
扩展方法比较复杂，需要考虑不放，和放两种状态，

poj 1979 红与黑 openjudge 1818
tag: bfs

## 星期一, 22. 八月 2016 02:09下午 
http://noi.openjudge.cn/ch0205/4980/ **
拯救棋盘行动
变形bfs。地图中增加了x守卫这样一种类型，守卫点需要花两个时间才能走过。在bfs模板的基础上，修改的地方是，队首元素出队列以后，判断是否是x点，如果是，本轮就只增加当前这个点的cost，形成新的状态并入队，不进行方向扩展。
http://noi.openjudge.cn/ch0205/6266/ * 6266:取石子游戏 递归。状态扩展只有一种方式。
http://poj.org/problem?id=1611 * 并查集
最基础的并查集入门。