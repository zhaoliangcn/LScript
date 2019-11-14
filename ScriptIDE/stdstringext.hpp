#ifndef _H_STDSTRINGEXT
#define _H_STDSTRINGEXT
#include <string>
#include <algorithm>
#include <functional>
#include <string.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <memory.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <locale.h>
#include <wctype.h>
#include <stdio.h>
#define WCHAR wchar_t
#endif
#include <stdlib.h>
#include <stdarg.h>
namespace STDSTRINGEXT
{
	using namespace std;
	// trim from start
	static inline std::string &ltrim(std::string &s) {
		const char* p = " \t\n\r\x0b";
		s.erase(0, s.find_first_not_of(p));
		return s;
	}
	// trim from end
	static inline std::string &rtrim(std::string &s) {
		 const char* p = " \t\n\r\x0b";
		s.erase(s.find_last_not_of(p) + 1);
		return s;
	}
	// trim both start end
	static inline std::string &trim(std::string &s) {
		return ltrim(rtrim(s));
	}
	static inline std::wstring &ltrim(std::wstring &s) {
		const wchar_t* p = L" \t\n\r\x0b";
    s.erase(0, s.find_first_not_of(p));
		return s;
	}
	// trim from end
	static inline std::wstring &rtrim(std::wstring &s) {
		const wchar_t* p = L" \t\n\r\x0b";
    s.erase(s.find_last_not_of(p) + 1);
		return s;
	}
	// trim both start end
	static inline std::wstring &trim(std::wstring &s) {
		return ltrim(rtrim(s));
	}
	static inline std::string Format(const char *_format, ...)
	{
		std::string temp;
		char szBuffer[1000];
		memset(szBuffer, 0x00, sizeof(szBuffer));
		va_list ap;
		va_start(ap, _format);
#ifdef _WIN32
		vsnprintf_s(szBuffer, 1000,1000, _format, ap);
#else
		vsnprintf(szBuffer, 1000, _format, ap);
#endif
		va_end(ap);
		temp.append(szBuffer);
		return temp;
	}
	static inline std::wstring Format(const wchar_t *_format, ...)
	{
		std::wstring temp;
		wchar_t szBuffer[1000];
		memset(szBuffer, 0x00, sizeof(szBuffer));
		va_list ap;
		va_start(ap, _format);
#ifdef _WIN32
		_vsnwprintf_s(szBuffer, 1000,1000, _format, ap);
#else
		vswprintf(szBuffer, 1000, _format, ap);
#endif
		va_end(ap);
		temp.append(szBuffer);
		return temp;
	}

	static string	WToA(wstring sW)
	{
		string	sResult;
		char *	Buffer	=	NULL;
#ifdef _WIN32
		DWORD	nChBuf = WideCharToMultiByte(CP_ACP,0,sW.c_str(),-1,NULL,0,NULL,NULL);
		Buffer = (LPSTR)malloc(nChBuf);
		nChBuf = WideCharToMultiByte(CP_ACP,0,sW.c_str(),-1,Buffer,nChBuf,NULL,NULL);
#else
		setlocale(LC_ALL,"zh_CN.GB18030");
		int len = wcstombs(NULL,sW.c_str(),0)+2;
		Buffer = (char *)malloc(len);
		memset(Buffer,0,len);
		wcstombs(Buffer,sW.c_str(),len);
#endif
		sResult = Buffer;
		free(Buffer);


		return sResult;
	}
	static wstring	AToW(string	sA)
	{
		wstring	sResult;
		wchar_t *	Buffer	=	NULL;

#ifdef _WIN32
		DWORD	nChBuf = MultiByteToWideChar(CP_ACP,0,sA.c_str(),-1,NULL,0);
		Buffer = (wchar_t *)malloc(nChBuf * sizeof(wchar_t));
		nChBuf = MultiByteToWideChar(CP_ACP,0,sA.c_str(),-1,Buffer,nChBuf);
#else
		setlocale(LC_ALL,"chs");
		int len = mbstowcs(NULL,sA.c_str(),0)+1;
		len=len*sizeof(wchar_t);
		Buffer = (wchar_t *)malloc(len);
		memset(Buffer,0,len);
		mbstowcs(Buffer,sA.c_str(),len);
#endif
		sResult = Buffer;
		free(Buffer);
		return sResult;

	}
#ifdef _WIN32	
	static inline string		 W2UTF(wstring	sW)
	{
		string	sResult;
		LPSTR	lpStrBuf	=	NULL;
		DWORD	nChBuf = WideCharToMultiByte(CP_UTF8,0,sW.c_str(),-1,NULL,0,NULL,NULL);
		lpStrBuf = (LPSTR)malloc(nChBuf);
		nChBuf = WideCharToMultiByte(CP_UTF8,0,sW.c_str(),-1,lpStrBuf,nChBuf,NULL,NULL);
		sResult = lpStrBuf;
		free(lpStrBuf);
		return sResult;
	}
	static inline wstring		 UTF2W(string	sU)
	{
		wstring	sResult;
		LPWSTR	lpStrBuf	=	NULL;
		DWORD	nChBuf = MultiByteToWideChar(CP_UTF8,0,sU.c_str(),-1,NULL,0);
		lpStrBuf = (LPWSTR)malloc(nChBuf * sizeof(WCHAR));
		nChBuf = MultiByteToWideChar(CP_UTF8,0,sU.c_str(),-1,lpStrBuf,nChBuf);
		sResult = lpStrBuf;
		free(lpStrBuf);
		return sResult;
	}

#else

	static inline int enc_get_utf8_size(const unsigned char pInput)
	{
		unsigned char c = pInput;
		// 0xxxxxxx 返回0
		// 10xxxxxx 不存在
		// 110xxxxx 返回2
		// 1110xxxx 返回3
		// 11110xxx 返回4
		// 111110xx 返回5
		// 1111110x 返回6
		if(c< 0x80) return 0;
		if(c>=0x80 && c<0xC0) return -1;
		if(c>=0xC0 && c<0xE0) return 2;
		if(c>=0xE0 && c<0xF0) return 3;
		if(c>=0xF0 && c<0xF8) return 4;
		if(c>=0xF8 && c<0xFC) return 5;
		if(c>=0xFC) return 6;
	}
	static inline int enc_utf8_to_unicode_one(const unsigned char* pInput, unsigned long *Unic)
	{
		if(pInput ==NULL || Unic==NULL)
		{
			return -1;
		}

		//    assert(pInput != NULL && Unic != NULL);

		// b1 表示UTF-8编码的pInput中的高字节, b2 表示次高字节, ...
		char b1, b2, b3, b4, b5, b6;

		*Unic = 0x0; // 把 *Unic 初始化为全零
		int utfbytes = enc_get_utf8_size(*pInput);
		unsigned char *pOutput = (unsigned char *) Unic;

		switch ( utfbytes )
		{
		case 0:
			*pOutput     = *pInput;
			utfbytes    += 1;
			break;
		case 2:
			b1 = *pInput;
			b2 = *(pInput + 1);
			//(b2 & 0xC0) != 0x80
			if ( (b2 & 0xC0) != 0x80)
				//if ( (b2 & 0xE0) != 0x80 )
				return 0;
			*pOutput     = (b1 << 6) + (b2 & 0x3F);
			*(pOutput+1) = (b1 >> 2) & 0x07;
			break;
		case 3:
			b1 = *pInput;
			b2 = *(pInput + 1);
			b3 = *(pInput + 2);
			if ( ((b2 & 0xC0) != 0x80) || ((b3 & 0xC0) != 0x80) )
				return 0;
			*pOutput     = (b2 << 6) + (b3 & 0x3F);
			*(pOutput+1) = (b1 << 4) + ((b2 >> 2) & 0x0F);
			break;
		case 4:
			b1 = *pInput;
			b2 = *(pInput + 1);
			b3 = *(pInput + 2);
			b4 = *(pInput + 3);
			if ( ((b2 & 0xC0) != 0x80) || ((b3 & 0xC0) != 0x80)
				|| ((b4 & 0xC0) != 0x80) )
				return 0;
			*pOutput     = (b3 << 6) + (b4 & 0x3F);
			*(pOutput+1) = (b2 << 4) + ((b3 >> 2) & 0x0F);
			*(pOutput+2) = ((b1 << 2) & 0x1C)  + ((b2 >> 4) & 0x03);
			break;
		case 5:
			b1 = *pInput;
			b2 = *(pInput + 1);
			b3 = *(pInput + 2);
			b4 = *(pInput + 3);
			b5 = *(pInput + 4);
			if ( ((b2 & 0xC0) != 0x80) || ((b3 & 0xC0) != 0x80)
				|| ((b4 & 0xC0) != 0x80) || ((b5 & 0xC0) != 0x80) )
				return 0;
			*pOutput     = (b4 << 6) + (b5 & 0x3F);
			*(pOutput+1) = (b3 << 4) + ((b4 >> 2) & 0x0F);
			*(pOutput+2) = (b2 << 2) + ((b3 >> 4) & 0x03);
			*(pOutput+3) = (b1 << 6);
			break;
		case 6:
			b1 = *pInput;
			b2 = *(pInput + 1);
			b3 = *(pInput + 2);
			b4 = *(pInput + 3);
			b5 = *(pInput + 4);
			b6 = *(pInput + 5);
			if ( ((b2 & 0xC0) != 0x80) || ((b3 & 0xC0) != 0x80)
				|| ((b4 & 0xC0) != 0x80) || ((b5 & 0xC0) != 0x80)
				|| ((b6 & 0xC0) != 0x80) )
				return 0;
			*pOutput     = (b5 << 6) + (b6 & 0x3F);
			*(pOutput+1) = (b5 << 4) + ((b6 >> 2) & 0x0F);
			*(pOutput+2) = (b3 << 2) + ((b4 >> 4) & 0x03);
			*(pOutput+3) = ((b1 << 6) & 0x40) + (b2 & 0x3F);
			break;
		default:
			return 0;
			break;
		}

		return utfbytes;
	}
	static inline int enc_unicode_to_utf8_one(unsigned long unic, unsigned char *pOutput,
		int outSize)
	{
		//   assert(pOutput != NULL);
		//   assert(outSize >= 6);
		if(pOutput == NULL || outSize<6)
		{
			return -1;
		}


		if ( unic <= 0x0000007F )
		{
			// * U-00000000 - U-0000007F:  0xxxxxxx
			*pOutput     = (unic & 0x7F);
			return 1;
		}
		else if ( unic >= 0x00000080 && unic <= 0x000007FF )
		{
			// * U-00000080 - U-000007FF:  110xxxxx 10xxxxxx
			*(pOutput+1) = (unic & 0x3F) | 0x80;
			*pOutput     = ((unic >> 6) & 0x1F) | 0xC0;
			return 2;
		}
		else if ( unic >= 0x00000800 && unic <= 0x0000FFFF )
		{
			// * U-00000800 - U-0000FFFF:  1110xxxx 10xxxxxx 10xxxxxx
			*(pOutput+2) = (unic & 0x3F) | 0x80;
			*(pOutput+1) = ((unic >>  6) & 0x3F) | 0x80;
			*pOutput     = ((unic >> 12) & 0x0F) | 0xE0;
			return 3;
		}
		else if ( unic >= 0x00010000 && unic <= 0x001FFFFF )
		{
			// * U-00010000 - U-001FFFFF:  11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
			*(pOutput+3) = (unic & 0x3F) | 0x80;
			*(pOutput+2) = ((unic >>  6) & 0x3F) | 0x80;
			*(pOutput+1) = ((unic >> 12) & 0x3F) | 0x80;
			*pOutput     = ((unic >> 18) & 0x07) | 0xF0;
			return 4;
		}
		else if ( unic >= 0x00200000 && unic <= 0x03FFFFFF )
		{
			// * U-00200000 - U-03FFFFFF:  111110xx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
			*(pOutput+4) = (unic & 0x3F) | 0x80;
			*(pOutput+3) = ((unic >>  6) & 0x3F) | 0x80;
			*(pOutput+2) = ((unic >> 12) & 0x3F) | 0x80;
			*(pOutput+1) = ((unic >> 18) & 0x3F) | 0x80;
			*pOutput     = ((unic >> 24) & 0x03) | 0xF8;
			return 5;
		}
		else if ( unic >= 0x04000000 && unic <= 0x7FFFFFFF )
		{
			// * U-04000000 - U-7FFFFFFF:  1111110x 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
			*(pOutput+5) = (unic & 0x3F) | 0x80;
			*(pOutput+4) = ((unic >>  6) & 0x3F) | 0x80;
			*(pOutput+3) = ((unic >> 12) & 0x3F) | 0x80;
			*(pOutput+2) = ((unic >> 18) & 0x3F) | 0x80;
			*(pOutput+1) = ((unic >> 24) & 0x3F) | 0x80;
			*pOutput     = ((unic >> 30) & 0x01) | 0xFC;
			return 6;
		}

		return 0;
	}
	static inline std::wstring Utf8ToUnicode(std::string utf8str)
	{
		std::wstring temp;
		int len = utf8str.length();
		unsigned char buffer[8]={0};
		for(int i=0;i<len;i++)
		{
			memset(buffer,0,sizeof(buffer));
			enc_utf8_to_unicode_one((const unsigned char *)utf8str.substr(i,1).c_str(),(unsigned long *)buffer);
			temp+=(wchar_t*)buffer;
		}
		return temp;
	}
	static inline std::string UnicodeToUtf8(std::wstring unistr)
	{
		std::string temp;
		int len = unistr.length();
		unsigned char buffer[8]={0};
		for(int i=0;i<len;i++)
		{
			memset(buffer,0,sizeof(buffer));
			unsigned long ulinput=*(unsigned long *)unistr.substr(i,1).c_str();
			enc_unicode_to_utf8_one(ulinput,(unsigned char *)buffer,8);
			temp+=(char*)buffer;
		}
		return temp;

	}

	static inline int UTF2W(const char* src, std::wstring &t)
	{
		if (src == NULL)
		{
			return -1;
		}

		int size_s = strlen(src);
		int size_d = size_s + 10;          //?

		wchar_t *des = new wchar_t[size_d];
		memset(des, 0, size_d * sizeof(wchar_t));

		int s = 0, d = 0;
		bool toomuchbyte = true; //set true to skip error prefix.

		while (s < size_s && d < size_d)
		{
			unsigned char c = src[s];
			if ((c & 0x80) == 0)
			{
				des[d++] += src[s++];
			}
			else if((c & 0xE0) == 0xC0)  ///< 110x-xxxx 10xx-xxxx
			{
				WCHAR &wideChar = des[d++];
				wideChar  = (src[s + 0] & 0x3F) << 6;
				wideChar |= (src[s + 1] & 0x3F);

				s += 2;
			}
			else if((c & 0xF0) == 0xE0)  ///< 1110-xxxx 10xx-xxxx 10xx-xxxx
			{
				WCHAR &wideChar = des[d++];

				wideChar  = (src[s + 0] & 0x1F) << 12;
				wideChar |= (src[s + 1] & 0x3F) << 6;
				wideChar |= (src[s + 2] & 0x3F);

				s += 3;
			}
			else if((c & 0xF8) == 0xF0)  ///< 1111-0xxx 10xx-xxxx 10xx-xxxx 10xx-xxxx
			{
				WCHAR &wideChar = des[d++];

				wideChar  = (src[s + 0] & 0x0F) << 18;
				wideChar  = (src[s + 1] & 0x3F) << 12;
				wideChar |= (src[s + 2] & 0x3F) << 6;
				wideChar |= (src[s + 3] & 0x3F);

				s += 4;
			}
			else
			{
				WCHAR &wideChar = des[d++]; ///< 1111-10xx 10xx-xxxx 10xx-xxxx 10xx-xxxx 10xx-xxxx

				wideChar  = (src[s + 0] & 0x07) << 24;
				wideChar  = (src[s + 1] & 0x3F) << 18;
				wideChar  = (src[s + 2] & 0x3F) << 12;
				wideChar |= (src[s + 3] & 0x3F) << 6;
				wideChar |= (src[s + 4] & 0x3F);

				s += 5;
			}
		}

		t = des;
		delete[] des;
		des = NULL;

		return 0;
	}



	static inline int W2UTF(wchar_t wchar, char *utf8)
	{
		if (utf8 == NULL) {
			return -1;
		}
		int len = 0;
		int size_d = 8;

		if (wchar < 0x80)
		{  //
			//length = 1;
			utf8[len++] = (char)wchar;
		}
		else if(wchar < 0x800)
		{
			//length = 2;

			if (len + 1 >= size_d)
				return -1;

			utf8[len++] = 0xc0 | ( wchar >> 6 );
			utf8[len++] = 0x80 | ( wchar & 0x3f );
		}
		else if(wchar < 0x10000 )
		{
			//length = 3;
			if (len + 2 >= size_d)
				return -1;

			utf8[len++] = 0xe0 | ( wchar >> 12 );
			utf8[len++] = 0x80 | ( (wchar >> 6) & 0x3f );
			utf8[len++] = 0x80 | ( wchar & 0x3f );
		}
		else if( wchar < 0x200000 )
		{
			//length = 4;
			if (len + 3 >= size_d)
				return -1;

			utf8[len++] = 0xf0 | ( (int)wchar >> 18 );
			utf8[len++] = 0x80 | ( (wchar >> 12) & 0x3f );
			utf8[len++] = 0x80 | ( (wchar >> 6) & 0x3f );
			utf8[len++] = 0x80 | ( wchar & 0x3f );
		}
		return len;
	}
	static inline std::wstring UTF2W(std::string src)
	{
		std::wstring temp;
		UTF2W(src.c_str(),temp);
		return temp;
	}

	static inline std::string W2UTF(std::wstring unistr)
	{
		std::string temp;
		int len = unistr.length();
		char buffer[8]={0};
		for(int i=0;i<len;i++)
		{
			memset(buffer,0,sizeof(buffer));
			W2UTF(*unistr.substr(i,1).begin(),buffer);
			temp+=(char*)buffer;
		}
		return temp;

	}
#endif
	static inline string AToU(string sA)
	{
		wstring sW = AToW(sA);
		return W2UTF(sW);
	}
	static inline string UToA(string sU)
	{
		wstring sW=UTF2W(sU);
		return WToA(sW);
	}
	static inline wstring		 ToUpperW(wstring	sW)
	{
		wstring	sResult = sW;
		transform(sResult.begin(),sResult.end(),sResult.begin(),::toupper);
		return	sResult;

	}
	static inline string		 ToUpperA(string	sA)
	{
		string	sResult = sA;
		transform(sResult.begin(),sResult.end(),sResult.begin(),::toupper);
		return	sResult;

	}
	static inline wstring		 ToLowerW(wstring	sW)
	{
		wstring	sResult = sW;
		transform(sResult.begin(),sResult.end(),sResult.begin(),::tolower);
		return	sResult;

	}
	static inline string		 ToLowerA(string	sA)
	{
		string	sResult = sA;
		transform(sResult.begin(),sResult.end(),sResult.begin(),::tolower);
		return	sResult;
	}
	static inline string         Reverse(string sA)
	{
		string sResult = sA;
		std::reverse(sResult.begin(),sResult.end());
		return sResult;
	}
	static inline wstring         Reverse(wstring sW)
	{
		wstring sResult = sW;
		std::reverse(sResult.begin(),sResult.end());
		return sResult;
	}

	static inline bool IsTextUTF8(char* str,unsigned long long  length)
	{
		unsigned long  nBytes=0;//UFT8可用1-6个字节编码,ASCII用一个字节
		unsigned char chr;
		bool bAllAscii=true; //如果全部都是ASCII, 说明不是UTF-8
		for(int i=0; i<length; ++i)
		{
			chr= *(str+i);
			if( (chr&0x80) != 0 ) // 判断是否ASCII编码,如果不是,说明有可能是UTF-8,ASCII用7位编码,但用一个字节存,最高位标记为0,o0xxxxxxx
				bAllAscii= false;
			if(nBytes==0) //如果不是ASCII码,应该是多字节符,计算字节数
			{
				if(chr>=0x80)
				{
					if(chr>=0xFC&&chr<=0xFD)
						nBytes=6;
					else if(chr>=0xF8)
						nBytes=5;
					else if(chr>=0xF0)
						nBytes=4;
					else if(chr>=0xE0)
						nBytes=3;
					else if(chr>=0xC0)
						nBytes=2;
					else
						return false;

					nBytes--;
				}
			}
			else //多字节符的非首字节,应为 10xxxxxx
			{
				if( (chr&0xC0) != 0x80 )
					return false;

				nBytes--;
			}
		}
		if( nBytes > 0 ) //违返规则
			return false;
		if( bAllAscii ) //如果全部都是ASCII, 说明不是UTF-8
			return false;

		return true;
	}
	static inline int Replace(std::wstring& strContent, std::wstring strReplace, std::wstring  strDest)
	{
		while (true)
		{
			size_t pos = strContent.find(strReplace);
			if (pos != std::wstring::npos)
			{
				WCHAR pBuf[1] = { L'\0' };
				strContent.replace(pos, strReplace.length(), pBuf, 0);
				strContent.insert(pos, strDest);
			}
			else
			{
				break;
			}
		}
		return 0;
	}
	static inline int Replace(std::string& strContent, std::string strReplace, std::string  strDest)
	{
		while (true)
		{
			size_t pos = strContent.find(strReplace);
			if (pos != std::string::npos)
			{
				char pBuf[1] = { '\0' };
				strContent.replace(pos, strReplace.length(), pBuf, 0);
				strContent.insert(pos, strDest);
			}
			else
			{
				break;
			}
		}
		return 0;
	}

	static char * HexToString(unsigned char * Hex, ULONG HexLen, char * strBuffer, ULONG strBuferSize)
	{
		if (strBuferSize < (HexLen * 2))
		{
			return NULL;
		}
		char buffer[4] = { 0 };
		for (int i = 0; i < HexLen; i++)
		{
			sprintf_s(buffer, "%02X", *(Hex + i));
			memcpy(strBuffer + (i * 2), buffer, 2);
		}
		return strBuffer;
	}
	static ULONG StringToHex(char * strBuffer, ULONG strLen, unsigned char * Hex, ULONG HexLen)
	{
		if (strBuffer && Hex && strLen == HexLen * 2)
		{
			for (int i = 0; i < HexLen; i++)
			{
				sscanf_s(&strBuffer[i * 2], "%2x", &Hex[i]);
			}
			return 0;
		}
		return -1;
	}
}
#endif //_H_STDSTRINGEXT
