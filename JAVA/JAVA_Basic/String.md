# String
문자열을 다루는 String 클래스(객체)는 데이터가 변하면 메모리상의 변화가 많아 속도가 느림

<br>

## String 객체

<img src="https://lh3.googleusercontent.com/GEqDdORYtKK6knPwsXIZww1XqB7tubmJi63kQRYOXQYkZ3cf5nfdfvgSwHnZf0arY-dXSYdq653P7M9vkbNbCc1KUO4e4UnWuyP42L_8e9dqcavoW92d7ljPPkQiEQwyY4rjkOR6grxS4-Rla3l2GDKiWLxRfge2JTbjPFYBKo5GiYac5S72N9R7HyJxRWGscZKI_QJwQLGVkdD_7yl41UTZmZ-Nfc3kKeJ9r7EMo4X_y5dmoZCLj9Ugr3Cz3JY8z0FWTwn7V6gm7sj9lSALw--DR0Dehw_BUuHek0wkxpptHx0z8hwP11M_UdbjllLDEzRUT8W_gqcyPsMjVG2setUOo3xc0ArccaSvqmZ6ffjPzsJupf3mEvyJlftCDckHPJtM8a1H0pKJ8XuNT6y-KxY2lMpY6Y85VjXsVPa4XUCbZtqXAOGtvl1thY3PaHC8Jw-NrhQFR_53-gF7spg73nh3XhgOZSukkJARQwzIpfTzC3Rol4OARGFoxRrj_lX03HYcCXBKEI60rjGxGG-qL8LSsuJyqkaKIdqLU_PUyZgZcJJNUEyYRXqTavXuzvYtnm9kmztKnuq6cqWlIltNyhSBZ-XIDPquqwyXiwYh2PZHBMoa7ELiXkBHE4B5qnYnRyUg9wnoubxN7bGm6UPU-aUHcsfCeL6yjjy9PemX3V1kTJN1DFKVsq8=w676-h394-no" width=400px>

`String str = "JAVA"`(객체 A)와 `str = str + "_8"` 후의 객체(객체 B)는 다르다.

즉, `.equals`의 값은 `false`가 된다.

- 문자열이 변경되면 기존의 객체를 버리고, 새로운 객체를 메모리에 생성
> String의 new로 생성된 instance는 immutable(메모리 공간 변화X)하다.

- 이때, 기존 객체는 GC에 의해서 메모리 회수가 이루어진다.

<br>

#### 장점
- String 클래스의 불변의 특성은 단순 읽는 조회(Read)에서는 속도가 빠름.
- multiThread환경에서 Sync를 신경쓸 필요가 없다.

<br>

#### 단점
- 문자열 연산이 많은 경우 **계속해서 객체를 만드는 Overhead**의 문제점이 있음. (성능저하),(연산내부는 char배열)

<br>

#### 결론
String클래스는 문자열 연산이 적고 조회가 많은 **MultiThread**환경에서 사용하면 좋다.

<br><br>

## StringBuffer, StringBuilder

<img src="https://1.bp.blogspot.com/-9Y25IXUtabI/XNls69qz4TI/AAAAAAAACqI/aoySDRgC2_IxukN1Ta4V4zDzvkjHw_qjQCLcBGAs/s1600/stringbuffer-java.png" width=500px>

String 클래스의 단점을 보완한 클래스로 데이터가 변경되면 메모리에서 기존 객체를 재활용한다.

`StringBuffer sf = new StringBuffer("JAVA")`와 `sf.appen("_8")`후의 객체가 같다.

- 문자열이 변경되어도 기존의 객체를 재활용한다.(`new`를 한번만 사용)

<br>

#### 장점
- 문자열 연산이 자주 있는 경우 성능이 좋다.

<br>

### StringBuffer vs StringBuilder
- `StringBuffer`는 multiThread환경에서 **Synchronized** keyword가 가능하므로 동기화가 가능하다. (**Thread-safe**)

- `StringBuilder`는 동기화를 지원하지 않기때문에 multiThread환경에서는 적합 **X** 대신에, 동기화를 고려하지 않기때문에 singleThread환경에서는 `StringBuffer`에 비해 연산처리 속도가 빠르다.

<br>

#### 결론
- 문자열 연산이 많음, multiThread => `StringBuffer`
- singleThread, Thread를 신경쓰지 않는 환경 => `StringBuilder`

<br>

> #### 참고 `StringBuffer`와 `StringBuilder` 속도
> - 성능면에서 약 2배정도의 차이가 있다고 하지만 참고사이트의 속도 차이 실험 결과는 `append()`연산이 약 1억6천만번 일어날때 약2.6초의 속도차이가 있다고함. <br>
> - (+`String`은 +연산이 16만번이상 넘어가면 10초이상 걸려서 매우 안좋은 성능을 보임) <br>
> - 따라서, 문자열 연산이 엄청 많이 일어나지 않는 환경이라면 `StringBuffer`를 사용하여 Thread-safe한 것이 더 좋을꺼 같음.
> - JDK1.5이상 `String`에서 +연산으로 작성하더라도 `StringBuilder`로 컴파일하게 만들어 놨다고는 하지만 여전히 `String`클래스의 객체 생성 부분은 동일하므로 `StringBuffer`, `StringBuilder` 사용이 필요함.
> - \+ `StringBuffer`, `StringBuilder`의 경우 buffer size를 초기에 설정해야하는데 이런 생성, 확장 overload가 걸려 buffer size를 잘못 초기화하는 경우 성능이 좋지 못할 가능성이 있음.
> - \+ `String`클래스가 컴파일분석단계에서 최적화될 가능성이 있기때문에 간혹 성능이 잘나오는 경우도 있음. 문자열 연산이 많지 않은 경우는 그냥 사용해도 무방.

> \+, concat을 사용하는 사고를 치면 안됨, 현업에서!!

참고blog[https://jeong-pro.tistory.com/85](https://jeong-pro.tistory.com/85)

<details>
    <summary>StringBuffer & StringBuilder</summary>
    ```java
    public class MainClass {
        public static void main(String[] args) {
            // String
    //      String str = "java";
            String str = new String("java");
            str = str + " world";
            System.out.println("str : " + str);
            
            System.out.println();
            
            // StringBuffer
            StringBuffer sf = new StringBuffer("java");
            System.out.println("sf : " + sf);
            
            System.out.println("sf.length() : " + sf.length());
            
            sf.append(" world");
            System.out.println("sf : " + sf);
            sf.insert(4, "~~~~");
            System.out.println("sf : " + sf);
            sf.insert(sf.length(), "!!");
            System.out.println("sf : " + sf);
            sf.delete(4,8);
            System.out.println("sf : " + sf);
            sf.delete(sf.length()-2, sf.length());
            System.out.println("sf : " + sf);
            sf.deleteCharAt(4);
            System.out.println("sf : " + sf);
            
            System.out.println();
            
            // StringBuilder
            StringBuilder sd = new StringBuilder("java");
            sd.append(" world");
            System.out.println("sd : " + sd);
            
            System.out.println("sd.length() : " + sd.length());
            
            sd.append(" world");
            System.out.println("sd : "+ sd);
            sd.insert(4, "~~~~");
            System.out.println("sd : " + sd);
            sd.insert(sd.length(), "!!");
            System.out.println("sd : " + sd);
            sd.delete(4,8);
            System.out.println("sd : " + sd);
            sd.delete(sd.length()-2, sd.length());
            System.out.println("sd : " + sd);
            sd.deleteCharAt(4);
            System.out.println("sd : " + sd);
        }       
    }
    ```
</details>

