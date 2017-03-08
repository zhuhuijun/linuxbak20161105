#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "cfg_op.h"


#define  DB_sid			"oracle_sid"
#define  DB_User		"appuser"
#define  DB_PassWord	"appuser"
#define	 CFG_FILENAME	"c:/cfg.ini"

void main_menu()
{
	printf("\n1 Test SetCfgItem(�������������ļ�)	");
	printf("\n2 Test GetCfgItem(���Զ�ȡ�����ļ�)	");
	printf("\n0 exit(0)        (�����˳�)	    ");
	printf("\nplease enter your choice:[1/2/0]: ");
	return;
}


int  Test_SetCfgItem()
{
	int		rv = 0; 
	int		choice = 0;

	char	key[1024] ;
	char	value[1024];

	memset(key, 0, sizeof(key));
	memset(value, 0, sizeof(value));

	printf("\nplease enter key:");
	scanf("%s", key);

	printf("\nplease enter value:");
	scanf("%s", value);

	rv  = SetCfgItem(CFG_FILENAME, key, value, strlen(value));
	if (rv != 0)
	{
		printf("SetCfgItem() err: %d \n", rv);
		goto End;
	}

	/*
	rv  = GetCfgItem(CFG_FILENAME, DB_sid, value2, &value2Len);
	if (rv != 0)
	{
		printf("SetCfgItem() err: %d \n", rv);
		goto End;
	}

	//�Ƚϳ���
	if (valuelen != value2Len)
	{
		printf("(valuelen != value2Len) err\n");
		goto End;
	}
	//�Ƚ�����
	if (memcmp(value, value2, value2Len) != 0)
	{
		printf("(memcmp(value, value2, value2Len)) err\n");
		goto End;
	}
	*/

	printf("��д�������̵Ʋ���ͨ��\n");

End:
	return rv;
	
}

int  Test_GetCfgItem()
{
	int		rv = 0; 
	int		choice = 0;

	char	key[1024] ;
	char	value[1024];
	int		valueLen = 1024;

	memset(key, 0, sizeof(key));
	memset(value, 0, sizeof(value));

	printf("\nplease enter key:");
	scanf("%s", key);

	//printf("\nplease enter value:");
	//scanf("%s", value);

	rv  = GetCfgItem(CFG_FILENAME, key, value, &valueLen);
	if (rv != 0)
	{
		printf("SetCfgItem() err: %d \n", rv);
		goto End;
	}
	printf("\n%s = %s", key, value);

	printf("\n��д�������̵Ʋ���ͨ��\n");

End:
	return rv;
	
}


/*
int  Test_GetCfgItem()
{
	int		rv = 0; 
	int		choice = 0;

	char	*value = "orcl";
	int		valuelen = strlen(value);

	char	value2[100];
	int		value2Len = 100;



	memset(value2, 0, sizeof(value2));


	rv  = SetCfgItem(CFG_FILENAME, DB_sid, value, valuelen);
	if (rv != 0)
	{
		printf("SetCfgItem() err: %d \n", rv);
		goto End;
	}

	rv  = GetCfgItem(CFG_FILENAME, DB_sid, value2, &value2Len);
	if (rv != 0)
	{
		printf("SetCfgItem() err: %d \n", rv);
		goto End;
	}

	//�Ƚϳ���
	if (valuelen != value2Len)
	{
		printf("(valuelen != value2Len) err\n");
		goto End;
	}
	//�Ƚ�����
	if (memcmp(value, value2, value2Len) != 0)
	{
		printf("(memcmp(value, value2, value2Len)) err\n");
		goto End;
	}

	printf("��д�������̵Ʋ���ͨ��\n");

End:
	return rv;
	
}
*/

int  main()
{
	int		rv = 0; 
	int		choice = 0;

	for(;;)
	{
		main_menu();
	    scanf("%d", &choice);
        switch (choice)
		{
		case 1:
			Test_SetCfgItem();   break;
		case 2:
			Test_GetCfgItem();   break;
		case 0:
			exit(0);
		default:
			exit(0);
		}
	}

End:
	return rv;
	getchar();
}


