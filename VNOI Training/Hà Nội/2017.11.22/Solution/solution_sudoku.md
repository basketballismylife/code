# <center> SOLUTION SUDOKU </center>

## Note: Đây là bài thi thử IOI 2017, không có solution. Thuật toán dưới đây chỉ ăn được gần hết các test.

### Thuật toán:
 - Ta giải bài toán này bằng luồng cực đại với từng bảng con (giải từ bảng con có nhiều dữ liệu nhất đến bảng con có ít dữ liệu nhất). Với mỗi bảng con, coi các số $1 -> 9$, các cạnh, dòng, là các đỉnh và 2 đỉnh ảo source(đỉnh phát), sink(đỉnh thu) đến xây dựng đồ thị nối source(đỉnh phát đến các số $1 ... 9$, giữa các số $1 ... 9$ đến hàng, hàng đến cột, từ cột đến đỉnh thu(sink).
 - Tìm luồng cực đại và truy vết.
 - Có thể giải bằng cặp ghép.