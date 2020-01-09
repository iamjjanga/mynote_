# I/O

- Input : Program -> I/O target
- Output : Program <- I/O target

- InputStream
    + FileInputStream
    + DataInputStream
    + BufferedInputStream
- OutputStream
    + FileOutputStream
    + DataOutputStream
    + BufferedOutputStream

## FileInputStream / FileOutputStream
### FileInputStream

<details>
    <summary>read() : 1byte씩 읽음</summary>
    ```java
        // read()
        InputStream inputStream = null;
        
        try {
            inputStream = new FileInputStream("C:\\Users\\LeeSiHyeong\\java_Basic\\pjtTest\\src\\pjtTest\\Hello.txt");
            int data = 0;
            
            while(true) {
                try {
                    data = inputStream.read();
                } catch (Exception e) {
                    e.printStackTrace();
                }
                if(data == -1) 
                    break;
                System.out.println("data : " + data);
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } finally {
            try {
                if(inputStream != null) inputStream.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    ```
</details>
<details>
    <summary>read(byte[]); : byte[] 배열크기만큼 읽음</summary>
    ```java
        // read(byte[])
        InputStream inputStream = null;
        try {
            inputStream = new FileInputStream("C:\\Users\\LeeSiHyeong\\java_Basic\\pjtTest\\src\\pjtTest\\Hello.txt");
            int data = 0;
            byte[] bs = new byte[3];
                
            while(true) {
                try {
                    data = inputStream.read(bs);
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if(data == -1) 
                    break;
                System.out.println("data : " + data);
                for(int i= 0;i < bs.length; i++)
                    System.out.println("bs[" + i + "] : " + bs[i]);
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } finally {
            try {
                if(inputStream != null) inputStream.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    ```

    ```
    *****output*****
    data : 3
    bs[0] : 72
    bs[1] : 101
    bs[2] : 108
    data : 3
    bs[0] : 108
    bs[1] : 111
    bs[2] : 32
    data : 3
    bs[0] : 87
    bs[1] : 111
    bs[2] : 114
    data : 3
    bs[0] : 108
    bs[1] : 100
    bs[2] : 33
    data : 2    //
    bs[0] : 33
    bs[1] : 33
    bs[2] : 33  // data가 2인데 출력된 값은 이전 배열의 쓰레기값이다. 
    ```
</details>

<br>

### FileOutputStream
<details>
    <summary>write(byte[] b); : 전체 쓰기</summary>
    ```java
        // write()
        OutputStream outputStream = null;
        try {
            outputStream = new FileOutputStream("C:\\Users\\ LeeSiHyeong\java_Basic\\pjtTest\\src\\pjtTest\\HelloW.txt");
            String data = "Hello java world!!";
            byte[] arr = data.getBytes();            
            try {
                outputStream.write(arr);
            } catch (IOException e) {
                e.printStackTrace();
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } finally {
            try {
                if(outputStream != null) outputStream.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    ```
</details>

<details>
    <summary>write(byte[], int off, int len) : byte[]를 off에서 len만큼 쓰기</summary>
    ```java
        // write(byte[], off, len)
        OutputStream outputStream = null;
        try {
            outputStream = new FileOutputStream("C:\\Users\\ LeeSiHyeong\java_Basic\\pjtTest\\src\\pjtTest\\HelloW.txt");
            String data = "Hello java world!!";
            byte[] arr = data.getBytes();            
            try {
                outputStream.write(arr, 0 , 5);
            } catch (IOException e) {
                e.printStackTrace();
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } finally {
            try {
                if(outputStream != null) outputStream.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    ```
</details>

<details>
    <summary>file copy</summary>
    ```java
        InputStream inputStream = null;
        OutputStream outputStream = null;
        
        try {
            inputStream = new FileInputStream("C:\\Users\\LeeSiHyeong\\java_Basic\\pjtTest\\src\\pjtTest\\Hello.txt");
            outputStream = new FileOutputStream("C:\\Users\\LeeSiHyeong\\java_Basic\\pjtTest\\src\\pjtTest\\HelloWW.txt");
            
            byte[] arr = new byte[3];
            
            while(true) {
                int len = inputStream.read(arr);
                if(len == -1) break;
                outputStream.write(arr, 0, len);
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            if(inputStream != null) {
                try {
                    inputStream.close();
                } catch (Exception e2) { e2.printStackTrace(); }
            }
            
            if(outputStream != null) {
                try {
                    outputStream.close();
                } catch (Exception e2) { e2.printStackTrace(); }
            }
        }
    ```
</details>
<br>

## DataInputStream / DataOutputStream
byte 단위의 입출력을 개선해 문자열을 좀 더 편리하게 다룰 수 있음.

<details>
    <summary>DataOutputStream</summary>
    ```java
    String str = "Hello Java World!!\n it's good for you, cause good choice!!";
    OutputStream outputStream = null;
    DataOutputStream dataOutputStream = null;
        
    try {
        outputStream = new FileOutputStream("C:\\Users\\LeeSiHyeong\\java_Basic\\pjtTest\\src\\pjtTest\\HelloWW.txt");
        dataOutputStream = new DataOutputStream(outputStream);
            
        dataOutputStream.writeUTF(str);
    } catch (Exception e) {
        e.printStackTrace();
    } finally {
        try {
            if(dataOutputStream != null) dataOutputStream.close();
        } catch (Exception e2) {
            e2.printStackTrace();
        }
            
        try {
            if(outputStream != null) outputStream.close();
        } catch (Exception e2) {
            e2.printStackTrace();
        }
    }
    ```
</details>

<details>
    <summary>file copy (DataInputStream, DataOutputStream)</summary>
    ```java
    InputStream inputStream = null;
    OutputStream outputStream = null;
    DataInputStream dataInputStream = null;
    DataOutputStream dataOutputStream = null;
    
    try {
        inputStream = new FileInputStream(arg0);
        dataInputStream = new DataInputStream(inputStream);
        
        String str = dataInputStream.readUTF();
        
        outputStream = new FileOutputStream(arg0);
        dataOutputStream = new DataOutputStream(outputStream);
        
        dataOutputStream.writeUTF(str);
    } catch (Exception e) {
        e.printStackTrace();
    } finally {
        try {
            if(dataOutputStream != null) dataOutputStream.close();
        } catch (Exception e2) {
            e2.printStackTrace();
        }
        
        try {
            if(outputStream != null) outputStream.close();
        } catch (Exception e2) {
            e2.printStackTrace();
        }
    }
    ```
</details>

