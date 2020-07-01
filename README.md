# cpp-algorithm-practice
108-2自主學習成果

<p>
我雖大部分僅實作並理解本書之排列演算法(共八個，分別為bubble sort、selection sort、insert sort、shell sort、quicksort、merge sort、radix sort、heap sort)，但我將自己實作之heap sort、quicksort、merge sort、bubble sort放在同一.cpp檔，利用亂數生成隨機陣列(一次生成4個長度皆為10000，每個欄位之值在[0,10000])，再用<ctime>函示庫中的測量它們的執行時間(根據網路資料，clock()函數可以獲得自系統啟動以來經過的時鐘滴答數)，以驗證它們的時間複雜度(time complexity)。
</p>
<p>實際編譯並執行後，其輸出如下:
<ol>
<li> quick sort ->約0.065秒
<li> bubble sort ->約0.319秒
<li> merge sort -約0.001秒
<li> heap sort ->約0.002秒
</ol>
</p>
<p>
而根據本書，除了bubble sort之時間複雜度為O(n^2)外，其餘3個皆為O(n*logn)，但由結果可知，雖bubble sort之運行時間明顯久於其他3個排序演算法，但為何quick sort之運行時間較merge sort、heap sort久?不是皆O(n*longn)嗎?
</p>
<p>
我的猜測為：quicksort是先選取陣列中的一個值(程式中以陣列第一個元素作為鍵值)，再將陣列元素與其比較後分為2部分進行quicksort，但由於程式中之陣列為亂數生成，故第一個元素經常為極大值或極小值，而非此排序方法中理想之中間值(陣列中位數)，導致程式將陣列二分時經常分成2個元素數量懸殊2邊，使程式無法發揮分治法之精神。
上述推測可由本書中提到之「快速排時的最壞時間複雜度為O(n^2)，而合併排序、堆積(樹)排序的時間複雜度每次皆為O(n*logn)」所印證。
透過實際測量執行時間，我終於對於時間複雜度一詞有具體了解，而非只是抽象概念！
</p>
<p>
另外，為了上傳程式檔，我也自行自網路學習如何在終端機中將專案納入git版本控制系統並push至github，令我管理程式專案之能力大幅提升，希望對未來之學習計畫或課堂作業有所幫助！
</p>
