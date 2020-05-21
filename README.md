# orb-math

Repo for just a hope to make a mathematics library by implementing in a more mathematical way.

이 아래에 서술되어있는 내용은 진위가 확실하지는 않습니다(?). 대부분 의식의 흐름에 따라 작성한 내용이라 글의 체계성이 부족할 수 있습니다.

구현 언어는 아마도 C++일 것 같습니다.

---

## 1. 자연수와 범자연수

### 이론적 배경

우리는 숫자(digit)를 이용하여 수(number)를 표현합니다. 0, 1, 2, ... , 9가 숫자죠. 이 숫자들을 여러 개 붙여쓰면 각 숫자의 위치에 따라 10의 거듭제곱꼴의 배수를 가지게 됩니다. 예를 들어, 147는 1×100+4×10+7로 쓸 수가 있는 것이죠. 147의 1은 100의 자리의 1이므로 100의 크기, 4는 10의 자리의 4이므로 40의 크기, 7은 1의 자리의 7이므로 7의 크기를 가집니다. 이를 모두 더해보면 147이라는 값을 나타냄을 알 수 있습니다. 우리는 이것을 <strong>10진법(decimal)</strong>이라고 부릅니다. 그리고, 이 방식을 이용하여 쓸 수 있는 수 중 0을 제외한 수들을 <strong>자연수(natural numbers)</strong>라고 하고, 여가에 0을 포함시킨 것을 <strong>범자연수(whole numbers)</strong>라고 부릅니다.

이를 컴퓨터에 구현하는 데에는 하나의 문제가 생깁니다. 우리의 뇌는 10진법의 각 숫자를 저장하는데, 컴퓨터는 그렇게 하려면 상당한 자원을 소모합니다. 대신 컴퓨터는 다양한 방법을 이용하여 `OFF`와 `ON`을 저장할 수 있죠. 이를 <strong>비트(bit)</strong>라고 하고, 이 비트의 `OFF`를 0, `ON`을 1로 하여 수를 저장할 수 있습니다. 즉, 수에서 하나의 숫자가 의미할 수 있는 가짓수는 2가지가 되는 것입니다. 이를 <strong>2진법(binary)</strong>라고 부릅니다. 사람이 사용하는 숫자 체계인 10진법과 비교해보면, 사람이 사용하는 숫자는 0에서 9까지 10개였지만 컴퓨터는 0과 1, 2개밖에 존재하지 않습니다. 예시를 들어보면, 101이라는 수는 사람 입장에서는 1×100+0×10+1로 계산하지만 컴퓨터의 입장에서는 1×100<sub>(2)</sub>+0×10<sub>(2)</sub>+1로 계산하여 10진법 기준으로 5의 값을 가집니다.

컴퓨터의 저장 장치는 기술이 발전하면서 충분히 발전해왔습니다. 이미 오래전부터 저장 장치의 최소 단위는 하나의 비트가 아닌 8개의 비트를 모아놓은 <strong>바이트(byte)</strong>를 사용했으니까요. 이 하나의 바이트에는 8개의 비트가 들어가는데, 이 말은 하나의 바이트는 00000000<sub>(2)</sub>부터 11111111<sub>(2)</sub>까지의 수를 저장할 수 있음을 의미합니다. 11111111<sub>(2)</sub>는 10진법으로 써보면 255인데, 이 말은 하나의 바이트가 0부터 255까지의 2<sup>8</sup>=256개의 수를 저장할 수 있다는 것입니다. 또한, 요즘은 2바이트(`short`), 4바이트(`int`), 또는 8바이트(`long` 또는 `long long`)를 하나의 수를 저장하는 데에 사용합니다(64비트 기준). 그렇게 저장할 경우 각각 2<sup>16</sup>=65536, 2<sup>32</sup>=4294967296, 2<sup>64</sup>=‭18446744073709551616‬개의 수를 저장할 수 있습니다.

### 구상 및 구현

제가 원하는 것은 이상적인 상황에서 제한없이 큰 범자연수를 저장할 수 있는 것입니다. 이를 구현할 때에는 위의 `unsigned long long`을 여러 개 엮어서 더 큰 정수를 의미하게 하려고 합니다. 8바이트 양의 정수 범위 이내의 수를 하나의 숫자로 하는 수 체계(18446744073709551616진법 또는 2<sup>64</sup>진법)를 만드는 것이죠. 단순하게 벡터를 이용하여 구현할 수 있을 것 같습니다. 다만, 평소에 숫자를 쓰는대로 왼쪽(벡터 기준 작은 index의 원소)에 큰 쪽의 숫자가 들어가는 것이 아니고 index가 큰 쪽에 들어갑니다. 추후 구현할 연산을 효율적으로 적용시키기 위해서죠.

#### 구현할 것

[소스 코드](/src/whole_number.cpp)

- [x] 클래스의 구조
- [x] 컴퓨터에서 사용하는 일반적인 정수형 값을 이 클래스로 만들어주는 함수(또는 생성자)
- [x] 문자열(hex, bin)을 파싱하여 이 클래스로 만들어주는 함수(또는 생성자)
- [x] 현재 클래스가 가지는 값(hex, bin)을 표시하는 함수

#### 테스트

[소스 코드](/src/whole_number_test.cpp)

- unsigned long long 값에 대해 WholeNumber를 생성했을 때 정상적인 값을 가지고 있는가
- unsigned long long 범위 밖의 hex string과 bin string에 대해 각각 WholeNumber를 생성했을 때 올바른 hex string과 bin string을 출력하는가
- 잘못된 string에 대해 오류를 잘 출력하는가
- 2 또는 16이 아닌 radix에 대해 오류를 잘 출력하는가
