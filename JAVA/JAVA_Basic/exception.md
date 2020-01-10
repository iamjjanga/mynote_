# Exception

**Exception?** vs **Error?**

- Exception : 개발자가 대처할 수 있음.
- Error : 전기가 끊김, H/W적 문제 등 개발자가 대처할 수 없음

<br>

## Exception

- **Checked Exception** : '예외처리'를 반드시 해야하는 경우 (Network, File System ..)
- **Unchecked Exception** : '예외처리'를 개발자의 판단에 맞기는 경우 (Data error ...)

- #### `Exception` Class
    + `NullPointerException` : 객체를 가리키지 않고 있는 래퍼런스를 이용할 때
    + `ArrayIndexOutOfBoundException` : 배열에서 존재하지 않는 인덱스를 가리킬 때
    + `NumberFormatException` : 숫자데이터에 문자데이터등을 넣었을 때

<br>

## Try ~ Catch ~ Finally

```
try {
    (예외가 발생할 수 있는 code)
} catch (Exception e) {
    (예외 발생했을 때 처리할 code)
}
```

<details>
    <summary>1. exception 출력</summary>

    ```java
    int i = 10;
    int j = 0;
    int r = 0;
    
    System.out.println("Exception BEFORE");
    
    try {
        r = i / j;
    } catch (Exception e) {
        e.printStackTrace();            // error message console창 출력
        String msg = e.getMessage();    // 간략한 error message 문자열 
        System.out.println("Exception : " + msg);
        }
    
    System.out.println("Exception AFTER");
    ```
</details>

<details>
    <summary>2. 예외처리 다양화</summary>

    ```java
    Scanner scanner = new Scanner(System.in);
    int i, j;
    ArrayList<String> list = null;
        
    int[] iArr = {0,1,2,3,4};
        
    System.out.println("Exception BEFORE");
        
    try {
        System.out.println("input i : ");
        i = scanner.nextInt();
        System.out.println("input j : ");
        j = scanner.nextInt();
            
        System.out.println("i / j = " + (i/j));
            
        for(int k = 0; k < 6; k++) {
            System.out.println("iArr[" + k + "] : " + iArr[k]);
        }
            
        System.out.println("list.size() : " + list.size());
    } catch (InputMismatchException e) {
        e.printStackTrace();
    } catch (ArrayIndexOutOfBoundsException e) {
        e.printStackTrace();
    } catch (Exception e) {
        e.printStackTrace();
    } finally {
            System.out.println("예외 발생 여부에 상관없이 언제나 실행 됩니다.");
    }
        
    System.out.println("Exception AFTER");
    ```
</details>

<details>
    <summary>3. throw</summary>
    예외 발생 시 예외 처리를 직접하지 않고 호출한 곳으로 넘긴다.
    ```java
    public class MainClass {
        public static void main(String[] args) {        
            MainClass main = new MainClass();
            
            try {
                main.firstMethod();
            } catch (Exception e) {                 // 여기서 처리
                e.printStackTrace();
            }
        }
        
        public void firstMethod() throws Exception {    // 호출한 mainClass로 넘김
            secondMethod();
        }
        public void secondMethod() throws Exception {   // 호출한 firstMethod로 넘김
            thirdMethod();
        }
        public void thirdMethod() throws Exception {    // 호출한 secondMethod로 넘김
            System.out.println("10 / 0 = " + (10 / 0));
        }
    }
    ```
</details>