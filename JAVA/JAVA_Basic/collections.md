# Collections

자료(데이터)를 효율적으로 관리하기 위한 방법

## List

- ArrayList
- LinkedList
- Vector

### 특징
- index를 이용
- 데이터 중복이 가능

```java
// ArrayList 객체 생성
ArrayList<String> list = new ArrayList<String>();

// data 추가
list.add("Hello");
list.add("Java");
list.add("World");
System.out.println("list.size : " + list.size());
System.out.println("list : " + list);

list.add(2, "Programming"); // 추가
System.out.println("list : " + list);

list.set(1, "C");           // 변경
System.out.println("list : " + list);

// data 출력
for(int i=0;i<list.size(); i++) {
    System.out.print(list.get(i) + " ");
}
System.out.println();

// data 추출
String str = list.get(2);
System.out.println("list.get(2) : " + str);
System.out.println("list : " + list);

// data 제거
str = list.remove(2);
System.out.println("list.remove(2) : " + str);
System.out.println("list : " + list);

// data 전체 제거
list.clear();               // 객체는 제거 X
System.out.println("list : " + list);

// data 유무
boolean b = list.isEmpty();
System.out.println("list.isEmpty() : " + b);
```

<br><br>

## Map

- HashMap

### 특징
- key를 이용
- key는 중복될 수 없다.
- 데이터 중복이 가능

```java
// HashMap 객체 생성
HashMap<Integer, String> map = new HashMap<Integer, String>();
System.out.println("map.size() : " + map.size());

// data 추가
map.put(5, "Hello");
map.put(6, "Java");
map.put(7, "World");
System.out.println("map : " + map);
System.out.println("map.size() : " + map.size());

map.put(8, "!!");
System.out.println("map : " + map);

// data 교체
map.put(6, "C");
System.out.println("map : " + map);

// data 출력
for(int i=5;i<=8; i++) {
    System.out.print(map.get(i) + "        
}
System.out.println();

// data 추출
String str  = map.get(5);
System.out.println("map.get(5) : " + str);

// data 제거
map.remove(8);
System.out.println("map : " + map);

// 특정 key 포함 유무
boolean b = map.containsKey(7);
System.out.println("map.containkey(7) : " + b);

// 특정 value 포함 유무
b = map.containsValue("World");
System.out.println("map.containValue(\"World\")" + b);

// data 전체 제거
map.clear();
System.out.println("map : " + map);

// data 유무
b = map.isEmpty();
System.out.println("map.isEmpty() : " + b);
```