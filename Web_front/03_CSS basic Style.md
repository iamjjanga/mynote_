# CSS Basic Style
<br><br>

## 1. color, Font와 같은 스타일 변경

### font 색생 변경

- color : red;
- color : rgba(255,0,0,0.5);
- color : #ff0000;

<br>

### font 사이즈 변경

- font-size : 16px; // 기본 폰트 사이즈
- font-szie : 1em;  // 기본 폰트의 배수 적용

<br>

### 배경색

- background-color : #ff0;  // yellow

<br>

### 글씨체/글꼴

- font-family : "Gulim";
- font-family : monospace;

> 각 style에 대해서는 필요에 의해 검색활용할 것!

<br>

<details>
    <summary>test code</summary>

    ```html
    <!DOCTYPE html>
    <html>
    <head>
      <meta charset="utf-8">
      <meta name="viewport" content="width=device-width">
      <title>JS Bin</title>
      <style>
        body > div {
          font-size : 16px;
          background-color : #ff0;
          font-family : "Gulim";
        }
        
        .myspan {
          color:#f00;
          font-size:2em;    /* 상속된 폰트의 2배 = 32px*/
        }
      </style>
    </head>
    <body>
        <div>
          <span class="myspan">my text is upper!</span>
        </div>
    </body>
    </html>
    ```

</details>

<br><br>

## 2. BOX Model을 이용한 엘리먼트 배치

<br>

### BOX MODEL

<img src="http://www.avajava.com/tutorials/cascading-style-sheets/how-are-margins-borders-padding-and-content-related/how-are-margins-borders-padding-and-content-related-01.gif" width="400px">

- HTML의 element는 사각형 박스 형태를 가지며, 다음과 같은 속성을 가진다.
- margin : elements간의 간격
- border : 테두리 두께
- padding : 테두리와 글자 간의 간격

<br>

### margin의 특성

- 인접한 두 개의 block elment가 서로 다른 margin을 가지고 있다면?
    \- 큰 값을 가진 margin값이 공유되어 사용됨
    \- 10px + 20px = 20px

- 인접한 두 개의 inline element의 margin은?
    \- 각각의 margin의 합으로 표현
    \- 10px + 20px = 30px

<br>

### margin, padding의 다양한 축약표기법

- margin : 0px, 0px, 0px, 10px; (top, right, bottom, left)
- margin : 10px; (네개의 분면이 모두 10px)
- margin : 10px 15px; (top, bottom은 10px, right left는 15px) 

<br>

<details>
    <summary>test code</summary>

    ```html
    <!DOCTYPE html>
    <html>
    <head>
      <meta charset="utf-8">
      <meta name="viewport" content="width=device-width">
      <title>JS Bin</title>
      <style>
        div {
          width:100px;
          height:100px;
          border:4px solid slategray;
        }
        .wrap {
          padding:10px;
          margin-bottom:30px;
        }
      </style>
    </head>
    <body>
      <div class="wrap">div elements</div>
      <div>other div elements</div>
    </body>
    </html>
    ```
</details>

