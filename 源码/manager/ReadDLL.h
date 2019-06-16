
#ifndef ReadDLL
#define ReadDLL
#include "stdafx.h"

#define    MAXBLOCK 2048 
#define    XON 0x11 
#define    XOFF 0x13 
#define RFCRC16_POLYNOM 0x8408


DWORD  _stdcall RFcrc_16( char offset, unsigned char *pointer, int length, DWORD crc16_preset);


// ���ô���
//m_sPort Com���ں� ��:"COM1"
//BaudRate ������
//Databit ����λ
//parity У��λ
//stopbit ֹͣλ
extern   "C"   __declspec(dllexport)  int  _stdcall SetCom(const char *m_sPort, int BaudRate, int Databit, char *parity, char *stopbit);
// �رմ���
extern   "C"   __declspec(dllexport)  int _stdcall CloseCom();
// ������
//inbuff �����װ�ַ���,�洢������Ϣ
//nBytesRead ��ȡ����
//ReadTime ��ȡ��ʱ
extern   "C"   __declspec(dllexport)  int _stdcall ReadCom( BYTE inbuff[], DWORD &nBytesRead, int ReadTime);
//д����
//Outbuff д�������ַ���
//nBytesRead ����
//ReadTime ��ȡ��ʱ
extern   "C"   __declspec(dllexport) int _stdcall WriteCom( BYTE Outbuff[], int size);

extern   "C"   __declspec(dllexport) int _stdcall Inventory(BYTE pUIDbuffer[],unsigned char Flag,DWORD &Tagcount);
extern   "C"   __declspec(dllexport) int _stdcall ReadSingleBlock(BYTE tagUID[],unsigned char Address,unsigned char BlkSize,BYTE BlkValue[]);
extern   "C"   __declspec(dllexport) int _stdcall WriteSingleBlock( BYTE tagUID[],unsigned char Address,unsigned char BlkSize, BYTE BlkValue[]);
extern   "C"   __declspec(dllexport) int _stdcall ReadMultiBlock(BYTE tagUID[],unsigned char nStartBlock,unsigned char nLength,unsigned char BlkSize,BYTE BlkValue[]);

extern   "C"   __declspec(dllexport) int _stdcall Quiet(BYTE tagUID[]);
extern   "C"   __declspec(dllexport) int _stdcall ResetToReady(BYTE tagUID[],unsigned char ResetModle);
extern   "C"   __declspec(dllexport) int _stdcall SpecialCMD(unsigned char CmdData);

extern   "C"   __declspec(dllexport) int _stdcall WriteAFI(BYTE tagUID[],unsigned char AFI,unsigned char isEvery);
extern   "C"   __declspec(dllexport) int _stdcall LockAFI(BYTE tagUID[],unsigned char isEvery);
extern   "C"   __declspec(dllexport) int _stdcall WriteDSFID(BYTE tagUID[],unsigned char DSFID,unsigned char isEvery);
extern   "C"   __declspec(dllexport) int _stdcall LockDSFID(BYTE tagUID[],unsigned char DSFID,unsigned char isEvery);
extern   "C"   __declspec(dllexport) int _stdcall GetSystemInfoByReader(BYTE tagUID[],unsigned char isFsk,BYTE BackData[]);
extern   "C"   __declspec(dllexport) int _stdcall GetMultiBlockSecurityStatus(BYTE tagUID[],unsigned char isFsk,BYTE BackData[],unsigned char Adress,unsigned char Number);
#endif


