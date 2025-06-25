!!! warning "声明 :loudspeaker:"
    &emsp;&emsp;本课程资料仅限哈尔滨工业大学（深圳）《计算机设计与实践》2025夏季课程使用，严禁扩散或用作其他用途。



# 课程概况

&emsp;&emsp;本实验文档为哈尔滨工业大学（深圳）《计算机设计与实践》课程实验指导材料。页面顶端为实验的指导书，页面左侧为指导书的各个小节目录，右侧为小节内的索引，页面右上角可详细搜索，页面下方可切换上下小节。请务必按顺序阅读指导书，有问题积极在群内提出。

!!! info "提示 :mega:"
    &emsp;&emsp;在开始之前，请回顾《数字逻辑设计》、《计算机组成原理》课程的相关理论和实践的知识、技能。

&emsp;&emsp;

## 相关链接

<!-- - ==线上答疑平台==：<a href="https://piazza.com/hitsz/summer2023/comp2012" target="_blank">Piazza/COMP2012</a>（访问码：`comp2012`） -->

- ==<a href="http://10.249.14.10:2012/" target="_blank">**点击下载课程材料**</a>==

- 在线答疑文档：

<embed src = "https://docs.qq.com/doc/DZHNIeWxpQVp2UmZ1?is_no_hook_redirect=1" width="100%" height="600">



## 各班级课表

- 少部分同学若课表存在冲突，请自行根据以下课表挑选合适的时间上课。

- ^^换时间上课请提前告知相关任课老师，否则可能被误当成缺课^^。

- ^^各班人数均接近实验室最大容量^^，**非必要请勿换班上课！自习的请自觉在其他班上课前离开！** 否则座位可能不够！

<center>课表A（地点：T2507，授课教师：江仲鸣）</center>
<center>
 <table>
  <tr>
   <th align="center">周次</th>
   <th align="center" colspan="4">课表</th>
  </tr>
  <tr>
   <td align="center">第1周</td>
   <td align="center">周一 5-6节</td>
   <td align="center">周二 5-6节</td>
   <td align="center">周三 5-8节</td>
   <td align="center">周五 1-4节</td>
  </tr>
  <tr>
   <td align="center">第2周</td>
   <td align="center">周二 5-8节</td>
   <td align="center">周四 5-8节</td>
   <td align="center">周五 5-8节</td>
  </tr>
  <tr>
   <td align="center">第3周</td>
   <td align="center">周一 5-8节</td>
   <td align="center">周三 5-8节</td>
   <td align="center">周五 1-4节</td>
  </tr>
  <tr>
   <td align="center">第4周</td>
   <td align="center">周一 1-4节</td>
   <td align="center">周二 5-8节</td>
   <td align="center">周四 5-8节</td>
  </tr>
 </table>
</center>

<center>课表B（地点：T2507，授课教师：江仲鸣）</center>
<center>
 <table>
  <tr>
   <th align="center">周次</th>
   <th align="center" colspan="4">课表</th>
  </tr>
  <tr>
   <td align="center">第1周</td>
   <td align="center">周一 7-8节</td>
   <td align="center">周二 7-8节</td>
   <td align="center">周四 5-8节</td>
   <td align="center">周五 5-8节</td>
  </tr>
  <tr>
   <td align="center">第2周</td>
   <td align="center">周一 5-8节</td>
   <td align="center">周三 5-8节</td>
   <td align="center">周五 1-4节</td>
  </tr>
  <tr>
   <td align="center">第3周</td>
   <td align="center">周二 5-8节</td>
   <td align="center">周四 5-8节</td>
   <td align="center">周五 5-8节</td>
  </tr>
  <tr>
   <td align="center">第4周</td>
   <td align="center">周一 5-8节</td>
   <td align="center">周三 1-4节</td>
   <td align="center">周五 1-4节</td>
  </tr>
 </table>
</center>

<center>课表C（地点：T2210，授课教师：郑海刚）</center>
<center>
 <table>
  <tr>
   <th align="center">周次</th>
   <th align="center" colspan="4">课表</th>
  </tr>
  <tr>
   <td align="center">第1周</td>
   <td align="center">周一 3-4节</td>
   <td align="center">周二 5-6节</td>
   <td align="center">周三 5-8节</td>
   <td align="center">周五 1-4节</td>
  </tr>
  <tr>
   <td align="center">第2周</td>
   <td align="center">周二 5-8节</td>
   <td align="center">周四 5-8节</td>
   <td align="center">周五 5-8节</td>
  </tr>
  <tr>
   <td align="center">第3周</td>
   <td align="center">周一 5-8节</td>
   <td align="center">周三 5-8节</td>
   <td align="center">周五 1-4节</td>
  </tr>
  <tr>
   <td align="center">第4周</td>
   <td align="center">周一 1-4节</td>
   <td align="center">周二 5-8节</td>
   <td align="center">周四 5-8节</td>
  </tr>
 </table>
</center>

<center>课表D（地点：T2210，授课教师：郑海刚）</center>
<center>
 <table>
  <tr>
   <th align="center">周次</th>
   <th align="center" colspan="4">课表</th>
  </tr>
  <tr>
   <td align="center">第1周</td>
   <td align="center">周一 7-8节</td>
   <td align="center">周二 7-8节</td>
   <td align="center">周四 5-8节</td>
   <td align="center">周五 5-8节</td>
  </tr>
  <tr>
   <td align="center">第2周</td>
   <td align="center">周一 5-8节</td>
   <td align="center">周三 5-8节</td>
   <td align="center">周五 1-4节</td>
  </tr>
  <tr>
   <td align="center">第3周</td>
   <td align="center">周二 5-8节</td>
   <td align="center">周四 5-8节</td>
   <td align="center">周五 5-8节</td>
  </tr>
  <tr>
   <td align="center">第4周</td>
   <td align="center">周一 5-8节</td>
   <td align="center">周三 1-4节</td>
   <td align="center">周三 5-8节</td>
  </tr>
 </table>
</center>

<center>课表E（地点：T2612，授课教师：薛睿）</center>
<center>
 <table>
  <tr>
   <th align="center">周次</th>
   <th align="center" colspan="4">课表</th>
  </tr>
  <tr>
   <td align="center">第1周</td>
   <td align="center">周一 5-6节</td>
   <td align="center">周二 5-6节</td>
   <td align="center">周三 5-8节</td>
   <td align="center">周五 1-4节</td>
  </tr>
  <tr>
   <td align="center">第2周</td>
   <td align="center">周二 5-8节</td>
   <td align="center">周四 5-8节</td>
   <td align="center">周五 5-8节</td>
  </tr>
  <tr>
   <td align="center">第3周</td>
   <td align="center">周一 5-8节</td>
   <td align="center">周三 5-8节</td>
   <td align="center">周五 1-4节</td>
  </tr>
  <tr>
   <td align="center">第4周</td>
   <td align="center">周一 1-4节</td>
   <td align="center">周二 5-8节</td>
   <td align="center">周四 5-8节</td>
  </tr>
 </table>
</center>

<center>课表F（地点：T2612，授课教师：薛睿）</center>
<center>
 <table>
  <tr>
   <th align="center">周次</th>
   <th align="center" colspan="4">课表</th>
  </tr>
  <tr>
   <td align="center">第1周</td>
   <td align="center">周一 7-8节</td>
   <td align="center">周二 7-8节</td>
   <td align="center">周四 5-8节</td>
   <td align="center">周五 5-8节</td>
  </tr>
  <tr>
   <td align="center">第2周</td>
   <td align="center">周一 5-8节</td>
   <td align="center">周三 5-8节</td>
   <td align="center">周五 1-4节</td>
  </tr>
  <tr>
   <td align="center">第3周</td>
   <td align="center">周二 5-8节</td>
   <td align="center">周四 5-8节</td>
   <td align="center">周五 5-8节</td>
  </tr>
  <tr>
   <td align="center">第4周</td>
   <td align="center">周一 5-8节</td>
   <td align="center">周二 1-4节</td>
   <td align="center">周四 1-4节</td>
  </tr>
 </table>
</center>

<center>课表G（地点：T2506，授课教师：仇洁婷）</center>
<center>
 <table>
  <tr>
   <th align="center">周次</th>
   <th align="center" colspan="4">课表</th>
  </tr>
  <tr>
   <td align="center">第1周</td>
   <td align="center">周一 5-6节</td>
   <td align="center">周二 5-6节</td>
   <td align="center">周三 5-8节</td>
   <td align="center">周五 5-8节</td>
  </tr>
  <tr>
   <td align="center">第2周</td>
   <td align="center">周一 1-4节</td>
   <td align="center">周二 5-8节</td>
   <td align="center">周三 1-4节</td>
  </tr>
  <tr>
   <td align="center">第3周</td>
   <td align="center">周一 5-8节</td>
   <td align="center">周二 5-8节</td>
   <td align="center">周三 1-4节</td>
  </tr>
  <tr>
   <td align="center">第4周</td>
   <td align="center">周一 5-8节</td>
   <td align="center">周二 5-8节</td>
   <td align="center">周四 5-8节</td>
  </tr>
 </table>
</center>

<center>课表H（地点：T2506，授课教师：仇洁婷）</center>
<center>
 <table>
  <tr>
   <th align="center">周次</th>
   <th align="center" colspan="4">课表</th>
  </tr>
  <tr>
   <td align="center">第1周</td>
   <td align="center">周一 7-8节</td>
   <td align="center">周二 7-8节</td>
   <td align="center">周四 5-8节</td>
   <td align="center">周五 1-4节</td>
  </tr>
  <tr>
   <td align="center">第2周</td>
   <td align="center">周一 5-8节</td>
   <td align="center">周三 5-8节</td>
   <td align="center">周五 1-4节</td>
  </tr>
  <tr>
   <td align="center">第3周</td>
   <td align="center">周一 1-4节</td>
   <td align="center">周三 5-8节</td>
   <td align="center">周五 1-4节</td>
  </tr>
  <tr>
   <td align="center">第4周</td>
   <td align="center">周二 1-4节</td>
   <td align="center">周三 5-8节</td>
   <td align="center">周四 1-4节</td>
  </tr>
 </table>
</center>



!!! abstract "致谢 :rose:"
    - 特别鸣谢17级胡博涵、18级黎庚祉、19级罗尹同学在Trace测试框架上做出的贡献。

    - 特别鸣谢19级罗翊洲同学在LA32R汇编工具上做出的贡献。
