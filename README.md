

# GoodByeJiokcheol - 지하철 승객 몰림 방지 시스템

# 프로젝트 개요

![logo](https://user-images.githubusercontent.com/63458653/88040826-70fd6e00-cb84-11ea-81a5-f29261b813df.PNG)

현재 지하철은 일부 칸이 비어 있음에도 다른 칸은 사람들로 가득 차 있는 
비효율적인 경우가 발생한다.<br>이로 인해, 많은 사람들이 편하게 목적지로 
이동할 수 있음에도 불구하고 가득 찬 칸을 이용하며 불편함을 겪는다. <br><br>
본 프로젝트에서는 사용자가 타려는 지하철 각 칸의 붐빔 정도를 측정하고
이를 LED 전광판으로 표시하는 장치와 HTML 웹페이지를 개발했다.<br><br>사람들이 지하철을 기다리면서 여유로운 칸을 미리 알고 기다리며 
붐비는 칸으로 사람이 더 몰리지 않게 하는 데 목적이 있다.
<br><br>
- 서비스: 지하철 승객 몰림 방지 시스템
- 개발 환경: Arduino 1.8.3
- 개발 언어: C++
- 관련 기술: Wifi, Webserver, HTML, TCP/IP, HTTP
<br>
<sup>본 프로젝트는 스마트 도시를 만들기 위한 아이디어로 시연을 목적에 두고 제작되었습니다.</sup>


# System
## 혼잡도 측정 센서
![image](https://user-images.githubusercontent.com/63458653/88042138-6cd25000-cb86-11ea-8e64-28755c343864.png)![image](https://user-images.githubusercontent.com/63458653/88047086-06e8c700-cb8c-11ea-82f8-3d05a544b0eb.png)

HC-SR04
- 초음파 센서로 승객들의 밀도를 측정한다.<br>

YZC-131
- 무게 센서로 승객들의 중량을 측정한다.

 두가지 센서로 조건 연산과 논리 연산으로 지하철의 혼잡도를 계산한다.
 <br><br>
## 와이파이 센서
![image](https://user-images.githubusercontent.com/63458653/88048361-254fc200-cb8e-11ea-90c6-945c957affc7.png)

ESP-8266
- 와이파이 네트워크와 연결
- Wizfi250 라이브러리를 이용해 TCP를 통해 웹서버와 연결 후 HTTP명령으로 HTML 웹페이지 제작
- 측정 센서에서 얻은 혼잡도 값을 실시간으로 웹페이지에서 시각적으로 보여줌 
<br>
<br>

# 구현

![1](https://user-images.githubusercontent.com/63458653/88051230-3f3fd380-cb93-11ea-8166-151845ea4e68.PNG)
![2](https://user-images.githubusercontent.com/63458653/88051238-41099700-cb93-11ea-916c-8f7f589f81f3.PNG)
![3](https://user-images.githubusercontent.com/63458653/88051246-423ac400-cb93-11ea-9814-27cd189280bb.PNG)
![4](https://user-images.githubusercontent.com/63458653/88051250-436bf100-cb93-11ea-90a8-f57cf8d9a533.PNG)

- 지하철의 각 호차, 각 칸 별로 승객 밀도와 중량을 측정해서 혼잡도를 계산
- 실시간으로 각 호차, 칸 별 혼잡도를 웹페이지와 LED 전광판을 통해 보여준다. 

<br><br>

