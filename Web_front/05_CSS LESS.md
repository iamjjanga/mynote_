# CSS(LESS)

<br>

## CSS언어의 아쉬운 점
1. varibles
- 변수라고 할 것들이 없다.

2. mixin
- 이미 선언된 클래스를 재활용해서 사용

3. 충첩된 rule 처리
- code가 function화 되지 않는다.

4. operation

<br>

=> 이러한 문제점을 **LESS**를 이용하면 **Programming적인** 작성이 가능해진다.

> LESS는 CSS에서 공식적인 지원 X
> 나중에는 우리가 알고 있는 CSS로 변환 후 브라우저로 배포해야함

<br>

**variable, mixin, nasted rule**

```html
<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width">
  <title>JS Bin</title>
</head>
<body>
  <div class="wrap">
    <h3>Hello world</h3>
    <div class="content">
      <ul>
        <li><a href="">한국일보</a></li>
        <li><a href="">조선일보</a></li>
        <li><a href="">매일경제</a></li>
        <li><a href="">스포츠조선</a></li>
      </ul>
    </div>
  </div>
  
  <footer>
    <ul>
      <li><a href="">새로운뉴스</a></li>
      <li><a href="">이전뉴스</a></li>
      <li><a href="">인기뉴스</a></li>
    </ul>
  </footer>
</body>
</html>
```

<br>

less code
```
@base_width:400px;
@base_height:400px;
@gray_border:1px solid gray;
@base_text_color:#5d1;

.wrap {
  width:@base_width;
  height:@base_height;
  border:@gray_border;
  padding:1rem;
  > h3 {
    text-align:center;
  }
}

.content {
  width:200px;
  height:@base_height/4;
  border:@gray_border;
  margin:0px auto;
  li {
    list-style:none;
    a {
      color:@base_text_color;
    }
  }
}

footer {
  li {
    color:red;
  }
  ul {
    .content;
    margin-top:12px;
  }
}
```

<br><br><br>

## LESS Compile

<br>

- LESS는 browser가 CSS로 인식을 못하기 때문에 CSS로 인식해주기 위한 Preprocessor(전처리기)의 처리과정인 compile이 필요하다.

> less compile를 설치하기 위해서는 Winodws의 Shell 환경 및 Node.js의 환경 구축이 먼저 구축 되어있어야함.

<br>

### install
1. Node.js 다운 및 `node -v`로 version확인하기 (안정화된 version install)
<br>

2. current directory path를 working directory로 이동 후 `npm install -g less`로 node상 less를 설치
<br>

3. `lessc [option option-parameter ...] <source> destination`으로 compile하고 html link값을 생성된 .css 파일인지 확인하기

<details>
    <summary>main.html</summary>

```html
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width">
    <title>less test</title>
    <link rel="stylesheet" href="main.css">
</head>
<body>
    <div class="wrap">
    <h3>Hello world</h3>
    <div class="content">
        <ul>
        <li><a href="">한국일보</a></li>
        <li><a href="">조선일보</a></li>
        <li><a href="">매일경제</a></li>
        <li><a href="">스포츠조선</a></li>
        </ul>
    </div>
    </div>      
    <footer>
    <ul>
        <li><a href="">새로운뉴스</a></li>
        <li><a href="">이전뉴스</a></li>
        <li><a href="">인기뉴스</a></li>
    </ul>
    </footer>
</body>
</html>
```
</details>

<details>
    <summary>main.less</summary>

```
@base_width:400px;
@base_height:400px;
@gray_border:1px solid gray;
@base_text_color:#5d1;

.wrap {
  width:@base_width;
  height:@base_height;
  border:@gray_border;
  margin:0px auto;
  padding:1rem;
  > h3 {
    text-align:center;
  }
}

.content {
  width:200px;
  height:100px;
  border:@gray_border;
  margin:0px auto;
  li {
    list-style:none;
    a {
      color:@base_text_color;
    }
  }
}

footer {
  li {
    color:red;
  }
  ul {
    .content;
    margin-top:12px;
  }
}
```
</details>

변환 후
<details>
    <summary>main.css</summary>
```css
.wrap {
  width: 400px;
  height: 400px;
  border: 1px solid gray;
  margin: 0px auto;
  padding: 1rem;
}
.wrap > h3 {
  text-align: center;
}
.content {
  width: 200px;
  height: 100px;
  border: 1px solid gray;
  margin: 0px auto;
}
.content li {
  list-style: none;
}
.content li a {
  color: #5d1;
}
footer li {
  color: red;
}
footer ul {
  width: 200px;
  height: 100px;
  border: 1px solid gray;
  margin: 0px auto;
  margin-top: 12px;
}
footer ul li {
  list-style: none;
}
footer ul li a {
  color: #5d1;
}
```
</details>