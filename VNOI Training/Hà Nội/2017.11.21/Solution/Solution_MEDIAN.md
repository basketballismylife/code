# <center> SOLUTION MEDIAN </center>

 - Ta chặt nhị phân kết quả, xét số $x$, ta tính $c(i, j)$ = -1 nếu $A(i, j) <= x$ ngược lại bằng 1. Dùng mảng cộng dồn với bảng $c$. bảng con có trung vị bé hơn $x$ nếu tổng của bảng con đó $\le 0$.