# Hướng dẫn ICPC 2021 Miền Trung (Khuyến khích các bạn đọc đề và hiểu rõ chúng)

## Link
*[Đề trên google drive](https://drive.google.com/drive/folders/1VNTlFeD6VBEb2JIwNzEntjIBU6_EBA9W)
*[Nơi submit](https://oj.vnoi.info/contest/icpc21_mt)

### Sol A

### Sol B 
#### tag : implementation 
* Đây là 1 bài dễ , bởi vì chỉ cần áp dụng if else bình thường cũng AC được nó
* Bởi vì bài yêu cầu mod cho 1e9(tương đương 10^9) nên bạn có thể giải quyết nhanh bằng [C++](https://vi.wikipedia.org/wiki/C%2B%2B)
* Để bạn rõ hơn , mình sẽ gợi ý như sau : để cho 1 mảng có giá trị tích là lớn nhất , thì
bạn có những hướng như sau :
	* Loại bỏ 1 số 0 (TH1)
	* Loại bỏ 1 số âm lớn nhất (TH2)
	* Không loại bỏ gì cả (TH3) 
* Đáp số cuối cùng sẽ là:
	* MAX(TH1 , TH2 , TH3)
* [https://github.com/tryCod3/SOL_ICPC/Code/B.cpp] (#CodeAC)