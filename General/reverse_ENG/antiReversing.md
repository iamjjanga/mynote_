# Anti-Reversing
## Anti-Reversing?
Anti-Reversing은 Anti-Debugging으로 reverse engineering을 통한 debugging의 접근을 막는것이다.

<br>

## 디버거 vs 디버기?

- 디버거 : 디버그를 하는쪽
- 디버기 : 디버깅을 당하는 쪽

program (*)<---debug--- Ollydbg <br>
		ㄴ-> 디버그 port를 열어 디버그를 하는거(processDebugPort(7번))

<br><br>

## 프로그램 분석

### 4. OutputDebugString

**LastError**
- CPU에 내장
- 함수가 실패한 이유를 내장함.
- 마지막 실패 이유

#### 4-1. debug mode

 ```
 SetLastError();		// 0x29a
 OutputDebugString();	// 성공
 GetLastError();		// 0x29a
 ```

SetLastError의 return과 GetLastError의 return이 같다. => 디버그 모드이다.("Debugger Detected")

#### 4-2. real mode

```
SetLastError();		// 0x29a
OutputDebugString();	// 실패
GetLastError();		// !0x29a
```

SetLastError의 return과 GetLastError의 return이 다르다. => 디버그 모드가 아니다.("No Debugger Detected")

### 5. FindWindow

- 현재 실행중인 창에 Ollydbg가 있는지를 검사한다.
- 만약에 없다면 Windbg까지 debuger가 있는지 검사를 하고 종료.
- 오류, 05.FindWindow를 실행하는 Ollydbg가 아닌 다른 실행파일을 debuging중인 Ollydbg가 작동을 해도 정상적인 debuger window를 찾았다고 알린다.

### 6. AntiQuiz1

- 각 문자열 breakpoint 걸어두고
- FindWindow의 Ollydbg값
- 해결
  - 1. findWindow의 OllyDbg의 unicode값을 변경한다.
  - 2. 다른 값을 조작한다.

<br><br>

#### 6-1. MFC로 만들어진 프로그램 분석법

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

<img src="https://lh3.googleusercontent.com/Be3PgLZd65LtBvQw9WJm78ddlTWPeV3ryBxrap6O6s5zo4Tc0VeDzSBS1_6annCUNtds0c8HykfC5uRN62b2-kkaGpy78SFTej9bb78Na0tGoBY4nHq7Bji9ZhKIsL6pw2xaEZa5qe_k0Qxq8WQAh7JQGTybvbp7PEWHaQ6sJN9ouRSWTzZ94frQeDLC9dOD2eIBZ_b4Qs8d7IF8Zcxq_3aJO6g5Fy0Zd8XUVG281fnj6wqU_dciC6W_tmyuWjV8x1hrbS6mQBoi_iGNQ3UShmh2HigCSTFRL8Owd92WUEAUn7YIBEAJqX0po4mAWsvvwsKyvtCLQHTRgyhRKvSldynWB18uP0B7FboHWQa0zmzkzce6kydgz9sI3OWcEtNiGdBesa7iYJh6fsq47TcMbfII7JmVFfDwAbH9V_k-rY0XbJoZj7qZkkdZZwdD9GB3dFeTP_pgnTvCSjhu9cDPSzTon_CtbMgHfH-8UhP2VS3AOTdCvoOct9ovDS2GEg7dySmuKNBuqkaXK65g5Pk0E98S1d-o3eOmKSKRoNCann_goUq9KQ4pnJ-Ry35jmOnxw7nmWSxCZjdcm7e9TVYUC1u8rGn-pH8FOJ8SImz7sRWIiAml7bCZApECvJeSGAFzU7zmhuJM2OwVsr-AWZc294dg-40v_aau-nn_mAvbRZ8ejsBuy7qKk2nUnjcPRtEdD98RdhlZv_Clu6jG6qVAGgWJkVJWtx-A2KNRB0a0Bf9ZcPR8=w1829-h937-no" width-300px />

<br><br>

### 7. Registry

- "Open with OllyDbg"로 registry를 이용하기 때문에 실행을 하면 OllyDbg debuger가 감지된다고 뜬다.
- 대부분 "Reg..."로 시작하는 함수들을 사용
- Reg정보를 읽어와서
  
> Registry 위키에 검색해서 내용 파악

- **Registry?**
	- Window상 설정정보를 모아둔 데이터베이스
	- key:value의 쌍
	- 최상위 root key 5개 존재
  
 <br>
 
 ### 8. NtSetInformationThread
 
- thread의 우선순위 루틴을 설정한다.
- 현재 process를 OllyDbg에서 떼어내고 숨긴다.(17번)
- 해결 : `ThreadInformationClass`값을 `ThreadHideFromDebugger`에서 다른 값으로 변경한다.
  

### 9. OllyDGOutputDebugString

- 사용중인 OllyDbg가 뻗는다.
- 해결 : OutputDebugString에 %s서식을 OllyDbg가 출력할려고 하면 뻗어서 이를 바꿔주면 된다.


### 10. OllyDbgStaticString
- 현재 사용중인 process를 열거해준다.
- 성공시 0이 아닌값
- 실패시 0(GetLastError)
- 현재 사용중인 Process 목록중에 OllyDbg가 있으면 정상동작 하지 않을 것이다.
- OllyDbg가 실행중이면 `4B064B`의 고유한 ASCII값을 가져 이를 debug으로 찾아서 판단한다.
- 해결 : `4B064B`의 값을 변경한다.
  
<br>
  
### 12. quiz2
  1. 먼저 registry함수를 분석
  2. aeDebuger는 system에 제일 처음 설치한 debuger
  3. NtSetInformation 우선순위 루틴과 OllyDbg 뻗는 해결법을 사용한다.
  
### 13. IsDebuggerPresendt-DirectPEB
 
<details>
    <summary>TEB.txt</summary>

```
  ntdll!_TEB
   +0x000 NtTib            : _NT_TIB
      +0x000 ExceptionList    : 0x0012fd0c _EXCEPTION_REGISTRATION_RECORD
      +0x004 StackBase        : 0x00130000 Void
      +0x008 StackLimit       : 0x0012e000 Void
      +0x00c SubSystemTib     : (null) 
      +0x010 FiberData        : 0x00001e00 Void
      +0x010 Version          : 0x1e00
      +0x014 ArbitraryUserPointer : (null) 
      +0x018 Self             : 0x7ffdf000 _NT_TIB ************ TEB 자기자신
   +0x01c EnvironmentPointer : (null) 
   +0x020 ClientId         : _CLIENT_ID
      +0x000 UniqueProcess    : 0x000003fc Void
      +0x004 UniqueThread     : 0x0000028c Void
   +0x028 ActiveRpcHandle  : (null) 
   +0x02c ThreadLocalStoragePointer : (null) 
   *************************************************************여기부터 PEB
   +0x030 ProcessEnvironmentBlock : 0x7ffd8000 _PEB
      +0x000 InheritedAddressSpace : 0 ''
      +0x001 ReadImageFileExecOptions : 0 ''
      +0x002 BeingDebugged    : 0x1 ''
      +0x003 SpareBool        : 0 ''
      +0x004 Mutant           : 0xffffffff Void
      +0x008 ImageBaseAddress : 0x00400000 Void
      +0x00c Ldr              : 0x00251ea0 _PEB_LDR_DATA
      +0x010 ProcessParameters : 0x00020000 _RTL_USER_PROCESS_PARAMETERS
      +0x014 SubSystemData    : (null) 
      +0x018 ProcessHeap      : 0x00150000 Void
      +0x01c FastPebLock      : 0x7c9ad600 _RTL_CRITICAL_SECTION
	 +0x000 DebugInfo        : 0x7c9ab500 _RTL_CRITICAL_SECTION_DEBUG
	 +0x004 LockCount        : 0n-1
	 +0x008 RecursionCount   : 0n0
	 +0x00c OwningThread     : (null) 
	 +0x010 LockSemaphore    : (null) 
	 +0x014 SpinCount        : 0
      +0x020 FastPebLockRoutine : 0x7c931000 Void
      +0x024 FastPebUnlockRoutine : 0x7c9310e0 Void
      +0x028 EnvironmentUpdateCount : 1
      +0x02c KernelCallbackTable : (null) 
      +0x030 SystemReserved   : [1] 0
      +0x034 AtlThunkSListPtr32 : 0
      +0x038 FreeList         : (null) 
      +0x03c TlsExpansionCounter : 0
      +0x040 TlsBitmap        : 0x7c9ad5c0 Void
      +0x044 TlsBitmapBits    : [2] 1
      +0x04c ReadOnlySharedMemoryBase : 0x7f6f0000 Void
      +0x050 ReadOnlySharedMemoryHeap : 0x7f6f0000 Void
      +0x054 ReadOnlyStaticServerData : 0x7f6f0688  -> (null) 
      +0x058 AnsiCodePageData : 0x7ffa0000 Void
      +0x05c OemCodePageData  : 0x7ffa0000 Void
      +0x060 UnicodeCaseTableData : 0x7ffd1000 Void
      +0x064 NumberOfProcessors : 1
      +0x068 NtGlobalFlag     : 0x70		*******************************<- 0이면 Real mode & !0 debug mode
      +0x070 CriticalSectionTimeout : _LARGE_INTEGER 0xffffe86d`079b8000
	 +0x000 LowPart          : 0x79b8000
	 +0x004 HighPart         : 0n-6035
	 +0x000 u                : __unnamed
	 +0x000 QuadPart         : 0n-25920000000000
      +0x078 HeapSegmentReserve : 0x100000
      +0x07c HeapSegmentCommit : 0x2000
      +0x080 HeapDeCommitTotalFreeThreshold : 0x10000
      +0x084 HeapDeCommitFreeBlockThreshold : 0x1000
      +0x088 NumberOfHeaps    : 3
      +0x08c MaximumNumberOfHeaps : 0x10
      +0x090 ProcessHeaps     : 0x7c9acfc0  -> 0x00150000 Void
      +0x094 GdiSharedHandleTable : (null) 
      +0x098 ProcessStarterHelper : (null) 
      +0x09c GdiDCAttributeList : 0
      +0x0a0 LoaderLock       : 0x7c9ab178 Void
      +0x0a4 OSMajorVersion   : 5
      +0x0a8 OSMinorVersion   : 1
      +0x0ac OSBuildNumber    : 0xa28
      +0x0ae OSCSDVersion     : 0x300
      +0x0b0 OSPlatformId     : 2
      +0x0b4 ImageSubsystem   : 3
      +0x0b8 ImageSubsystemMajorVersion : 5
      +0x0bc ImageSubsystemMinorVersion : 0
      +0x0c0 ImageProcessAffinityMask : 0
      +0x0c4 GdiHandleBuffer  : [34] 0
      +0x14c PostProcessInitRoutine : (null) 
      +0x150 TlsExpansionBitmap : 0x7c9ad5b8 Void
      +0x154 TlsExpansionBitmapBits : [32] 0
      +0x1d4 SessionId        : 0
      +0x1d8 AppCompatFlags   : _ULARGE_INTEGER 0x0
      +0x1e0 AppCompatFlagsUser : _ULARGE_INTEGER 0x0
      +0x1e8 pShimData        : (null) 
      +0x1ec AppCompatInfo    : (null) 
      +0x1f0 CSDVersion       : _UNICODE_STRING "Service Pack 3"
      +0x1f8 ActivationContextData : 0x00140000 Void
      +0x1fc ProcessAssemblyStorageMap : 0x001529b8 Void
      +0x200 SystemDefaultActivationContextData : 0x00130000 Void
      +0x204 SystemAssemblyStorageMap : (null) 
      +0x208 MinimumStackCommit : 0
   *************************************************여기까지 PEB
   +0x034 LastErrorValue   : 0
   +0x038 CountOfOwnedCriticalSections : 0
  ```
  </details>
  
  <br><br>
  
  ### 13-1. process 구조체
  
  - #### TEB ( Thread Environment Block )
	  - TEB가 PEB가는 방법을 알려줌
	  - fs:[0] -> TEB : fs의 0번째 인덱스는 TEB
	  - TEB + 0x18 -> Self : TEB 자기자신을 가리킴
	  - TEB + 0x30 -> PEB : TEB구조체 안에서 0x30만큼 떨어진 곳에 PEB
	  - 들여쓰기 된만큼에 PEB
  
  - #### PEB ( Process Environment Block )
  	  - PEB + 0x002 BeingDebugged  : 1값이면 debugging당함, 0이면 debugging 당하지 않음
  
  ### 13-2. isDebuggerPresent 우회 
  1. fs:[30]을 통해 값을 직접 찾아가서 변경
  2. LoadLibraryW에서 시작해서 <br>
  	-> GetprocAddress <br>
	-> GetCurrntProcessId <br>
	-> OpenProcess분석하고 <br>
	-> NtQueryInformationProcess의 0번째 즉, `ProcessBasicInforamtion`의 2번째 멤버변수(8B)인 PEB를 `EBP-20`의 값에 저장  <br>
	-> ECX (=EBP-20) + 2인지점, 즉 begingdebugged의 값이 0인지 아닌지 확인한다.
	
  ### 15.isDebuggerPresent1
  - 맨위로 올라가보면 30만큼 이동후 EAX + 2이동하여 isbeingDebug로
  - 현재 이 코드는 Assembly 언어를 통해 사용자가 강제로 isDebuggerPresent를 코드로 작성한 예제이다.
  
  ### 16. NTGlobalFlag
  - 현재 작동 중인 mode가 `real mode`이지 `debug mode`인지를 나타내주는 PEB구조체 값이다.
  - PEB + 0x068에 위치
  	- real mode == 0
	- debug mode != 0
	
  ### 18. ProcessHeapFlag
  - PEB 구조체로 부터 `0x018`, `0x090` ProcessHeaps를 따라서 주소를 찾아 Heap 구조체를 찾아보면
  - Heap 구조체의 아래 2개의 flag들을 통해 antiReversing을 할 수 있다.
  	- \+ `0x00c` Flags : (R) 00000002
	- \+ `0x010` ForceFlags : (R) 00000000
	> (R) = real mode

  ### 20. RDTSC ( 시간 탐지 기법 )
  ```
  (time1)
  (operation)
  (time2)
  ```
  - 어떤 작업하기 전 time1 측정, 작업 후 time2 측정
  - time2 - time1해서 시간 차가 크게 나면 debug 사용임을 감지
  - 우회법
  	- 1. RDTSC 코드를 debug 후 한번더 time1에서 다시 내려오는 JMP표현
	- 2. (time2 - time1)의 차를 조정
	
  ### 21. INT3
  - INT3(Interrupt3) : User level Interrupt = breakpoint
  - INT3는 debug mode에서만 사용된다. (real mode에서 사용하면 error)
  	- 임의의 program에서 처음 실행의 binary code 처음 1Byte를 `CC`로 변경 후 저장하고 실행
	- Error 확인
	
  ```c
  int main(void) {
  	int n1, n2;
	int result;
	scanf("%d", &n1);
	scanf("%d", &n2);		// divided by zero
	result = n1 / n2;
  }
  ```
  
  - runtime 중 Exception(예외) -> Exception handle(예외 처리)
  	- 있음 -> runtime 유지
	- 없음 -> runtime error
	
  ```
  try {
  	__asm {
			INT3
	}
  } catch, except, exception ...() {
  	(예외 처리)	
  }
  ```
  - 우회
  	- 1. `Shift + F9`를 누르면 예외를 처리하지 않고 무시하고 진행한다.
	- 2. Debugging options에 Exception tab에 예외 처리를 따로 체크한다.
	
  ### Self-Debugging
  - `self-debugging`이 시작하고 자기 자신을 하나 더(`self-debugging'`) 실행한다. 
  - `self'`이 `self`를 debug(`DebugActiveProcess`)한다.
  - 규칙
  	- `debuggee`는 `debugger`를 하나만 둘 수 있다.
	
  #### Self-Debugging 우회
  - 1. 일부러 error를 만든다. (실행 처음에 E8값을 CC로 변경하여 강제로 `INT3`를 준다)
  - 2. 변경 내용을 저장한다. (다른이름으로 저장이 아닌 Overwrite해서)
  - 3. 실행을 해서 `디버그`버튼을 누르면 VS로 연동된다. 다시 OllyDbg오 연동하기 위해서는 OllyDbg를 다시 키고 `Debug`-`Just-in-time debugging`옵션에서 `Make OllyDbg just-in-time debugger`를 활성화한다.
  - 4. 다시 CC의 값을 E8로 변경하고, CreateProcess에 breakpoint를 걸고 실행
  - 5. `F8`로 프로시저단위 디버깅을 하면 사본이 생성된다.
  - 6. 사본에서 다시 CC를 E8로 변경하고 `DebugActiveProcess`에 breakpoint를 걸어준다.
  
  ### Olly Advanced
  - Anti Reversing을 하기 위한 우회를 도와주는 라이브러리이다.
  - 포함된 2개의 file을 OllyDbg가 설치된 경로의 plugin directory(ex. `C:\odbg110\plugin`)로 복사
  - 과정
  	- 1. OllyDbg 실행 후
	- 2. `Plugins`-`options`-`Anti-Debug2`에 `isDebuggerPresent`항목 체크 후 다시 실행
  	- 3. 우회된 것 확인
  > 도구를 사용해서 하는 것이 더 좋을 수 도 있음. 코드를 해결하기 보다는 **코드 분석에 초점**을 맞춰야 한다.
  
  ### AntiQuiz3
  - MFC를 통해 event처리를 하는 code지만 event보다는 도달하는 과정에서 막힘을 인지한다.
  - OnInitDialog가 main역할을 한다.
  	- 하위에 `GetSystemMenu`, `LoadString`, `IsEmpty` ...이 나오는걸 확인하고
	- 여기서 막히는 부분은 //TODO에 있는 `AntiDebug1-4()`부분이다.
	- `AntiDebug1-3`은 위의 방식과 비슷하나, `AntiDebug4()`에서 조금 막힌다.
	- PBE + 0x0c부분은 LDR_DATA이다. 
	- LDR은 동적할당을 확정적으로 한다. 이 프로그램의 debug 모드에서 컴파일러가 동적메모리임을 인식하기 위해서 `0xEEFEEEFE`를 맨 마지막에 넣는다.
	```cpp
	__try {
		while (*ldr_module != 0xEEFEEEFE) {
			printf("Value at pointer: %08X\n", *ldr_module);
			walk = walk +0x01;
			ldr_module = (const DWORD *)walk;
		}

	}
	__except (EXCEPTION_EXECUTE_HANDLER) {
		flag = 1;
	}
	```
	- 위의 코드로 무한루프를 통해 예외를 발생하면서 동적메모리를 인식하기 위해 넣은 `0xEEFEEEFE`를 인식한다.
	- 우회법
		- 1. 가장쉬운법은 `AntiDebugger1-4`를 호출하지 않는다. ( 밀어버림 )
		
