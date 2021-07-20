1.1 Definitions of operating system

* 컴퓨터 시스템의 구성요소

하드웨어 : 기본 리소스를 제공한다.
 Ex) CPU, I/O device, memory

2. OS(operating system) : CPU를 효율적으로 돌리기 위해 많은 어플리케이션에게 리소스를 적합하게 줌으로서 통제하고 관리한다.

3. Application Programs : 사용자의 목적을 달성하기 위한 프로그램들
 Ex) 워드프로세서, 스프레드시트, 컴파일러, 웹브라우저 등등


4. User



OS는 무엇인가?

컴퓨터의 하드웨어를 관리해주는 프로그램이다.
하드웨어와 어플리케이션 사이에서 중개자
 = 하드웨어(CPU)의 효율적 이용을 위해 만들어졌다.
OS = Kernel + additional programs(system program)


* 커널(kernel)은 운영 체제의 핵심 부분으로서, 운영 체제의 다른 부분 및 응용 프로그램 수행에 필요한 여러 가지 서비스를 제공한다. 컴퓨터가 켜진 순간 항상 커널은 작동한다.

System program : OS와는 관련이 있지만 커널에 필수적인 부분은 아닌 프로그램
application programs : OS와 전혀 관련 없는 프로그램









OS는 무엇을 하는가? (System View)

1. Control Program : 오류를 방지하고 프로그램을 통제한다.
 = 프로그램 하나가 잘못되어 일부나 다른 전체를 망칠 때 통제를 한다. 
Ex) 블루스크린

2. Resource allocator: 시스템리소스 관리, 하드웨어와 어플리케이션 사이에서 중개자
 = 한정된 CPU의 리소스를 많은 프로그램이 동시에 접근한다면, 충돌과 보안에서의 문제가 생길 것이므로 그것을 프로그램의 순서와 메모리 공간을 고려해 할당해주는 역할을 한다. 즉, 하드웨어(CPU)의 효율적 이용을 위해 만들어졌다.

3. Providing environment: 자신 자체로는 아무 것도 하지 않지만, 사용자가 뭘 할 때 쉽게 해준다.



OS의 존재 이유(목적)는 무엇인가?

- Execute user programs and make solving user problems easier.
- Make the computer system convenient to use.
- Use the computer hardware in an efficient manner







1.2 computer system organization and operation

computer system organization


옛날 버전






Common bus: 컴퓨터 간에 데이터를 전송하는 하위 시스템 구성 요소들
CPU, 메모리, device controller 모두 Common Bus에 연결되어 있다.
I/O devices와 CPU를 동시에 실행 할 수 있다.
매우 간단하고 경제적이다.
각각의 장치는 local buffer를 가지고 있다.
Computer System operation

OS는 어떻게 작동하는가?

컴퓨터를 키면 
Bootstrap program (firmware)이 실행된다.
 firmware(하드웨어를 동작시키기 위한 소프트웨어ROM, EEPROM) 체크
 CPU의 레지스터부터 device controller, 메모리까지 모두 검사한다.
 오류가 없으면 Bootstrap loader가 하드웨어의 첫 번째 섹터에서 OS커널을 불러와서 메모리에 올려 실행한다. 
cf> 메모리에 올려서 실행하는 것은 CPU의 일인데 어떻게 Bootstrap Loader가 할 수 있나요?
사실 Bootstrap loader는 그것이 OS인 줄 모르고, 약속한 장소에서만나는 것이다.

2. OS

 Unix에선 init라는 프로세스를 시작하고 다른 프로세스들을 시작합니다.
 그리고 이벤트를 기다리고 이벤트가 발생하면 처리한다.
Ex)이벤트: 키보드, 마우스 클릭
=
 Modern operating systems are
 interrupt driven programs



Interrupt: 주의를 끌기 위해 하드웨어나 소프트웨어에서 나오는 예측 불가능한 신호

별도의 코드들이 각 유형의 인터럽트에 대해 취해야 할 조치를 결정합니다.
각 유형의 표 : interrupt vector


















H/W interrupt: Sending signal to CPU
S/W interrupt: System call(=Moniter call), Ex) I/O access, memory allocation
Excetption Ex) Divide by zero, invalid memory aceess,

Interrupt Mechanism

Ex) Scanf함수 호출 (CPU는 다른 일을 하는 중) -> 키 입력(이벤트 발생) -> Interrupt(CPU에게 알림) -> Key buffer에 저장 -> CPU가 처리
Interrupt가 발생하면 CPU가 잠깐 하던걸 멈추고 그 일을 봐준다.
























CPU가 지금 하는 일을 멈추고 interrupt handler(interrupt vector)를 실행
인터럽트는 어떤 handler랑 일치함으로써 그  handler로 처리된다.
Storage Structure





registers: CPU속에 있는 연산을 위한 조그마한 메모리 , buffer
cache: 추후 설명
I/O Structure


Old System: Busty waiting (No Interrupt)

Busy waiting: CPU가 장치 상태를 계속 확인하고 있어야 한다.
 = CPU가 오직 I/O 디바이스만 기다린다 
= 다른일을 할 수 가 없다. = 느리다.





Modern systems
 1. Interrupt-driven I/O



CPU가 컨트롤러한테 요청을 보낸다.
I/O 요청이 완료되면 interrupt로 CPU에게 알린다.
This form of interrupt-driven I/O is fine for moving small amounts of data
but can produce high overhead when used for bulk data movement such as disk
I/O. To solve this problem, direct memory access (DMA) is used











2. DMA(Direct memory Access)
After setting up buffers, pointers, and counters for the I/O device, the device controller transfers an entire block of data directly to or from its own buffer storage to memory, with no intervention by the CPU.

CPU가 다른 일을 할 수 있고, 그만큼 성능이 향상된다.


1.3 Computer system architecture

single-processor systems

Computer 1대 – CPU 1개
싸고, 간단하다, User를 위한 프로세스라기보단 특수한 목적을 가진 디바이스를 위한 것


2. Multi-processor Systems (Multi-core, parallel systems)

Computer 1대 – CPU 여러 개

 - Symmetric multiprocessing (SMP) : All processors are peers




Asymmetric multiprocessing : Master-slave relation
  master schedules and allocates the slaves.

일정시간에 할 수 있는 처리량이 증가한다.
안정성이 증가한다.
메모리와 주변기기를 공유하기 때문에 경제성이 있다.


3. Clustered Systems

Computer 여러 대 – CPU 여러 개

- SAN(storage-area network)를 통해 저장 공간을 공유한다.
- High-availability : 여러 대의 컴퓨터가 있기 때문에 한 컴퓨터가 죽어도 나머지로 버팀
- 고성능
 *DLM(Distributed lock manger): 여러대의 컴퓨터가 같은 데이터를 수정하는 것을 방지


1.4 Operating System Structure

옛날엔 CPU와 I/O 디바이스의 용량이 작아서 최대한 저 둘을 바쁘게 쓰려는 의도에서 만들어진 구조이다. 그러다가 효율적으로 쓰는 방향을 개선해 나갔다.


Multiprogramming

멀티프로그래밍은 CPU의 사용률을 job scheduling을 통해 높혔다. 하지만 메인 메모리는 모든 job들을 수용하기엔 너무 작아서 처음엔 job pool에다가 저장을 했다. 이 풀은 디스크에 위치하며 메인 메모리로 올라가기 기다리는 모든 job의 저장소 이다.

자발적으로 어쩌다 한번 job switching
Cpu가 한번에 하나의 job을 처리한다.







Multitasking(Timesharing)

Cpu가 한 번에 여러 개의 job을 처리한다.

job들을 빠르게 자주 바꿔줌으로써 사용자가 각각의 프로그램이랑 interact할 수 있게 해준다.
response time < 1sec.
CPU scheduler가 준비된 job을 선택한다.
 cpu scheduler: cpu time를 배분해주는 모듈
      =다음 job은 무엇인가?




Virtual Memory
메인 메모리가 부족해 physical disk를 메모리처럼 쓰는 것

만약 
하얀 동그라미를 호출하면 빠르게 디스크에서 하얀 동그라미를 메모리로 올린다.










Dual mode operation

여러 프로세스들이 메모리를 공유하기 때문에 한 프로세스가 모두를 해칠 수 있다. 
-> 중요한 명령어를 따로 구분을 해 두었다.

user mode (mode bit=1): 
previlieged instructions 같은 다른 시스템에 해를 끼질 수 있는 코드 사용 불가
Ex) I/O instruction, timer instruction


kernel mode (mode bit=0):=supervisor mode, system mode, privileged mode
OS code, privileged instructions 허용


cf> Function call을 사용하지 않는 이유?
Function call을 사용하면 mode bit가 바뀌지 않아 OS MODE에 진입할 수가 없다.

cf> 어떻게 OS모드를 신뢰할 수 있는가?
Interrupt는 os를 통해 cpu가 처리하고 그 처리기준은 interrupt vector이다. interrupt vector는 kernel에 의해 보증되었기 때문에 kernel모드를 신뢰할 수 있는 것이다.



* Time interrupt

한 프로그램이 너무 많은 실행 시간을 가지고 있으면 강제로 메모리를 회수하는 것





1.5 Core Components of OS

Process management

① Process: 실행중인 프로그램 (active entity)
Ex) Job, time-shared program
두 프로세스가 동일한 프로그램에서 나왔다고 해도 개별 실행 시퀸스로 간주한다.

program counter (PC, 레지스터 안에 있다) 
 sequence of machine instruction를 찾아준다.
  (=specifying the next instruction to execute)

 - 리소스를 필요로 한다.
 - 시스템을 구성하고 있는 유닛 
    system code를 실행시키는 OS 프로세스 =  + user code를 실행시키는 User 프로세스)




② Thread: 프로그램 수행 시 프로세스 내부에 존재하는 수행 경로, 일련의 실행 코드
 한 프로세스에서 여러 갈래로 나뉘는 일
(프로세스는 껍데기일뿐, 실제 작업은 쓰레드가 담당한다.)

 - 각각의 쓰레드는 아이디, PC, 레지스터 셋, 스택 등을 각각 가지고 있다.
 - 한 프로세서에서 메모리를 공유한다. (= 리소스가 공유되는 수행 경로)

Cf> Single-thread, Multi-thread
 - 싱글 쓰레드 프로세스는 하나의 프로그램 카운터를 가진다.
 - 멀티쓰레드 프로세스는 여러개의 프로그램 카운터를 가진다. 
    멀티쓰레딩 : 하나의 프로세스 내에서 다수의 스레드가 동시에 수행되는 것


③ Task: address space를 통한 수행 경로
 = 리소스가 공유되지 않는 다른 일
 Cf> Linux에선 프로세스인지 쓰레드인지 테스크인지 구별이 안된다.

 


• Scheduling processes and threads on the CPUs
• Creating and deleting both user and system processes
• Suspending and resuming processes
• Providing mechanisms for process synchronization
• Providing mechanisms for process communication










Process Management


Creation / deletion process
 ID/ Memory / process control block(PCB)를 OS kernel이 만들어 준다. like 학적부

2. Suspending / resuming process
3. Terminate process






2. Process synchronization


다른 프로세스가 같은 리소스를 요청할 때 
교통정리를 하는 것










3. Process communication

원칙 상으로는 한 프로세스가 다른 프로세스에 간섭을 하지 못한다. 왜냐하면 프로세스가 서로를 죽일 수 있기 때문이다. 하지만 OS가 둘 사이를 연결해 전화의 형식으로 소통하게 해준다.






4. Dead lock Handling

 프로세스 A가 a라는 자원을 점유하고 있으며, 프로세스 B가 b라는 자원을 점유하고 있다. 이때 추가적인 작업을 위해 프로세스 A가 b 자원을 요청하고 프로세스 B가 a 자원을 요청하는 경우, 각 자원이 다른 프로세스에 의해 사용중이므로 해제가 될 때까지 대기하게 된다. 이런 경우 서로 자원을 해제할 때까지 무한히 대기하게 된다. 이것을 데드락이라고 한다.
2. Memory Management

Memory Management
: 현대 컴퓨터 시스템의 운영에 있어 핵심적인 부분
메인 메모리는 크기가 수십에서 수십억에 이르는 큰 바이트 배열
각각의 바이트는 고유의 주소를 갖는다.
CPU 및 I/O장치에 의해 공유된 빠르게 액세스 할 수 있는 데이터 저장소

The operating system is responsible for the following activities in connection
with memory management:
• Keeping track of which parts of memory are currently being used and who
is using them
• Deciding which processes (or parts of processes) and data to move into
and out of memory
• Allocating and deallocating memory space as needed


3. Storage Management

① File-System Management by Os
- Physical storage: magnetic disk, optical disk, magnetic tape....
- File: logical storage unit abstracted by OS

• Creating and deleting files
• Creating and deleting directories to organize files
• Supporting primitives for manipulating files and directories
• Mapping files onto secondary storage
• Backing up files on stable (nonvolatile) storage media


② Device Driver
Device driver vs Device controller
③  Mass-Storage Management


메인메모리는 
1. 모든 데이터와 프로그램을 수용하기는 너무나 작다.
2. 휘발성 메모리이기 때문에 전원이 나가면 모두 지워진다.
-> 두 번째 저장 공간의 필요

• Free-space management
• Storage allocation
• Disk scheduling

④ Caching

cache: 
사용된 정보를 다음 액세스를 위한 작고 빠른 저장소에 있는 사용된 정보의 일시적 복사본


locality of reference: 뭘 불러오면 향후에 그것을 불러올 확률이 높다.

As it is used, it is copied into a faster storage system—the cache—on a
temporary basis. When we need a particular piece of information, we first
check whether it is in the cache. If it is, we use the information directly from
the cache. If it is not, we use the information from the source, putting a copy
in the cache under the assumption that we will need it again soon.


cf. Main memory can be viewed as a cache for secondary
memory.


※ Cache coherency

한 번에 한 프로세스만 돌아가는 싱글프로세스 환경에서는 어떤 자료에 대한 엑세스는 항상 계층 구조의 최상위 레벨에 복사본이기 때문에 A에 대한 접근은 문제가 없다.
하지만 다음 그림과 같은 멀티태스킹 환경에서는 A에 대한 엑세스의 관리가 매우 중요하다. 
여러 프로세스가 A에 엑세스 하려고하면 이러한 각 프로세스는 가장 최근에 업데이트 된 A값을 얻는다.
이 상황은 내부 레지스터를 유지하는 멀티프로세스 환경에서는 더욱더 복잡해진다. 각각의 CPU들은 local cache를 포함하고 있어 A의 사본이 동수에 여러 캐시에 존재하는 것이다. 여러 CPU들이 동시에 캐시를 실행할 수 있기 때문에, 한 캐시의 A값에 대한 업데이트가 A가 있는 다른 모든 캐시에 즉시 반영되는지 확인해야한다. 이 상황을 cache coherency라고 하고 하드웨어 이슈(OS시스템 레벨 아래서 다루는 문제이다.







⑤ I/O Systems

OS의 목적 중 하나는 특정 하드웨어 장치의 특성을 사용자로부터 숨기는 것이다.

예를 들어, 유닉스에서는 I/O장치 특성을 I/O장치 하위 시스템에 의해 운영 체제 자체의 대부분에서 숨겨진다.

I/O의 하위 시스템의 구성 요소

• 버퍼링, 캐싱, 스풀링을 포함하는 메모리 관리 요소
• 디바이스 드라이버 인터페이스
• 구체적 하드웨어 장치를 위한 드라이버 

=> 오직 디바이스 드라이버만 특정 드라이버가 어디 할당되어 있는지, 특성이 무엇인지 안다. 


4. Protection and Security

Protection: 리소스마다 이름을 붙여 나 아니면 사용하지 못하게 하는 것
Security: 내 비밀번호를 훔쳐가지 못하게 하는 것
2.1 Operating System Service

Service For User
UI 
– CLI(커맨드라인 인터페이스)
- batch Interface: 명령을 제어하는 명령과 지시문을 파일에 입력하고 해당 파일을 실행
- GUI(Graphic User Interface)

• Program execution
• I/O operations. 프로세스는 I/O가 필요한데 효율과 안정성을 위해 유저가 직접 I/O장치에 엑세스할 수 없게 만들고 OS를 통해 대신 제공하게 했다.A running program may require I/O, 

• File-system manipulation. The file system is of particular interest. Obviously,
programs need to read and write files and directories. 
They also need to create and delete them by name, search for a given file, and
list file information. 
Finally, some operating systems include permissions
management to allow or deny access to files or directories based on file
ownership. 
Many operating systems provide a variety of file systems,
sometimes to allow personal choice and sometimes to provide specific
features or performance characteristics.

• Error detection. 
• Communications. 프로세스 간의 정보공유통신, 사전 정의된 형식의 정보 패킷이 운영체제에 의해 프로세스간 이동

Functions for efficient operation of system itself

• Resource allocation. 
- 여러 프로세스가 돌아갈 때 메모리의 할당
- determining how best to use the CPU, operating systems have CPU-scheduling routines that take into account the speed of the CPU, the jobs that must be executed, the number of registers available, and other factors. There may also be routines to allocate printers, USB storage drives, and other peripheral devices.

• Accounting. 우리가 어떻게 또는 얼마나 리소스를 사용하는지 파악하고 저장한다.  

• Protection and security.

User and Operating-System Interface

One provides a command-line interface, or command interpreter, that allows users
to directly enter commands to be performed by the operating system. 
The other allows users to interface with the operating system via a graphical user
interface, or GUI.

2.2.1 Command Interpreters
Some operating systems include the command interpreter in the kernel. 

CI의 주 기능은 유저의 구체적인 커맨드를 받아서 실행하는 것이다. 여러 개의 커맨드들은 다음과 같은 파일 관리요청을 수행할 수 있어야 한다. (create, delete, list print, copy, execute..)

The MS-DOS and UNIX shells operate in this way. These commands can be implemented in two general ways.

첫 번째 방법은 CI 스스로가 커맨드를 실행할 코드를 포함하는 것이다. 예를 들어 삭제를 명령 할 때 CI는 매개 변수를 설정하고 적절한 시스템 호출으로 하는 코드의 섹션으로 점프합니다.
이 경우에는 각각의 명령들은 자체 구현코드가 필요하기 때문에 CI의 크기가 결정될 수 있다.

두 번째 방법은 유닉스에서 쓰이는 방법인데, 명령 실행은 시스템 프로그램에 의해 결정되는 경우이다. 이 상황에서는 CI는 어떤 식으로든 명령을 이해하지 못하고 단지 명령을 사용하여 메모리에 로드되어 실행될 파일을 식별한다.
예를 들어, 유닉스 명령인 rm a.txt를 사용할 때, rm라는 파일을 호출하고 메모리에 올리고 rm의 매개변수 a.txt를 설정하고 실행합니다. 즉 rm명령과 관련된 기능은 파일 rm의 코드에 의해 완전히 정의되는 것이다.
이 경우 프로그래머들은 적절한 이름으로 새로운 파일을 만듬으로서 쉽게 새로운 명령을 추가할 수 있다. 
The command-interpreter program, which can be small, does not have to be changed for new commands to be added.

2.2.2 Graphical User Interfaces

a mouse-based window and-menu system characterized by a desktop metaphor.

The user moves the mouse to position its pointer on images, or icons, on the screen (the desktop) that represent programs, files, directories, and system functions. Depending on the mouse pointer’s location, clicking a button on the mouse can invoke a program, select a file or directory—known as a folder—or pull down a menu that contains commands.

Xerox Alto computer (1973)
 Apple Macintosh (1980s)
 MS-Windows
 Desktops based on X-window (CDE, KDE, GNOME)
 3D desktop (XGL, SphereXP, …)




System Calls (=Interrupt)

인터럽트를 통해 사용할 수있는 OS 커널 함수 호출
낮은 privileged mode에서 더 높은 privileged mode로 제어를 안전하게 전송하는 메커니즘



시스템 호출은 운영 체제에서 사용할 수 있는 서비스에 대한 인터페이스를 제공합니다. 또한 시스템 콜은 low-level 언어(c,c++ 혹은 머신랭귀지)로 작성된 루틴으로 사용할 수 있다. (그래야 직접적으로 하드웨어에 접근할 수 있기 때문이다.)




Parameter Passing in System Call
내부적으로, 시스템 콜은 인터럽트를 통해 서비스된다.
추가 정보가 필요할 수 있는데 그 때, 정보를 3가지 방법으로 옮긴다.

1. The simplest approach is to pass the parameters in registers. In some cases,
however, there may be more parameters than registers. 

2. In these cases, the parameters are generally stored in a block, or table, in memory, and the address of the block is passed as a parameter in a register (Figure 2.7). This is the approach taken by Linux and Solaris. Parameters also can be placed, or pushed, onto the stack by the program and popped off the stack by the operating system. 

3. Some operating systems prefer the block or stack method because those approaches do not limit the number or length of parameters being passed.









As you can see, even simple programs may make heavy use of the
operating system. Frequently, systems execute thousands of system calls
per second. Most programmers never see this level of detail, however.
Typically, application developers design programs according to an application
programming interface (API). The API specifies a set of functions that are
available to an application programmer, including the parameters that are
passed to each function and the return values the programmer can expect.



System call interface

많은 프로그래밍 언어에서, runtime support system (컴파일러에 포함 된 라이브러리에 내장 된 함수)은 운영 체제에서 사용할 수 있는 시스템 호출에 대한 링크로 사용되는 시스템 호출 인터페이스를 제공합니다. 

- 시스템 호출 인터페이스는 API에서 함수 호출을 받아 운영 체제 내에서 필요한 시스템 호출을 호출합니다. 

- 전형적으로, 숫자는 각 시스템 호출과 연관되며 시스템 호출 인터페이스는 이 숫자에 따라 색인화 된 테이블을 유지 관리합니다.

- 시스템 호출 인터페이스는 운영 체제 커널에서 원하는 시스템 호출을 호출하고 시스템 호출 및 모든 반환 값의 상태를 반환합니다.

- The caller need know nothing about how the system call is implemented
or what it does during execution. 
Rather, the caller need only obey the API and understand what the operating system will do as a result of the execution of that system call. 

Thus, most of the details of the operating-system interface are hidden from the programmer by the API and are managed by the run-time support library. 


Example of system-call interface in Linux



%eax: 레지스터의 이름
movl 5: 이것을 레지스터에 넣는다.
int$0x80: interrupt 번호(system call number) -> Handler(vector) -> Os kernel, 
이것은 privilige instruction이 아니다. user모드에서 도는 명렁어이다.


What does system-call interface do?
 Passing information to the kernel
 Switch to kernel mode
 Any data processing and preparation for execution in kernel mode


Cf> system call vs I/O functions in programming language
fopen() // open()
 - fopen: C에서 정의된 표준함수 (호환성이 높다.)
 - open: OS에서 제공되는 advanced feature
fopen ()는 open ()를 사용하여 구현됩니다.
Application Programming Interface

API: system call을 조합해서 덩어리가 된 것들

Three of the most common APIs available to application programmers are
1.the Windows API for Windows systems, 
2. the POSIX API for POSIX-based systems
(which include virtually all versions of UNIX, Linux, and Mac OS X), 
하도 기관마다 지들끼리 만드는 유닉스가 많아서 유닉스의 기준을 만든 것이 POSIX이다. 
POSIX는 유닉스의 표준으로 필수 SYSTEM CALL이 있다.
Ex) open, close, read, write, fork, kill, wait
3. Java API for programs that run on the Java virtual machine. 

프로그래머는 운영 체제에서 제공하는 코드 라이브러리를 통해 API에 액세스합니다. UNIX 및 Linux의 경우 C 언어로 작성된 프로그램의 경우 라이브러리는 ibc입니다.
그의 텍스트에서 사용 된 시스템 호출 이름은 일반적인 예입니다. 각 운영 체제에는 각 시스템 호출마다 고유 한 이름이 있습니다. 일반적으로 API를 구성하는 함수는 응용 프로그램 프로그래머를 대신하여 실제 시스템 호출을 호출합니다.

 For example, the Windows function CreateProcess() (which unsurprisingly is used to create a new process) actually invokes the NTCreateProcess() system call in the
Windows kernel.

Why would an application programmer prefer programming according to
an API rather than invoking actual system calls? There are several reasons for
doing so. 
One benefit concerns program portability. An application programmer designing a program using an API can expect her program to compile and run on any system that supports the same API (although, in reality, architectural differences often make this more difficult than it may appear). 

더군다나, 실제 시스템 호출은 응용 프로그램 프로그래머가 사용할 수있는 API보다 더 상세하고 작업하기가 어려울 수 있습니다. 그럼에도 불구하고 API의 함수와 커널 내의 연관된 시스템 호출 간에는 강한 상관 관계가 존재하는 경우가 종종 있습니다 실제로 POSIX 및 Windows API의 대부분은 UNIX, Linux 및 Windows 운영 체제에서 제공하는 기본 시스템 호출과 유사합니다.


The relationship between an API, the system-call interface, and the operating system is shown in Figure 2.6, which illustrates how the operating system handles a user application invoking the open() system call.
Type of System Calls
System calls can be grouped roughly into six major categories: process
control, file manipulation, device manipulation, information maintenance,
communications, and protection. In Sections 2.4.1 through 2.4.6, we briefly
discuss the types of system calls that may be provided by an operating system.
Most of these system calls support, or are supported by, concepts and functions
that are discussed in later chapters. Figure 2.8 summarizes the types of system
calls normally provided by an operating system. As mentioned, in this text,
we normally refer to the system calls by generic names. Throughout the text,
however, we provide examples of the actual counterparts to the system calls
for Windows, UNIX, and Linux systems.

Process Control

①Load/Execution

- create process() or submit job()
we have created a new job or process to be multiprogrammed.

- get process attributes() and set process attributes()
the ability to determine and reset the attributes of a job or process, including
the job’s priority, its maximum allowable execution time, and so on

- terminate process()
to terminate a job or process that we created ()

- wait time()
to wait for a certain amount of time to pass ()

- wait event() 
to wait for a specific event to occur

- signal event()
The jobs or processes should then signal when that event has occurred 

acquire lock(), release lock()
To ensure the integrity of the data being shared, operating systems often provide system calls allowing a process to lock shared data. 
Then, no other process can access the data until the lock is released.



The MS-DOS operating(a single-tasking system)


MS-DOS는 single-tasking system이기 때문에 프로세스가 돌아가는 동안 다른 프로세스를 실행 할 수 없다.
시스템이 켜지면, CI가 호출된다.
프로세스를 올리면 최대한의 메모리를 할당해 주시 위해서 CI의 영역까지 줄이면서 메모리공간을 내준다.
프로세스가 실행된다.
오류가 나면 에러 코드를 다음을 위해 메모리에 저장하고 종료하는 시스템 콜을 호출한다.
CI의 남은부분 (아까 프로세스를 위해 내준 메모리 공간 이외의 부분)이 실행을 계속한다.
아까 프로세스를 위해 내준 메모리 공간을 디스크로부터 회수하고 에러를 보고한다.

FreeBSD (derived from Berkeley UNIX) 

로그인을 하면 사용자가 shell(CI)을 골라 사용한다. ex)cmd, powershell 
 (MS-DOS랑 비슷하지만 FreeBSD는 멀티태스킹 프로그램이기 때문에 CI가 실행되면서 다른 프로세스가 실행될 수 있다.)
fork()를 사용하여 새로운 프로세스를 만든다.
그 프로세스가 exec()을 사용해 메모리로 프로그램을 올린다.
명령의 방식에 따라 shell은 프로세스가 완료될 때 까지 기다리거나( 2)wait), 백그라운드에서 프로세스를 실행한다.(1)continue)
(1)continue)의 경우 shell은 즉시 다른 명령을 요청한다. (프로세스가 백그라운드에서 돌아갈 때, 바로 키보드에서 입력을 받지 못한다, 왜냐하면 shell이 I/O resource를 쓰고 있기 때문이다.)
프로세스가 끝날 때 exit()을 사용해서 끝내며 shell에게 status code를 전송한다. (0 or error code)

FreeBSD (derived from Berkeley UNIX) is an example of a multitasking system. When a user logs on to the system, the shell of the user’s choice is run. This shell is similar to the MS-DOS shell in that it accepts commands and executes programs that the user requests. However, since FreeBSD is a multitasking system, the command interpreter may continue running while another program is executed (Figure 2.10). To start a new process, the shell executes a fork() system call. Then, the selected program is loaded into memory via an exec() system call, and the program is executed. Depending on the way the command was issued, the shell the neither waits for the process to ﬁnish or runs the process “in the background.” In the latter case, the shell immediately requests another command. When a process is running in the background, it cannot receive input directly from the keyboard, because the shell is using this resource. I/O is therefore done through ﬁles or through a GUI interface. Meanwhile, the user is free to ask the shell to run other programs, to monitor the progress of the running process, to change that program’s priority, and so on. When the process is done, it executes an exit() system call to terminate, returning to the invoking process a status code of 0 or a nonzero error code. This status or error code is then available to the shell or other programs.







fork(): 프로세스를 생성할 때 사용한다. 이 때 생성하는 프로세스는 parent process, 생성된 프로세스는 child process라고 부른다. 
모든 프로세스는 생성될 때 프로세스 아이디(pid)를 부여받는데, 이때 fork()에 대한 parent의 반환 값은 자식 프로세스의 pid이고 child의 반환값은 0이다.

execlp()

wait()
주로 fork()를 이용해서 자식 프로세스를 생성했을 때 사용한다. wait() 를 쓰면 자식프로세스가 종료할 때까지 해당영역에서 부모프로세스가 sleep() 모드로 기다리게 된다. 이는 자식프로세스와 부모프로세스의 동기화를 위한목적으로 부모프로세스가 자식프로세스보다 먼저 종료되어서 자식프로세스가 고아 프로세스(PPID 가 1)인 프로세스가 되는 걸 방지하기 위한 목적이다.  만약 자식 프로세스가 종료되었다면 함수는 즉시 리턴되며, 자식이 사용한 모든 시스템자원을 해제한다. 그런데 어떤 이유로 부모가 wait()를 호출하기 전에 자식 프로세스가 종료버리는 경우도 있다(잘못된 메모리 연산등으로 인한 죽음, 혹은 정상적으로), 이럴 경우 자식프로세스는 좀비프로세스가 되는데, wait()함수는 즉시 리턴하도록 되어있다. 
wait()의 인자 status 를 통하여 자식 프로세스의 상태를 받아올수 있는데, 자식프로세스의 상태값은 0 or –1(에러)

② Termination
Normal termination 
 Deallocate resources, information about current process

Abnormal termination (abort) 
 Dump memory into a file for debugging and analysis 
 Ask user how to handle 
 Interactive system: command interpreter 
 GUI system: pop-up window 
 Batch system: terminates entire job and continue with next job
  Control card: command to manage execution of process

->  프로그램이 종료 될 때 비정상적으로 종료되면 에러메세지(팝업 등)를 띄우고 디버거로 오류를 찾을 수 있다. 프로그램이 비정상적으로 종료되면 운영체제는 CI로 control을 전송하고, CI는 그냥 다음 커맨드를 실행한다. 유저가 알아서 잘 처리했을 것이라는 가정 하에.
어떤 시스템은 문제를 발견하고 비정상적으로 종료하고 싶을 때 에러 레벨을 정의한다.
정상종료는 에러 레벨0이고, CI는 에러 레벨을 사용해서 다음 액션을 어떻게 할지 자동으로 정한다.



2. File Management

create(), delete()
open(), close()
read(), write(), reposition()
reposition(): 파일을 읽을 때 r/w pointer가 있는데 그것의 위치를 앞뒤로 조정하는 것이 reposition이다.
get_file_attributes(), set_file_attributes()
move(), copy()
 Functions can be provided by either system calls, APIs, or system programs



3. Device Management

Physical device: disk, tape, memory
Abstract device: file..

시스템 콜을 할 때, file과 device를 일단 장치가 요청되고 (우리에게 할당 된), 우리는 파일을 읽을 수 있는 것처럼 장치를 읽거나 , 쓸 수 있고 (가능하다면) 재 위치시킬 수 있습니다.
실제로, I / O 장치와 파일 간의 유사성은 너무 커서 UNIX를 포함한 많은 운영 체제가 두 장치를 결합 된 파일 장치 구조로 병합합니다.
 이 경우 파일과 장치 모두에 일련의 시스템 호출이 사용됩니다. 때때로 I / O 장치는 특수 파일 이름, 디렉터리 배치 또는 파일 특성으로 식별됩니다.
 기본 시스템 호출이 다른 경우에도 사용자 인터페이스는 파일과 장치를 비슷하게 보일 수 있습니다. 이것은 운영 체제 및 사용자 인터페이스를 구축하는 데 필요한 여러 가지 설계 결정의 또 다른 예입니다.
















4. Information Maintenance

Many system calls exist simply for the purpose of transferring information between the user program and the operating system. For example, most systems have a system call to return the current time() and date(). Other system calls may return information about the system, such as the number of current users, the version number of the operating system, the amount of free memory or disk space, and soon. Another set of system calls is helpful in debugging a program. Many systems provide system calls to dump() memory. This provision is useful for debugging. A program trace lists each system call as it is executed. Even microprocessors provide a CPU mode known as single step, in which a trap is executed by the CPU after every instruction. The trap is usually caught by a debugger. Many operating systems provide a time proﬁle of a program to indicate the amount of time that the program executes at a particular location or set of locations. A time proﬁle requires either a tracing facility or regular timer interrupts.At every occurrence of the timer interrupt, the value of the program counter is recorded. With sufﬁciently frequent timer interrupts, a statistical picture of the time spent on various parts of the program can be obtained. In addition, the operating system keeps information about all its processes, and system calls are used to access this information. Generally, calls are also used to reset the process information (get process attributes() and set process attributes()).

 Transfer information between OS and user program 
 Current time, date 
 Information about system 
   # of current user, OS version, amount of free memory/disk space
 OS keeps information about all it processes 
Ex) /proc of LinuX

 ※ System programs
: 프로그램 개발과 실행에 편리한 환경을 제공해주는 프로그램

Operating – System Structure

Simple Structure

MS-DOS (1981)


  인터페이스와 기능의 레벨이 잘 나눠져있지 않았다.
- 어플리케이션 프로그램이 I/O에 직접 접근가능
- 에러하나 나면 시스템 전체가 죽었다.
- 듀얼 모드(커널, 유저모드)가 없다.













Non-simple Structure

Original UNIX

-System programs
 : Shell, commands compiler, interpreter, system library ...

Monolithic kernel: 일체형 커널, 입출력, 네트워크, 장치 지원 등 일반적인 기능을 모두 커널에다 집어넣은 형태
구조: 커널과 시스템 프로그램으로 구성됨
System call 아래에 있고, 하드웨어 위에 위치 해 있다. 
파일 시스템 제공, 시스템 콜을 통한 CPU스케줄링 메모리 관리, 다른 OS 기능
O 단점: 유지 및 보수가 힘듬
O 장점: distinct performance

Modern Operating Systems


- 보수가 쉽다
유연하다
위험하거나 알아도 쓸모없는 정보를 숨길 수 있다.















Layered Approach

레이어의 형식으로 구성되어 있는 OS이다.

각각의 레이어는 할 수 있는 역할로 구분되어 있다.
layer 0 이 가장 핵심적인 부분이고 위로 올라갈수록 덜하다.
상위 레이어가 하위 레이어를 호출할 수 는 있지만 하위 레이어가 상위 레이어를 호출 할 수는 없다.

O 장점: 한 레이어에서 문제가 발생하면 위, 아래 레이어를 볼 필요 없이 그 레이어만 보면 된다.
하위 레이어는 에러가 나지 않았고 상위 레이어는 접근을 하지 못하므로 그 레이어에만 문제가 있다는 뜻이다.

O 단점: 오직 하위 레이어만 호출 할 수 있기 때문에 주의깊은 설계가 필요하다.

다른 형식보다 비효율적이다. 한 프로세스를 실행 시켰을 때, 여러 레이어를 거쳐가기　 때문에 느려진다.
Microkernels
: 반드시 필요한 것만 넣고 나머지는 User/system-level program으로 빼놓은 커널
-> Smaller kernel 

마이크로 커널의 주요 기능은 클라이언트 프로그램과 사용자 공간에서 실행되는 다양한 서비스 간의 통신을 제공하는 것입니다. By message passing

장점
OS의 확장이 쉽다. user space에 붙어있어서 거기만 수정하면 된다.
Easy to port from one hardware design to another
유저 프로세스에서 대부분의 서비스가 실행되기 때문에 높은 안정성과 신뢰성

단점 : 느리다. 프로세스를 실행 할 때마다 message passing을 해야함



Modules
Kernels with loadable modules
객체 지향 접근,Ex) 솔라리스, 리눅스
각각의 코어는 분리되어 있고 각각은 알려진 인터페이스를 통해 다른 모듈과 통신한다.

서비스를 동적으로 링크하는 것은 새로운 기능을 커널에 직접 추가하는 것보다 바람직합니다. 변경 사항이 있을 때마다 커널을 다시 컴파일해야합니다.


모듈을 필요할 때만 로드해서 쓰고 모두가 커널 모드에서 돈다.

Advantage: 마이크로커널과 mologolithic커널의 장점을 합쳐 놓은 것
1. 레이어 구조보다 더 flexible하다, 어떤 모듈이든 붙일 수 있기 때문
2. 모듈 전체가 커널에서 돌기 때문에 빠르다. (messagepassing이 필요없다.)
Hybrid System

여러 가지 커널유형을 혼합해서 쓴다. 



Mac OS X Structure




Android Architecture









Virtual Machines: 컴퓨터 플랫폼과 운영체제간에 가상화된 환경을 생성하는 소프트웨어
운영 체제가 다른 운영 체제 내에서 응용 프로그램으로 실행될 수 있게 해주는 기술입니다.

※ Emulator: 소스 CPU 유형이 목표 CPU 유형과 다른 경우 에뮬레이션이 사용됩니다.

한 컴퓨터 내에서 여러 다른 실행환경 제공

각각의 VM은 고유의 CPU와 메모리를 가지고 있는 것처럼 보인다.

 문제점
1. 디스크 크기
 만약, 컴퓨터 본체의 용량이 128GB라면 VM1,2,3에게 적당히 나눠서 디스크 용량을 분할 해야한다.  --> 해결: Virtual disk (minidisks)

2. 구현 문제 (Virtual dual mode)

VM은 기본적으로 User mode에서 돌아가는 프로세스인데 VM에도 커널모드와 User mode가 나뉘어 있다. 이때, VM의 커널모드는 결국 User mode에 있는 것이라 문제가 발생한다.
--> 해결: 에뮬레이터

3. 속도: 실행속도가 느리다.
만약, 컴퓨터 본체의 램이 8GB라면 VM1, VM2, VM3는 모두 RAM을 8GB로 가지고 필요에 따라 Timesharing으로 사용한다.

장점: 
 1. 안에서 뭔짓을 해도 진짜 컴퓨터에게 영향을 미치지 않는다. --> 실험모드용
 2. Virtual I/O can be faster (spooling) or slower (interpreted)


3. Process Concept

Process = 실행되고 있는 프로그램 + resource



Program counter(PC)
프로그램에서 instruction을 순차적으로 진행할 때 어디까지 왔는지 가리키는 포인터

Stack: 임시데이터를 저장하는 공간 
Ex) function parameters, return address, local variable

heap: 프로세스 런타임 중 동적으로 할당되는 메모리 공간
Data: 전역 변수가 있는 공간



Process state


New: 만들어지는 것
Running: 실행 중인 것 (오직 한 프로세스만 한 번에 실행될 수 있다.)
Ready: 프로세스가 프로세서에 할당되기를 기다리고 있는 상태
waiting: 어떤 이벤트가 발생하기를 기다리는 것
terminated: 프로세스가 죽으면 minimum의 정보를 가지고 있는 상태
 ①Ready/Running State



※ PCB (Process Control Block)
: 프로세스에 대한 모든 정보를 저장하는 임시저장소

Contents
Process state: new, ready, running, waiting, terminated
Process number: pid(Process ID)
CPU Registers: Program counter(다음 실행할 인스트럭션의 위치를 저장)
CPU Scheduling info. : 우선순위,
Memory-management info.: 
Accounting info. 
I/O status info.




Process Scheduling
: CPU에서 실행할 프로세스를 선택하는 것
- 한번에 한 프로세스만 한 프로세서에서 돌아간다
나머지 프로세스들은 기다려야한다.


Scheduling Queue
: CPU시간과 다른 리소스를 쓰기 위해 프로세스들이 기다리고 있는 리스트
Linked list의 형태로 PCB에 저장되어 있다


Job queue: 시스템에 있는 모든 프로세스가 상주하는 곳
Ready queue: 리소스만 투입되면 바로 돌아갈 수 있는 프로세스들이 상주하는 곳
Device queue: I/O 명령을 기다리는 프로세스들이 상주하는 곳


Queueing Diagram


Scheduling: 리소스를 task에게 분배하는 것
스케쥴링의 목표 : 
- CPU사용률의 높이는 것, 
- 사용자와 각각의 프로그램이 상호작용할 수 있는 것



Schedulers

CPU scheduler(Short-term scheduler)

매우 자주 실행된다. (최소 100msec당 한번)
스케줄링 타임이 매우 짧아야 한다.
일단 무조건 빠르게 봐야한다.





Job scheduler (Long-term scheduler)
 - 멀티프로그래밍의 정도를 통제한다.
즉, Ready queue의 크기를 적절하게 
조절함으로서 performance를 증가시킨다.

 - Ready queue보다는 적게 실행된다.
프로세스가 시스템을 떠날 때만 실행 된다.

  -> 적절한 I/O bound와 CPU bound 프로세스의 조합을 선택해야한다.

I/O인지 CPU bound인지를 OS가 어떻게 판단할까?
I/O, CPU bound process의 정의?
I/O + CPU bound process에서 CPU의 비중이 높으면? I/O의 비중이 높으면?


Medium-term scheduler
Ready queue에 너무 프로세스가 많다면 Job queue로 다시 내려보낸다.



Windows, Linux는 Job queue가 없다. 왜냐하면 Job queue가 없어도 프로세스를 실행하는데 문제가 없기 때문이다. 다만 모든 프로세스가 ready queue에 있기 때문에 느려질 뿐인데 너무 느려지다 보면 알아서 사용자가 프로세스를 줄일 것이기 때문에 없는 것이다.


Context Switch
CPU에서 프로세스가 바뀔 때 현재 상황을 PCB에 저장하고 다음프로세스를 준비하는 작업

Context: 레지스터의 내용, OS의 구체적인 데이터
멀티태스킹이나 인터럽트가 발생했을 때 스위치가 일어난다.
즉, 자주 발생하기 때문에 빨라야한다.
Operation on Processes

process creation

fork()함수를 이용해 프로세스를 만들면 각각에 프로세스에는 pid가 할당된다.

Tree


init -  모든 프로세스의 모체
Parent가 죽은 Orphan들은 모두 init에 붙인다.
프로세스 아이디를 알고 싶으면 ps [-el] 명령어를 사용하면 된다. (In unix)



Some option to create a process

Resource:  1. Child가 리소스를 자신고유의 리소스로 OS에게 직접 요청한다.
            2. Child가 리소스를 parent의 리소스랑 공유한다.

Execution  1. Parent와 동시에 child가 실행된다.
            2. Parent가 child가 끝날 때까지 기다린다

Address space  1. 프로그램 코드와 데이터가 공유된다.
2. child프로세스가 새로운 프로그램을 로드한다.
system call related to process creation

fork() : 프로세스를 만들고 그 프로세스의 pid를 반환한다.
 - parent 프로세스의 경우 child의 pid를 반환한다.
 - child 프로세스의 경우 0을 반환한다.
    -> 프로세스의 parent/child구별이 반환 값으로 가능하다.

새로운 프로세스를 위한 메모리를 할당하고 fork()를 호출한 프로세스를 새로운 공간으로 전부 복사하게 되고, 원래 프로세스는 원래 프로세스대로 작업을 실행한다.
fork()를 이용해서 생성된 프로세스(자식 프로세스는 자신만의 PID를 가지게 되며, PPID는 부모프로세스의 PID를 가지게 된다. 부모 프로세스와 자식 프로세스는 메모리 주소만 다를 뿐 모든 자원을 공유한다.
프로그램 실행 ---> fork() 문 ---> 부모의 fork() 리턴이후 ----> 자식의 fork()

exec() family: 


1. l, v : argv인자를 넘겨줄 때 사용합니다. (l일 경우는 char *로 하나씩 v일 경우에는 char *[]로 배열로 한번에 넘겨줌) 

2. e : 환경변수를 넘겨줄 때 사용합니다. (e는 위에서 v와 같이 char *[]로 배열로 넘겨줍니다.)

3. p : p가 있는 경우에는 환경변수 PATH를 참조하기 때문에 절대경로를 입력하지 않아도 됩니다. 
 bin/ls를 실행하겠다. ls argv[0], NULL argv[0]에서 끝내겠다.








wait() 함수: 부모프로세스가 자식프로세스를 만들고 자식프로세스가 실행을 완료 할 때 까지 기다리는 함수




자식 프로세스의 리소스 (more about fork)
 - DATA: 변수 등을 부모 프로세스 것을 복사한다.
 - 메모리 주소: 자식프로세스는 자신만의 고유한 메모리 주소를 갖는다.
 - Files 
 1. fork()이전에 fopen을 하면 r/w pointer를 공유한다. (r/w pointer 1개)
 2. fork()이후에 fopen을 하면 r/w pointer를 공유하지 않는다. (r/w pointer 2개)
wait에 대하여

pid_t wait(int *stat_loc);

stat_loc: 정수 포인터
1. 만약 NULL이라면 무시되지만

2. exit(code); code == (stat >> 8) & 0xff
wait(&stat) 일 경우 child프로세스의 결과 값이 부모 프로세스에게 전달된다.


※ exit(int return_code): 자식 프로세스에 의해 호출된다.
 - 메모리 해제
 - 파일 닫기
 - 등등등등

위 return_code는 부모 프로세스에게 전달된다.
exit(code)의 리턴값이 0이라면 성공한 것이고 그 이외의 1-255까지의 값은 오류인 것이다.


win32 process creation

CreateProcess(): fork()랑 비슷함, 그러나 자식 프로세스의 속성을 구체화한 매개변수가 더 많음

WaitForSingleObject(): wait()와 비슷함

void ZeroMemory(PVOID Destination, SIZE_T Length); 메모리 블록을 0으로 채움
Inter-process communication(IPC)



IPC의 목표: 협력
정보공유
컴퓨팅 속도향상
모듈성: 시스템 기능을 나눔
편리성: 편집, 표시, 컴파일링을 동시에

Shared-memory model

Shared memory: OS가 여러 프로세스가 공유할 수 있는 메모리 공간을 할당해 준다. 카페 주인 같은 역할

장점: 빠르다, 많은 양의 데이터를 옮기기 적합




Producer – consumer



Producer: consumer를 위해 정보를 생산함
Consumer: producer에 의해 만들어진 정보를 소비함

예를 들면, 컴파일러-어셈블러, 서버-클라이언트 같은 관계가 있음


Shared memory는 두종류가 있다. 
unbounded buffer: 메모리 크기 제한이 없어서 producer가 마구마구생산 할수 있음
Bounded buffer: 메모리 크기 제한이 있어 꽉 차 있으면 기다려야 한다.





Bounded Buffer에 대표적인 예: Circular queue(FIFO)









Circular queue


위의 그림을 보면 (A)는 시작 부분이라 T(Tail)과 H(Head)가 동일한 위치에 있다. 즉, 이것은 큐가 비어있다는 것을 의미한다. 큐에 데이터를 삽입할 때 H가 가리키는 위치에 데이터를 삽입하게 되면 모든 큐에 데이터를 삽입했을 경우(=포화 상태) T와 H가 같은 곳을 가리키게 된다. 즉 포화 상태인지 큐가 비어있는 상태인지 알 수가 없다.
 따라서 H가 가리키는 위치가 아니라 H + 1의 위치에 데이터를 삽입한다. 그리고 항상 삽입 전에 H + 1의 위치가 T의 위치가 같은지 확인한다. 만약 H + 1과 T의 위치가 같다면 포화 상태로 간주하는 것이 원형 큐의 원리이다. 사실 상 큐가 비어있지만, 저 곳에 만약 데이터를 삽입하게 된다면 앞서 설명한 것과 같이 포화 상태와 빈 상태를 구분할 수가 없기에 데이터를 덮어씌워 손실이 생길 수 있다.

(D)를 보면 H + 1은 인덱스를 초과하므로 다시 큐의 0번 인덱스를 가리킨다. 즉 H + 1과 T의 위치가 같으므로 포화 상태로 간주하여 더 이상 큐에 데이터를 입력할 수 없다.

이번에는 (F - H) 과정을 거쳐 모든 큐의 데이터를 제거하게 되면, 다시 T와 H가 같은 위치를 가리키게 된다.(= 큐가 빈(empty) 상태)






동작원리

(1) 큐의 시작과 끝의 인덱스를 저장하는 head와 tail을 초기화한다. 0,0

(2 - 1) 삽입 명령이 있을 경우, 큐의 포화상태를 확인한다.

(2 - 2) 현재 (head의 위치 + 1) % MAX의 값이 tail이 가리키는 위치와 같다면 포화상태이다.

※  (head의 위치 + 1) % MAX 연산을 하는 이유는 큐의 크기를 벗어나면 다시 0부터 시작하기 위함이다.
현재 H가 3을 가리키고 있는 상황에서 + 1을 하면 4가 되므로 큐의 인덱스를 초과한다.
그러므로 큐의 크기로 나머지 연산을 해서 다시 0부터 시작하게끔 만드는 것이다.

(2 - 3) 포화상태가 아닐 경우 head의 위치를 1 증가시키고 해당 위치에 데이터를 삽입한다.
(3 - 1) 제거 명령이 있을 경우, 큐가 비어있는지 확인한다.
(3 - 2) head의 위치과 tail의 위치가 같다면 비어있다는 것이다.
(3 - 3) 큐에 데이터가 있다면 tail의 위치를 1 증가시키고, 기존 데이터를 반환한다.


#define BUFFER_SIZE 6
typedef struct { typedef전체가 shared memory 안에 있어야 한다.
...
} item;
item buffer[BUFFER_SIZE];
int in =0; // tail or rear
int out=0; // head or front

Producer
item nextProduced;

while(1) { 
// produce an item in nextProduced
while((in + 1) % BUUFER_SIZE) == out); //waiting, 가득 찼을 때
buffer[in] = nextProduced;
in = (in + 1) % BUFFER_SIZE;
}

Consumer
item nextConsumed;

while(1) {
while(in == out); // waiting, 버퍼가 비었을 때
nextConsumed = buffer[out];
out = (out + 1) % BUFFER_SIZE;
// consume the item in nextConsumed
}
2. Message-Passing Systems

-장점: 충돌이 없다. (소규모의 데이터 전공)
다른 컴퓨터 간의 통신 가능

-필수요건: sender, receiver
-구현방법
Direct/Indirect
syn/asyn
buffering (zero/bounded/unbounded capacity)




Direct/Indirect Communication





2. Synchronize/Asynchronize

syn: 메일을 주고 받아갈 때까지 기다림 / 줄 때 까지 기다림
asyn: 메일을 주고 다른 일함 / 다른 일 하다가 주면 받아감

3. buffering
 3-1. Zero capacity: 임시 저장공간이 없으므로 asyn불가능 
 3-2. bounded capacity: 
 3-3. unbounded capacity
Example of IPC system

1. Shared memory (allocate – attach - deallocate)

Create
int shmget(key_t key, int size, int shmflg);
Ex) seg_id = shmget(IPC_private, size, S_IRISROS_IWUSR)
공유 메모리를 만들 땐, P1 밖에 만든다. get은 아직 사용하는 상태가 아니며 아직 프로세스에 속하지 않았기 때문에 리턴 값은 공유 메모리(자신)의 ID이다.


Attach
void *shmat(int shmid, char *shmaddr, int shmflg); 
 Ex) shared_mem = (char *)shmat(seg_id, NULL, 0)
P1의 메모리 값을 리턴한다. 왜냐하면 메모리에 붙였기 때문이다.




P2는 attach의 과정만 가진다. 
P2는 어떻게 SM의 ID를 아는가?
P1, P2는 거의 부모-자식 관계이다. 그렇지 않을 때는 메시지 패싱으로 알려준다.

Detach
int shmdt(cjar *shmaddr);
Ex) shmdt(shared_mem);
 프로세스 하나를 Attach 할 때, count를 한다. (shm_nattach++) detach할 때 count를 뺀다. 카운트가 0이면 해제한다.



Deallocation
Shmctl(shmid, IPC_RMID, NULL); // IPC_RMID는 지우라는 명령이다.
shm_nattach == 0일 때, 해제할 수 있다.
Communication in client-server systems


RPC: 별도의 원격 제어를 위한 코딩 없이 다른 주소 공간에서 함수나 프로시저를 실행할 수 있게하는 프로세스 간 통신 기술이다. 다시 말해, 원격 프로시저 호출을 이용하면 프로그래머는 함수가 실행 프로그램에 로컬 위치에 있든 원격 위치에 있든 동일한 코드를 이용할 수 있다. Function 단위

RMI: 로컬 컴퓨터에서 원격 컴퓨터의 메서드를 호출하는 기술이다 object 단위

- 소켓: 커뮤니케이션의 종착점, 기본적으로 소켓은 통신을 위한 일종의 통로라고 생각할 수 있습니다. 기본적으로 소켓은 상대방에게 데이터를 보내거나 받는 역할을 한다. 

이때, IP주소로 Socket이 연결되면 해당컴퓨터끼리 연결이 되지만 하나의 컴퓨터 안에서도 인터넷을 사용하는 여러 프로세스가 동시에 실행되고 있을 수 있기 때문에 정확한 프로세스에 도착하기 위해선 어떤 프로세스로 가야하는지에 대한 정보가 필요합니다.
예를 들자면, Socket으로 연결되는 IP주소는 건물이고 Port는 방 번호인 것이다. 


- 포트: 
 포트 정의: TCP 및 UDP 프로토콜에 의해 인식되는 컴퓨터에 대한 논리적 접촉점

쉽게 말해, TCP나 UDP 에서 어플리케이션(프로세스들)의 구분을 위해서 사용하는 번호
포트 번호는, 서버에서 들어오는 정보를 컴퓨터 내에서 실행되고 있는 적절한 프로세스에 분배시키기 위해 할당되는 숫자를 말한다. 이것은 물리적인 플러그나 소켓이 아니며, 다만 논리적인 할당일 뿐이다. 따라서 컴퓨터는 여러 개의 포트가 있을 수 있습니다. (0-65535)


1. 잘 알려진 서비스는 각각의 1024아래의 고유한 포트번호를 갖습니다.
ex) talnet:23 ftp:21 http:80 미리 지정된 포트번호
서버는 항상 위 포트를 수신하고 있는다.

2. 1024번 위의 포트는 네트워크 통신을 할 때 프로세스에게 랜덤으로 할당됩니다.
다른 응용프로그램 프로세스들은 매번 접속할 때마다 포트번호가 동적으로 부여된다.


-소켓을 통한 연결과정
서버는 연결 요청을 수락하기 위해 포트를 연다.
임의의 클라이언트는 1024 이상의 포트를 할당한다. ex)146.86.5.20에 port 1625 할당
클라이언트가 서버에 연결을 요청한다. ex)웹 서버 161.25.19.8 port 80
서버가 요청을 수락하면 연결된다. ex) 146.86.5.20:1625 – 161.25.19.8:80
만약 너무 많은 클라이언트가 서버에 요청을 하면 거절될 수 있다.

자바소켓
소켓 클래스
 ServerSocket: 연결 요청을 받아드리는 소켓
 Socket: 실질적으로 통신을 담당하는 소켓



클라이언트가 ServerSocket으로 연결요청을 보낸다.
서버의 SeverSocket이 서버의 Socket에게 연결 성공 실패 여부를 리턴한다.
연결이 완료되면 서버는 클라이언트 소켓과, 클라이언트는 서버의 Socket과 통신한다.

소켓연결 예시코드
ServerSocket socket = new ServerSocket(6013); // ServerSocket생성 서버포트는 6013

Socket client = socket.accept(); 
// 클라이언트가 들어오는 것을 기다리기, 클라이언트가 해당 6013포트로 연결을 시도한다면 accept 메소드는 대기를 풀고, 클라이언트와 연결시키는 Socket클래스를 생성하여 반환 (여기서 생성되는 Socket은 client)

Socket sock = new Socket(“127.0.0.1”, 6013) // 내 소켓을 만든다.

연결이 된다면, 
서버는 클라이언트와 client소켓을 통해 통신하고
클라이언트는 서버와 sock소켓을 통해 통신한다.

데이터 전송 예시코드
PrintWriter pout = new PrintWriter(client.getOutputStream(),true);

// 텍스트를 출력하는 함수, 
여기서 OutputStream은 Binary 형식이다. 즉, 서버에서 클라이언트로 전달할 메시지를 작성하여 전달한다.

pout.println(new java.util.Date().toString());
// 현재 날짜를 출력, getOuputStream으로 현재 날짜를 스트링 형식으로 보낸다.

client.close();

InputStream in = sock.getInputStream(); // 서버에서 보낸 데이터를 읽어오기
BufferedReader bin = new BufferedReader(new InputStreamReader(in)) 
// BufferedReader 읽어오는 스트림을 인스턴스화 한 것, 여기서 읽어오는 데이터는 텍스트의 형식이다.
String line;
while((line = bin.readLine()) != null) // close 할 때 까지 읽어오기
System.out.println(line); 
sock.close();
Remote Procedure Call (RPC)
한 컴퓨터의 프로그램에서 다른 컴퓨터에서 동작하는 프로그램의 API를 호출




Stub: 원격지(Client의 원격지는 Server, Server의 원격지는 Client)에 위치해있는 프로그램을 대리하는 작은 루틴(어떤 프로그램이 실행될 때 불려지거나 반복해서 사용되도록 만들어진 일련의 코드). RPC(혹은 RMI)를 사용하는 프로그램이 컴파일 되면 요청된 절차를 제공하는 프로그램의 대역을 한다.

 - Marshal / unmarshal parameter: 
클라이언트에서 작업을 요청하는 데이터를 Marshaling하고 작업이 완료된 데이터를 다시 UnMarshaling하는 역할

 - 포트에 위치한다.


Parameter marshaling

각 시스템마다 고유한 데이터 형식을 가져 시스템 간 데이터 형식의 차이가 있을 수 있다.
Ex) Client의 integer, char같은 데이터 형식이 Server의 intger, char형식과 다를 수 있다.
->데이터를 표준 규격으로 통합할 필요가 있다.
XDR : eXternal Data Representation (데이터 표준 규격)

Marshalling: native representation -> XDR
Unmarshalling: XDR -> native representation

Remote Method Invocation (RMI)
RPC의 자바 버전, 원격 메서드 호출로 네트워크상에서 떨어져 있는 객체의 메서드를 투명하게 호출하는 것, 다른 말로는 분산되어 존재하는 객체간의 메세지 전송(메쏘드를 부르는 것과 동일함)을 가능케 해주는 것이 바로 RMI 프로토콜이다. 

 여기서 네트워크상에 떨어져 있는 객체를 Remote객체(또는 원격객체)라 하고 이를 호출하는 것을 local 객체(또는 로컬 객체)라 한다



( Parameter marshalling 추가 설명:
메쏘드의 인자를 일정한 포맷으로 바꿔주는 것이다. 이렇게 인자를 일정한 포맷으로 바꿔주는 일을 parameter marshalling 이라고 한다. 즉, 인자를 조율하고 정리하는 역할을 하는 것이다. 왜 이런 parameter marshalling 이 필요한 것일까? 정수가 차지하는 메모리의 양도 다를 수 있다. 자바는 플랫폼과는 독립적으로 작동하는 언어이다. 만약 한 객체가 윈도우 시스템에서 작동하고 다른 객체는 유닉스 환경에서 작동하고 있다면 이러한 데이터의 구현 방법을 통일해 줄 필요가 있다. )

 Skeleton: RPC의 server stub와 비슷한 역할, Client의 stub을 통해 객체를 전달 받는다.

1.  원격 객체를 가지고 있는 서버의 JVM(자바 가상 머신)과 연결 상태를 만든다.
2.  Marshalling 후 전송
3. 원격 메서드의 실행 결과를 기다린다.
4. 다시 받고 Unmarshalling


Client에서 연결 요청이 올 때 까지 대기
Skeleton에서 전송받고 Unmarshalling
처리 후 marshalling 해서 Client로 전송
4단원 Thread

개요

왜 쓰레드가 필요했나?
 대부분의 최신 응용 프로그램은 다중 스레드
 응용 프로그램 내에서 스레드가 실행됩니다.
 응용 프로그램과 함께 여러 작업을 별도의 스레드로 구현할 수 있습니다
  디스플레이 업데이트, 데이터 가져 오기, 맞춤법 검사, 네트워크 요청에 응답
 스레드 생성이 가벼운 반면 프로세스 생성은 무겁습니다
 코드를 단순화하고 효율성을 높일 수 있습니다.
 커널은 일반적으로 다중 스레드


쓰레드란? : 프로그램이 두 개 이상의 동시에 실행되는 작업으로 나뉘는 방법
※ 프로세스 : 실행중인 프로그램
 각 프로세스는 실행에 필요한 리소스를 차지합니다.
 프로세스보다 작은 단위
 프로세스의 스레드는 리소스를 공유합니다.

구성: 스레드는 스레드 ID, 프로그램 카운터, 레지스터 세트, 스택 등으로 구성됩니다.

멀티 쓰레드의 장점
싱글 쓰레드와의 차이: 확장성과 반응성이 좋다.
멀티 프로세스와의 차이 : 
경제적이다, 프로세스 생성이 쓰레드 생성보다 30배정도 느리다.
리소스 쉐어링(Not IPC)

프로그래머를 힘들게 하는 멀티 코어 또는 멀티프로세서 시스템의 문제점은 
 Dividing activities
 Balance
 Data splitting
 Data dependency
 Test and debugging


<멀티코어 프로그래밍>

Parallelism
Data Parallelism: 동일한 데이터를 여러 코어에 분산 시키며 각 코어에서 동일한 작업을 수행합니다. (Operation은 같지만 data만 나눠서 일함)

Task Parallelism: 각각 다른 작업을 쓰레드에 분산시켜서 수행합니다. (Operation 자체가 다름)

스레드 수가 증가하면 스레딩에 대한 능률도 증가합니다.
 CPU에는 하드웨어 스레드 같이 코어가 있습니다.
 Oracle SPARC T4의 경우 8개의 코어가 있고, 각각 8개씩의 쓰레드를 가진다.


※ Concurrency, Parallelism
Concurrency: 하나 이상의 작업이 진행되는 것을 지원합니다. (흐름이 1개, 단지 스위칭을 빨리해서 흐름이 여러 개처럼 보이는 것 뿐이다.)
Parallelism: 시스템이 둘 이상의 작업을 동시에 수행 할 수 있음을 나타냅니다. (흐름이 2개)

<암델의 법칙>
코어를 추가하면 성능이 좋아진다.


여기서 S는 쪼갤수 없는 일(serial, 직렬적 구성), N은 CPU의 개수(코어의 개수)라고 ,P는 쪼갤 수 있는 일(Parallel, 병렬적 구성)이라고 정의하자 를 정의하자.


위 그림에서 S+P=1(전체 일)이고, P는 쪼갤 수 있는 일이므로 N개의 코어가 있다면 P의 시간은 P/N이 된다. P = 1-S이기 때문에, 1-S/N이 되고 S와 합친것의 역수는 처리 속도의 증가분이 된다.

Ex) 25%가 serial, 75%가 parallel 할 때, 코어의 개수가 1개에서 2개로 증가한다면, 위 공식에 의해 1.6배 빨라진다. 즉, 코어를 무한정 추가한다면 1/S에 수렴한다.
-> Serial portion는 코어를 추가한다고 해서 비례해서 성능이 좋아지지 않는다. 불균형하게 성능이 증가하는 면모를 보인다. 


쓰레드의 종류
공유기와 회사에서 나온 랜선의 비유

User Thread: 유저 레벨의 Thread library(Not system call)에서 제공되는 쓰레드
  유저 쓰레드간의 스위칭이 커널 스위치 간 스위칭보다 빠르다

Kernel Thread: 커널에서 제공되는 쓰레드
  1. 커널에 의해 관리되고 만들어진다.
  2. 프로세스보다 가볍지만 유저 쓰레드 보단 무겁다 (Ut < Kt < Process)



멀티쓰레딩 모델

유저쓰레드와 커널쓰레드는 어떻게 같이 사용되는가?

Many-to-one model

한 커널쓰레드를 여러 유저쓰레드가 공유한다.

이 쓰레드들은 당연히 유저레벨 쓰레드 라이브러리에서 관리(Branch)한다.

Ex) Green threads, GNU Portable Threads








2. One-to-one model

하나의 커널쓰레드 당 한 유저 쓰레드가 매핑

이 쓰레드들은 커널이 관리한다.

Ex) Linux, Windows, Solaris

->More concurrecy: 속도가 빠르다
->More overhead: 커널 스케줄러의 사용으로 오버헤드가 유저 쓰레드보다 빈번하다.


3. Many-to-Many model


 다수의 유저쓰레드를 더 적은수 혹은 같은 수의 쓰레드와 매핑(n:1모델과 1:1의 모델의 절충안)

만약 I/O모드가 실행될 때, 커널이 User Thread가 I/O모드로 간 것을 알지만 switching은 User library가 한다. 

스케줄링은 유저 라이브러리, 커널 둘다 관여한다.



4. Two-level model
Many-to-many모델의 변형이다. 따라서 사실상 many-to-many모델과 비슷하다.

Ex) IRIX, HP-UX, Tru64, Solaris(old)










LWP(Lightweight process)

Scheduler activation
Many to many 모델과 two level 모델에서 커널과 쓰레드 라이브러리 간의 통신을 어떻게 할 것인지에 대한 해결방안



커널과 LWP는 1:1로 대응한다. (LWP를 커널로 볼 수도 있다.)
프로세스-커널의 관계와 LWP와 유저쓰레드의 관계가 유사하다.
예를 들면, 커널은 주방, LWP는 주문서, 유저쓰레드는 홀이라고 볼 수 있다.

커널은 일련의 LWP(가상 프로세스)를 제공한다.
유저 레벨 라이브러리는 유저 쓰레드를 LWP에 스케줄한다.
Upcall: 커널 쓰레드가 blocked of unblocked되면 커널이 유저쓰레드 라이브러리에게 알린다. (User Thread Library가 처리)
  만약 커널 쓰레드가 blocked 되면 다른 커널 쓰레드에 LWP를 할당한다
  만약 커널 쓰레드가 unblocked 되면 unblocked된 커널 쓰레드에 LWP를 할당한다.
Thread Libraries

POSIX Pthreads ex)LinuxThreads, NPTL, GNU Portable Threads, 
Win32 threads
Java threads

POSIX Pthread

- 쓰레드 만들기: int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void * (*start_routine)(void *), void *arg);
- 쓰레드의 옵션 지정하기: int pthread_attr_init(pthread_attr_t *attr); 
- 쓰레드 wait: int pthread_join(pthread_t th, void **thread_return); 
// th쓰레드가 종료될 때까지 기다린다..
- 쓰레드 종료: void pthread_exit(void *retval);

예시



Java Threads
일반적으로, 기본 OS가 제공하는 thread 모델을 사용해 구현됩니다.
Runnable class와 Thread Class로 구현할 수 있다.






첫 번째가 Thread class
두 번째가 Runnable class





묵시적 쓰레드
프로그래머가 아닌 컴파일러 및 런타임 라이브러리에 의해 수행되는 스레드 생성, 관리

Thread Pools
스레드가 필요할 때마다 할당하고 해제하기 번거롭고 비용도 많이 드니 스레드 풀을 이용해 미리 스레드를 만들어 놓는 것

장점:
 새로운 스레드를 만들어 쓰는 것 보다 약간 빠르다.
 전체 스레드를 관리하기 편하다.

2. OpenMP
Thread의 개수만큼 반복해주는 C, C++, FORTRAN용 컴파일러 지시문

#pragma omp parallel 밑에 코드를 작성하면 쓰레드의 개수만큼 반복한다.


3. Grand Central Dispatch(다시 공부)
멀티코어 프로세서를 위한 스레드 프로그래밍을 OS가 자동 관리, 분배해주는 C Library
애플은 MAC OS X, iOS에 제공하고 있다.


- 시리일 디스패치 큐(Serial Dispatch Queue).
  큐에 추가된 순서 안에서 선입선출(FIFO) 방식으로 작업을 실행한다. 또한, 큐에 있는 작업 하나를 실행시킨 후에 실행이 끝날 때까지 큐에 있는 다른 작업들은 기다리고 있다. 즉, 스레드 하나로 순차 처리를 하고 있다.

- 콘커런트 디스패치 큐(Concurrent Dispatch Queue).
  시리얼 디스패치 큐와는 다르게 실행 중인 작업을 기다리지 않고 큐에 있는 다른 작업들을 동시에 별도의 스레드에 수행시킨다. 동시에 실행되는 작업 수는 시스템 상태에 따라 달라지며, 이것을 판단 및 관리는 XNU 커널이 알아서 해준다.




Thread issues
쓰레드 실행 프로세스 명령어들을 쓰면 어떻게 될까?
-fork, exec
fork(): 모든 쓰레드가 복사됨
 fork1(): 해당 쓰레드만 복사됨

exec(): 모든 쓰레드가 복사됨

-cancellation
스레드가 일을 다 하기 전에 종료시키면 다른 스레드와 리소스를 공유하기 때문에 미완성의 상태의 결과물이 나올 수 도 있고, 에러를 발생시킬 수도 있다.
cf> 프로세스는 자신의 고유한 리소스를 갖기 때문에 상관없다.

Asynchronous cancellation: 너 당장 죽어!
Deferred cancellation: 종료해도 문제가 되지 않는 시점에서만 종료할 수 있게 처리
Signal Handling

Signal: 특정 이벤트가 발생했을 때 프로세스에 알리는 유닉스에 의해 제공되는 메커니즘
프로세스로 전달되는 소프트웨어 인터럽트
like, user-mode-interrupt

Type
Synchronous: 동일한 프로세스에서 오는 신호
Ex) illegal memory access, division by 0

2. asynchronous: 외부에서 오는 신호 Ex) Ctrl + C






신호가 전달되어야하는 스레드는 무엇입니까?

신호를 전달할 쓰레드 지정
 POSIX의 pthread_kill (tid, signal)



Thread local storage
 스레드 로컬 저장소 (TLS)를 사용하면 각 스레드가 자체 데이터 복사본을 가질 수 있습니다

 스레드 생성 프로세스를 제어 할 수없는 경우 유용하다 (즉, 스레드 풀을 사용할 때)


 지역 변수와 다릅니다.
 단일 함수 호출 동안에만 볼 수있는 지역 변수
 함수 호출에서 TLS를 볼 수 있습니다.

 정적 데이터와 비슷합니다.
 TLS는 각 스레드마다 고유합니다.

그림
CPU 스케줄링

이 단원의 학습목표
CPU 스케줄링의 개념 소개
여러 가지 CPU 스케줄링 알고리즘 소개


Why? 멀티프로그래밍, 멀티태스킹 환경에서 CPU 사용률을 최대한 높이기 위해 

CPU, I/O burst


프로세스 실행은 CPU실행과 I/O wait으로 구성된다. 프로세스는 이 둘을 번갈아 가며 실행.



-CPU burst: 프로그램 실행 중 연속적으로 CPU를 사용하는 단절된 구간 (스케줄링 단위)
-I/O burst: 프로그램 실행 중 I/O의 완료를 기다리며 block되는 구간

-> I/O bound process: 많고 짧은 CPU burst로 이루어짐
-> CPU bound process: 적고 긴 CPU burst로 이루어짐

Cf> 프로세스의 실행과 종료는 CPU burst로 구성된다.










2. CPU scheduler (= short term scheduler)

: Ready queue에서 프로세스를 선택해 CPU에 할당해주는 역할

구현: FIFO, priority queue, tree, unordered linked list

Cf> 각각의 프로세스는 PCB로 표현됨


※ preemptive, non-preemptive scheduler

preemptive scheduler
: 우선순위가 높다면 프로세스가 Running state에서 실행되고 있어도 switching이 가능한 스케줄러

non-preemptive scheduler
: 우선순위에 관계없이 프로세스가 Running state에서 실행되면 스스로 나오지 않는 한 switching이 불가능한 스케줄러


Running state -> waiting state
Running state -> ready state    Ex) 인터럽트 발생
waiting state -> ready state     Ex) I/O 완료
Running state -> terminated

Non - Preemptive scheduler의 경우
1,4번의 경우는 running state가 비어 있기 때문에 switching이 무조건 발생해야한다.
하지만 2번의 경우(동일한 프로세스가 다시 running state로 들어올 수 있음)와 3번의 경우 (running state의 프로세스의 변화가 없음)에는 switching은 선택적이다.

Preemptive scheduler의 경우
1,2,3,4번의 경우 모두 프로세스의 이동이 일어나면서 우선순위가 바뀌어 switching이 일어날 수 있다.






※ preemptive, non-preemptive kernel

preemptive kernel: 시스템 콜 수행도중에 일정 포인트마다 인터럽트를 확인해서 인터럽트 수행을 우선시 합니다.

non-preemptive kernel: 시스템 콜 수행도중에는 인터럽트 처리 루틴으로 빠져나가지 않고 시스템 콜 수행 후에 인터럽트를 처리한다. -> 대부분의 OS가 이것을 쓴다.


※ Dispatcher
: CPU 스케줄러에 의해 선택된 프로세스를 CPU로 보내주는 역할

- Dispatcher의 역할
• Switching Context
• 사용자 모드로 전환
• 이전에 실행되었던 instruction point로 점프하여 해당 프로그램을 다시 시작하게 도와줌.

Cf> Dispatch latency
디스패처는 프로세스 전환 중에 호출되므로 가능한 한 빨라야한다. 
디스패처가 한 프로세스를 중지하고 다른 프로세스를 시작하는 데 걸리는 시간
(=Context switching이 일어날 때 소요되는 시간)


좋은 스케줄링의 기준
CPU utilization (사용률): CPU를 얼마나 바쁘게 사용하는가?
Throughput(처리량): 단위 시간당 몇 개의 프로세스를 처리할 수 있는가?
Turnaround time(처리시간): 총 프로세스를 완료하기 까지 걸린 시간 (=대기 + 실행시간)
Waiting time (대기시간): Ready queue에서 총 얼마나 기다렸는가?
Response time(반응시간): 하나의 요청에 첫 번째 응답이 나올 때까지의 시간

Turnaround time(처리 시간)이 최상의 기준이 아닐 수도 있습니다.
종종 프로세스는 output을 상당히 빨리 내놓을 수 있고, 그 output이 출력되는 동안 다른 output을 위한 계산을 할 수 있습니다.

-> 하나의 요청에 첫 번째 응답이 나올 때까지의 시간
(응답을 출력하는 데 걸리는 시간이 아니라 응답을 시작하는 데 걸리는 시간입니다.)

기준의 기준: 평균값, 최솟값, 최댓값

3. Scheduling Algorithms

-FCFS(First Come, First Served)

먼저 온 프로세스부터 처리해주는 방식

Non-preemptive scheduling
CPU, I/O 사용률이 비효율적이다.







-SJF(Shortest Job First)

가장 burst time이 짧은 프로세스부터 처리해주는 방식
가장 효율적인 알고리즘
문제점: 어떤 프로세스가 가장 짧은가?
-> 예측해서 계산한다.










 한 프로세스를 n번째 돌렸을 때 실제 걸린 시간 (측정치)

 한 프로세스를 n번째 돌릴 때 얼마나 시간이 소요될지 예측한 시간 (예측치)

 측정치와 예측치의 연관성

만약, 0이라면 최근 기록은 영향을 미치지 않고
     1이라면 최근 기록에 의해서만 영향을 받는다.
            주로 0.5로 사용한다.
-> 오래된 기록일수록 예측치에 덜 영향을 미친다.







※ Preemptive Version Of SJF


a. P1이 제일 먼저 들어와서 Running state에 들어가서 실행되고 있다.
b. P2가 2초에 들어와서 P1의 남은 burst time보다 적기 때문에 switching된다.
P2의 burst time = 4, P1 burst time = 7-2=5

c. P3가 4초에 들어와서 P2의 남은 burst time보다 적기 때문에 switching된다. 
P3의 burst time = 1, P2의 burst time = 4-2 = 2
1초의 burst time을 사용하고 P3는 종료됨

d. P4가 5초에 들어오지만 P1, P2, P4중 남은 burst time이 가장 짧은 P2로 switching된다.
P1의 burst time = 5, P2의 burst time = 2, P4의 burst time = 4
2초의 burst time을 사용하고 P2는 종료됨

e. P1과 P4중 남은 burst time이 P4가 더 적기 때문에 P4로 switching된다.
4초의 burst time을 사용하고 P4는 종료됨

f. P1이 5초 동안 실행되고 모든 프로세스 종료


-Priority scheduling
프로세스에 우선순위를 매겨 그 순위대로 처리하는 방법










Cf> Priority
Priority의 숫자가 낮을수록 높은 우선순위를 가진다.
Priority는 CPU에 의해, 또는 사용자에 의해 정해진다.
Priority는 preemptive or non-preemptive 모두 가능하다.
 1. Preemptive
 새로 도착한 프로세스의 우선순위가 현재 실행중인 프로세스의 우선순위보다 높은 경우 CPU를 선점한다.
2. Non-preemptive 
 새로운 프로세스가 들어와도 Ready queue에 넣어주기만 하면 된다.

->문제점
Indefinite blocking(=Starvation) 발생
 -->> Aging: 오래 기다릴수록 priority를 높혀준다.


-Round-robin scheduling

Preemptive FCFS, CPU time을 time quantum 혹은 time slice이라는 단위로 나눠서 프로세스를 실행시키는 방법

 -> Ready queue는 circular queue로 구현


a. P1은 burst time이 24이기 때문에, time slice가 4인 이 스케줄러에서 4만큼 밖에 실행되지 못한다.

b. 4초가 지나서 P2로 switching되고, P2는 burst time이 3이기 때문에 time slice를 다 쓰지 않고, 반환한다. 

c. 3초가 지나서 P3로 switching되고, P3는 burst time이 3이기 때문에 time slice를 다 쓰지 않고, 반환한다.

d. 남은 프로세스가 P1 하나이기 때문에 종료되기 전까지 실행된다. 

권장사항
평균 처리시간은 time slice의 크기에 비례하지도 반비례하지도 않지만, 대부분의 프로세스가 단일 time slice에서 CPU burst를 완료하면 평균 처리시간이 향상된다.

그렇다고 너무 time slice를 길게 한다면 FCFS와 같게 되기 때문에 좋지않다.

Rule of thumb: CPU burst의 80% 정도가 time slice보다 짧아야한다.







-Multi-level queue scheduling

•원리: 프로세스를 여러 그룹으로 분류하고 다른 스케줄링 적용
•기준: 메모리 요구 사항, 우선 순위, 프로세스 유형, ...


각 큐에는 고유 한 스케줄링 알고리즘이 있습니다.


＃ Fixed-priority preemptive scheduling
  우선순위가 낮은 큐의 프로세스는 우선순위가 높은 대기열이 모두 비어있는 경우에만 실행

＃ Time-slicing among queues
Ex) foreground queue (자주 사용, 가시적)80 % : background queue  (비가시적) 20 %

한번 프로세스가 큐에 할당이 되면 영구적으로 그 큐를 벗어나지 못한다.


- Multiple feedback queue scheduling

Multi-level Queue Scheduling과 비슷하지만 프로세스가 큐 간 이동이 가능
•원리 : CPU 버스트 시간에 따라 프로세스를 구분
  -> 프로세스가 CPU 시간을 너무 많이 사용하면 우선순위가 낮은 대기열로 이동시킴.
※ 일반적으로, I/O-bound, interactive processes는 우선 순위가 높은 대기열에 있다

예시) Time quantum = 8

i) T < 8 
highest priority에서 계속 실행

ii) 8 < T < 16
highest에서 8초를 사용하고, middle 에서 남은시간 쓰고 나감 (반복)

iii) T > 16
FCFS
Time quantum을 초과하면 우선순위가 낮은 큐로 이동시킴
• 고려사항
1. 큐의 개수
2. 각각의 큐에 대한 스케줄링 알고리즘
3. 언제 프로세스의 우선순위를 조정할지 정하는 기준
4. Method to determine which queue a process will enter when it nedds service
->가장 복잡한 알고리즘



4. Processor Affinity, Load Balancing

Processor Affinity (친화성)
: 한 프로세스가 CPU A에서 실행됐으면 다음에 실행될 때도, 동일한 CPU A에서 실행되는 것이 효율적이다. (because of Cache) 
  -> Migration overhead 방지

 • Soft Affinity: 웬만하면 동일한 CPU에서 실행시키지만, 다른 CPU로 이동할 수 있다.
 • Hard Affinity: 절대로 다른 CPU에서 실행시키지 않는다.


Load Balancing
: 계속 한 CPU에서 실행되다보면 하나의 CPU만 실행되니까 그 균형을 맞춰주는 것
※ 이 때, 각 CPU(프로세서)는 ready queue를 가지고 있어야 한다.

 • Push migration: 덜 바쁜 CPU가 자원해서 프로세스를 받아오는 것
 • Pull migration: 한쪽 CPU에 너무 몰리면 적당하게 다른 CPU에 분배하는 것
-> Push, Pull은 parallel하게 구현되어야 한다.

Load Balancing과 Processor Affinity는 상충관계(Counteract)이다.


※Multi-core Processors
: CPU 한 개에 여러 프로세스 코어를 사용한다.

Memory stall: 캐시에 없는 데이터에 접근하는 것 같은 이유로 메모리에 접근 해 데이터를 사용할 수 있을 때까지의 상당한 준비시간이 걸린다.
-> 멀티 쓰레드 사용












첫 번째 그림은 실행과 메모리 접근을 한 쓰레드가 번갈아 가면서 실행하기 때문에 Memory stall 중에는 실행을 하지 못한다.
하지만, 멀티쓰레드를 사용하여 한 쓰레드가 실행하는 도중에 다른 쓰레드는 메모리에 접근해 데이터를 읽어온다. 이러한 일을 두 쓰레드가 alternative하게 한다면 성능개선이 가능하다.
5. Thread Scheduling

※Thread
1. User thread (thread library에 의해 지원, 간접적으로는 LWP)
2. Kernel thread (OS kernel에 의해 지원)
-> OS의 스케줄링 단위는 kernel thread이다.

- Thread Priority Contention
 • PCS(Process-contention scope): User thread간의 경쟁
  ex) Many-to-one model, Many-to-many model



 SCS(System-contention scope): Kernel thread간의 경쟁 = 전체 시스템차원의 경쟁
  ex) One-to-one model


code) SCS 범위의 쓰레드 생성
..... // 생략
pthread_attr_init(&attr); // default로 attribute를 채운다.
pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM); // thread 경쟁범위 설정
pthread_attr_getscope(&attr, &scope); // set으로 설정한 thread 속성을 가져옴
.... // 생략
pthread_create(&tid, &attr, runner, NULL); // attr의 속성을 가져와서 thread 생성
6. Real example in various OS

Windows Scheduling

우선순위를 고려한 preemptive scheduling이다. (by Dispatcher)
 • Memory management(0)
 • Real time class(16~32)
 • Variable class(1~15)

0을 제외한 각 숫자가 클수록 우선순위가 높은 프로세스다  

















우선순위 변경 함수
SetprioirtyClass(): 표에서 좌우 이동
SetThreadPriority(): 표에서 상하 이동

특징
우선순위가 아무리 밀려도 자기가 속해있는 class의 최저점보다 낮아지지 않는다.
 ex) real-time class에서 idle은 가장 우선순위가 낮지만 15아래로 떨어지지 않음

2. waiting 상태에서 해제된 스레드의 우선순위를 높여준다. 얼마나 기다렸는지에 따라 우선순위를 높이는 양이 달라진다.

3. 대충 foreground process에게 background process보다 3배의 time slice를 배정한다.