# <center> SOLUTION GAMESHOW </center>

 - Quy hoạch động: $f(i, j)$ là chi phí ít nhất để đi từ $1 -> i$ và đi qua $j$ cửa.
   * $f(i, j) = f(i - 1, j) - T$ nếu không đi qua cửa $i$.
   * $f(i, j) = f(i - 1, j - 1) + A(i)$ nếu đi qua cửa $i$.