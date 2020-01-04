# HTML
HTML(Hyper Text Markup Language)

## 1. 기본형태
```
	HTML
		head
		body
```

html, css, javascript를 바로 테스트 해볼 수 있는 사이트

> jsbin.com

<br><br><br><br><br>


## 2. tag의 종류
태그는 그 의미에 맞춰서 사용해야 함

- link
- image
- list
- title

> google에서 html tag list로 w3school에서 원하는 정보 찾기

<details>
	<summary>toggle code</summary>

	<p>
    ```html
    <!DOCTYPE html>
    <html>
    <head>
      <meta charset="utf-8">
      <meta name="viewport" content="width=device-width">
      <title>JS Bin</title>
    </head>
    <body>
      <div>
        <h1>반갑습니다.</h1>
        여기 여러분들이 좋아하는 과일이 있어요.
        <ul>
          <li><a href="https://www.apple.com">사과</a></li>
          <li>바나나</li>
          <li>메론</li>
          <li>귤</li>
      	</ul>
      </div>
    </body>
    </html>
    ```
    </p>
</details>

<br><br><br><br><br>

## 3. Layout을 위한 tag

Layout은 화면을 구성하는 기본적인 모습

- header
- section
- nav
- footer
- aside

##### Layout을 설명하는 image

<img src="http://cfile240.uf.daum.net/image/27788F3E5518F13033C3D0" width="300px"/>


<details>
    <summary>toggle code</summary>

    ```html
    <!DOCTYPE html>
    <html>
    <head>
      <meta charset="utf-8">
      <meta name="viewport" content="width=device-width">
      <title>JS Bin</title>
    </head>
    <body>
      <header>header</header>
      <div id="container">
        <nav><ul>
          <li>home</li>
          <li>news</li>
          <li>sports</li>
        </ul></nav>
        <aside><ul>
          <li>로그아웃</li>
          <li>오늘의 날씨</li>
          <li>운세</li>
        </ul></aside>
      </div>
      <footer>footer</footer>
    </body>
    </html>
    ```
</details>

<br><br><br><br><br>

## 4. html 구조화 설계(html structure design)


- html5의 template는 이전 버전과 비교하면 매우 간소화되었다.

- 기존 `<div>`태그만 사용했다면, 이제는 구조화를 위한 다양한 요소들이 세분화되면서 등장
- 구조화를 통해 특정 의미를 가진 요소를 사용하여 웹 문서 안에 있는 문장의 의미를 명확하게 나타낸다.

<img src="https://i.imgur.com/xsQJ6YJ.png" alt="A canonical page design and major page elements" width="700px" />

<details>
    <summary>toggle code</summary>

    ```html
    <!DOCTYPE html>
    <html>
    <head>
      <meta charset="utf-8">
      <meta name="viewport" content="width=device-width">
      <title>JS Bin</title>
    </head>
    <body>
      <header>
      <h1>Company Name</h1>
        <img src="..." alt="logo">
      </header>
      
      <section>
        <nav><ul>
          <li>Home</li>
          <li>Home</li>
          <li>About</li>
          <li>Map</li>
        </ul></nav>
      
        <section>
          <button></button>
          <div><img src="dd" alt=""></div>
          <div><img src="dd" alt=""></div>
          <div><img src="dd" alt=""></div>
          <button></button>
        </section>
        <section>
          <ul>
            <li>
              <h3>What we do</h3>
              <div>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Accusamus vel possimus est nam consectetur facilis assumenda distinctio ex, nulla aut rerum unde. Molestiae dolor tempore aperiam, accusantium at quis voluptatem.</div>
            </li>
            <li>
              <h3>What we do</h3>
              <div>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Accusamus vel possimus est nam consectetur facilis assumenda distinctio ex, nulla aut rerum unde. Molestiae dolor tempore aperiam, accusantium at quis voluptatem.</div>
            </li>
            <li>
              <h3>What we do</h3>
              <div>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Accusamus vel possimus est nam consectetur facilis assumenda distinctio ex, nulla aut rerum unde. Molestiae dolor tempore aperiam, accusantium at quis voluptatem.</div>
            </li>
          </ul>
        </section>
      </section>
      <footer>
        <span>Copyright @codesquad</span>
      </footer>
    </body>
    </html>
    ```
</details>

<br><br><br><br><br>


## 5. html 속성

##### id
- 고유한 속성으로 한 HTML문서에 하나만 사용 가능
- 고유한 ID값이 있으면 하나하나에 특별한 제어를 할 수 있으며 검색에도 용이

##### class
- 하나의 HTML문서안에 중복해서 사용 가능
- 홈페이지 전체적인 스타일을 일관성 있게 지정하기 위해서는 class의 사용이 필수적

<details>
    <summary>toogle code</summary>

    ```html
    <!DOCTYPE html>
    <html>
    <head>
      <meta charset="utf-8">
      <meta name="viewport" content="width=device-width">
      <title>JS Bin</title>
    </head>
    <body>
      <header>
      <h1>Company Name</h1>
        <img src="..." alt="logo">
      </header>
      
      <section>
        <nav><ul>
          <li>Home</li>
          <li>Home</li>
          <li>About</li>
          <li>Map</li>
        </ul></nav>
      
        <section id="nav-section">
          <button></button>
          <div><img src="dd" alt=""></div>
          <div><img src="dd" alt=""></div>
          <div><img src="dd" alt=""></div>
          <button></button>
        </section>
        <section id="roll-section">
          <ul>
            <li class="our_description">
              <h3>What we do</h3>
              <div>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Accusamus vel possimus est nam consectetur facilis assumenda distinctio ex, nulla aut rerum unde. Molestiae dolor tempore aperiam, accusantium at quis voluptatem.</div>
            </li>
            <li class="our_description">
              <h3>What we do</h3>
              <div>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Accusamus vel possimus est nam consectetur facilis assumenda distinctio ex, nulla aut rerum unde. Molestiae dolor tempore aperiam, accusantium at quis voluptatem.</div>
            </li>
            <li class="our_description">
              <h3>What we do</h3>
              <div>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Accusamus vel possimus est nam consectetur facilis assumenda distinctio ex, nulla aut rerum unde. Molestiae dolor tempore aperiam, accusantium at quis voluptatem.</div>
            </li>
          </ul>
        </section>
      </section>
      <footer>
        <span>Copyright @codesquad</span>
      </footer>
    </body>
    </html>
    ```
</details>

<br><br><br><br><br>


## 6. 개발자도구(Elements tab)을 활용한 HTML CSS 디버깅

웹 프로그래밍을 할 때면 개발자도구(Elements tab)을 활용한 HTML, CSS 디버깅이 큰 역할을 한다.

F12를 누르고, 각 element의 size와 value들을 CSS style항목에서 임시로 변경해 보거나, Computed 항목에서 적용된 value의 값들을 확인할 수 있다.

