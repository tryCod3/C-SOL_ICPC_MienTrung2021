# Hướng dẫn ICPC 2021 Miền Trung (Khuyến khích các bạn đọc đề và hiểu rõ chúng)

## Link
* [Đề trên google drive](https://drive.google.com/drive/folders/1VNTlFeD6VBEb2JIwNzEntjIBU6_EBA9W)
* [Nơi submit](https://oj.vnoi.info/contest/icpc21_mt)


### Sol B 
#### tag : implementation 
* Đây là 1 bài dễ , bởi vì chỉ cần áp dụng if else bình thường cũng AC được nó
* Bởi vì bài yêu cầu mod cho [1e9+7](https://www.google.com/search?q=1e9%2B7&oq=&aqs=chrome.1.69i57j6.3548j0j7&sourceid=chrome&ie=UTF-8) nên bạn có thể giải quyết nhanh bằng [C++](https://vi.wikipedia.org/wiki/C%2B%2B)
* Để bạn rõ hơn , mình sẽ gợi ý như sau : để cho 1 mảng có giá trị tích là lớn nhất , thì
bạn có những hướng như sau :
	* Loại bỏ 1 số 0 (TH1)
	* Loại bỏ 1 số âm lớn nhất (TH2)
	* Không loại bỏ gì cả (TH3) 
* Đáp số cuối cùng sẽ là:
	* MAX(TH1 , TH2 , TH3)
* [Code AC bằng C++](https://github.com/tryCod3/SOL_ICPC/blob/master/Code/B.cpp)

### Sol G
#### tag : PrefixSum , SegmentTree
* Đây là dạng bài cổ điển trong những bài truy vấn phân đoạn
	* tăng đoạn [l , r] lên k đơn vị
	* sum(l , r) = ?
* Quay lại với dữ liệu đề bài cho , ta thấy không thể duyệt trâu được <img src="https://github.com/tryCod3/SOL_ICPC/blob/master/img/TLE_G.jpg">
* nếu bạn code như này bạn sẽ bị TLE
* Và nếu bạn thấy tag của bài G , đây là những thuật toán bạn sẽ cần dùng đến , chọn 1 trong 2 cách
	* Với cách 1 (PrefixSum):
		* Ý tưởng của thuật toán này sẽ tạo 1 mảng cộng dồn 
			* Ta tạo 2 test: [L , R] = K
				* với L = 2 , R = 3 , K= 10
					* prefixSum [0 , 10 , 10 , 0 , 0]
				* với L = 1 , R = 5 , K= 2	
					* prefixSum [2 , 12 , 12 , 2 , 2]
		 * Bạn thấy mảng prefixSum chính là mảng từng phần tử trong string trong bài cộng vào
		 * Mình biết khi đọc tới đây , bạn sẽ hỏi rằng vậy việc duyệt từ [l , r] rồi cộng K đơn vị
		   thì khác gì cái ảnh TLE trên kia
			* Nó khác đó , bạn sẽ dùng 1 trick , mình sẽ gợi ý như này : 
				* bạn hãy đánh dấu vị trí
				* sau khi đánh dấu vị trí sau hết cả , tới lúc này hãy cộng chúng vào 
	* [Code AC bằng C++](https://github.com/tryCod3/SOL_ICPC/blob/master/Code/G.cpp)	
	<br/>
	* Với cách 2 SegmentTree with lazy:

