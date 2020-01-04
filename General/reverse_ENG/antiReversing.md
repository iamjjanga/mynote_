### 디버거 vs 디버기?

- 디버거 : 디버그를 하는쪽
- 디버기 : 디버깅을 당하는 쪽

program (*)<---debug--- Ollydbg <br>
		ㄴ-> 디버그 port를 열어 디버그를 하는거(processDebugPort(7번))

<br><br>

## 프로그램 분석

- ### OutputDebugString

LastError
- CPU에 내장
- 함수가 실패한 이유를 내장함.
- 마지막 실패 이유

  - debug mode

  ```
  SetLastError();			// 0x29a
  OutputDebugString();	// 성공
  GetLastError();			// 0x29a
  ```

  SetLastError의 return과 GetLastError의 return이 같다. => 디버그 모드이다.("Debugger Detected")

  - real mode

  ```
  SetLastError();			// 0x29a
  OutputDebugString();	// 실패
  GetLastError();			// !0x29a
  ```

  SetLastError의 return과 GetLastError의 return이 다르다. => 디버그 모드가 아니다.("No Debugger Detected")

- ### FindWindow

  - 현재 실행중인 창에 Ollydbg가 있는지를 검사한다.
  - 만약에 없다면 Windbg까지 debuger가 있는지 검사를 하고 종료.
  - 오류, 05.FindWindow를 실행하는 Ollydbg가 아닌 다른 실행파일을 debuging중인 Ollydbg가 작동을 해도 정상적인 debuger window를 찾았다고 알린다.

- ### AntiQuiz1

  - 각 문자열 breakpoint 걸어두고
  - FindWindow의 Ollydbg값
  - 해결
    - 1. findWindow의 OllyDbg의 unicode값을 변경한다.
    - 2. 다른 값을 조작한다.

<br><br>

## MFC로 만들어진 프로그램 분석법

1. MFC 라이브러리 정보를 Ollydbg에 알려주기
	- debug
	- select import libraries
	- add
	- 경로('c-program files-microsoft Visual Studio-VC98-MFC-Lib')
	- process버튼클릭
	- Ollydbg 재시작
	
2. MFC, windows는 event기반으로 동작한다.
	- 시작
	- 프로그램
	- microsoft visual studio
	- 도구들
	- (측정하고자 하는 프로그램을 먼저 키고나서)
	- spy++
	- 프로그램명 찾기("AntiQuiz1") -> 2개버튼 확인(start, exit)
	- Control ID 확인 -> 000003E8
	
3. MFC Message Map
```
struct AFX_MSGMAP_ENTRY
{
	UINT nMessage;   // windows message
	UINT nCode;      // control code or WM_NOTIFY code
	UINT nID;        // control ID (or 0 for windows messages)				// Control ID
	UINT nLastID;    // used for entries specifying a range of control id's	// Control ID
	UINT nSig;       // signature type (action) or pointer to message #		// 4Byte 건너뛰고
	AFX_PMSG pfn;    // routine to call (or special value)					// 이 함수가 수행할려는 기능
};
```

spy++을 통해 찾은 Control ID로 MFC Message Map을 다음과 같이 분석할 수 있다.

<img src="https://lh3.googleusercontent.com/j4U7MMSiMWFIL5rZGhWXV3fg0VvIdgCdmdJ5CzruEnJpjjDCBAHVjy4L7mFy7QeEUFm3VHnRxODrtJNdLTEryfa0t-_Zhm4ZzMdt7aMRYiyueWcbI8_CYeo4Xm9upwEsctAtsHgPDmGhD8gsCXYI9U8t2EUTj2J1CZaJ2Rn1eNBbjWz1Qg3T6uDXtyDc97ufp9WJI_OB-PyqHHaMKyhohfXw0z6hAXDlqAtutkqqtO7zYnV7ZXwreosrcuHwhfath7EC2iTHtvtWLeQtTl_eAJpugV7k_UJChprN19IcCwCUtL9oqJ5gqK7XeZX1NELZ_EpiIOkI8d6DSVqlAqCzj2dvS5C_n_RcnaxXsTNr09SZnPPCiRg4x-D3G0yDraHzGZvBYlo4RhPYGzpxh7KqVA0zQP0I-eQMSt3N7etbfhb_oCFiiK6so88EJ4fdaDk-pBI-hlujqxh171WRgtHnQHtnTQcT5C5YYDeQUN70psWsfhYs44avQPZ7kIHF9PEX0-x6Fb2-R3tsYobWLrtAVTBD0mRM2-8Fqjiv7aUtJP_TLQOKqSXhrtYhN6-PtbPAtdIon1-dlszyaOi47NSp63yJXhOt9qlnF9YSX6R-jLyYAOrnLdoComyRrpS57KF-zw_34harJb0NlvJFp1yZFPuJbi7XQG3YDP_YeKjEIu2zTimQCQPbjso=w958-h491-no" width-300px />

<br><br>

- ### Registry

  - "Open with OllyDbg"로 registry를 이용하기 때문에 실행을 하면 OllyDbg debuger가 감지된다고 뜬다.
  - 대부분 "Reg..."로 시작하는 함수들을 사용
  - Reg정보를 읽어와서
  
  > Registry 위키에 검색해서 내용 파악

  **Registry?**
  - Window상 설정정보를 모아둔 데이터베이스
  - key:value의 쌍
  - 최상위 root key 5개 존재
  
 <br>
 
 - ### NtSetInformationThread
 
  - thread의 우선순위 루틴을 설정한다.
  - 현재 process를 OllyDbg에서 떼어내고 숨긴다.(17번)
  - 해결 : `ThreadInformationClass`값을 `ThreadHideFromDebugger`에서 다른 값으로 변경한다.
  

- ### OllyDGOutputDebugString

  - 사용중인 OllyDbg가 뻗는다.
  - 해결 : OutputDebugString에 %s서식을 OllyDbg가 출력할려고 하면 뻗어서 이를 바꿔주면 된다.


- ### OllyDbgStaticString
  - 현재 사용중인 process를 열거해준다.
  - 성공시 0이 아닌값
  - 실패시 0(GetLastError)
  - 현재 사용중인 Process 목록중에 OllyDbg가 있으면 정상동작 하지 않을 것이다.
  - OllyDbg가 실행중이면 `4B064B`의 고유한 ASCII값을 가져 이를 debug으로 찾아서 판단한다.
  - 해결 : `4B064B`의 값을 변경한다.
  
  <br>
  
  - ### 12.quiz2
  1. 먼저 registry함수를 분석
  2. aeDebuger는 system에 제일 처음 설치한 debuger
  3. NtSetInformation 우선순위 루틴과 OllyDbg 뻗는 해결법을 사용한다.
  
