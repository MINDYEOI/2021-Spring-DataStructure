# 2020-2 Midterm
1. Validation과 Verification의 차이, software life cycle에서 문제를 분석하고 명세서를 작성하는 작업에 업무에 대한 이해도와 software 개발에 대한 이해도 높은 사람을 투입해야 하는 이유를 설명하라.
-	Vilification(검사)는 명세서로 프로그램이 동작하는 지를 확인하는 것이고 validation(검증)은 명세서대로 구현된 시스템이 구상한대로 실제 문제를 해결할 수 있는 지를 확인하는 것임. 
-	명세서는 시스템의 성공여부를 결정하고 개발비용 산정의 근거가 됨.
-	따라서 명세서는 문제를 정확하게 분석하고 문제해결을 위해서 꼭 필요한 기능들을 소프트웨어 개발자가 정확하게 이해할 수 있도록 작성되어야 함
-	이를 위해서 업무를 정확하게 이해하고 소프트웨어 개발자의 언어를 구사할 수 있는 사람이 필요함 
* * *
2. Queue는 FIFO구조를 갖는다. 그러나 경우에 따라서는 큐의 특성과 list의 특성을 동시에 갖춘 자료구조가 필요할 때가 있다.  Queue의 본래 기능에 불필요한 기록을 찾아서 삭제하는 list의 Delete() 기능이 추가된 새로운 자료구조를 구현하고자 한다. 이 새로운 queue는 배열과 linked structure를 이용하여 구현할 수 있다. 두 방법 중 최적의 방법을 제시하고 그 이유를 설명하라.
-	Linked Structure를 이용하여 구현하는 것이 유리
  - Enqueue와 Dequeue는 두 방법이 비슷한 난이도를 갖지만, 
  -	메모리를 효율적으로 사용할 수 있고
  -	자료의 추가/삭제 시 shift operation이 필요 없어 상대적으로 빠름. 
* * *
3. 동적으로 할당된 배열을 이용하여 구현된 stack class의 객체를 copy constructor 재정의 없이 pass by value로 함수에 전달했을 때 actual parameter stack에 미치는 영향은 상황별로 다를 수 있다. 가능한 상황별로 actual parameter stack에 미치는 영향을 설명하라. 
  -	함수 안에서 push와 pop이 함께 일어나면 actual parameter stack이 변경되어 return됨.
  -	함수 안에서 Push나 Pop중 한가지만 일어나면 actual stack은 영향을 받지 않음
  * * *

# 2020-1 Midterm
1.	ADT 설계의 장점을 2가지 이상 제시하라.
* 구현과 무관하게 응용 프로그램을 짤 수 있다. (구현이 바뀌어도 응용 프로그램의 수정이 필요 없다.)
-  큰 프로그램을 작성할 때 ADT를 작성하면 ADT를 통해 업무의 분배가 가능하다.
-  시스템 흐름을 쉽게 파악할 수 있다.

* * *
2. N개의 자료를 처리하는 알고리즘을 수식으로 표현하면 아래와 같다. 이 알고리즘의 복잡도를 Big-O 표기법으로 표현하라. sum(k=0 to n)는 for-loop과 동일하게 취급한다. <br>
![image](https://user-images.githubusercontent.com/71140885/116046484-157d8500-a6ae-11eb-8b7f-b05ffa4ddec2.png)
* F(N) = 0.2N*logN*10000+N*9999+N*0.01N+9999 = O(N^2)
