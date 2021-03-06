# SolveProblems

### 코딩테스트 준비를 위한 알고리즘 문제 해결
- 업데이트 : 21.03.04(세부 로직 별 분류)
#### 코딩테스트가 목적이니 각 프로그램의 완성도보다는 주어진 시간 내에, 주어진 메모리를 가지고 통과하는데 초점을 둠
- 예시 : 스택, 힙에 잡히지 않는 전역변수를 주로 사용 

### 목차
- [알고리즘](https://github.com/KimUJin3359/Solve_Problems/blob/master/README.md#%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98)
- [BFS](https://github.com/KimUJin3359/Solve_Problems#bfs)
- [완전탐색](https://github.com/KimUJin3359/Solve_Problems/blob/master/README.md#%EC%99%84%EC%A0%84%ED%83%90%EC%83%89)
- [DFS 및 Back Tracking](https://github.com/KimUJin3359/Solve_Problems/blob/master/README.md#dfs-%EB%B0%8F-back-tracking)
- [DP](https://github.com/KimUJin3359/Solve_Problems/blob/master/README.md#dp)

---

### [알고리즘](https://github.com/KimUJin3359/Solve_Problems/tree/master/ALGORITHM)

[1. Amusement Park](https://github.com/KimUJin3359/Solve_Problems/blob/master/ALGORITHM/AmusementPark.c)
- [문제](https://www.acmicpc.net/problem/1561)
- [초안](https://github.com/KimUJin3359/Solve_Problems/blob/master/ALGORITHM/AmusementPark_First.cpp)
- N명의 아이들이 M종류의 1인승 놀이기구를 타려함
- 놀이기구에는 1번부터 M번까지 번호가 정해져있고, 각각의 운행 시간이 정해져 있음
- N번째 아이가 타게 될 놀이기구의 번호를 출력
- 접근 방법
  - Brute-Force
    - 처음에는 입력받은 배열을 가지고, 시간의 흐름에 따라 타게 되는 아이들을 다 검색해서 계산을 해줌
    - N명의 아이들이 있을 때, 최대 N * 30M번의 경우(1개의 놀이기구만 30분을 간격으로 운영)를 봐줘야 할 경우가 될 수 있음으로 실행시간 초과 발생
  - Brute-Force
    - 입력받은 배열을 시간에 따라(1~30분) 해당 인원의 수를 계산해서 넣어줌
    - N명의 아이들이 있어도, 최대 30 * 30M번의 경우만 봐주면 됨
    - 위 계산의 결과가, 원하는 값을 초과했을 때 그 전으로 복귀해 계산
    - 많은 경우의 수를 줄였다고 생각했으나, 실행시간 초과 발생
  - Brute-Force + Binary Search
    - 위의 경우에도, 모든 시간값을 다 봐주게 된다면 최대 60000000000번을 봐줘야 되었었음
    - 이를 binary search로 시간 단축하였음

[2. Count Group(SW Expert Academy : 창용 마을 무리의 개수)](https://github.com/KimUJin3359/Solve_Problems/blob/master/ALGORITHM/CountGroup.cpp)
- [문제](https://swexpertacademy.com/main/talk/solvingClub/problemView.do?solveclubId=AXc2524K9JYDFAWs&contestProbId=AWngfZVa9XwDFAQU&probBoxId=AXf1vIAqWMkDFAUO&type=PROBLEM&problemBoxTitle=Day+16%28%EB%AC%B8%EC%A0%9C%ED%92%80%EC%9D%B41%29&problemBoxCnt=3)
- 두 사람이 서로 아는 관계이거나 몇 사람을 거쳐서 알 수 있는 관계일 경우 같은 무리라고 함
- 몇 개의 무리가 존재하는지 계산하는 프로그램
- 접근 방법
  - Disjoint-set 사용

[3. Rich Project](https://github.com/KimUJin3359/Solve_Problems/blob/master/ALGORITHM/RichProject.cpp)
- [문제](https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5LrsUaDxcDFAXc&categoryId=AV5LrsUaDxcDFAXc&categoryType=CODE)
- 원재는 연속된 N일 동안의 물건의 매매가를 예측하여 알고 있음
- 하루 최대 1개만큼 구입할 수 있음
- 판매는 언제든지 할 수 있음
- 원재가 벌 수 있는 최대이익 계산
- 접근 방법
  - max priority queue를 사용하여, 최대 값의 index와 value를 저장함
  - queue에서 top에 있는 원소를 확인하여, 현재 index 값보다 뒤에 있는 경우 top 원소의 index 까지 차익을 계산해 더해감

[4. Rolling Dice(Baekjoon : 주사위 굴리기)](https://github.com/KimUJin3359/Solve_Problems/blob/master/ALGORITHM/RollingDice.cpp)
- [문제](https://www.acmicpc.net/problem/14499)
- 주사위를 굴림
- 동, 서, 남, 북 방향에 따라 주사위도 회전함
- 주사위를 옮길 때, 해당 지도의 값이 0이면 주사위 바닥면의 값이 지도의 값에 복사
- 주사위를 옮길 때, 해당 지도의 값이 0이 아니면 지도의 값이 주사위의 바닥면에 복사되고, 지도의 값은 0이 됨
- 주사위는 지도의 바깥으로 나갈 수 없음
- 접근 방법
  - 알고리즘 : 동, 서, 남, 북으로 이동할 때 해당 주사위가 바뀌는 규칙을 찾아 해당 값을 setting
  - 주사위과 동, 서, 남, 북으로 움직일 수 있기 때문에 배열을 사용해서 앞뒤를 한칸씩 밀어주는 것보다, deque를 사용한 push_front, push_back을 사용

[5. Quad Tree(알고스팟 : 쿼드트리 뒤집기)](https://github.com/KimUJin3359/Solve_Problems/blob/master/ALGORITHM/QuadTree.cpp)
- [문제](https://algospot.com/judge/problem/read/QUADTREE#)
- 쿼드 트리로 압축된 흑백 그림이 주어졌을 때, 이 그림을 상하로 뒤집은 그림을 쿼드트리 압축해서 출력하는 프로그램
- 접근 방법
  - 쿼드 트리 구현
  - 출력 시 위아래 뒤집어서 출력

[6. ATM(백준 : ATM)](https://github.com/KimUJin3359/Solve_Problems/blob/master/ALGORITHM/ATM.cpp)
- [문제](https://www.acmicpc.net/problem/11399)
- 사람 수와, 돈을 인출하는데 각각 걸리는 시간이 주어짐
- 돈을 인출하는데 필요한 시간의 합의 최소값 구하기
- 접근 방법
  - priority queue 활용

[7. A To B(백준 : A -> B)](https://github.com/KimUJin3359/Solve_Problems/blob/master/ALGORITHM/AToB.cpp)
- [문제](https://www.acmicpc.net/problem/16953)
- 정수 A를 B로 바꾸려함
  - 2를 곱한다
  - 1을 수의 가장 오른쪽에 추가한다
- A를 B로 바꾸는데 필요한 연산의 최소값 구하기
- 접근 방법
  - B에서 A로 접근 ( 계산 횟수 줄이기 )
  - 2의 배수인 것과 1로 끝나는 것은 공통 부분이 없음
    - % 10 == 1 -> /= 10
    - % 2 == 0 -> /= 2
  - B가 A보다 작거나 같을 때 까지 반복, 최종 값이 A와 같지 않다면 -1 같다면 횟수 반환

[8. Zoo(백준 : 동물원)](https://github.com/KimUJin3359/Solve_Problems/blob/master/ALGORITHM/Zoo.cpp)
- [문제](https://www.acmicpc.net/problem/12907)
- 동물원에 N마리 동물(토끼/ 고양이)이 존재
- 모든 토끼는 자신보다 키가 큰 토끼의 수를 말함
- 모든 고양이는 자신보다 키가 큰 고양이의 수를 말함
- 가능한 조합의 수
- 접근 방법
  - 유효성 검사(0, 1, 2 ... 순서에 맞게 존재하는지)
  - 유효성 검사를 충족했을 때 조합의 수가 더 생길 수 있는지 판단

[9. A and B(백준 : A와 B)](https://github.com/KimUJin3359/Solve_Problems/blob/master/ALGORITHM/AandB.cpp)
- [문제](https://www.acmicpc.net/problem/12904)
- A와 B로만 이루어진 영어 단어가 존재
- 두 문자열 S와 T가 주어졌을 때, S를 T로 바꿀 수 있는지 확인
  - 문자열의 뒤에 A를 추가
  - 문자열을 뒤집고 뒤에 B를 추가
- 접근 방법
  - T에서 A로 끝나냐 B로 끝나냐에 따라 규칙을 거꾸로 적용

[10. Magician Shark And Tornado(백준 : 마법사 상어와 토네이도)](https://github.com/KimUJin3359/Solve_Problems/blob/master/ALGORITHM/MagicianSharkAndTornado.cpp)
- [문제](https://www.acmicpc.net/problem/20057)
- 접근 방법
  - 모래의 이동 방향
    - 1, 1 / 2, 2 처럼 두 번씩 반복하여 해당 길이만큼 이동
    - 방향은 각 1 / 1 / 2 / 2 마다 바뀜
  - 모래가 흩날리는 위치를 미리 입력한 후, 해당 위치가 칸 밖일 경우 겪자 밖으로 나간 모래의 양에 더해줌

[11. Work](https://github.com/KimUJin3359/Solve_Problems/blob/master/ALGORITHM/Work.cpp)
- 문제
- '번호, 요청 시각, 업무량'
- 대기 중 or 작업 중인 일이 없을 때, 업무가 들어오면 즉각 처리
- 대기 중 or 작업 중인 일이 있을 때, 요청된 업무는 대기열에 추가
- 현재 업무 후 다음 업무를 선택
  - 업무량이 작은 일부터 선택
  - 업무량이 같을 경우 먼저 요청된 업무부터 수행
  - 현재 업무가 끝나느 시간과 새로 들어온 요청의 시간이 같은 경우, 새로 들어온 요청은 먼저 대기열에 추가한 후 처리할 작업 선택
- 접근 방법
  - Priority Queue 사용(업무량이 가장 적은 일 찾기)
  - 요청 시각과 현재의 시각을 비교
    - 현재의 시각이 더 작다면, 해당 업무를 다른 곳에 담아둠
  - 만약 전체를 다 봤지만, 현재 시각에 들어온 업무가 없을 시 전체 업무중 최소 시간 업무를 수행
  - 현재 시각에 들어온 업무가 있을 시, 다른 곳에 담아두었던 업무를 다시 가져오고 현재 시각을 

[12. Sale](https://github.com/KimUJin3359/Solve_Problems/blob/master/ALGORITHM/Sale.cpp)
- 문제
- 공장의 물품을 팔려함
- 거래처에서 원하는 물건의 갯수를 알 수 없으나, 요구량을 맞추지 못할경우 100원 -> 50원 -> 25원 -> 거래 중단으로 이어짐
- 총 전체 주어지는 날의 평균 거래액을 소수 2째자리까지 문자열로 반환
- 접근 방법
  - 주어진대로 코딩

---

### [BFS](https://github.com/KimUJin3359/Solve_Problems/tree/master/BFS)

[1. Escape(백준 : 탈출)](https://github.com/KimUJin3359/Solve_Problems/blob/master/BFS/Escape.cpp)
- [문제](https://www.acmicpc.net/problem/3055)
- 고슴도치가 비버의 굴로 가능한 빨리 도망가 홍수를 피하려함
- 매분마다 고슴도치는 현재 있는 칸과 인접한 네 칸 중 하나로 이동
- 물도 매분마다 비어있는 칸으로 확장
- 물이 있는 칸과 인접해있는 비어있는 칸또한 고슴도치가 가지 못함
- 비버의 굴로 이동하기 위한 최소의 시간
- 접근 방법
  - BFS
  - 물을 먼저 한칸씩 이동시킨 후, 고슴도치를 이동시킴
  - time을 두어 고슴도치가 이동할 때만 물이 한 칸씩 퍼지도록 함

[2. Hide And Seek(백준 : 숨바꼭질)](https://github.com/KimUJin3359/Solve_Problems/blob/master/BFS/HideAndSeek.cpp)
- [문제](https://www.acmicpc.net/problem/1697)
- 수빈이는 동생과 숨바꼭질을 함
- 2배, -1칸, 1칸을 이동할 수 있을 때 동생을 찾는 최소 시간
- 접근 방법
  - BFS
  - 2배, -1칸, 1칸을 이동할 때 마다 같은 값이 나오면 최소값으로 갱신

[3. Make Maze(백준 : 미로만들기)](https://github.com/KimUJin3359/Solve_Problems/blob/master/BFS/MakeMaze.cpp)
- [문제](https://www.acmicpc.net/problem/2665)
- n * n크기의 방이 존재
- 왼쪽 최상단에서 우측 최하단으로 이동할 때, 뚫고 지나가야하는 막힌 방의 갯수
- 접근 방법
  - BFS
  - 다음에 볼 칸(검은색)이 현재의 칸 + 1보다 값이 크면 해당 경로 인
  - 다음에 볼 칸(흰색)이 현재의 칸보다 값이 크면 해당 경로 확인 

 
[4. Move Knight(백준 : 나이트의 이동)](https://github.com/KimUJin3359/Solve_Problems/blob/master/BFS/MoveKnight.cpp)
- [문제](https://www.acmicpc.net/problem/7562)
- 체스판 위에 나이트가 놓여져 있음
- 나이트가 목적지로 이동할 때 지나야하는 최소 동작 수
- 접근 방법
  - BFS
  - 나이트가 움직일 수 있는 8방향을 BFS로 완전 탐색
 
[5. Search Maze(백준 : 미로 탐색)](https://github.com/KimUJin3359/Solve_Problems/blob/master/BFS/SearchMaze.cpp)
- [문제](https://www.acmicpc.net/problem/2178)
- N * M크기의 미로가 존재
- 출발지(1, 1)에서 목적지(N, M)으로 이동할 때 지나야하는 최소 칸의 수
- 접근 방법
  - BFS

---

### [완전탐색](https://github.com/KimUJin3359/Solve_Problems/tree/master/BRUTE_FORCE)

[1. Get Honey(SW Expert Academy : 벌꿀채취)](https://github.com/KimUJin3359/Solve_Problems/blob/master/BRUTE_FORCE/GetHoney.cpp)
- [문제](https://swexpertacademy.com/main/talk/solvingClub/problemView.do?solveclubId=AXc2524K9JYDFAWs&contestProbId=AV5V4A46AdIDFAWu&probBoxId=AXf6ka1a40gDFAUO+&type=PROBLEM&problemBoxTitle=Day+17%28%EB%AC%B8%EC%A0%9C%ED%92%80%EC%9D%B42%29&problemBoxCnt=3&&&&&&)
- 꿀을 채취할 수 있는 벌통의 수가 주어짐
- 두 명의 일꾼이 존재/ 각각의 일꾼은 가로로 연속되도록 주어진 수의 벌통만큼 벌통을 선택(겹치면 안됨)
- 일꾼이 채취할 수 있는 최대 꿀의 양이 주어짐
- 각 채취한 벌통의 제곱의 합이 최대가 되는 경우
- 접근 방법
  - 각 값을 제곱한 결과값을 저장
  - 새로운 배열을 만들어 비트 연산자를 활용해 만들 수 있는 최대 값을 계산
  - Brute-Force를 통해 겹치지 않는 두 개의 값 중 최대 값을 선택

[2. Middle Average](https://github.com/KimUJin3359/Solve_Problems/blob/master/BRUTE_FORCE/GetMiddleAverage.cpp)
- [문제](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5Pw_-KAdcDFAUq)
- 10개의 수를 입력 받아, 최대 수와 최소 수를 제외한 나머지의 평균값을 출력하는 프로그램
- 첫째 자리에서 반올림
- 접근 방법
  - 입력받으면서 최대, 최소값 찾기
  - 그를 제외한 나머지들의 합을 구해서 %연산을 활용하여 반올림

[3. Kill Flies](https://github.com/KimUJin3359/Solve_Problems/blob/master/BRUTE_FORCE/KillFlies.cpp)
- [문제](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PzOCKAigDFAUq&)
- 접근 방법
  - 각 범위의 사각형 만큼 합을 구해 최대값을 구함(brute force)
- 알게된 점
  - 동적할당은 정적할당보다 시간이 더 많이 걸림
  - 그렇기 때문에, 코딩 테스트에서는 동적할당보다 정적할당이 유용

[4. Pattern Length](https://github.com/KimUJin3359/Solve_Problems/blob/master/BRUTE_FORCE/PatternLength.cpp)
- [문제](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5P1kNKAl8DFAUq&categoryId=AV5P1kNKAl8DFAUq&categoryType=CODE)
- 각 문자열의 길이는 30
- 마디의 최대 길이는 10일 때, 마디의 최소 길이를 출력
- 접근 방법
  - 문자열의 길이에 따른 substring을 구함
  - find 함수로 문자열 끝까지 substring을 찾아갈 때, 결과 값이 발견했던 index + length 과 같으면 계속해서 탐색하고 같지 않을 시 다음 케이스를 확인

[5. Read Column](https://github.com/KimUJin3359/Solve_Problems/blob/master/BRUTE_FORCE/ReadColumn.cpp)
- [문제](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWVWgkP6sQ0DFAUO)
- 다섯개의 단어가 주어짐
- 단어의 길이는 서로 다를 수 있음
- 이를 세로로 읽었을 때 나오는 문자열을 구하는 문제
- 접근 방법
  - 읽은 값이 0일 때를 제외하고, 문자열에 이어 붙임

[6. Subset Sum](https://github.com/KimUJin3359/Solve_Problems/blob/master/BRUTE_FORCE/SubsetSum.c)
- [문제](https://www.acmicpc.net/problem/1806)
- 10,000 이하의 자연수로 이루어진 길이 N짜리 수열이 주어짐
- 연속된 수들의 부분합 중, 그 합이 주어지는 값(S) 이상 되는 것 중 가장 짧은 것의 길이를 구하는 문제
- 접근 방법
  - DP 
  - 배열의 첫 번째 값에는 입력받은 값을 저장
  - 배열의 두 번째 값에는 S보다 작은 앞의 수들과의 합을 저장
  - index를 통해 시작 점을 잡아주고, 현재 읽은 수를 이 전의 합과 합쳤을 때 S를 넘는다면 index 값을 뺴주며 길이 확인

[7. Vertificate Sudoku](https://github.com/KimUJin3359/Solve_Problems/blob/master/BRUTE_FORCE/VertificateSudoku.cpp)
- [문제](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5Psz16AYEDFAUq)
- 접근 방법
  - 행, 열, 사각형을 기준으로 각 원소가 정확히 1~9까지 중복되지 않고 존재하는지 확인(brute force)

[8. Where To Insert](https://github.com/KimUJin3359/Solve_Problems/blob/master/BRUTE_FORCE/WhereToInsert.cpp)
- [문제](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PuPq6AaQDFAUq)
- 접근 방법
  - 행, 열에 따라 문자가 들어갈 수 있는 길이를 구하여, 원하는 값과 같을 시 결과값을 더하기 1(brute force)

[9. Home Security Service(SW Expert Academy : 홈 방범 서비스)](https://github.com/KimUJin3359/Solve_Problems/blob/master/BRUTE_FORCE/HomeSecurityService.cpp)
- [문제](https://swexpertacademy.com/main/talk/solvingClub/problemView.do?solveclubId=AXc2524K9JYDFAWs&contestProbId=AV5V61LqAf8DFAWu&probBoxId=AXf_stfartEDFAUO+&type=PROBLEM&problemBoxTitle=Day+18%28%EB%AC%B8%EC%A0%9C%ED%92%80%EC%9D%B43%29&problemBoxCnt=++3+)
- N * N 크기의 도시가 존재
- 마름모 모양의 영역에만 홈방범 서비스를 제공
- 보안회사에서 손해를 보지 않으면서 최대한 많은 집에 홈방범 서비스를 제공하려할 때, 제공받는 가구의 수
- 접근 방법
  - Brute Force
  - 맵을 다채우는 마름모의 크기 (3 / 2) * N 부터 2의 크기까지 모두 확인
  - 1의 크기는 기본적으로 모든 마을에서 만족함(홍방범 서비스의 비용 1, 가구 지불비용 최소 1)

[10. Launch Time(SW Expert Academy : 점심 식사시간)](https://github.com/KimUJin3359/Solve_Problems/blob/master/BRUTE_FORCE/LaunchTime.cpp)
- [문제](https://swexpertacademy.com/main/talk/solvingClub/problemView.do?solveclubId=AXc2524K9JYDFAWs&contestProbId=AV5-BEE6AK0DFAVl&probBoxId=AXf_stfartEDFAUO+&type=PROBLEM&problemBoxTitle=Day+18%28%EB%AC%B8%EC%A0%9C%ED%92%80%EC%9D%B43%29&problemBoxCnt=3)
- 두 개의 계단이 존재
- 최대 3명의 학생만이 계단을 이용할 수 있고, 한명이 다 쓰고난 후 다음 사람이 쓸 수 있음
- 모든 사람이 다 내려갈 수 있는 최소 시간 구하기
- 접근 방법
  - Brute Force
  - 각 사람들이 계단1, 계단2로 이동하는 모든 경우의 수를 계산
  - 실행시간을 단축시키기 위해 bit 연산자 사용
  - priority queue를 사용해 각 계단에 도착하는 최소 시간의 사람을 구해서 그 사람들 부터 내려보냄

[11. Infinite String(백준 : 무한 문자열)](https://github.com/KimUJin3359/Solve_Problems/blob/master/BRUTE_FORCE/InfiniteString.cpp)
- [문제](https://www.acmicpc.net/problem/12871)
- x가 abc일 떄, f(x)는 'abcabcabc...'
- s와 t가 주어졌을 때 f(s)와 f(t)가 같은 문자열을 만드는지 판단
- 접근 방법
  - Brute Force
  - s와 t중 더 짧은 문자열 기준(t로 둠)
  - t의 사이즈만큼 substring을 만들면서 t안에서 반복되는 부분 문자열이 있을 경우, s에서도 반복되는지 

[12. 2048(백준 : 2048(Easy))](https://github.com/KimUJin3359/Solve_Problems/blob/master/BRUTE_FORCE/2048.cpp)
- [문제](https://www.acmicpc.net/problem/12100)
- N크기의 보드가 주어짐
- 2의 제곱꼴의 수, 또는 빈칸(0)이 주어질 때 5번 이동시켜서 얻을 수 있는 가장 큰 블록을 출력
- 접근 방법
  - Brute Force
  - 위, 아래, 왼쪽, 오른쪽으로 모두 옮겨봄
  - 5번째의 횟수에 전체 맵을 탐색하여, 가장 큰 값으로 갱신
  - 이 문제는 변경한 값들을 기억하는 것이어렵기 때문에 새로운 맵을 계속해서 만들어서 값을 갱신하여 넘겨줌
  ```
  2 2 2              4 2 0
  0 2 2   -(왼쪽)->  4 0 0
  4 4 0              8 0 0
  ```

[13. Magician Shark And Fire Storn(백준 : 마법사 상어와 파이어 스톰)](https://github.com/KimUJin3359/Solve_Problems/blob/master/BRUTE_FORCE/MagicianSharkAndFireStorm.cpp)
- [문제](https://www.acmicpc.net/problem/20058)
- 접근 방법
  - 맵 나누기
    - 최대 2^6 크기의 맵을 2 / 4 / 8 / 16 .. 등 입력받은 수로 나누어줌
  - 맵 돌리기
    - 가장 껍데기부터 안으로 들어가면서 돌려줌(횟수는 한변의 길이 / 2)
    - 위쪽 행의 첫번 째 인덱스부터 순서대로 오른쪽 열의 첫번 째 인덱스와 교환
    - 교환 되면서 오른쪽 열의 값들이 위쪽 행으로 옮겨감
    - 위쪽 행의 첫번 째 인덱스부터 아래쪽 행의 인덱스 역순으로 교환
    - ... 
    ```
    4 4 4 4 4 4 4 4
    4 3 3 3 3 3 3 4
    4 3 2 2 2 2 3 4
    4 3 2 1 1 2 3 4
    4 3 2 1 1 2 3 4
    4 3 2 2 2 2 3 4
    4 3 3 3 3 3 3 4
    4 4 4 4 4 4 4 4 
    ```
  - 완전 탐색으로 얼음 값이 감소할 구간을 찾기
  - 가장 큰 블록(끊기지 않고 연결된 구간) 찾기
    - 맵의 크기만큼 전체를 보지만, 이미 이어졌다고 판단된 부분은 다시보지 않음(Visited 배열 사용)  

[14. Mail Vertification](https://github.com/KimUJin3359/Solve_Problems/blob/master/BRUTE_FORCE/MailVertification.cpp)
- 메일이 '이름@도메인.탑도메인'으로 구성
- 이름은 소문자와 .으로만 구성
- 도메인은 소문자로만 구성
- 탑도메인은 com, net, org로 구성
- 규격에 맞는 주소는 몇 개인지 찾기
- 접근 방법
  - 한 문자열 씩 brute force
  - 이름 장소에 소문자 혹은 . 이면 다음 문자 확인/ @이면 도메인 탐색 규칙으로 넘어감
  - 도메인 장소에 소문자가 나오면 다음 문자 확인 / .이면 탑도메인 탐색 규칙으로 넘어감
  - 탑 도메인 장소에는 com, net, org가 아닐 시 다음 문자열로 넘어감  

[15. Sliding Bead](https://github.com/KimUJin3359/Solve_Problems/blob/master/BRUTE_FORCE/SlidingBead.cpp)
- 구슬이 바닥으로 어지는 시작 위치의 개수
- N \* N크기의 정사각 격자 형태가 존재
- \# : 아래로 한칸
- \> : 오른쪽으로 한칸
- \< : 왼쪽으로 한칸
- \* : 밑으로 한칸, 두번 째 만날 떄는 멈춤
- 접근 방법
  - 각각의 문자열을 마주쳤을 때, 주어진 방식대로 움직임

[16. Make Number](https://github.com/KimUJin3359/Solve_Problems/blob/master/BRUTE_FORCE/MakeNumber.cpp)
- 성냥개비로 숫자를 만듦
- 성냥개비의 갯수가 주어졌을 때, 만들 수 있는 숫자의 갯수
- 0을 제외한 숫자는 0으로 시작할 수 없음
- 접근 방법
  - 처음 숫자의 경우에만 1 ~ 9 으로 dfs
  - 성냥개비의 갯수가 6일 때, 예외적으로 결과 + 1

---

### [DFS 및 Back Tracking](https://github.com/KimUJin3359/Solve_Problems/tree/master/DFS%26BACKTRACKING)

[1. Cooking(SW Expert Academy : 요리사)](https://github.com/KimUJin3359/Solve_Problems/blob/master/DFS%26BACKTRACKING/Cooking.cpp)
- [문제](https://swexpertacademy.com/main/talk/solvingClub/problemView.do?solveclubId=AXc2524K9JYDFAWs&contestProbId=AWIeUtVakTMDFAVH&probBoxId=AXf6ka1a40gDFAUO+&type=PROBLEM&problemBoxTitle=Day+17%28%EB%AC%B8%EC%A0%9C%ED%92%80%EC%9D%B42%29&problemBoxCnt=3)
- N개의 식재료가 주어짐
- 식재료들을 N / 2개씩 나누어 두개의 요리를 함
- A음식과 B음식의 맛의 차이가 최소가 되도록 재료를 배분하는 문제
- 접근 방법
  - DFS : 순열

[2. Make Number(SW Expert Academy : 숫자 만들기)](https://github.com/KimUJin3359/Solve_Problems/blob/master/DFS%26BACKTRACKING/MakeNumber.cpp)
- [문제](https://swexpertacademy.com/main/talk/solvingClub/problemView.do?solveclubId=AXc2524K9JYDFAWs&contestProbId=AWIeRZV6kBUDFAVH&probBoxId=AXf1vIAqWMkDFAUO&type=PROBLEM&problemBoxTitle=Day+16%28%EB%AC%B8%EC%A0%9C%ED%92%80%EC%9D%B41%29&problemBoxCnt=3)
- n개의 숫자와 n - 1개의 연산자를 입력받아 만들 수 있는 maximum, minimum의 차를 출력하는 문제
- 연산자의 우선 순위는 고려하지 않음
- 접근 방법
  - Back tracking
  - 깊이 우선탐색을 하지만 이전에 결과를 도출했던 연산자를 또 사용하지 않음
  - (n - 1)개의 연산자 중 중복되는 연산자가 다수 존재/ 중복 배제

[3. Remote Control](https://github.com/KimUJin3359/Solve_Problems/blob/master/DFS%26BACKTRACKING/RemoteControl.cpp)
- [문제](https://www.acmicpc.net/problem/1107)
- 임의의 숫자 버튼이 고장난 리모컨이 존재
- 고장난 버튼을 제외하고 0~9까지의 숫자와 +/- 버튼이 존재할 때, 몇 번을 눌러야 최소한의 횟수로 원하는 채널을 볼 수 있는가
- 기존 채널 번호는 100번
- 접근 방법
  - BFS
  - 0번 부터 1000000번까지 만들 수 있는 모든 수에대해 계산
  - default 값과의 차(100번으로부터 +/-만 눌렀을 때)와 위의 만들어지는 횟수를 비교하여 최종 결론 도출
- 어려웠던 점 및 해결방법은 주석으로 정리  

[4.Square Room](https://github.com/KimUJin3359/Solve_Problems/blob/master/DFS%26BACKTRACKING/SquareRoom.cpp)
- N^2개의 방이 존재
- 각 방에는 1이상 N^2 이하의 수가 적혀 있음
- 상하좌우에 있는 다른 방으로 이동할 수 있음(방 존재/ 이동하려는 방에 적힌 숫자가 현재 방에 적힌 숫자보다 정확히 1 더 커야 이동 가능)
- 처음 어떤 수가 적힌 방에 있어야 가장 많은 개수의 방을 이동할 수 있는지 구하는 프로그램
- 접근 방식
  - BFS

[5. Swimming Pool(SW Expert Academy : 수영장)](https://github.com/KimUJin3359/Solve_Problems/blob/master/DFS%26BACKTRACKING/SwimmingPool.cpp)
- [문제](https://swexpertacademy.com/main/talk/solvingClub/problemView.do?solveclubId=AXc2524K9JYDFAWs&contestProbId=AV5PpFQaAQMDFAUq&probBoxId=AXf1vIAqWMkDFAUO&type=PROBLEM&problemBoxTitle=Day+16%28%EB%AC%B8%EC%A0%9C%ED%92%80%EC%9D%B41%29&problemBoxCnt=3)
- 일간, 월간, 3월간, 연간 이용권이 존재할 때 최소 비용으로 수영장을 이용할 떄의 요금을 구하는 문제
- 접근 방법
  - Back tracking
  - 일간 이용권(개장 일 수 * 일간 이용권 가격), 월간 이용권을 비교하여 월간 이용권의 가격이 더 비싼 경우 해당 case를 확인하지 않음

[6. Work Division](https://github.com/KimUJin3359/Solve_Problems/blob/master/DFS%26BACKTRACKING/WorkDivision.cpp)
- N명의 직원과 N개의 일이 존재
- 직원들의 번호가 1부터 N까지 매겨져 있고, 해야할 일에도 번호가 1부터 N까지 매겨져 있을 때, i번 직원이 j의 일을 성공할 확률이 Pi,j
- 주어진 일이 모두 성공할 확률의 최댓값을 구하는 프로그램
- 접근 방법
  - DFS : 기본적으로 모든 가능 경우의 수를 순열을 사용해 전부 다 봐줘야 하는 문제
  - Back tracking : 현재 구한 확률 값이 구해진 결과값보다 작을 때 더이상 보지 않음(확률의 최대값 1, 다른 수가 곱해진다 해서 현재 가진결과값 보다 커질 수 없음)
  - greedy
    - 최악의 경우 tree상에 결과값(BFS)이 끝으로 갈수록 커진다면 모든 경우를 다 봐줘야 될 수 있음
    - 이를 대비하여, 처음 경우에 확률 중 큰 값 만을 찾아서 곱해 만든 결과값을 기준점으로 지정

[7. Mountain Route(SW Expert Academy : 등산로 조성)](https://github.com/KimUJin3359/Solve_Problems/blob/master/DFS%26BACKTRACKING/MountainRoute.cpp)
- [문제](https://swexpertacademy.com/main/talk/solvingClub/problemView.do?solveclubId=AXc2524K9JYDFAWs&contestProbId=AV5PoOKKAPIDFAUq&probBoxId=AXf_stfartEDFAUO+&type=PROBLEM&problemBoxTitle=Day+18%28%EB%AC%B8%EC%A0%9C%ED%92%80%EC%9D%B43%29&problemBoxCnt=++3+)
- 높은 곳(가장 높은 봉우리에서 시작)부터 낮은 곳을 길을 만들 때 최대 길이
- 입력받은 K의 높이만큼 딱 한번 길을 깎을 수 있음
- 접근 방법
  - DFS : 기본적으로 모든 경우의 수를 다 봐줘야 되는 문제

[8. Make Rome Number(백준 : 로마 숫자 만들기](https://github.com/KimUJin3359/Solve_Problems/blob/master/DFS%26BACKTRACKING/MakeRomeNumber.cpp)
- [문제](https://www.acmicpc.net/problem/16922)
- I, V, X, L이 각각 1, 5, 10, 50을 의미
- 로마 숫자 N개(1 ~ 20)를 사용해서 만들 수 있는 서로 다른 수의 개수
- 접근 방법
  - DFS
  - 최대 50 * 20 -> 1000 까지 만들 수 있음
  - 각 값을 만들었을 때 해당 항목을 갱신해주어서 visit을 판단하여 겹치는 숫자가 없이 갯수를 세어줌

[9. Rolling Ball(백준 : 구슬 탈출 2)](https://github.com/KimUJin3359/Solve_Problems/blob/master/DFS%26BACKTRACKING/RollingBall.cpp)
- [문제](https://www.acmicpc.net/problem/13460)
- 빨간 구슬, 파랑 구슬, 구멍의 위치가 주어질 때 빨간 구슬을 탈출 시킬 수 있는 가장 최소의 횟수
- 파랑 구슬이 같이 들어가서는 안됨
- 접근 방법
  - 각각의 구슬들을 벽에 닿을 때까지 움직여보는 작업을 각 방향으로 진행
  - 만약 두 구슬이 겹친다면, 기존의 위치로 상하 판단
  - 파랑 구슬을 먼저 움직인다 가정(파랑 구슬이 들어가면 그 이상 볼 필요가 없기 때문)

[10. Baby Shark(백준 : 청소년 상어)](https://github.com/KimUJin3359/Solve_Problems/blob/master/DFS%26BACKTRACKING/BabyShark.cpp)
- [문제](https://www.acmicpc.net/problem/19236)
- 접근 방법
  - 물고기 이동
    - 1번 부터 16번 까지의 물고기를 확인
    - 물고기가 존재할 경우, 이동가능성 여부를 판단하며 만약 이동 불가시 반시계방향으로 45도씩 회전
    - 8번을 돌아 다시 원래 방향을 가리킨다면 이동을 할 수 없다 판단
  - 상어의 이동
    - 상어가 가려는 칸이 빈칸(물고기가 없는 칸)이 아니면 이동하여 다시 탐색(DFS)

---

### [DP](https://github.com/KimUJin3359/Solve_Problems/tree/master/DP)

[1. Catch Runner(SW Expert Academy : 탈주범 검거)](https://github.com/KimUJin3359/Solve_Problems/blob/master/DP/CatchRunner.cpp)
- [문제](https://swexpertacademy.com/main/talk/solvingClub/problemView.do?solveclubId=AXc2524K9JYDFAWs&contestProbId=AV5PpLlKAQ4DFAUq&probBoxId=AXf6ka1a40gDFAUO+&type=PROBLEM&problemBoxTitle=Day+17%28%EB%AC%B8%EC%A0%9C%ED%92%80%EC%9D%B42%29&problemBoxCnt=3)
- 탈주범의 출발 지점이 주어짐, 출발 시간이 1
- 1시간 마다 연결된 경로로 이동 가능
- 파이프의 모양에 따라 이동이 가능할 수도, 불가능할 수도 있음
- 주어진 시간 후 탈주범이 있을 수 있는 모든 공간의 수를 구하는 문제
- 접근 방법
  - 각 지점으로 이동할 수 있는지를 체크
  - DP : 각 지점에 도착할 수 있는 최소 시간을 입력
  - 최소 시간이 주어진 시간보다 작거나 같은 경우를 셈

[2. Pascal Triangle](https://github.com/KimUJin3359/Solve_Problems/blob/master/DP/PascalTriangle.cpp)
- [문제](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5P0-h6Ak4DFAUq)
- 크기가 N인 파스칼 삼각형 만들기
  - 첫 번째 줄은 항상 1
  - 두 번째 줄부터 각 숫자들은 자신의 왼쪽과 오른쪽 위의 숫자의 합으로 구성
- 접근 방법
  - 1 ~ 10의 결과값을 만들어둔다
  - 입력 받는 값에 따라, 출력
  - 개선 방안
    - 문제를 풀면서 채워놓고, 값이 존재하지 않을 때만 추가적으로 더 해를 구하기(DP)

[3. Leave(백준 : 퇴사)](https://github.com/KimUJin3359/Solve_Problems/blob/master/DP/Leave.cpp)
- [문제](https://www.acmicpc.net/problem/14501)
- 접근 방법
  - DP
  - 첫째 날부터 일을 했을 경우의 결과 값을 일이 끝나는 날에 적음
  - 당일에 도착했을 때, 전날의 값과 현재의 값을 비교하여 더 큰 값으로 DP 배열을 세팅해감
  - N째 날에 도착했을 때의 값이 maximum이 됨

[4. Integer Triangle(백준 : 정수 삼각형)](https://github.com/KimUJin3359/Solve_Problems/blob/master/DP/IntegerTriangle.cpp)
- [문제](https://www.acmicpc.net/problem/1932)
- 맨 위층부터 시작해서 아래에 있는 수 중 하나를 선택하여 아래층으로 내려올 때, 선택된 수의 합이 최대가 되는 경로를 구하는 문제
- 접근 방법
  - DP
  - 맨마지막의 윗층부터, 꼭대기층까지 Bottom-up 방식으로 선택가능한 숫자들 중 가장 큰 숫자를 자기 자신에게 더해감

[5. Subset Sum4(백준 : 구간 합 구하기 4)](https://github.com/KimUJin3359/Solve_Problems/blob/master/DP/SubsetSum4.cpp)
- [문제](https://www.acmicpc.net/problem/11659)
- 수 N개가 주어졌을 때, i번째부터 j번째 수까지 합을 구하는 문제
- 접근 방법
  - DP
  - 숫자를 입력받으면서 그 전까지의 합 + 입력받은 숫자로 배열 초기화
  - j번째 - (i - 1)번째 값이 i번째부터 j번째 수 까지의 합이 됨

[6. Subset Sum5(백준 : 구간 합 구하기 5)](https://github.com/KimUJin3359/Solve_Problems/blob/master/DP/SubsetSum5.cpp)
- [문제](https://www.acmicpc.net/problem/11660)
- N * N개의 수가 주어졌을 때, (x1, y1)부터 (x2, y2)까지의 합을 구하는 문제
- 접근 방법
  - DP
  - 숫자를 입력받으면서 행 기준으로 그 전까지의 합 + 입력받은 숫자로 배열 초기화
  - 그 후 열 기준으로 위 index 값 + 현재 index 값으로 초기화
    - 사각형의 합이 표에 채워짐
  - (x2, y2) 사각형 - (x1, y2) 사각형 - (x2, y1) 사각형 + (x1, y1) 사각형

[7. Climb Stairs(백준 : 계단 오르기)](https://github.com/KimUJin3359/Solve_Problems/blob/master/DP/ClimbStairs.cpp)
- [문제](https://www.acmicpc.net/problem/2579)
- 계단은 한 번에 한 계단 or 두 계단씩 오를 수 있음
- 연속된 세 개의 계단을 모두 밟으면 안됨
- 마지막 도착 계단은 반드시 밟아야 됨
- 맨 마지막 계단을 밟을 때의 최대 점수를 구하는 문제
- 접근 방법
  - DP(점화식)
  - 현재 밟는 계단의 최대 값을 구할 때
    1) 현재 밟고있는 계단의 두개 전 계단 까지의 최대값 + 현재 계단의 값
    2) 현재 밟고있는 계단의 세개 전 계단 까지의 최대값 + 현재 계단 한개 전 계단의 값 + 현재 계단의 값 

[8. Get Biggest Square(백준 : 가장 큰 정사각형)](https://github.com/KimUJin3359/Solve_Problems/blob/master/DP/GetBiggestSquare.cpp)
- [문제](https://www.acmicpc.net/problem/1915)
- n * m의 0, 1로된 배열이 존재
- 이 배열에서 1로 구성된 가장 큰 정사각형의 크기를 구하는 문제
- 접근 방식
  - DP(점화식)
  - 왼쪽, 위쪽, 대각선 위쪽 중 만들어지는 사각형의 값이 가장 작은 경우 + 1
  ```
  0010
  1110
  1100
  1111
  - (3, 2)의 상황에서 대각선 위는 두 칸의 정사각형, 왼쪽은 두 칸의 정사각형을 가지고 있지만
  - 위쪽에서 0칸을 가지고 있기 때문에 최대 1의 정사각형밖에 만들지 못함
  ```

[9. Common Sentence(백준 : 공통 부분 문자열)](https://github.com/KimUJin3359/Solve_Problems/blob/master/DP/CommonSentence.cpp)
- [문제](https://www.acmicpc.net/problem/5582)
- 두 문자열이 주어졌을 때, 두 문자열에 모두 포함된 가장 긴 공통 부문 문자열 길이 찾기
- 접근 방식
  - DP
  - 두 문자의 크기만큼 표를 만들어 공통되는 문자의 갯수를 채워나감
    - (i, j)의 문자가 같을 때 = (i - 1, j - 1) + 1
 
 [10. BOJ(백준 : BOJ 거리)](https://github.com/KimUJin3359/Solve_Problems/blob/master/DP/BOJ.cpp)
 - [문제](https://www.acmicpc.net/problem/12026)
 - B, O, J 순서대로 보도블럭을 밟아가며 이동할 수 있음
 - 해당 칸을 움직이는데 드는 비용은 거리의 제곱
 - 목적지 까지 갈 수 있는 최소의 비용 구하기
 - 접근 방식
   - B, O, J의 좌표를 갖는 큐를 생성
   - 각각의 좌표에서 올 수 있는 최소의 값을 선택
     - 예를 들어 현재 J라면, O들의 배열 중 가장 J까지 오는데 cost가 적은 값을 택함(O의 배열까지 걸린 값 + O ~ 현재 J 까지 오는데 걸린 값)
   - 마지막 까지 값을 갱신하여 만약 마지막 값이 초기값이 아니라면 해당 값 출력 
