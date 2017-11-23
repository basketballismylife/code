# <center> SOLUTION QUEUE <\center>

 ### Giải bài toán đơn giản: *Cho $N$ điểm $(x_1, y_1), (x_2, y_2), ..., (x_n, y_n)$ tính năng lượng tiêu thụ ít nhất để xếp $n$ điểm thành 1 đường thẳng song song với trục hoành*.
 
 - Nhận xét: 
   * $x, y$ tách biệt không ảnh hưởng lẫn nhau. * Dòng mà $n$ điểm di chuyển tới có phương trình $y = v$ với $v$ là trung vị của $y_1, y_2, ..., y_n$. 
   * Cần tìm cột $p$ để xếp $n$ điểm vào : $p, p + 1, p + 2, ..., p + n$. 
   * Giả sử $x_1 \le x_2 \le x_3 \le ... \le x_n$. Chi phí tối thiểu để xếp thành hàng ngang là : 
   $|x_1 - p| + |x_2 - p - 1| + |x_3 - p - 2| + ... + |x_n - p - (n - 1)|$
   $<=> |x_1 - p| + |x_2 - 1 - p| + |x_3 - 2 - p| + ... + |x_n - (n - 1) - p|$
   $<=> $p$ là trung vị của $x_1, x_2 - 1, ..., x_n - (n - 1)$.

### Quay lại bài toán:
 - Giả sử ta cần xếp $n$ điểm vào hình $r * c$. Làm tương tự như bài toán ở trên để tìm điểm $(p, q)$ là góc trái dưới của hình chữ nhật.