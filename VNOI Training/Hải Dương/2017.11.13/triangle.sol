TRIANGLE
Cho n điểm và điểm P trên mặt phẳng. Đếm xem có bao nhiêu tam giác chưa điểm P.

Thuật toán: đếm số tam giác không chứa P.

B1: Với A1, A2, ..., An
Sắp xếp các góc tăng dần. 

B2: for  = 1 -> n {
	- Đếm xem có bao nhiêu góc > delta i, <= delta i + pi => k.
	=> Số cách chọn là C(k, 2);
}

B3: đáp số là C(n, 3) - tổng.