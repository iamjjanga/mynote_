# Networking

네트워크 대상(객체) 사이에 입/출력(InputStream, OutputStream)를 이용해서 데이터를 입력하고 출력한다.

<br>

## Socket & ServerSocket

<img src="https://static.javatpoint.com/core/images/socket-programming.png" width=400px>

<details>
    <summary>Socket code</summary>
    ```java
    public static void main(String[] args) {
        
        Socket socket = null;
        
        try {
            socket = new Socket("localhost", 9000);
            System.out.println("connect to Server~~");
            System.out.println("socket : " + socket);
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            try {
                if(socket != null) socket.close();
            } catch (Exception e2) {
                e2.printStackTrace();
            }
        }
    }
    ```
</details>

<details>
    <summary>ServerSocket code</summary>
    ```java
    public static void main(String[] args) {
    
        ServerSocket serverSocket = null;
        Socket socket = null;
        
        try {
            serverSocket = new ServerSocket(9000);
            System.out.println("ready to connect");
            
            socket = serverSocket.accept();
            System.out.println("success to connect");
            System.out.println("socket : " + socket);
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                if(socket != null) socket.close();
                if(serverSocket != null) serverSocket.close();
            } catch (Exception e2) {
                e2.printStackTrace();
            }
        }
    }
    ```
</details>

<br>

## Client-Server Message 통신

<img src="http://www.askyb.com/wp-content/uploads/2013/03/simple-tcp-client.png"width=400px>

<details>
    <summary>Client code</summary>
    ```java
    public class ClientClass {
        public static void main(String[] args) {
            
            Socket socket = null;
            
            OutputStream outputStream = null;
            DataOutputStream dataOutputStream = null;
            
            InputStream inputStream = null;
            DataInputStream dataInputStream = null;
            
            Scanner scanner = null;
            
            try {
                socket = new Socket("localhost", 9000);
                System.out.println("ready to connect");
                
                outputStream = socket.getOutputStream();
                dataOutputStream = new DataOutputStream(outputStream);
                
                inputStream = socket.getInputStream();
                dataInputStream = new DataInputStream(inputStream);
                
                scanner = new Scanner(System.in);
                
                while(true) {
                    System.out.print("input Message : ");
                    String outMessage = scanner.nextLine();
                    dataOutputStream.writeUTF(outMessage);
                    dataOutputStream.flush();
                    
                    String inMessage = dataInputStream.readUTF();
                    System.out.println("inMessage : " + inMessage);
                    
                    if(outMessage.equals("exit")) break;
                }
                
            } catch (IOException e) {
                e.printStackTrace();
            } finally {
                try {
                    if(dataOutputStream != null) dataOutputStream.close();
                    if(outputStream != null) outputStream.close();
                    if(dataInputStream != null) dataInputStream.close();
                    if(inputStream != null) inputStream.close();
                } catch (IOException e2) {
                    e2.printStackTrace();
                }
            } 
        }
    }
    ```
</details>

<details>
    <summary>Server code</summary>
    ```java
    public class ServerClass {
        public static void main(String[] args) {
            
            ServerSocket serverSocket = null;
            Socket socket = null;
            
            OutputStream outputStream = null;
            DataOutputStream dataOutputStream = null;
            
            InputStream inputStream = null;
            DataInputStream dataInputStream = null;
            
            try {
                serverSocket = new ServerSocket(9000);
                System.out.println("ready to connect");
                
                socket = serverSocket.accept();
                System.out.println("success to connect");
                System.out.println("socket : " + socket);
                
                outputStream = socket.getOutputStream();
                dataOutputStream = new DataOutputStream(outputStream);
                
                inputStream = socket.getInputStream();
                dataInputStream = new DataInputStream(inputStream);
                
                while(true) {
                    String clientMessage = dataInputStream.readUTF();
                    System.out.println("ClientMessage : " + clientMessage);
                    
                    dataOutputStream.writeUTF("ack~");
                    dataOutputStream.flush();
                    
                    if(clientMessage.equals("exit")) break;
                }
            } catch (IOException e) {
                e.printStackTrace();
            } finally {
                try {
                    if(dataOutputStream != null) dataOutputStream.close();
                    if(outputStream != null) outputStream.close();
                    if(dataInputStream != null) dataInputStream.close();
                    if(inputStream != null) inputStream.close();
                } catch (IOException e2) {
                    e2.printStackTrace();
                }
            }
        }
    }
    ```
</details>