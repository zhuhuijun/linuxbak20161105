/*
cfg_test.h
*/
#ifndef _INC_CFG_TEST_H
#endif _INC_CFG_TEST_H

#ifdef __cplusplus
extern "C"{
	int GetCfgItem(
		char *pFileName /*in*/, 
		char *pKey /*in*/,
		char * pValue/*in out*/, 
		int * pValueLen /*out*/);
	int WriteCfgItem(
		char *pFileName /*in*/,
		char *pItemName /*in*/,
		char *pItemValue/*in*/, 
		int itemValueLen /*in*/);

#ifdef  __cplusplus
}
#endif

#endif 