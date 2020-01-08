# Lambda

JAVA에서의 객체지향이 아닌 **함수 지향**으로 프로그래밍을 할 수 있는 방법

<br>

## 람다식?

익명 함수 (annoymous function)를 이용하여 익명 객체를 생성하기 위한 식

#### 기존 방법
`Interface Type 변수` <-`할당(대입)`- `interface 구현`
<br>

#### 람다식 방법
`Interface Type 변수` <-`할당(대입)`- `Lambda Expression` <- `interface 구현`

<br>

LamdaInterfaces
```java
public interface LambdaInterface1 {
    public void method(String s1, String s2, String s3);
}

public interface LambdaInterface2 {
    public void method(String s);
}

public interface LambdaInterface3 {
    public void method();   
}

public interface LambdaInterface4 {
    public int method(int x, int y);
}
```

main
```java
public class MainClass {
    public static void main(String[] args) {
        
        // 매개변수와 실행문만으로 작성(접근자, 반환형, return 키워드 생략)
        LambdaInterface1 li1 = (String s1, String s2, String s3) -> {System.out.println(s1 + " " + s2 + " " + s3);};
        li1.method("Hello", "java", "world");
        
        System.out.println();
        
        // 매개변수가 1개이거나 타입이 같을 경우, 타입 생략 가능
        LambdaInterface2 li2 = (s1) -> { System.out.println(s1); };
        li2.method("Hello");
        
        // 실행문이 1개일 경우, '{}'를 생략 가능
        LambdaInterface2 li3 = (s1) -> System.out.println(s1);
        li3.method("Hello");
        
        // 매개변수와 실행문이 1개일 경우, '()'와 '{}'를 생략할 수 있다.
        LambdaInterface2 li4 = s1 -> System.out.println(s1);
        li4.method("Hello");
        
        // 매개변수가 없을 경우, '()'만 작성
        LambdaInterface3 li5 = () -> System.out.println("No parameter");
        li5.method();
        
        // 반환값이 있는 경우
        LambdaInterface4 li6 = (x, y) -> {
            int result = x + y;
            return result;
        };
        System.out.printf("li6.method(10,20) : %d\n", li6.method(10, 20));
        
        // 람다식은 재선언으로 변경할 수 있다.
        li6 = (x,y) -> {
            int result = x * y;
            return result;
        };
        System.out.printf("li6.method(10,20) : %d\n", li6.method(10, 20));
        
        li6 = (x, y) -> {
            int result = x - y;
            return result;
        };
        System.out.printf("li6.method(10,20) : %d\n", li6.method(10, 20));
    }       
}
```
