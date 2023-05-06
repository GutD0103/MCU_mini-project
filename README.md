Trong project giữa kì này, một hệ thống đếm lùi sẽ được hiện thực trên phần mềm mô phỏng Proteus.
Như được trình bày ở hình dưới, các thành phần chính của hệ thống bao gồm vi điều khiển STM32F103C6, một đèn LED, một LED 7 đoạn và 3 nút nhấn đơn.
![image](https://user-images.githubusercontent.com/96888431/236594654-71778311-8314-4baf-8f25-f3facee4f02e.png)
Một số tính năng chính của hệ thống được trình bày như sau:
- LED 7 đoạn dùng để hiển thị giá trị của counter, có giá trị từ 0 đến 9.
- Nút RESET được dùng để reset giá trị của counter về 0. Trong khi đó, nút nhấn INC và DEC được dùng để tăng hoặc giảm giá trị của counter. Có 2 sự
kiện cần phải xử lý cho các nút nhấn, là nhấn thường và nhấn giữa.
Trong dự án này, một nút nhấn được coi là nhấn giữ, nếu nó giữ nguyên trạng thái đó trong 3 giây liên tiếp.
- Đèn LED D1 được dùng để theo dõi hoạt động của hệ thống, nó sẽ luân phiên
chớp tắt mỗi giây.
Link video demo: https://drive.google.com/file/d/1a-LBAfdF1Pr5F7py8kANA1nPoc8uPTqa/view?usp=sharing
