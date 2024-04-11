/*
13장--포인터
64비트 운영체제의 장단점
동시처리능력이 좋음/ram을 2^64까지(16EB) 사용가능
32비트는 2^32>42GB까지 사용가능
운영체제는 메모리 주소를 1바이트 단위로 관리
102번지에 1042라는값을 2바이트크기로 저장하겠다
2바이트,short형
1042는 4와 18로 나누어짐 2진수:0000 0100 0001 0010 
10진수: 4와18!  16진수 : 0x04  0x12 바이트단위로저장:0x0412
1042값은 8비트에 저장할수없기 때문에 두개의 8비트에 나누어저장
102번지에18, 13번지에 4가저장 
윈도우는 리틀엔디안 바이트정렬 그러므로 18,4로저장
뒷번호가 먼저저장 18부터!
빅엔디안이면 4,18
c언어는 간접주소지정방식으로 동작하는 포인터문법을 제공
자신이 사용하고싶은 메모리의 주소를 저장하고있는 메모리가포인터
포인터변수는 자료형을 선언하지않아도 무조건4바이트(32비트니까)
short *ptr :자료형 *포인터변수이름
ptr포인터변수는 4바이트 
ptr포인터가 가리키는 대상은 short형 2바이트
*ptr=0x0412;  // birthday=0x0412;와 같은결과
ptr =  :포인터 변수의 값이 변경
*ptr = :포인터가 가리기키는 대상의 값이변경
const int *0 :*p의 값을 변경하려면 오류(대상을 const)
int * const p: p값이 변경되면 오류(자신을 const)
const int * const p; 둘다 오류
--포인터변수의주소연산
short dat=0;
short*p=&data;
p = p+1; //포인터변수에 저장된 주소값을 1만큼증가
포인터에서 +1의 의미는 그 다음 데이터의 주소를의미
원래 p에저장된주소값이 100이였다면 101이아니라 102로되는것
p+2면 104 p+@ :@는 포인터가 가리키는 대상의 크기가얼마냐에따라 달라짐  int*p였다면 p+1은 4씩증가 104!
포인터 변수를 선언할떄 *연산자 앞에 적는 자료형은 포인터변수가 가리키는 대상의 크기를 의미 int *p;
int data=0x12345678,i;
char*p=(char*)&data;
//4바이트 데이터를 바이트 단위로 값을 출력하기 위해 4번반복
for(i=0;i<4;i++){
	printf("%X,",*p); //p가 가진 주소부터 1바이트 크기만 사용
	p+++; //p가 가리킬 수 있는 크기(1바이트)만큼 주소증가
	}
}   16진수로 표시 >한자리가 4비트니까 2자리면 한바이트!
리틀엔디안 방식이니  data변수(4바이트)
0x78 0x56 0x34 0x12 로 메모리에 저장
p는 0x78 한바이트만 가리키는중 p+1은 0x56 가리키는중
void 키워드:정해져 있지 않다
포인터변수가 가리키는 대상의 크기를 모를떄 void*p 사용
*/