배우고 완성하겠음

읽지 마셈



이번에도 O(N)의 방법으로 수열을 처음부터 확인할건데 이번에는 이분탐색을 이용하여 LIS를 유지하기 위한 **최적의 위치에다가 수를 삽입**하는 방식입니다.

 자리를 찾는데 lower_bound를 이용하기 때문에 O(logN)의 시간복잡도를 가지게 되어 총 O(NlogN)의 시간복잡도를 가지게 됩니다.



벡터를 하나 생성 한 뒤 -INF(나올 수 없는 가장 작은 값)를 삽입해 줍니다.



이후 매번 수열을 볼때마다 벡터의 맨 뒤 원소와 현재 보고있는 수열의 원소를 비교하여 수열의 원소가 더 클 시 벡터에 push_back해준 뒤 LIS의 크기(답)을 1증가 시켜줍니다.



만약 수열의 원소가 벡터의 맨 뒤 원소보다 작을 경우 lower_bound를 이용하여 최적의 자리를 찾은 뒤 그 자리의 값을 해당 수열의 원소로 교체해 버립니다.



만약 벡터에 현재 10 40 70 이라는 값이 들어있다고 할 때 50이 들어갈 위치를 찾기 위하여 lower_bound로 50을 찾는다면 이터레이터는 70의 위치를 가리키게 되어 70을 50으로 갱신할 것 입니다.



그러면 벡터에는 10 40 50 이라는 값이 들어가게 될 것입니다.



우리가 lower_bound를 이용하여 x라는 값을 찾으면 x보다 크거나 같은값중 최솟값의 위치를 return하기 때문에



현재 구성된 lis구조를 유지하면서 앞으로 보게 될 수열들을 최대한 벡터가 많이 수용할 수 있도록 적절한 위치에 값이 갱신이 됩니다.



![LIS_binary1.png](https://github.com/doooooooong/studyBoard/blob/master/algorithm/DP/image/LIS_binary1.png?raw=true)

빨간부분은 지금 보는 위치이고 파란칸을 벡터라고 하겠습니다. 10의 경우 첫번째 수이기 때문에 우선 벡터에 넣어줍니다.



![LIS_binary2.png](https://github.com/doooooooong/studyBoard/blob/master/algorithm/DP/image/LIS_binary2.png?raw=true)

3번째 인덱스까지는 벡터의 끝값이 항상 수열의 값보다 작기 때문에 전부 삽입해 줍니다. 



![LIS_binary3.png](https://github.com/doooooooong/studyBoard/blob/master/algorithm/DP/image/LIS_binary3.png?raw=true)

이후 4번째 인덱스의 값이 벡터의 끝값보다 작기 때문에 lower_bound로 탐색한 뒤 40을 25로 갱신해줍니다.



![LIS_binary4.png](https://github.com/doooooooong/studyBoard/blob/master/algorithm/DP/image/LIS_binary4.png?raw=true)

5번째 인덱스의 값또한 벡터의 끝값보다 작기 때문에 lower_bound로 탐색한 뒤 20을 20으로 갱신해줍니다.



![LIS_binary5.png](https://github.com/doooooooong/studyBoard/blob/master/algorithm/DP/image/LIS_binary5.png?raw=true)

6번째 인덱스의 값은 벡터의 끝값보다 크기 때문에 50을 추가해 줍니다.



![LIS_binary6.png](https://github.com/doooooooong/studyBoard/blob/master/algorithm/DP/image/LIS_binary6.png?raw=true)

7번째 인덱스의 값은 벡터의 끝값보다 작기 때문에 lower_bound로 탐색 한 뒤 50을 30으로 갱신해줍니다.



자 이때 만약에 뒤에 40이라는 값이 온다면 벡터의 끝값을 30으로 갱신하지 않았다면 40을 추가하지 못할것입니다.



하지만 매 순간 증가수열을 유지할 수 있는 최적의 장소를 찾아서 갱신하기 때문에 다음에 40이 올 경우 추가할 수 있게됩니다.



![LIS_binary7.png](https://github.com/doooooooong/studyBoard/blob/master/algorithm/DP/image/LIS_binary7.png?raw=true)

자 다시 돌아와서 70과 85를 벡터에 추가해준다면 우리는 이 수열에서의 LIS의 길이는 6이라는 사실을 알 수 있게됩니다.

