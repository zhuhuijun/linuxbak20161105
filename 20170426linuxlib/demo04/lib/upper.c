#include <string.h>
void upper(const char *src,char *desc)
{
	int len = strlen(src);
	int i = 0;
	 for(;i<len;i++){
	 	if (src[i] >='a' && src[i]<='z'){
	 		desc[i] =src[i]-0x20;
	 	}else{
	 		desc[i] = src[i];
	 	}
	 }
}