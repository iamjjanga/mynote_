# Layout

<br>

## 1. Position 속성을 이용한 Layout

<br>

- position은 위치 값을 조정하는 데 사용하는 속성
- static
- relative
- absolute
- fixed

<br><br>

### HTML code

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
    <div>first</div>
    <div>second</div>
    <div>third</div>
    <div>fourth</div>
  </div>
</body>
</html>
```


<br>

### position:static

- static은 설정 전과 후의 값에 변동이 없다.

```css
.wrap div {
  width:100px;
  height:100px;
  border:1px solid slategray;
  margin:10px;
}

.wrap > div:nth-child(2) {
  color:red;
  position:static;
  top:40px;
  left:40px;
}
```

<details>
    <summary>output</summary>

<img src="https://lh3.googleusercontent.com/s4niUsIBJ4ZiMhhCip2LQKUOKdPwMJDf2WFyd8myDjq-ln-pPRPpVgc53bLVRfztAQ4zl8pcdrKnQE5LZgKZyOFVKVgBNsDU6Lxhqv6pL-0_oZ37MyL-cgDhHbYMZUAkFsQg1MJtB5NfGI8ONZAZ99yjZxw3gPovFe4i5w-6I9M4AVaMWNDPp9-sin_rGEQ02DOwuHv96NJiBfXJg9GQXeteiu32a-Aaxg1yrFEkYMgy5c2DBPMLsiGOLg5Hsnn1wCoqW186jgvwSkMIPFl81ViLId9Tqteu0MN5FObDhltiK-XdDkGAOzdqv9d8NlUvWJKmTiWxBPawaDHH6ZXCb52AjDV2AOEprzK5y3qAH0RQo8_UzxzNzgvUAvS8E3NNhk9RkITfYcv6ObjvtCW8pEDvD-Qfw-BVcYAVTVR5Bn1S026jZbhJfsZU8p5Tz4bskKQfkKW4lJ5tmIEoN8WKk8pJsKkqWDt7_7lehBvXHXx6VLjHh6G2fJtJvGfwZd_CB3LqVGeZY3YUTEeQE_4rsmBxQh4RVv2ImSn2xEu8FidOp-RqrTkb5G8uQaLqLMfioIcpcrDYJWyfpH9OnrGxlt5mVnSCLpJ9eV151kNEHbcobzRpEOsQEpJmu5z3AWn8cQL_ro2b7xrVdPcakxNlYObywFvOcKweBDILOZtjsNoPhtEtDhRKsas=w277-h436-no" width="200px">
</details>

<br>

### position:relative

- 위치 계산을 static의 원래위치부터 계산
- top, right, bottom, left를 설정 가능

```css
.wrap div {
  width:100px;
  height:100px;
  border:1px solid slategray;
  margin:10px;
}

.wrap > div:nth-child(2) {
  color:red;
  position:relative;
  top:40px;
  left:40px;
}

.wrap >div:nth-child(4){
  color:blue;
  position:relative;
  top:0px;
  left:0px;
}
```

<details>
    <summary>output</summary>

<img src="https://lh3.googleusercontent.com/SBJc-QwPP1R9MrzzIfuju9bkNtqwqX9sLhOLdL2HljlgqE2RfYiM44zKb5hQvgCgcu1cES-myy1XhrUpo5Drje224XBUvJrbV64J7NsOMtFcqJpZpXrkiSD6MUXaa8Xk626trx603mMLbPiREaDDBlPG0iZy4Dwga4RDHuRpVSYL0R4OLYt8MGa3mMOe7EeLcZkFr8h_8GYKeRySIsQKTEmHi3EJ7Vm2YmBCyXLuS27yAZyn3tipQqJKZFUUdzj_D-iJuVUoGIw1g2jmLdv7iK-jnwXKM5HlZ3b2xvzlKF0dfVVSkTnPCEK3gJSPhjavividN1bw63BXyFQ_mic0PXcKtV7pViyIOPdV0hJvO9WJcoFFR4nuQnqnTZXhoUkSibEVkXGWahVYO2EbHRsAMzB_oue-urX9YqlWEsqHR3RhY6qtmmJhab1IUFLoADenKXoufpJwKjOGqjnIAN3u1_PKAiYHxBMOf8drbN-nMWKvxSweZ9n95wdEXCX1B_W5D6VzcIYu6gsEJW2rSElOVeDAktbcwST7misVVfiL7YgYlbK71JxzjycbeGXInmV5GCF1FHj00NGE3Jv6t0geJqgTdGTNlNbyIXvl0nTWGY3UDjkoBLHtDcg_vzceE3B42Lw1_KNLh17SdsJh0R-FbGpHbGj1imsXvl2hkJ8ycQhuOD3ndGR3x5k=w251-h637-no" width="200px">
</details>

<br>

### position:absolute

- relative와 달리 문서의 원래 위치와 상관없이 위치를 지정할 수 있다.
- 하지만, 가장 가까운 상위 요소 (static 제외) 위치에서 결정
- 상위 요소가 없으면 html이 기준으로 설정
- top, right, bottom, left를 기준으로 설정

```css
.wrap div {
  width:100px;
  height:100px;
  border:1px solid slategray;
  position:static;
  margin:10px;
}

.wrap > div:nth-child(2) {
  color:red;
  position:absolute;
  top:40px;
  left:40px;
}

.wrap >div:nth-child(4){
  color:blue;
  position:absolute;
  top:20px;
  left:0px;
}
```

<details>
    <summary>output</summary>

<img src="https://lh3.googleusercontent.com/a1ZlFc3EprdEL2XKC4AyNe1ryB0w_RZBvNxGVXGYdRn3tDHP5G-EhzT-d5V4KRQRtNR7yac4_6Mb5yHyeU0GoOEa37PPh9jJfi1n9zOBI3QqnlUBIzA3tuIDzjx7Ajp8aQBIbOgK44uewSOG0ZzcK_y5iHZ2O39jf9lTuPybkJTsaw5DybAKMJwqUr5XsD_3_fviRVwLQdnE0eCWzKfxdS8da-p30Pi-H05R_kMCs0uiPzamT13x78MLaIlMWXeKg3LmKwCP4v7TNnCN8xM-6QRM3nmtMuXZEtq7klrIoGcYy491KVDuww_eY_cZuAoN1pDfN83QaUO0Jgq4k2rEtqki8WZmGppdNE19y-eXqhnYiaUU3RXqCZsWfl4WJ-bmAIxqxyKOhXLkWejfXJYqPtDgu1PrugbCf8vA4Pl8SHx1Y1yuIBAXEhjCSN30pRQKXzyGNXvAlRKMI2iVOAOXX3C053sEqrSNgwPv8ZafA15gOjbuUAyf_WbWZTjoFBsQBOiKTf1lSynxBXZtexNzZCJbvK7dZnqXGH5wYAijfKTK7wy2eftIzkEIwGfRB9KfkToTKKvkF19MrgJGF8Om_s1nyIP049l3OwLk45f6RAqGgFvPAfHLwWhZzTaHw4uJD-mZKJBa3bhCPlVXf158yR_6GA6fx7XNfRMEDDZl1Z8xGFbJpGLV5sM=w230-h388-no" width="200px">
</details>

<br>

### position:fixed

- fixed는 브라우저 화면의 상대 위치
- 화면이 바뀌어도 고정된 위치를 설정가능 (상위 요소 영향 x)
- Scroll시 고정적(광고 배너 등에 사용)
- **IE7, IE8은 position:fixed 값이 적용되지 않음 -> 문서 타입을 규정해주어야 한다.**

```css
.wrap {
  height:3000px;
}
.wrap div {
  width:100px;
  height:100px;
  border:1px solid slategray;
  position:static;
  margin:10px;
}

.wrap >div:nth-child(3){
  color:blue;
  position:fixed;
  top:100px;
  left:300px;
}
```

<details>
    <summary>output</summary>

<img src="https://lh3.googleusercontent.com/N_r7-94MPnR5b2GiPCO5nSc8eXGX24f3nfXqFOu4Zfr6003i29EfqyohRFqrv7EGFsuLOyARQfJMs_3NN8PBly4hUxPXNuQ4SdVL7-3f6MtYop0aCe_ix3XO46kViZwHfRBlliBuW9G0Au5LiDC84byy05d7bbIZ6b9H17pHrEnPhcTukHY8HDQQKoLdzzBTN9kx_azJaTxtwus7HYsX-EAgnktPqjPZO5pQe9JFaxGBFBthi-wP_ocN1WgaQTohHzN4ocRQCjRE_bl7QOP9A3E2zffTKrtiLv_xhyMVpdAlgvgm0S07pnZUopwEiCH5MJVmFMyOahXJQCHU2Ypmrx_brtyhtS9R6wgCvsJ2_LUbwo0xQ_VlrvBb_hQ29e79lHRKF-ChZtDasMY1mQlInmdezDdquPFzFrfD5Am2A1SiFunIIdiayOYbZSYjUXBhSrsUVPQK2svtmNMIhiFlYTGvBgIaU1-b7lppoZmV2uuLWA74kMZt6tIPbUK4lahRb1djimIl_7Rz6fz23gaVQiEeAS2HXEuze_toNJEXweiN4g0tvVzNpwQVGhIB1Ej1XoAPcwNfrnxs-ZxE6FXAuvAzhIP4tLYAlB7AqG3Jd8cGqHHy4YlkwQZmZ2B7at-aoUinNufuhA_8uxjyZIkUWnm-ReBO89mv_mG17xOxMtE5wnfwJGDQ_YM=w638-h449-no" width=400px>

</details>

<br><br>
---
<br><br>

## 2. Float기반 Layout \#1

- float는 CSS에서 **정렬**하기 위해 사용되는 속성.
- example, 문서에 사진과 그림이 있을 때, 그림을 왼쪽이나 오른쪽으로 띄워서 **정렬**하거나,
- 각 객체를 오른쪽이나 왼쪽으로 정렬하여 전체 문서를 배치할 때 도 사용

<br>

```css
.wrap > div {
  border:1px solid slategray;
  width:100px;
  height:100px;
  margin:10px;
  float:left;
}
```

<details>
    <summary>output</summary>

<img src="https://lh3.googleusercontent.com/KQQ3YEauDo-kIGJYIvTW3pWs6YDdIVw7yEv22YYsHdJOn_-YAH1y1sZngGBEVEXQ4GAAT1T4x8t8xW1FFeCoq_o-XUIWlwnXryJ2RBArhswRWeImcndnbBMelbbb8izaP_X5-_g2f6_6zlT3X8e6N4--F3JUqIgc26SqQvdwwwSS4q5E874w9DMPIcLNZjHuXlQSF174jhHhZWvvO4SyfcpxoUccfc531ZU4u0rPg04Rp5QgL6j2KiAVcYgL_RMmL4a3OXT_ZHdktAHHaYYIu6rNnhricbVIq4O7TCkY5Y9wt4qAJRUDoKmH_01KKuGesbHL_K5UAhcOIEBCl8N9lwA1UVZhWmBkm9g_qmGbQK6mVnkGd5yjPMAmuuSo2rphTJoP_aPT7mFYTPSwvug6hlcBiJ7vQ1gf_2RiOFgyQVAwHl7qa2o5MDIRE_PJaa8EE4dESUWEIYS79SljZ1rRtzp1iFtFgqXNbVq1itG6bAYD0rKfSUWOlkpal3EdveUyQ1sLF-cgh7O4RfO8KrpKBYRwnz83E-j4NcNRwFURbzKqnIeyxduE10r4WA9VYBHNhYQrI6z3QH0wWWw-qs_hyrVUmKppAUN_PH2ro94iAw8DNQJEs3YaBjvNxLeY01A7DLt843ysSTaAjfk3WApVtUXx5JW5p0WiRVMw8__yW5BVVI97mptQSNg=w500-h187-no" width=400px>

</details>

<br><br>
---
<br><br>

## 3. Float 기반 Layout \#2 - float에서 생기는 문제 해결

- clear
- overflow

<br>

### float와 overflow의 관계

- 하위 element에 float가 주었을 경우, 상위 element의 overflow에는 auto 혹은 hidden을 부여해 주어야한다.

<br>

**overflow를 통해 자식 float를 인식**

```css
.wrap {
  background-color:slategray;
  padding:0.5rem;
  width:300px;
  overflow:auto;
  box-sizing:border-box;
}

.wrap > div {
  background-color:#333;
  width:50px;
  height:50px;
  margin:0.5rem;
  color:#fff;
  float:left;
}

footer {
  width:300px;
  height:100px;
  background-color:#bb3;
  margin-top:0.5rem;
}
```

<details>
    <summary>output</summary>

<img src="https://lh3.googleusercontent.com/3LlTKUVsa3V_BkFVAA_ingsmuc0_QYfCJx7kpTXsScsnYlSVXJr8uuoCcEteYtzIhpJ3FhBZBS7bxjNwBo-UnKc9lV8vvlK_f9KL4VrwKA7uSTgB7wx9hPE_rWQCi2sq1n2c3bZ4XNfCyCA7kcwqZzF7OkHHNTMAMyWZpSfEKXJsq1zWC8F9-lyYOcSJlFUyGvEBs9PmKNe6jkM3FH2vR6qLapdqpsI_JGez6y09Y2ZwY51wVLYgrKRVUj0CB8MEQNcIwqdHT2Afr4_cGPuSgwwoBUc1f90rNqqrQPJO_zXWbsN-kdREXOgMGds3agqXDhV79rV64zv8LuVe8fC7xoYytKp9oymN5IEcj4v4D_ZSG55qmKHLpIKXNYhPj8YScMAfcVFKL10bkU3qnK93F2Kai8AeKyY6fTxgyXLckPQjvAjN-Cje6KpCpP9I_-ySEewXNxngNbt3JIDuAricinTQrnWLB16DU1H3NqV8tH5HmDLVlwvt8aab5J3PQ2alrKC2RnR7eaz-mNy601BndrvvPlLvyhgyDwZ6u6JHvRB_74M76Ui2DJFlZvCva2ZjVWV6xnnRArgNdgUBwcf6o2H2qbGHwUbHe9uyvgwnqkTH4OaW2sMqxXQ2CRE8hnUj1kIBqMVKAulyYVGkl_SuDPISgEsmnp9XEyJq8mysCpIfP4DiJKlVgIA=w573-h455-no" width=400px>
</details>


<br><br>

**footer가 wrap div하위에 들어온 경우 clear를 통한 구분**

- clear은 '취소하다'라는 뜻으로 
- clear:left = float:left된 값을 취소하고
- clear:both = float:left or float:right를 자동 인식하여 취소

```css
.wrap {
  background-color:slategray;
  padding:0.5rem;
  width:300px;
  overflow:auto;
}

.wrap > div {
  background-color:#333;
  width:50px;
  height:50px;
  margin:0.5rem;
  color:#fff;
  float:left;
}

footer {
  width:300px;
  height:100px;
  background-color:#bb3;
  margin-top:0.5rem;
  clear:both;
}
```

<details>
    <summary>output</summary>

<img src="https://lh3.googleusercontent.com/Hei9kCgOqYohX9DmdWA54Xuo86Yxv8B93DYMrbomtugiWvJrjquoLZzZytp1gxjohhUCZClFpbW3HAz6fI3wI1jcNrkAZhZMpc9weoXF66ge01YjuDKoKutvWwxbU_D7Aqvm5tIHypWkHK3pdyutiEJq5LjuIYBHP9LxOvojOS13B9jG3DWPotii77G798c2dtM2xgQh4TfAzOnb1T3z3LH6CEC0yf2Tbv8ze-38YPzGfJkVwDeRWDeqzqG5YmqOW0toZbBUkRNwoKIYnj6_MBJD0lBSFjEliavH4TQ8wqKV5u2KtsD4OkiWwme20i7xfJRWZesQ8eDOprI3snKIVPnq0HPpbERVsfXylDzlqieD8nrQ5ni3zNXYBAKAUklCfXGmEUsEFfnNZ-LBiWaIcYPBb14vjJAVdmOGm2nKwmdyAz1q2W4ZayiEqdmbGGKXHL0SdI2nFfKmDtGsr1QVugvswV2u4-kfh-7bwzpPNg0ztki2GXt8Xr-qIUZY3wIz0Kd5FqqXEpo8ZRveqnUv9vMxHjLH1c9G6jtq3lZUu9OTQYU-7gRnly7DObkc8s1lj06mzQfsRCvgPnOFyoCsztmq9C-ZUPIeKqdUK4jAgdmiDCnidp2QlV1cRDZWV1S-2ejBY8Ccd4Eas4rCpInteRvJNVIUb8uuD8tBSiFrda49YuZAWdhGoDI=w580-h437-no" width=400px>
</details>

<br><br>

> **Box-sizing?**
> 박스의 크기를 어ㄸ너 것을 기준으로 계산할지를 정하는 속성
> - content-box : content 영역을 기준으로 크기 정함
> - border-box : 테두리를 기준으로 크기를 정함
> - initial : 기본값
> - inherit : 부모 요소의 속성값을 상속 받음


<br><br>
---
<br><br>

## 4. FLEX 기반 Layout

- flex / flexbox
- layout

> [flex site link](https://css-tricks.com/snippets/css/a-guide-to-flexbox/)

<br>

**display, flex-direction, justify-content, align-items**

```css
.wrap {
  background-color:slategray;
  height:500px;
  
  display:flex;
  justify-content:center;
  flex-direction:row;
  align-items:center;
}

.wrap > div {
  width:200px;
  height:200px;
  background-color:skyblue;
  color:white;
}
```

<br>

**menu type**

```css
.wrap {
  background-color:slategray;
  height:500px;
  
  display:flex;
  justify-content:flex-end;
  flex-direction:row;
}

.wrap > div {
  height:30px;
  padding:0.5rem;
  background-color:skyblue;
  color:white;
}
```

<br>

**flex-grow**

```css
.wrap {
  background-color:slategray;
  height:500px;
  
  display:flex;
  justify-content:center;
  flex-direction:row;
  align-items:center;
}

.wrap > div {
  flex-grow:1;
  height:20px;
  padding:0.5rem;
  margin:0.2rem;
  background-color:skyblue;
  color:white;
}
```

<br><br>
---
<br><br>

## 5. z-index 속성의 이해

### Stacking context

- 자식 element들의 z-index 속성 값은 오로지 부모 안에서만 의미를 가짐
- stacking context는 부모 element의 stacking element를 구성하는 하나의 단위

<img src="https://cphinf.pstatic.net/mooc/20171226_233/1514276900770FpJG6_PNG/stacking.png" width=500px>

- 부모가 가지고 있는 z-index값의 기본 속성이 낮으면, 자식의 z-index값이 높아도 부모의 stacking order를 따른다.

<br>

**z-index example code**

```css
.wrap {
    position:relative;
    background:slategray;
}
.wrap > div {
  width:100px;
  height:100px;
  margin:0.5rem;
  color:#fff;
  position:absolute;
}

.wrap > div:nth-child(1) {
  top:10px;
  left:10px;
  background-color:red;
  z-index:1;
}

.wrap > div:nth-child(2) {
  top:50px;
  left:50px;
  background-color:green;
  z-index:999;
}

.wrap > div:nth-child(3) {
  top:90px;
  left:90px;
  background-color:blue;
  z-index:-1;
}
```

<details>
    <summary>output</summary>

<img src="https://lh3.googleusercontent.com/9XP82z2-3MYn67b85ryKcFJ55qHWtZtTC7X6OBhHe5zJg0xQ8AxMlPqeBkRChseTGePzmH6ojU6sO4Q_R8JfFQy3QUjmfu43Ri_gS4PsbfDjAwmG4MX3uIntHcjbo4i8ROtRggMLhZMhrdI212mi-XqF1iY67jsEcKdjiNxK5JRaV77c8b8MeODL8IArLFSiLkz_rtN6sBViP9WGKgLQf3mC8KPQWZNdYPaoBCRfQPK66mk9mZOXSv6ljMUK7LU0uWrL0MBcsb8JQKW9xhFtDsinf8GDARNES7DZSFNQY90aEST0wMUGmALkFx8941lSusqYWfk0YNK2X5-jgQBVuFMp9spiWHyUsUfhFkWGYvpIsCn2gw4v8T-SSvrDs8KHw3Y57vVBir9R3nb-2jyyUA5knzfnYvJNJleXAXB-pzCrBSoMpJYk9H_PawqShRQoKqq44Up8-ncIF5oeoSGEn7QudaKwVKd5kAx94e_N85R6ykJ9aSNjhvcb959HBIZr7inA8wo0zDumz3Lp1DJA3KqMSBsR3UIXnBDyb2MRvGm_uSHdOzTqqUZSwVvLEL5KHoyIdyUMw5kHwzIDwjs32io7jgyOmYX2Z50eZl9pbeoGRv2Jp52YmfkmCtl9mG2_FcyUgQE1RCVTbr9pgbq0g4Y7rYO6oQQy4f0TcBOjtaqKhQDGg8QQjfQ=w589-h496-no" width=500px>
</details>

<br>

**부모의 stacking order를 따르는 example**

```css
.wrap {
  position:relative;
  background-color:slategray;
  z-index:1;
}

.wrap > div {
  width:100px;
  height:100px;
  margin:0.5rem;
  color:#fff;
  position:absolute;
}

.wrap > div:nth-child(1) {
  top:10px;
  left:10px;
  background-color:red;
}

.wrap > div:nth-child(2) {
  top:50px;
  left:50px;
  background-color:green;
  z-index:5;
}

.wrap > div:nth-child(3) {
  top:90px;
  left:90px;
  background-color:blue;
  z-index:-1;
}

.wrap2 {
  width:100px;
  height:100px;
  margin:0.5rem;
  position:absolute;
  top:130px;
  left:130px;
  background-color:yellow;
  z-index:2;
}
```

<details>
    <summary>output</summary>

<img src="https://lh3.googleusercontent.com/NQryypW0jtwGhJ72gzu_i2O-Wg8huwlnEfy-0FLGC2DQjCYU81w-beCcj5u8p2rsAZPypfD7kGlcy1PdEbAPoLDmfotcj3urp71I9NyZPaXfMP_ova0o35Nh7tvRcsf5yC_KHGozVJEbISR9cDYeXJp58XhBB9wmOgXzHzISQL7pZGzR-TfjLNIY_7rKcjkxFhev3g4WvHQyVoV4IuQhase0ymcNnej-3fQ8mdg3VLDoq0DH4cQ25F9Ds3CUUZyYL-4pt5tkfRYRVtJ8VL_yaL7bTlVlF7qYBnPwaXx1PxF_IR_YlvUwl5ivm7ctQRswoYQuOdxvojRn0-rxKNsWwy6YIbqXyx0icEQO6ObZkGp3p7btA47fMvJDMt2I_9RD3NUULZ7qoo6QOrRfweB-b4C8f8g0gaLiFk3nxmtT7GStolg7QUvl0zCleH8DpmMrjoFcSpSAZmJUEKzot7XEzBIfKK9PC4vE0ywvT8RvBBi9ZrE97fSAz6Rx501bBjkZnpR9b_xpjiDkhOD1XyYWPfYX17PjVYGZ6T2dNTWNAosZWA8RcP-WCNKS7yIwAd0Ky28BiLBGDDzv3MeTQ7bROTl2pPzAt7DLAu92qXQAhb_pS5M_VUvTF1F7FARpEM974-7tRYq1-4oRfaGfQZxs2k4jfNREX7zmqwU_aOEKhizi25A-EfXVfek=w564-h514-no" width=500px>
<br>
second의 z-index가 5임에도 불구하고, 부모(wrap)의 z-index가 1이 wrap2의 z-index인 2보다 stacking order에 후순위라 밀림을 확인할 수 있다.

</details>

<br>