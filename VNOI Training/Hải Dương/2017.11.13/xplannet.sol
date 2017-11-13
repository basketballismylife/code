XPLANNET
Có n góc tường mô tả ma trận a(i, j) = 1 / 0 (góc tường i có chung đường vào góc j)

b[1], b[2], ..., b[n] là bật / tắt của n bóng
Bật ít nhất để n bóng đều sáng.

Gọi x[i] là số lần bật tắt công tắc góc i => x[i] = 0/1
Số lần thay đổi trạng thái của bóng i
=>
a(i, 1) * x1 + a(i, 2) * x2 + ... + a(i, n) * xn =  (1 - b(i)) % 2
=> ta có được 1 hệ phương trình => dùng khử gauss để tính