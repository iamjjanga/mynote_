# CSS animation

<br>

## 1. transition을 이용한 CSS 기본 애니메이션

box element를 CSS 속성을 변경하여 애니메이션 (속도 등)을 조절하고 싶은 경우 **transition**을 이용한다.

> [CSS transition](https://developer.mozilla.org/ko/docs/Web/CSS/CSS_Transitions/Using_CSS_transitions)


<details>
    <summary>HTML</summary>

```html
<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width">
  <title>JS Bin</title>
</head>
<body>
  <div class="box">
    box!
  </div>
</body>
</html>
```
</details>

CSS
```css
.box {
  width:100px;
  height:100px;
  background-color:slategray;
  color:#fff;
  text-align:center;
  line-height:100px;
  transition: all 1s, easy-in;
}
```

JavaScript
```javascript
var box = document.querySelector(".box");
box.addEventListener("click", function(evt){
  evt.target.style.height = "200px";
  evt.target.style.width = "200px";
});
```

<br><br><br>

## 2. transform 속성 활용

transform을 이용해서 element를 변형 시킬 수 있다.
transform은 좌표공간을 변형함으로써, 다른 element에 영향을 미치지 않고 특정 element의 위치를 바꿀 수 있다.

<br>

### CSS 성능

**transform**은 빠르게 browser rendering을 처리할 수 있는 대표적이다.

- transform(GPU 가속) > position > float (-> burden이 높다)
- translate : translate3d(x,y,z) > translateX(x)

<br><br>

<img src="https://lh3.googleusercontent.com/L9xyWx0d4M5IY4mG3_vGC15FQVGE9X8OB3MhuMvRXYyZDV5hoOvdu_Whk3pYDBSOtNPmbt0XZ5cvquoqvd6L6KFOOJ71L8YjP-xghRkv2dx5JhwDAdFLiev9K6msEWufcC0dSK7euNuFamXx7Bgc8stx-4t74ssXBA5QroYXK8z_iGhy8i5kFAq1Lls9FjZlK7JVu_MPo8i6JewJqV8_amRQEU6wbEflZAvnSDfB8j9lMSM2iiwmK_eGrrs1Y6pQ_4SG8Mubu5mIidDgh8FtkdHGOteOB_fqklgW-AsuSI0482Q3XALbcWRvX2mwgBGw9eeRMRFxQnWypfzicSSEvNPMqNwERJedHYThD5TujA1fZE2ykHHMAeJs8AIZJgyqTwazGxTWIAhobwSG5x9zGL8kY_wYy-lEuZD1avF9usWC1IF1b6TlRdAmor3nDA_otIYeWRO87iaXMhfbGHibWLedlDDGT4AW9KQKEII-EXwGQR4gtUhByze4NJ-IlXdH22b6X7wFzGrdD27ot9kXkNmiTlvWIX6rNLBGm7kh35yM5plymHL8OejlZW4c2Rwiz-J1oUASNaYZajugNM50BfXLURCslI05sfiH2my0QyUsl2trQDGha1d61C0WXFLPfBtLdS9sCsQSf9aGLDJQlvVz2zsZwmY47Ll1oEQmWuwLzJWYY2E3LlE=w506-h217-no" width=500px>

<br>

<details>
    <summary>HTML</summary>

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
    <div class="box">box1</div>
    <div class="box">box2</div>
    <div class="box">box3</div>
  </div>
</body>
</html>
```
</details>

position을 이용

```css
.wrap{
  position:relative;
}

.box{
  width:100px; height:100px;
  background-color:slategray;
  color:#fff;
  text-align:center;
  line-height:100px;
  position:absolute;
  top:0px;
  left:0px;
}

.box:nth-child(2){
  left:100px;
}

.box:nth-child(3){
  left:200px;
}
```

<br>

transform을 이용

```css
.wrap{
  position:relative;
}

.box{
  width:100px; height:100px;
  background-color:slategray;
  color:#fff;
  text-align:center;
  line-height:100px;
  position:absolute;
}

.box:nth-child(2){
  transform:translateX(100px);
  /* or transfor:translate3d(100px,0,0); */
}

.box:nth-child(3){
  transform:translateX(200px);
  /* or transfor:translate3d(200px,0,0); */
}
```