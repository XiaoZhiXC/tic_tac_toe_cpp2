# 井字棋游戏项目说明

## 实现功能&特色

1，游戏菜单，游戏AI难度选择，先手选择，游戏结束菜单

2，C++协同蓝图开发，C++实现了一些复杂的算法函数比如最大最小搜索，棋局状态检测等等，蓝图实现了基本的游戏规则，UI等等

3，实现了背景图片的切换，菜单Bgm，游戏Bgm，棋子选择音效，胜利和失败的音效

## AI难度

![Snipaste_2024-04-12_20-36-50](https://github.com/XiaoZhiXC/tic_tac_toe_cpp2/assets/45706293/c9e36dcc-e153-49e2-a06d-2f4f1f4420d9)

派蒙：随机下棋  

获胜：随便下

可莉：往下看一步，即搜索深度为1

获胜：先手，右边三格从上往下依次下

![Snipaste_2024-04-12_20-42-26](https://github.com/XiaoZhiXC/tic_tac_toe_cpp2/assets/45706293/fb880697-c003-4902-a589-d3bf3d6f32a9)

芭芭拉：往下看两步

获胜：先手，三角杀

![Snipaste_2024-04-12_20-42-35](https://github.com/XiaoZhiXC/tic_tac_toe_cpp2/assets/45706293/c6085aa5-f808-4e53-b744-4f709f83ddd8)

纳西妲：计算所有的情况，搜索深度为当前空余格子数

获胜：无法战胜，最多平局

散兵：在你出手前随机下棋，直到他获胜

获胜：点开就是输

## C++函数讲解

1，游戏胜利判断函数

![Snipaste_2024-04-11_22-38-34](https://github.com/XiaoZhiXC/tic_tac_toe_cpp2/assets/45706293/96fe5038-119c-428b-9f47-57d7f1af8552)

2，棋局估值函数，用于最大最小搜索函数递归的最后深度的棋局估值

![Snipaste_2024-04-11_22-38-47](https://github.com/XiaoZhiXC/tic_tac_toe_cpp2/assets/45706293/561e964f-066d-45bb-adfa-82c49ccbea18)

3，获取可移动格子，并保存在FMove结构体数组中

![Snipaste_2024-04-11_22-38-59](https://github.com/XiaoZhiXC/tic_tac_toe_cpp2/assets/45706293/3f5870a5-4c7b-41c5-b501-b9165ce1e5ce)

4，最大最小搜索函数，输入为搜索深度Depth，用于调控AI难度

![Snipaste_2024-04-11_22-39-09](https://github.com/XiaoZhiXC/tic_tac_toe_cpp2/assets/45706293/d5b1d78d-3871-4710-a7e9-2fb435004b39)

5，获取AI移动棋子，输入为保存棋盘状态的三维向量数组（因为UE蓝图不支持多维数组，所以用三个三维向量表示），输出为FMove，一个有两个整型参数的结构体，为电脑AI下棋的坐标

![Snipaste_2024-04-11_22-39-22](https://github.com/XiaoZhiXC/tic_tac_toe_cpp2/assets/45706293/f0b89b89-ba32-47c8-b0ba-58b7ff0c6608)

6，更新棋盘

![Snipaste_2024-04-11_22-39-35](https://github.com/XiaoZhiXC/tic_tac_toe_cpp2/assets/45706293/1617bcd9-d7cd-4440-8ef1-80b29f82c4e1)

7，判断游戏是否结束

![Snipaste_2024-04-11_22-39-44](https://github.com/XiaoZhiXC/tic_tac_toe_cpp2/assets/45706293/0edce169-0034-4857-833a-50dc77f85afe)
