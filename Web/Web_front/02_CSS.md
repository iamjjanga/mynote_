# CSS

html문안의 표현하는 데이터와 디자인을 분리를 용이하게 해준다.

<br><br>
## 1. CSS 기본 사용법
```css
span { color : red;}
selector(선택자) { property : value; }
```

style을 HTML에 적용하는 3가지 방법

- inline (1)
- internal (2)
- external (3)

1. inline
    - HTML 태그 안에 적용
    - 2개 이상은 사용을 권장하지 않음
    - 우선순위 1
2. internal
    - style tag로 지정
    - inline보다 유지보수가 쉬우나, 전체적인 사이트 style 변경시에는 개별적 페이지에 들어가 바꿔줘야 한다는 점에서 유지보수가 어려움
    - 별도의 CSS파일을 관리 안해도 됨
    - 서버에 CSS파일을 부르기 위해 별도의 브라우저의 요청을 보낼 필요가 없음
3. external
    - 외부파일(.css)로 지정

<details>
    <summary>html</summary>

    ```html
    <!DOCTYPE html>
    <html>
    <head>
      <meta charset="utf-8">
      <meta name="viewport" content="width=device-width">
      <!-- external -->
      <link rel="stylesheet" type="text/css" href="mystyle.css">
      <!-- internal -->
      <style>
      div > p {
        font-szie:20px;
      };</style>
      <title>JS Bin</title>
    </head>
    <body>
       <div>
         <!-- inline -->
         <p style="color:blue;">Lorem ipsum dolor sit amet, consectetur adipisicing elit. Sapiente magnam accusamus excepturi, sunt sit dolorum consequatur eaque labore cum aliquam incidunt, alias aut omnis veritatis. Dignissimos facilis sed vero placeat!</p>
       </div>
    </body>
    </html>
    ```
</details>

<details>
    <summary>CSS</summary>

    ```css
    div>p {
      color:red;
      border:1px solid slategray;
    }
    ```
</details>

<br><br><br><br>

## 2. CSS에서의 상속 개념

상위에 설정된 style을 하위에서도 사용

<details>
    <summary>deep inheritance</summary>

    ```html
    <!DOCTYPE html>
    <html>
    <head>
      <meta charset="utf-8">
      <meta name="viewport" content="width=device-width">
      <title>JS Bin</title>
      <!-- body아래 div아래 ul아래 li아래 div아래 p의 색을 blue로-->
      <style>
      body div ul li div p{
        color:blue;
      }</style>
    </head>
    <body>
      <div>
        <span>my text is upper!</span>
        <ul>
          <li>
            <span>my text is dummy!</span>
            <div>
              <p>
                Lorem ipsum dolor sit amet, consectetur adipisicing elit. Sed cum maiores fugit voluptas praesentium adipisci esse velit nesciunt commodi culpa. Ullam dolorum labore maxime voluptates quam, sed voluptatum reprehenderit qui.
              </p>
            </div>
          </li>
        <li></li>
        </ul>
      </div>
    </body>
    </html>
    ```
</details>

<details>
    <summary>shallow inheritance</summary>

    ```html
    <!DOCTYPE html>
    <html>
    <head>
      <meta charset="utf-8">
      <meta name="viewport" content="width=device-width">
      <title>JS Bin</title>
      
      <style>
      body > div {
        color : green;
        font-size : 20px;
        /* 배치에 관련된 값들은 상속에 영향을 받지 않는다. */
        border : 2px solid slategray;
        padding : 30px;
      }</style>
    </head>
    <body>
      <div>
        <span>my text is upper!</span>
        <ul>
          <li>
            <span>my text is dummy!</span>
            <div>
              <p>
                Lorem ipsum dolor sit amet, consectetur adipisicing elit. Sed cum maiores fugit voluptas praesentium adipisci esse velit nesciunt commodi culpa. Ullam dolorum labore maxime voluptates quam, sed voluptatum reprehenderit qui.
              </p>
            </div>
          </li>
        <li></li>
        </ul>
      </div>
    </body>
    </html>
    ```
</details>

<br><br><br><br>

## 3. Cascading - computed style이 결정되는 방식

- CSS는 Cascading Style Sheets의 약자
- 하나의 태그에 여러가지 방법으로 동일한 속성의 스타일을 적용하는 경우, **우선순위(경쟁)**에 따라서 적용될 스타일이 결정
    - 경쟁 : 똑같은 속성을 CSS파일 혹은 inline으로 정의를 중복으로 한 경우, 다른 selector을 사용하였지만 결국 같은 필드를 가리키는 경우 어떤 스타일을 브라우저가 반영하는가?
- 한 요소에 여러 가지 선언이 이루어지는 경우 충돌을 피할 수 있게끔 computed style이 결정되는 방식에 대해 고민해야함

<br><br>
#### 3-1. 선언방식에 따른 차이

inline > internal > external
<br><br>

#### 3-2. 동일하면 나중에 것 우선

```css
span {
    color : red;
}

span {
    color : blue;
}
```

<details>
    <summary>output</summary>

<span style="color:blue; font-size:30px;">blue</span>
</details>

<br><br>
#### 3-3. 구체적으로 표현된 것 우선

```css
body > span {
    color : red;
}

span {
    color : blue;
}
```
<details>
    <summary>output</summary>

<span style="color:red; font-size:30px;">red</span>
</details>

<br><br>

#### 3-4. id > class > element

```html
<div id="a" class="b"> text... </div>
```

```css
#a {
    color:red;
}
.b {
    color:blue;
}
div {
    color:green;
}
```

<details>
    <summary>output</summary>

<span style="color:red; font-size:30px;">red</span>
</details>

> 경쟁 점수 확인 : css specificity

<br><br><br><br>

## 4. Selector를 활용한 DOM 검색

<br><br>
### CSS Selector
- HTML의 요소룰 tag, id, html 태그 속성 등을 통해 쉽게 찾아주는 방법

<br><br>

### element에 style 지정을 위한 3가지 기본 선택자

1. tag로 지정


```css
<style>
    span{
        color:red;
    }
</style>
```
<br><br>
2. id로 지정

```css
<style>
    #spantag {
        color:red;
    }
</style>

<body>
    <span id="spantag">Hello world!</span>
</body>
```

<details>
    <summary>output</summary>

<span style="color:red; font-size:30px;">Hello world!(red)</span>
</details>

<br><br>
3. class로 지정

```css
<style>
    .spanClass{
        color:red;
    }
</style>

<body>
    <span class="spanClass">Hello world!</span>
</body>
```

<details>
    <summary>output</summary>

<span style="color:red; font-size:30px;">Hello world!(red)</span>
</details>

<br><br><br>
### CSS Selector의 다양한 활용

- id, class 요소 선택자와 함께 활용

```css
#myid {color:red}
div.myclassname{color:red}
```

<br><br><br>

- group 선택

```css
h1, span, div {color:red}
h1, span, div#id {color:red}
h1.span, div.classname {color:red}
```

<br><br>

- 요소 선택 (공백) - 자손요소

```html
<div id="jisu">
    <div>
        <span> span tag in</span>
    </div>
    <span> span tag out</span>
</div>
```

```css
#jisu span {color:red;}
```

<details>
    <summary>output</summary>

<span style="color:red; font-size:30px;">span tag in(red)</span><br>
<span style="color:red; font-size:30px;">span tag out(red)</span>
</details>

<br><br>

- 자식 선텍(>)

```html
<div id="jisu">
    <div>
        <span> span tag in</span>
    </div>
    <span> span tag out</span>
</div>
```

```css
#jisu > span {color:red;}
```

<details>
    <summary>output</summary>

<span style="color:black; font-size:30px;">span tag in</span><br>
<span style="color:red; font-size:30px;">span tag out(red)</span>
</details>


<br><br>

- n번째 자식요소를 선택(nth-child)

```html
<div id="jisu">
    <h2>단락 선택</h2>
    <p>첫번째 단락입니다.</p>
    <p>두번째 단락입니다.</p>
    <p>세번째 단락입니다.</p>
    <p>네번째 단락입니다.</p>
  </div>
```

```css
#jisu > p:nth-child(2) {color:red;}
```

<details>
    <summary>output</summary>

<span>단락 선택</span><br>
<span style="color:red">첫번째 단락입니다.(red)</span><br>
<span>두번째 단락입니다.</span><br>
<span>세번째 단락입니다.</span><br>
<span>네번째 단락입니다.</span>
</details>
