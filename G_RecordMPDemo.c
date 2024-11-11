void G_RecordMPDemo(char *inputdemoname)

{
  size_t sVar1;
  int iVar2;
  char *_Str;
  char local_10c [256];
  
  sprintf(local_10c,"%s\\mpd\\v2.2.10\\main\\",&srb2home);
  strcpy(&demoname,inputdemoname);
  sVar1 = strlen(&demoname);
  // some kind of struct
  *(undefined4 *)(&demoname + sVar1) = 0x64706d2e;
  (&DAT_009f7c84)[sVar1] = 0;
  iVar2 = M_CheckParm("-maxdemo");
  if (iVar2 != 0) {
    iVar2 = M_IsNextParm();
    if (iVar2 != 0) {
      _Str = (char *)M_GetNextParm();
      iVar2 = atoi(_Str);
      sVar1 = iVar2 << 0x10;
      goto LAB_00476f1e;
    }
  }
  sVar1 = 0x4000000;
LAB_00476f1e:
  demo_p = 0;
  demobuffer = malloc(sVar1);
  demoend = (int)demobuffer + sVar1;
  mpdemoversion = 9;
  mpdemorecording = 1;
  CONS_Printf("G_RecordMPDemo : demoname is %s\n",&demoname);
  S_StartSound(0,0x210);
  if (multiplayer == 0) {
    return;
  }
  sVar1 = strlen(inputdemoname);
  strncpy(&curmpdemoname,inputdemoname,sVar1 + 1);
  FIL_StripExtension(&curmpdemoname);
  strcatbf(&curmpdemoname,local_10c,&DAT_00762c35);
  return;
}

